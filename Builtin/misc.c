/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : misc.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "misc.h"
#include "misc.usr"


#define ASCII_PRED "statistics"
#define PRED       X73746174697374696373
#define ARITY      0

Begin_Public_Pred
      pragma_c(Display_Statistics();)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "statistics"
#define PRED       X73746174697374696373
#define ARITY      2

Begin_Public_Pred
      pragma_c(Statistics_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gensym"
#define PRED       X67656E73796D
#define ARITY      1

Begin_Public_Pred
      get_x_variable(1,0)
      put_constant(X2473796D,0)
      execute(Pred_Name(X67656E73796D,2),1,"gensym",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gensym"
#define PRED       X67656E73796D
#define ARITY      2

Begin_Public_Pred
      allocate(3)
      get_y_variable(2,0)
      get_y_variable(0,1)
      put_y_value(2,2)
      put_x_variable(0,1)
      builtin_2(g_read,2,1)
      math_load_x_value(0,0)
      function_1(inc,1,0)
      put_y_value(2,2)
      builtin_2(g_assign,2,1)
      put_y_variable(1,1)
      call(Pred_Name(X6E756D6265725F61746F6D,2),0,3,1,"number_atom",2)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X61746F6D5F636F6E636174,3),0,"atom_concat",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "version"
#define PRED       X76657273696F6E
#define ARITY      0

Begin_Public_Pred
      pragma_c(Display_Version();)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "compiler_name"
#define PRED       X636F6D70696C65725F6E616D65
#define ARITY      1

Begin_Public_Pred
      pragma_c(get_constant(atom_compiler,0))
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wam_version"
#define PRED       X77616D5F76657273696F6E
#define ARITY      1

Begin_Public_Pred
      pragma_c(get_constant(atom_wam_version,0))
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wam_year"
#define PRED       X77616D5F79656172
#define ARITY      1

Begin_Public_Pred
      pragma_c(get_integer(WAM_YEAR,0))
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "argc"
#define PRED       X61726763
#define ARITY      1

Begin_Public_Pred
      pragma_c(Argc_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "argv"
#define PRED       X61726776
#define ARITY      2

Begin_Public_Pred
      pragma_c(Argv_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "unix"
#define PRED       X756E6978
#define ARITY      1

Begin_Public_Pred
      switch_on_term(G_label(3),G_label(1),fail,fail,G_label(2))

label(1)
      switch_on_constant(1,"[(cd,8),(shell,16)]")

label(2)
      switch_on_structure(2,"[(access/2,4),(argv/1,6),(cd/1,10),(exit/1,12),(getenv/2,14),(shell/1,18),(shell/2,20),(system/1,22),(system/2,24)]")

label(3)
      try_me_else(5)

label(4)
      get_structure(X616363657373,2,0)
      unify_x_variable(0)
      unify_x_variable(1)
      execute(Pred_Name(X756E69785F616363657373,2),1,"unix_access",2)

label(5)
      retry_me_else(7)

label(6)
      get_structure(X61726776,1,0)
      unify_x_variable(0)
      execute(Pred_Name(X756E69785F61726776,1),1,"unix_argv",1)

label(7)
      retry_me_else(9)

label(8)
      allocate(1)
      get_constant(X6364,0)
      put_constant(X484F4D45,0)
      put_y_variable(0,1)
      call(Pred_Name(X756E69785F676574656E76,2),1,1,1,"unix_getenv",2)          /* begin sub 1 */
      put_y_unsafe_value(0,0)
      deallocate
      execute(Pred_Name(X756E69785F6364,1),1,"unix_cd",1)

label(9)
      retry_me_else(11)

label(10)
      get_structure(X6364,1,0)
      unify_x_variable(0)
      execute(Pred_Name(X756E69785F6364,1),1,"unix_cd",1)

label(11)
      retry_me_else(13)

label(12)
      get_structure(X65786974,1,0)
      unify_x_variable(0)
      execute(Pred_Name(X68616C74,1),0,"halt",1)

label(13)
      retry_me_else(15)

label(14)
      get_structure(X676574656E76,2,0)
      unify_x_variable(0)
      unify_x_variable(1)
      execute(Pred_Name(X756E69785F676574656E76,2),1,"unix_getenv",2)

label(15)
      retry_me_else(17)

label(16)
      get_constant(X7368656C6C,0)
      put_x_variable(0,0)
      put_x_variable(1,1)
      execute(Pred_Name(X756E69785F7368656C6C,2),1,"unix_shell",2)

label(17)
      retry_me_else(19)

label(18)
      get_structure(X7368656C6C,1,0)
      unify_x_variable(0)
      put_x_variable(1,1)
      execute(Pred_Name(X756E69785F7368656C6C,2),1,"unix_shell",2)

label(19)
      retry_me_else(21)

label(20)
      get_structure(X7368656C6C,2,0)
      unify_x_variable(0)
      unify_x_variable(1)
      execute(Pred_Name(X756E69785F7368656C6C,2),1,"unix_shell",2)

label(21)
      retry_me_else(23)

label(22)
      get_structure(X73797374656D,1,0)
      unify_x_variable(0)
      put_x_variable(1,1)
      execute(Pred_Name(X756E69785F73797374656D,2),1,"unix_system",2)

label(23)
      trust_me_else_fail

label(24)
      get_structure(X73797374656D,2,0)
      unify_x_variable(0)
      unify_x_variable(1)
      execute(Pred_Name(X756E69785F73797374656D,2),1,"unix_system",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "unix_access"
#define PRED       X756E69785F616363657373
#define ARITY      2

Begin_Private_Pred
      pragma_c(Unix_Access_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "unix_argv"
#define PRED       X756E69785F61726776
#define ARITY      1

Begin_Private_Pred
      allocate(2)
      get_y_variable(0,0)
      put_y_variable(1,0)
      call(Pred_Name(X61726763,1),1,2,1,"argc",1)          /* begin sub 1 */
      put_integer(1,0)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X756E69785F6172677631,3),1,"unix_argv1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "unix_argv1"
#define PRED       X756E69785F6172677631
#define ARITY      3

Begin_Private_Pred
      execute(Pred_Name(X756E69785F61726776315F2461757831,3),1,"unix_argv1_$aux1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "unix_argv1_$aux1"
#define PRED       X756E69785F61726776315F2461757831
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      builtin_2(term_eq,0,1)
      neck_cut
      get_nil(2)
      proceed

label(1)
      trust_me_else_fail
      allocate(4)
      get_y_variable(1,0)
      get_y_variable(0,1)
      get_y_variable(3,2)
      put_y_value(1,0)
      put_y_variable(2,1)
      call(Pred_Name(X61726776,2),1,4,1,"argv",2)          /* begin sub 1 */
      put_y_value(3,0)
      get_list(0)
      unify_y_local_value(2)
      unify_x_variable(2)
      math_load_y_value(1,0)
      function_1(inc,0,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X756E69785F6172677631,3),1,"unix_argv1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "unix_cd"
#define PRED       X756E69785F6364
#define ARITY      1

Begin_Private_Pred
      pragma_c(Unix_Cd_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "unix_getenv"
#define PRED       X756E69785F676574656E76
#define ARITY      2

Begin_Private_Pred
      pragma_c(Unix_Getenv_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "unix_shell"
#define PRED       X756E69785F7368656C6C
#define ARITY      2

Begin_Private_Pred
      allocate(6)
      get_y_variable(3,0)
      get_y_variable(0,1)
      get_y_bc_reg(5)
      put_y_variable(4,0)
      call(Pred_Name(X756E69785F7368656C6C5F2461757832,1),1,6,1,"unix_shell_$aux2",1)          /* begin sub 1 */
      cut_y(5)
      put_constant(X6578656320,0)
      put_y_unsafe_value(4,1)
      put_y_variable(2,2)
      call(Pred_Name(X61746F6D5F636F6E636174,3),0,4,2,"atom_concat",3)          /* begin sub 2 */
      put_y_value(3,0)
      put_y_unsafe_value(2,1)
      put_y_variable(1,2)
      call(Pred_Name(X756E69785F7368656C6C5F2461757833,3),1,2,3,"unix_shell_$aux3",3)          /* begin sub 3 */
      put_y_unsafe_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X756E69785F73797374656D,2),1,"unix_system",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "unix_shell_$aux3"
#define PRED       X756E69785F7368656C6C5F2461757833
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      builtin_1(var,0)
      neck_cut
      get_x_value(1,2)
      proceed

label(1)
      trust_me_else_fail
      allocate(3)
      get_y_variable(1,0)
      get_y_variable(0,2)
      put_x_value(1,0)
      put_constant(X202D6320,1)
      put_y_variable(2,2)
      call(Pred_Name(X61746F6D5F636F6E636174,3),0,3,1,"atom_concat",3)          /* begin sub 1 */
      put_y_unsafe_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X61746F6D5F636F6E636174,3),0,"atom_concat",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "unix_shell_$aux2"
#define PRED       X756E69785F7368656C6C5F2461757832
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      get_x_variable(1,0)
      put_constant(X5348454C4C,0)
      execute(Pred_Name(X756E69785F676574656E76,2),1,"unix_getenv",2)

label(1)
      trust_me_else_fail
      get_constant(X2F62696E2F7368,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "unix_system"
#define PRED       X756E69785F73797374656D
#define ARITY      2

Begin_Private_Pred
      pragma_c(Unix_System_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(misc)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X73746174697374696373,"statistics")
 Define_Atom(X67656E73796D,"gensym")
 Define_Atom(X2473796D,"$sym")
 Define_Atom(X76657273696F6E,"version")
 Define_Atom(X636F6D70696C65725F6E616D65,"compiler_name")
 Define_Atom(X77616D5F76657273696F6E,"wam_version")
 Define_Atom(X77616D5F79656172,"wam_year")
 Define_Atom(X61726763,"argc")
 Define_Atom(X61726776,"argv")
 Define_Atom(X756E6978,"unix")
 Define_Atom(X616363657373,"access")
 Define_Atom(X6364,"cd")
 Define_Atom(X484F4D45,"HOME")
 Define_Atom(X65786974,"exit")
 Define_Atom(X676574656E76,"getenv")
 Define_Atom(X7368656C6C,"shell")
 Define_Atom(X73797374656D,"system")
 Define_Atom(X756E69785F616363657373,"unix_access")
 Define_Atom(X756E69785F61726776,"unix_argv")
 Define_Atom(X756E69785F6172677631,"unix_argv1")
 Define_Atom(X756E69785F61726776315F2461757831,"unix_argv1_$aux1")
 Define_Atom(X756E69785F6364,"unix_cd")
 Define_Atom(X756E69785F676574656E76,"unix_getenv")
 Define_Atom(X756E69785F7368656C6C,"unix_shell")
 Define_Atom(X6578656320,"exec ")
 Define_Atom(X756E69785F7368656C6C5F2461757833,"unix_shell_$aux3")
 Define_Atom(X202D6320," -c ")
 Define_Atom(X756E69785F7368656C6C5F2461757832,"unix_shell_$aux2")
 Define_Atom(X5348454C4C,"SHELL")
 Define_Atom(X2F62696E2F7368,"/bin/sh")
 Define_Atom(X756E69785F73797374656D,"unix_system")


 Define_Pred(X73746174697374696373,0,1)

 Define_Pred(X73746174697374696373,2,1)

 Define_Pred(X67656E73796D,1,1)

 Define_Pred(X67656E73796D,2,1)

 Define_Pred(X76657273696F6E,0,1)

 Define_Pred(X636F6D70696C65725F6E616D65,1,1)

 Define_Pred(X77616D5F76657273696F6E,1,1)

 Define_Pred(X77616D5F79656172,1,1)

 Define_Pred(X61726763,1,1)

 Define_Pred(X61726776,2,1)

 Define_Pred(X756E6978,1,1)
 Define_Switch_CST_Table(Swt_Table_Name(X756E6978,1,1,cst),2)
     Define_Switch_CST(X6364,Label_Pred_Name(X756E6978,1,8))
     Define_Switch_CST(X7368656C6C,Label_Pred_Name(X756E6978,1,16))
 Define_Switch_STC_Table(Swt_Table_Name(X756E6978,1,2,stc),9)
     Define_Switch_STC(X616363657373,2,Label_Pred_Name(X756E6978,1,4))
     Define_Switch_STC(X61726776,1,Label_Pred_Name(X756E6978,1,6))
     Define_Switch_STC(X6364,1,Label_Pred_Name(X756E6978,1,10))
     Define_Switch_STC(X65786974,1,Label_Pred_Name(X756E6978,1,12))
     Define_Switch_STC(X676574656E76,2,Label_Pred_Name(X756E6978,1,14))
     Define_Switch_STC(X7368656C6C,1,Label_Pred_Name(X756E6978,1,18))
     Define_Switch_STC(X7368656C6C,2,Label_Pred_Name(X756E6978,1,20))
     Define_Switch_STC(X73797374656D,1,Label_Pred_Name(X756E6978,1,22))
     Define_Switch_STC(X73797374656D,2,Label_Pred_Name(X756E6978,1,24))

 Define_Pred(X756E69785F616363657373,2,0)

 Define_Pred(X756E69785F61726776,1,0)

 Define_Pred(X756E69785F6172677631,3,0)

 Define_Pred(X756E69785F61726776315F2461757831,3,0)

 Define_Pred(X756E69785F6364,1,0)

 Define_Pred(X756E69785F676574656E76,2,0)

 Define_Pred(X756E69785F7368656C6C,2,0)

 Define_Pred(X756E69785F7368656C6C5F2461757833,3,0)

 Define_Pred(X756E69785F7368656C6C5F2461757832,1,0)

 Define_Pred(X756E69785F73797374656D,2,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(misc)



End_Exec_Directives
