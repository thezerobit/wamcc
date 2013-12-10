/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Buit-In Predicates                                   Daniel Diaz - 1994 */
/*                                                                         */
/* Dynamic code management                                                 */
/*                                                                         */
/* assert.pl                                                               */
/*-------------------------------------------------------------------------*/


          /* dynamic clauses (assert, retract, clause, abolish,...) */

:- public asserta/1, assertz/1, clause/2, clause1/1, retract/1, 
          abolish/1, abolish/2,
          reinit_predicate/1, reinit_predicate/2.


asserta(C):-
	(C=(H:-B) ; C=H, B=true),
	!,
	asserta1([H|B]).

asserta1(_C):-
	pragma_c('Asserta1_1').




assertz(C):-
	(C=(H:-B) ; C=H, B=true),
	!,
	assertz1([H|B]).

assertz1(_C):-
	pragma_c('Assertz1_1').




clause(H,B):-
	clause1([H|B]).

clause1(_C):-
	pragma_c('Clause1_1').




retract(C):-
	(C=(H:-B) ; C=H, B=true),
	!,
	clause1([H|B]),
	pragma_c('Retract_0').




abolish(F/N):-
	abolish(F,N).


abolish(_F,_N):-
	pragma_c('Abolish_2').




reinit_predicate(F/N):-
	reinit_predicate(F,N,2).

reinit_predicate(F,N):-
	reinit_predicate(F,N,2).

reinit_predicate(_F,_N,_WhatToDo):-
	pragma_c('Reinit_Predicate_3').




          /* consult */

:- public '.'/2, consult/1.


[File|Files]:-
        consult(File),
        consult(Files).




consult([]):-
	!.

consult([File|Files]):-
        !,
        consult(File),
        consult(Files).

consult(File):-
	pragma_c('New_Consult_0'),
        (File==user -> File1=user
                    ;  prolog_file_name(File,File1)),
        see(File1),
        repeat,
        read_term(C,[singletons(SingNames)]),
	(C\==end_of_file
             -> (C=(:- Direc) -> exec_directive(Direc)
                              ;  add_clause(C,SingNames)),
                fail
             ;
                !,
                seen).




prolog_file_name(File,File1):-
        atom_length(File,L),
        P is L-2,
        (sub_atom(File,P,3,'.pl') 
              -> File1=File
              ;  atom_concat(File,'.pl',File1)).




exec_directive(C):-
	functor(C,F,N),
	((F==main, N=<2) ; (F==(public), N==1)),
        formata('Warning: directive <~w> ignored~n',[C]),
        !.

exec_directive(C):-
        (call(C) -> true
                 ;  formata('Warning: directive <~w> failed~n',[C])).




add_clause(C,SingNames):-
	(C=(H:-B) ; C=H, B=true),
	!,
	functor(H,F,N),
	get_singletons(SingNames,Sing),
	(Sing\==[]
            -> formata('{Warning: ~w - singleton variables in ~a/~d}~n',
                       [Sing,F,N])
            ;  true),
	reinit_predicate(F,N,1),
	assertz1([H|B]).




get_singletons([],[]).

get_singletons([X=_|SingNames],Sing1):-
        (sub_atom(X,1,1,'_') -> Sing1=Sing
                             ;  Sing1=[X|Sing]),
        get_singletons(SingNames,Sing).




          /* listing */

:- public listing/1.

listing(F/N):-
	functor(H,F,N),
	(clause(H,B),
	 pp_clause(H,B),
	 fail
           ;
         true).



