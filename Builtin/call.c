/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : call.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "call.h"
#include "call.usr"


#define ASCII_PRED "otherwise"
#define PRED       X6F7468657277697365
#define ARITY      0

Begin_Public_Pred
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "true"
#define PRED       X74727565
#define ARITY      0

Begin_Public_Pred
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "false"
#define PRED       X66616C7365
#define ARITY      0

Begin_Public_Pred
      fail

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "fail"
#define PRED       X6661696C
#define ARITY      0

Begin_Public_Pred
      fail

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "repeat"
#define PRED       X726570656174
#define ARITY      0

Begin_Public_Pred
      try_me_else(1)
      proceed

label(1)
      trust_me_else_fail
      execute(Pred_Name(X726570656174,0),1,"repeat",0)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "for"
#define PRED       X666F72
#define ARITY      3

Begin_Public_Pred
      try_me_else(1)
      get_x_value(0,1)
      math_load_x_value(0,0)
      math_load_x_value(2,2)
      builtin_2(lte,0,2)
      proceed

label(1)
      trust_me_else_fail
      math_load_x_value(1,1)
      math_load_x_value(2,2)
      builtin_2(lt,1,2)
      math_load_x_value(1,1)
      function_1(inc,1,1)
      execute(Pred_Name(X666F72,3),1,"for",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "halt"
#define PRED       X68616C74
#define ARITY      0

Begin_Public_Pred
      put_integer(0,0)
      execute(Pred_Name(X68616C74,1),1,"halt",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "halt"
#define PRED       X68616C74
#define ARITY      1

Begin_Public_Pred
      pragma_c(Halt_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "halt_or_else"
#define PRED       X68616C745F6F725F656C7365
#define ARITY      1

Begin_Public_Pred
      get_x_variable(1,0)
      put_integer(0,0)
      execute(Pred_Name(X68616C745F6F725F656C7365,2),1,"halt_or_else",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "halt_or_else"
#define PRED       X68616C745F6F725F656C7365
#define ARITY      2

Begin_Public_Pred
      execute(Pred_Name(X68616C745F6F725F656C73655F2461757831,2),1,"halt_or_else_$aux1",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "halt_or_else_$aux1"
#define PRED       X68616C745F6F725F656C73655F2461757831
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      put_constant(X24746F705F6C6576656C,2)
      put_integer(0,1)
      builtin_2(g_read,2,1)
      neck_cut
      execute(Pred_Name(X68616C74,1),1,"halt",1)

label(1)
      trust_me_else_fail
      put_x_value(1,0)
      execute(Pred_Name(X63616C6C,1),1,"call",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "abort"
#define PRED       X61626F7274
#define ARITY      0

Begin_Public_Pred
      allocate(0)
      call(Pred_Name(X6E6F6465627567,0),0,0,1,"nodebug",0)          /* begin sub 1 */
      put_integer(1,0)
      put_structure(X7468726F77,1,1)
      unify_constant(X61626F7274)
      deallocate
      execute(Pred_Name(X68616C745F6F725F656C7365,2),1,"halt_or_else",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "dbg_exec"
#define PRED       X6462675F65786563
#define ARITY      0

Begin_Public_Pred
      allocate(2)
      get_y_bc_reg(0)
      put_constant(X7C203A2D,0)
      call(Pred_Name(X7772697465,1),0,2,1,"write",1)          /* begin sub 1 */
      put_y_variable(1,0)
      call(Pred_Name(X72656164,1),0,2,2,"read",1)          /* begin sub 2 */
      put_y_unsafe_value(1,0)
      call(Pred_Name(X6462675F657865635F2461757832,1),1,1,3,"dbg_exec_$aux2",1)          /* begin sub 3 */
      cut_y(0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "dbg_exec_$aux2"
#define PRED       X6462675F657865635F2461757832
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      put_constant(X656E645F6F665F66696C65,1)
      builtin_2(term_eq,0,1)
      proceed

label(1)
      retry_me_else(2)
      execute(Pred_Name(X63616C6C,1),1,"call",1)

label(2)
      trust_me_else_fail
      get_x_variable(2,0)
      put_constant(X7B5761726E696E673A207E77202D20676F616C206661696C65647D7E6E,0)
      put_list(1)
      unify_x_local_value(2)
      unify_nil
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "^"
#define PRED       X5E
#define ARITY      2

Begin_Public_Pred
      put_x_value(1,0)
      execute(Pred_Name(X63616C6C,1),1,"call",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "call"
#define PRED       X63616C6C
#define ARITY      1

Begin_Public_Pred
      put_integer(CMN,2)
      get_x_bc_reg(1)
      execute(Pred_Name(X63616C6C31,3),1,"call1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "call"
#define PRED       X63616C6C
#define ARITY      2

Begin_Public_Pred
      get_x_variable(2,1)
      get_x_bc_reg(1)
      execute(Pred_Name(X63616C6C31,3),1,"call1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "call1"
#define PRED       X63616C6C31
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      allocate(0)
      builtin_1(var,0)
      neck_cut
      put_constant(X4572726F723A207661726961626C6520676976656E20617320676F616C,0)
      call(Pred_Name(X7772697465,1),0,0,1,"write",1)          /* begin sub 1 */
      call(Pred_Name(X6E6C,0),0,0,2,"nl",0)          /* begin sub 2 */
      fail

label(1)
      retry_me_else(16)
      switch_on_term(G_label(4),G_label(2),fail,fail,G_label(3))

label(2)
      switch_on_constant(2,"[(true,5),(!,11)]")

label(3)
      switch_on_structure(3,"[((,)/2,7),((;)/2,9),((->)/2,13),((\+)/1,15)]")

label(4)
      try_me_else(6)

label(5)
      get_constant(X74727565,0)
      neck_cut
      proceed

label(6)
      retry_me_else(8)

label(7)
      allocate(3)
      get_structure(X2C,2,0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_y_variable(1,1)
      get_y_variable(0,2)
      neck_cut
      put_y_value(1,1)
      put_y_value(0,2)
      call(Pred_Name(X63616C6C31,3),1,3,3,"call1",3)          /* begin sub 3 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X63616C6C31,3),1,"call1",3)

label(8)
      retry_me_else(10)

label(9)
      get_structure(X3B,2,0)
      unify_x_variable(0)
      unify_x_variable(5)
      get_x_variable(4,1)
      get_x_variable(3,2)
      neck_cut
      pragma_c(Debug_Call("call_or_$aux",4,1);)
      put_x_value(5,1)
      put_x_value(4,2)
      execute(Pred_Name(X63616C6C5F6F72,4),1,"call_or",4)

label(10)
      retry_me_else(12)

label(11)
      get_constant(X21,0)
      cut_x(1)
      proceed

label(12)
      retry_me_else(14)

label(13)
      allocate(4)
      get_structure(X2D3E,2,0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_y_variable(1,1)
      get_y_variable(0,2)
      get_y_bc_reg(3)
      cut_y(3)
      put_y_value(0,1)
      call(Pred_Name(X63616C6C,2),1,4,4,"call",2)          /* begin sub 4 */
      cut_y(3)
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X63616C6C31,3),1,"call1",3)

label(14)
      trust_me_else_fail

label(15)
      get_structure(X5C2B,1,0)
      unify_x_variable(0)
      neck_cut
      put_x_value(2,1)
      get_x_bc_reg(2)
      execute(Pred_Name(X63616C6C315F2461757833,3),1,"call1_$aux3",3)

label(16)
      trust_me_else_fail
      pragma_c(Call1_3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "call1_$aux3"
#define PRED       X63616C6C315F2461757833
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      allocate(1)
      get_y_variable(0,2)
      call(Pred_Name(X63616C6C,2),1,1,1,"call",2)          /* begin sub 1 */
      cut_y(0)
      fail

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "call_or"
#define PRED       X63616C6C5F6F72
#define ARITY      4

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,fail,fail,G_label(1))

label(1)
      get_structure(X2D3E,2,0)
      unify_x_variable(0)
      unify_x_variable(7)
      get_x_variable(6,1)
      get_x_variable(5,2)
      get_x_variable(4,3)
      neck_cut
      put_x_value(7,1)
      put_x_value(6,2)
      put_x_value(5,3)
      get_x_bc_reg(5)
      execute(Pred_Name(X63616C6C5F6F725F2461757834,6),1,"call_or_$aux4",6)

label(2)
      retry_me_else(3)
      put_x_value(2,1)
      put_x_value(3,2)
      execute(Pred_Name(X63616C6C31,3),1,"call1",3)

label(3)
      trust_me_else_fail
      pragma_c(Debug_Has_Failed_Redo();)
      put_x_value(1,0)
      put_x_value(2,1)
      put_x_value(3,2)
      execute(Pred_Name(X63616C6C31,3),1,"call1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "call_or_$aux4"
#define PRED       X63616C6C5F6F725F2461757834
#define ARITY      6

Begin_Private_Pred
      try_me_else(1)
      allocate(4)
      get_y_variable(2,1)
      get_y_variable(1,3)
      get_y_variable(0,4)
      get_y_variable(3,5)
      put_y_value(0,1)
      call(Pred_Name(X63616C6C,2),1,4,1,"call",2)          /* begin sub 1 */
      cut_y(3)
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X63616C6C31,3),1,"call1",3)

label(1)
      trust_me_else_fail
      pragma_c(Debug_Has_Failed_Redo();)
      put_x_value(2,0)
      put_x_value(3,1)
      put_x_value(4,2)
      execute(Pred_Name(X63616C6C31,3),1,"call1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "catch"
#define PRED       X6361746368
#define ARITY      3

Begin_Public_Pred
      put_integer(CMN,3)
      execute(Pred_Name(X6361746368,4),1,"catch",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "catch"
#define PRED       X6361746368
#define ARITY      4

Begin_Public_Pred
      put_constant(X2462616C6C5F,5)
      put_constant(X246E6F5F62616C6C5F,4)
      builtin_2(g_assign,5,4)
      put_constant(X2468616E646C65725F,6)
      put_x_variable(4,5)
      builtin_2(g_read,6,5)
      execute(Pred_Name(X636174636831,5),1,"catch1",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "catch1"
#define PRED       X636174636831
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      allocate(6)
      get_y_variable(5,0)
      get_y_variable(4,3)
      get_y_variable(0,4)
      get_y_bc_reg(3)
      put_y_variable(2,0)
      call(Pred_Name(X6765745F63757272656E745F42,1),1,6,1,"get_current_B",1)          /* begin sub 1 */
      put_constant(X2468616E646C65725F,1)
      put_y_value(2,0)
      builtin_2(g_assign,1,0)
      put_y_value(5,0)
      put_y_value(4,1)
      call(Pred_Name(X63616C6C,2),1,4,2,"call",2)          /* begin sub 2 */
      put_y_variable(1,0)
      call(Pred_Name(X6765745F63757272656E745F42,1),1,4,3,"get_current_B",1)          /* begin sub 3 */
      put_y_unsafe_value(3,0)
      put_y_unsafe_value(2,1)
      put_y_unsafe_value(1,2)
      call(Pred_Name(X6361746368315F2461757835,3),1,1,4,"catch1_$aux5",3)          /* begin sub 4 */
      put_constant(X2468616E646C65725F,1)
      put_y_value(0,0)
      builtin_2(g_assign,1,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      get_x_variable(0,1)
      get_x_variable(1,2)
      get_x_variable(2,3)
      put_constant(X2468616E646C65725F,3)
      builtin_2(g_assign,3,4)
      put_constant(X2462616C6C5F,5)
      put_x_variable(3,4)
      builtin_2(g_read,5,4)
      put_constant(X246E6F5F62616C6C5F,4)
      builtin_2(term_neq,3,4)
      execute(Pred_Name(X6361746368315F2461757836,4),1,"catch1_$aux6",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "catch1_$aux5"
#define PRED       X6361746368315F2461757835
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      math_load_x_value(2,2)
      math_load_x_value(1,1)
      builtin_2(gt,2,1)
      neck_cut
      put_x_value(1,0)
      execute(Pred_Name(X747261696C5F68616E646C6572,1),1,"trail_handler",1)

label(1)
      trust_me_else_fail
      cut_x(0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "catch1_$aux6"
#define PRED       X6361746368315F2461757836
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      get_x_value(3,0)
      neck_cut
      put_constant(X2462616C6C5F,3)
      put_constant(X246E6F5F62616C6C5F,0)
      builtin_2(g_assign,3,0)
      put_x_value(1,0)
      put_x_value(2,1)
      execute(Pred_Name(X63616C6C,2),1,"call",2)

label(1)
      trust_me_else_fail
      put_x_value(3,0)
      execute(Pred_Name(X756E77696E64,1),1,"unwind",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "trail_handler"
#define PRED       X747261696C5F68616E646C6572
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      proceed

label(1)
      trust_me_else_fail
      put_constant(X2468616E646C65725F,1)
      builtin_2(g_assign,1,0)
      fail

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "throw"
#define PRED       X7468726F77
#define ARITY      1

Begin_Public_Pred
      put_constant(X2462616C6C5F,1)
      builtin_2(g_assign,1,0)
      execute(Pred_Name(X756E77696E64,1),1,"unwind",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "unwind"
#define PRED       X756E77696E64
#define ARITY      1

Begin_Private_Pred
      put_constant(X2468616E646C65725F,3)
      put_x_variable(1,2)
      builtin_2(g_read,3,2)
      execute(Pred_Name(X756E77696E645F2461757837,2),1,"unwind_$aux7",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "unwind_$aux7"
#define PRED       X756E77696E645F2461757837
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      allocate(0)
      get_x_variable(3,0)
      math_load_x_value(1,1)
      put_integer(0,0)
      builtin_2(eq,1,0)
      neck_cut
      put_constant(X7E6E73797374656D206572726F72202D2063616E6E6F74206361746368207E777E6E,0)
      put_structure(X7468726F77,1,2)
      unify_x_local_value(3)
      put_list(1)
      unify_x_value(2)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,0,1,"formata",2)          /* begin sub 1 */
      put_integer(2,0)
      put_constant(X61626F7274,1)
      deallocate
      execute(Pred_Name(X68616C745F6F725F656C7365,2),1,"halt_or_else",2)

label(1)
      trust_me_else_fail
      allocate(0)
      put_x_value(1,0)
      call(Pred_Name(X7365745F63757272656E745F42,1),1,0,2,"set_current_B",1)          /* begin sub 2 */
      fail

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "catch_signal"
#define PRED       X63617463685F7369676E616C
#define ARITY      1

Begin_Public_Pred
      pragma_c(Catch_Signal_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "signal_handler"
#define PRED       X7369676E616C5F68616E646C6572
#define ARITY      1

Begin_Public_Pred
      get_x_variable(1,0)
      put_structure(X7369676E616C,1,0)
      unify_x_local_value(1)
      execute(Pred_Name(X7468726F77,1),1,"throw",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "top_level"
#define PRED       X746F705F6C6576656C
#define ARITY      2

Begin_Public_Pred
      allocate(3)
      get_y_variable(1,1)
      put_y_variable(2,1)
      get_integer(CMN,1)
      call(Pred_Name(X746F705F6C6576656C5F2461757838,1),1,3,1,"top_level_$aux8",1)          /* begin sub 1 */
      put_constant(X24746F705F6C6576656C,1)
      put_y_variable(0,0)
      builtin_2(g_read,1,0)
      math_load_y_value(0,0)
      function_1(inc,0,0)
      put_constant(X24746F705F6C6576656C,1)
      builtin_2(g_assign,1,0)
      put_y_unsafe_value(2,0)
      put_y_value(1,1)
      call(Pred_Name(X746F705F6C6576656C31,2),1,1,2,"top_level1",2)          /* begin sub 2 */
      put_constant(X24746F705F6C6576656C,1)
      put_y_value(0,0)
      builtin_2(g_assign,1,0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "top_level_$aux8"
#define PRED       X746F705F6C6576656C5F2461757838
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      put_constant(X74727565,1)
      builtin_2(term_eq,0,1)
      neck_cut
      execute(Pred_Name(X76657273696F6E,0),0,"version",0)

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "top_level1"
#define PRED       X746F705F6C6576656C31
#define ARITY      2

Begin_Private_Pred
      get_x_variable(3,0)
      get_x_variable(4,1)
      put_structure(X746F705F6C6576656C32,1,0)
      unify_x_local_value(3)
      put_x_variable(5,1)
      put_structure(X2461667465725F7468726F77,3,2)
      unify_x_value(5)
      unify_x_local_value(3)
      unify_x_local_value(4)
      execute(Pred_Name(X6361746368,4),1,"catch",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "$after_throw"
#define PRED       X2461667465725F7468726F77
#define ARITY      3

Begin_Public_Pred
      execute(Pred_Name(X2461667465725F7468726F775F2461757839,3),1,"$after_throw_$aux9",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "$after_throw_$aux9"
#define PRED       X2461667465725F7468726F775F2461757839
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      allocate(3)
      get_y_variable(2,0)
      get_y_variable(1,1)
      get_y_variable(0,2)
      put_y_value(0,1)
      put_constant(X74727565,0)
      builtin_2(term_eq,1,0)
      neck_cut
      call(Pred_Name(X6E6F6465627567,0),0,3,1,"nodebug",0)          /* begin sub 1 */
      call(Pred_Name(X7365656E,0),0,3,2,"seen",0)          /* begin sub 2 */
      put_constant(X7E6E7B7E777D7E6E,0)
      put_list(1)
      unify_y_local_value(2)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,2,3,"formata",2)          /* begin sub 3 */
      put_y_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X746F705F6C6576656C31,2),1,"top_level1",2)

label(1)
      trust_me_else_fail
      put_constant(X24746F705F6C6576656C,3)
      put_x_variable(1,2)
      builtin_2(g_read,3,2)
      math_load_x_value(1,1)
      function_1(dec,1,1)
      put_constant(X24746F705F6C6576656C,2)
      builtin_2(g_assign,2,1)
      execute(Pred_Name(X7468726F77,1),1,"throw",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "top_level2"
#define PRED       X746F705F6C6576656C32
#define ARITY      1

Begin_Public_Pred
      allocate(4)
      get_y_variable(3,0)
      get_y_bc_reg(2)
      call(Pred_Name(X726570656174,0),1,4,1,"repeat",0)          /* begin sub 1 */
      call(Pred_Name(X77726974655F64656275675F696E64696361746F72,0),1,4,2,"write_debug_indicator",0)          /* begin sub 2 */
      put_constant(X7C203F2D20,0)
      call(Pred_Name(X7772697465,1),0,4,3,"write",1)          /* begin sub 3 */
      put_y_variable(1,0)
      put_structure(X7661726961626C655F6E616D6573,1,2)
      unify_y_variable(0)
      put_list(1)
      unify_x_value(2)
      unify_nil
      call(Pred_Name(X726561645F7465726D,2),0,4,4,"read_term",2)          /* begin sub 4 */
      put_y_value(3,0)
      put_y_unsafe_value(2,1)
      put_y_unsafe_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X746F705F6C6576656C325F246175783130,4),1,"top_level2_$aux10",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "top_level2_$aux10"
#define PRED       X746F705F6C6576656C325F246175783130
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      allocate(1)
      get_y_variable(0,1)
      put_constant(X656E645F6F665F66696C65,0)
      builtin_2(term_eq,2,0)
      neck_cut
      call(Pred_Name(X6E6F6465627567,0),0,1,1,"nodebug",0)          /* begin sub 1 */
      call(Pred_Name(X6E6C,0),0,1,2,"nl",0)          /* begin sub 2 */
      cut_y(0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      allocate(1)
      put_x_value(2,1)
      put_x_value(3,2)
      call(Pred_Name(X746F705F6C6576656C325F246175783131,3),1,1,3,"top_level2_$aux11",3)          /* begin sub 3 */
      put_y_variable(0,0)
      call(Pred_Name(X64656275675F6D6F6465,1),0,1,4,"debug_mode",1)          /* begin sub 4 */
      put_y_unsafe_value(0,0)
      call(Pred_Name(X64656275675F6D6F6465,1),0,0,5,"debug_mode",1)          /* begin sub 5 */
      fail

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "top_level2_$aux11"
#define PRED       X746F705F6C6576656C325F246175783131
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      allocate(1)
      get_x_variable(3,0)
      get_y_bc_reg(0)
      put_x_value(1,0)
      put_x_value(2,1)
      put_x_value(3,2)
      call(Pred_Name(X65786563,3),1,1,1,"exec",3)          /* begin sub 1 */
      cut_y(0)
      call(Pred_Name(X6E6C,0),0,0,2,"nl",0)          /* begin sub 2 */
      put_constant(X796573,0)
      call(Pred_Name(X7772697465,1),0,0,3,"write",1)          /* begin sub 3 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

label(1)
      trust_me_else_fail
      allocate(0)
      call(Pred_Name(X6E6C,0),0,0,4,"nl",0)          /* begin sub 4 */
      put_constant(X6E6F,0)
      call(Pred_Name(X7772697465,1),0,0,5,"write",1)          /* begin sub 5 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "write_debug_indicator"
#define PRED       X77726974655F64656275675F696E64696361746F72
#define ARITY      0

Begin_Private_Pred
      allocate(1)
      put_y_variable(0,0)
      call(Pred_Name(X64656275675F6D6F6465,1),0,1,1,"debug_mode",1)          /* begin sub 1 */
      put_y_unsafe_value(0,0)
      deallocate
      execute(Pred_Name(X77726974655F64656275675F696E64696361746F72,1),1,"write_debug_indicator",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "write_debug_indicator"
#define PRED       X77726974655F64656275675F696E64696361746F72
#define ARITY      1

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(1),fail,fail,fail)

label(1)
      switch_on_constant(1,"[(debug,3),(trace,5),(nodebug,7)]")

label(2)
      try_me_else(4)

label(3)
      allocate(0)
      get_constant(X6465627567,0)
      put_constant(X7B64656275677D,0)
      call(Pred_Name(X7772697465,1),0,0,1,"write",1)          /* begin sub 1 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

label(4)
      retry_me_else(6)

label(5)
      allocate(0)
      get_constant(X7472616365,0)
      put_constant(X7B74726163657D,0)
      call(Pred_Name(X7772697465,1),0,0,2,"write",1)          /* begin sub 2 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

label(6)
      trust_me_else_fail

label(7)
      get_constant(X6E6F6465627567,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "exec"
#define PRED       X65786563
#define ARITY      3

Begin_Private_Pred
      allocate(5)
      get_y_variable(4,0)
      get_y_variable(2,1)
      get_y_variable(3,2)
      put_y_variable(1,0)
      call(Pred_Name(X6765745F63757272656E745F42,1),1,5,1,"get_current_B",1)          /* begin sub 1 */
      put_y_value(4,0)
      put_y_value(3,1)
      call(Pred_Name(X63616C6C,2),1,3,2,"call",2)          /* begin sub 2 */
      put_y_variable(0,0)
      call(Pred_Name(X6765745F63757272656E745F42,1),1,3,3,"get_current_B",1)          /* begin sub 3 */
      put_y_value(2,0)
      call(Pred_Name(X77726974655F736F6C7574696F6E,1),1,2,4,"write_solution",1)          /* begin sub 4 */
      put_y_unsafe_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X657865635F246175783132,2),1,"exec_$aux12",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "exec_$aux12"
#define PRED       X657865635F246175783132
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      allocate(1)
      math_load_x_value(1,1)
      math_load_x_value(0,0)
      builtin_2(gt,1,0)
      neck_cut
      put_constant(X203F20,0)
      call(Pred_Name(X7772697465,1),0,1,1,"write",1)          /* begin sub 1 */
      put_y_variable(0,0)
      call(Pred_Name(X726561645F636F6D6D616E64,1),1,1,2,"read_command",1)          /* begin sub 2 */
      put_y_value(0,1)
      put_integer(10,0)
      builtin_2(term_eq,1,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "read_command"
#define PRED       X726561645F636F6D6D616E64
#define ARITY      1

Begin_Private_Pred
      allocate(2)
      get_y_variable(1,0)
      put_y_variable(0,0)
      call(Pred_Name(X67657430,1),0,2,1,"get0",1)          /* begin sub 1 */
      put_y_value(0,0)
      call(Pred_Name(X736B69705F756E74696C5F72657475726E,1),1,2,2,"skip_until_return",1)          /* begin sub 2 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X726561645F636F6D6D616E645F246175783133,2),1,"read_command_$aux13",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "read_command_$aux13"
#define PRED       X726561645F636F6D6D616E645F246175783133
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      put_integer(10,2)
      builtin_2(term_eq,1,2)
      neck_cut
      get_x_value(1,0)
      proceed

label(1)
      retry_me_else(2)
      allocate(1)
      get_y_variable(0,0)
      put_integer(59,0)
      builtin_2(term_neq,1,0)
      neck_cut
      put_constant(X416374696F6E2028223B2220666F72206D6F72652063686F696365732C20,0)
      call(Pred_Name(X7772697465,1),0,1,1,"write",1)          /* begin sub 1 */
      put_constant(X6F7468657277697365203C72657475726E3E293A20,0)
      call(Pred_Name(X7772697465,1),0,1,2,"write",1)          /* begin sub 2 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X726561645F636F6D6D616E64,1),1,"read_command",1)

label(2)
      trust_me_else_fail
      get_x_value(1,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "skip_until_return"
#define PRED       X736B69705F756E74696C5F72657475726E
#define ARITY      1

Begin_Private_Pred
      execute(Pred_Name(X736B69705F756E74696C5F72657475726E5F246175783134,1),1,"skip_until_return_$aux14",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "skip_until_return_$aux14"
#define PRED       X736B69705F756E74696C5F72657475726E5F246175783134
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      put_integer(10,1)
      builtin_2(term_eq,0,1)
      neck_cut
      proceed

label(1)
      trust_me_else_fail
      allocate(1)
      put_y_variable(0,0)
      call(Pred_Name(X67657430,1),0,1,1,"get0",1)          /* begin sub 1 */
      put_y_unsafe_value(0,0)
      deallocate
      execute(Pred_Name(X736B69705F756E74696C5F72657475726E,1),1,"skip_until_return",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "write_solution"
#define PRED       X77726974655F736F6C7574696F6E
#define ARITY      1

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(2)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(0)
      get_structure(X3D,2,0)
      unify_x_variable(2)
      unify_y_variable(1)
      put_constant(X7E6E7E61203D20,0)
      put_list(1)
      unify_x_value(2)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,2,1,"formata",2)          /* begin sub 1 */
      put_y_value(1,0)
      put_structure(X71756F746564,1,3)
      unify_constant(X74727565)
      put_structure(X6E756D62657276617273,1,1)
      unify_constant(X66616C7365)
      put_list(2)
      unify_x_value(1)
      unify_nil
      put_list(1)
      unify_x_value(3)
      unify_x_value(2)
      call(Pred_Name(X77726974655F7465726D,2),0,1,2,"write_term",2)          /* begin sub 2 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X77726974655F736F6C7574696F6E,1),1,"write_solution",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "get_current_B"
#define PRED       X6765745F63757272656E745F42
#define ARITY      1

Begin_Public_Pred
      pragma_c(Get_Current_B_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "set_current_B"
#define PRED       X7365745F63757272656E745F42
#define ARITY      1

Begin_Public_Pred
      pragma_c(Set_Current_B_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "$exe_1"
#define PRED       X246578655F31
#define ARITY      0

Begin_Private_Pred
      allocate(1)
      get_y_bc_reg(0)
      put_integer(2,0)
      call(Pred_Name(X63617463685F7369676E616C,1),1,1,1,"catch_signal",1)          /* begin sub 1 */
      put_integer(3,0)
      call(Pred_Name(X63617463685F7369676E616C,1),1,1,2,"catch_signal",1)          /* begin sub 2 */
      cut_y(0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(call)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X6F7468657277697365,"otherwise")
 Define_Atom(X74727565,"true")
 Define_Atom(X66616C7365,"false")
 Define_Atom(X6661696C,"fail")
 Define_Atom(X726570656174,"repeat")
 Define_Atom(X666F72,"for")
 Define_Atom(X68616C74,"halt")
 Define_Atom(X68616C745F6F725F656C7365,"halt_or_else")
 Define_Atom(X68616C745F6F725F656C73655F2461757831,"halt_or_else_$aux1")
 Define_Atom(X24746F705F6C6576656C,"$top_level")
 Define_Atom(X61626F7274,"abort")
 Define_Atom(X7468726F77,"throw")
 Define_Atom(X6462675F65786563,"dbg_exec")
 Define_Atom(X7C203A2D,"| :-")
 Define_Atom(X6462675F657865635F2461757832,"dbg_exec_$aux2")
 Define_Atom(X656E645F6F665F66696C65,"end_of_file")
 Define_Atom(X7B5761726E696E673A207E77202D20676F616C206661696C65647D7E6E,"{Warning: ~w - goal failed}~n")
 Define_Atom(X5E,"^")
 Define_Atom(X63616C6C,"call")
 Define_Atom(X63616C6C31,"call1")
 Define_Atom(X4572726F723A207661726961626C6520676976656E20617320676F616C,"Error: variable given as goal")
 Define_Atom(X2C,",")
 Define_Atom(X3B,";")
 Define_Atom(X21,"!")
 Define_Atom(X2D3E,"->")
 Define_Atom(X5C2B,"\\+")
 Define_Atom(X63616C6C315F2461757833,"call1_$aux3")
 Define_Atom(X63616C6C5F6F72,"call_or")
 Define_Atom(X63616C6C5F6F725F2461757834,"call_or_$aux4")
 Define_Atom(X6361746368,"catch")
 Define_Atom(X2462616C6C5F,"$ball_")
 Define_Atom(X246E6F5F62616C6C5F,"$no_ball_")
 Define_Atom(X2468616E646C65725F,"$handler_")
 Define_Atom(X636174636831,"catch1")
 Define_Atom(X6361746368315F2461757835,"catch1_$aux5")
 Define_Atom(X6361746368315F2461757836,"catch1_$aux6")
 Define_Atom(X747261696C5F68616E646C6572,"trail_handler")
 Define_Atom(X756E77696E64,"unwind")
 Define_Atom(X756E77696E645F2461757837,"unwind_$aux7")
 Define_Atom(X7E6E73797374656D206572726F72202D2063616E6E6F74206361746368207E777E6E,"~nsystem error - cannot catch ~w~n")
 Define_Atom(X63617463685F7369676E616C,"catch_signal")
 Define_Atom(X7369676E616C5F68616E646C6572,"signal_handler")
 Define_Atom(X7369676E616C,"signal")
 Define_Atom(X746F705F6C6576656C,"top_level")
 Define_Atom(X746F705F6C6576656C5F2461757838,"top_level_$aux8")
 Define_Atom(X746F705F6C6576656C31,"top_level1")
 Define_Atom(X746F705F6C6576656C32,"top_level2")
 Define_Atom(X2461667465725F7468726F77,"$after_throw")
 Define_Atom(X2461667465725F7468726F775F2461757839,"$after_throw_$aux9")
 Define_Atom(X7E6E7B7E777D7E6E,"~n{~w}~n")
 Define_Atom(X7C203F2D20,"| ?- ")
 Define_Atom(X7661726961626C655F6E616D6573,"variable_names")
 Define_Atom(X746F705F6C6576656C325F246175783130,"top_level2_$aux10")
 Define_Atom(X746F705F6C6576656C325F246175783131,"top_level2_$aux11")
 Define_Atom(X796573,"yes")
 Define_Atom(X6E6F,"no")
 Define_Atom(X77726974655F64656275675F696E64696361746F72,"write_debug_indicator")
 Define_Atom(X6465627567,"debug")
 Define_Atom(X7B64656275677D,"{debug}")
 Define_Atom(X7472616365,"trace")
 Define_Atom(X7B74726163657D,"{trace}")
 Define_Atom(X6E6F6465627567,"nodebug")
 Define_Atom(X65786563,"exec")
 Define_Atom(X657865635F246175783132,"exec_$aux12")
 Define_Atom(X203F20," ? ")
 Define_Atom(X726561645F636F6D6D616E64,"read_command")
 Define_Atom(X726561645F636F6D6D616E645F246175783133,"read_command_$aux13")
 Define_Atom(X416374696F6E2028223B2220666F72206D6F72652063686F696365732C20,"Action (\";\" for more choices, ")
 Define_Atom(X6F7468657277697365203C72657475726E3E293A20,"otherwise <return>): ")
 Define_Atom(X736B69705F756E74696C5F72657475726E,"skip_until_return")
 Define_Atom(X736B69705F756E74696C5F72657475726E5F246175783134,"skip_until_return_$aux14")
 Define_Atom(X77726974655F736F6C7574696F6E,"write_solution")
 Define_Atom(X3D,"=")
 Define_Atom(X7E6E7E61203D20,"~n~a = ")
 Define_Atom(X71756F746564,"quoted")
 Define_Atom(X6E756D62657276617273,"numbervars")
 Define_Atom(X6765745F63757272656E745F42,"get_current_B")
 Define_Atom(X7365745F63757272656E745F42,"set_current_B")
 Define_Atom(X246578655F31,"$exe_1")


 Define_Pred(X6F7468657277697365,0,1)

 Define_Pred(X74727565,0,1)

 Define_Pred(X66616C7365,0,1)

 Define_Pred(X6661696C,0,1)

 Define_Pred(X726570656174,0,1)

 Define_Pred(X666F72,3,1)

 Define_Pred(X68616C74,0,1)

 Define_Pred(X68616C74,1,1)

 Define_Pred(X68616C745F6F725F656C7365,1,1)

 Define_Pred(X68616C745F6F725F656C7365,2,1)

 Define_Pred(X68616C745F6F725F656C73655F2461757831,2,0)

 Define_Pred(X61626F7274,0,1)

 Define_Pred(X6462675F65786563,0,1)

 Define_Pred(X6462675F657865635F2461757832,1,0)

 Define_Pred(X5E,2,1)

 Define_Pred(X63616C6C,1,1)

 Define_Pred(X63616C6C,2,1)

 Define_Pred(X63616C6C31,3,0)
 Define_Switch_CST_Table(Swt_Table_Name(X63616C6C31,3,2,cst),2)
     Define_Switch_CST(X74727565,Label_Pred_Name(X63616C6C31,3,5))
     Define_Switch_CST(X21,Label_Pred_Name(X63616C6C31,3,11))
 Define_Switch_STC_Table(Swt_Table_Name(X63616C6C31,3,3,stc),4)
     Define_Switch_STC(X2C,2,Label_Pred_Name(X63616C6C31,3,7))
     Define_Switch_STC(X3B,2,Label_Pred_Name(X63616C6C31,3,9))
     Define_Switch_STC(X2D3E,2,Label_Pred_Name(X63616C6C31,3,13))
     Define_Switch_STC(X5C2B,1,Label_Pred_Name(X63616C6C31,3,15))

 Define_Pred(X63616C6C315F2461757833,3,0)

 Define_Pred(X63616C6C5F6F72,4,0)

 Define_Pred(X63616C6C5F6F725F2461757834,6,0)

 Define_Pred(X6361746368,3,1)

 Define_Pred(X6361746368,4,1)

 Define_Pred(X636174636831,5,0)

 Define_Pred(X6361746368315F2461757835,3,0)

 Define_Pred(X6361746368315F2461757836,4,0)

 Define_Pred(X747261696C5F68616E646C6572,1,0)

 Define_Pred(X7468726F77,1,1)

 Define_Pred(X756E77696E64,1,0)

 Define_Pred(X756E77696E645F2461757837,2,0)

 Define_Pred(X63617463685F7369676E616C,1,1)

 Define_Pred(X7369676E616C5F68616E646C6572,1,1)

 Define_Pred(X746F705F6C6576656C,2,1)

 Define_Pred(X746F705F6C6576656C5F2461757838,1,0)

 Define_Pred(X746F705F6C6576656C31,2,0)

 Define_Pred(X2461667465725F7468726F77,3,1)

 Define_Pred(X2461667465725F7468726F775F2461757839,3,0)

 Define_Pred(X746F705F6C6576656C32,1,1)

 Define_Pred(X746F705F6C6576656C325F246175783130,4,0)

 Define_Pred(X746F705F6C6576656C325F246175783131,3,0)

 Define_Pred(X77726974655F64656275675F696E64696361746F72,0,0)

 Define_Pred(X77726974655F64656275675F696E64696361746F72,1,0)
 Define_Switch_CST_Table(Swt_Table_Name(X77726974655F64656275675F696E64696361746F72,1,1,cst),3)
     Define_Switch_CST(X6465627567,Label_Pred_Name(X77726974655F64656275675F696E64696361746F72,1,3))
     Define_Switch_CST(X7472616365,Label_Pred_Name(X77726974655F64656275675F696E64696361746F72,1,5))
     Define_Switch_CST(X6E6F6465627567,Label_Pred_Name(X77726974655F64656275675F696E64696361746F72,1,7))

 Define_Pred(X65786563,3,0)

 Define_Pred(X657865635F246175783132,2,0)

 Define_Pred(X726561645F636F6D6D616E64,1,0)

 Define_Pred(X726561645F636F6D6D616E645F246175783133,2,0)

 Define_Pred(X736B69705F756E74696C5F72657475726E,1,0)

 Define_Pred(X736B69705F756E74696C5F72657475726E5F246175783134,1,0)

 Define_Pred(X77726974655F736F6C7574696F6E,1,0)

 Define_Pred(X6765745F63757272656E745F42,1,1)

 Define_Pred(X7365745F63757272656E745F42,1,1)

 Define_Pred(X246578655F31,0,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(call)


 Exec_Directive(1,Pred_Name(X246578655F31,0))

End_Exec_Directives
