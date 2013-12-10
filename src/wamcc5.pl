/*-------------------------------------------------------------------------*/
/* Passe 5: Allocation des variables (registres) temporaires.              */
/*                                                                         */
/* predicat d'appel: allocation_varsX(W)                                   */
/*                                                                         */
/* entree-sortie                                                           */
/* W      : code wam, W=[inst_wam, ...]                                    */
/*                                                                         */
/* Names: Arg: Arg is an argument  iff integer(Arg)                        */
/*        Tmp: Tmp is a  temporary iff var(Tmp)                            */
/*        Reg: Reg is a register if it is either an argument or a temporary*/
/*                                                                         */
/* This allocation proceeds in 3 steps:                                    */
/*                                                                         */
/*  1) computing aliases (i.e. list of same values at entry of each inst): */
/*     LAlias is a list of aliases (one for each wam inst)                 */
/*     LAlias=[Alias,...]                                                  */
/*     The aliases (Alias) are represented as a set of same values (LSame) */
/*     Alias=[LSame,...].                                                  */
/*     each LSame is a set of Regs (integers or variables)                 */
/*     ex Alias=[ [1,2,X,Y],[3,Z,4] ] means 1,2,X,Y are aliased, 3,Z,4 also*/
/*                                                                         */
/*  2) computing the list of temporaries LTmp=[tmp(Tmp,Imposs,Wish),...]   */
/*     where Imposs is a set of impossible values and Wish a set of desired*/
/*     values (to give rise to useless copy instructions).                 */
/*     The code is traversed in reverse order, computing at each time the  */
/*     set of Regs in life (InLife) (see Mats Carlsson's PhD Thesis).      */
/*                                                                         */
/*  3) Each Tmp in LTmp is assigned wrt to Wish and Imposs in 2 steps:     */
/*                                                                         */
/*     a) from [tmp(Tmp,Imposs,Wish)|LTmp]:                                */
/*                                                                         */
/*        while there exists Tmpj in Wish and not in Imposs:               */
/*           let tmp(Tmpj,Impossj,Wishj) be the associated record in LTmp  */
/*           Imposs:=Imposs+Impossj and Wish:=Wish+Wishj,                  */
/*           LTmp:=LTmp - tmp(Tmpj,Impossj,Wishj) (remove Tmpj from LTmp)  */
/*           Tmpj=Tmp (unify them)                                         */
/*                                                                         */
/*        At the end of the loop:                                          */
/*        if there exists an integer k in Wish-Imposs then  (see comment *)*/
/*           Tmp=k else replace tmp(Tmp,Imposs,Wish) in LTmp               */
/*                                                                         */
/*     b) for each Tmp remaining in LTmp assign a value w.r.t to Imposs    */
/*        by chosing the first integer not present in Imposs (after sort)  */
/*                                                                         */
/* Comments:                                                               */
/*                                                                         */
/* (*) It seems that from the construction in Wish only remains possible   */
/*     so the compl(Wish,Imposs,AssignOK) would be useless, but I have to  */
/*     check this correctly.                                               */
/*                                                                         */
/* It would be possible to eliminate useless instructions. In codification */
/* we could add an argument specifying that when a w(Reg) code is handled  */
/* and Reg is not in InLife then the surrounding instruction is useless.   */
/* it is the case for get_x_variable and put_x_value,                      */
/* not for put_x_variable. It is also the case for math_load_x_value in    */
/* fast_math mode since no types have to be checked.                       */
/* In this case:  p(X):- Y=X, Z is X+Y, q(X,X)                             */
/* would give rise to: put_x_value(0,1)                                    */
/*                     execute(q/2).                                       */
/* Is it useful ?                                                          */
/*-------------------------------------------------------------------------*/

:- public allocation_varsX/1.

allocation_varsX(W):-
	aliases(W,[],LAlias),
	create_lst_tmp(W,LAlias,_,LTmp),
	assign_lst_tmp(LTmp).




          /* Aliasing information creation */

