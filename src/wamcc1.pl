/*-------------------------------------------------------------------------*/
/* Passe 1: Elimination de certaines structures syntaxiques.               */
/*                                                                         */
/* ..., !,...: devient '$get_bc_reg'(VarCut)...'$cut'(VarCut), ...         */
/*                                                                         */
/* (P -> Q)  : devient '$get_bc_reg'(VarCut),P,'$cut'(VarCut),Q ; fail)    */
/*                                                                         */
/* (P -> Q;R): devient '$get_bc_reg'(VarCut),P,'$cut'(VarCut),Q ; R)       */
/*                                                                         */
/* (\+P)     : devient '$get_bc_reg'(VarCut),P,'$cut'(VarCut),fail ; true) */
/*                                                                         */
/* X         : devient call(X)                                             */
/*                                                                         */
/* P;Q;...;R : devient '$aux_k'(var1,var2,...,varp)          k=1,2,...,n   */
/*                  et '$aux_k'(var1,var2,...,varp):- P                    */
/*                     '$aux_k'(var1,var2,...,varp):- Q                    */
/*                        :                                                */
/*                     '$aux_k'(var1,var2,...,varp):- R                    */
/*                                                                         */
/*                                                                         */
/* predicat d'appel: sucre_syntaxique(ClSrc,LSrc,ClSrc1,LSrc1)             */
/*                                                                         */
/* entree                                                                  */
/* ClSrc  : clause source a verifier/modifier                              */
/* LSrc   : liste des autres clauses sources                               */
/*                                                                         */
/* sortie                                                                  */
/* ClSrc1 : clause modifiee                                                */
/* LSrc1  : liste a laquelle on a ajoute les clause '$aux_k'(var1,...,varp)*/
/*                                                                         */
/* En mode debug: P:- Q1, ... , Qn. devient P:- Q1, ..., Qn, '$dbg_true'.  */
/* si Qn n'est pas defini dans le module courant. $dbg_true est un inline  */
/* qui ne s'expanse en rien mais entraine la generation d'un proceed pour  */
/* cette clause. Sinon on ne peut tracer sous debug la sortie de l'appel de*/
/* P si celui-ci est fait depuis un module non debugge.                    */
/*-------------------------------------------------------------------------*/

:- public sucre_syntaxique/4.

sucre_syntaxique(ClSrc,LSrc,ClSrc2,LSrc1):-
	(ClSrc=(T:-_) ; ClSrc=T),
        functor(T,F,N),
	(test_pred_info(dyn,F,N) 
              -> make_special_clause(nb_clause_dyn,'$dyn_',
                                     assertz(ClSrc),ClSrc2),
                 LSrc1=LSrc
              ;
	         normalise_cuts(ClSrc,ClSrc1),
		 normalise_alts(ClSrc1,LSrc,ClSrc2,LSrc1)),
	!.




normalise_cuts((T:-C),ClSrc):-                                  % clause
        normalise_cuts1(C,VarCut,C1,HasCut),
        (HasCut==t -> ClSrc=(T:-'$get_bc_reg'(VarCut),C1)
                   ;  ClSrc=(T:-C1)).

normalise_cuts(T,T).                                            % fait




normalise_cuts1(X,_,call(X),_):-
	var(X).

normalise_cuts1((P->Q;R),VarCut,ClSrc,HasCut):-
	ClSrc=('$get_bc_reg'(VarCut1),P,'$cut'(VarCut1),Q1;R1),
	normalise_cuts1(Q,VarCut,Q1,HasCut),
	normalise_cuts1(R,VarCut,R1,HasCut).

normalise_cuts1((P->Q),VarCut,ClSrc,HasCut):-
	ClSrc=('$get_bc_reg'(VarCut1),P,'$cut'(VarCut1),Q1;fail),
	normalise_cuts1(Q,VarCut,Q1,HasCut).

normalise_cuts1(\+P,VarCut,ClSrc,HasCut):-
	normalise_cuts1((P->fail;true),VarCut,ClSrc,HasCut).

normalise_cuts1((P,Q),VarCut,(P1,Q1),HasCut):-
	normalise_cuts1(P,VarCut,P1,HasCut),
	normalise_cuts1(Q,VarCut,Q1,HasCut).

