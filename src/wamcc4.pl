/*-------------------------------------------------------------------------*/
/* Passe 4: Generation du code.                                            */
/*                                                                         */
/* predicat d'appel: generation_code(T,C,NbChunk,Pred,W)                   */
/*                                                                         */
/* entree                                                                  */
/* T      : format interne de la tete                                      */
/* C      : format interne du corps                                        */
/* NbChunk: nombre de chunks du corps                                      */
/*                                                                         */
/* sortie                                                                  */
/* Pred   : nom du predicat de la tete (nom de la clause)                  */
/* W      : code wam associe a la clause, W = [inst_wam,...]               */
/*                                                                         */
/*                                                                         */
/* Principe:                                                               */
/* genere_tete  se charge de generer le code de la tete.                   */
/* genere_corps se charge de generer le code du corps. Remarquer que si le */
/* dernier but est un predicat inline il n'y a pas de execute mais un      */
/* un proceed.                                                             */
/*                                                                         */
/* Les termes structures:                                                  */
/* On entend par terme structure un format interne lst(_,_) ou stc(_,_),   */
/* on designera pas Strc de tels formats.                                  */
/* La gestion des termes structures de la tete et du corps est assuree par */
/* gen_lst_strc(LStrcReg,UL,LSuiv,W)                                       */
/*                                                                         */
/* entree                                                                  */
/* LStrcReg: une liste de Strc/Reg dont il faut generer le code            */
/* UL      : unif/load pour differencier les traitements                   */
/* LSuiv   : liste de codes wam a placer apres le resultat                 */
/*                                                                         */
/* sortie                                                                  */
/* W       : code wam associe a LStrcReg                                   */
/*                                                                         */
/* Un element de LStrcReg (un Strc/Reg) indique que Strc doit etre unifie  */
/* avec (resp. charge dans) le registre Reg si UL=unif (resp. UL=load).    */
/*                                                                         */
/* Pour chaque Strc/Reg on appelle:                                        */
/*                                                                         */
/* gen_strc(Strc,Reg,UL,LSuiv,StrcW,LStrcRegAux) qui calcule le code wam   */
/* associe a Strc/Reg (StrcW) et fournit une liste auxiliaire contenant    */
/* les sous termes structures de Strc (liste LStrcRegAux).                 */
/*                                                                         */
/* Il reste alors a rappeler gen_lst_strc() sur LStrcRegAux et aussi sur   */
/* LStrcReg' (LStrcReg = [Strc/Reg | LStrcReg']).                          */
/* Ce qui differe entre la tete et le corps est la facon dont doivent etre */
/* ajances les differents codes:                                           */
/*                                                                         */
/* en unif (tete) : LStrcRegW = StrcW        + LStrcRegAuxW + LStrcReg'W   */
/* en load (corps): LStrcRegW = LStrcRegAuxW + StrcW        + LStrcReg'W   */
/*                                                                         */
/* Exemples:                                                               */
/*                                                                         */
/* p(f(g(a,b),c)).                                                         */
/*                                                                         */
/* LStrcReg    = [f(g(a,b),c)/0]              (0 car a unifier contre A0)  */
/* StrcW       = [get_structure(f/2,0),                                    */
/*                unify_x_variable(_1),                                    */
/*                unify_constant(c)]                                       */
/*                                                                         */
/* LStrcRegAux = [g(a,b)/_1]                  (_1 temporaire cree)         */
/*                                                                         */
/* puis:                                                                   */
/* LStrcRegAuxW= [get_structure(g/2,_1),                                   */
/*                unify_constant(a),                                       */
/*                unify_constant(b)]                                       */
/*                                                                         */
/* d'ou:                                                                   */
/* LStrcRegW   = [get_structure(f/2,0),                                    */
/*                unify_x_variable(_1),                                    */
/*                unify_constant(c),                                       */
/*                get_structure(g/2,_1),                                   */
/*                unify_constant(a),                                       */
/*                unify_constant(b)]                                       */
/*                                                                         */
/*                                                                         */
/* p:- q(f(g(a,b),c)).                                                     */
/*                                                                         */
/* LStrcReg    = [f(g(a,b),c)/0]              (0 car a charger dans A0)    */
/* StrcW       = [put_structure(f/2,0),                                    */
/*                unify_x_value(_1),                                       */
/*                unify_constant(c)]                                       */
/*                                                                         */
/* LStrcRegAux = [g(a,b)/_1]                  (_1 temporaire cree)         */
/*                                                                         */
/* puis:                                                                   */
/* LStrcRegAuxW= [put_structure(g/2,_1),                                   */
/*                unify_constant(a),                                       */
/*                unify_constant(b)]                                       */
/*                                                                         */
/* d'ou:                                                                   */
/* LStrcRegW   = [put_structure(g/2,_1),                                   */
/*                unify_constant(a),                                       */
/*                unify_constant(b)]                                       */
/*                put_structure(f/2,0),                                    */
/*                unify_x_value(_1),                                       */
/*                unify_constant(c)]                                       */
/*-------------------------------------------------------------------------*/

