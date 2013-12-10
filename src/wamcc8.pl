/*-------------------------------------------------------------------------*/
/* Emission en mode c                                                      */
/*                                                                         */
/* predicat d'appel:                                                       */
/*   c_emission(LPaqW,Main).                                               */
/*                                                                         */
/* entree                                                                  */
/* LPaqW     : liste de paquets = [paq(Pred/N,[ [wam_inst,...],...]),...]  */
/* Main      : no_main ou declaration de main                              */
/*-------------------------------------------------------------------------*/

:- public c_emission/2.

c_emission(LPaqW,Main):-
	c_emit_fic_c(LPaqW,Main,DicAt,DicPr,NbPrivate),
	!,
	c_emit_fic_h(DicAt,DicPr,NbPrivate),
	g_read(fic_usr,FicUsr),
	c_emit_fic_usr(FicUsr).




          /* generation: C file (.c) */

c_emit_fic_c(LPaqW,Main,DicAt,DicPr,NbPrivate):-
	g_read(fic_out,FicC),
	g_read(module,Module),
	tell(FicC),
	formata('/*~*c~n',[75,0'*]),
        display_version,
	formata('File : ~a~n',[FicC]),
	formata('Main : ~w~n',[Main]),
	formata('~*c*/~n~n',[75,0'*]),
        (g_read(fast_math,t) -> formata('#define FAST_MATH~n',[])
                             ;  true),
        g_read(debug,Debug),
	formata('#define DEBUG_LEVEL    ~d~n',[Debug]),
	nl,
	formata('#include "wam_engine.h"~n~n',[]),
	formata('#include "~a.h"~n',[Module]),
	formata('#include "~a.usr"',[Module]),
	add_to_dic_atom(DicAt,[]),
	c_emit_lst_pred(LPaqW,DicAt,DicPr),
	c_emit_fct_init_tables(DicAt,DicPr,NbPrivate),
	c_emit_fct_exec_directives,
	(Main\==no_main -> c_emit_fct_main(Main)
                        ;  true),
	told.




c_emit_lst_pred([],_,[]).

c_emit_lst_pred([paq(Pred/N,W)|LPaqW],DicAt,DicPr1):-
	add_to_dic_atom(DicAt,Pred),
	DicPr1=[p(Pred/N,LSwtCst,LSwtStc)|DicPr],
	c_emit_pred(Pred,N,LSwtCst,LSwtStc,W,DicAt),
	!,
	c_emit_lst_pred(LPaqW,DicAt,DicPr).




c_emit_pred(Pred,N,LSwtCst,LSwtStc,W,DicAt):-
	!,
	nl, nl, nl,
	c_string(Pred,CPred),
	write('#define ASCII_PRED '), write(CPred),  nl,
	write('#define PRED       '), h_write(Pred), nl,
	write('#define ARITY      '), write(N), nl, nl,
	(test_pred_info(pub,Pred,N) -> write('Begin_Public_Pred')
                                    ;  write('Begin_Private_Pred')),
        nl,
	c_emit(W,DicAt,1,_,LSwtCst,LSwtStc),
	nl, write('End_Pred'), nl, nl,
	write('#undef ASCII_PRED'),  nl,
	write('#undef PRED'),  nl,
	write('#undef ARITY'), nl.




c_emit([],_,NoSub,NoSub,[],[]).

c_emit([InstW|W],DicAt,NoSub,NoSub2,LSwtCst,LSwtStc):-
                                                          % applatit le code
	(special_form(InstW,InstW1) ; InstW1=InstW),
        !,
	c_emit(InstW1,DicAt,NoSub,NoSub1,LSwtCst1,LSwtStc1),
	c_emit(W,DicAt,NoSub1,NoSub2,LSwtCst2,LSwtStc2),
	!,
	append(LSwtCst1,LSwtCst2,LSwtCst),
	append(LSwtStc1,LSwtStc2,LSwtStc).

c_emit(InstW,_,NoSub,NoSub,[],[]):-
	dummy_instruction(InstW).                         % cf wamcc5.pl

c_emit(get_constant(C,A),DicAt,NoSub,NoSub,[],[]):-
	add_to_dic_atom(DicAt,C),
	tab(6), write('get_constant('), h_write(C),
	formata(',~d)~n',[A]).

c_emit(put_constant(C,A),DicAt,NoSub,NoSub,[],[]):-
	add_to_dic_atom(DicAt,C),
	tab(6), write('put_constant('), h_write(C),
	formata(',~d)~n',[A]).

c_emit(get_structure(F/N,R),DicAt,NoSub,NoSub,[],[]):-
	add_to_dic_atom(DicAt,F),
	tab(6), write('get_structure('), h_write(F),
	formata(',~d,~d)~n',[N,R]).

c_emit(put_structure(F/N,R),DicAt,NoSub,NoSub,[],[]):-
	add_to_dic_atom(DicAt,F),
	tab(6), write('put_structure('), h_write(F),
	formata(',~d,~d)~n',[N,R]).

c_emit(unify_constant(C),DicAt,NoSub,NoSub,[],[]):-
	add_to_dic_atom(DicAt,C),
	tab(6), write('unify_constant('), h_write(C),
	write(')'), nl.

c_emit(call(Pred/N,Trimming),_,NoSub,NoSub1,[],[]):-
	(test_pred_info(def,Pred,N) -> Local=1
                                    ;  Local=0),
	NoSub1 is NoSub+1,
	c_string(Pred,CPred),
	tab(6), write('call('), write_pred_name(Pred,N),
	formata(',~d,~d,~d,~a,~d)',[Local,Trimming,NoSub,CPred,N]),
	c_emit_header_sub_pred(NoSub).

c_emit(execute(Pred/N),_,NoSub,NoSub,[],[]):-
	(test_pred_info(def,Pred,N) -> Local=1
                                    ;  Local=0),
	c_string(Pred,CPred),
	tab(6), write('execute('), write_pred_name(Pred,N),
	formata(',~d,~a,~d)~n',[Local,CPred,N]).

c_emit(switch_on_term(LabVar,LabCst,LabInt,LabLst,LabStc),_,NoSub,NoSub,[],[]):-
	tab(6), write('switch_on_term('),
	c_emit_goto_or_fail(LabVar), write(','),
	c_emit_goto_or_fail(LabCst), write(','),
	c_emit_goto_or_fail(LabInt), write(','),
	c_emit_goto_or_fail(LabLst), write(','),
	c_emit_goto_or_fail(LabStc), write(')'), nl.

c_emit_goto_or_fail(Lab):-
	(Lab==fail -> write(fail)
                   ;
		      write('G_label'(Lab))).

c_emit(switch_on_constant(Lab,Nb,Lst),_,NoSub,NoSub,[c(Lab,Nb,Lst)],[]):-
	tab(6), write('switch_on_constant('),
	formata('~d,"~w")~n',[Lab,Lst]).

        % C switch for switch_on_integer

c_emit(switch_on_integer(_,_,Lst),_,NoSub,NoSub,[],[]):-
	tab(6), write('switch_on_integer(lst('),
        c_emit_swt_int(Lst),
	formata('),"~w")~n',[Lst]).


c_emit_swt_int([]).

c_emit_swt_int([(Int,Label)|Lst]):-
	write(i(Int,Label)), write(' '),
	c_emit_swt_int(Lst).



c_emit(switch_on_structure(Lab,Nb,Lst),_,NoSub,NoSub,[],[s(Lab,Nb,Lst)]):-
	tab(6), write('switch_on_structure('), 
	formata('~d,"~w")~n',[Lab,Lst]).

c_emit(try(Lab),_,NoSub,NoSub1,[],[]):-
	NoSub1 is NoSub+1,
	tab(6), write(try(Lab,NoSub)),
	c_emit_header_sub_pred(NoSub).

c_emit(retry(Lab),_,NoSub,NoSub1,[],[]):-
	NoSub1 is NoSub+1,
	tab(6), write(retry(Lab,NoSub)),
	c_emit_header_sub_pred(NoSub).


c_emit(label(Lab),_,NoSub,NoSub,[],[]):-
	(Lab=0 -> true
	       ;
	          nl, write(label(Lab)), nl).

c_emit(InstW,_,NoSub,NoSub,[],[]):-
	tab(6), write(InstW), nl.




c_emit_header_sub_pred(NoSub):-
	formata('          /* begin sub ~d */~n',[NoSub]).




c_emit_fct_init_tables(DicAt,DicPr,NbPrivate):-
	g_read(module,Module),
	nl, nl,
	write('Begin_Init_Tables'(Module)),       nl, nl,
	c_emit_init_tables_atom(DicAt),           nl,
	c_emit_init_tables_pred(DicPr,NbPrivate), nl,
	write(' Init_Usr_File'),                  nl, nl,
	write('End_Init_Tables'),                 nl.




c_emit_init_tables_atom([]).                        % unifie var fin de liste

c_emit_init_tables_atom([Atom|DicAt]):-
	c_string(Atom,CAtom),
	write(' Define_Atom('), h_write(Atom), 
        formata(',~a)~n',[CAtom]),
	c_emit_init_tables_atom(DicAt).




c_emit_init_tables_pred([],0).

c_emit_init_tables_pred([p(Pred/N,LSwtCst,LSwtStc)|DicPr],NbPrivate):-
	nl,
	write(' Define_Pred('), h_write(Pred), formata(',~d,',[N]),
	(test_pred_info(pub,Pred,N) -> write(1), Private=0
                                    ;  write(0), Private=1),
	write(')'), nl,
	c_emit_init_tbl_swt_cst(LSwtCst,Pred,N),
	c_emit_init_tbl_swt_stc(LSwtStc,Pred,N),
	c_emit_init_tables_pred(DicPr,NbPrivate1),
	NbPrivate is NbPrivate1+Private.




c_emit_init_tbl_swt_cst([],_,_).

c_emit_init_tbl_swt_cst([c(Lab,Nb,Lst)|LSwtCst],Pred,N):-
	write(' Define_Switch_CST_Table('),
	write_swt_table_name(Pred,N,Lab,cst),
	formata(',~d)~n',[Nb]),
	c_emit_init_swt_cst(Lst,Pred,N),
	c_emit_init_tbl_swt_cst(LSwtCst,Pred,N).




c_emit_init_swt_cst([],_,_).

c_emit_init_swt_cst([(Atom,Label)|Lst],Pred,N):-
	write('     Define_Switch_CST('), h_write(Atom),
	write(','), write_label_pred_name(Pred,N,Label),
	write(')'), nl,
	c_emit_init_swt_cst(Lst,Pred,N).

	


c_emit_init_tbl_swt_stc([],_,_).

c_emit_init_tbl_swt_stc([s(Lab,Nb,Lst)|LSwtStc],Pred,N):-
	write(' Define_Switch_STC_Table('),
	write_swt_table_name(Pred,N,Lab,stc),
	formata(',~d)~n',[Nb]),
	c_emit_init_swt_stc(Lst,Pred,N),
	c_emit_init_tbl_swt_stc(LSwtStc,Pred,N).




c_emit_init_swt_stc([],_,_).

c_emit_init_swt_stc([(Atom/N1,Label)|Lst],Pred,N):-
	write('     Define_Switch_STC('), h_write(Atom),
	formata(',~d,',[N1]), write_label_pred_name(Pred,N,Label),
	write(')'), nl,
	c_emit_init_swt_stc(Lst,Pred,N).




c_emit_fct_exec_directives:-
	g_read(module,Module),
	nl, nl,
	write('Begin_Exec_Directives'(Module)), nl, nl,
	g_read(nb_clause_dyn,NbClauseDyn),
	c_emit_exec_directives(1,NbClauseDyn,'$dyn_'), nl,
	g_read(nb_clause_exe,NbClauseExe),
	c_emit_exec_directives(1,NbClauseExe,'$exe_'), nl,
	write('End_Exec_Directives'), nl.



c_emit_exec_directives(I,N,Prefix):-
        (I=<N -> make_special_clause_head(Prefix,I,Pred),      % en wamcc0.pl
	         formata(' Exec_Directive(~d,',[I]),
		 write_pred_name(Pred,0), write(')'), nl,
		 I1 is I+1,
		 c_emit_exec_directives(I1,N,Prefix)
              ;
                 true).  




          /* generation: main() */


c_emit_fct_main(Main):-
	g_read(module,Module),
	(Main=main, LMod=[], LStack=[]
                    ;
         Main=main(LMod), LStack=[]
                    ;
         Main=main(LMod,LStack)),
        !,
        append(LMod,[Module],LMod1),
	LMod2=['Builtin'|LMod1],
	formata('~n~n/*** MAIN ***/~n~n',[]),
	formata('int main(int argc,char *argv[])~n~n{~n',[]),
        formata(' unix_argc=argc;~n',[]),
        formata(' unix_argv=argv;~n~n',[]),
	c_emit_fct_main_define_stacks(LStack),          nl,
        formata(' Init_Wam_Engine();~n~n',[]),
        c_emit_fct_main_init_tables_modules(LMod2),     nl,
	c_emit_fct_main_exec_directives_modules(LMod2), nl,
        formata(' Term_Wam_Engine();~n~n',[]),
        formata(' return 0;~n}~n',[]).




c_emit_fct_main_define_stacks([]).

c_emit_fct_main_define_stacks([stack(Name,EnvVar,Size)|LStack]):-
	formata(' Set_Stack_Defaults("~a","~a",~d);~n',[Name,EnvVar,Size]),
	c_emit_fct_main_define_stacks(LStack).




c_emit_fct_main_init_tables_modules([]).

c_emit_fct_main_init_tables_modules([ImportModule|LMod]):-
	write(' Init_Tables_Of_Module'(ImportModule)), nl,
        c_emit_fct_main_init_tables_modules(LMod).




c_emit_fct_main_exec_directives_modules([]).

c_emit_fct_main_exec_directives_modules([ImportModule|LMod]):-
	write(' Exec_Directives_Of_Module'(ImportModule)), nl,
        c_emit_fct_main_exec_directives_modules(LMod).





          /* Tools */



add_to_dic_atom(DicAt,Atom):-
	member(Atom,DicAt).




c_string(Atom,CAtom):-
	atom_codes(Atom,SAtom),
	prolog_to_c_string(SAtom,SCAtom),
	atom_codes(CAtom,[0'"|SCAtom]).




prolog_to_c_string([],[0'"]).

prolog_to_c_string([X|SAtom],SCAtom1):-
	((X=0'\; X=0'") -> SCAtom1=[0'\,X|SCAtom]
	                ;  SCAtom1=[X|SCAtom]),
	prolog_to_c_string(SAtom,SCAtom).                 




          /* generation: header file (.h) */

c_emit_fic_h(DicAt,DicPr,NbPrivate):-
	g_read(module,Module),
	g_read(fic_h,FicH),
	tell(FicH),
	formata('/*~*c~n',[75,0'*]),
        display_version,
	formata('file : ~a~n',[FicH]),
	formata('~*c*/~n~n',[75,0'*]),
	formata('#define NB_OF_PRIVATE_PREDS    ~d~n~n',[NbPrivate]),
	c_string(Module,CModule),
	formata('static char    *module_name=~a;~n',[CModule]),
	formata('static int      module_nb;~n~n',[]),
	c_emit_decl_var_atom(DicAt), nl,
	c_emit_decl_var_pred(DicPr), nl,
	told.




c_emit_decl_var_atom([]).                           % unifie var fin de liste

c_emit_decl_var_atom([Atom|DicAt]):-
	write('static AtomInf *'), h_write(Atom), write(';'), nl,
	c_emit_decl_var_atom(DicAt).




c_emit_decl_var_pred([]).                           % unifie var fin de liste

c_emit_decl_var_pred([p(Pred/N,LSwtCst,LSwtStc)|DicPr]):-
	c_emit_decl_tbl_swt(LSwtCst,cst,Pred,N),
	c_emit_decl_tbl_swt(LSwtStc,stc,Pred,N),
	c_emit_decl_var_pred(DicPr).




c_emit_decl_tbl_swt([],_,_,_).

c_emit_decl_tbl_swt([Swt|LSwt],Type,Pred,N):-
	arg(1,Swt,Lab),
	write('static SwtTbl   '),
	write_swt_table_name(Pred,N,Lab,Type), write(';'), nl,
	c_emit_decl_tbl_swt(LSwt,Type,Pred,N).




          /* generation: user file (.usr) */

c_emit_fic_usr(FicUsr):-
	unix(access(FicUsr,0)).        /* si existe deja, ne fait rien */


c_emit_fic_usr(FicUsr):-
	tell(FicUsr),
	formata('/*~*c~n',[75,0'*]),
        display_version,
	formata('file : ~a~n',[FicUsr]),
	formata('~*c*/~n~n',[75,0'*]),
	c_emit_modif_fail,
	c_emit_en_tete_init_usr, nl, nl,
	formata('{~n}~n',[]),
	c_emit_restore_fail,
	told.



c_emit_modif_fail:-
	nl,
	write('/* Above this line, put your first macros '),
	write('(these included by pragma_c) */'), nl, 
	nl,
	write('#undef  fail'), nl,
	write('#define fail Fail_Like_Bool'), nl, 
	nl,
	write('/* Below this line, put your others macros '),
	write('and your functions */'), nl,
	nl, nl.



c_emit_restore_fail:-
	nl,
	write('/* end of user file */'), nl,
	nl,
	write('#undef  fail'), nl,
	write('#define fail Fail_Like_Wam'), nl.




c_emit_en_tete_init_usr:-
	write('static void Initialize_Usr(void)').




write_pred_name(Pred,N):-
	write('Pred_Name('), h_write(Pred), 
	formata(',~d)',[N]).




write_label_pred_name(Pred,N,Lab):-
	write('Label_Pred_Name('), h_write(Pred),
	formata(',~d,~d)',[N,Lab]).




write_swt_table_name(Pred,N,Lab,Type):-
	write('Swt_Table_Name('), h_write(Pred),
	formata(',~d,~d,~a)',[N,Lab,Type]).




h_write(X):-
	atom_codes(X,Str),
	write('X'),
	h_write_hexa(Str).




h_write_hexa([]).

h_write_hexa([C|Str]):-
	formata('~16R',[C]),
	h_write_hexa(Str).





