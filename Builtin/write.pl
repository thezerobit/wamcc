/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Buit-In Predicates                                   Daniel Diaz - 1994 */
/*                                                                         */
/* write/1 and friends                                                     */
/*                                                                         */
/* write.pl                                                                */
/*-------------------------------------------------------------------------*/

          /* write term */

:- public write/1, writeq/1, write_canonical/1, write_term/2.


write(_X):-
	pragma_c('Write_1').




writeq(_X):-
	pragma_c('Writeq_1').




write_canonical(_X):-
	pragma_c('Write_Canonical_1').




write_term(X,L):-
        get_params(L,Depth,Quote,Op,NumberVars),
	write_term(X,Depth,Quote,Op,NumberVars).



write_term(_X,_Depth,_Quote,_Op,_NumberVars):-
	pragma_c('Write_Term_5').




get_params([],-1,0,1,1).

get_params([X|L],Depth,Quote,Op,NumberVars):-
        get_params1(X,L,Depth,Quote,Op,NumberVars).


get_params1(max_depth(Depth),L,Depth,Quote,Op,NumberVars):-
	integer(Depth),
        get_params(L,_,Quote,Op,NumberVars).

get_params1(quoted(B),L,Depth,Quote,Op,NumberVars):-
	(B==false -> Quote=0
                  ;  Quote=1),
        get_params(L,Depth,_,Op,NumberVars).

get_params1(ignore_ops(B),L,Depth,Quote,Op,NumberVars):-
	(B==true  -> Op=0
                  ;  Op=1),
        get_params(L,Depth,Quote,_,NumberVars).

get_params1(numbervars(B),L,Depth,Quote,Op,NumberVars):-
	(B==false -> NumberVars=0
                  ;  NumberVars=1),
        get_params(L,Depth,Quote,Op,_).




          /* pretty print a clause */

:- public pp_clause/1, pp_clause/2.

pp_clause(C):-
	(C=(H:-B) ; C=H, B=true),
	!,
	pp_clause(H,B).




pp_clause(H,B):-
	numbervars(H,0,N),
	numbervars(B,N,_),
	writeq(H),
	 (B\==true -> write(' :-'), nl, tab(8), pp_body(B,8)
                   ;  true),
	 write('.'), nl.




pp_body((P,Q),N):-
	!,
	pp_body(P,N),
	write(','), 
	nl, tab(N),
	pp_body(Q,N).

pp_body((P->Q),N):-
	!,
	pp_body(P,N),
	write(' ->'), nl, tab(N),
	pp_body(Q,N).

pp_body((P;Q),N):-
	!,
	N1 is N+4,
	write('(   '),
	pp_body(P,N1),
	nl, tab(N), write(';   '),
	pp_body_or(Q,N),
	nl, tab(N), write(')').

pp_body(P,_):-
	writeq(P).




pp_body_or((P;Q),N):-
	!,
	N1 is N+4,
	pp_body(P,N1),
	nl, tab(N), write(';   '),
	pp_body_or(Q,N).

pp_body_or(P,N):-
	pp_body(P,N).




          /* number variables */

:- public numbervars/3.

numbervars(X,N,N1):-
	var(X),
	!,
	X='$VAR'(N),
	N1 is N+1.

numbervars(X,N,N1):-
	atomic(X),
	!,
	N1=N.

numbervars([X|Xs],N,N2):- 
	!,
        numbervars(X,N,N1),
        numbervars(Xs,N1,N2).

numbervars(X,N,N1):-
        functor(X,_,A),
        numbervars(0,A,X,N,N1).

numbervars(I,A,X,N,N2):-
	(I=:=A -> N2=N 
               ;
                  I1 is I+1,
		  arg(I1,X,X1),
		  numbervars(X1,N,N1),
		  numbervars(I1,A,X,N1,N2)).
