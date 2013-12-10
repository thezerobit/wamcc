/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Buit-In Predicates                                   Daniel Diaz - 1994 */
/*                                                                         */
/* List library                                                            */
/*                                                                         */
/* list.pl                                                                 */
/*-------------------------------------------------------------------------*/


:- public append/3, member/2, memberchk/2, reverse/2, 
	  delete/3, select/3, permutation/2,
	  prefix/2, suffix/2, sublist/2, last/2,
	  length/2, nth/3, min_list/2, max_list/2, sum_list/2.


append([],L,L).

append([H|T1],List,[H|T2]):-
        append(T1,List,T2).




member(X,[H|T]):-
        X=H ; member(X,T).


memberchk(X,[H|T]):-
        X=H, ! ; memberchk(X,T).




reverse([],[]).

reverse([H|T],L):-
        reverse1(T,L,[H]).


reverse1([],L,L).

reverse1([H|T],L,L1):-
        reverse1(T,L,[H|L1]).




delete([],_,[]).

delete([H|T],X,L):-
        H==X,
	!,
        delete(T,X,L).

delete([H|T],X,[H|L]):-
        delete(T,X,L).





select(X,[X|T],T).

select(X,[H|T1],[H|T2]):-
        select(X,T1,T2).





permutation([],[]).

permutation(L,[H|T]):-
        select(H,L,Rest),
        permutation(Rest,T).





prefix([],_).

prefix([X|T],[X|T1]):-
        prefix(T,T1).




suffix(L,L).

suffix(X,[_|T]):-
        suffix(X,T).




sublist(L,L).

sublist(Sub,[H|T]):-
	sublist1(T,H,Sub).


sublist1(Sub,_,Sub).

sublist1([H|T],_,Sub):-
	sublist1(T,H,Sub).

sublist1([H|T],X,[X|Sub]):-
	sublist1(T,H,Sub).




last([H|T],X):-
	last1(T,H,X).

last1([],X,X).

last1([H|T],_,X):-
	last1(T,H,X).





length(L,N):-
        integer(N),
        !,
        N>=0,
        make_list(N,L).

length(L,N):-
        length(L,0,N).


length([],N,N).

length([_|L],M,N):-
        M1 is M+1,
        length(L,M1,N).




make_list(0,[]):-
        !.

make_list(N,[_|L]):-
        N1 is N-1,
        make_list(N1,L).




nth(N,L,X):-
        integer(N),!,
        N>=1,
	nth1(N,L,X).

nth(N,L,X):-
        var(N),
        nth2(L,X,1,N).


nth1(1,[X|_],X):-
	!.

nth1(N,[_|T],X):-
	N1 is N-1,
	nth1(N1,T,X).


nth2([X|_],X,N,N).

nth2([_|T],X,I,N):-
	I1 is I+1,
	nth2(T,X,I1,N).




max_list([H|T],Max):-
        max_list1(T,H,Max).

max_list1([],Max,Max).

max_list1([H|T],X,Max):-
        H=<X,
	!,
        max_list1(T,X,Max).

max_list1([H|T],_,Max):-
        max_list1(T,H,Max).




min_list([H|T],Min):-
        min_list1(T,H,Min).

min_list1([],Min,Min).

min_list1([H|T],X,Min):-
        H>=X,
	!,
        min_list1(T,X,Min).

min_list1([H|T],_,Min):-
        min_list1(T,H,Min).





sum_list(L,Sum):-
        sum_list1(L,0,Sum).

sum_list1([],Sum,Sum).

sum_list1([H|T],Sum0,Sum):-
        Sum1 is H+Sum0,
        sum_list1(T,Sum1,Sum).

