/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Buit-In Predicates                                   Daniel Diaz - 1994 */
/*                                                                         */
/* file i/o                                                                */
/*                                                                         */
/* inout.pl                                                                */
/*-------------------------------------------------------------------------*/

:- public nl/0, get0/1, get/1, skip/1, put/1, tab/1.


nl:-	pragma_c('Nl_0').




get0(_X):-
	pragma_c('Get0_1').




get(_X):-
	pragma_c('Get_1').




skip(_X):-
	pragma_c('Skip_1').




put(_X):-
	pragma_c('Put_1').




tab(_X):-
	pragma_c('Tab_1').




:- public see/1, seen/0, seeing/1, tell/1, told/0, telling/1.


see(_X):-
	pragma_c('See_1').



seen:-	pragma_c('Seen_0').




seeing(_X):-
	pragma_c('Seeing_1').



tell(_X):-
	pragma_c('Tell_1').



told:-	pragma_c('Told_0').



telling(_X):-
	pragma_c('Telling_1').






