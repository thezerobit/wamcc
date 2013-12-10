/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : term.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "term.h"
#include "term.usr"


#define ASCII_PRED "copy_term"
#define PRED       X636F70795F7465726D
#define ARITY      2

Begin_Public_Pred
      pragma_c(Term_Copy_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "setarg"
#define PRED       X736574617267
#define ARITY      3

Begin_Public_Pred
      pragma_c(Setarg_3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sort"
#define PRED       X736F7274
#define ARITY      2

Begin_Public_Pred
      try_me_else(5)
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      neck_cut
      get_nil(1)
      proceed

label(3)
      trust_me_else_fail

label(4)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      neck_cut
      get_list(1)
      unify_x_value(0)
      unify_nil
      proceed

label(5)
      trust_me_else_fail
      get_x_variable(3,1)
      put_nil(1)
      put_integer(0,2)
      execute(Pred_Name(X736F7274,4),1,"sort",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sort"
#define PRED       X736F7274
#define ARITY      4

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(3),fail,G_label(1),fail)

label(1)
      try(5,1)          /* begin sub 1 */
      trust(7)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      put_x_value(1,0)
      put_integer(0,1)
      put_list(2)
      unify_x_local_value(3)
      unify_nil
      execute(Pred_Name(X73616D66757365,3),1,"samfuse",3)

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      neck_cut
      put_list(2)
      unify_x_value(0)
      unify_nil
      put_list(0)
      unify_x_value(2)
      unify_x_local_value(1)
      put_integer(0,1)
      put_list(2)
      unify_x_local_value(3)
      unify_nil
      execute(Pred_Name(X73616D66757365,3),1,"samfuse",3)

label(6)
      trust_me_else_fail

label(7)
      allocate(7)
      get_list(0)
      unify_x_variable(4)
      unify_x_variable(0)
      get_y_variable(4,1)
      get_y_variable(6,2)
      get_y_variable(0,3)
      put_list(1)
      unify_x_value(4)
      unify_void(1)
      put_x_value(1,2)
      put_y_variable(5,3)
      put_y_variable(3,4)
      call(Pred_Name(X73616D72756E,5),1,7,2,"samrun",5)          /* begin sub 2 */
      math_load_y_value(6,0)
      function_1(inc,0,0)
      get_y_variable(1,0)
      put_list(0)
      unify_y_local_value(5)
      unify_y_local_value(4)
      put_y_value(1,1)
      put_y_variable(2,2)
      call(Pred_Name(X73616D66757365,3),1,4,3,"samfuse",3)          /* begin sub 3 */
      put_y_unsafe_value(3,0)
      put_y_unsafe_value(2,1)
      put_y_unsafe_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X736F7274,4),1,"sort",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "samfuse"
#define PRED       X73616D66757365
#define ARITY      3

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,fail,G_label(1),fail)

label(1)
      allocate(4)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_y_variable(0,2)
      math_load_x_value(1,1)
      put_integer(1,2)
      function_2(and,2,1,2)
      get_integer(0,2)
      neck_cut
      math_load_x_value(1,1)
      put_integer(1,2)
      function_2(shr,1,1,2)
      get_y_variable(1,1)
      put_x_value(3,1)
      put_y_variable(3,2)
      call(Pred_Name(X6D65726765,3),1,4,1,"merge",3)          /* begin sub 1 */
      put_list(0)
      unify_y_local_value(3)
      unify_y_value(2)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X73616D66757365,3),1,"samfuse",3)

label(2)
      trust_me_else_fail
      get_x_value(0,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "samrun"
#define PRED       X73616D72756E
#define ARITY      5

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,fail,G_label(1),fail)

label(1)
      allocate(6)
      get_list(0)
      unify_x_variable(7)
      unify_y_variable(4)
      get_x_variable(6,1)
      get_x_variable(5,2)
      get_y_variable(1,3)
      get_y_variable(0,4)
      get_y_bc_reg(5)
      get_list(5)
      unify_x_variable(1)
      unify_void(1)
      put_x_variable(0,2)
      builtin_3(compare,2,7,1)
      put_x_value(7,1)
      put_x_value(6,2)
      put_x_value(5,3)
      put_y_variable(3,4)
      put_y_variable(2,5)
      call(Pred_Name(X73616D72756E74,6),1,6,1,"samrunt",6)          /* begin sub 1 */
      cut_y(5)
      put_y_value(4,0)
      put_y_unsafe_value(3,1)
      put_y_unsafe_value(2,2)
      put_y_value(1,3)
      put_y_value(0,4)
      deallocate
      execute(Pred_Name(X73616D72756E,5),1,"samrun",5)

