/*-------------------------------------------------------------------------*/
/* Lecture du fichier source                                               */
/*                                                                         */
/* predicat d'appel:                                                       */
/*   lire_fichier(FicIn,LSrc,Main).                                        */
/*                                                                         */
/* entree                                                                  */
/* FicIn     : nom du programme prolog a compiler                          */
/*                                                                         */
/* sortie                                                                  */
/* LSrc      : liste des clauses du programme                              */
/* Main      : no_main ou declaration de main                              */
/*                                                                         */
/* traitement des directives:                                              */
/*                                                                         */
/* Les directives :- public...  maj les infos d'un predicat (cf fin de fic)*/
/* Les directives :- dynamic... maj les infos d'un predicat (cf fin de fic)*/
/*                                                                         */
/* On verifie si dans une directive il y a une declaration d'operateur     */
/* (op/3), si c'est le cas elle est executee.                              */
/*                                                                         */
/* Toutes les autres directives sont transformees en:                      */
/*                                                                         */
/* :- Corps1. devient '$exe_1':- Corps1, !.                                */
/* :- Corps2. devient '$exe_2':- Corps2, !.                                */
/*       :                                                                 */
/* :- Corpsk. devient '$exe_k':- Corpsk, !.                                */
/*                                                                         */
/* Chaque directive est transformee en clause dont la tete est unique car  */
/* on utilise un numero sequentiel. Au moment de l'emission du code les    */
/* clause '$exe_i' seront distinguees.                                     */
/* L'ajout du ! en fin provient du fait qu'il n'y a pas de backtracking    */
/* sur les directives.                                                     */
/*                                                                         */
/* Les clause ClSrc d'un predicat dynamique sont transformees en clauses : */
/* '$dyn_j':- assertz(ClSrC).                                              */
/* Les appels a un predicat dynamique P sont transformes en call(P).       */
/*-------------------------------------------------------------------------*/

:- public lire_fichier/2.

lire_fichier(LSrc,Main):-
        g_read(file_nb,FileNb),
        FileNb1 is FileNb+1,
	g_assign(file_nb,FileNb1),
	g_read(fic_in,FicIn),
	g_assign(nb_clause_exe,0),
	g_assign(nb_clause_dyn,0),
	see(FicIn),
	read_term(ClSrc,[singletons(SingNames),syntax_errors(fail)]),
	lire_clauses(ClSrc,SingNames,LSrc,Main),
	!,
	seen.




lire_clauses(end_of_file,_,LSrc,Main):-
	!,                                            % cut important
	(var(Main) -> Main=no_main,
		      LSrc=[]
                   ;  
		      make_special_clause(nb_clause_exe,'$exe_',
                                          top_level(true,true),Directive),
		      LSrc=[Directive]).

lire_clauses((:- public P),_,LSrc,Main):-
	!,                                            % cut important
	read_term(ClSrc1,[singletons(SingNames1),syntax_errors(fail)]),
	lire_clauses(ClSrc1,SingNames1,LSrc,Main),
	def_flag_for_preds(P,pub).

lire_clauses((:- dynamic P),_,LSrc,Main):-
	!,                                            % cut important
	read_term(ClSrc1,[singletons(SingNames1),syntax_errors(fail)]),
	lire_clauses(ClSrc1,SingNames1,LSrc,Main),
	def_flag_for_preds(P,dyn).

lire_clauses((:- C),_,LSrc,Main):-
	!,                                            % cut important
	(functor(C,main,_) 
            -> Main=C,
	       LSrc=LSrc1
	    ;
	       traite_op(C),
	       make_special_clause(nb_clause_exe,'$exe_',(C,!),Directive),
	       LSrc=[Directive|LSrc1]),
	read_term(ClSrc1,[singletons(SingNames1),syntax_errors(fail)]),
	lire_clauses(ClSrc1,SingNames1,LSrc1,Main).

lire_clauses(ClSrc,SingNames,[ClSrc|LSrc],Main):-
	(ClSrc=(H:-_) ; ClSrc=H),
	functor(H,F,N),
	!,
        set_pred_info(def,F,N),
	get_singletons(SingNames,Sing),
	(Sing\==[] 
            -> formata('{Warning: ~w - singleton variables in ~a/~d}~n',
                       [Sing,F,N])
            ;  true),
	read_term(ClSrc1,[singletons(SingNames1),syntax_errors(fail)]),
	lire_clauses(ClSrc1,SingNames1,LSrc,Main).




traite_op((P,Q)):-                                % on ne traite pas (P;Q).
	traite_op(P),
	traite_op(Q).
	                           
traite_op(op(X,Y,Z)):-                            % on execute op/3
	op(X,Y,Z).

traite_op(_).




get_singletons([],[]).

get_singletons([X=_|SingNames],Sing1):-
	(sub_atom(X,1,1,'_') -> Sing1=Sing
                             ;  Sing1=[X|Sing]),
	get_singletons(SingNames,Sing).




def_flag_for_preds((P1,P2),Flag):-
	def_flag_for_preds(P1,Flag),
	def_flag_for_preds(P2,Flag).

def_flag_for_preds(P/N,Flag):-
	set_pred_info(Flag,P,N).




:- public make_special_clause/4, make_special_clause_head/3.

make_special_clause(CounterName,Prefix,C,(Head:-C)):-
	g_read(CounterName,X),
	X1 is X+1,
	g_assign(CounterName,X1),
	make_special_clause_head(Prefix,X1,Head).




make_special_clause_head(Prefix,I,Head):-
	number_atom(I,IA),
	atom_concat(Prefix,IA,Head).





          /* info: dynamic   public   defined   file nb  */
          /*  bit:   18        17        16       15-0   */

:- public pred_name_to_gvar_name/3.

pred_name_to_gvar_name(F,N,GVar):-
	number_atom(N,An),
	atom_concat(F,'/',F1),
	atom_concat(F1,An,GVar).





:- public set_pred_info/3, test_pred_info/3.

set_pred_info(Flag,F,N):-
	flag_bit(Flag,Bit),
        set_bit(F,N,Bit).



flag_bit(def,16).
flag_bit(pub,17).
flag_bit(dyn,18).


 
set_bit(F,N,Bit):-
	pred_name_to_gvar_name(F,N,GVar),
        g_read(GVar,X),
	g_read(file_nb,FileNb),
	(FileNb =:= X/\65535 
	    -> X1 is (1<<Bit)\/X
            ;  X1 is (1<<Bit)\/FileNb),
	g_assign(GVar,X1).




test_pred_info(Flag,F,N):-
	flag_bit(Flag,Bit),
        test_bit(F,N,Bit).




test_bit(F,N,Bit):-
	pred_name_to_gvar_name(F,N,GVar),
        g_read(GVar,X),
	g_read(file_nb,FileNb),
        FileNb=:=(X/\65535),
        X/\(1<<Bit)>0.

