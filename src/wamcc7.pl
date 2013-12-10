/*-------------------------------------------------------------------------*/
/* Emission en mode wam                                                    */
/*                                                                         */
/* predicat d'appel: wam_emission(LPaqW).                                  */
/*                                                                         */
/* entree                                                                  */
/* LPaqW   : liste de paquets = [paq(Pred/N,[ [wam_inst,...],...]),...]    */
/*                                                                         */
/* cf explication sur code imbrique de LClW en indexation.                 */
/*                                                                         */
/*                                                                         */
/* Instructions wam produites par les passes 4 et 6                        */
/*                                                                         */
/* legende:                                                                */
/*  C, F = constantes (atomes prolog)    X = registre X (var)(entier >= 0) */
/*  I    = integer    (entier 28 bits)   A = registre A      (entier >= 0) */
/*  N    = arite      (entier >  0)      R = registre A ou X (entier >= 0) */
/*  Nb   = nombre     (entier >= 0)      Y = variable Y      (entier >= 0) */
/*  Type = private/public                WR= reg. wam (pas X)(constante)   */
/*  P    = nom fonction C du pred F/N    L = label           (entier >= 0) */
/*                                                                         */
/*                                                                         */
/*                                                                         */
/* get_x_variable(X,A)                      put_x_variable(X,A)            */
/* get_x_value(X,A)                         put_x_value(X,A)               */
/*                                                                         */
/* get_y_variable(Y,A)                      put_y_variable(Y,A)            */
/* get_y_value(Y,A)                         put_y_value(Y,A)               */
/*                                          put_y_unsafe_value(Y,A)        */
/*                                                                         */
/* get_constant(C,A)                        put_constant(C,A)              */
/* get_integer(I,A)                         put_integer(I,A)               */
/* get_nil(A)                               put_nil(A)                     */
/* get_list(R)                              put_list(R)                    */
/* get_structure(F/N,R)                     put_structure(F/N,R)           */
/*                                                                         */
/*                                                                         */
/*                                                                         */
/* unify_x_variable(X)                      allocate     {..(Nb)}          */
/* unify_x_value(X)                         deallocate                     */
/* unify_x_local_value(X)                                                  */
/*                                          call(F/N,NbY)                  */
/* unify_y_variable(Y)                      execute(F/N)                   */
/* unify_y_value(Y)                         proceed                        */
/* unify_y_local_value(Y)                   fail                           */
/*                                                                         */
/* unify_void(Nb)                                                          */
/*                                                                         */
/* unify_constant(C)                                                       */
/* unify_integer(I)                                                        */
/*                                                                         */
/*                                                                         */
/* switch_on_term(Lvar,Lcst,Lint,Llst,Lstc)                                */
/* switch_on_constant(NbCst, [(C,L),...])    {..(Lcur,NbCst,[(C,L),...])}  */
/* switch_on_integer(NbInt, [(I,L),...])     {..(Lcur,NbInt,[(I,L),...])}  */
/* switch_on_structure(NbStc,[(F/N,L),...])  {..(Lcur,NbStc,[(F/N,L),...])}*/
/*                                                                         */
/* try_me_else(L)                          try(L)                          */
/* retry_me_else(L)                        retry(L)                        */
/* trust_me_else_fail                      trust(L)                        */
/*                                                                         */
/*                                                                         */
/*                                                                         */
/* get_x_bc_reg(X)                         for debugging:                  */
/* get_y_bc_reg(Y)                         dbg_clause (start of a clause)  */
/* cut_x(X)                                dbg_body   (after get insts)    */
/* cut_y(Y)                                                                */
/*                                                                         */
/* math_load_x_value(X,A)                                                  */
/* math_load_y_value(Y,A)                                                  */
/* function_n(C,X,X1,...,Xn)                                               */
/* builtin_n(C,X1,...,Xn)                                                  */
/*                                                                         */
/* pragma_c(C_code)                                                        */
/*                                                                         */
/* Les formats entre accolades sont ceux produits en Mode c uniquement.    */
/* Pour switch_on_constant/integer/structure on trouve en 1er arg le label */
/* courant (celui ou est defini l'instruction en question). Pour try/retry */
/* on trouve en 2eme argument le label suivant (en Mode c il y a un label  */
/* apres chaque try/retry; ce n'est pas le cas en Mode wam).               */
/* Ceci est utilise pour l'emission en Mode c.                             */
/*                                                                         */
/* Au sujet des labels:                                                    */
/*                                                                         */
/*  - le label 0 n'est jamais adresse (reference)                          */
/*  - tout label reference, l'est avant d'etre defini                      */
/*  - les labels sont consecutifs (sans trous) et dans l'ordre croissant   */
/*                                                                         */
/* En mode wam on emet en plus les instructions :                          */
/*                                                                         */
/*    def_predicate(F/N,Type)                                              */
/*    def_directive                                                        */
/*    label(L)                                                             */
/*-------------------------------------------------------------------------*/

:- public wam_emission/1.

wam_emission(LPaqW):-
	g_read(fic_out,FicWam),
	tell(FicWam),
	wam_emit_lst_pred(LPaqW),
	told.




wam_emit_lst_pred([]).

wam_emit_lst_pred([paq(Pred,W)|LPaqW]):-
	wam_emit_pred(Pred,W),
	!,
	wam_emit_lst_pred(LPaqW).




wam_emit_pred(Pred/N,W):-
	nl, nl,
	(N==0, sub_atom(Pred,1,5,Prefix),
	 (Prefix=='$exe_' ; Prefix=='$dyn_')
	   -> writeq(def_directive)
	   ;
	     (test_pred_info(pub,Pred,N) -> Type=(public)
	                                 ;  Type=(private)),
	     writeq(def_predicate(Pred/N,Type))),
	write('.'), nl, nl,
	wam_emit(W,t,_),
	!,
	wam_finir_emission_inst.




wam_emit([],Prem,Prem).

wam_emit([InstW|W],Prem,Prem2):-
	(special_form(InstW,InstW1) ; InstW1=InstW),
        !,
	wam_emit(InstW1,Prem,Prem1),                    % applatit le code
	wam_emit(W,Prem1,Prem2).

wam_emit(InstW,Prem,Prem):-
	dummy_instruction(InstW).                       % cf wamcc5

wam_emit(label(Lab),_,t):-
	(Lab\==0 -> wam_finir_emission_inst
	         ;  true),
	formata('wam(~w, ',[Lab]).

wam_emit(InstW,Prem,f):-
	(Prem==t -> write('[')
	         ;  write(',')),
	nl, 
	tab(4), 
	writeq(InstW).




wam_finir_emission_inst:-
	write(']).'), nl, nl.





:- public special_form/2.

special_form(put_x_value(255,Arg),get_x_bc_reg(Arg)).

special_form(cut_x(255),neck_cut).

special_form(get_x_bc_reg(255),get_x_variable(255,255)).