:- public generation_code/5.

generation_code(T,C,NbChunk,Pred,TW1):-
	g_read(debug,Debug),
        (Debug>0 -> TW1=[dbg_clause|TW], CW1=[dbg_body|CW]
                 ;  TW1=TW, CW1=CW),
	genere_tete(T,NbChunk,CW1,TW,Pred),
	genere_corps(C,CW).




genere_tete(p(_,Pred,LstArg,NbY),NbChunk,LSuiv,TW,Pred):-
	gen_tete_lst_arg(LstArg,0,LSuiv,TW1),
	(NbChunk > 1 -> TW=[allocate(NbY)|TW1]
	             ;  TW=TW1).




gen_tete_lst_arg([],_,LSuiv,LSuiv).

gen_tete_lst_arg([Arg|LstArg],Reg,LSuiv,ArgW):-
	gen_unif_arg(Arg,Reg,LstArgW,ArgW),
	!,
	Reg1 is Reg+1,
	gen_tete_lst_arg(LstArg,Reg1,LSuiv,LstArgW).




genere_corps([],[proceed]).                                         % 0 buts

genere_corps([p(_,fail/0,[],_)|_],[fail]).

genere_corps([p(_,false/0,[],_)|_],[fail]).

genere_corps([p(NoPred,Pred/N,LstArg,_)|C],PredW):-
	inline_predicate(Pred,N),
	gen_inline_pred(Pred,N,NoPred,LstArg,CW,PredW),
	(C=[] -> (NoPred>1 -> CW=[deallocate,proceed]
	                   ;  CW=[proceed])
	      ;
	         genere_corps(C,CW)).

genere_corps([p(NoPred,Pred,LstArg,Trimming)|C],PredW):-
	gen_corps_lst_arg(LstArg,0,NoPred,CallExecuteW,PredW),
	(C=[] -> (NoPred>1 -> CallExecuteW=[deallocate,execute(Pred)]
	                   ;  CallExecuteW=[execute(Pred)])
	      ;
	         CallExecuteW=[call(Pred,Trimming)|CW],
	         genere_corps(C,CW)).




gen_corps_lst_arg([],_,_,LSuiv,LSuiv).

gen_corps_lst_arg([Arg|LstArg],Reg,NoPred,LSuiv,ArgW):-
	gen_load_arg(Arg,Reg,NoPred,LstArgW,ArgW),
	Reg1 is Reg+1,
	!,
	gen_corps_lst_arg(LstArg,Reg1,NoPred,LSuiv,LstArgW).




	/* gen_unif_arg(Arg,Reg,LSuiv,W) */

gen_unif_arg(var(igv(x(No),_,_,_,_),PremOcc,_),Reg,LSuiv,[ArgW|LSuiv]):-
	(PremOcc==t -> ArgW=get_x_variable(No,Reg)
	            ;  ArgW=get_x_value(No,Reg)).

gen_unif_arg(var(igv(y(No),_,_,_,_),PremOcc,_),Reg,LSuiv,[ArgW|LSuiv]):-
	(PremOcc==t -> ArgW=get_y_variable(No,Reg)
	            ;  ArgW=get_y_value(No,Reg)).

gen_unif_arg(cst(C),Reg,LSuiv,[get_constant(C,Reg)|LSuiv]).

gen_unif_arg(int(N),Reg,LSuiv,[get_integer(N,Reg)|LSuiv]).

gen_unif_arg(nil,Reg,LSuiv,[get_nil(Reg)|LSuiv]).

gen_unif_arg(Strc,Reg,LSuiv,StrcW):-
	gen_lst_strc([Strc/Reg],unif,LSuiv,StrcW).




	/* gen_load_arg(Arg,Reg,NoPred,LSuiv,W) */

gen_load_arg(var(igv(x(No),_,_,_,_),PremOcc,_),Reg,_,LSuiv,[ArgW|LSuiv]):-
	(PremOcc==t -> ArgW=put_x_variable(No,Reg)
	            ;  ArgW=put_x_value(No,Reg)).

