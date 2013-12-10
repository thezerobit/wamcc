/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : wamcc3.c
Main : no_main
****************************************************************************/

#define FAST_MATH
#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "wamcc3.h"
#include "wamcc3.usr"


#define ASCII_PRED "classif_variables"
#define PRED       X636C61737369665F7661726961626C6573
#define ARITY      2

Begin_Public_Pred
      allocate(2)
      get_y_variable(1,0)
      put_x_value(1,0)
      put_y_variable(0,1)
      call(Pred_Name(X636C61737369665F636F727073,2),1,2,1,"classif_corps",2)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X636C61737369665F74657465,2),1,"classif_tete",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "classif_tete"
#define PRED       X636C61737369665F74657465
#define ARITY      2

Begin_Private_Pred
      put_x_variable(2,2)
      execute(Pred_Name(X636C61737369665F70726564,3),1,"classif_pred",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "classif_corps"
#define PRED       X636C61737369665F636F727073
#define ARITY      2

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_integer(0,1)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(3)
      get_list(0)
      unify_y_variable(2)
      unify_x_variable(0)
      get_y_variable(0,1)
      put_y_variable(1,1)
      call(Pred_Name(X636C61737369665F636F727073,2),1,3,1,"classif_corps",2)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X636C61737369665F70726564,3),1,"classif_pred",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "classif_pred"
#define PRED       X636C61737369665F70726564
#define ARITY      3

Begin_Private_Pred
      switch_on_term(G_label(1),fail,fail,fail,G_label(1))

label(1)
      allocate(3)
      get_structure(X70,4,0)
      unify_x_variable(4)
      unify_void(1)
      unify_x_variable(0)
      unify_y_variable(1)
      get_x_variable(3,1)
      get_y_variable(0,2)
      put_x_value(4,1)
      put_x_value(3,2)
      put_y_value(1,3)
      put_nil(4)
      put_y_variable(2,5)
      call(Pred_Name(X636C61737369665F6C73745F617267,6),1,3,1,"classif_lst_arg",6)          /* begin sub 1 */
      put_y_unsafe_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X616C6C6F635F7672616965735F7661727359,3),1,"alloc_vraies_varsY",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "classif_lst_arg"
#define PRED       X636C61737369665F6C73745F617267
#define ARITY      6

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_x_value(2,3)
      get_x_value(4,5)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(7)
      get_list(0)
      unify_y_variable(6)
      unify_x_variable(0)
      get_y_variable(5,1)
      get_y_variable(3,3)
      get_y_variable(1,5)
      get_y_bc_reg(0)
      put_y_value(5,1)
      put_y_variable(4,3)
      put_y_variable(2,5)
      call(Pred_Name(X636C61737369665F6C73745F617267,6),1,7,1,"classif_lst_arg",6)          /* begin sub 1 */
      put_y_value(6,0)
      put_y_value(5,1)
      put_y_unsafe_value(4,2)
      put_y_value(3,3)
      put_y_unsafe_value(2,4)
      put_y_value(1,5)
      call(Pred_Name(X636C61737369665F617267,6),1,1,2,"classif_arg",6)          /* begin sub 2 */
      cut_y(0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "classif_arg"
#define PRED       X636C61737369665F617267
#define ARITY      6

Begin_Private_Pred
      switch_on_term(G_label(3),G_label(10),fail,fail,G_label(1))

label(1)
      switch_on_structure(1,"[(var/3,2),(cst/1,12),(int/1,14),(lst/2,16),(stc/2,18)]")

label(2)
      try(4,1)          /* begin sub 1 */
      retry(6,2)          /* begin sub 2 */
      trust(8)

label(3)
      try_me_else(5)

label(4)
      get_structure(X766172,3,0)
      unify_x_variable(0)
      unify_void(1)
      unify_constant(X74)
      get_structure(X696776,5,0)
      unify_x_variable(0)
      unify_void(1)
      unify_x_variable(6)
      unify_void(2)
      get_x_value(6,1)
      get_x_value(2,3)
      get_x_value(4,5)
      builtin_1(var,0)
      get_structure(X78,1,0)
      unify_void(1)
      proceed

label(5)
      retry_me_else(7)

label(6)
      get_structure(X766172,3,0)
      unify_x_variable(0)
      unify_void(1)
      unify_constant(X74)
      get_structure(X696776,5,0)
      unify_x_variable(6)
      unify_void(1)
      unify_x_variable(0)
      unify_void(2)
      get_structure(X79,1,6)
      unify_x_variable(6)
      get_x_value(2,3)
      get_list(5)
      unify_x_value(6)
      unify_x_local_value(4)
      builtin_1(var,0)
      get_x_value(1,0)
      proceed

label(7)
      retry_me_else(9)

label(8)
      get_structure(X766172,3,0)
      unify_void(2)
      unify_constant(X66)
      get_x_value(2,3)
      get_x_value(4,5)
      proceed

label(9)
      retry_me_else(11)

label(10)
      get_constant(X6E696C,0)
      get_x_value(2,3)
      get_x_value(4,5)
      proceed

label(11)
      retry_me_else(13)

label(12)
      get_structure(X637374,1,0)
      unify_void(1)
      get_x_value(2,3)
      get_x_value(4,5)
      proceed

label(13)
      retry_me_else(15)

label(14)
      get_structure(X696E74,1,0)
      unify_void(1)
      get_x_value(2,3)
      get_x_value(4,5)
      proceed

label(15)
      retry_me_else(17)

label(16)
      get_structure(X6C7374,2,0)
      unify_x_variable(7)
      unify_x_variable(0)
      put_list(6)
      unify_x_value(0)
      unify_nil
      put_list(0)
      unify_x_value(7)
      unify_x_value(6)
      execute(Pred_Name(X636C61737369665F6C73745F617267,6),1,"classif_lst_arg",6)

label(17)
      trust_me_else_fail

label(18)
      get_structure(X737463,2,0)
      unify_void(1)
      unify_x_variable(0)
      execute(Pred_Name(X636C61737369665F6C73745F617267,6),1,"classif_lst_arg",6)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "temporaire"
#define PRED       X74656D706F7261697265
#define ARITY      3

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,G_label(1),fail,fail)