label(2)
      trust_me_else_fail
      get_list(2)
      unify_void(1)
      unify_nil
      get_x_value(1,3)
      get_x_value(0,4)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "samrunh"
#define PRED       X73616D72756E68
#define ARITY      4

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(1),fail,fail,fail)

label(1)
      switch_on_constant(1,"[(<,3),(=,5)]")

label(2)
      try_me_else(4)

label(3)
      get_constant(X3C,0)
      get_list(3)
      unify_x_local_value(1)
      unify_x_local_value(2)
      proceed

label(4)
      trust_me_else_fail

label(5)
      get_constant(X3D,0)
      get_x_value(2,3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "samrunt"
#define PRED       X73616D72756E74
#define ARITY      6

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(1),fail,fail,fail)

label(1)
      switch_on_constant(1,"[(<,3),(=,5),(>,7)]")

label(2)
      try_me_else(4)

label(3)
      get_constant(X3C,0)
      get_x_value(3,5)
      get_list(2)
      unify_x_variable(3)
      unify_void(1)
      put_x_variable(0,5)
      builtin_3(compare,5,1,3)
      put_x_value(4,3)
      execute(Pred_Name(X73616D72756E68,4),1,"samrunh",4)

label(4)
      retry_me_else(6)

label(5)
      get_constant(X3D,0)
      get_x_value(2,4)
      get_x_value(3,5)
      proceed

label(6)
      trust_me_else_fail

label(7)
      get_constant(X3E,0)
      get_list(3)
      unify_void(1)
      unify_x_variable(0)
      get_x_value(2,4)
      get_x_value(0,5)
      get_list(0)
      unify_x_local_value(1)
      unify_void(1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "merge"
#define PRED       X6D65726765
#define ARITY      3

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),G_label(1),fail,fail,fail)

label(1)
      get_nil(0)
      neck_cut
      get_x_value(1,2)
      proceed

label(2)
      retry_me_else(3)
      get_nil(1)
      neck_cut
      get_x_value(0,2)
      proceed

label(3)
      trust_me_else_fail
      get_x_variable(5,0)
      get_x_variable(4,1)
      get_x_variable(3,2)
      get_list(5)
      unify_x_variable(2)
      unify_void(1)
      get_list(4)
      unify_x_variable(1)
      unify_void(1)
      put_x_variable(0,6)
      builtin_3(compare,6,2,1)
      put_x_value(5,1)
      put_x_value(4,2)
      execute(Pred_Name(X6D65726765,4),1,"merge",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "merge"
#define PRED       X6D65726765
#define ARITY      4

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(1),fail,fail,fail)

label(1)
      switch_on_constant(1,"[(<,3),(=,5),(>,7)]")

label(2)
      try_me_else(4)

label(3)
      get_constant(X3C,0)
      get_list(1)
      unify_x_variable(4)
      unify_x_variable(0)
      get_x_variable(1,2)
      get_list(3)
      unify_x_value(4)
      unify_x_variable(2)
      execute(Pred_Name(X6D65726765,3),1,"merge",3)

label(4)
      retry_me_else(6)

label(5)
      get_constant(X3D,0)
      get_list(1)
      unify_void(1)
      unify_x_variable(0)
      put_x_value(2,1)
      put_x_value(3,2)
      execute(Pred_Name(X6D65726765,3),1,"merge",3)

label(6)
      trust_me_else_fail