gen_load_arg(var(igv(y(No),_,NoPDOcc,_,Unsafe),PremOcc,_),Reg,NoPred,LSuiv,[ArgW|LSuiv]):-
	(PremOcc==t -> ArgW=put_y_variable(No,Reg)
	            ;  (Unsafe==t, NoPred==NoPDOcc 
	                          -> ArgW=put_y_unsafe_value(No,Reg)
	                          ;  ArgW=put_y_value(No,Reg))).

gen_load_arg(cst(C),Reg,_,LSuiv,[put_constant(C,Reg)|LSuiv]).

gen_load_arg(int(N),Reg,_,LSuiv,[put_integer(N,Reg)|LSuiv]).

gen_load_arg(nil,Reg,_,LSuiv,[put_nil(Reg)|LSuiv]).

gen_load_arg(Strc,Reg,_,LSuiv,StrcW):-
	gen_lst_strc([Strc/Reg],load,LSuiv,StrcW).




	/* gen_lst_strc(LStrcReg,UL,LSuiv,W) */

gen_lst_strc([],_,LSuiv,LSuiv).

gen_lst_strc([Strc/Reg|LStrcReg],UL,LSuiv,W):-
	gen_strc(Strc,Reg,UL,W1,W2,LStrcRegAux),
	gen_lst_strc(LStrcRegAux,UL,W3,W4),
	gen_lst_strc(LStrcReg,UL,LSuiv,W5),
	(UL==unif -> W=W2, W1=W4, W3=W5
	          ;  W=W4, W3=W2, W1=W5).




gen_strc(lst(Car,Cdr),Reg,UL,LSuiv,[W|LstW],LStrcRegAux):-
	(UL==unif -> W=get_list(Reg) 
	          ;  W=put_list(Reg)),
	gen_unify_lst_arg([Car,Cdr],UL,LSuiv,LstW,LStrcRegAux).

gen_strc(stc(F,LstArg),Reg,UL,LSuiv,[W|StcW],LStrcRegAux):-
	(UL==unif -> W=get_structure(F,Reg) 
	          ;  W=put_structure(F,Reg)),
	gen_unify_lst_arg(LstArg,UL,LSuiv,StcW,LStrcRegAux).




gen_unify_lst_arg([],_,LSuiv,LSuiv,[]).

gen_unify_lst_arg([Arg|LstArg],UL,LSuiv,ArgW,LStrcRegAux1):-
	gen_compte_void([Arg|LstArg],0,N,LstArg1),
	(N=0 
	  -> gen_unify_arg(Arg,UL,LstArgW,ArgW,LStrcRegAux,LStrcRegAux1),
	     gen_unify_lst_arg(LstArg,UL,LSuiv,LstArgW,LStrcRegAux)
	  ;
	     ArgW=[unify_void(N)|LstArg1W],
	     gen_unify_lst_arg(LstArg1,UL,LSuiv,LstArg1W,LStrcRegAux1)),
	!.




gen_compte_void([var(_,t,t)|LstArg],N,N2,LstArg1):-
	N1 is N+1,
	gen_compte_void(LstArg,N1,N2,LstArg1).

gen_compte_void(LstArg,N,N,LstArg).

	          


gen_unify_arg(var(igv(x(No),NoPPOcc,_,Stc,_),PremOcc,_),_,LSuiv,[ArgW|LSuiv],
	  LStrcRegAux,LStrcRegAux):-
	(PremOcc==t -> ArgW=unify_x_variable(No)
	            ; (NoPPOcc=0, Stc==f -> ArgW=unify_x_local_value(No)
	                                 ;  ArgW=unify_x_value(No))).

gen_unify_arg(var(igv(y(No),_,_,Stc,_),PremOcc,_),_,LSuiv,[ArgW|LSuiv],
	  LStrcRegAux,LStrcRegAux):-
	(PremOcc==t  -> ArgW=unify_y_variable(No)
	             ;  (Stc==f -> ArgW=unify_y_local_value(No)
	                        ;  ArgW=unify_y_value(No))).

gen_unify_arg(cst(C),_,LSuiv,[unify_constant(C)|LSuiv],LStrcRegAux,LStrcRegAux).

gen_unify_arg(int(N),_,LSuiv,[unify_integer(N)|LSuiv],LStrcRegAux,LStrcRegAux).

gen_unify_arg(nil,_,LSuiv,[unify_nil|LSuiv],LStrcRegAux,LStrcRegAux).

