/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : wamcc4.c
Main : no_main
****************************************************************************/

#define FAST_MATH
#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "wamcc4.h"
#include "wamcc4.usr"


#define ASCII_PRED "generation_code"
#define PRED       X67656E65726174696F6E5F636F6465
#define ARITY      5

Begin_Public_Pred
      allocate(7)
      get_y_variable(6,0)
      get_y_variable(1,1)
      get_y_variable(5,2)
      get_y_variable(2,3)
      put_constant(X6465627567,2)
      put_x_variable(1,0)
      builtin_2(g_read,2,0)
      put_x_value(4,0)
      put_y_variable(4,2)
      put_y_variable(3,3)
      put_y_variable(0,4)
      call(Pred_Name(X67656E65726174696F6E5F636F64655F2461757831,5),1,7,1,"generation_code_$aux1",5)          /* begin sub 1 */
      put_y_value(6,0)
      put_y_value(5,1)
      put_y_unsafe_value(4,2)
      put_y_unsafe_value(3,3)
      put_y_value(2,4)
      call(Pred_Name(X67656E6572655F74657465,5),1,2,2,"genere_tete",5)          /* begin sub 2 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X67656E6572655F636F727073,2),1,"genere_corps",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "generation_code_$aux1"
#define PRED       X67656E65726174696F6E5F636F64655F2461757831
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      math_load_x_value(1,1)
      put_integer(0,5)
      builtin_2(gt,1,5)
      neck_cut
      get_list(0)
      unify_constant(X6462675F636C61757365)
      unify_x_local_value(3)
      get_list(2)
      unify_constant(X6462675F626F6479)
      unify_x_local_value(4)
      proceed

label(1)
      trust_me_else_fail
      get_x_value(3,0)
      get_x_value(4,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "genere_tete"
#define PRED       X67656E6572655F74657465
#define ARITY      5

Begin_Private_Pred
      switch_on_term(G_label(1),fail,fail,fail,G_label(1))

label(1)
      allocate(4)
      get_structure(X70,4,0)
      unify_void(1)
      unify_x_variable(5)
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(2,1)
      get_y_variable(1,3)
      get_x_value(5,4)
      put_integer(0,1)
      put_y_variable(0,3)
      call(Pred_Name(X67656E5F746574655F6C73745F617267,4),1,4,1,"gen_tete_lst_arg",4)          /* begin sub 1 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_unsafe_value(0,3)
      deallocate
      execute(Pred_Name(X67656E6572655F746574655F2461757832,4),1,"genere_tete_$aux2",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "genere_tete_$aux2"
#define PRED       X67656E6572655F746574655F2461757832
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      math_load_x_value(1,1)
      put_integer(1,4)
      builtin_2(gt,1,4)
      neck_cut
      get_list(2)
      unify_x_variable(1)
      unify_x_local_value(3)
      get_structure(X616C6C6F63617465,1,1)
      unify_x_local_value(0)
      proceed

label(1)
      trust_me_else_fail
      get_x_value(3,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_tete_lst_arg"
#define PRED       X67656E5F746574655F6C73745F617267
#define ARITY      4

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_x_value(2,3)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(5)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_y_variable(3,1)
      get_y_variable(1,2)
      get_y_bc_reg(4)
      put_y_value(3,1)
      put_y_variable(0,2)
      call(Pred_Name(X67656E5F756E69665F617267,4),1,5,1,"gen_unif_arg",4)          /* begin sub 1 */
      cut_y(4)
      math_load_y_value(3,0)
      function_1(inc,1,0)
      put_y_value(2,0)
      put_y_value(1,2)
      put_y_unsafe_value(0,3)
      deallocate
      execute(Pred_Name(X67656E5F746574655F6C73745F617267,4),1,"gen_tete_lst_arg",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "genere_corps"
#define PRED       X67656E6572655F636F727073
#define ARITY      2

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(3),fail,G_label(1),fail)

label(1)
      try(5,1)          /* begin sub 1 */
      retry(7,2)          /* begin sub 2 */
      retry(9,3)          /* begin sub 3 */
      trust(11)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      get_list(1)
      unify_constant(X70726F63656564)
      unify_nil
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_x_variable(0)
      unify_void(1)
      get_structure(X70,4,0)
      unify_void(1)
      unify_x_variable(0)
      unify_nil
      unify_void(1)
      get_structure(X2F,2,0)
      unify_constant(X6661696C)
      unify_integer(0)
      get_list(1)
      unify_constant(X6661696C)
      unify_nil
      proceed

label(6)
      retry_me_else(8)

label(7)
      get_list(0)
      unify_x_variable(0)
      unify_void(1)
      get_structure(X70,4,0)
      unify_void(1)
      unify_x_variable(0)
      unify_nil
      unify_void(1)
      get_structure(X2F,2,0)
      unify_constant(X66616C7365)
      unify_integer(0)
      get_list(1)
      unify_constant(X6661696C)
      unify_nil
      proceed

label(8)
      retry_me_else(10)

