/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : trace.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "trace.h"
#include "trace.usr"


#define ASCII_PRED "debug"
#define PRED       X6465627567
#define ARITY      0

Begin_Public_Pred
      put_constant(X6465627567,0)
      execute(Pred_Name(X64656275675F6D6F6465,1),1,"debug_mode",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "trace"
#define PRED       X7472616365
#define ARITY      0

Begin_Public_Pred
      put_constant(X7472616365,0)
      execute(Pred_Name(X64656275675F6D6F6465,1),1,"debug_mode",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "nodebug"
#define PRED       X6E6F6465627567
#define ARITY      0

Begin_Public_Pred
      put_constant(X6E6F6465627567,0)
      execute(Pred_Name(X64656275675F6D6F6465,1),1,"debug_mode",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "notrace"
#define PRED       X6E6F7472616365
#define ARITY      0

Begin_Public_Pred
      put_constant(X6E6F6465627567,0)
      execute(Pred_Name(X64656275675F6D6F6465,1),1,"debug_mode",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "debug_mode"
#define PRED       X64656275675F6D6F6465
#define ARITY      1

Begin_Public_Pred
      pragma_c(Debug_Mode_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "debugging"
#define PRED       X646562756767696E67
#define ARITY      0

Begin_Public_Pred
      pragma_c(Debug_Display_Infos();)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "leash"
#define PRED       X6C65617368
#define ARITY      1

Begin_Public_Pred
      allocate(0)
      call(Pred_Name(X6C6561736831,1),1,0,1,"leash1",1)          /* begin sub 1 */
      pragma_c(Debug_Display_Leashing();)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "leash1"
#define PRED       X6C6561736831
#define ARITY      1

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      pragma_c(Debug_Add_Leash_Mode(NULL);)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(1)
      get_list(0)
      unify_y_variable(0)
      unify_x_variable(0)
      call(Pred_Name(X6C6561736831,1),1,1,1,"leash1",1)          /* begin sub 1 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X6C6561736832,1),1,"leash2",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "leash2"
#define PRED       X6C6561736832
#define ARITY      1

Begin_Private_Pred
      pragma_c(Leash2_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "spy"
#define PRED       X737079
#define ARITY      1

Begin_Public_Pred
      switch_on_term(G_label(1),fail,fail,fail,G_label(1))

label(1)
      allocate(1)
      get_structure(X2F,2,0)
      unify_x_variable(0)
      unify_x_variable(1)
      call(Pred_Name(X73707931,2),1,1,1,"spy1",2)          /* begin sub 1 */
      put_y_variable(0,0)
      call(Pred_Name(X64656275675F6D6F6465,1),1,1,2,"debug_mode",1)          /* begin sub 2 */
      put_y_unsafe_value(0,0)
      deallocate
      execute(Pred_Name(X7370795F2461757831,1),1,"spy_$aux1",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "spy_$aux1"
#define PRED       X7370795F2461757831
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      put_constant(X6E6F6465627567,1)
      builtin_2(term_eq,0,1)
      neck_cut
      execute(Pred_Name(X6465627567,0),1,"debug",0)

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "spy1"
#define PRED       X73707931
#define ARITY      2

Begin_Private_Pred
      pragma_c(Spy1_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "nospy"
#define PRED       X6E6F737079
#define ARITY      1

Begin_Public_Pred
      switch_on_term(G_label(1),fail,fail,fail,G_label(1))

label(1)
      get_structure(X2F,2,0)
      unify_x_variable(0)
      unify_x_variable(1)
      execute(Pred_Name(X6E6F73707931,2),1,"nospy1",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "nospy1"
#define PRED       X6E6F73707931
#define ARITY      2

Begin_Private_Pred
      pragma_c(Nospy1_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "nospyall"
#define PRED       X6E6F737079616C6C
#define ARITY      0

Begin_Public_Pred
      pragma_c(Debug_Remove_Spy_Point(NULL,0);)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(trace)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X6465627567,"debug")
 Define_Atom(X7472616365,"trace")
 Define_Atom(X6E6F6465627567,"nodebug")
 Define_Atom(X6E6F7472616365,"notrace")
 Define_Atom(X64656275675F6D6F6465,"debug_mode")
 Define_Atom(X646562756767696E67,"debugging")
 Define_Atom(X6C65617368,"leash")
 Define_Atom(X6C6561736831,"leash1")
 Define_Atom(X6C6561736832,"leash2")
 Define_Atom(X737079,"spy")
 Define_Atom(X2F,"/")
 Define_Atom(X7370795F2461757831,"spy_$aux1")
 Define_Atom(X73707931,"spy1")
 Define_Atom(X6E6F737079,"nospy")
 Define_Atom(X6E6F73707931,"nospy1")
 Define_Atom(X6E6F737079616C6C,"nospyall")


 Define_Pred(X6465627567,0,1)

 Define_Pred(X7472616365,0,1)

 Define_Pred(X6E6F6465627567,0,1)

 Define_Pred(X6E6F7472616365,0,1)

 Define_Pred(X64656275675F6D6F6465,1,1)

 Define_Pred(X646562756767696E67,0,1)

 Define_Pred(X6C65617368,1,1)

 Define_Pred(X6C6561736831,1,0)

 Define_Pred(X6C6561736832,1,0)

 Define_Pred(X737079,1,1)

 Define_Pred(X7370795F2461757831,1,0)

 Define_Pred(X73707931,2,0)

 Define_Pred(X6E6F737079,1,1)

 Define_Pred(X6E6F73707931,2,0)

 Define_Pred(X6E6F737079616C6C,0,1)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(trace)



End_Exec_Directives