aliases([],_,[]).

aliases([InstW|W],Alias,[Alias|LAlias]):-
	functor(InstW,F,_),
	((F==call ; F==execute) -> Alias1=[]
                                ;  
			           codification(InstW,LCode),
				   !,
				   aliases1(LCode,Alias,Alias1)),
	aliases(W,Alias1,LAlias).


aliases1([],Alias,Alias).

aliases1([Code|LCode],Alias,Alias3):-
	(Code=r(Reg), Alias2=Alias
                    ;
	 Code=w(Reg), remove_aliases_of(Alias,Reg,Alias2)
                    ;  
         Code=c(Reg,Reg1), remove_aliases_of(Alias,Reg1,Alias1),
	                   add_alias(Alias1,Reg,Reg1,Alias2)),
	!,
	aliases1(LCode,Alias2,Alias3).




add_alias([],Reg,Reg1,[[Reg,Reg1]]).

add_alias([LSame|Alias],Reg,Reg1,[LSame1|Alias1]):-
	(ens_elt(LSame,Reg) -> ens_ajout(LSame,Reg1,LSame1),
                               Alias1=Alias
                            ;  
                               LSame1=LSame,
                               add_alias(Alias,Reg,Reg1,Alias1)).
	



find_aliases_of([LSame|Alias],Reg,LSame1):-
	(ens_retrait(LSame,Reg,LSame1) 
               -> true
               ; 
		  find_aliases_of(Alias,Reg,LSame1)).




remove_aliases_of([],_,[]).

remove_aliases_of([LSame|Alias],Reg,Alias1):-
	(ens_retrait(LSame,Reg,LSame1) 
             -> ((LSame1==[];LSame1=[_]) -> Alias1=Alias
                                         ;  Alias1=[LSame1|Alias])
              ; 
                Alias1=[LSame|Alias2],
                remove_aliases_of(Alias,Reg,Alias2)).




          /* Temporarie dictionnary creation (lifetime analysis) */

create_lst_tmp([],[],[],[]).

create_lst_tmp([InstW|W],[Alias|LAlias],InLife1,LTmp1):-
	create_lst_tmp(W,LAlias,InLife,LTmp),
	codification(InstW,LCode),
	!,
	handle_lst_code(LCode,Alias,InLife,InLife1,LTmp,LTmp1).




handle_lst_code([],_,InLife,InLife,LTmp,LTmp).

handle_lst_code([Code|LCode],Alias,InLife,InLife2,LTmp,LTmp2):-
	handle_lst_code(LCode,Alias,InLife,InLife1,LTmp,LTmp1),
	handle_one_code(Code,Alias,[],InLife1,InLife2,LTmp1,LTmp2).




handle_one_code(r(Reg),Alias,Wish,InLife,InLife1,LTmp,LTmp2):-
	(ens_elt(InLife,Reg)
              -> InLife1=InLife,
                 (var(Reg), Wish\==[] -> update_tmp(LTmp,Reg,[],Wish,LTmp2)
	                              ;  LTmp2=LTmp)
              ;
	         InLife1=[Reg|InLife],
		 constraints(Reg,InLife,Alias,Cstr),
		 make_imposs(Cstr,[Reg],LTmp,LTmp1),
		 (var(Reg) -> update_tmp(LTmp1,Reg,Cstr,Wish,LTmp2)
			   ;  LTmp2=LTmp1)).

handle_one_code(w(Reg),Alias,Wish,InLife,InLife1,LTmp,LTmp2):-
	(ens_retrait(InLife,Reg,InLife1)
              -> (var(Reg), Wish\==[] -> update_tmp(LTmp,Reg,[],Wish,LTmp2)
	                              ;  LTmp2=LTmp)
              ;
	         InLife1=InLife,
	         (var(Reg) -> constraints(Reg,InLife1,Alias,Cstr),
		              (Wish\==[] -> ens_compl(Cstr,Wish,Cstr1)
                                         ;  Cstr1=Cstr),
			      make_imposs(Cstr1,[Reg],LTmp,LTmp1),
	                      update_tmp(LTmp1,Reg,Cstr1,Wish,LTmp2)
			   ;
			      LTmp2=LTmp)).