label(9)
      allocate(7)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(1)
      get_structure(X70,4,0)
      unify_y_variable(2)
      unify_x_variable(0)
      unify_y_variable(4)
      unify_void(1)
      get_structure(X2F,2,0)
      unify_y_variable(6)
      unify_y_variable(5)
      get_y_variable(3,1)
      put_y_value(6,0)
      put_y_value(5,1)
      call(Pred_Name(X696E6C696E655F707265646963617465,2),0,7,4,"inline_predicate",2)          /* begin sub 4 */
      put_y_value(6,0)
      put_y_value(5,1)
      put_y_value(2,2)
      put_y_value(4,3)
      put_y_variable(0,4)
      put_y_value(3,5)
      call(Pred_Name(X67656E5F696E6C696E655F70726564,6),1,3,5,"gen_inline_pred",6)          /* begin sub 5 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_unsafe_value(0,2)
      deallocate
      execute(Pred_Name(X67656E6572655F636F7270735F2461757833,3),1,"genere_corps_$aux3",3)

label(10)
      trust_me_else_fail

label(11)
      allocate(5)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(1)
      get_structure(X70,4,0)
      unify_y_variable(4)
      unify_y_variable(3)
      unify_x_variable(0)
      unify_y_variable(2)
      get_x_variable(4,1)
      put_integer(0,1)
      put_y_value(4,2)
      put_y_variable(0,3)
      call(Pred_Name(X67656E5F636F7270735F6C73745F617267,5),1,5,6,"gen_corps_lst_arg",5)          /* begin sub 6 */
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_value(1,3)
      put_y_unsafe_value(0,4)
      deallocate
      execute(Pred_Name(X67656E6572655F636F7270735F2461757835,5),1,"genere_corps_$aux5",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "genere_corps_$aux3"
#define PRED       X67656E6572655F636F7270735F2461757833
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      get_nil(1)
      neck_cut
      put_x_value(2,1)
      execute(Pred_Name(X67656E6572655F636F7270735F2461757834,2),1,"genere_corps_$aux4",2)

label(1)
      trust_me_else_fail
      put_x_value(1,0)
      put_x_value(2,1)
      execute(Pred_Name(X67656E6572655F636F727073,2),1,"genere_corps",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "genere_corps_$aux4"
#define PRED       X67656E6572655F636F7270735F2461757834
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      math_load_x_value(0,0)
      put_integer(1,2)
      builtin_2(gt,0,2)
      neck_cut
      get_list(1)
      unify_constant(X6465616C6C6F63617465)
      unify_x_variable(0)
      get_list(0)
      unify_constant(X70726F63656564)
      unify_nil
      proceed

label(1)
      trust_me_else_fail
      get_list(1)
      unify_constant(X70726F63656564)
      unify_nil
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "genere_corps_$aux5"
#define PRED       X67656E6572655F636F7270735F2461757835
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      get_nil(3)
      neck_cut
      put_x_value(4,2)
      execute(Pred_Name(X67656E6572655F636F7270735F2461757836,3),1,"genere_corps_$aux6",3)

label(1)
      trust_me_else_fail
      get_x_variable(0,1)
      get_list(4)
      unify_x_variable(4)
      unify_x_variable(1)
      get_structure(X63616C6C,2,4)
      unify_x_local_value(0)
      unify_x_local_value(2)
      put_x_value(3,0)
      execute(Pred_Name(X67656E6572655F636F727073,2),1,"genere_corps",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "genere_corps_$aux6"
#define PRED       X67656E6572655F636F7270735F2461757836
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      math_load_x_value(0,0)
      put_integer(1,3)
      builtin_2(gt,0,3)
      neck_cut
      get_list(2)
      unify_constant(X6465616C6C6F63617465)
      unify_x_variable(0)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      get_structure(X65786563757465,1,0)
      unify_x_local_value(1)
      proceed

label(1)
      trust_me_else_fail
      get_list(2)
      unify_x_variable(0)
      unify_nil
      get_structure(X65786563757465,1,0)
      unify_x_local_value(1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_corps_lst_arg"
#define PRED       X67656E5F636F7270735F6C73745F617267
#define ARITY      5

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_x_value(3,4)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(6)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(5,1)
      get_y_variable(2,2)
      get_y_variable(1,3)
      get_y_bc_reg(4)
      put_y_value(5,1)
      put_y_value(2,2)
      put_y_variable(0,3)
      call(Pred_Name(X67656E5F6C6F61645F617267,5),1,6,1,"gen_load_arg",5)          /* begin sub 1 */
      math_load_y_value(5,0)
      function_1(inc,1,0)
      cut_y(4)
      put_y_value(3,0)
      put_y_value(2,2)
      put_y_value(1,3)
      put_y_unsafe_value(0,4)
      deallocate
      execute(Pred_Name(X67656E5F636F7270735F6C73745F617267,5),1,"gen_corps_lst_arg",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_unif_arg"
#define PRED       X67656E5F756E69665F617267
#define ARITY      4

Begin_Private_Pred
      try_me_else(13)
      switch_on_term(G_label(3),G_label(12),fail,fail,G_label(1))

label(1)
      switch_on_structure(1,"[(var/3,2),(cst/1,8),(int/1,10)]")

label(2)
      try(4,1)          /* begin sub 1 */
      trust(6)

label(3)
      try_me_else(5)

label(4)
      get_structure(X766172,3,0)
      unify_x_variable(0)
      unify_x_variable(5)
      unify_void(1)
      get_structure(X696776,5,0)
      unify_x_variable(0)
      unify_void(4)
      get_structure(X78,1,0)
      unify_x_variable(0)
      get_x_variable(4,1)
      get_list(3)
      unify_x_variable(3)
      unify_x_local_value(2)
      put_x_value(5,1)
      put_x_value(4,2)
      execute(Pred_Name(X67656E5F756E69665F6172675F2461757837,4),1,"gen_unif_arg_$aux7",4)

label(5)
      retry_me_else(7)

label(6)
      get_structure(X766172,3,0)
      unify_x_variable(0)
      unify_x_variable(5)
      unify_void(1)
      get_structure(X696776,5,0)
      unify_x_variable(0)
      unify_void(4)
      get_structure(X79,1,0)
      unify_x_variable(0)
      get_x_variable(4,1)
      get_list(3)
      unify_x_variable(3)
      unify_x_local_value(2)
      put_x_value(5,1)
      put_x_value(4,2)
      execute(Pred_Name(X67656E5F756E69665F6172675F2461757838,4),1,"gen_unif_arg_$aux8",4)

label(7)
      retry_me_else(9)

label(8)
      get_structure(X637374,1,0)
      unify_x_variable(0)
      get_list(3)
      unify_x_variable(3)
      unify_x_local_value(2)
      get_structure(X6765745F636F6E7374616E74,2,3)
      unify_x_value(0)
      unify_x_local_value(1)
      proceed

label(9)
      retry_me_else(11)

label(10)
      get_structure(X696E74,1,0)
      unify_x_variable(0)
      get_list(3)
      unify_x_variable(3)
      unify_x_local_value(2)
      get_structure(X6765745F696E7465676572,2,3)
      unify_x_value(0)
      unify_x_local_value(1)
      proceed

label(11)
      trust_me_else_fail

label(12)
      get_constant(X6E696C,0)
      get_list(3)
      unify_x_variable(0)
      unify_x_local_value(2)
      get_structure(X6765745F6E696C,1,0)
      unify_x_local_value(1)
      proceed

label(13)
      trust_me_else_fail
      put_structure(X2F,2,4)
      unify_x_local_value(0)
      unify_x_local_value(1)
      put_list(0)
      unify_x_value(4)
      unify_nil
      put_constant(X756E6966,1)
      execute(Pred_Name(X67656E5F6C73745F73747263,4),1,"gen_lst_strc",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_unif_arg_$aux7"
#define PRED       X67656E5F756E69665F6172675F2461757837
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      put_constant(X74,4)
      builtin_2(term_eq,1,4)
      neck_cut
      get_structure(X6765745F785F7661726961626C65,2,3)
      unify_x_local_value(0)
      unify_x_local_value(2)
      proceed

label(1)
      trust_me_else_fail
      get_structure(X6765745F785F76616C7565,2,3)
      unify_x_local_value(0)
      unify_x_local_value(2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_unif_arg_$aux8"
#define PRED       X67656E5F756E69665F6172675F2461757838
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      put_constant(X74,4)
      builtin_2(term_eq,1,4)
      neck_cut
      get_structure(X6765745F795F7661726961626C65,2,3)
      unify_x_local_value(0)
      unify_x_local_value(2)
      proceed

label(1)
      trust_me_else_fail
      get_structure(X6765745F795F76616C7565,2,3)
      unify_x_local_value(0)
      unify_x_local_value(2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_load_arg"
#define PRED       X67656E5F6C6F61645F617267
#define ARITY      5

Begin_Private_Pred
      try_me_else(13)
      switch_on_term(G_label(3),G_label(12),fail,fail,G_label(1))

label(1)
      switch_on_structure(1,"[(var/3,2),(cst/1,8),(int/1,10)]")

label(2)
      try(4,1)          /* begin sub 1 */
      trust(6)

label(3)
      try_me_else(5)

label(4)
      get_structure(X766172,3,0)
      unify_x_variable(0)
      unify_x_variable(6)
      unify_void(1)
      get_structure(X696776,5,0)
      unify_x_variable(0)
      unify_void(4)
      get_structure(X78,1,0)
      unify_x_variable(0)
      get_x_variable(5,1)
      get_x_variable(1,3)
      get_list(4)
      unify_x_variable(3)
      unify_x_local_value(1)
      put_x_value(6,1)
      put_x_value(5,2)
      execute(Pred_Name(X67656E5F6C6F61645F6172675F2461757839,4),1,"gen_load_arg_$aux9",4)

label(5)
      retry_me_else(7)

label(6)
      get_structure(X766172,3,0)
      unify_x_variable(0)
      unify_x_variable(8)
      unify_void(1)
      get_structure(X696776,5,0)
      unify_x_variable(0)
      unify_void(1)
      unify_x_variable(10)
      unify_void(1)
      unify_x_variable(9)
      get_structure(X79,1,0)
      unify_x_variable(0)
      get_x_variable(7,1)
      get_x_variable(5,2)
      get_list(4)
      unify_x_variable(6)
      unify_x_local_value(3)
      put_x_value(10,1)
      put_x_value(9,2)
      put_x_value(8,3)
      put_x_value(7,4)
      execute(Pred_Name(X67656E5F6C6F61645F6172675F246175783130,7),1,"gen_load_arg_$aux10",7)

label(7)
      retry_me_else(9)

label(8)
      get_structure(X637374,1,0)
      unify_x_variable(0)
      get_list(4)
      unify_x_variable(2)
      unify_x_local_value(3)
      get_structure(X7075745F636F6E7374616E74,2,2)
      unify_x_value(0)
      unify_x_local_value(1)
      proceed

label(9)
      retry_me_else(11)

label(10)
      get_structure(X696E74,1,0)
      unify_x_variable(0)
      get_list(4)
      unify_x_variable(2)
      unify_x_local_value(3)
      get_structure(X7075745F696E7465676572,2,2)
      unify_x_value(0)
      unify_x_local_value(1)
      proceed

label(11)
      trust_me_else_fail

label(12)
      get_constant(X6E696C,0)
      get_list(4)
      unify_x_variable(0)
      unify_x_local_value(3)
      get_structure(X7075745F6E696C,1,0)
      unify_x_local_value(1)
      proceed

label(13)
      trust_me_else_fail
      put_structure(X2F,2,2)
      unify_x_local_value(0)
      unify_x_local_value(1)
      put_list(0)
      unify_x_value(2)
      unify_nil
      put_constant(X6C6F6164,1)
      put_x_value(3,2)
      put_x_value(4,3)
      execute(Pred_Name(X67656E5F6C73745F73747263,4),1,"gen_lst_strc",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_load_arg_$aux9"
#define PRED       X67656E5F6C6F61645F6172675F2461757839
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      put_constant(X74,4)
      builtin_2(term_eq,1,4)
      neck_cut
      get_structure(X7075745F785F7661726961626C65,2,3)
      unify_x_local_value(0)
      unify_x_local_value(2)
      proceed

label(1)
      trust_me_else_fail
      get_structure(X7075745F785F76616C7565,2,3)
      unify_x_local_value(0)
      unify_x_local_value(2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_load_arg_$aux10"
#define PRED       X67656E5F6C6F61645F6172675F246175783130
#define ARITY      7

Begin_Private_Pred
      try_me_else(1)
      put_constant(X74,1)
      builtin_2(term_eq,3,1)
      neck_cut
      get_structure(X7075745F795F7661726961626C65,2,6)
      unify_x_local_value(0)
      unify_x_local_value(4)
      proceed

label(1)
      retry_me_else(2)
      put_constant(X74,3)
      builtin_2(term_eq,2,3)
      builtin_2(term_eq,5,1)
      neck_cut
      get_structure(X7075745F795F756E736166655F76616C7565,2,6)
      unify_x_local_value(0)
      unify_x_local_value(4)
      proceed

label(2)
      trust_me_else_fail
      get_structure(X7075745F795F76616C7565,2,6)
      unify_x_local_value(0)
      unify_x_local_value(4)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_lst_strc"
#define PRED       X67656E5F6C73745F73747263
#define ARITY      4

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_x_value(2,3)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(10)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(8)
      get_structure(X2F,2,0)
      unify_x_variable(0)
      unify_x_variable(4)
      get_y_variable(6,1)
      get_y_variable(7,2)
      get_y_variable(5,3)
      put_x_value(4,1)
      put_y_value(6,2)
      put_y_variable(4,3)
      put_y_variable(3,4)
      put_y_variable(9,5)
      call(Pred_Name(X67656E5F73747263,6),1,10,1,"gen_strc",6)          /* begin sub 1 */
      put_y_unsafe_value(9,0)
      put_y_value(6,1)
      put_y_variable(2,2)
      put_y_variable(1,3)
      call(Pred_Name(X67656E5F6C73745F73747263,4),1,9,2,"gen_lst_strc",4)          /* begin sub 2 */
      put_y_value(8,0)
      put_y_value(6,1)
      put_y_value(7,2)
      put_y_variable(0,3)
      call(Pred_Name(X67656E5F6C73745F73747263,4),1,7,3,"gen_lst_strc",4)          /* begin sub 3 */
      put_y_value(6,0)
      put_y_value(5,1)
      put_y_unsafe_value(4,2)
      put_y_unsafe_value(3,3)
      put_y_unsafe_value(2,4)
      put_y_unsafe_value(1,5)
      put_y_unsafe_value(0,6)
      deallocate
      execute(Pred_Name(X67656E5F6C73745F737472635F246175783131,7),1,"gen_lst_strc_$aux11",7)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_lst_strc_$aux11"
#define PRED       X67656E5F6C73745F737472635F246175783131
#define ARITY      7

Begin_Private_Pred
      try_me_else(1)
      put_constant(X756E6966,7)
      builtin_2(term_eq,0,7)
      neck_cut
      get_x_value(3,1)
      get_x_value(5,2)
      get_x_value(6,4)
      proceed

label(1)
      trust_me_else_fail
      get_x_value(5,1)
      get_x_value(3,4)
      get_x_value(6,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_strc"
#define PRED       X67656E5F73747263
#define ARITY      6

Begin_Private_Pred
      switch_on_term(G_label(2),fail,fail,fail,G_label(1))

label(1)
      switch_on_structure(1,"[(lst/2,3),(stc/2,5)]")

label(2)
      try_me_else(4)

label(3)
      allocate(6)
      get_structure(X6C7374,2,0)
      unify_y_variable(5)
      unify_y_variable(4)
      get_y_variable(3,2)
      get_y_variable(2,3)
      get_list(4)
      unify_x_variable(2)
      unify_y_variable(1)
      get_y_variable(0,5)
      put_x_value(1,0)
      put_y_value(3,1)
      call(Pred_Name(X67656E5F737472635F246175783132,3),1,6,1,"gen_strc_$aux12",3)          /* begin sub 1 */
      put_list(1)
      unify_y_value(4)
      unify_nil
      put_list(0)
      unify_y_value(5)
      unify_x_value(1)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_value(1,3)
      put_y_value(0,4)
      deallocate
      execute(Pred_Name(X67656E5F756E6966795F6C73745F617267,5),1,"gen_unify_lst_arg",5)

label(4)
      trust_me_else_fail

label(5)
      allocate(5)
      get_structure(X737463,2,0)
      unify_x_variable(0)
      unify_y_variable(4)
      get_y_variable(3,2)
      get_y_variable(2,3)
      get_list(4)
      unify_x_variable(3)
      unify_y_variable(1)
      get_y_variable(0,5)
      put_y_value(3,2)
      call(Pred_Name(X67656E5F737472635F246175783133,4),1,5,2,"gen_strc_$aux13",4)          /* begin sub 2 */
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_value(1,3)
      put_y_value(0,4)
      deallocate
      execute(Pred_Name(X67656E5F756E6966795F6C73745F617267,5),1,"gen_unify_lst_arg",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_strc_$aux12"
#define PRED       X67656E5F737472635F246175783132
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      put_constant(X756E6966,3)
      builtin_2(term_eq,1,3)
      neck_cut
      get_structure(X6765745F6C697374,1,2)
      unify_x_local_value(0)
      proceed

label(1)
      trust_me_else_fail
      get_structure(X7075745F6C697374,1,2)
      unify_x_local_value(0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_strc_$aux13"
#define PRED       X67656E5F737472635F246175783133
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      put_constant(X756E6966,4)
      builtin_2(term_eq,2,4)
      neck_cut
      get_structure(X6765745F737472756374757265,2,3)
      unify_x_local_value(0)
      unify_x_local_value(1)
      proceed

label(1)
      trust_me_else_fail
      get_structure(X7075745F737472756374757265,2,3)
      unify_x_local_value(0)
      unify_x_local_value(1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_unify_lst_arg"
#define PRED       X67656E5F756E6966795F6C73745F617267
#define ARITY      5

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_x_value(2,3)
      get_nil(4)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(9)
      get_list(0)
      unify_y_variable(8)
      unify_y_variable(7)
      get_y_variable(6,1)
      get_y_variable(5,2)
      get_y_variable(4,3)
      get_y_variable(3,4)
      get_y_bc_reg(0)
      put_list(0)
      unify_y_value(8)
      unify_y_value(7)
      put_integer(0,1)
      put_y_variable(2,2)
      put_y_variable(1,3)
      call(Pred_Name(X67656E5F636F6D7074655F766F6964,4),1,9,1,"gen_compte_void",4)          /* begin sub 1 */
      put_y_value(8,0)
      put_y_value(7,1)
      put_y_value(6,2)
      put_y_value(5,3)
      put_y_value(4,4)
      put_y_value(3,5)
      put_y_unsafe_value(2,6)
      put_y_unsafe_value(1,7)
      call(Pred_Name(X67656E5F756E6966795F6C73745F6172675F246175783134,8),1,1,2,"gen_unify_lst_arg_$aux14",8)          /* begin sub 2 */
      cut_y(0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_unify_lst_arg_$aux14"
#define PRED       X67656E5F756E6966795F6C73745F6172675F246175783134
#define ARITY      8

Begin_Private_Pred
      try_me_else(1)
      allocate(5)
      get_y_variable(4,1)
      get_y_variable(3,2)
      get_y_variable(2,3)
      get_integer(0,6)
      neck_cut
      put_y_value(3,1)
      put_y_variable(1,2)
      put_x_value(4,3)
      put_y_variable(0,4)
      call(Pred_Name(X67656E5F756E6966795F617267,6),1,5,1,"gen_unify_arg",6)          /* begin sub 1 */
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_unsafe_value(1,3)
      put_y_unsafe_value(0,4)
      deallocate
      execute(Pred_Name(X67656E5F756E6966795F6C73745F617267,5),1,"gen_unify_lst_arg",5)

label(1)
      trust_me_else_fail
      get_x_variable(1,2)
      get_x_variable(2,3)
      get_list(4)
      unify_x_variable(0)
      unify_x_variable(3)
      get_structure(X756E6966795F766F6964,1,0)
      unify_x_local_value(6)
      put_x_value(7,0)
      put_x_value(5,4)
      execute(Pred_Name(X67656E5F756E6966795F6C73745F617267,5),1,"gen_unify_lst_arg",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_compte_void"
#define PRED       X67656E5F636F6D7074655F766F6964
#define ARITY      4

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,fail,G_label(1),fail)

label(1)
      get_list(0)
      unify_x_variable(4)
      unify_x_variable(0)
      get_structure(X766172,3,4)
      unify_void(1)
      unify_constant(X74)
      unify_constant(X74)
      math_load_x_value(1,1)
      function_1(inc,1,1)
      execute(Pred_Name(X67656E5F636F6D7074655F766F6964,4),1,"gen_compte_void",4)

label(2)
      trust_me_else_fail
      get_x_value(1,2)
      get_x_value(0,3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_unify_arg"
#define PRED       X67656E5F756E6966795F617267
#define ARITY      6

Begin_Private_Pred
      try_me_else(13)
      switch_on_term(G_label(3),G_label(12),fail,fail,G_label(1))

label(1)
      switch_on_structure(1,"[(var/3,2),(cst/1,8),(int/1,10)]")

label(2)
      try(4,1)          /* begin sub 1 */
      trust(6)

label(3)
      try_me_else(5)

label(4)
      get_structure(X766172,3,0)
      unify_x_variable(0)
      unify_x_variable(7)
      unify_void(1)
      get_structure(X696776,5,0)
      unify_x_variable(0)
      unify_x_variable(9)
      unify_void(1)
      unify_x_variable(8)
      unify_void(1)
      get_structure(X78,1,0)
      unify_x_variable(0)
      get_list(3)
      unify_x_variable(6)
      unify_x_local_value(2)
      get_x_value(4,5)
      put_x_value(9,1)
      put_x_value(8,2)
      put_x_value(7,3)
      put_x_value(6,4)
      execute(Pred_Name(X67656E5F756E6966795F6172675F246175783135,5),1,"gen_unify_arg_$aux15",5)

label(5)
      retry_me_else(7)

label(6)
      get_structure(X766172,3,0)
      unify_x_variable(0)
      unify_x_variable(6)
      unify_void(1)
      get_structure(X696776,5,0)
      unify_x_variable(0)
      unify_void(2)
      unify_x_variable(7)
      unify_void(1)
      get_structure(X79,1,0)
      unify_x_variable(0)
      get_list(3)
      unify_x_variable(3)
      unify_x_local_value(2)
      get_x_value(4,5)
      put_x_value(7,1)
      put_x_value(6,2)
      execute(Pred_Name(X67656E5F756E6966795F6172675F246175783136,4),1,"gen_unify_arg_$aux16",4)

label(7)
      retry_me_else(9)

label(8)
      get_structure(X637374,1,0)
      unify_x_variable(0)
      get_list(3)
      unify_x_variable(1)
      unify_x_local_value(2)
      get_structure(X756E6966795F636F6E7374616E74,1,1)
      unify_x_value(0)
      get_x_value(4,5)
      proceed

label(9)
      retry_me_else(11)

label(10)
      get_structure(X696E74,1,0)
      unify_x_variable(0)
      get_list(3)
      unify_x_variable(1)
      unify_x_local_value(2)
      get_structure(X756E6966795F696E7465676572,1,1)
      unify_x_value(0)
      get_x_value(4,5)
      proceed

label(11)
      trust_me_else_fail

label(12)
      get_constant(X6E696C,0)
      get_list(3)
      unify_constant(X756E6966795F6E696C)
      unify_x_local_value(2)
      get_x_value(4,5)
      proceed

label(13)
      trust_me_else_fail
      get_x_variable(6,0)
      get_x_variable(0,1)
      get_list(3)
      unify_x_variable(1)
      unify_x_local_value(2)
      get_list(5)
      unify_x_variable(2)
      unify_x_local_value(4)
      get_structure(X2F,2,2)
      unify_x_local_value(6)
      unify_x_variable(2)
      execute(Pred_Name(X67656E5F756E6966795F6172675F246175783137,3),1,"gen_unify_arg_$aux17",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_unify_arg_$aux15"
#define PRED       X67656E5F756E6966795F6172675F246175783135
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      put_constant(X74,1)
      builtin_2(term_eq,3,1)
      neck_cut
      get_structure(X756E6966795F785F7661726961626C65,1,4)
      unify_x_local_value(0)
      proceed

label(1)
      retry_me_else(2)
      get_integer(0,1)
      put_constant(X66,1)
      builtin_2(term_eq,2,1)
      neck_cut
      get_structure(X756E6966795F785F6C6F63616C5F76616C7565,1,4)
      unify_x_local_value(0)
      proceed

label(2)
      trust_me_else_fail
      get_structure(X756E6966795F785F76616C7565,1,4)
      unify_x_local_value(0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_unify_arg_$aux16"
#define PRED       X67656E5F756E6966795F6172675F246175783136
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      put_constant(X74,1)
      builtin_2(term_eq,2,1)
      neck_cut
      get_structure(X756E6966795F795F7661726961626C65,1,3)
      unify_x_local_value(0)
      proceed

label(1)
      retry_me_else(2)
      put_constant(X66,2)
      builtin_2(term_eq,1,2)
      neck_cut
      get_structure(X756E6966795F795F6C6F63616C5F76616C7565,1,3)
      unify_x_local_value(0)
      proceed

label(2)
      trust_me_else_fail
      get_structure(X756E6966795F795F76616C7565,1,3)
      unify_x_local_value(0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_unify_arg_$aux17"
#define PRED       X67656E5F756E6966795F6172675F246175783137
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      put_constant(X756E6966,3)
      builtin_2(term_eq,0,3)
      neck_cut
      get_structure(X756E6966795F785F7661726961626C65,1,1)
      unify_x_local_value(2)
      proceed

label(1)
      trust_me_else_fail
      get_structure(X756E6966795F785F76616C7565,1,1)
      unify_x_local_value(2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_inline_pred"
#define PRED       X67656E5F696E6C696E655F70726564
#define ARITY      6

Begin_Private_Pred
      try_me_else(14)
      switch_on_term(G_label(2),G_label(1),fail,fail,fail)

label(1)
      switch_on_constant(1,"[($get_bc_reg,3),($cut,5),($dbg_true,7),(pragma_c,9),(calling_module_nb,11),(=,13)]")

label(2)
      try_me_else(4)

label(3)
      allocate(2)
      get_constant(X246765745F62635F726567,0)
      get_integer(1,1)
      get_list(3)
      unify_x_variable(0)
      unify_nil
      get_structure(X766172,3,0)
      unify_x_variable(1)
      unify_x_variable(0)
      unify_void(1)
      get_structure(X696776,5,1)
      unify_y_variable(1)
      unify_void(4)
      get_list(5)
      unify_y_variable(0)
      unify_x_local_value(4)
      call(Pred_Name(X67656E5F696E6C696E655F707265645F246175783138,1),1,2,1,"gen_inline_pred_$aux18",1)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X67656E5F696E6C696E655F707265645F246175783139,2),1,"gen_inline_pred_$aux19",2)

label(4)
      retry_me_else(6)

label(5)
      get_constant(X24637574,0)
      get_integer(1,1)
      get_list(3)
      unify_x_variable(0)
      unify_nil
      get_structure(X766172,3,0)
      unify_x_variable(0)
      unify_void(2)
      get_structure(X696776,5,0)
      unify_x_variable(0)
      unify_void(4)
      get_list(5)
      unify_x_variable(1)
      unify_x_local_value(4)
      execute(Pred_Name(X67656E5F696E6C696E655F707265645F246175783230,2),1,"gen_inline_pred_$aux20",2)

label(6)
      retry_me_else(8)

label(7)
      get_constant(X246462675F74727565,0)
      get_integer(0,1)
      get_x_value(4,5)
      proceed

label(8)
      retry_me_else(10)

label(9)
      get_constant(X707261676D615F63,0)
      get_integer(1,1)
      get_list(3)
      unify_x_variable(0)
      unify_nil
      get_structure(X637374,1,0)
      unify_x_variable(0)
      get_list(5)
      unify_x_variable(1)
      unify_x_local_value(4)
      get_structure(X707261676D615F63,1,1)
      unify_x_value(0)
      proceed

label(10)
      retry_me_else(12)

label(11)
      get_constant(X63616C6C696E675F6D6F64756C655F6E62,0)
      get_integer(1,1)
      get_list(3)
      unify_x_variable(7)
      unify_nil
      put_constant(X3D,0)
      put_integer(2,1)
      put_structure(X696E74,1,3)
      unify_constant(X434D4E)
      put_list(6)
      unify_x_value(3)
      unify_nil
      put_list(3)
      unify_x_value(7)
      unify_x_value(6)
      execute(Pred_Name(X67656E5F696E6C696E655F70726564,6),1,"gen_inline_pred",6)

label(12)
      trust_me_else_fail

label(13)
      get_constant(X3D,0)
      get_integer(2,1)
      get_x_variable(0,2)
      get_list(3)
      unify_x_variable(1)
      unify_x_variable(2)
      get_list(2)
      unify_x_variable(2)
      unify_nil
      put_x_value(4,3)
      put_x_value(5,4)
      execute(Pred_Name(X67656E5F696E6C696E655F707265645F246175783231,5),1,"gen_inline_pred_$aux21",5)

label(14)
      retry_me_else(15)
      allocate(6)
      get_y_variable(2,0)
      get_integer(1,1)
      get_list(3)
      unify_y_variable(5)
      unify_nil
      get_y_variable(0,4)
      get_y_variable(4,5)
      put_y_value(2,0)
      call(Pred_Name(X747970655F746573745F66756E63746F72,1),1,6,2,"type_test_functor",1)          /* begin sub 2 */
      put_y_value(5,0)
      put_y_variable(1,1)
      put_x_variable(2,2)
      put_y_variable(3,3)
      put_y_value(4,4)
      call(Pred_Name(X67656E5F6C6F61645F617267,5),1,4,3,"gen_load_arg",5)          /* begin sub 3 */
      put_y_unsafe_value(3,0)
      get_list(0)
      unify_x_variable(0)
      unify_y_local_value(0)
      get_structure(X6275696C74696E5F31,2,0)
      unify_y_local_value(2)
      unify_y_local_value(1)
      deallocate
      proceed

label(15)
      retry_me_else(16)
      allocate(12)
      get_y_variable(4,0)
      get_integer(3,1)
      get_list(3)
      unify_y_variable(11)
      unify_x_variable(0)
      get_list(0)
      unify_y_variable(9)
      unify_x_variable(0)
      get_list(0)
      unify_y_variable(7)
      unify_nil
      get_y_variable(0,4)
      get_y_variable(10,5)
      put_y_value(4,0)
      call(Pred_Name(X7465726D5F6F70655F66756E63746F72,1),1,12,4,"term_ope_functor",1)          /* begin sub 4 */
      put_y_value(11,0)
      put_y_variable(3,1)
      put_x_variable(2,2)
      put_y_variable(8,3)
      put_y_value(10,4)
      call(Pred_Name(X67656E5F6C6F61645F617267,5),1,10,5,"gen_load_arg",5)          /* begin sub 5 */
      put_y_value(9,0)
      put_y_variable(2,1)
      put_x_variable(2,2)
      put_y_variable(6,3)
      put_y_unsafe_value(8,4)
      call(Pred_Name(X67656E5F6C6F61645F617267,5),1,8,6,"gen_load_arg",5)          /* begin sub 6 */
      put_y_value(7,0)
      put_y_variable(1,1)
      put_x_variable(2,2)
      put_y_variable(5,3)
      put_y_unsafe_value(6,4)
      call(Pred_Name(X67656E5F6C6F61645F617267,5),1,6,7,"gen_load_arg",5)          /* begin sub 7 */
      put_y_unsafe_value(5,0)
      get_list(0)
      unify_x_variable(0)
      unify_y_local_value(0)
      get_structure(X6275696C74696E5F33,4,0)
      unify_y_local_value(4)
      unify_y_local_value(3)
      unify_y_local_value(2)
      unify_y_local_value(1)
      deallocate
      proceed

label(16)
      retry_me_else(17)
      allocate(10)
      get_integer(2,1)
      get_list(3)
      unify_y_variable(9)
      unify_x_variable(1)
      get_list(1)
      unify_y_variable(7)
      unify_nil
      get_y_variable(0,4)
      get_y_variable(8,5)
      get_y_bc_reg(5)
      put_y_variable(3,1)
      call(Pred_Name(X7465726D5F636D705F66756E63746F725F6E616D65,2),1,10,8,"term_cmp_functor_name",2)          /* begin sub 8 */
      put_y_value(9,0)
      put_y_variable(2,1)
      put_x_variable(2,2)
      put_y_variable(6,3)
      put_y_value(8,4)
      call(Pred_Name(X67656E5F6C6F61645F617267,5),1,8,9,"gen_load_arg",5)          /* begin sub 9 */
      put_y_value(7,0)
      put_y_variable(1,1)
      put_x_variable(2,2)
      put_y_variable(4,3)
      put_y_unsafe_value(6,4)
      call(Pred_Name(X67656E5F6C6F61645F617267,5),1,6,10,"gen_load_arg",5)          /* begin sub 10 */
      cut_y(5)
      put_y_unsafe_value(4,0)
      get_list(0)
      unify_x_variable(0)
      unify_y_local_value(0)
      get_structure(X6275696C74696E5F32,3,0)
      unify_y_local_value(3)
      unify_y_local_value(2)
      unify_y_local_value(1)
      deallocate
      proceed

label(17)
      retry_me_else(19)
      switch_on_term(G_label(18),G_label(18),fail,fail,fail)

label(18)
      allocate(5)
      get_constant(X6973,0)
      get_integer(2,1)
      get_list(3)
      unify_y_variable(3)
      unify_x_variable(0)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      get_y_variable(1,4)
      get_y_bc_reg(4)
      put_y_variable(2,1)
      put_y_variable(0,2)
      put_x_value(5,3)
      call(Pred_Name(X696E6C696E655F6C6F61645F6D6174685F65787072,4),1,5,11,"inline_load_math_expr",4)          /* begin sub 11 */
      cut_y(4)
      put_y_value(3,0)
      put_y_unsafe_value(2,1)
      put_y_value(1,2)
      put_y_unsafe_value(0,3)
      deallocate
      execute(Pred_Name(X67656E5F756E69665F617267,4),1,"gen_unif_arg",4)

label(19)
      retry_me_else(20)
      allocate(10)
      get_integer(2,1)
      get_list(3)
      unify_y_variable(9)
      unify_x_variable(1)
      get_list(1)
      unify_y_variable(7)
      unify_nil
      get_y_variable(0,4)
      get_y_variable(8,5)
      get_y_bc_reg(5)
      put_y_variable(3,1)
      call(Pred_Name(X6D6174685F636D705F66756E63746F725F6E616D65,2),1,10,12,"math_cmp_functor_name",2)          /* begin sub 12 */
      put_y_value(9,0)
      put_y_variable(2,1)
      put_y_variable(6,2)
      put_y_value(8,3)
      call(Pred_Name(X696E6C696E655F6C6F61645F6D6174685F65787072,4),1,8,13,"inline_load_math_expr",4)          /* begin sub 13 */
      put_y_value(7,0)
      put_y_variable(1,1)
      put_y_variable(4,2)
      put_y_unsafe_value(6,3)
      call(Pred_Name(X696E6C696E655F6C6F61645F6D6174685F65787072,4),1,6,14,"inline_load_math_expr",4)          /* begin sub 14 */
      cut_y(5)
      put_y_unsafe_value(4,0)
      get_list(0)
      unify_x_variable(0)
      unify_y_local_value(0)
      get_structure(X6275696C74696E5F32,3,0)
      unify_y_local_value(3)
      unify_y_local_value(2)
      unify_y_local_value(1)
      deallocate
      proceed

label(20)
      trust_me_else_fail
      allocate(9)
      get_y_variable(3,0)
      get_integer(2,1)
      get_list(3)
      unify_y_variable(8)
      unify_x_variable(0)
      get_list(0)
      unify_y_variable(6)
      unify_nil
      get_y_variable(0,4)
      get_y_variable(7,5)
      put_y_value(3,0)
      call(Pred_Name(X675F7661725F66756E63746F72,1),1,9,15,"g_var_functor",1)          /* begin sub 15 */
      put_y_value(8,0)
      put_y_variable(2,1)
      put_x_variable(2,2)
      put_y_variable(5,3)
      put_y_value(7,4)
      call(Pred_Name(X67656E5F6C6F61645F617267,5),1,7,16,"gen_load_arg",5)          /* begin sub 16 */
      put_y_value(6,0)
      put_y_variable(1,1)
      put_x_variable(2,2)
      put_y_variable(4,3)
      put_y_unsafe_value(5,4)
      call(Pred_Name(X67656E5F6C6F61645F617267,5),1,5,17,"gen_load_arg",5)          /* begin sub 17 */
      put_y_unsafe_value(4,0)
      get_list(0)
      unify_x_variable(0)
      unify_y_local_value(0)
      get_structure(X6275696C74696E5F32,3,0)
      unify_y_local_value(3)
      unify_y_local_value(2)
      unify_y_local_value(1)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_inline_pred_$aux19"
#define PRED       X67656E5F696E6C696E655F707265645F246175783139
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      get_structure(X78,1,0)
      unify_x_variable(0)
      get_structure(X6765745F785F62635F726567,1,1)
      unify_x_value(0)
      proceed

label(1)
      trust_me_else_fail
      get_structure(X79,1,0)
      unify_x_variable(0)
      get_structure(X6765745F795F62635F726567,1,1)
      unify_x_value(0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_inline_pred_$aux18"
#define PRED       X67656E5F696E6C696E655F707265645F246175783138
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      put_constant(X66,1)
      builtin_2(term_eq,0,1)
      neck_cut
      put_constant(X246765745F62635F7265672075736564207769746820626F756E64207661726961626C652E2E2E,0)
      execute(Pred_Name(X6572726F72,1),0,"error",1)

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_inline_pred_$aux20"
#define PRED       X67656E5F696E6C696E655F707265645F246175783230
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      get_structure(X78,1,0)
      unify_x_variable(0)
      get_structure(X6375745F78,1,1)
      unify_x_value(0)
      proceed

label(1)
      trust_me_else_fail
      get_structure(X79,1,0)
      unify_x_variable(0)
      get_structure(X6375745F79,1,1)
      unify_x_value(0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_inline_pred_$aux21"
#define PRED       X67656E5F696E6C696E655F707265645F246175783231
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      get_x_variable(7,0)
      get_x_variable(6,3)
      get_x_variable(5,4)
      get_structure(X766172,3,1)
      unify_x_variable(1)
      unify_x_variable(0)
      unify_void(1)
      get_structure(X696776,5,1)
      unify_x_variable(1)
      unify_void(4)
      get_structure(X78,1,1)
      unify_x_variable(1)
      neck_cut
      put_x_value(7,3)
      put_x_value(6,4)
      execute(Pred_Name(X696E6C696E655F756E69665F7265675F7465726D65,6),1,"inline_unif_reg_terme",6)

label(1)
      retry_me_else(2)
      get_x_variable(7,0)
      get_x_variable(8,1)
      get_x_variable(6,3)
      get_x_variable(5,4)
      get_structure(X766172,3,2)
      unify_x_variable(1)
      unify_x_variable(0)
      unify_void(1)
      get_structure(X696776,5,1)
      unify_x_variable(1)
      unify_void(4)
      get_structure(X78,1,1)
      unify_x_variable(1)
      neck_cut
      put_x_value(8,2)
      put_x_value(7,3)
      put_x_value(6,4)
      execute(Pred_Name(X696E6C696E655F756E69665F7265675F7465726D65,6),1,"inline_unif_reg_terme",6)

label(2)
      trust_me_else_fail
      allocate(5)
      get_y_variable(2,0)
      get_y_variable(3,2)
      get_y_variable(1,3)
      put_x_value(1,0)
      put_y_variable(4,1)
      put_y_value(2,2)
      put_y_variable(0,3)
      call(Pred_Name(X67656E5F6C6F61645F617267,5),1,5,1,"gen_load_arg",5)          /* begin sub 1 */
      put_x_variable(0,0)
      put_y_unsafe_value(4,1)
      put_y_value(3,2)
      put_y_value(2,3)
      put_y_value(1,4)
      put_y_unsafe_value(0,5)
      deallocate
      execute(Pred_Name(X696E6C696E655F756E69665F7265675F7465726D65,6),1,"inline_unif_reg_terme",6)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "inline_unif_reg_terme"
#define PRED       X696E6C696E655F756E69665F7265675F7465726D65
#define ARITY      6

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),G_label(1),fail,fail,fail)

label(1)
      get_constant(X66,0)
      put_x_value(2,0)
      put_x_value(4,2)
      put_x_value(5,3)
      execute(Pred_Name(X67656E5F756E69665F617267,4),1,"gen_unif_arg",4)

label(2)
      trust_me_else_fail
      put_x_value(2,0)
      put_x_value(3,2)
      put_x_value(4,3)
      put_x_value(5,4)
      execute(Pred_Name(X67656E5F6C6F61645F617267,5),1,"gen_load_arg",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "type_test_functor"
#define PRED       X747970655F746573745F66756E63746F72
#define ARITY      1

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(1),fail,fail,fail)

label(1)
      switch_on_constant(1,"[(var,3),(nonvar,5),(atom,7),(integer,9),(number,11),(atomic,13),(compound,15),(callable,17)]")

label(2)
      try_me_else(4)

label(3)
      get_constant(X766172,0)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_constant(X6E6F6E766172,0)
      proceed

label(6)
      retry_me_else(8)

label(7)
      get_constant(X61746F6D,0)
      proceed

label(8)
      retry_me_else(10)

label(9)
      get_constant(X696E7465676572,0)
      proceed

label(10)
      retry_me_else(12)

label(11)
      get_constant(X6E756D626572,0)
      proceed

label(12)
      retry_me_else(14)

label(13)
      get_constant(X61746F6D6963,0)
      proceed

label(14)
      retry_me_else(16)

label(15)
      get_constant(X636F6D706F756E64,0)
      proceed

label(16)
      trust_me_else_fail

label(17)
      get_constant(X63616C6C61626C65,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "term_ope_functor"
#define PRED       X7465726D5F6F70655F66756E63746F72
#define ARITY      1

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(1),fail,fail,fail)

label(1)
      switch_on_constant(1,"[(arg,3),(functor,5),(compare,7)]")

label(2)
      try_me_else(4)

label(3)
      get_constant(X617267,0)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_constant(X66756E63746F72,0)
      proceed

label(6)
      trust_me_else_fail

label(7)
      get_constant(X636F6D70617265,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "term_cmp_functor_name"
#define PRED       X7465726D5F636D705F66756E63746F725F6E616D65
#define ARITY      2

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(1),fail,fail,fail)

label(1)
      switch_on_constant(1,"[(=..,3),(==,5),(\==,7),(@<,9),(@=<,11),(@>,13),(@>=,15)]")

label(2)
      try_me_else(4)

label(3)
      get_constant(X3D2E2E,0)
      get_constant(X7465726D5F756E6976,1)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_constant(X3D3D,0)
      get_constant(X7465726D5F6571,1)
      proceed

label(6)
      retry_me_else(8)

label(7)
      get_constant(X5C3D3D,0)
      get_constant(X7465726D5F6E6571,1)
      proceed

label(8)
      retry_me_else(10)

label(9)
      get_constant(X403C,0)
      get_constant(X7465726D5F6C74,1)
      proceed

label(10)
      retry_me_else(12)

label(11)
      get_constant(X403D3C,0)
      get_constant(X7465726D5F6C7465,1)
      proceed

label(12)
      retry_me_else(14)

label(13)
      get_constant(X403E,0)
      get_constant(X7465726D5F6774,1)
      proceed

label(14)
      trust_me_else_fail

label(15)
      get_constant(X403E3D,0)
      get_constant(X7465726D5F677465,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "inline_load_math_expr"
#define PRED       X696E6C696E655F6C6F61645F6D6174685F65787072
#define ARITY      4

Begin_Private_Pred
      try_me_else(13)
      switch_on_term(G_label(3),fail,fail,fail,G_label(1))

label(1)
      switch_on_structure(1,"[(var/3,4),(int/1,6),(lst/2,8),(stc/2,2)]")

label(2)
      try(10,1)          /* begin sub 1 */
      trust(12)

label(3)
      try_me_else(5)

label(4)
      get_structure(X766172,3,0)
      unify_x_variable(0)
      unify_x_variable(7)
      unify_void(1)
      get_structure(X696776,5,0)
      unify_x_variable(0)
      unify_void(4)
      get_x_variable(6,1)
      get_x_variable(5,2)
      get_x_variable(4,3)
      put_x_value(7,1)
      put_x_value(6,2)
      put_x_value(5,3)
      execute(Pred_Name(X696E6C696E655F6C6F61645F6D6174685F657870725F246175783232,5),1,"inline_load_math_expr_$aux22",5)

label(5)
      retry_me_else(7)

label(6)
      get_structure(X696E74,1,0)
      unify_x_variable(0)
      get_list(3)
      unify_x_variable(3)
      unify_x_local_value(2)
      get_structure(X7075745F696E7465676572,2,3)
      unify_x_value(0)
      unify_x_local_value(1)
      proceed

label(7)
      retry_me_else(9)

label(8)
      get_structure(X6C7374,2,0)
      unify_x_variable(0)
      unify_constant(X6E696C)
      execute(Pred_Name(X696E6C696E655F6C6F61645F6D6174685F65787072,4),1,"inline_load_math_expr",4)

label(9)
      retry_me_else(11)

label(10)
      allocate(7)
      get_structure(X737463,2,0)
      unify_x_variable(0)
      unify_x_variable(4)
      get_structure(X2F,2,0)
      unify_x_variable(0)
      unify_void(1)
      get_list(4)
      unify_y_variable(6)
      unify_nil
      get_y_variable(4,1)
      get_y_variable(3,2)
      get_y_variable(5,3)
      put_y_variable(2,1)
      call(Pred_Name(X696E6C696E655F6C6F61645F6D6174685F657870725F246175783233,2),1,7,2,"inline_load_math_expr_$aux23",2)          /* begin sub 2 */
      put_y_value(6,0)
      put_y_variable(1,1)
      put_y_variable(0,2)
      put_y_value(5,3)
      call(Pred_Name(X696E6C696E655F6C6F61645F6D6174685F65787072,4),1,5,3,"inline_load_math_expr",4)          /* begin sub 3 */
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_unsafe_value(2,2)
      put_y_unsafe_value(1,3)
      put_y_unsafe_value(0,4)
      deallocate
      execute(Pred_Name(X696E6C696E655F6C6F61645F6D6174685F657870725F246175783234,5),1,"inline_load_math_expr_$aux24",5)

label(11)
      trust_me_else_fail

label(12)
      allocate(8)
      get_structure(X737463,2,0)
      unify_x_variable(0)
      unify_x_variable(4)
      get_structure(X2F,2,0)
      unify_x_variable(0)
      unify_void(1)
      get_list(4)
      unify_y_variable(7)
      unify_x_variable(4)
      get_list(4)
      unify_y_variable(5)
      unify_nil
      get_y_variable(4,1)
      get_y_variable(3,2)
      get_y_variable(6,3)
      put_y_variable(2,1)
      call(Pred_Name(X6D6174685F6578705F66756E63746F725F6E616D65,2),1,8,4,"math_exp_functor_name",2)          /* begin sub 4 */
      put_y_value(7,0)
      put_y_variable(1,1)
      put_y_variable(0,2)
      put_y_value(6,3)
      call(Pred_Name(X696E6C696E655F6C6F61645F6D6174685F65787072,4),1,6,5,"inline_load_math_expr",4)          /* begin sub 5 */
      put_y_value(5,0)
      put_y_value(4,1)
      put_y_value(3,2)
      put_y_unsafe_value(2,3)
      put_y_unsafe_value(1,4)
      put_y_unsafe_value(0,5)
      deallocate
      execute(Pred_Name(X696E6C696E655F6C6F61645F6D6174685F657870725F246175783235,6),1,"inline_load_math_expr_$aux25",6)

label(13)
      trust_me_else_fail
      put_constant(X496C6C6567616C2061726974686D657469632065787072657373696F6E,0)
      execute(Pred_Name(X6572726F72,1),0,"error",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "inline_load_math_expr_$aux22"
#define PRED       X696E6C696E655F6C6F61645F6D6174685F657870725F246175783232
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      put_constant(X74,0)
      builtin_2(term_eq,1,0)
      neck_cut
      put_constant(X496C6C6567616C2061726974686D657469632065787072657373696F6E,0)
      execute(Pred_Name(X6572726F72,1),0,"error",1)

label(1)
      retry_me_else(2)
      get_structure(X78,1,0)
      unify_x_variable(0)
      get_list(4)
      unify_x_variable(1)
      unify_x_local_value(3)
      get_structure(X6D6174685F6C6F61645F785F76616C7565,2,1)
      unify_x_value(0)
      unify_x_local_value(2)
      proceed

label(2)
      trust_me_else_fail
      get_structure(X79,1,0)
      unify_x_variable(0)
      get_list(4)
      unify_x_variable(1)
      unify_x_local_value(3)
      get_structure(X6D6174685F6C6F61645F795F76616C7565,2,1)
      unify_x_value(0)
      unify_x_local_value(2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "inline_load_math_expr_$aux24"
#define PRED       X696E6C696E655F6C6F61645F6D6174685F657870725F246175783234
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      put_constant(X616464,5)
      builtin_2(term_eq,2,5)
      neck_cut
      get_x_value(3,0)
      get_x_value(1,4)
      proceed

label(1)
      trust_me_else_fail
      get_list(4)
      unify_x_variable(4)
      unify_x_local_value(1)
      get_structure(X66756E6374696F6E5F31,3,4)
      unify_x_local_value(2)
      unify_x_local_value(0)
      unify_x_local_value(3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "inline_load_math_expr_$aux23"
#define PRED       X696E6C696E655F6C6F61645F6D6174685F657870725F246175783233
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      put_constant(X2D,2)
      builtin_2(term_eq,0,2)
      neck_cut
      get_constant(X6E6567,1)
      proceed

label(1)
      trust_me_else_fail
      execute(Pred_Name(X6D6174685F6578705F66756E63746F725F6E616D65,2),1,"math_exp_functor_name",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "inline_load_math_expr_$aux25"
#define PRED       X696E6C696E655F6C6F61645F6D6174685F657870725F246175783235
#define ARITY      6

Begin_Private_Pred
      try_me_else(1)
      allocate(6)
      get_y_variable(2,1)
      get_y_variable(0,2)
      get_y_variable(1,4)
      get_y_variable(4,5)
      get_y_bc_reg(5)
      get_structure(X696E74,1,0)
      unify_integer(1)
      put_x_value(3,0)
      put_y_variable(3,1)
      call(Pred_Name(X696E6C696E655F6C6F61645F6D6174685F657870725F246175783236,2),1,6,1,"inline_load_math_expr_$aux26",2)          /* begin sub 1 */
      cut_y(5)
      put_y_value(4,0)
      get_list(0)
      unify_x_variable(0)
      unify_y_local_value(0)
      get_structure(X66756E6374696F6E5F31,3,0)
      unify_y_local_value(3)
      unify_y_local_value(2)
      unify_y_local_value(1)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      allocate(6)
      get_y_variable(3,1)
      get_y_variable(0,2)
      get_y_variable(4,3)
      get_y_variable(2,4)
      put_y_variable(1,1)
      put_y_variable(5,2)
      put_x_value(5,3)
      call(Pred_Name(X696E6C696E655F6C6F61645F6D6174685F65787072,4),1,6,2,"inline_load_math_expr",4)          /* begin sub 2 */
      put_y_unsafe_value(5,0)
      get_list(0)
      unify_x_variable(0)
      unify_y_local_value(0)
      get_structure(X66756E6374696F6E5F32,4,0)
      unify_y_local_value(4)
      unify_y_local_value(3)
      unify_y_local_value(2)
      unify_y_local_value(1)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "inline_load_math_expr_$aux26"
#define PRED       X696E6C696E655F6C6F61645F6D6174685F657870725F246175783236
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      put_constant(X616464,2)
      builtin_2(term_eq,0,2)
      get_constant(X696E63,1)
      proceed

label(1)
      trust_me_else_fail
      put_constant(X737562,2)
      builtin_2(term_eq,0,2)
      get_constant(X646563,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "math_exp_functor_name"
#define PRED       X6D6174685F6578705F66756E63746F725F6E616D65
#define ARITY      2

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(1),fail,fail,fail)

label(1)
      switch_on_constant(1,"[(+,3),(-,5),(*,7),(//,9),(mod,11),(/\,13),(\/,15),(^,17),(\,19),(<<,21),(>>,23)]")

label(2)
      try_me_else(4)

label(3)
      get_constant(X2B,0)
      get_constant(X616464,1)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_constant(X2D,0)
      get_constant(X737562,1)
      proceed

label(6)
      retry_me_else(8)

label(7)
      get_constant(X2A,0)
      get_constant(X6D756C,1)
      proceed

label(8)
      retry_me_else(10)

label(9)
      get_constant(X2F2F,0)
      get_constant(X646976,1)
      proceed

label(10)
      retry_me_else(12)

label(11)
      get_constant(X6D6F64,0)
      get_constant(X6D6F64,1)
      proceed

label(12)
      retry_me_else(14)

label(13)
      get_constant(X2F5C,0)
      get_constant(X616E64,1)
      proceed

label(14)
      retry_me_else(16)

label(15)
      get_constant(X5C2F,0)
      get_constant(X6F72,1)
      proceed

label(16)
      retry_me_else(18)

label(17)
      get_constant(X5E,0)
      get_constant(X786F72,1)
      proceed

label(18)
      retry_me_else(20)

label(19)
      get_constant(X5C,0)
      get_constant(X6E6F74,1)
      proceed

label(20)
      retry_me_else(22)

label(21)
      get_constant(X3C3C,0)
      get_constant(X73686C,1)
      proceed

label(22)
      trust_me_else_fail

label(23)
      get_constant(X3E3E,0)
      get_constant(X736872,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "math_cmp_functor_name"
#define PRED       X6D6174685F636D705F66756E63746F725F6E616D65
#define ARITY      2

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(1),fail,fail,fail)

label(1)
      switch_on_constant(1,"[(=:=,3),(=\=,5),(<,7),(=<,9),(>,11),(>=,13)]")

label(2)
      try_me_else(4)

label(3)
      get_constant(X3D3A3D,0)
      get_constant(X6571,1)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_constant(X3D5C3D,0)
      get_constant(X6E6571,1)
      proceed

label(6)
      retry_me_else(8)

label(7)
      get_constant(X3C,0)
      get_constant(X6C74,1)
      proceed

label(8)
      retry_me_else(10)

label(9)
      get_constant(X3D3C,0)
      get_constant(X6C7465,1)
      proceed

label(10)
      retry_me_else(12)

label(11)
      get_constant(X3E,0)
      get_constant(X6774,1)
      proceed

label(12)
      trust_me_else_fail

label(13)
      get_constant(X3E3D,0)
      get_constant(X677465,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "g_var_functor"
#define PRED       X675F7661725F66756E63746F72
#define ARITY      1

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(1),fail,fail,fail)

label(1)
      switch_on_constant(1,"[(g_assign,3),(g_assignb,5),(g_link,7),(g_read,9),(g_array_size,11)]")

label(2)
      try_me_else(4)

label(3)
      get_constant(X675F61737369676E,0)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_constant(X675F61737369676E62,0)
      proceed

label(6)
      retry_me_else(8)

label(7)
      get_constant(X675F6C696E6B,0)
      proceed

label(8)
      retry_me_else(10)

label(9)
      get_constant(X675F72656164,0)
      proceed

label(10)
      trust_me_else_fail

label(11)
      get_constant(X675F61727261795F73697A65,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(wamcc4)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X67656E65726174696F6E5F636F6465,"generation_code")
 Define_Atom(X6465627567,"debug")
 Define_Atom(X67656E65726174696F6E5F636F64655F2461757831,"generation_code_$aux1")
 Define_Atom(X6462675F636C61757365,"dbg_clause")
 Define_Atom(X6462675F626F6479,"dbg_body")
 Define_Atom(X67656E6572655F74657465,"genere_tete")
 Define_Atom(X70,"p")
 Define_Atom(X67656E6572655F746574655F2461757832,"genere_tete_$aux2")
 Define_Atom(X616C6C6F63617465,"allocate")
 Define_Atom(X67656E5F746574655F6C73745F617267,"gen_tete_lst_arg")
 Define_Atom(X67656E6572655F636F727073,"genere_corps")
 Define_Atom(X70726F63656564,"proceed")
 Define_Atom(X2F,"/")
 Define_Atom(X6661696C,"fail")
 Define_Atom(X66616C7365,"false")
 Define_Atom(X67656E6572655F636F7270735F2461757833,"genere_corps_$aux3")
 Define_Atom(X67656E6572655F636F7270735F2461757834,"genere_corps_$aux4")
 Define_Atom(X6465616C6C6F63617465,"deallocate")
 Define_Atom(X67656E6572655F636F7270735F2461757835,"genere_corps_$aux5")
 Define_Atom(X63616C6C,"call")
 Define_Atom(X67656E6572655F636F7270735F2461757836,"genere_corps_$aux6")
 Define_Atom(X65786563757465,"execute")
 Define_Atom(X67656E5F636F7270735F6C73745F617267,"gen_corps_lst_arg")
 Define_Atom(X67656E5F756E69665F617267,"gen_unif_arg")
 Define_Atom(X766172,"var")
 Define_Atom(X696776,"igv")
 Define_Atom(X78,"x")
 Define_Atom(X79,"y")
 Define_Atom(X637374,"cst")
 Define_Atom(X6765745F636F6E7374616E74,"get_constant")
 Define_Atom(X696E74,"int")
 Define_Atom(X6765745F696E7465676572,"get_integer")
 Define_Atom(X6E696C,"nil")
 Define_Atom(X6765745F6E696C,"get_nil")
 Define_Atom(X756E6966,"unif")
 Define_Atom(X67656E5F756E69665F6172675F2461757837,"gen_unif_arg_$aux7")
 Define_Atom(X74,"t")
 Define_Atom(X6765745F785F7661726961626C65,"get_x_variable")
 Define_Atom(X6765745F785F76616C7565,"get_x_value")
 Define_Atom(X67656E5F756E69665F6172675F2461757838,"gen_unif_arg_$aux8")
 Define_Atom(X6765745F795F7661726961626C65,"get_y_variable")
 Define_Atom(X6765745F795F76616C7565,"get_y_value")
 Define_Atom(X67656E5F6C6F61645F617267,"gen_load_arg")
 Define_Atom(X7075745F636F6E7374616E74,"put_constant")
 Define_Atom(X7075745F696E7465676572,"put_integer")
 Define_Atom(X7075745F6E696C,"put_nil")
 Define_Atom(X6C6F6164,"load")
 Define_Atom(X67656E5F6C6F61645F6172675F2461757839,"gen_load_arg_$aux9")
 Define_Atom(X7075745F785F7661726961626C65,"put_x_variable")
 Define_Atom(X7075745F785F76616C7565,"put_x_value")
 Define_Atom(X67656E5F6C6F61645F6172675F246175783130,"gen_load_arg_$aux10")
 Define_Atom(X7075745F795F7661726961626C65,"put_y_variable")
 Define_Atom(X7075745F795F756E736166655F76616C7565,"put_y_unsafe_value")
 Define_Atom(X7075745F795F76616C7565,"put_y_value")
 Define_Atom(X67656E5F6C73745F73747263,"gen_lst_strc")
 Define_Atom(X67656E5F6C73745F737472635F246175783131,"gen_lst_strc_$aux11")
 Define_Atom(X67656E5F73747263,"gen_strc")
 Define_Atom(X6C7374,"lst")
 Define_Atom(X737463,"stc")
 Define_Atom(X67656E5F737472635F246175783132,"gen_strc_$aux12")
 Define_Atom(X6765745F6C697374,"get_list")
 Define_Atom(X7075745F6C697374,"put_list")
 Define_Atom(X67656E5F737472635F246175783133,"gen_strc_$aux13")
 Define_Atom(X6765745F737472756374757265,"get_structure")
 Define_Atom(X7075745F737472756374757265,"put_structure")
 Define_Atom(X67656E5F756E6966795F6C73745F617267,"gen_unify_lst_arg")
 Define_Atom(X67656E5F756E6966795F6C73745F6172675F246175783134,"gen_unify_lst_arg_$aux14")
 Define_Atom(X756E6966795F766F6964,"unify_void")
 Define_Atom(X67656E5F636F6D7074655F766F6964,"gen_compte_void")
 Define_Atom(X67656E5F756E6966795F617267,"gen_unify_arg")
 Define_Atom(X756E6966795F636F6E7374616E74,"unify_constant")
 Define_Atom(X756E6966795F696E7465676572,"unify_integer")
 Define_Atom(X756E6966795F6E696C,"unify_nil")
 Define_Atom(X67656E5F756E6966795F6172675F246175783135,"gen_unify_arg_$aux15")
 Define_Atom(X756E6966795F785F7661726961626C65,"unify_x_variable")
 Define_Atom(X66,"f")
 Define_Atom(X756E6966795F785F6C6F63616C5F76616C7565,"unify_x_local_value")
 Define_Atom(X756E6966795F785F76616C7565,"unify_x_value")
 Define_Atom(X67656E5F756E6966795F6172675F246175783136,"gen_unify_arg_$aux16")
 Define_Atom(X756E6966795F795F7661726961626C65,"unify_y_variable")
 Define_Atom(X756E6966795F795F6C6F63616C5F76616C7565,"unify_y_local_value")
 Define_Atom(X756E6966795F795F76616C7565,"unify_y_value")
 Define_Atom(X67656E5F756E6966795F6172675F246175783137,"gen_unify_arg_$aux17")
 Define_Atom(X67656E5F696E6C696E655F70726564,"gen_inline_pred")
 Define_Atom(X246765745F62635F726567,"$get_bc_reg")
 Define_Atom(X24637574,"$cut")
 Define_Atom(X246462675F74727565,"$dbg_true")
 Define_Atom(X707261676D615F63,"pragma_c")
 Define_Atom(X63616C6C696E675F6D6F64756C655F6E62,"calling_module_nb")
 Define_Atom(X3D,"=")
 Define_Atom(X434D4E,"CMN")
 Define_Atom(X6275696C74696E5F31,"builtin_1")
 Define_Atom(X6275696C74696E5F33,"builtin_3")
 Define_Atom(X6275696C74696E5F32,"builtin_2")
 Define_Atom(X6973,"is")
 Define_Atom(X67656E5F696E6C696E655F707265645F246175783139,"gen_inline_pred_$aux19")
 Define_Atom(X6765745F785F62635F726567,"get_x_bc_reg")
 Define_Atom(X6765745F795F62635F726567,"get_y_bc_reg")
 Define_Atom(X67656E5F696E6C696E655F707265645F246175783138,"gen_inline_pred_$aux18")
 Define_Atom(X246765745F62635F7265672075736564207769746820626F756E64207661726961626C652E2E2E,"$get_bc_reg used with bound variable...")
 Define_Atom(X67656E5F696E6C696E655F707265645F246175783230,"gen_inline_pred_$aux20")
 Define_Atom(X6375745F78,"cut_x")
 Define_Atom(X6375745F79,"cut_y")
 Define_Atom(X67656E5F696E6C696E655F707265645F246175783231,"gen_inline_pred_$aux21")
 Define_Atom(X696E6C696E655F756E69665F7265675F7465726D65,"inline_unif_reg_terme")
 Define_Atom(X747970655F746573745F66756E63746F72,"type_test_functor")
 Define_Atom(X6E6F6E766172,"nonvar")
 Define_Atom(X61746F6D,"atom")
 Define_Atom(X696E7465676572,"integer")
 Define_Atom(X6E756D626572,"number")
 Define_Atom(X61746F6D6963,"atomic")
 Define_Atom(X636F6D706F756E64,"compound")
 Define_Atom(X63616C6C61626C65,"callable")
 Define_Atom(X7465726D5F6F70655F66756E63746F72,"term_ope_functor")
 Define_Atom(X617267,"arg")
 Define_Atom(X66756E63746F72,"functor")
 Define_Atom(X636F6D70617265,"compare")
 Define_Atom(X7465726D5F636D705F66756E63746F725F6E616D65,"term_cmp_functor_name")
 Define_Atom(X3D2E2E,"=..")
 Define_Atom(X7465726D5F756E6976,"term_univ")
 Define_Atom(X3D3D,"==")
 Define_Atom(X7465726D5F6571,"term_eq")
 Define_Atom(X5C3D3D,"\\==")
 Define_Atom(X7465726D5F6E6571,"term_neq")
 Define_Atom(X403C,"@<")
 Define_Atom(X7465726D5F6C74,"term_lt")
 Define_Atom(X403D3C,"@=<")
 Define_Atom(X7465726D5F6C7465,"term_lte")
 Define_Atom(X403E,"@>")
 Define_Atom(X7465726D5F6774,"term_gt")
 Define_Atom(X403E3D,"@>=")
 Define_Atom(X7465726D5F677465,"term_gte")
 Define_Atom(X696E6C696E655F6C6F61645F6D6174685F65787072,"inline_load_math_expr")
 Define_Atom(X496C6C6567616C2061726974686D657469632065787072657373696F6E,"Illegal arithmetic expression")
 Define_Atom(X696E6C696E655F6C6F61645F6D6174685F657870725F246175783232,"inline_load_math_expr_$aux22")
 Define_Atom(X6D6174685F6C6F61645F785F76616C7565,"math_load_x_value")
 Define_Atom(X6D6174685F6C6F61645F795F76616C7565,"math_load_y_value")
 Define_Atom(X696E6C696E655F6C6F61645F6D6174685F657870725F246175783234,"inline_load_math_expr_$aux24")
 Define_Atom(X616464,"add")
 Define_Atom(X66756E6374696F6E5F31,"function_1")
 Define_Atom(X696E6C696E655F6C6F61645F6D6174685F657870725F246175783233,"inline_load_math_expr_$aux23")
 Define_Atom(X2D,"-")
 Define_Atom(X6E6567,"neg")
 Define_Atom(X696E6C696E655F6C6F61645F6D6174685F657870725F246175783235,"inline_load_math_expr_$aux25")
 Define_Atom(X66756E6374696F6E5F32,"function_2")
 Define_Atom(X696E6C696E655F6C6F61645F6D6174685F657870725F246175783236,"inline_load_math_expr_$aux26")
 Define_Atom(X696E63,"inc")
 Define_Atom(X737562,"sub")
 Define_Atom(X646563,"dec")
 Define_Atom(X6D6174685F6578705F66756E63746F725F6E616D65,"math_exp_functor_name")
 Define_Atom(X2B,"+")
 Define_Atom(X2A,"*")
 Define_Atom(X6D756C,"mul")
 Define_Atom(X2F2F,"//")
 Define_Atom(X646976,"div")
 Define_Atom(X6D6F64,"mod")
 Define_Atom(X2F5C,"/\\")
 Define_Atom(X616E64,"and")
 Define_Atom(X5C2F,"\\/")
 Define_Atom(X6F72,"or")
 Define_Atom(X5E,"^")
 Define_Atom(X786F72,"xor")
 Define_Atom(X5C,"\\")
 Define_Atom(X6E6F74,"not")
 Define_Atom(X3C3C,"<<")
 Define_Atom(X73686C,"shl")
 Define_Atom(X3E3E,">>")
 Define_Atom(X736872,"shr")
 Define_Atom(X6D6174685F636D705F66756E63746F725F6E616D65,"math_cmp_functor_name")
 Define_Atom(X3D3A3D,"=:=")
 Define_Atom(X6571,"eq")
 Define_Atom(X3D5C3D,"=\\=")
 Define_Atom(X6E6571,"neq")
 Define_Atom(X3C,"<")
 Define_Atom(X6C74,"lt")
 Define_Atom(X3D3C,"=<")
 Define_Atom(X6C7465,"lte")
 Define_Atom(X3E,">")
 Define_Atom(X6774,"gt")
 Define_Atom(X3E3D,">=")
 Define_Atom(X677465,"gte")
 Define_Atom(X675F7661725F66756E63746F72,"g_var_functor")
 Define_Atom(X675F61737369676E,"g_assign")
 Define_Atom(X675F61737369676E62,"g_assignb")
 Define_Atom(X675F6C696E6B,"g_link")
 Define_Atom(X675F72656164,"g_read")
 Define_Atom(X675F61727261795F73697A65,"g_array_size")


 Define_Pred(X67656E65726174696F6E5F636F6465,5,1)

 Define_Pred(X67656E65726174696F6E5F636F64655F2461757831,5,0)

 Define_Pred(X67656E6572655F74657465,5,0)

 Define_Pred(X67656E6572655F746574655F2461757832,4,0)

 Define_Pred(X67656E5F746574655F6C73745F617267,4,0)

 Define_Pred(X67656E6572655F636F727073,2,0)

 Define_Pred(X67656E6572655F636F7270735F2461757833,3,0)

 Define_Pred(X67656E6572655F636F7270735F2461757834,2,0)

 Define_Pred(X67656E6572655F636F7270735F2461757835,5,0)

 Define_Pred(X67656E6572655F636F7270735F2461757836,3,0)

 Define_Pred(X67656E5F636F7270735F6C73745F617267,5,0)

 Define_Pred(X67656E5F756E69665F617267,4,0)
 Define_Switch_STC_Table(Swt_Table_Name(X67656E5F756E69665F617267,4,1,stc),3)
     Define_Switch_STC(X766172,3,Label_Pred_Name(X67656E5F756E69665F617267,4,2))
     Define_Switch_STC(X637374,1,Label_Pred_Name(X67656E5F756E69665F617267,4,8))
     Define_Switch_STC(X696E74,1,Label_Pred_Name(X67656E5F756E69665F617267,4,10))

 Define_Pred(X67656E5F756E69665F6172675F2461757837,4,0)

 Define_Pred(X67656E5F756E69665F6172675F2461757838,4,0)

 Define_Pred(X67656E5F6C6F61645F617267,5,0)
 Define_Switch_STC_Table(Swt_Table_Name(X67656E5F6C6F61645F617267,5,1,stc),3)
     Define_Switch_STC(X766172,3,Label_Pred_Name(X67656E5F6C6F61645F617267,5,2))
     Define_Switch_STC(X637374,1,Label_Pred_Name(X67656E5F6C6F61645F617267,5,8))
     Define_Switch_STC(X696E74,1,Label_Pred_Name(X67656E5F6C6F61645F617267,5,10))

 Define_Pred(X67656E5F6C6F61645F6172675F2461757839,4,0)

 Define_Pred(X67656E5F6C6F61645F6172675F246175783130,7,0)

 Define_Pred(X67656E5F6C73745F73747263,4,0)

 Define_Pred(X67656E5F6C73745F737472635F246175783131,7,0)

 Define_Pred(X67656E5F73747263,6,0)
 Define_Switch_STC_Table(Swt_Table_Name(X67656E5F73747263,6,1,stc),2)
     Define_Switch_STC(X6C7374,2,Label_Pred_Name(X67656E5F73747263,6,3))
     Define_Switch_STC(X737463,2,Label_Pred_Name(X67656E5F73747263,6,5))

 Define_Pred(X67656E5F737472635F246175783132,3,0)

 Define_Pred(X67656E5F737472635F246175783133,4,0)

 Define_Pred(X67656E5F756E6966795F6C73745F617267,5,0)

 Define_Pred(X67656E5F756E6966795F6C73745F6172675F246175783134,8,0)

 Define_Pred(X67656E5F636F6D7074655F766F6964,4,0)

 Define_Pred(X67656E5F756E6966795F617267,6,0)
 Define_Switch_STC_Table(Swt_Table_Name(X67656E5F756E6966795F617267,6,1,stc),3)
     Define_Switch_STC(X766172,3,Label_Pred_Name(X67656E5F756E6966795F617267,6,2))
     Define_Switch_STC(X637374,1,Label_Pred_Name(X67656E5F756E6966795F617267,6,8))
     Define_Switch_STC(X696E74,1,Label_Pred_Name(X67656E5F756E6966795F617267,6,10))

 Define_Pred(X67656E5F756E6966795F6172675F246175783135,5,0)

 Define_Pred(X67656E5F756E6966795F6172675F246175783136,4,0)

 Define_Pred(X67656E5F756E6966795F6172675F246175783137,3,0)

 Define_Pred(X67656E5F696E6C696E655F70726564,6,0)
 Define_Switch_CST_Table(Swt_Table_Name(X67656E5F696E6C696E655F70726564,6,1,cst),6)
     Define_Switch_CST(X246765745F62635F726567,Label_Pred_Name(X67656E5F696E6C696E655F70726564,6,3))
     Define_Switch_CST(X24637574,Label_Pred_Name(X67656E5F696E6C696E655F70726564,6,5))
     Define_Switch_CST(X246462675F74727565,Label_Pred_Name(X67656E5F696E6C696E655F70726564,6,7))
     Define_Switch_CST(X707261676D615F63,Label_Pred_Name(X67656E5F696E6C696E655F70726564,6,9))
     Define_Switch_CST(X63616C6C696E675F6D6F64756C655F6E62,Label_Pred_Name(X67656E5F696E6C696E655F70726564,6,11))
     Define_Switch_CST(X3D,Label_Pred_Name(X67656E5F696E6C696E655F70726564,6,13))

 Define_Pred(X67656E5F696E6C696E655F707265645F246175783139,2,0)

 Define_Pred(X67656E5F696E6C696E655F707265645F246175783138,1,0)

 Define_Pred(X67656E5F696E6C696E655F707265645F246175783230,2,0)

 Define_Pred(X67656E5F696E6C696E655F707265645F246175783231,5,0)

 Define_Pred(X696E6C696E655F756E69665F7265675F7465726D65,6,0)

 Define_Pred(X747970655F746573745F66756E63746F72,1,0)
 Define_Switch_CST_Table(Swt_Table_Name(X747970655F746573745F66756E63746F72,1,1,cst),8)
     Define_Switch_CST(X766172,Label_Pred_Name(X747970655F746573745F66756E63746F72,1,3))
     Define_Switch_CST(X6E6F6E766172,Label_Pred_Name(X747970655F746573745F66756E63746F72,1,5))
     Define_Switch_CST(X61746F6D,Label_Pred_Name(X747970655F746573745F66756E63746F72,1,7))
     Define_Switch_CST(X696E7465676572,Label_Pred_Name(X747970655F746573745F66756E63746F72,1,9))
     Define_Switch_CST(X6E756D626572,Label_Pred_Name(X747970655F746573745F66756E63746F72,1,11))
     Define_Switch_CST(X61746F6D6963,Label_Pred_Name(X747970655F746573745F66756E63746F72,1,13))
     Define_Switch_CST(X636F6D706F756E64,Label_Pred_Name(X747970655F746573745F66756E63746F72,1,15))
     Define_Switch_CST(X63616C6C61626C65,Label_Pred_Name(X747970655F746573745F66756E63746F72,1,17))

 Define_Pred(X7465726D5F6F70655F66756E63746F72,1,0)
 Define_Switch_CST_Table(Swt_Table_Name(X7465726D5F6F70655F66756E63746F72,1,1,cst),3)
     Define_Switch_CST(X617267,Label_Pred_Name(X7465726D5F6F70655F66756E63746F72,1,3))
     Define_Switch_CST(X66756E63746F72,Label_Pred_Name(X7465726D5F6F70655F66756E63746F72,1,5))
     Define_Switch_CST(X636F6D70617265,Label_Pred_Name(X7465726D5F6F70655F66756E63746F72,1,7))

 Define_Pred(X7465726D5F636D705F66756E63746F725F6E616D65,2,0)
 Define_Switch_CST_Table(Swt_Table_Name(X7465726D5F636D705F66756E63746F725F6E616D65,2,1,cst),7)
     Define_Switch_CST(X3D2E2E,Label_Pred_Name(X7465726D5F636D705F66756E63746F725F6E616D65,2,3))
     Define_Switch_CST(X3D3D,Label_Pred_Name(X7465726D5F636D705F66756E63746F725F6E616D65,2,5))
     Define_Switch_CST(X5C3D3D,Label_Pred_Name(X7465726D5F636D705F66756E63746F725F6E616D65,2,7))
     Define_Switch_CST(X403C,Label_Pred_Name(X7465726D5F636D705F66756E63746F725F6E616D65,2,9))
     Define_Switch_CST(X403D3C,Label_Pred_Name(X7465726D5F636D705F66756E63746F725F6E616D65,2,11))
     Define_Switch_CST(X403E,Label_Pred_Name(X7465726D5F636D705F66756E63746F725F6E616D65,2,13))
     Define_Switch_CST(X403E3D,Label_Pred_Name(X7465726D5F636D705F66756E63746F725F6E616D65,2,15))

 Define_Pred(X696E6C696E655F6C6F61645F6D6174685F65787072,4,0)
 Define_Switch_STC_Table(Swt_Table_Name(X696E6C696E655F6C6F61645F6D6174685F65787072,4,1,stc),4)
     Define_Switch_STC(X766172,3,Label_Pred_Name(X696E6C696E655F6C6F61645F6D6174685F65787072,4,4))
     Define_Switch_STC(X696E74,1,Label_Pred_Name(X696E6C696E655F6C6F61645F6D6174685F65787072,4,6))
     Define_Switch_STC(X6C7374,2,Label_Pred_Name(X696E6C696E655F6C6F61645F6D6174685F65787072,4,8))
     Define_Switch_STC(X737463,2,Label_Pred_Name(X696E6C696E655F6C6F61645F6D6174685F65787072,4,2))

 Define_Pred(X696E6C696E655F6C6F61645F6D6174685F657870725F246175783232,5,0)

 Define_Pred(X696E6C696E655F6C6F61645F6D6174685F657870725F246175783234,5,0)

 Define_Pred(X696E6C696E655F6C6F61645F6D6174685F657870725F246175783233,2,0)

 Define_Pred(X696E6C696E655F6C6F61645F6D6174685F657870725F246175783235,6,0)

 Define_Pred(X696E6C696E655F6C6F61645F6D6174685F657870725F246175783236,2,0)

 Define_Pred(X6D6174685F6578705F66756E63746F725F6E616D65,2,0)
 Define_Switch_CST_Table(Swt_Table_Name(X6D6174685F6578705F66756E63746F725F6E616D65,2,1,cst),11)
     Define_Switch_CST(X2B,Label_Pred_Name(X6D6174685F6578705F66756E63746F725F6E616D65,2,3))
     Define_Switch_CST(X2D,Label_Pred_Name(X6D6174685F6578705F66756E63746F725F6E616D65,2,5))
     Define_Switch_CST(X2A,Label_Pred_Name(X6D6174685F6578705F66756E63746F725F6E616D65,2,7))
     Define_Switch_CST(X2F2F,Label_Pred_Name(X6D6174685F6578705F66756E63746F725F6E616D65,2,9))
     Define_Switch_CST(X6D6F64,Label_Pred_Name(X6D6174685F6578705F66756E63746F725F6E616D65,2,11))
     Define_Switch_CST(X2F5C,Label_Pred_Name(X6D6174685F6578705F66756E63746F725F6E616D65,2,13))
     Define_Switch_CST(X5C2F,Label_Pred_Name(X6D6174685F6578705F66756E63746F725F6E616D65,2,15))
     Define_Switch_CST(X5E,Label_Pred_Name(X6D6174685F6578705F66756E63746F725F6E616D65,2,17))
     Define_Switch_CST(X5C,Label_Pred_Name(X6D6174685F6578705F66756E63746F725F6E616D65,2,19))
     Define_Switch_CST(X3C3C,Label_Pred_Name(X6D6174685F6578705F66756E63746F725F6E616D65,2,21))
     Define_Switch_CST(X3E3E,Label_Pred_Name(X6D6174685F6578705F66756E63746F725F6E616D65,2,23))

 Define_Pred(X6D6174685F636D705F66756E63746F725F6E616D65,2,0)
 Define_Switch_CST_Table(Swt_Table_Name(X6D6174685F636D705F66756E63746F725F6E616D65,2,1,cst),6)
     Define_Switch_CST(X3D3A3D,Label_Pred_Name(X6D6174685F636D705F66756E63746F725F6E616D65,2,3))
     Define_Switch_CST(X3D5C3D,Label_Pred_Name(X6D6174685F636D705F66756E63746F725F6E616D65,2,5))
     Define_Switch_CST(X3C,Label_Pred_Name(X6D6174685F636D705F66756E63746F725F6E616D65,2,7))
     Define_Switch_CST(X3D3C,Label_Pred_Name(X6D6174685F636D705F66756E63746F725F6E616D65,2,9))
     Define_Switch_CST(X3E,Label_Pred_Name(X6D6174685F636D705F66756E63746F725F6E616D65,2,11))
     Define_Switch_CST(X3E3D,Label_Pred_Name(X6D6174685F636D705F66756E63746F725F6E616D65,2,13))

 Define_Pred(X675F7661725F66756E63746F72,1,0)
 Define_Switch_CST_Table(Swt_Table_Name(X675F7661725F66756E63746F72,1,1,cst),5)
     Define_Switch_CST(X675F61737369676E,Label_Pred_Name(X675F7661725F66756E63746F72,1,3))
     Define_Switch_CST(X675F61737369676E62,Label_Pred_Name(X675F7661725F66756E63746F72,1,5))
     Define_Switch_CST(X675F6C696E6B,Label_Pred_Name(X675F7661725F66756E63746F72,1,7))
     Define_Switch_CST(X675F72656164,Label_Pred_Name(X675F7661725F66756E63746F72,1,9))
     Define_Switch_CST(X675F61727261795F73697A65,Label_Pred_Name(X675F7661725F66756E63746F72,1,11))

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(wamcc4)



End_Exec_Directives
