/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Buit-In Predicates                                   Daniel Diaz - 1994 */
/*                                                                         */
/* inline bips definitions (for call/1)                                    */
/*                                                                         */
/* inline.pl                                                               */
/*-------------------------------------------------------------------------*/

          /* for call/1, inline Built-ins (e.g. =/2) must be defined here */

:- public (=)/2.


X=X.




:- public arg/3, functor/3, (=..)/2.


arg(N,T,A):-
	arg(N,T,A).




functor(T,F,N):-
	functor(T,F,N).




T1=..T2:-
	T1=..T2.




:- public compare/3, (==)/2, (\==)/2, (@<)/2, (@=<)/2, (@>)/2, (@>=)/2.


compare(C,T1,T2):-
	compare(C,T1,T2).


X == Y:-
	X == Y.

X \== Y:-
	X \== Y.

X @< Y:-
	X @< Y.

X @=< Y:-
	X @=< Y.

X @> Y:-
	X @> Y.

X @>= Y:-
	X @>= Y.




:- public var/1, nonvar/1, atom/1, integer/1, number/1, atomic/1, 
          compound/1, callable/1.


var(X):-
	var(X).

nonvar(X):-
	nonvar(X).

atom(X):-
	atom(X).

integer(X):-
	integer(X).

number(X):-
	number(X).

atomic(X):-
	atomic(X).

compound(X):-
	compound(X).

callable(X):-
	callable(X).




:- public is/2, (=:=)/2, (=\=)/2, (<)/2, (=<)/2, (>)/2, (>=)/2, eval/2.

Var is ExpX:-
	eval(ExpX,X),
	Var=X.

ExpX =:= ExpY:-
	eval(ExpX,X),
	eval(ExpY,Y),
	X =:= Y.

ExpX =\= ExpY:-
	eval(ExpX,X),
	eval(ExpY,Y),
	X =\= Y.

ExpX < ExpY:-
	eval(ExpX,X),
	eval(ExpY,Y),
	X < Y.

ExpX =< ExpY:-
	eval(ExpX,X),
	eval(ExpY,Y),
	X =< Y.

ExpX > ExpY:-
	eval(ExpX,X),
	eval(ExpY,Y),
	X > Y.

ExpX >= ExpY:-
	eval(ExpX,X),
	eval(ExpY,Y),
	X >= Y.




eval(Exp,V):-
	eval1(Exp,V),
	!.

eval(Exp,_):-
	write('Error: '), write(Exp),
	write(' Illegal arithmetic expression'), nl,
	fail.



eval1(Exp,_):-
	var(Exp),
	!,
	fail.

eval1(Exp,Exp):-
	integer(Exp).

eval1([ExpX],V):-
	eval1(ExpX,V).

eval1(+(ExpX),V):-
	eval1(ExpX,V).

eval1(-(ExpX),V):-
	eval1(ExpX,X),
	V is -X.

eval1(ExpX + ExpY,V):-
	eval1(ExpX,X),
	eval1(ExpY,Y),
	V is X + Y.

eval1(ExpX - ExpY,V):-
	eval1(ExpX,X),
	eval1(ExpY,Y),
	V is X - Y.

eval1(ExpX * ExpY,V):-
	eval1(ExpX,X),
	eval1(ExpY,Y),
	V is X * Y.

eval1(ExpX // ExpY,V):-
	eval1(ExpX,X),
	eval1(ExpY,Y),
	V is X // Y.

eval1(ExpX mod ExpY,V):-
	eval1(ExpX,X),
	eval1(ExpY,Y),
	V is X mod Y.

eval1(ExpX /\ ExpY,V):-
	eval1(ExpX,X),
	eval1(ExpY,Y),
	V is X /\ Y.

eval1(ExpX \/ ExpY,V):-
	eval1(ExpX,X),
	eval1(ExpY,Y),
	V is X \/ Y.

eval1(ExpX ^ ExpY,V):-
	eval1(ExpX,X),
	eval1(ExpY,Y),
	V is X ^ Y.

eval1(\(ExpX),V):-
	eval1(ExpX,X),
	V is \(X).

eval1(ExpX << ExpY,V):-
	eval1(ExpX,X),
	eval1(ExpY,Y),
	V is X << Y.

eval1(ExpX >> ExpY,V):-
	eval1(ExpX,X),
	eval1(ExpY,Y),
	V is X >> Y.



:- public g_assign/2, g_assignb/2, g_link/2, g_read/2, g_array_size/2.


g_assign(Var,Value):-
	g_assign(Var,Value).




g_assignb(Var,Value):-
	g_assignb(Var,Value).




g_link(Var,Value):-
	g_link(Var,Value).




g_read(Var,Value):-
	g_read(Var,Value).




g_array_size(Var,Type):-
	g_array_size(Var,Type).