label(7)
      get_constant(X3E,0)
      get_x_variable(0,1)
      get_list(2)
      unify_x_variable(2)
      unify_x_variable(1)
      get_list(3)
      unify_x_value(2)
      unify_x_variable(2)
      execute(Pred_Name(X6D65726765,3),1,"merge",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "keysort"
#define PRED       X6B6579736F7274
#define ARITY      2

Begin_Public_Pred
      try_me_else(5)
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      neck_cut
      get_nil(1)
      proceed

label(3)
      trust_me_else_fail

label(4)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      neck_cut
      get_list(1)
      unify_x_value(0)
      unify_nil
      proceed

label(5)
      trust_me_else_fail
      get_x_variable(3,1)
      put_nil(1)
      put_integer(0,2)
      execute(Pred_Name(X6B6579736F7274,4),1,"keysort",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "keysort"
#define PRED       X6B6579736F7274
#define ARITY      4

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(3),fail,G_label(1),fail)

label(1)
      try(5,1)          /* begin sub 1 */
      trust(7)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      put_x_value(1,0)
      put_integer(0,1)
      put_list(2)
      unify_x_local_value(3)
      unify_nil
      execute(Pred_Name(X73616D6B657966757365,3),1,"samkeyfuse",3)

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      neck_cut
      put_list(2)
      unify_x_value(0)
      unify_nil
      put_list(0)
      unify_x_value(2)
      unify_x_local_value(1)
      put_integer(0,1)
      put_list(2)
      unify_x_local_value(3)
      unify_nil
      execute(Pred_Name(X73616D6B657966757365,3),1,"samkeyfuse",3)

label(6)
      trust_me_else_fail

label(7)
      allocate(7)
      get_list(0)
      unify_x_variable(4)
      unify_x_variable(0)
      get_y_variable(4,1)
      get_y_variable(6,2)
      get_y_variable(0,3)
      put_list(1)
      unify_x_value(4)
      unify_void(1)
      put_x_value(1,2)
      put_y_variable(5,3)
      put_y_variable(3,4)
      call(Pred_Name(X73616D6B657972756E,5),1,7,2,"samkeyrun",5)          /* begin sub 2 */
      math_load_y_value(6,0)
      function_1(inc,0,0)
      get_y_variable(1,0)
      put_list(0)
      unify_y_local_value(5)
      unify_y_local_value(4)
      put_y_value(1,1)
      put_y_variable(2,2)
      call(Pred_Name(X73616D6B657966757365,3),1,4,3,"samkeyfuse",3)          /* begin sub 3 */
      put_y_unsafe_value(3,0)
      put_y_unsafe_value(2,1)
      put_y_unsafe_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X6B6579736F7274,4),1,"keysort",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "samkeyfuse"
#define PRED       X73616D6B657966757365
#define ARITY      3

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,fail,G_label(1),fail)

label(1)
      allocate(4)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_y_variable(0,2)
      math_load_x_value(1,1)
      put_integer(1,2)
      function_2(and,2,1,2)
      get_integer(0,2)
      neck_cut
      math_load_x_value(1,1)
      put_integer(1,2)
      function_2(shr,1,1,2)
      get_y_variable(1,1)
      put_x_value(3,1)
      put_y_variable(3,2)
      call(Pred_Name(X6B65796D65726765,3),1,4,1,"keymerge",3)          /* begin sub 1 */
      put_list(0)
      unify_y_local_value(3)
      unify_y_value(2)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X73616D6B657966757365,3),1,"samkeyfuse",3)