label(1)
      get_integer(0,0)
      proceed

label(2)
      retry_me_else(3)
      get_constant(X74,1)
      proceed

label(3)
      trust_me_else_fail
      get_x_value(0,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "alloc_vraies_varsY"
#define PRED       X616C6C6F635F7672616965735F7661727359
#define ARITY      3

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_x_value(1,2)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(2)
      get_list(0)
      unify_y_variable(0)
      unify_x_variable(0)
      get_y_variable(1,2)
      put_y_value(0,2)
      call(Pred_Name(X616C6C6F635F7672616965735F7661727359,3),1,2,1,"alloc_vraies_varsY",3)          /* begin sub 1 */
      math_load_y_value(0,0)
      function_1(inc,0,0)
      get_y_value(1,0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(wamcc3)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X636C61737369665F7661726961626C6573,"classif_variables")
 Define_Atom(X636C61737369665F74657465,"classif_tete")
 Define_Atom(X636C61737369665F636F727073,"classif_corps")
 Define_Atom(X636C61737369665F70726564,"classif_pred")
 Define_Atom(X70,"p")
 Define_Atom(X636C61737369665F6C73745F617267,"classif_lst_arg")
 Define_Atom(X636C61737369665F617267,"classif_arg")
 Define_Atom(X766172,"var")
 Define_Atom(X74,"t")
 Define_Atom(X696776,"igv")
 Define_Atom(X78,"x")
 Define_Atom(X79,"y")
 Define_Atom(X66,"f")
 Define_Atom(X6E696C,"nil")
 Define_Atom(X637374,"cst")
 Define_Atom(X696E74,"int")
 Define_Atom(X6C7374,"lst")
 Define_Atom(X737463,"stc")
 Define_Atom(X74656D706F7261697265,"temporaire")
 Define_Atom(X616C6C6F635F7672616965735F7661727359,"alloc_vraies_varsY")


 Define_Pred(X636C61737369665F7661726961626C6573,2,1)

 Define_Pred(X636C61737369665F74657465,2,0)

 Define_Pred(X636C61737369665F636F727073,2,0)

 Define_Pred(X636C61737369665F70726564,3,0)

 Define_Pred(X636C61737369665F6C73745F617267,6,0)

 Define_Pred(X636C61737369665F617267,6,0)
 Define_Switch_STC_Table(Swt_Table_Name(X636C61737369665F617267,6,1,stc),5)
     Define_Switch_STC(X766172,3,Label_Pred_Name(X636C61737369665F617267,6,2))
     Define_Switch_STC(X637374,1,Label_Pred_Name(X636C61737369665F617267,6,12))
     Define_Switch_STC(X696E74,1,Label_Pred_Name(X636C61737369665F617267,6,14))
     Define_Switch_STC(X6C7374,2,Label_Pred_Name(X636C61737369665F617267,6,16))
     Define_Switch_STC(X737463,2,Label_Pred_Name(X636C61737369665F617267,6,18))

 Define_Pred(X74656D706F7261697265,3,0)

 Define_Pred(X616C6C6F635F7672616965735F7661727359,3,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(wamcc3)



End_Exec_Directives
