/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : wamcc2.c
Main : no_main
****************************************************************************/

#define FAST_MATH
#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "wamcc2.h"
#include "wamcc2.usr"


#define ASCII_PRED "format_interne"
#define PRED       X666F726D61745F696E7465726E65
#define ARITY      5

Begin_Public_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,fail,fail,G_label(1))

label(1)
      allocate(4)
      get_structure(X3A2D,2,0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_x_variable(5,1)
      get_y_variable(1,3)
      get_y_variable(0,4)
      put_y_variable(2,1)
      put_x_value(5,3)
      call(Pred_Name(X666F726D6174655F74657465,4),1,4,1,"formate_tete",4)          /* begin sub 1 */
      put_y_value(3,0)
      put_y_unsafe_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X666F726D6174655F636F727073,4),1,"formate_corps",4)

label(2)
      trust_me_else_fail
      get_x_variable(5,1)
      get_nil(3)
      get_integer(0,4)
      put_x_variable(1,1)
      put_x_value(5,3)
      execute(Pred_Name(X666F726D6174655F74657465,4),1,"formate_tete",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "formate_tete"
#define PRED       X666F726D6174655F74657465
#define ARITY      4

Begin_Private_Pred
      allocate(3)
      get_y_variable(2,0)
      get_y_variable(1,1)
      get_y_variable(0,2)
      put_y_value(2,0)
      put_x_value(3,1)
      call(Pred_Name(X7072656D5F617267,2),1,3,1,"prem_arg",2)          /* begin sub 1 */
      put_y_value(2,0)
      put_integer(0,1)
      put_y_value(1,2)
      put_y_value(0,3)
      put_x_variable(4,4)
      deallocate
      execute(Pred_Name(X666F726D6174655F70726564,5),1,"formate_pred",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "prem_arg"
#define PRED       X7072656D5F617267
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      get_structure(X2F,2,1)
      unify_x_variable(2)
      unify_x_variable(1)
      builtin_1(compound,0)
      put_integer(1,5)
      put_x_variable(3,4)
      builtin_3(arg,5,0,4)
      builtin_1(nonvar,3)
      builtin_3(functor,3,2,1)
      proceed

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "formate_corps"
#define PRED       X666F726D6174655F636F727073
#define ARITY      4

Begin_Private_Pred
      get_x_variable(4,1)
      get_x_variable(5,2)
      get_x_variable(6,3)
      put_integer(0,1)
      put_x_value(4,2)
      put_constant(X74,3)
      put_nil(4)
      put_x_variable(7,7)
      execute(Pred_Name(X666F726D6174655F636F72707331,8),1,"formate_corps1",8)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "formate_corps1"
#define PRED       X666F726D6174655F636F72707331
#define ARITY      8

Begin_Private_Pred
      try_me_else(5)
      switch_on_term(G_label(1),G_label(4),fail,fail,G_label(2))

label(1)
      try_me_else(3)

label(2)
      allocate(9)
      get_structure(X2C,2,0)
      unify_x_variable(0)
      unify_y_variable(8)
      get_y_variable(6,2)
      get_y_variable(4,4)
      get_y_variable(2,6)
      get_y_variable(1,7)
      get_y_bc_reg(0)
      put_y_value(6,2)
      put_y_variable(3,4)
      put_y_variable(7,6)
      put_y_variable(5,7)
      call(Pred_Name(X666F726D6174655F636F72707331,8),1,9,1,"formate_corps1",8)          /* begin sub 1 */
      cut_y(0)
      put_y_value(8,0)
      put_y_unsafe_value(7,1)
      put_y_value(6,2)
      put_y_unsafe_value(5,3)
      put_y_value(4,4)
      put_y_unsafe_value(3,5)
      put_y_value(2,6)
      put_y_value(1,7)
      call(Pred_Name(X666F726D6174655F636F72707331,8),1,1,2,"formate_corps1",8)          /* begin sub 2 */
      cut_y(0)
      deallocate
      proceed

label(3)
      trust_me_else_fail

label(4)
      get_constant(X74727565,0)
      get_x_value(4,5)
      get_x_value(1,6)
      get_x_value(3,7)
      proceed

label(5)
      trust_me_else_fail
      allocate(6)
      get_y_variable(5,0)
      get_y_variable(3,2)
      get_list(5)
      unify_y_variable(2)
      unify_x_local_value(4)
      get_y_variable(4,6)
      get_y_variable(1,7)
      put_x_value(1,0)
      put_x_value(3,1)
      put_y_value(4,2)
      call(Pred_Name(X666F726D6174655F636F727073315F2461757831,3),1,6,3,"formate_corps1_$aux1",3)          /* begin sub 3 */
      put_y_value(5,0)
      put_y_value(4,1)
      put_y_value(3,2)
      put_y_value(2,3)
      put_y_variable(0,4)
      call(Pred_Name(X666F726D6174655F70726564,5),1,2,4,"formate_pred",5)          /* begin sub 4 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X666F726D6174655F636F727073315F2461757832,2),1,"formate_corps1_$aux2",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "formate_corps1_$aux2"
#define PRED       X666F726D6174655F636F727073315F2461757832
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      put_constant(X74,2)
      builtin_2(term_eq,1,2)
      neck_cut
      get_constant(X66,0)
      proceed

label(1)
      trust_me_else_fail
      get_constant(X74,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "formate_corps1_$aux1"
#define PRED       X666F726D6174655F636F727073315F2461757831
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      put_constant(X74,3)
      builtin_2(term_eq,1,3)
      neck_cut
      math_load_x_value(0,0)
      function_1(inc,0,0)
      get_x_value(2,0)
      proceed

label(1)
      trust_me_else_fail
      get_x_value(0,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "formate_pred"
#define PRED       X666F726D6174655F70726564
#define ARITY      5

Begin_Private_Pred
      allocate(3)
      get_x_variable(6,0)
      get_structure(X70,4,3)
      unify_x_local_value(1)
      unify_x_variable(0)
      unify_x_variable(5)
      unify_void(1)
      get_structure(X2F,2,0)
      unify_y_variable(2)
      unify_y_variable(1)
      get_y_variable(0,4)
      put_y_value(2,3)
      put_y_value(1,0)
      builtin_3(functor,6,3,0)
      put_list(3)
      unify_void(1)
      unify_x_variable(0)
      builtin_2(term_univ,6,3)
      put_constant(X66,3)
      put_x_value(5,4)
      call(Pred_Name(X666F726D6174655F6C73745F617267,5),1,3,1,"formate_lst_arg",5)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X666F726D6174655F707265645F2461757833,3),1,"formate_pred_$aux3",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "formate_pred_$aux3"
#define PRED       X666F726D6174655F707265645F2461757833
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      allocate(2)
      get_y_variable(0,2)
      get_y_bc_reg(1)
      call(Pred_Name(X696E6C696E655F707265646963617465,2),1,2,1,"inline_predicate",2)          /* begin sub 1 */
      cut_y(1)
      put_y_value(0,0)
      get_constant(X74,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      get_constant(X66,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "formate_lst_arg"
#define PRED       X666F726D6174655F6C73745F617267
#define ARITY      5

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_nil(4)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(6)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(4)
      get_y_variable(3,1)
      get_y_variable(2,2)
      get_y_variable(1,3)
      get_list(4)
      unify_x_variable(4)
      unify_y_variable(0)
      get_y_bc_reg(5)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_value(1,3)
      call(Pred_Name(X666F726D6174655F617267,5),1,6,1,"formate_arg",5)          /* begin sub 1 */
      cut_y(5)
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_value(1,3)
      put_y_value(0,4)
      deallocate
      execute(Pred_Name(X666F726D6174655F6C73745F617267,5),1,"formate_lst_arg",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "formate_arg"
#define PRED       X666F726D6174655F617267
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      allocate(4)
      get_x_variable(5,0)
      get_y_variable(3,1)
      get_y_variable(2,3)
      get_structure(X766172,3,4)
      unify_y_variable(1)
      unify_y_variable(0)
      unify_void(1)
      builtin_1(var,5)
      put_x_value(2,0)
      put_structure(X76,2,1)
      unify_x_local_value(5)
      unify_y_value(1)
      call(Pred_Name(X6C6F6F6B75705F766172,2),1,4,1,"lookup_var",2)          /* begin sub 1 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X666F726D6174655F6172675F2461757834,4),1,"formate_arg_$aux4",4)

label(1)
      retry_me_else(6)
      switch_on_term(G_label(2),G_label(3),fail,G_label(5),fail)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      get_constant(X6E696C,4)
      proceed

label(4)
      trust_me_else_fail

label(5)
      allocate(4)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(2,1)
      get_y_variable(1,2)
      get_structure(X6C7374,2,4)
      unify_x_variable(4)
      unify_y_variable(0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_constant(X74,3)
      call(Pred_Name(X666F726D6174655F617267,5),1,4,2,"formate_arg",5)          /* begin sub 2 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_constant(X74,3)
      put_y_value(0,4)
      deallocate
      execute(Pred_Name(X666F726D6174655F617267,5),1,"formate_arg",5)

label(6)
      trust_me_else_fail
      get_x_variable(3,4)
      put_x_variable(4,7)
      put_x_variable(5,6)
      builtin_3(functor,0,7,6)
      execute(Pred_Name(X666F726D6174655F6172675F2461757835,6),1,"formate_arg_$aux5",6)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "formate_arg_$aux4"
#define PRED       X666F726D6174655F6172675F2461757834
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      builtin_1(var,2)
      neck_cut
      get_structure(X696776,5,2)
      unify_void(1)
      unify_x_local_value(0)
      unify_void(1)
      unify_x_local_value(1)
      unify_void(1)
      get_constant(X74,3)
      proceed

label(1)
      trust_me_else_fail
      get_x_variable(5,0)
      get_x_variable(1,3)
      get_structure(X696776,5,2)
      unify_x_variable(3)
      unify_x_variable(0)
      unify_void(1)
      unify_x_variable(2)
      unify_x_variable(4)
      get_constant(X66,1)
      put_x_value(5,1)
      execute(Pred_Name(X646574656374655F7661725F59,5),1,"detecte_var_Y",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "formate_arg_$aux5"
#define PRED       X666F726D6174655F6172675F2461757835
#define ARITY      6

Begin_Private_Pred
      try_me_else(1)
      get_integer(0,5)
      neck_cut
      put_x_value(4,0)
      put_x_value(3,1)
      execute(Pred_Name(X747970655F61746F6D6963,2),1,"type_atomic",2)

label(1)
      trust_me_else_fail
      allocate(4)
      get_x_variable(6,0)
      get_y_variable(3,3)
      get_y_variable(2,4)
      get_y_variable(1,5)
      put_list(3)
      unify_void(1)
      unify_x_variable(0)
      builtin_2(term_univ,6,3)
      put_constant(X74,3)
      put_y_variable(0,4)
      call(Pred_Name(X666F726D6174655F6C73745F617267,5),1,4,1,"formate_lst_arg",5)          /* begin sub 1 */
      put_y_value(3,0)
      get_structure(X737463,2,0)
      unify_x_variable(0)
      unify_y_local_value(0)
      get_structure(X2F,2,0)
      unify_y_local_value(2)
      unify_y_local_value(1)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "lookup_var"
#define PRED       X6C6F6F6B75705F766172
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      builtin_1(var,0)
      neck_cut
      get_list(0)
      unify_x_local_value(1)
      unify_void(1)
      proceed

label(1)
      trust_me_else_fail
      switch_on_term(G_label(3),fail,fail,G_label(2),fail)

label(2)
      try(4,1)          /* begin sub 1 */
      trust(6)

label(3)
      try_me_else(5)

label(4)
      get_list(0)
      unify_x_variable(0)
      unify_void(1)
      get_structure(X76,2,0)
      unify_x_variable(0)
      unify_x_variable(2)
      get_structure(X76,2,1)
      unify_x_variable(1)
      unify_x_value(2)
      builtin_2(term_eq,1,0)
      neck_cut
      proceed

label(5)
      trust_me_else_fail

label(6)
      get_list(0)
      unify_void(1)
      unify_x_variable(0)
      execute(Pred_Name(X6C6F6F6B75705F766172,2),1,"lookup_var",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "type_atomic"
#define PRED       X747970655F61746F6D6963
#define ARITY      2

Begin_Public_Pred
      try_me_else(1)
      get_structure(X637374,1,1)
      unify_x_local_value(0)
      builtin_1(atom,0)
      neck_cut
      proceed

label(1)
      trust_me_else_fail
      get_structure(X696E74,1,1)
      unify_x_local_value(0)
      builtin_1(integer,0)
      neck_cut
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "detecte_var_Y"
#define PRED       X646574656374655F7661725F59
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      get_x_value(0,1)
      proceed

label(1)
      retry_me_else(3)
      switch_on_term(G_label(2),fail,G_label(2),fail,fail)

label(2)
      get_integer(0,0)
      get_integer(1,1)
      proceed

label(3)
      trust_me_else_fail
      get_structure(X79,1,3)
      unify_void(1)
      put_x_value(2,1)
      put_x_value(4,2)
      execute(Pred_Name(X646574656374655F64616E67657265757365,3),1,"detecte_dangereuse",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "detecte_dangereuse"
#define PRED       X646574656374655F64616E67657265757365
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      get_constant(X74,2)
      put_integer(0,2)
      builtin_2(term_neq,0,2)
      put_constant(X66,0)
      builtin_2(term_eq,1,0)
      proceed

label(1)
      trust_me_else_fail
      get_constant(X66,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "inline_predicate"
#define PRED       X696E6C696E655F707265646963617465
#define ARITY      2

Begin_Public_Pred
      put_constant(X6E6F5F696E6C696E65,4)
      put_x_variable(2,3)
      builtin_2(g_read,4,3)
      execute(Pred_Name(X696E6C696E655F707265646963617465,3),1,"inline_predicate",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "inline_predicate"
#define PRED       X696E6C696E655F707265646963617465
#define ARITY      3

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(1),fail,fail,fail)

label(1)
      switch_on_constant(1,"[($get_bc_reg,3),($cut,5),($dbg_true,7),(pragma_c,9),(calling_module_nb,11),(=,13),(var,15),(nonvar,17),(atom,19),(integer,21),(number,23),(atomic,25),(compound,27),(callable,29),(functor,31),(arg,33),(compare,35),(=..,37),(==,39),(\==,41),(@<,43),(@=<,45),(@>,47),(@>=,49),(is,51),(=:=,53),(=\=,55),(<,57),(=<,59),(>,61),(>=,63),(g_assign,65),(g_assignb,67),(g_link,69),(g_read,71),(g_array_size,73)]")

label(2)
      try_me_else(4)

label(3)
      get_constant(X246765745F62635F726567,0)
      get_integer(1,1)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_constant(X24637574,0)
      get_integer(1,1)
      proceed

label(6)
      retry_me_else(8)

label(7)
      get_constant(X246462675F74727565,0)
      get_integer(0,1)
      proceed

label(8)
      retry_me_else(10)

label(9)
      get_constant(X707261676D615F63,0)
      get_integer(1,1)
      proceed

label(10)
      retry_me_else(12)

label(11)
      get_constant(X63616C6C696E675F6D6F64756C655F6E62,0)
      get_integer(1,1)
      proceed

label(12)
      retry_me_else(14)

label(13)
      get_constant(X3D,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

label(14)
      retry_me_else(16)

label(15)
      get_constant(X766172,0)
      get_integer(1,1)
      get_constant(X66,2)
      proceed

label(16)
      retry_me_else(18)

label(17)
      get_constant(X6E6F6E766172,0)
      get_integer(1,1)
      get_constant(X66,2)
      proceed

label(18)
      retry_me_else(20)

label(19)
      get_constant(X61746F6D,0)
      get_integer(1,1)
      get_constant(X66,2)
      proceed

label(20)
      retry_me_else(22)

label(21)
      get_constant(X696E7465676572,0)
      get_integer(1,1)
      get_constant(X66,2)
      proceed

label(22)
      retry_me_else(24)

label(23)
      get_constant(X6E756D626572,0)
      get_integer(1,1)
      get_constant(X66,2)
      proceed

label(24)
      retry_me_else(26)

label(25)
      get_constant(X61746F6D6963,0)
      get_integer(1,1)
      get_constant(X66,2)
      proceed

label(26)
      retry_me_else(28)

label(27)
      get_constant(X636F6D706F756E64,0)
      get_integer(1,1)
      get_constant(X66,2)
      proceed

label(28)
      retry_me_else(30)

label(29)
      get_constant(X63616C6C61626C65,0)
      get_integer(1,1)
      get_constant(X66,2)
      proceed

label(30)
      retry_me_else(32)

label(31)
      get_constant(X66756E63746F72,0)
      get_integer(3,1)
      get_constant(X66,2)
      proceed

label(32)
      retry_me_else(34)

label(33)
      get_constant(X617267,0)
      get_integer(3,1)
      get_constant(X66,2)
      proceed

label(34)
      retry_me_else(36)

label(35)
      get_constant(X636F6D70617265,0)
      get_integer(3,1)
      get_constant(X66,2)
      proceed

label(36)
      retry_me_else(38)

label(37)
      get_constant(X3D2E2E,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

label(38)
      retry_me_else(40)

label(39)
      get_constant(X3D3D,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

label(40)
      retry_me_else(42)

label(41)
      get_constant(X5C3D3D,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

label(42)
      retry_me_else(44)

label(43)
      get_constant(X403C,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

label(44)
      retry_me_else(46)

label(45)
      get_constant(X403D3C,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

label(46)
      retry_me_else(48)

label(47)
      get_constant(X403E,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

label(48)
      retry_me_else(50)

label(49)
      get_constant(X403E3D,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

label(50)
      retry_me_else(52)

label(51)
      get_constant(X6973,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

label(52)
      retry_me_else(54)

label(53)
      get_constant(X3D3A3D,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

label(54)
      retry_me_else(56)

label(55)
      get_constant(X3D5C3D,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

label(56)
      retry_me_else(58)

label(57)
      get_constant(X3C,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

label(58)
      retry_me_else(60)

label(59)
      get_constant(X3D3C,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

label(60)
      retry_me_else(62)

label(61)
      get_constant(X3E,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

label(62)
      retry_me_else(64)

label(63)
      get_constant(X3E3D,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

label(64)
      retry_me_else(66)

label(65)
      get_constant(X675F61737369676E,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

label(66)
      retry_me_else(68)

label(67)
      get_constant(X675F61737369676E62,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

label(68)
      retry_me_else(70)

label(69)
      get_constant(X675F6C696E6B,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

label(70)
      retry_me_else(72)

label(71)
      get_constant(X675F72656164,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

label(72)
      trust_me_else_fail

label(73)
      get_constant(X675F61727261795F73697A65,0)
      get_integer(2,1)
      get_constant(X66,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(wamcc2)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X666F726D61745F696E7465726E65,"format_interne")
 Define_Atom(X3A2D,":-")
 Define_Atom(X666F726D6174655F74657465,"formate_tete")
 Define_Atom(X7072656D5F617267,"prem_arg")
 Define_Atom(X2F,"/")
 Define_Atom(X666F726D6174655F636F727073,"formate_corps")
 Define_Atom(X74,"t")
 Define_Atom(X666F726D6174655F636F72707331,"formate_corps1")
 Define_Atom(X2C,",")
 Define_Atom(X74727565,"true")
 Define_Atom(X666F726D6174655F636F727073315F2461757832,"formate_corps1_$aux2")
 Define_Atom(X66,"f")
 Define_Atom(X666F726D6174655F636F727073315F2461757831,"formate_corps1_$aux1")
 Define_Atom(X666F726D6174655F70726564,"formate_pred")
 Define_Atom(X70,"p")
 Define_Atom(X666F726D6174655F707265645F2461757833,"formate_pred_$aux3")
 Define_Atom(X666F726D6174655F6C73745F617267,"formate_lst_arg")
 Define_Atom(X666F726D6174655F617267,"formate_arg")
 Define_Atom(X766172,"var")
 Define_Atom(X76,"v")
 Define_Atom(X6E696C,"nil")
 Define_Atom(X6C7374,"lst")
 Define_Atom(X666F726D6174655F6172675F2461757834,"formate_arg_$aux4")
 Define_Atom(X696776,"igv")
 Define_Atom(X666F726D6174655F6172675F2461757835,"formate_arg_$aux5")
 Define_Atom(X737463,"stc")
 Define_Atom(X6C6F6F6B75705F766172,"lookup_var")
 Define_Atom(X747970655F61746F6D6963,"type_atomic")
 Define_Atom(X637374,"cst")
 Define_Atom(X696E74,"int")
 Define_Atom(X646574656374655F7661725F59,"detecte_var_Y")
 Define_Atom(X79,"y")
 Define_Atom(X646574656374655F64616E67657265757365,"detecte_dangereuse")
 Define_Atom(X696E6C696E655F707265646963617465,"inline_predicate")
 Define_Atom(X6E6F5F696E6C696E65,"no_inline")
 Define_Atom(X246765745F62635F726567,"$get_bc_reg")
 Define_Atom(X24637574,"$cut")
 Define_Atom(X246462675F74727565,"$dbg_true")
 Define_Atom(X707261676D615F63,"pragma_c")
 Define_Atom(X63616C6C696E675F6D6F64756C655F6E62,"calling_module_nb")
 Define_Atom(X3D,"=")
 Define_Atom(X6E6F6E766172,"nonvar")
 Define_Atom(X61746F6D,"atom")
 Define_Atom(X696E7465676572,"integer")
 Define_Atom(X6E756D626572,"number")
 Define_Atom(X61746F6D6963,"atomic")
 Define_Atom(X636F6D706F756E64,"compound")
 Define_Atom(X63616C6C61626C65,"callable")
 Define_Atom(X66756E63746F72,"functor")
 Define_Atom(X617267,"arg")
 Define_Atom(X636F6D70617265,"compare")
 Define_Atom(X3D2E2E,"=..")
 Define_Atom(X3D3D,"==")
 Define_Atom(X5C3D3D,"\\==")
 Define_Atom(X403C,"@<")
 Define_Atom(X403D3C,"@=<")
 Define_Atom(X403E,"@>")
 Define_Atom(X403E3D,"@>=")
 Define_Atom(X6973,"is")
 Define_Atom(X3D3A3D,"=:=")
 Define_Atom(X3D5C3D,"=\\=")
 Define_Atom(X3C,"<")
 Define_Atom(X3D3C,"=<")
 Define_Atom(X3E,">")
 Define_Atom(X3E3D,">=")
 Define_Atom(X675F61737369676E,"g_assign")
 Define_Atom(X675F61737369676E62,"g_assignb")
 Define_Atom(X675F6C696E6B,"g_link")
 Define_Atom(X675F72656164,"g_read")
 Define_Atom(X675F61727261795F73697A65,"g_array_size")


 Define_Pred(X666F726D61745F696E7465726E65,5,1)

 Define_Pred(X666F726D6174655F74657465,4,0)

 Define_Pred(X7072656D5F617267,2,0)

 Define_Pred(X666F726D6174655F636F727073,4,0)

 Define_Pred(X666F726D6174655F636F72707331,8,0)

 Define_Pred(X666F726D6174655F636F727073315F2461757832,2,0)

 Define_Pred(X666F726D6174655F636F727073315F2461757831,3,0)

 Define_Pred(X666F726D6174655F70726564,5,0)

 Define_Pred(X666F726D6174655F707265645F2461757833,3,0)

 Define_Pred(X666F726D6174655F6C73745F617267,5,0)

 Define_Pred(X666F726D6174655F617267,5,0)

 Define_Pred(X666F726D6174655F6172675F2461757834,4,0)

 Define_Pred(X666F726D6174655F6172675F2461757835,6,0)

 Define_Pred(X6C6F6F6B75705F766172,2,0)

 Define_Pred(X747970655F61746F6D6963,2,1)

 Define_Pred(X646574656374655F7661725F59,5,0)

 Define_Pred(X646574656374655F64616E67657265757365,3,0)

 Define_Pred(X696E6C696E655F707265646963617465,2,1)

 Define_Pred(X696E6C696E655F707265646963617465,3,0)
 Define_Switch_CST_Table(Swt_Table_Name(X696E6C696E655F707265646963617465,3,1,cst),36)
     Define_Switch_CST(X246765745F62635F726567,Label_Pred_Name(X696E6C696E655F707265646963617465,3,3))
     Define_Switch_CST(X24637574,Label_Pred_Name(X696E6C696E655F707265646963617465,3,5))
     Define_Switch_CST(X246462675F74727565,Label_Pred_Name(X696E6C696E655F707265646963617465,3,7))
     Define_Switch_CST(X707261676D615F63,Label_Pred_Name(X696E6C696E655F707265646963617465,3,9))
     Define_Switch_CST(X63616C6C696E675F6D6F64756C655F6E62,Label_Pred_Name(X696E6C696E655F707265646963617465,3,11))
     Define_Switch_CST(X3D,Label_Pred_Name(X696E6C696E655F707265646963617465,3,13))
     Define_Switch_CST(X766172,Label_Pred_Name(X696E6C696E655F707265646963617465,3,15))
     Define_Switch_CST(X6E6F6E766172,Label_Pred_Name(X696E6C696E655F707265646963617465,3,17))
     Define_Switch_CST(X61746F6D,Label_Pred_Name(X696E6C696E655F707265646963617465,3,19))
     Define_Switch_CST(X696E7465676572,Label_Pred_Name(X696E6C696E655F707265646963617465,3,21))
     Define_Switch_CST(X6E756D626572,Label_Pred_Name(X696E6C696E655F707265646963617465,3,23))
     Define_Switch_CST(X61746F6D6963,Label_Pred_Name(X696E6C696E655F707265646963617465,3,25))
     Define_Switch_CST(X636F6D706F756E64,Label_Pred_Name(X696E6C696E655F707265646963617465,3,27))
     Define_Switch_CST(X63616C6C61626C65,Label_Pred_Name(X696E6C696E655F707265646963617465,3,29))
     Define_Switch_CST(X66756E63746F72,Label_Pred_Name(X696E6C696E655F707265646963617465,3,31))
     Define_Switch_CST(X617267,Label_Pred_Name(X696E6C696E655F707265646963617465,3,33))
     Define_Switch_CST(X636F6D70617265,Label_Pred_Name(X696E6C696E655F707265646963617465,3,35))
     Define_Switch_CST(X3D2E2E,Label_Pred_Name(X696E6C696E655F707265646963617465,3,37))
     Define_Switch_CST(X3D3D,Label_Pred_Name(X696E6C696E655F707265646963617465,3,39))
     Define_Switch_CST(X5C3D3D,Label_Pred_Name(X696E6C696E655F707265646963617465,3,41))
     Define_Switch_CST(X403C,Label_Pred_Name(X696E6C696E655F707265646963617465,3,43))
     Define_Switch_CST(X403D3C,Label_Pred_Name(X696E6C696E655F707265646963617465,3,45))
     Define_Switch_CST(X403E,Label_Pred_Name(X696E6C696E655F707265646963617465,3,47))
     Define_Switch_CST(X403E3D,Label_Pred_Name(X696E6C696E655F707265646963617465,3,49))
     Define_Switch_CST(X6973,Label_Pred_Name(X696E6C696E655F707265646963617465,3,51))
     Define_Switch_CST(X3D3A3D,Label_Pred_Name(X696E6C696E655F707265646963617465,3,53))
     Define_Switch_CST(X3D5C3D,Label_Pred_Name(X696E6C696E655F707265646963617465,3,55))
     Define_Switch_CST(X3C,Label_Pred_Name(X696E6C696E655F707265646963617465,3,57))
     Define_Switch_CST(X3D3C,Label_Pred_Name(X696E6C696E655F707265646963617465,3,59))
     Define_Switch_CST(X3E,Label_Pred_Name(X696E6C696E655F707265646963617465,3,61))
     Define_Switch_CST(X3E3D,Label_Pred_Name(X696E6C696E655F707265646963617465,3,63))
     Define_Switch_CST(X675F61737369676E,Label_Pred_Name(X696E6C696E655F707265646963617465,3,65))
     Define_Switch_CST(X675F61737369676E62,Label_Pred_Name(X696E6C696E655F707265646963617465,3,67))
     Define_Switch_CST(X675F6C696E6B,Label_Pred_Name(X696E6C696E655F707265646963617465,3,69))
     Define_Switch_CST(X675F72656164,Label_Pred_Name(X696E6C696E655F707265646963617465,3,71))
     Define_Switch_CST(X675F61727261795F73697A65,Label_Pred_Name(X696E6C696E655F707265646963617465,3,73))

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(wamcc2)



End_Exec_Directives