handle_one_code(c(Reg,Reg1),Alias,_,InLife,InLife2,LTmp,LTmp2):-
	handle_one_code(w(Reg1),Alias,[Reg],InLife,InLife1,LTmp,LTmp1),
	handle_one_code(r(Reg),Alias,[Reg1],InLife1,InLife2,LTmp1,LTmp2).




constraints(Reg,InLife,Alias,Cstr):-
	(find_aliases_of(Alias,Reg,LSame) -> ens_compl(InLife,LSame,Cstr)
                                          ;  Cstr=InLife).




update_tmp([],Reg,Imposs,Wish,[tmp(Reg,Imposs,Wish)]).

update_tmp([Tmp|LTmp],Reg,Imposs,Wish,[Tmp1|LTmp1]):-
	Tmp=tmp(Reg1,Imposs1,Wish1),
	(Reg==Reg1 -> ens_union(Imposs,Imposs1,Imposs2),
	              ens_union(Wish,Wish1,Wish2),
		      Tmp1=tmp(Reg,Imposs2,Wish2),
		      LTmp1=LTmp
                   ;
		      Tmp1=Tmp,
		      update_tmp(LTmp,Reg,Imposs,Wish,LTmp1)).




remove_tmp([T|LTmp],Reg,Imposs,Wish,LTmp2):-
	T=tmp(Reg1,Imposs1,Wish1),
	(Reg==Reg1 -> Imposs=Imposs1,
                      Wish=Wish1,
		      LTmp2=LTmp
                   ;
		      LTmp2=[T|LTmp1],
		      remove_tmp(LTmp,Reg,Imposs,Wish,LTmp1)).





make_imposs([],_,LTmp,LTmp).

make_imposs([Reg|Cstr],Imposs,LTmp,LTmp2):-
	(var(Reg) -> update_tmp(LTmp,Reg,Imposs,[],LTmp1)
	          ;  LTmp1=LTmp),
	make_imposs(Cstr,Imposs,LTmp1,LTmp2).




          /* Register assignment */

assign_lst_tmp(LTmp):-
	assign_wishes(LTmp,LTmp1),
	assign_values(LTmp1).




assign_wishes([],[]).

assign_wishes([tmp(Tmp,Imposs,Wish)|LTmp],LTmp3):-
	collapse_tmps(Wish,Imposs,LTmp,Tmp,Wish1,Imposs1,LTmp1),
	try_a_whish(Tmp,Imposs1,Wish1),
	(var(Tmp) -> LTmp3=[tmp(Tmp,Imposs1)|LTmp2] % no longer wish in tmp()
                  ;  LTmp3=LTmp2),
        assign_wishes(LTmp1,LTmp2).




collapse_tmps([],Imposs,LTmp,_,[],Imposs,LTmp).

collapse_tmps([Reg|Wish],Imposs,LTmp,Tmp,Wish1,Imposs1,LTmp1):-
	(Reg==Tmp ; ens_elt(Imposs,Reg)),
        !,
	collapse_tmps(Wish,Imposs,LTmp,Tmp,Wish1,Imposs1,LTmp1).

collapse_tmps([Arg|Wish],Imposs,LTmp,Tmp,[Arg|Wish1],Imposs1,LTmp1):-
	integer(Arg),
	!,
	collapse_tmps(Wish,Imposs,LTmp,Tmp,Wish1,Imposs1,LTmp1).

collapse_tmps([Tmp1|Wish],Imposs,LTmp,Tmp,Wish3,Imposs3,LTmp2):-
	remove_tmp(LTmp,Tmp1,Imposs1,Wish1,LTmp1),
	ens_union(Imposs,Imposs1,Imposs2),
	ens_union(Wish,Wish1,Wish2),
	Tmp=Tmp1,
	collapse_tmps(Wish2,Imposs2,LTmp1,Tmp,Wish3,Imposs3,LTmp2).




