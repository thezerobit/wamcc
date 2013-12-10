/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Buit-In Predicates                                   Daniel Diaz - 1994 */
/*                                                                         */
/* debug predicates                                                        */
/*                                                                         */
/* trace.pl                                                                */
/*-------------------------------------------------------------------------*/

:- public debug/0, trace/0, nodebug/0, notrace/0, debug_mode/1, debugging/0,
          leash/1.

debug:-
	debug_mode(debug).

trace:-
	debug_mode(trace).

nodebug:-
	debug_mode(nodebug).

notrace:-
	debug_mode(nodebug).

debug_mode(_X):-
	pragma_c('Debug_Mode_1').

debugging:-
	pragma_c('Debug_Display_Infos();').




leash(L):-
	leash1(L),
	pragma_c('Debug_Display_Leashing();').


leash1([]):-
	pragma_c('Debug_Add_Leash_Mode(NULL);').

leash1([X|L]):-
	leash1(L),                             % do not reverse these 2 lines
	leash2(X).


leash2(_X):-
	pragma_c('Leash2_1').




:- public (spy)/1, (nospy)/1, nospyall/0.


spy(X/N):-
	spy1(X,N),
	debug_mode(D),
	(D==nodebug -> debug
                    ;  true).


spy1(_X,_N):-
	pragma_c('Spy1_2').




nospy(X/N):-
	nospy1(X,N).

nospy1(_X,_N):-
	pragma_c('Nospy1_2').




nospyall:-
	pragma_c('Debug_Remove_Spy_Point(NULL,0);').