normalise_cuts1((P;Q),VarCut,(P1;Q1),HasCut):-
	normalise_cuts1(P,VarCut,P1,HasCut),
	normalise_cuts1(Q,VarCut,Q1,HasCut).

normalise_cuts1((!),VarCut,'$cut'(VarCut),t).

normalise_cuts1(P,_,P1,_):-
	functor(P,F,N),
	(test_pred_info(dyn,F,N) -> P1=call(P)
                                 ;  P1=P).




normalise_alts((T:-C),LSrc,(T:-C2),LSrc1):-                          % clause
	functor(T,F,_),
	normalise_alts1(C,LSrc,F,T,C1,LSrc1,LastPred),
	g_read(debug,Debug),
	(Debug=:=0 -> C2=C1
                   ;  
                      functor(LastPred,FLastPred,NLastPred),
	              (test_pred_info(def,FLastPred,NLastPred)
	                     -> C2=C1
                             ;  C2=(C1,'$dbg_true'))).

normalise_alts(T,LSrc,T,LSrc).                                       % fait


normalise_alts1(X,LSrc,_,_,call(X),LSrc,call(_)):-
	var(X).

normalise_alts1((P,Q),LSrc,F,RestC,(P1,Q1),LSrc2,LastPred):-
	normalise_alts1(P,LSrc,F,(RestC,Q),P1,LSrc1,_),
	normalise_alts1(Q,LSrc1,F,(RestC,P),Q1,LSrc2,LastPred).

normalise_alts1((P;Q),LSrc,F,RestC,PredAux,LSrc1,PredAux):-
	g_read(aux,Aux),
	Aux1 is Aux+1,
	g_assign(aux,Aux1),
	(sub_atom(F,Pos,5,'_$aux') -> L is Pos-1,
                	              sub_atom(F,1,L,F1)
			           ; 
				      F1=F),
	number_atom(Aux,ANo),
	atom_concat('$aux',ANo,AAux),
	atom_concat(F1,'_',F2),
	atom_concat(F2,AAux,Nom),
	lst_var(RestC,[],VarRestC),
	lst_var((P;Q),[],VarOu),
	ens_inter(VarRestC,VarOu,V),
	PredAux=..[Nom|V],
	functor(PredAux,FPredAux,NPredAux),                % add a new clause
	set_pred_info(def,FPredAux,NPredAux),
	linearise((P;Q),PredAux,LSrc,LSrc1).

normalise_alts1(P,LSrc,_,_,P,LSrc,P).




linearise(Body,PredAux,LSrc,LSrc2):-
	(Body=(P;Q) -> linearise(Q,PredAux,LSrc,LSrc1),
	               linearise1(P,PredAux,LSrc1,LSrc2)
                    ;
                       linearise1(Body,PredAux,LSrc,LSrc2)).


linearise1(P,PredAux,LSrc,LSrc1):-
	(P==fail -> LSrc1=LSrc
                 ;  
		    copy_term((PredAux:-P),AltP),
		    LSrc1=[AltP|LSrc]).




/* on utilise linearise plutot que :

   normalise_alts1((P;Q),...) recursivement sur P et Q

   pour generer un code plus optimal (code plat) x:-P;Q;R donne :
   
   x:-	'$aux_1'     au lieu de  x:- '$aux_1'

   '$aux_1':- P.                 '$aux_1':- P.
   '$aux_1':- Q.                 '$aux_1':- '$aux_2'.
   '$aux_1':- R.
                                 '$aux_2':- Q.
                                 '$aux_2':- R.
*/




lst_var(X,V,V1):-
	var(X),
	!,
	ens_ajout(V,X,V1).

lst_var(T,V,V1):-
	functor(T,_,A),
	lst_var_args(1,A,T,V,V1).



lst_var_args(I,A,T,V,V2):-
	(I=<A -> arg(I,T,ArgT),
                 lst_var(ArgT,V,V1),
		 I1 is I+1,
		 lst_var_args(I1,A,T,V1,V2)
              ;
                 V2=V).

