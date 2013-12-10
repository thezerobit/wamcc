/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Buit-In Predicates                                   Daniel Diaz - 1994 */
/*                                                                         */
/* format/2                                                                */
/*                                                                         */
/* format.pl                                                               */
/*-------------------------------------------------------------------------*/

:- public format/2, formata/2.


format(S,L):-
	atom_codes(F,S),
	(L=[_|_] -> L1=L
                 ;  L1=[L]),
	formata(F,L1).




formata(_F,_L):-
	pragma_c('Formata_2').