gen_unify_arg(Strc,UL,LSuiv,[ArgW|LSuiv],LStrcRegAux,[Strc/Reg|LStrcRegAux]):-
	(UL==unif -> ArgW=unify_x_variable(Reg)
	          ;  ArgW=unify_x_value(Reg)).



	% Code des predicats inline : 
	%      gen_inline_pred(Pred,Arite,NoPred,LstArg,LSuiv,Code)
	% Tous les predicats definis ici doivent aussi avoir une clause
	% dans le predicat inline_predicate/3 en passe 2 definissant tous
	% les predicats inline.




	/* Cut inline ('$get_bc_reg'/1,'$cut'/1) */

gen_inline_pred('$get_bc_reg',1,_,[var(igv(Nom,_,_,_,_),PremOcc,_)],
	    LSuiv,[InstW|LSuiv]):-
	(PremOcc==f -> error('$get_bc_reg used with bound variable...')
	            ;  true),
	(Nom=x(No), InstW=get_x_bc_reg(No)
	      ; 
	 Nom=y(No), InstW=get_y_bc_reg(No)).




gen_inline_pred('$cut',1,_,[var(igv(Nom,_,_,_,_),_,_)],LSuiv,[InstW|LSuiv]):-
	(Nom=x(No), InstW=cut_x(No) 
	      ; 
	 Nom=y(No), InstW=cut_y(No)).




	/* dbg_true */

gen_inline_pred('$dbg_true',0,_,_,LSuiv,LSuiv).




	/* Pragma C (pragma_c/1) */

gen_inline_pred(pragma_c,1,_,[cst(Code)],LSuiv,[pragma_c(Code)|LSuiv]).




          /* calling module nb inline */

gen_inline_pred(calling_module_nb,1,NoPred,[Arg1],LSuiv,CodeW):-
	gen_inline_pred((=),2,NoPred,[Arg1,int('CMN')],LSuiv,CodeW).




	/* Unification inline (=/2) */

gen_inline_pred((=),2,NoPred,[Arg1,Arg2],LSuiv,UnifW):-
	(Arg1=var(igv(x(Reg),_,_,_,_),PremOcc,_) 
	   -> inline_unif_reg_terme(PremOcc,Reg,Arg2,NoPred,LSuiv,UnifW)
	   ;
	      (Arg2=var(igv(x(Reg),_,_,_,_),PremOcc,_)
	         -> inline_unif_reg_terme(PremOcc,Reg,Arg1,NoPred,
	                                  LSuiv,UnifW)
	         ;
	            gen_load_arg(Arg1,Reg,NoPred,Unif1W,UnifW),
	            inline_unif_reg_terme(PremOcc,Reg,Arg2,NoPred,
	                                  LSuiv,Unif1W))).




inline_unif_reg_terme(f,Reg,Arg,_,LSuiv,UnifW):-
	gen_unif_arg(Arg,Reg,LSuiv,UnifW).

inline_unif_reg_terme(_,Reg,Arg,NoPred,LSuiv,UnifW):-
	gen_load_arg(Arg,Reg,NoPred,LSuiv,UnifW).




          /* Type test inline */

gen_inline_pred(F,1,_,[Arg],LSuiv,TestW):-
	type_test_functor(F),
	gen_load_arg(Arg,Reg,_,InstW,TestW),
	InstW=[builtin_1(F,Reg)|LSuiv].




type_test_functor(var).
type_test_functor(nonvar).
type_test_functor(atom).
type_test_functor(integer).
type_test_functor(number).
type_test_functor(atomic).
type_test_functor(compound).
type_test_functor(callable).




          /* Term decomposition + compare/3 inline */

gen_inline_pred(F,3,_,[Arg1,Arg2,Arg3],LSuiv,TermW):-
	term_ope_functor(F),
        gen_load_arg(Arg1,Reg1,_,Term1W,TermW),
        gen_load_arg(Arg2,Reg2,_,Term2W,Term1W),
        gen_load_arg(Arg3,Reg3,_,InstW,Term2W),
        InstW=[builtin_3(F,Reg1,Reg2,Reg3)|LSuiv].




term_ope_functor(arg).
term_ope_functor(functor).
term_ope_functor(compare).




          /* Term comparison inline */

