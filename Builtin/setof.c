/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : setof.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "setof.h"
#include "setof.usr"


#define ASCII_PRED "findall"
#define PRED       X66696E64616C6C
#define ARITY      3

Begin_Public_Pred
      put_nil(3)
      execute(Pred_Name(X66696E64616C6C,4),1,"findall",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "findall"
#define PRED       X66696E64616C6C
#define ARITY      4

Begin_Public_Pred
      allocate(5)
      get_y_variable(4,0)
      get_y_variable(3,1)
      get_y_variable(2,2)
      get_y_variable(1,3)
      put_constant(X2466696E64616C6C,0)
      put_y_variable(0,1)
      call(Pred_Name(X67656E73796D,2),0,5,1,"gensym",2)          /* begin sub 1 */
      put_y_value(0,1)
      put_list(0)
      unify_x_variable(2)
      unify_x_value(2)
      builtin_2(g_assign,1,0)
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_value(1,3)
      put_y_unsafe_value(0,4)
      deallocate
      execute(Pred_Name(X66696E64616C6C5F2461757831,5),1,"findall_$aux1",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "findall_$aux1"
#define PRED       X66696E64616C6C5F2461757831
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      allocate(2)
      get_y_variable(1,0)
      get_y_variable(0,4)
      put_x_value(1,0)
      call(Pred_Name(X63616C6C,1),0,2,1,"call",1)          /* begin sub 1 */
      put_y_value(0,3)
      put_list(1)
      unify_x_variable(0)
      unify_x_variable(2)
      builtin_2(g_read,3,1)
      get_list(0)
      unify_y_local_value(1)
      unify_x_variable(3)
      put_y_value(0,1)
      put_list(0)
      unify_x_value(3)
      unify_x_value(2)
      builtin_2(g_assign,1,0)
      fail

label(1)
      trust_me_else_fail
      put_list(0)
      unify_x_local_value(3)
      unify_x_local_value(2)
      builtin_2(g_read,4,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "setof"
#define PRED       X7365746F66
#define ARITY      3

Begin_Public_Pred
      allocate(2)
      get_y_variable(0,2)
      put_y_variable(1,2)
      call(Pred_Name(X6261676F66,3),1,2,1,"bagof",3)          /* begin sub 1 */
      put_y_unsafe_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X736F7274,2),0,"sort",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "bagof"
#define PRED       X6261676F66
#define ARITY      3

Begin_Public_Pred
      try_me_else(1)
      allocate(11)
      get_y_variable(9,0)
      get_y_variable(8,1)
      get_y_variable(1,2)
      get_y_bc_reg(4)
      put_y_value(8,0)
      put_y_value(9,1)
      put_nil(2)
      put_y_variable(10,3)
      call(Pred_Name(X667265655F7661726961626C6573,4),1,11,1,"free_variables",4)          /* begin sub 1 */
      put_y_value(10,1)
      put_nil(0)
      builtin_2(term_neq,1,0)
      cut_y(4)
      put_y_variable(2,1)
      put_list(0)
      unify_constant(X2E)
      unify_y_local_value(10)
      builtin_2(term_univ,1,0)
      put_y_value(2,2)
      put_constant(X2E,1)
      put_y_variable(6,0)
      builtin_3(functor,2,1,0)
      put_structure(X2D,2,0)
      unify_y_local_value(2)
      unify_y_local_value(9)
      put_y_value(8,1)
      put_y_variable(7,2)
      call(Pred_Name(X66696E64616C6C,3),1,8,2,"findall",3)          /* begin sub 2 */
      put_y_unsafe_value(7,0)
      put_y_value(2,1)
      put_y_unsafe_value(6,2)
      put_y_variable(5,3)
      call(Pred_Name(X7265706C6163655F696E7374616E6365,4),1,6,3,"replace_instance",4)          /* begin sub 3 */
      put_y_unsafe_value(5,0)
      put_y_variable(3,1)
      call(Pred_Name(X6B6579736F7274,2),0,5,4,"keysort",2)          /* begin sub 4 */
      cut_y(4)
      put_y_unsafe_value(3,0)
      put_y_unsafe_value(2,1)
      put_y_variable(0,2)
      call(Pred_Name(X636F6E636F7264616E745F737562736574,3),1,2,5,"concordant_subset",3)          /* begin sub 5 */
      put_y_value(1,0)
      get_y_value(0,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      get_list(2)
      unify_x_variable(4)
      unify_x_variable(3)
      put_list(2)
      unify_x_value(4)
      unify_x_value(3)
      execute(Pred_Name(X66696E64616C6C,3),1,"findall",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "replace_instance"
#define PRED       X7265706C6163655F696E7374616E6365
#define ARITY      4

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_nil(3)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(5)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_structure(X2D,2,0)
      unify_x_variable(4)
      unify_x_variable(0)
      get_y_variable(2,1)
      get_y_variable(1,2)
      get_list(3)
      unify_x_variable(1)
      unify_y_variable(0)
      get_structure(X2D,2,1)
      unify_x_value(4)
      unify_x_value(0)
      get_y_bc_reg(4)
      put_y_value(1,0)
      put_y_value(2,1)
      put_x_value(4,2)
      call(Pred_Name(X7265706C6163655F6B65795F7661726961626C6573,3),1,5,1,"replace_key_variables",3)          /* begin sub 1 */
      cut_y(4)
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X7265706C6163655F696E7374616E6365,4),1,"replace_instance",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "replace_key_variables"
#define PRED       X7265706C6163655F6B65795F7661726961626C6573
#define ARITY      3

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,G_label(1),fail,fail)

label(1)
      get_integer(0,0)
      neck_cut
      proceed

label(2)
      retry_me_else(3)
      put_x_variable(3,4)
      builtin_3(arg,0,2,4)
      builtin_1(nonvar,3)
      neck_cut
      math_load_x_value(0,0)
      function_1(dec,0,0)
      execute(Pred_Name(X7265706C6163655F6B65795F7661726961626C6573,3),1,"replace_key_variables",3)

label(3)
      trust_me_else_fail
      put_x_variable(3,4)
      builtin_3(arg,0,1,4)
      builtin_3(arg,0,2,3)
      math_load_x_value(0,0)
      function_1(dec,0,0)
      execute(Pred_Name(X7265706C6163655F6B65795F7661726961626C6573,3),1,"replace_key_variables",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "concordant_subset"
#define PRED       X636F6E636F7264616E745F737562736574
#define ARITY      3

Begin_Private_Pred
      switch_on_term(G_label(1),fail,fail,G_label(1),fail)

label(1)
      allocate(6)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      get_structure(X2D,2,3)
      unify_y_variable(4)
      unify_y_variable(3)
      get_y_variable(1,1)
      get_y_variable(0,2)
      put_y_value(4,1)
      put_y_variable(2,2)
      put_y_variable(5,3)
      call(Pred_Name(X636F6E636F7264616E745F737562736574,4),1,6,1,"concordant_subset",4)          /* begin sub 1 */
      put_y_unsafe_value(5,0)
      put_y_value(4,1)
      put_list(2)
      unify_y_value(3)
      unify_y_local_value(2)
      put_y_value(1,3)
      put_y_value(0,4)
      deallocate
      execute(Pred_Name(X636F6E636F7264616E745F737562736574,5),1,"concordant_subset",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "concordant_subset"
#define PRED       X636F6E636F7264616E745F737562736574
#define ARITY      4

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,fail,G_label(1),fail)

label(1)
      get_list(0)
      unify_x_variable(4)
      unify_x_variable(0)
      get_structure(X2D,2,4)
      unify_x_variable(4)
      unify_x_variable(5)
      get_list(2)
      unify_x_value(5)
      unify_x_variable(2)
      builtin_2(term_eq,4,1)
      neck_cut
      execute(Pred_Name(X636F6E636F7264616E745F737562736574,4),1,"concordant_subset",4)

label(2)
      trust_me_else_fail
      get_nil(2)
      get_x_value(0,3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "concordant_subset"
#define PRED       X636F6E636F7264616E745F737562736574
#define ARITY      5

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),G_label(1),fail,fail,fail)

label(1)
      get_nil(0)
      get_x_value(1,3)
      get_x_value(2,4)
      neck_cut
      proceed

label(2)
      retry_me_else(3)
      get_x_value(1,3)
      get_x_value(2,4)
      proceed

label(3)
      trust_me_else_fail
      put_x_value(3,1)
      put_x_value(4,2)
      execute(Pred_Name(X636F6E636F7264616E745F737562736574,3),1,"concordant_subset",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "free_variables"
#define PRED       X667265655F7661726961626C6573
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      allocate(3)
      get_y_variable(1,0)
      get_y_variable(2,2)
      get_list(3)
      unify_y_local_value(1)
      unify_y_local_value(2)
      get_y_bc_reg(0)
      put_y_value(1,0)
      builtin_1(var,0)
      put_x_value(1,0)
      put_y_value(1,1)
      call(Pred_Name(X7465726D5F69735F667265655F6F66,2),1,3,1,"term_is_free_of",2)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_value(1,1)
      call(Pred_Name(X6C6973745F69735F667265655F6F66,2),1,1,2,"list_is_free_of",2)          /* begin sub 2 */
      cut_y(0)
      deallocate
      proceed

label(1)
      retry_me_else(2)
      get_x_value(2,3)
      builtin_1(var,0)
      neck_cut
      proceed

label(2)
      retry_me_else(3)
      allocate(5)
      get_y_variable(1,2)
      get_y_variable(0,3)
      get_y_bc_reg(4)
      put_y_variable(3,2)
      put_y_variable(2,3)
      call(Pred_Name(X6578706C696369745F62696E64696E67,4),1,5,3,"explicit_binding",4)          /* begin sub 3 */
      cut_y(4)
      put_y_unsafe_value(3,0)
      put_y_unsafe_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X667265655F7661726961626C6573,4),1,"free_variables",4)

label(3)
      trust_me_else_fail
      get_x_variable(7,0)
      get_x_variable(6,1)
      get_x_variable(5,2)
      get_x_variable(4,3)
      put_x_variable(0,2)
      put_x_variable(0,1)
      builtin_3(functor,7,2,1)
      put_x_value(7,1)
      put_x_value(6,2)
      put_x_value(5,3)
      execute(Pred_Name(X667265655F7661726961626C6573,5),1,"free_variables",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "free_variables"
#define PRED       X667265655F7661726961626C6573
#define ARITY      5

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,G_label(1),fail,fail)

label(1)
      get_integer(0,0)
      get_x_value(3,4)
      neck_cut
      proceed

label(2)
      trust_me_else_fail
      allocate(6)
      get_y_variable(5,0)
      get_y_variable(3,1)
      get_y_variable(2,2)
      get_y_variable(0,4)
      get_y_bc_reg(4)
      put_y_value(5,4)
      put_y_value(3,2)
      put_x_variable(0,1)
      builtin_3(arg,4,2,1)
      put_y_value(2,1)
      put_x_value(3,2)
      put_y_variable(1,3)
      call(Pred_Name(X667265655F7661726961626C6573,4),1,6,1,"free_variables",4)          /* begin sub 1 */
      math_load_y_value(5,0)
      function_1(dec,0,0)
      cut_y(4)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_unsafe_value(1,3)
      put_y_value(0,4)
      deallocate
      execute(Pred_Name(X667265655F7661726961626C6573,5),1,"free_variables",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "explicit_binding"
#define PRED       X6578706C696369745F62696E64696E67
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      builtin_1(var,0)
      neck_cut
      fail

label(1)
      trust_me_else_fail
      switch_on_term(G_label(3),fail,fail,fail,G_label(2))

label(2)
      switch_on_structure(2,"[((\+)/1,4),(not/1,6),(^ /2,8),(setof/3,10),(bagof/3,12),(findall/3,14),(findall/4,16)]")

label(3)
      try_me_else(5)

label(4)
      get_structure(X5C2B,1,0)
      unify_void(1)
      get_constant(X6661696C,2)
      get_x_value(1,3)
      proceed

label(5)
      retry_me_else(7)

label(6)
      get_structure(X6E6F74,1,0)
      unify_void(1)
      get_constant(X6661696C,2)
      get_x_value(1,3)
      proceed

label(7)
      retry_me_else(9)

label(8)
      get_structure(X5E,2,0)
      unify_x_variable(0)
      unify_x_variable(4)
      get_x_value(4,2)
      get_structure(X2B,2,3)
      unify_x_local_value(1)
      unify_x_value(0)
      proceed

label(9)
      retry_me_else(11)

label(10)
      get_structure(X7365746F66,3,0)
      unify_x_variable(0)
      unify_x_variable(5)
      unify_x_variable(4)
      get_structure(X2D,2,2)
      unify_x_value(5)
      unify_x_value(4)
      get_structure(X2B,2,3)
      unify_x_local_value(1)
      unify_x_value(0)
      proceed

label(11)
      retry_me_else(13)

label(12)
      get_structure(X6261676F66,3,0)
      unify_x_variable(0)
      unify_x_variable(5)
      unify_x_variable(4)
      get_structure(X2D,2,2)
      unify_x_value(5)
      unify_x_value(4)
      get_structure(X2B,2,3)
      unify_x_local_value(1)
      unify_x_value(0)
      proceed

label(13)
      retry_me_else(15)

label(14)
      get_structure(X66696E64616C6C,3,0)
      unify_void(2)
      unify_x_variable(0)
      get_x_value(0,2)
      get_x_value(1,3)
      proceed

label(15)
      trust_me_else_fail

label(16)
      get_structure(X66696E64616C6C,4,0)
      unify_void(2)
      unify_x_variable(4)
      unify_x_variable(0)
      get_structure(X2D,2,2)
      unify_x_value(4)
      unify_x_value(0)
      get_x_value(1,3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "term_is_free_of"
#define PRED       X7465726D5F69735F667265655F6F66
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      builtin_1(var,0)
      neck_cut
      builtin_2(term_neq,0,1)
      proceed

label(1)
      trust_me_else_fail
      get_x_variable(3,0)
      get_x_variable(2,1)
      put_x_variable(0,4)
      put_x_variable(0,1)
      builtin_3(functor,3,4,1)
      put_x_value(3,1)
      execute(Pred_Name(X7465726D5F69735F667265655F6F66,3),1,"term_is_free_of",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "term_is_free_of"
#define PRED       X7465726D5F69735F667265655F6F66
#define ARITY      3

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,G_label(1),fail,fail)

label(1)
      get_integer(0,0)
      neck_cut
      proceed

label(2)
      trust_me_else_fail
      allocate(4)
      get_y_variable(3,0)
      get_y_variable(1,1)
      get_y_variable(0,2)
      get_y_bc_reg(2)
      put_y_value(3,3)
      put_y_value(1,2)
      put_x_variable(0,1)
      builtin_3(arg,3,2,1)
      put_y_value(0,1)
      call(Pred_Name(X7465726D5F69735F667265655F6F66,2),1,4,1,"term_is_free_of",2)          /* begin sub 1 */
      math_load_y_value(3,0)
      function_1(dec,0,0)
      cut_y(2)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X7465726D5F69735F667265655F6F66,3),1,"term_is_free_of",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "list_is_free_of"
#define PRED       X6C6973745F69735F667265655F6F66
#define ARITY      2

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
      get_list(0)
      unify_x_variable(2)
      unify_x_variable(0)
      builtin_2(term_neq,2,1)
      execute(Pred_Name(X6C6973745F69735F667265655F6F66,2),1,"list_is_free_of",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(setof)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X66696E64616C6C,"findall")
 Define_Atom(X2466696E64616C6C,"$findall")
 Define_Atom(X66696E64616C6C5F2461757831,"findall_$aux1")
 Define_Atom(X7365746F66,"setof")
 Define_Atom(X6261676F66,"bagof")
 Define_Atom(X2E,".")
 Define_Atom(X2D,"-")
 Define_Atom(X7265706C6163655F696E7374616E6365,"replace_instance")
 Define_Atom(X7265706C6163655F6B65795F7661726961626C6573,"replace_key_variables")
 Define_Atom(X636F6E636F7264616E745F737562736574,"concordant_subset")
 Define_Atom(X667265655F7661726961626C6573,"free_variables")
 Define_Atom(X6578706C696369745F62696E64696E67,"explicit_binding")
 Define_Atom(X5C2B,"\\+")
 Define_Atom(X6661696C,"fail")
 Define_Atom(X6E6F74,"not")
 Define_Atom(X5E,"^")
 Define_Atom(X2B,"+")
 Define_Atom(X7465726D5F69735F667265655F6F66,"term_is_free_of")
 Define_Atom(X6C6973745F69735F667265655F6F66,"list_is_free_of")


 Define_Pred(X66696E64616C6C,3,1)

 Define_Pred(X66696E64616C6C,4,1)

 Define_Pred(X66696E64616C6C5F2461757831,5,0)

 Define_Pred(X7365746F66,3,1)

 Define_Pred(X6261676F66,3,1)

 Define_Pred(X7265706C6163655F696E7374616E6365,4,0)

 Define_Pred(X7265706C6163655F6B65795F7661726961626C6573,3,0)

 Define_Pred(X636F6E636F7264616E745F737562736574,3,0)

 Define_Pred(X636F6E636F7264616E745F737562736574,4,0)

 Define_Pred(X636F6E636F7264616E745F737562736574,5,0)

 Define_Pred(X667265655F7661726961626C6573,4,0)

 Define_Pred(X667265655F7661726961626C6573,5,0)

 Define_Pred(X6578706C696369745F62696E64696E67,4,0)
 Define_Switch_STC_Table(Swt_Table_Name(X6578706C696369745F62696E64696E67,4,2,stc),7)
     Define_Switch_STC(X5C2B,1,Label_Pred_Name(X6578706C696369745F62696E64696E67,4,4))
     Define_Switch_STC(X6E6F74,1,Label_Pred_Name(X6578706C696369745F62696E64696E67,4,6))
     Define_Switch_STC(X5E,2,Label_Pred_Name(X6578706C696369745F62696E64696E67,4,8))
     Define_Switch_STC(X7365746F66,3,Label_Pred_Name(X6578706C696369745F62696E64696E67,4,10))
     Define_Switch_STC(X6261676F66,3,Label_Pred_Name(X6578706C696369745F62696E64696E67,4,12))
     Define_Switch_STC(X66696E64616C6C,3,Label_Pred_Name(X6578706C696369745F62696E64696E67,4,14))
     Define_Switch_STC(X66696E64616C6C,4,Label_Pred_Name(X6578706C696369745F62696E64696E67,4,16))

 Define_Pred(X7465726D5F69735F667265655F6F66,2,0)

 Define_Pred(X7465726D5F69735F667265655F6F66,3,0)

 Define_Pred(X6C6973745F69735F667265655F6F66,2,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(setof)



End_Exec_Directives
