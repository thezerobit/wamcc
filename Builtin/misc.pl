/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Buit-In Predicates                                   Daniel Diaz - 1994 */
/*                                                                         */
/* Miscellaneous                                                           */
/*                                                                         */
/* misc.pl                                                                 */
/*-------------------------------------------------------------------------*/


	/* statistics */

:- public statistics/0, statistics/2.


statistics:- 
	pragma_c('Display_Statistics();').



statistics(_S,_L):-
	pragma_c('Statistics_2').




          /* gensym */

:- public gensym/1, gensym/2.

gensym(X):-
	gensym('$sym',X).



gensym(Prefix,X):-
	g_read(Prefix,Count),
	Count1 is Count+1,
	g_assign(Prefix,Count1),
	number_atom(Count,X1),
	atom_concat(Prefix,X1,X).




          /* version */

:- public version/0, compiler_name/1, wam_version/1, wam_year/1.


version:-
	pragma_c('Display_Version();').




compiler_name(_C):-
	pragma_c('get_constant(atom_compiler,0)').




wam_version(_V):-
	pragma_c('get_constant(atom_wam_version,0)').




wam_year(_D):-
	pragma_c('get_integer(WAM_YEAR,0)').




	/* Unix Arguments */

:- public argc/1, argv/2.


argc(_N):-
	pragma_c('Argc_1').

argv(_N,_A):-
	pragma_c('Argv_2').




          /* unix interface */


:- public unix/1.

unix(access(P,M)):-
	unix_access(P,M).

unix(argv(A)):-
	unix_argv(A).

unix(cd):-
	unix_getenv('HOME',P),
	unix_cd(P).

unix(cd(P)):-
	unix_cd(P).

unix(exit(S)):-
	halt(S).

unix(getenv(N,V)):-
	unix_getenv(N,V).

unix(shell):-
	unix_shell(_,_).

unix(shell(C)):-
	unix_shell(C,_).

unix(shell(C,S)):-
	unix_shell(C,S).

unix(system(C)):-
	unix_system(C,_).

unix(system(C,S)):-
	unix_system(C,S).




unix_access(_P,_M):-
	pragma_c('Unix_Access_2').




unix_argv(A):-
	argc(N),
	unix_argv1(1,N,A).    /* unix_argv1 without arg[0] (i.e. prg name) */


unix_argv1(I,N,A):-
	(I==N -> A=[]
              ;
                 argv(I,X),
		 A=[X|A1],
		 I1 is I+1,
		 unix_argv1(I1,N,A1)).




unix_cd(_P):-
	pragma_c('Unix_Cd_1').




unix_getenv(_N,_V):-
	pragma_c('Unix_Getenv_2').



unix_shell(C,S):-
	(unix_getenv('SHELL',ShName) ; ShName='/bin/sh'),
	!,
	atom_concat('exec ',ShName,C0),
	(var(C) -> Cmd=C0
                ;
                   atom_concat(C0,' -c ',C1),
		   atom_concat(C1,C,Cmd)),
	unix_system(Cmd,S).



unix_system(_C,_S):-
	pragma_c('Unix_System_2').

