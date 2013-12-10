/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Buit-In Predicates                                   Daniel Diaz - 1994 */
/*                                                                         */
/* read/1 and friends                                                      */
/*                                                                         */
/* read.pl                                                                 */
/*-------------------------------------------------------------------------*/

:- public read_line/1, read_word/1, read_integer/1, read/1, read_term/2.


read_line(_X):-
	pragma_c('Read_Line_1').




read_word(_X):-
	pragma_c('Read_Word_1').




read_integer(_X):-
	pragma_c('Read_Integer_1').




read(_X):-
	pragma_c('Read_1').



read_term(X,L):-
	get_params(L,Vars,VarNames,SinglNames,SynErr),
	read_term(X,Vars,VarNames,SinglNames,SynErr).




read_term(_X,_Vars,_VarNames,_SinglNames,_SynErr):-
	pragma_c('Read_Term_5').




get_params([],[],[],[],dec10).

get_params([X|L],Vars,VarNames,SinglNames,SynErr):-
	get_params1(X,L,Vars,VarNames,SinglNames,SynErr).


get_params1(variables(Vars),L,Vars,VarNames,SinglNames,SynErr):-
	get_params(L,_,VarNames,SinglNames,SynErr).

get_params1(variable_names(VarNames),L,Vars,VarNames,SinglNames,SynErr):-
	get_params(L,Vars,_,SinglNames,SynErr).

get_params1(singletons(SinglNames),L,Vars,VarNames,SinglNames,SynErr):-
	get_params(L,Vars,VarNames,_,SynErr).

get_params1(syntax_errors(SynErr),L,Vars,VarNames,SinglNames,SynErr):-
	get_params(L,Vars,VarNames,SinglNames,_).