try_a_whish(Tmp,Imposs,Wish):-
	ens_compl(Wish,Imposs,AssignOk),
	(AssignOk=[Tmp|_] ; true),
	!.




assign_values([]).

assign_values([tmp(Tmp,Imposs)|LTmp]):-
	sort(Imposs,Imposs1),
	find_hole(Imposs1,0,Tmp),
        assign_values(LTmp).




find_hole([],Nb,Nb).

find_hole([Reg|Imposs],Nb,Nb1):-
        var(Reg),
	!,
        find_hole(Imposs,Nb,Nb1).

find_hole([Reg|Imposs],Nb,Nb2):-
        (Reg>Nb -> Nb2=Nb                                        % hole found
                ;
                  (Reg==Nb -> Nb1 is Nb+1
                           ;  Nb1=Nb),
                  find_hole(Imposs,Nb1,Nb2)).




          /* instruction codification */

codification(get_x_variable(Tmp,Arg),          [c(Arg,Tmp)]).
	                                             
codification(get_x_value(Tmp,Arg),             [r(Tmp), r(Arg)]).

codification(get_y_variable(_,Arg),            [r(Arg)]).

codification(get_y_value(_,Arg),               [r(Arg)]).

codification(get_constant(_,Arg),              [r(Arg)]).

codification(get_integer(_,Arg),               [r(Arg)]).

codification(get_nil(Arg),                     [r(Arg)]).

codification(get_list(Reg),                    [r(Reg)]).

codification(get_structure(_,Reg),             [r(Reg)]).

codification(put_x_variable(Tmp,Arg),          [w(Tmp), w(Arg)]).

codification(put_x_value(Tmp,Arg),             [c(Tmp,Arg)]).

codification(put_y_variable(_,Arg),            [w(Arg)]).

codification(put_y_value(_,Arg),               [w(Arg)]).

codification(put_y_unsafe_value(_,Arg),        [w(Arg)]).

codification(put_constant(_,Arg),              [w(Arg)]).

codification(put_integer(_,Arg),               [w(Arg)]).

codification(put_nil(Arg),                     [w(Arg)]).

codification(put_list(Reg),                    [w(Reg)]).

codification(put_structure(_,Reg),             [w(Reg)]).

codification(unify_x_variable(Tmp),            [w(Tmp)]).

codification(unify_x_value(Tmp),               [r(Tmp)]).

codification(unify_x_local_value(Tmp),         [r(Tmp)]).

codification(call(_/N,_),                      [w(255)|LCode]):- 
	cree_liste_r(0,N,LCode).

codification(execute(_/N),                     [w(255)|LCode]):- 
	cree_liste_r(0,N,LCode).

codification(get_x_bc_reg(Tmp),                [c(255,Tmp)]).

codification(cut_x(Tmp),                       [r(Tmp)]).

codification(math_load_x_value(Reg1,Reg2),     [c(Reg1,Reg2)]).

codification(math_load_y_value(_,Reg2),        [w(Reg2)]).

codification(function_1(_,Reg,Reg1),           [r(Reg1), w(Reg)]).

codification(function_2(_,Reg,Reg1,Reg2),      [r(Reg1), r(Reg2), w(Reg)]).

codification(builtin_1(_,Reg1),                [r(Reg1)]).

codification(builtin_2(_,Reg1,Reg2),           [r(Reg1), r(Reg2)]).

codification(builtin_3(_,Reg1,Reg2,Reg3),      [r(Reg1), r(Reg2), r(Reg3)]).


	% instructions which use no temporaries

codification(_,                                []).




cree_liste_r(N,N,[]).

cree_liste_r(I,N,[r(I)|L]):-
	I1 is I+1,
	cree_liste_r(I1,N,L).




:- public dummy_instruction/1.

dummy_instruction(get_x_variable(X,X)).

dummy_instruction(put_x_value(X,X)).






