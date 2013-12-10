/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Compiler                                             Daniel Diaz - 1991 */
/*                                                                         */
/* predicat d'appel: wamcc(CommandLine)                                    */
/*                                                                         */
/* entree                                                                  */
/* CommandLine: a file name or a list of options and file names            */
/*                                                                         */
/* Generalites:                                                            */
/*                                                                         */
/* !    : Les seuls cuts (!) indispensables sont signales (% cut important)*/
/*        ils sont au nombre de 5 en debut de programme. TOUS les autres   */
/*        cuts peuvent etre supprimes, ils ne sont la que pour eviter de   */
/*        trop empiler de points de choix inutiles.                        */
/*                                                                         */
/* Fin  : Cette variable est utilisee pour faire des ajouts en fin de liste*/
/*        en temps constant. L'idee est d'utiliser une liste terminee par  */
/*        cette variable Fin, et de garder celle-ci "a portee de main".    */
/*        Pour ajouter un element E a la liste L il suffit d'unifier la    */
/*        variable Fin avec [E|Fin1]. La nouvelle variable Fin sera Fin1.  */
/*        Lorsqu'il n'y a plus d'elements a inserer il suffit d'unifier la */
/*        variable Fin courante avec [].                                   */
/*                                                                         */
/* LSuiv: LSuiv est une liste a placer en fin de liste resultat. Elle sert */
/*        a eviter un append. Exemple:                                     */
/*                                                                         */
/*        au lieu de:                                                      */
/*           f(L1,L2,R) :- trait(L1,R1), trait(L2,R2), append(R1,R2,R).    */
/*                                                                         */
/*           trait([],[]).                                                 */
/*           trait([E|L],[E1|R]):- modif(E,E1),trait(L,R).                 */
/*                                                                         */
/*        on ecrit:                                                        */
/*           f(L1,L2,R1):- trait(L1,R2,R1), trait(L2,[],R2).               */
/*                                                                         */
/*           trait([],LSuiv,LSuiv).                                        */
/*           trait([E|L],LSuiv,[E1|R]):- modif(E,E1), trait(L,LSuiv,R).    */
/*                                                                         */
/* global variables (g_assign/2, g_read/2):                                */
/*                                                                         */
/* options:mode_c=t/f  fast_math=t/f  no_inline=t/f  debug=0-2  verbose=t/f*/
/*                                                                         */
/* others: module, fic_in, fic_out, fic_h, fic_usr (files)                 */
/*         file_nb: file counter (as a key for info about predicates)      */
/*         aux (auxiliary counter)                                         */
/*         nb_clause_exe ('$exe_i' clause counter, i.e. directives)        */
/*         nb_clause_dyn ('$dyn_j' clause counter, i.e. dynamic clauses)   */
/*-------------------------------------------------------------------------*/

:- main([wamcc0,wamcc1,wamcc2,wamcc3,wamcc4,wamcc5,wamcc6,wamcc7,wamcc8]).


wamcc(CmdLine):-
	(cmd_line(CmdLine,LFic)
              -> (g_read(verbose,t) -> display_version
	                            ;  true),
	         compile1(LFic)
	      ;
                 display_version,
                 display_help, 
		 error('')).




compile1([]):-
	!.                                            % cut important

compile1([Fic|LFic]):-
	!,                                            % cut important
	(compile2(Fic), fail ; true),                 % gc
	compile1(LFic).


compile2(Fic):-
	cree_noms_fic(Fic),
        (g_read(verbose,t) -> g_read(fic_in,FicIn),
	                      formata('Compiling ~w...~n',[FicIn])
                           ;  true),
	g_assign(aux,1),
	lire_fichier(LSrc,Main),
	compiler(LSrc,Main),
	!.                                            % cut important

compile2(_):- 
	seen, 
	told, 
	error('        ... Fail').