label(2)
      trust_me_else_fail
      get_x_value(0,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "samkeyrun"
#define PRED       X73616D6B657972756E
#define ARITY      5

Begin_Private_Pred
      try_me_else(6)
      switch_on_term(G_label(2),fail,fail,G_label(1),fail)

label(1)
      try(3,1)          /* begin sub 1 */
      trust(5)

label(2)
      try_me_else(4)

label(3)
      get_list(0)
      unify_x_variable(5)
      unify_x_variable(0)
      get_structure(X2D,2,5)
      unify_x_variable(7)
      unify_void(1)
      get_list(2)
      unify_x_variable(6)
      unify_x_variable(2)
      get_structure(X2D,2,6)
      unify_x_variable(6)
      unify_void(1)
      builtin_2(term_gte,7,6)
      neck_cut
      get_list(2)
      unify_x_value(5)
      unify_void(1)
      execute(Pred_Name(X73616D6B657972756E,5),1,"samkeyrun",5)

label(4)
      trust_me_else_fail

label(5)
      get_list(0)
      unify_x_variable(6)
      unify_x_variable(0)
      get_x_variable(5,1)
      get_structure(X2D,2,6)
      unify_x_variable(7)
      unify_void(1)
      get_list(5)
      unify_x_variable(1)
      unify_void(1)
      get_structure(X2D,2,1)
      unify_x_variable(1)
      unify_void(1)
      builtin_2(term_lt,7,1)
      neck_cut
      put_list(1)
      unify_x_value(6)
      unify_x_local_value(5)
      execute(Pred_Name(X73616D6B657972756E,5),1,"samkeyrun",5)

label(6)
      trust_me_else_fail
      get_list(2)
      unify_void(1)
      unify_nil
      get_x_value(1,3)
      get_x_value(0,4)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "keymerge"
#define PRED       X6B65796D65726765
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      get_nil(1)
      neck_cut
      get_x_value(0,2)
      proceed

label(1)
      retry_me_else(6)
      switch_on_term(G_label(2),G_label(3),fail,G_label(5),fail)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      neck_cut
      get_x_value(1,2)
      proceed

label(4)
      trust_me_else_fail

label(5)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      get_structure(X2D,2,3)
      unify_x_variable(5)
      unify_void(1)
      get_list(1)
      unify_x_variable(4)
      unify_void(1)
      get_structure(X2D,2,4)
      unify_x_variable(4)
      unify_void(1)
      builtin_2(term_lte,5,4)
      neck_cut
      get_list(2)
      unify_x_value(3)
      unify_x_variable(2)
      execute(Pred_Name(X6B65796D65726765,3),1,"keymerge",3)

label(6)
      trust_me_else_fail
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      get_list(2)
      unify_x_value(3)
      unify_x_variable(2)
      execute(Pred_Name(X6B65796D65726765,3),1,"keymerge",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(term)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X636F70795F7465726D,"copy_term")
 Define_Atom(X736574617267,"setarg")
 Define_Atom(X736F7274,"sort")
 Define_Atom(X73616D66757365,"samfuse")
 Define_Atom(X73616D72756E,"samrun")
 Define_Atom(X73616D72756E68,"samrunh")
 Define_Atom(X3C,"<")
 Define_Atom(X3D,"=")
 Define_Atom(X73616D72756E74,"samrunt")
 Define_Atom(X3E,">")
 Define_Atom(X6D65726765,"merge")
 Define_Atom(X6B6579736F7274,"keysort")
 Define_Atom(X73616D6B657966757365,"samkeyfuse")
 Define_Atom(X73616D6B657972756E,"samkeyrun")
 Define_Atom(X2D,"-")
 Define_Atom(X6B65796D65726765,"keymerge")


 Define_Pred(X636F70795F7465726D,2,1)

 Define_Pred(X736574617267,3,1)

 Define_Pred(X736F7274,2,1)

 Define_Pred(X736F7274,4,0)

 Define_Pred(X73616D66757365,3,0)

 Define_Pred(X73616D72756E,5,0)

 Define_Pred(X73616D72756E68,4,0)
 Define_Switch_CST_Table(Swt_Table_Name(X73616D72756E68,4,1,cst),2)
     Define_Switch_CST(X3C,Label_Pred_Name(X73616D72756E68,4,3))
     Define_Switch_CST(X3D,Label_Pred_Name(X73616D72756E68,4,5))

 Define_Pred(X73616D72756E74,6,0)
 Define_Switch_CST_Table(Swt_Table_Name(X73616D72756E74,6,1,cst),3)
     Define_Switch_CST(X3C,Label_Pred_Name(X73616D72756E74,6,3))
     Define_Switch_CST(X3D,Label_Pred_Name(X73616D72756E74,6,5))
     Define_Switch_CST(X3E,Label_Pred_Name(X73616D72756E74,6,7))

 Define_Pred(X6D65726765,3,0)

 Define_Pred(X6D65726765,4,0)
 Define_Switch_CST_Table(Swt_Table_Name(X6D65726765,4,1,cst),3)
     Define_Switch_CST(X3C,Label_Pred_Name(X6D65726765,4,3))
     Define_Switch_CST(X3D,Label_Pred_Name(X6D65726765,4,5))
     Define_Switch_CST(X3E,Label_Pred_Name(X6D65726765,4,7))

 Define_Pred(X6B6579736F7274,2,1)

 Define_Pred(X6B6579736F7274,4,0)

 Define_Pred(X73616D6B657966757365,3,0)

 Define_Pred(X73616D6B657972756E,5,0)

 Define_Pred(X6B65796D65726765,3,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(term)



End_Exec_Directives
