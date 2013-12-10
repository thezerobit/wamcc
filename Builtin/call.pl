/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Buit-In Predicates                                   Daniel Diaz - 1994 */
/*                                                                         */
/* call/1 and other control predicates                                     */
/*                                                                         */
/* call.pl                                                                 */
/*-------------------------------------------------------------------------*/


	/* Control */

:- public otherwise/0, true/0, false/0, fail/0, repeat/0, for/3,
   halt/0, halt/1, halt_or_else/1, halt_or_else/2, abort/0.


otherwise.

true.

false:-	fail.

fail:-	fail.


repeat.
repeat:-
	repeat.



for(A,A,B):-
	A=<B.

for(I,A,B):-
	A<B,
	A1 is A+1,
	for(I,A1,B).




halt:-	halt(0).




halt(_S):-
	pragma_c('Halt_1').




halt_or_else(P):-
	halt_or_else(0,P).

halt_or_else(S,P):-
	(g_read('$top_level',0) -> halt(S)
                                ;  call(P)).




abort:-
	nodebug,
	halt_or_else(1,throw(abort)).




:- public dbg_exec/0.


dbg_exec:-
	write('| :-'),
	read(X),
	(X==end_of_file
              ;
         call(X)
              ;
         formata('{Warning: ~w - goal failed}~n',[X])),
	!.




:- public (^)/2, call/1, call/2.


_^Goal:-
	Goal.




call(P):-
	calling_module_nb(Module),
        '$get_bc_reg'(VarCut),
	call1(P,VarCut,Module).


call(P,Module):-
        '$get_bc_reg'(VarCut),
	call1(P,VarCut,Module).


call1(X,_,_):-
	var(X),
	!,
	write('Error: variable given as goal'), nl,
	fail.

call1(true,_,_):-
	!.

call1((P,Q),VarCut,Module):-
	!, 
	call1(P,VarCut,Module),
	call1(Q,VarCut,Module).

call1((P;Q),VarCut,Module):-
	!,
	pragma_c('Debug_Call("call_or_$aux",4,1);'),
	call_or(P,Q,VarCut,Module).

call1(!,VarCut,_):- 
%           !,          this cut is useless because Meta_Cut
        '$cut'(VarCut).

call1((P->Q),VarCut,Module):- 
	!,
	call(P,Module),
	!,
	call1(Q,VarCut,Module).

call1(\+P,_,Module):- 
	!, 
	(call(P,Module), !, fail; true).

call1(_P,_VarCut,_Module):-
	pragma_c('Call1_3').




/*--- this code is already in call.usr to add an extra Y variable ---

call_dynamic(P,_,Module):-
	'$get_bc_reg'(VarCut),
        pragma_c('Debug_Call(NULL,0,1);'),
	clause1([P|B]),
	pragma_c('Debug_Dynamic_Body();'),
        call1(B,VarCut,Module),
	pragma_c('Debug_Proceed(TRUE);').

--------------------------------------------------------------------*/




call_or((P->Q),R,VarCut,Module):-
	!,
	(call(P,Module),
	 !,
	 call1(Q,VarCut,Module) 
	   ;
         pragma_c('Debug_Has_Failed_Redo();'), 
	 call1(R,VarCut,Module)).
	
call_or(P,_,VarCut,Module):-
	call1(P,VarCut,Module).

call_or(_,Q,VarCut,Module):-
	pragma_c('Debug_Has_Failed_Redo();'),
	call1(Q,VarCut,Module).




          /* catch and throw */

:- public catch/3, catch/4, throw/1, catch_signal/1, signal_handler/1.


catch(Goal,Catch,Recovery):-
	calling_module_nb(Module),
	catch(Goal,Catch,Recovery,Module).


catch(Goal,Catch,Recovery,Module):-
	g_assign('$ball_','$no_ball_'),
	g_read('$handler_',Handler),
	catch1(Goal,Catch,Recovery,Module,Handler).