cree_noms_fic(Fic):-
	atom_length(Fic,L),
	P is L-2,
	(sub_atom(Fic,P,3,'.pl') -> L1 is P-1,
                                    sub_atom(Fic,1,L1,Prefix),
				    FicIn=Fic
                                 ;
                                    Prefix=Fic,
                                    atom_concat(Prefix,'.pl',FicIn)),
	(g_read(mode_c,t) -> atom_concat(Prefix,'.c',FicOut),
   	                     atom_concat(Prefix,'.h',FicH),
			     atom_concat(Prefix,'.usr',FicUsr)
                          ;
			     atom_concat(Prefix,'.wam',FicOut),
			     FicH=null,
			     FicUsr=null),
	base_name(Prefix,Module),
	g_assign(module,Module),
	g_assign(fic_in,FicIn),
	g_assign(fic_out,FicOut),
	g_assign(fic_h,FicH),
	g_assign(fic_usr,FicUsr).




base_name(Prefix,Module):-
	(sub_atom(Prefix,P,1,'/') -> atom_length(Prefix,L),
	                             P1 is P+1,
				     L1 is L-P,
	                             sub_atom(Prefix,P1,L1,Prefix1),
				     base_name(Prefix1,Module)
                                  ;
				     Module=Prefix).




cmd_line(CmdLine,LFic):-
        ((CmdLine=[_|_] ; CmdLine==[]) -> CmdLine1=CmdLine
                                       ;  CmdLine1=[CmdLine]),
	set_default_options,
	cmd_line1(CmdLine1,LFic).


cmd_line1([],[]).

cmd_line1([Opt|CmdLine],LFic):-
        (Opt= -Opt1, !
             ;
	 sub_atom(Opt,1,1,'-'), !,
         atom_length(Opt,L), L1 is L-1, sub_atom(Opt,2,L1,Opt1)),
	traite_opt(Opt1),
	cmd_line1(CmdLine,LFic).

cmd_line1([Fic|CmdLine],[Fic|LFic]):-
	cmd_line1(CmdLine,LFic).




set_default_options:-
	g_assign(mode_c,    t),
        g_assign(fast_math, f),
        g_assign(no_inline, f),
        g_assign(debug,     0),
        g_assign(verbose,   f).




traite_opt(c):-         g_assign(mode_c,    t).
traite_opt(wam):-       g_assign(mode_c,    f).
traite_opt(fast_math):- g_assign(fast_math, t).
traite_opt(no_inline):- g_assign(no_inline, t).
traite_opt(dbg0):-      g_assign(debug,     0).
traite_opt(dbg):-       g_assign(debug,     1).
traite_opt(dbg1):-      g_assign(debug,     1).
traite_opt(dbg2):-      g_assign(debug,     2).
traite_opt(v):-         g_assign(verbose,   t).




:- public display_version/0.

display_version:-
	!,
	ProgramCmt='Prolog to Wam Compiler',
        wam_version(V),
	wam_year(Y),
	name(ProgramCmt,SProgramCmt),
	length(SProgramCmt,LC),
	name(V,SV),
	length(SV,LV),
	DC is 40-LC,
	DV is 45-LV,
	formata('~s~*c   INRIA Rocquencourt - ChLoE Project~n',[SProgramCmt,DC,32]),
	formata('Version ~s~*c      Daniel Diaz - ~d~n~n',[SV,DV,32,Y]).




display_help:-
	compiler_name(Name),
	formata('Usage:~n~n',[]),
        formata('   ~w [option | filename]...~n~n',[Name]),
	formata('Options:~n~n',[]),
	formata('   -c         produce a .c   file~n',[]),
	formata('   -wam       produce a .wam file~n',[]),
	formata('   -fast_math do not test types in math expressions~n',[]),
	formata('   -no_inline do not inline any builtin predicates~n',[]),
	formata('   -dbg       compile for prolog debugging~n',[]),
	formata('   -dbg2      compile for prolog and wam debugging~n',[]),
	formata('   -v         verbose mode~n',[]),
	formata('   -h         display help~n',[]).





