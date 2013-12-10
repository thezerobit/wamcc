/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Buit-In Predicates                                   Daniel Diaz - 1994 */
/*                                                                         */
/* Constant processing                                                     */
/*                                                                         */
/* const.pl                                                                */
/*-------------------------------------------------------------------------*/

:- public atom_length/2, atom_concat/3,  sub_atom/4,
          char_code/2,   number_atom/2,  atom_codes/2, 
          chars_codes/2, number_codes/2, number_chars/2, 
          atom_chars/2,  name/2.



atom_length(_A,_L):-
	pragma_c('Atom_Length_2').




atom_concat(A1,A2,A3):-
	atom_concat_det(A1,A2,A3,Code),   /* Code:0=fail, 1=det, 2=non det */
	(Code==1 -> true
                 ;  Code==2, atom_concat_non_det(A1,A2,A3)).


atom_concat_det(_A1,_A2,_A3,_Code):-
	pragma_c('Atom_Concat_Det_4').


atom_concat_non_det(A1,A2,A3):-
	atom_codes(A3,LCodeA3),
	append(LCodeA1,LCodeA2,LCodeA3),
	atom_codes(A1,LCodeA1),
	atom_codes(A2,LCodeA2).




sub_atom(A,S,L,A1):-
	atom_codes(A,LCodeA),
	atom_length(A,N),
	(integer(S) -> S>=1, S=<N
                    ;  list_i_j(1,N,SL), member(S,SL)),
        NX0 is S-1,
	(integer(L) -> true
                    ;  
		       MaxL is N-NX0,
                       list_i_j(0,MaxL,LL), member(L,LL)),
	length(LCodeA1,L),
	length(X0,NX0),
	NX2 is N-L-NX0,
	length(X2,NX2),
	append(X1,X2,LCodeA),
	append(X0,LCodeA1,X1),
	atom_codes(A1,LCodeA1).




list_i_j(I,J,L):-
	(I>J -> L=[]
              ;  
                 I1 is I+1,
                 L=[I|L1],
		 list_i_j(I1,J,L1)).




char_code(_Char,_Code):-
	pragma_c('Char_Code_2').




number_atom(_N,_A):-
	pragma_c('Number_Atom_2').



atom_codes(_A,_LCode):-
	pragma_c('Atom_Codes_2').




chars_codes([],[]).

chars_codes([Char|LChar],[Code|LCode]):-
	char_code(Char,Code),
	chars_codes(LChar,LCode).




number_codes(N,LCode):-
	(nonvar(N) -> number_atom(N,A),
                      atom_codes(A,LCode)
                   ;
                      nonvar(LCode),
                      atom_codes(A,LCode),
                      number_atom(N,A)).




number_chars(N,LChar):-
	(nonvar(N) -> number_codes(N,LCode),
                      chars_codes(LChar,LCode)
                   ;
                      nonvar(LChar),
                      chars_codes(LChar,LCode),
                      number_codes(N,LCode)).




atom_chars(A,LChar):-
	(nonvar(A) -> atom_codes(A,LCode),
                      chars_codes(LChar,LCode)
                   ;
                      nonvar(LChar),
                      chars_codes(LChar,LCode),
                      atom_codes(A,LCode)).





name(X,LCode):-
	(number_codes(X,LCode) -> true
                               ;  atom_codes(X,LCode)).