catch1(Goal,_,_,Module,Handler):-
	get_current_B(B),
	g_assign('$handler_',B),
	call(Goal,Module),
        get_current_B(B1),
	(B1>B -> trail_handler(B)
              ;  !),
	g_assign('$handler_',Handler).

catch1(_,Catch,Recovery,Module,Handler):-
	g_assign('$handler_',Handler),
	g_read('$ball_',Ball),
	Ball\=='$no_ball_',
	(Catch=Ball -> g_assign('$ball_','$no_ball_'),
                       call(Recovery,Module)
                    ;
                       unwind(Ball)).




trail_handler(_).
trail_handler(Handler):-
	g_assign('$handler_',Handler),
	fail.




throw(Ball):-
	g_assign('$ball_',Ball),
	unwind(Ball).



unwind(Ball):-
	g_read('$handler_',Handler),
	(Handler=:=0 
            -> formata('~nsystem error - cannot catch ~w~n',[throw(Ball)]),
	       halt_or_else(2,abort)
            ;  set_current_B(Handler),
	       fail).




catch_signal(_Sig):-
	pragma_c('Catch_Signal_1').




signal_handler(Sig):-
	throw(signal(Sig)).




          /* top level */

:- public top_level/2, 
   top_level2/1, '$after_throw'/3.      % should be prefixed with module name
                                        % at call time


top_level(Banner,Catch):-                /* top_level/1 catches everything */
	calling_module_nb(Module),
        (Banner==true -> version
                      ;  true),
	g_read('$top_level',Top),
	Top1 is Top+1,
	g_assign('$top_level',Top1),
	top_level1(Module,Catch),
	g_assign('$top_level',Top).
	                   

top_level1(Module,Catch):-
	catch(top_level2(Module),X,'$after_throw'(X,Module,Catch),Module).




'$after_throw'(X,Module,Catch):-
        (Catch==true -> nodebug,
	                seen,
			formata('~n{~w}~n',[X]), 
			top_level1(Module,Catch)
                     ;
	                g_read('$top_level',Top),
			Top1 is Top-1,
			g_assign('$top_level',Top1),
			throw(X)).



top_level2(Module):-
	repeat,
	write_debug_indicator,
	write('| ?- '),
	read_term(X,[variable_names(VarNames)]),
	(X==end_of_file -> nodebug,
                           nl,
	                   !
                        ;
                           (exec(X,VarNames,Module) -> nl, write(yes), nl
                                                    ;  nl, write(no),  nl),
			   debug_mode(DbgMode),             % read debug mode
			   debug_mode(DbgMode),             % reinit debugger
			   fail).




write_debug_indicator:-
	debug_mode(DebugMode),
	write_debug_indicator(DebugMode).


write_debug_indicator(debug):-
	write('{debug}'), nl.

write_debug_indicator(trace):-
	write('{trace}'), nl.

write_debug_indicator(nodebug).




exec(X,VarNames,Module):-
	get_current_B(B),
	call(X,Module),
	get_current_B(B1),
	write_solution(VarNames),
	(B1>B -> write(' ? '),
                 read_command(C),
		 C==10
              ;
                 true).




read_command(C):-
	get0(C1),
	skip_until_return(C1),
	(C1==10 -> C=C1
                ;  
		   (C1\==0'; -> write('Action (";" for more choices, '),
		                write('otherwise <return>): '),
                                read_command(C)
                             ;  C=C1)).




skip_until_return(C):-
	(C==10 -> true
               ;
                  get0(C1),
		  skip_until_return(C1)).




write_solution([]).

write_solution([X=V|L]):-
	formata('~n~a = ',[X]),
	write_term(V,[quoted(true),numbervars(false)]),
	write_solution(L).




:- public get_current_B/1, set_current_B/1.

get_current_B(_B):-
	pragma_c('Get_Current_B_1').




set_current_B(_B):-
	pragma_c('Set_Current_B_1').




:- catch_signal(2),        % SIGINT
   catch_signal(3).        % SIGQUIT

