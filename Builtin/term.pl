/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Buit-In Predicates                                   Daniel Diaz - 1994 */
/*                                                                         */
/* Term handling                                                           */
/*                                                                         */
/* term.pl                                                                 */
/*-------------------------------------------------------------------------*/


          /* Term copy */

:- public copy_term/2.


copy_term(_T1,_T2):-
	pragma_c('Term_Copy_2').




          /* sub-term destructive assignment */

:- public setarg/3.


setarg(_I,_T,_V):-
	pragma_c('Setarg_3').




          /* Term sorting (from O'Keefe public domain code) */

:- public sort/2, keysort/2.


sort([],L):-
	!,
	L=[].

sort([A],L):-		                              	       % optimisation
	!,
	L=[A].

sort(List,Sorted):-
	sort(List,[],0,Sorted).


sort([],Stack,_,Sorted):-
	samfuse(Stack,0,[Sorted]).

sort([Head],Stack,_,Sorted):-
	!,		% optimisation
	samfuse([[Head]|Stack],0,[Sorted]).

sort([Head|Tail],Stack,R,Sorted):-
	Qh = [Head|_],
	samrun(Tail,Qh,Qh,Run,Rest),
	S is R+1,
	samfuse([Run|Stack],S,NewStack),
	sort(Rest,NewStack,S,Sorted).




samfuse([A,B|Rest],K,Ans):-
	0 is K /\ 1,
	!,
	J is K >> 1,
	merge(B,A,C),				% B before A for stability
	samfuse([C|Rest],J,Ans).

samfuse(Stack,_,Stack).




% samrun(List,Q1,Q2,Run,Rest)

% List is a list of elements,Rest is some tail of that list,
% Run is an ordered _set_ of the difference between List and Rest,
% Q1 is the cons containing the first element of List.

% Q2 is the last cons of Run.


samrun([H|Tail],QH,QT,Run,Rest):-
	QT = [Q|_],
	compare(X,H,Q),
	samrunt(X,H,QH,QT,QH1,QT1),
	!,
        samrun(Tail,QH1,QT1,Run,Rest).

samrun(Rest,Run,[_],Run,Rest).


samrunh(<,H,QH,[H|QH]).

samrunh(=,_,QH,QH).


samrunt(<,H,QH,QT,QH1,QT):-
	QH = [Q|_],
	compare(X,H,Q),
	samrunh(X,H,QH,QH1).

samrunt(=,_,QH,QT,QH,QT).

samrunt(>,H,QH,[_|QT],QH,QT):-
	QT = [H|_].




merge([],L,Out):-
	!,
	Out=L.

merge(L,[],Out):-
	!,
	Out=L.

merge(L1,L2,Out):-
	L1 = [H1|_],
	L2 = [H2|_],
	compare(X,H1,H2),
	merge(X,L1,L2,Out).


merge(<,[H1|L1],L2,[H1|Out]):-
	merge(L1,L2,Out).

merge(=,[_|L1],L2,Out):-
	merge(L1,L2,Out).

merge(>,L1,[H2|L2],[H2|Out]):-
	merge(L1,L2,Out).




keysort([],Out):-
	!,
	Out=[].

keysort([A],Out):-	             	                   % optimisation
	!,
	Out=[A].

keysort(List,Sorted):-
	keysort(List,[],0,Sorted).


keysort([],Stack,_,Sorted):-
	samkeyfuse(Stack,0,[Sorted]).

keysort([Head],Stack,_,Sorted):-
	!,		% optimisation
	samkeyfuse([[Head]|Stack],0,[Sorted]).

keysort([Head|Tail],Stack,R,Sorted):-
	Qh = [Head|_],
	samkeyrun(Tail,Qh,Qh,Run,Rest),
	S is R+1,
	samkeyfuse([Run|Stack],S,NewStack),
	keysort(Rest,NewStack,S,Sorted).




samkeyfuse([A,B|Rest],K,Ans):-
	0 is K /\ 1,!,
	J is K >> 1,
	keymerge(B,A,C),			% B before A for stability
	samkeyfuse([C|Rest],J,Ans).

samkeyfuse(Stack,_,Stack).




% samkeyrun(List,Q1,Q2,Run,Rest)
% List is a list of pairs K-V,Rest is some tail of that list,
% Run is an ordered _list_ of the difference between List and Rest,
% Q1 is the cons containing the first element of List.

% Q2 is the last cons of Run.


samkeyrun([Hd|Tail],QH,QT,Run,Rest):-
	Hd = H-_,
	QT = [Q-_|QT2],
	H @>= Q,!,
	QT2 = [Hd|_],
	samkeyrun(Tail,QH,QT2,Run,Rest).

samkeyrun([Hd|Tail],QH,QT,Run,Rest):-
	Hd = H-_,
	QH = [Q-_|_],
	H @< Q,!,
	samkeyrun(Tail,[Hd|QH],QT,Run,Rest).

samkeyrun(Rest,Run,[_],Run,Rest).




keymerge(L1,[],Out):-
	!,
	Out=L1.

keymerge([],L2,Out):-
	!,
	Out=L2.

keymerge([H1|T1],L2,Out):-	
	H1 = K1-_,
	L2 = [K2-_|_],
	K1 @=< K2,!,
	Out = [H1|Out1],
	keymerge(T1,L2,Out1).

keymerge(L1,[H2|L2],[H2|Out]):-
	keymerge(L1,L2,Out).