gen_inline_pred(F,2,_,[Arg1,Arg2],LSuiv,CompW):-
	term_cmp_functor_name(F,Name),
	gen_load_arg(Arg1,Reg1,_,Comp1W,CompW),
	gen_load_arg(Arg2,Reg2,_,InstW,Comp1W),
	!,
	InstW=[builtin_2(Name,Reg1,Reg2)|LSuiv].



term_cmp_functor_name((=..),term_univ).        % not a cmp but its arity is 2

term_cmp_functor_name((==), term_eq).
term_cmp_functor_name((\==),term_neq).
term_cmp_functor_name((@<), term_lt).
term_cmp_functor_name((@=<),term_lte).
term_cmp_functor_name((@>), term_gt).
term_cmp_functor_name((@>=),term_gte).




	/* Mathematical inlines (is/2 =:=/2 ...) */

gen_inline_pred(is,2,_,[Arg1,Arg2],LSuiv,MathW):-
        inline_load_math_expr(Arg2,Reg,UnifW,MathW),
        !,
        gen_unif_arg(Arg1,Reg,LSuiv,UnifW).




gen_inline_pred(F,2,_,[Arg1,Arg2],LSuiv,Math1W):-
	math_cmp_functor_name(F,Name),
	inline_load_math_expr(Arg1,Reg1,Math2W,Math1W),
	inline_load_math_expr(Arg2,Reg2,InstW, Math2W),
	!,
	InstW=[builtin_2(Name,Reg1,Reg2)|LSuiv].




inline_load_math_expr(var(igv(Nom,_,_,_,_),PremOcc,_),Reg,LSuiv,MathW):-
	(PremOcc==t 
	    -> error('Illegal arithmetic expression')
	    ;  (Nom=x(No), MathW=[math_load_x_value(No,Reg)|LSuiv]
	           ;
	        Nom=y(No), MathW=[math_load_y_value(No,Reg)|LSuiv])).

inline_load_math_expr(int(N),Reg,LSuiv,MathW):-
	MathW=[put_integer(N,Reg)|LSuiv].

inline_load_math_expr(lst(Arg,nil),Reg,LSuiv,MathW):-
	inline_load_math_expr(Arg,Reg,LSuiv,MathW).

inline_load_math_expr(stc(F/_,[Arg]),Reg,LSuiv,MathW):-
	(F== (-) -> Name=neg
                 ;  math_exp_functor_name(F,Name)),
	inline_load_math_expr(Arg,Reg1,InstW,MathW),
        (Name==add -> Reg=Reg1,
                      InstW=LSuiv
                   ;
		      InstW=[function_1(Name,Reg,Reg1)|LSuiv]).

inline_load_math_expr(stc(F/_,[Arg1,Arg2]),Reg,LSuiv,MathW):-
	math_exp_functor_name(F,Name),
	inline_load_math_expr(Arg1,Reg1,Math1W,MathW),
	(Arg2=int(1), (Name==add, Name1=inc ; Name==sub, Name1=dec) 
	      -> Math1W=InstW,
	         InstW=[function_1(Name1,Reg,Reg1)|LSuiv]
	      ;
	         inline_load_math_expr(Arg2,Reg2,InstW,Math1W),
	         InstW=[function_2(Name,Reg,Reg1,Reg2)|LSuiv]).

inline_load_math_expr(_,_,_,_):-
	error('Illegal arithmetic expression').




math_exp_functor_name((+),  add).
math_exp_functor_name((-),  sub).
math_exp_functor_name((*),  mul).
math_exp_functor_name((//), div).
math_exp_functor_name(mod,  mod).
math_exp_functor_name((/\), and).
math_exp_functor_name((\/), or).
math_exp_functor_name((^),  xor).
math_exp_functor_name((\),  not).
math_exp_functor_name((<<), shl).
math_exp_functor_name((>>), shr).


math_cmp_functor_name((=:=),eq).
math_cmp_functor_name((=\=),neq).
math_cmp_functor_name((<),  lt).
math_cmp_functor_name((=<), lte).
math_cmp_functor_name((>),  gt).
math_cmp_functor_name((>=), gte).




          /* Global variables */

gen_inline_pred(F,2,_,[Arg1,Arg2],LSuiv,GVarW):-
	g_var_functor(F),
        gen_load_arg(Arg1,Reg1,_,GVar1W,GVarW),
        gen_load_arg(Arg2,Reg2,_,InstW,GVar1W),
        InstW=[builtin_2(F,Reg1,Reg2)|LSuiv].




g_var_functor(g_assign).
g_var_functor(g_assignb).
g_var_functor(g_link).
g_var_functor(g_read).
g_var_functor(g_array_size).