compiler(LSrc,Main):-
	g_read(mode_c,ModeC),
	exec_passes(LSrc,LClComp),                                  !,
	cree_paquets(LClComp,LPaq),                                 !,
	exec_indexation(LPaq,LPaqW),                                !,
	(ModeC==f
	   ->  wam_emission(LPaqW)
	   ;   c_emission(LPaqW,Main)).




exec_passes([],[]).

exec_passes([ClSrc|LSrc],[clcomp(Pred,Arg1,W)|LClComp]):-
	sucre_syntaxique(ClSrc,LSrc,ClSrc1,LSrc1),                  !,
	format_interne(ClSrc1,Arg1,T,C,NbChunk),                    !,
	classif_variables(T,C),                                     !,
	generation_code(T,C,NbChunk,Pred,W),                        !,
	allocation_varsX(W),                                        !,
	exec_passes(LSrc1,LClComp).




cree_paquets([],[]).

cree_paquets([ClComp|LClComp],LPaq1):-
	cree_paquets(LClComp,LPaq),
	ajout_clause(LPaq,ClComp,LPaq1),
	!.




ajout_clause(LPaq,ClComp,[Paq|LPaq1]):-             % replace paquet devant
	trouve_paquet(LPaq,ClComp,Paq,LPaq1).




trouve_paquet([],clcomp(Pred,Arg1,W),paq(Pred,[Cl]),[]):-
	format_index(Arg1,W,Cl).

trouve_paquet([paq(Pred,LCl)|LPaq],clcomp(Pred,Arg1,W),paq(Pred,[Cl|LCl]),LPaq):- 
	format_index(Arg1,W,Cl).

trouve_paquet([Paq|LPaq],ClComp,Paq1,[Paq|LPaq1]):-
	trouve_paquet(LPaq,ClComp,Paq1,LPaq1).




format_index(Arg1,W,cl(_,Arg1,W)).                    % pour indexation




exec_indexation([],[]).

exec_indexation([paq(Pred,LCl)|LPaq],[paq(Pred,LClW)|LPaqW]):-
	indexation(LCl,LClW),
	!,
	exec_indexation(LPaq,LPaqW).




/*--- Gestion des ensembles (sans unification) ----------------------------*/

:- public ens_ajout/3, ens_retrait/3,
          ens_elt/2, ens_inter/3,  ens_union/3, ens_compl/3.

ens_ajout([],X,[X]).

ens_ajout([Y|L],X,[Y|L]):-
	X==Y, 
	!.

ens_ajout([Y|L],X,[Y|L1]):- 
	ens_ajout(L,X,L1).




ens_retrait([Y|L],X,L):-                % ens_retrait(L,X,L1) echoue si
        X==Y,                           % X n'appartient pas a L
        !.

ens_retrait([Y|L],X,[Y|L1]):-
        ens_retrait(L,X,L1).




ens_elt([Y|_],X):-
	X==Y, 
	!.

ens_elt([_|L],X):-
	ens_elt(L,X).




ens_inter([],_,[]).

ens_inter([X|L1],L2,[X|L3]):-
	ens_elt(L2,X), 
	!, 
	ens_inter(L1,L2,L3).

ens_inter([_|L1],L2,L3):-
	ens_inter(L1,L2,L3).




ens_union([],L2,L2).

ens_union([X|L1],L2,L3):-
	ens_elt(L2,X),
	!,
	ens_union(L1,L2,L3).

ens_union([X|L1],L2,[X|L3]):-
	ens_union(L1,L2,L3).




ens_compl([],_,[]).

ens_compl([X|L],L1,L3):-
	(ens_elt(L1,X) -> L3=L2
                       ;  L3=[X|L2]),
        ens_compl(L,L1,L2).




/*--- Erreurs -------------------------------------------------------------*/

:- public error/1.

error(Err):-
	write(Err), nl,
	abort.




/*--- Unix interface ------------------------------------------------------*/

go:- unix(argv(L)), (L\==[] -> wamcc(L), halt_or_else(0,true) ; true).

:- go.


