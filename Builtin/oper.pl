/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Buit-In Predicates                                   Daniel Diaz - 1994 */
/*                                                                         */
/* operator predicates                                                     */
/*                                                                         */
/* oper.pl                                                                 */
/*-------------------------------------------------------------------------*/

:- public op/3.

op(Prec,Assoc,Oper):-
        atom(Oper),
	!,
	op2(Oper,Prec,Assoc).

op(Prec,Assoc,LOper):-
	op1(LOper,Prec,Assoc).


op1([],_,_).

op1([Oper|LOper],Prec,Assoc):-
	op2(Oper,Prec,Assoc),
	op1(LOper,Prec,Assoc).


op2(_X,_Prec,_Assoc):-
	pragma_c('Op2_3').




:-	op(1200, xfx,[(:-)]),
	op(1200,  fx,[(:-)]),
	op(1150,  fx,[(public),(dynamic)]),
	op(1100, xfy,[';']),
	op(1050, xfy,['->']),
	op(1000, xfy,[',']),
	op( 900,  fy,[(\+),(spy),(nospy)]),
	op( 700, xfx,[(=),(is),(=..),
                      (==),(\==),(@<),(@>),(@=<),(@>=),
                      (=:=),(=\=),(<),(=<),(>),(>=)]),
	op( 500, yfx,[(+),(-),(/\),(\/)]),
	op( 500,  fx,[(+),(-)]),
	op( 400, yfx,[(*),(/),(//),(<<),(>>)]),
	op( 300, xfx,[(mod)]),
	op( 200, xfy,[(^)]),
	fail ; true.                     % gc 

