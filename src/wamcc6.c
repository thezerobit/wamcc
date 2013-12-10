/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : wamcc6.c
Main : no_main
****************************************************************************/

#define FAST_MATH
#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "wamcc6.h"
#include "wamcc6.usr"


#define ASCII_PRED "indexation"
#define PRED       X696E6465786174696F6E
#define ARITY      2

Begin_Public_Pred
      allocate(1)
      get_y_variable(0,1)
      put_constant(X66,1)
      put_x_variable(2,2)
      put_y_value(0,3)
      call(Pred_Name(X696E6465786174696F6E31,4),1,1,1,"indexation1",4)          /* begin sub 1 */
      put_y_value(0,0)
      put_integer(0,1)
      put_x_variable(2,2)
      deallocate
      execute(Pred_Name(X616C6C6F635F6C6162656C73,3),1,"alloc_labels",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "indexation1"
#define PRED       X696E6465786174696F6E31
#define ARITY      4

Begin_Private_Pred
      allocate(7)
      get_y_variable(2,1)
      get_list(3)
      unify_x_variable(1)
      unify_y_variable(1)
      get_structure(X6C6162656C,1,1)
      unify_x_local_value(2)
      get_y_bc_reg(0)
      put_y_variable(6,1)
      put_y_variable(5,2)
      put_y_variable(4,3)
      put_y_variable(3,4)
      call(Pred_Name(X636865726368655F766172,5),1,7,1,"cherche_var",5)          /* begin sub 1 */
      put_y_unsafe_value(6,0)
      put_y_unsafe_value(5,1)
      put_y_unsafe_value(4,2)
      put_y_unsafe_value(3,3)
      put_y_value(2,4)
      put_y_value(1,5)
      call(Pred_Name(X696E6465786572,6),1,1,2,"indexer",6)          /* begin sub 2 */
      cut_y(0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cherche_var"
#define PRED       X636865726368655F766172
#define ARITY      5

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(3),fail,G_label(1),fail)

label(1)
      try(5,1)          /* begin sub 1 */
      trust(7)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      get_integer(2,1)
      get_nil(2)
      get_nil(4)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_x_variable(5)
      unify_x_variable(0)
      get_structure(X636C,3,5)
      unify_x_variable(7)
      unify_x_variable(5)
      unify_x_variable(6)
      get_nil(2)
      get_structure(X636C,3,3)
      unify_x_value(7)
      unify_x_value(5)
      unify_x_value(6)
      get_x_value(0,4)
      builtin_1(var,5)
      execute(Pred_Name(X636865726368655F7661725F2461757831,2),1,"cherche_var_$aux1",2)

label(6)
      trust_me_else_fail

label(7)
      allocate(2)
      get_list(0)
      unify_x_variable(5)
      unify_x_variable(0)
      get_y_variable(1,1)
      get_list(2)
      unify_x_value(5)
      unify_x_variable(2)
      put_y_variable(0,1)
      call(Pred_Name(X636865726368655F766172,5),1,2,2,"cherche_var",5)          /* begin sub 2 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X636865726368655F7661725F2461757832,2),1,"cherche_var_$aux2",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cherche_var_$aux1"
#define PRED       X636865726368655F7661725F2461757831
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      put_nil(2)
      builtin_2(term_eq,0,2)
      neck_cut
      get_integer(14,1)
      proceed

label(1)
      trust_me_else_fail
      get_integer(13,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cherche_var_$aux2"
#define PRED       X636865726368655F7661725F2461757832
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      put_integer(13,2)
      builtin_2(term_eq,1,2)
      neck_cut
      get_integer(11,0)
      proceed

label(1)
      retry_me_else(2)
      put_integer(14,2)
      builtin_2(term_eq,1,2)
      neck_cut
      get_integer(12,0)
      proceed

label(2)
      trust_me_else_fail
      get_x_value(1,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "indexer"
#define PRED       X696E6465786572
#define ARITY      6

Begin_Private_Pred
      switch_on_term(G_label(2),fail,G_label(1),fail,fail)

label(1)
      switch_on_integer(lst(i(11,3) i(12,5) i(13,7) i(14,9) i(2,11) ),"[(11,3),(12,5),(13,7),(14,9),(2,11)]")

label(2)
      try_me_else(4)

label(3)
      allocate(9)
      get_integer(11,0)
      get_y_variable(8,1)
      get_structure(X636C,3,2)
      unify_void(2)
      unify_y_variable(1)
      get_y_variable(7,3)
      get_y_variable(6,5)
      put_x_value(4,0)
      put_y_variable(5,1)
      put_y_variable(3,2)
      call(Pred_Name(X696E64657865725F2461757833,3),1,9,1,"indexer_$aux3",3)          /* begin sub 1 */
      put_integer(2,0)
      put_y_value(8,1)
      put_x_variable(2,2)
      put_x_variable(3,3)
      put_constant(X66,4)
      put_y_variable(4,5)
      call(Pred_Name(X696E6465786572,6),1,8,2,"indexer",6)          /* begin sub 2 */
      put_y_value(7,0)
      put_constant(X74,1)
      put_y_variable(2,2)
      put_y_variable(0,3)
      call(Pred_Name(X696E6465786174696F6E31,4),1,7,3,"indexation1",4)          /* begin sub 3 */
      put_y_value(6,0)
      get_list(0)
      unify_y_local_value(5)
      unify_x_variable(0)
      get_list(0)
      unify_y_local_value(4)
      unify_x_variable(0)
      get_list(0)
      unify_x_variable(1)
      unify_x_variable(0)
      get_structure(X6C6162656C,1,1)
      unify_y_local_value(3)
      get_list(0)
      unify_x_variable(1)
      unify_x_variable(0)
      get_structure(X72657472795F6D655F656C7365,1,1)
      unify_y_local_value(2)
      get_list(0)
      unify_y_value(1)
      unify_y_local_value(0)
      deallocate
      proceed

label(4)
      retry_me_else(6)

label(5)
      allocate(6)
      get_integer(12,0)
      get_y_variable(5,1)
      get_structure(X636C,3,2)
      unify_void(2)
      unify_y_variable(0)
      get_y_variable(4,5)
      put_x_value(4,0)
      put_y_variable(3,1)
      put_y_variable(1,2)
      call(Pred_Name(X696E64657865725F2461757834,3),1,6,4,"indexer_$aux4",3)          /* begin sub 4 */
      put_integer(2,0)
      put_y_value(5,1)
      put_x_variable(2,2)
      put_x_variable(3,3)
      put_constant(X66,4)
      put_y_variable(2,5)
      call(Pred_Name(X696E6465786572,6),1,5,5,"indexer",6)          /* begin sub 5 */
      put_y_value(4,0)
      get_list(0)
      unify_y_local_value(3)
      unify_x_variable(0)
      get_list(0)
      unify_y_local_value(2)
      unify_x_variable(0)
      get_list(0)
      unify_x_variable(1)
      unify_x_variable(0)
      get_structure(X6C6162656C,1,1)
      unify_y_local_value(1)
      get_list(0)
      unify_constant(X74727573745F6D655F656C73655F6661696C)
      unify_y_value(0)
      deallocate
      proceed

label(6)
      retry_me_else(8)

label(7)
      allocate(6)
      get_integer(13,0)
      get_structure(X636C,3,2)
      unify_void(2)
      unify_y_variable(1)
      get_y_variable(5,3)
      get_y_variable(3,5)
      put_x_value(4,0)
      put_y_variable(4,1)
      put_y_variable(2,2)
      call(Pred_Name(X696E64657865725F2461757835,3),1,6,6,"indexer_$aux5",3)          /* begin sub 6 */
      put_y_value(5,0)
      put_constant(X74,1)
      put_y_unsafe_value(4,2)
      put_y_variable(0,3)
      call(Pred_Name(X696E6465786174696F6E31,4),1,4,7,"indexation1",4)          /* begin sub 7 */
      put_y_value(3,0)
      get_list(0)
      unify_y_local_value(2)
      unify_x_variable(0)
      get_list(0)
      unify_y_value(1)
      unify_y_local_value(0)
      deallocate
      proceed

label(8)
      retry_me_else(10)

label(9)
      get_integer(14,0)
      get_structure(X636C,3,2)
      unify_void(2)
      unify_x_variable(0)
      put_x_value(4,1)
      put_x_value(5,2)
      execute(Pred_Name(X696E64657865725F2461757836,3),1,"indexer_$aux6",3)

label(10)
      trust_me_else_fail

label(11)
      allocate(19)
      get_integer(2,0)
      get_y_variable(3,1)
      get_y_bc_reg(0)
      put_x_value(4,0)
      put_x_value(5,1)
      put_y_variable(14,2)
      put_y_variable(11,3)
      put_y_variable(8,4)
      put_y_variable(5,5)
      put_y_variable(18,6)
      put_y_variable(2,7)
      call(Pred_Name(X696E64657865725F2461757837,8),1,19,8,"indexer_$aux7",8)          /* begin sub 8 */
      put_y_value(3,0)
      put_y_variable(15,1)
      put_y_variable(12,2)
      put_y_variable(9,3)
      put_y_variable(6,4)
      call(Pred_Name(X6465636F75706572,5),1,19,9,"decouper",5)          /* begin sub 9 */
      cut_y(0)
      put_y_value(14,0)
      put_y_value(15,1)
      put_y_variable(17,2)
      put_y_variable(16,3)
      call(Pred_Name(X696E64657865725F2461757838,4),1,19,10,"indexer_$aux8",4)          /* begin sub 10 */
      put_y_value(11,0)
      put_y_value(12,1)
      put_y_value(17,2)
      put_y_value(16,3)
      call(Pred_Name(X696E64657865725F2461757839,4),1,19,11,"indexer_$aux9",4)          /* begin sub 11 */
      put_y_value(8,0)
      put_y_value(9,1)
      put_y_value(17,2)
      put_y_value(16,3)
      call(Pred_Name(X696E64657865725F246175783130,4),1,19,12,"indexer_$aux10",4)          /* begin sub 12 */
      put_y_value(5,0)
      put_y_value(6,1)
      put_y_value(17,2)
      put_y_value(16,3)
      call(Pred_Name(X696E64657865725F246175783131,4),1,19,13,"indexer_$aux11",4)          /* begin sub 13 */
      put_y_unsafe_value(18,0)
      put_y_unsafe_value(17,1)
      put_y_unsafe_value(16,2)
      put_y_variable(13,3)
      call(Pred_Name(X696E64657865725F246175783132,4),1,16,14,"indexer_$aux12",4)          /* begin sub 14 */
      put_y_unsafe_value(15,0)
      put_constant(X7377697463685F6F6E5F636F6E7374616E74,1)
      put_y_unsafe_value(14,2)
      put_y_variable(10,3)
      put_y_unsafe_value(13,4)
      call(Pred_Name(X67656E5F737769746368,5),1,13,15,"gen_switch",5)          /* begin sub 15 */
      cut_y(0)
      put_y_unsafe_value(12,0)
      put_constant(X7377697463685F6F6E5F696E7465676572,1)
      put_y_unsafe_value(11,2)
      put_y_variable(7,3)
      put_y_unsafe_value(10,4)
      call(Pred_Name(X67656E5F737769746368,5),1,10,16,"gen_switch",5)          /* begin sub 16 */
      cut_y(0)
      put_y_unsafe_value(9,0)
      put_y_unsafe_value(8,1)
      put_y_variable(4,2)
      put_y_unsafe_value(7,3)
      call(Pred_Name(X67656E5F6C69737465,4),1,7,17,"gen_liste",4)          /* begin sub 17 */
      cut_y(0)
      put_y_unsafe_value(6,0)
      put_constant(X7377697463685F6F6E5F737472756374757265,1)
      put_y_unsafe_value(5,2)
      put_y_variable(1,3)
      put_y_unsafe_value(4,4)
      call(Pred_Name(X67656E5F737769746368,5),1,4,18,"gen_switch",5)          /* begin sub 18 */
      cut_y(0)
      put_y_value(3,0)
      put_y_unsafe_value(2,1)
      put_y_unsafe_value(1,2)
      call(Pred_Name(X67656E5F696E737473,3),1,1,19,"gen_insts",3)          /* begin sub 19 */
      cut_y(0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "indexer_$aux3"
#define PRED       X696E64657865725F2461757833
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      put_constant(X66,3)
      builtin_2(term_eq,0,3)
      neck_cut
      get_structure(X7472795F6D655F656C7365,1,1)
      unify_x_local_value(2)
      proceed

label(1)
      trust_me_else_fail
      get_structure(X72657472795F6D655F656C7365,1,1)
      unify_x_local_value(2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "indexer_$aux4"
#define PRED       X696E64657865725F2461757834
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      put_constant(X66,3)
      builtin_2(term_eq,0,3)
      neck_cut
      get_structure(X7472795F6D655F656C7365,1,1)
      unify_x_local_value(2)
      proceed

label(1)
      trust_me_else_fail
      get_structure(X72657472795F6D655F656C7365,1,1)
      unify_x_local_value(2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "indexer_$aux5"
#define PRED       X696E64657865725F2461757835
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      put_constant(X66,3)
      builtin_2(term_eq,0,3)
      neck_cut
      get_structure(X7472795F6D655F656C7365,1,2)
      unify_x_local_value(1)
      proceed

label(1)
      trust_me_else_fail
      get_structure(X72657472795F6D655F656C7365,1,2)
      unify_x_local_value(1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "indexer_$aux6"
#define PRED       X696E64657865725F2461757836
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      put_constant(X66,3)
      builtin_2(term_eq,1,3)
      neck_cut
      get_x_value(0,2)
      proceed

label(1)
      trust_me_else_fail
      get_list(2)
      unify_constant(X74727573745F6D655F656C73655F6661696C)
      unify_x_local_value(0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "indexer_$aux12"
#define PRED       X696E64657865725F246175783132
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      put_constant(X74,4)
      builtin_2(term_eq,2,4)
      neck_cut
      get_x_value(3,0)
      get_constant(X6661696C,1)
      proceed

label(1)
      trust_me_else_fail
      get_x_value(3,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "indexer_$aux11"
#define PRED       X696E64657865725F246175783131
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      put_nil(4)
      builtin_2(term_eq,1,4)
      neck_cut
      get_x_value(2,0)
      get_constant(X74,3)
      proceed

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "indexer_$aux10"
#define PRED       X696E64657865725F246175783130
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      put_nil(4)
      builtin_2(term_eq,1,4)
      neck_cut
      get_x_value(2,0)
      get_constant(X74,3)
      proceed

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "indexer_$aux9"
#define PRED       X696E64657865725F2461757839
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      put_nil(4)
      builtin_2(term_eq,1,4)
      neck_cut
      get_x_value(2,0)
      get_constant(X74,3)
      proceed

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "indexer_$aux8"
#define PRED       X696E64657865725F2461757838
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      put_nil(4)
      builtin_2(term_eq,1,4)
      neck_cut
      get_x_value(2,0)
      get_constant(X74,3)
      proceed

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "indexer_$aux7"
#define PRED       X696E64657865725F2461757837
#define ARITY      8

Begin_Private_Pred
      try_me_else(1)
      put_constant(X66,8)
      builtin_2(term_eq,0,8)
      neck_cut
      get_list(1)
      unify_x_variable(0)
      unify_x_local_value(6)
      get_structure(X7377697463685F6F6E5F7465726D,5,0)
      unify_x_local_value(7)
      unify_x_local_value(2)
      unify_x_local_value(3)
      unify_x_local_value(4)
      unify_x_local_value(5)
      proceed

label(1)
      trust_me_else_fail
      get_list(1)
      unify_constant(X74727573745F6D655F656C73655F6661696C)
      unify_x_variable(0)
      get_list(0)
      unify_x_variable(0)
      unify_x_local_value(6)
      get_structure(X7377697463685F6F6E5F7465726D,5,0)
      unify_x_local_value(7)
      unify_x_local_value(2)
      unify_x_local_value(3)
      unify_x_local_value(4)
      unify_x_local_value(5)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "decouper"
#define PRED       X6465636F75706572
#define ARITY      5

Begin_Private_Pred
      allocate(6)
      get_y_variable(4,1)
      get_y_variable(2,2)
      get_x_variable(8,3)
      get_y_variable(0,4)
      put_nil(1)
      put_nil(2)
      put_structure(X61,2,3)
      unify_x_variable(4)
      unify_x_value(4)
      put_nil(4)
      put_y_variable(5,5)
      put_y_variable(3,6)
      put_structure(X61,2,7)
      unify_nil
      unify_x_local_value(8)
      put_y_variable(1,8)
      call(Pred_Name(X6465636F7570657231,9),1,6,1,"decouper1",9)          /* begin sub 1 */
      put_y_unsafe_value(5,0)
      put_y_value(4,1)
      call(Pred_Name(X66696E69725F6C69737465,2),1,4,2,"finir_liste",2)          /* begin sub 2 */
      put_y_unsafe_value(3,0)
      put_y_value(2,1)
      call(Pred_Name(X66696E69725F6C69737465,2),1,2,3,"finir_liste",2)          /* begin sub 3 */
      put_y_unsafe_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X66696E69725F6C69737465,2),1,"finir_liste",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "decouper1"
#define PRED       X6465636F7570657231
#define ARITY      9

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_x_value(1,5)
      get_x_value(2,6)
      get_x_value(3,7)
      get_x_value(4,8)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(9)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(8)
      get_structure(X636C,3,0)
      unify_x_variable(13)
      unify_x_variable(0)
      unify_void(1)
      get_x_variable(12,1)
      get_x_variable(11,2)
      get_x_variable(10,3)
      get_x_variable(9,4)
      get_y_variable(3,5)
      get_y_variable(2,6)
      get_y_variable(1,7)
      get_y_variable(0,8)
      put_x_value(13,1)
      put_x_value(12,2)
      put_x_value(11,3)
      put_x_value(10,4)
      put_x_value(9,5)
      put_y_variable(7,6)
      put_y_variable(6,7)
      put_y_variable(5,8)
      put_y_variable(4,9)
      call(Pred_Name(X6465636F7570657232,10),1,9,1,"decouper2",10)          /* begin sub 1 */
      put_y_value(8,0)
      put_y_unsafe_value(7,1)
      put_y_unsafe_value(6,2)
      put_y_unsafe_value(5,3)
      put_y_unsafe_value(4,4)
      put_y_value(3,5)
      put_y_value(2,6)
      put_y_value(1,7)
      put_y_value(0,8)
      deallocate
      execute(Pred_Name(X6465636F7570657231,9),1,"decouper1",9)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "decouper2"
#define PRED       X6465636F7570657232
#define ARITY      10

Begin_Private_Pred
      switch_on_term(G_label(3),fail,fail,fail,G_label(1))

label(1)
      switch_on_structure(1,"[(/ /2,2)]")

label(2)
      try(4,1)          /* begin sub 1 */
      retry(6,2)          /* begin sub 2 */
      trust(8)

label(3)
      try_me_else(5)

label(4)
      allocate(7)
      get_structure(X2F,2,0)
      unify_y_variable(6)
      unify_integer(0)
      get_y_variable(5,1)
      get_y_variable(4,2)
      get_y_variable(3,3)
      get_y_variable(2,6)
      get_y_variable(1,7)
      get_x_value(4,8)
      get_x_value(5,9)
      put_y_value(6,0)
      put_y_variable(0,1)
      call(Pred_Name(X747970655F61746F6D6963,2),0,7,3,"type_atomic",2)          /* begin sub 3 */
      put_y_value(6,0)
      put_y_value(5,1)
      put_y_value(4,2)
      put_y_value(3,3)
      put_y_value(2,4)
      put_y_value(1,5)
      put_y_unsafe_value(0,6)
      deallocate
      execute(Pred_Name(X6465636F75706572325F246175783133,7),1,"decouper2_$aux13",7)

label(5)
      retry_me_else(7)

label(6)
      get_structure(X2F,2,0)
      unify_constant(X2E)
      unify_integer(2)
      get_structure(X61,2,4)
      unify_x_variable(4)
      unify_x_variable(0)
      get_list(4)
      unify_x_local_value(1)
      unify_x_variable(1)
      get_x_value(2,6)
      get_x_value(3,7)
      get_structure(X61,2,8)
      unify_x_value(1)
      unify_x_value(0)
      get_x_value(5,9)
      proceed

label(7)
      trust_me_else_fail

label(8)
      get_structure(X2F,2,0)
      unify_x_variable(12)
      unify_x_variable(11)
      get_x_variable(10,1)
      get_x_value(2,6)
      get_x_value(3,7)
      get_x_value(4,8)
      put_x_value(5,0)
      put_structure(X2F,2,1)
      unify_x_value(12)
      unify_x_value(11)
      put_x_value(10,2)
      put_x_value(9,3)
      execute(Pred_Name(X616A6F75745F656E5F6C69737465,4),1,"ajout_en_liste",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "decouper2_$aux13"
#define PRED       X6465636F75706572325F246175783133
#define ARITY      7

Begin_Private_Pred
      try_me_else(1)
      allocate(2)
      get_x_variable(8,0)
      get_x_variable(7,1)
      get_y_variable(0,3)
      get_y_variable(1,5)
      put_structure(X637374,1,0)
      unify_x_local_value(8)
      builtin_2(term_eq,6,0)
      neck_cut
      put_x_value(2,0)
      put_x_value(8,1)
      put_x_value(7,2)
      put_x_value(4,3)
      call(Pred_Name(X616A6F75745F656E5F6C69737465,4),1,2,1,"ajout_en_liste",4)          /* begin sub 1 */
      put_y_value(1,0)
      get_y_value(0,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      allocate(2)
      get_x_variable(8,0)
      get_x_variable(7,1)
      get_y_variable(0,2)
      get_y_variable(1,4)
      put_x_value(3,0)
      put_x_value(8,1)
      put_x_value(7,2)
      put_x_value(5,3)
      call(Pred_Name(X616A6F75745F656E5F6C69737465,4),1,2,2,"ajout_en_liste",4)          /* begin sub 2 */
      put_y_value(1,0)
      get_y_value(0,0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "ajout_en_liste"
#define PRED       X616A6F75745F656E5F6C69737465
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
      get_list(3)
      unify_x_variable(0)
      unify_nil
      get_structure(X61,3,0)
      unify_x_local_value(1)
      unify_x_variable(0)
      unify_x_variable(1)
      get_list(1)
      unify_x_local_value(2)
      unify_x_value(0)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_x_variable(0)
      unify_x_variable(6)
      get_structure(X61,3,0)
      unify_x_variable(5)
      unify_x_variable(4)
      unify_x_variable(0)
      get_list(4)
      unify_x_variable(7)
      unify_x_variable(4)
      get_x_value(5,1)
      get_x_value(7,2)
      get_list(3)
      unify_x_variable(1)
      unify_x_value(6)
      get_structure(X61,3,1)
      unify_x_value(5)
      unify_x_value(4)
      unify_x_value(0)
      proceed

label(6)
      trust_me_else_fail

label(7)
      get_list(0)
      unify_x_variable(4)
      unify_x_variable(0)
      get_list(3)
      unify_x_value(4)
      unify_x_variable(3)
      execute(Pred_Name(X616A6F75745F656E5F6C69737465,4),1,"ajout_en_liste",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "finir_liste"
#define PRED       X66696E69725F6C69737465
#define ARITY      2

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_nil(1)
      proceed

label(3)
      trust_me_else_fail

label(4)
      get_list(0)
      unify_x_variable(2)
      unify_x_variable(0)
      get_structure(X61,3,2)
      unify_x_variable(3)
      unify_nil
      unify_x_variable(2)
      get_list(1)
      unify_x_variable(4)
      unify_x_variable(1)
      get_structure(X61,2,4)
      unify_x_value(3)
      unify_x_value(2)
      execute(Pred_Name(X66696E69725F6C69737465,2),1,"finir_liste",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_switch"
#define PRED       X67656E5F737769746368
#define ARITY      5

Begin_Private_Pred
      try_me_else(5)
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
      get_list(0)
      unify_x_variable(0)
      unify_nil
      get_structure(X61,2,0)
      unify_void(1)
      unify_x_variable(0)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      get_x_value(0,2)
      get_x_value(3,4)
      proceed

label(5)
      trust_me_else_fail
      allocate(5)
      get_y_variable(4,1)
      get_y_variable(3,2)
      get_list(4)
      unify_x_variable(2)
      unify_x_variable(1)
      get_structure(X6C6162656C,1,2)
      unify_y_local_value(3)
      get_list(1)
      unify_y_variable(2)
      unify_x_variable(4)
      put_y_variable(1,1)
      put_y_variable(0,2)
      call(Pred_Name(X637265655F6C697374655F737769746368,5),1,5,1,"cree_liste_switch",5)          /* begin sub 1 */
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_unsafe_value(1,3)
      put_y_unsafe_value(0,4)
      deallocate
      execute(Pred_Name(X67656E5F7377697463685F246175783134,5),1,"gen_switch_$aux14",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_switch_$aux14"
#define PRED       X67656E5F7377697463685F246175783134
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      put_constant(X6D6F64655F63,6)
      put_constant(X74,5)
      builtin_2(g_read,6,5)
      neck_cut
      put_list(5)
      unify_x_local_value(4)
      unify_nil
      put_list(4)
      unify_x_local_value(3)
      unify_x_value(5)
      put_list(3)
      unify_x_local_value(1)
      unify_x_value(4)
      put_list(1)
      unify_x_local_value(0)
      unify_x_value(3)
      builtin_2(term_univ,2,1)
      proceed

label(1)
      trust_me_else_fail
      put_list(1)
      unify_x_local_value(4)
      unify_nil
      put_list(4)
      unify_x_local_value(3)
      unify_x_value(1)
      put_list(1)
      unify_x_local_value(0)
      unify_x_value(4)
      builtin_2(term_univ,2,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cree_liste_switch"
#define PRED       X637265655F6C697374655F737769746368
#define ARITY      5

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_integer(0,1)
      get_nil(2)
      get_x_value(3,4)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(6)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(5)
      get_structure(X61,2,0)
      unify_x_variable(5)
      unify_x_variable(0)
      get_y_variable(1,1)
      get_list(2)
      unify_x_variable(1)
      unify_y_variable(4)
      get_structure(X2C,2,1)
      unify_x_value(5)
      unify_x_variable(1)
      get_y_variable(3,3)
      put_y_variable(2,2)
      put_x_value(4,3)
      call(Pred_Name(X67656E5F6C69737465,4),1,6,1,"gen_liste",4)          /* begin sub 1 */
      put_y_value(5,0)
      put_y_variable(0,1)
      put_y_value(4,2)
      put_y_value(3,3)
      put_y_unsafe_value(2,4)
      call(Pred_Name(X637265655F6C697374655F737769746368,5),1,2,2,"cree_liste_switch",5)          /* begin sub 2 */
      math_load_y_value(0,0)
      function_1(inc,0,0)
      get_y_value(1,0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_liste"
#define PRED       X67656E5F6C69737465
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
      get_x_value(2,3)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      get_x_value(0,1)
      get_x_value(2,3)
      proceed

label(6)
      trust_me_else_fail

label(7)
      get_list(0)
      unify_x_variable(4)
      unify_x_variable(0)
      get_x_variable(5,1)
      get_x_variable(1,2)
      get_list(3)
      unify_x_variable(3)
      unify_x_variable(2)
      get_structure(X6C6162656C,1,3)
      unify_x_local_value(5)
      get_list(2)
      unify_x_variable(3)
      unify_x_variable(2)
      get_structure(X747279,1,3)
      unify_x_value(4)
      execute(Pred_Name(X67656E5F6C6973746531,3),1,"gen_liste1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_liste1"
#define PRED       X67656E5F6C6973746531
#define ARITY      3

Begin_Private_Pred
      switch_on_term(G_label(2),fail,fail,G_label(1),fail)

label(1)
      try(3,1)          /* begin sub 1 */
      trust(5)

label(2)
      try_me_else(4)

label(3)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      get_list(2)
      unify_x_variable(2)
      unify_x_local_value(1)
      get_structure(X7472757374,1,2)
      unify_x_value(0)
      proceed

label(4)
      trust_me_else_fail

label(5)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      get_list(2)
      unify_x_variable(4)
      unify_x_variable(2)
      get_structure(X7265747279,1,4)
      unify_x_value(3)
      execute(Pred_Name(X67656E5F6C6973746531,3),1,"gen_liste1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_insts"
#define PRED       X67656E5F696E737473
#define ARITY      3

Begin_Private_Pred
      switch_on_term(G_label(2),fail,fail,G_label(1),fail)

label(1)
      try(3,1)          /* begin sub 1 */
      trust(5)

label(2)
      try_me_else(4)

label(3)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      get_structure(X636C,3,0)
      unify_x_variable(0)
      unify_void(1)
      unify_x_variable(3)
      get_x_value(0,1)
      get_list(2)
      unify_x_variable(1)
      unify_x_value(3)
      get_structure(X6C6162656C,1,1)
      unify_x_value(0)
      proceed

label(4)
      trust_me_else_fail

label(5)
      allocate(6)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      get_structure(X636C,3,3)
      unify_y_variable(2)
      unify_void(1)
      unify_y_variable(1)
      get_y_variable(4,1)
      get_y_variable(5,2)
      put_y_variable(3,1)
      put_y_variable(0,2)
      call(Pred_Name(X67656E5F696E73747331,3),1,6,2,"gen_insts1",3)          /* begin sub 2 */
      put_y_value(5,0)
      get_list(0)
      unify_x_variable(1)
      unify_x_variable(0)
      get_structure(X6C6162656C,1,1)
      unify_y_local_value(4)
      get_list(0)
      unify_x_variable(1)
      unify_x_variable(0)
      get_structure(X7472795F6D655F656C7365,1,1)
      unify_y_local_value(3)
      get_list(0)
      unify_x_variable(1)
      unify_x_variable(0)
      get_structure(X6C6162656C,1,1)
      unify_y_value(2)
      get_list(0)
      unify_y_value(1)
      unify_y_local_value(0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "gen_insts1"
#define PRED       X67656E5F696E73747331
#define ARITY      3

Begin_Private_Pred
      switch_on_term(G_label(2),fail,fail,G_label(1),fail)

label(1)
      try(3,1)          /* begin sub 1 */
      trust(5)

label(2)
      try_me_else(4)

label(3)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      get_structure(X636C,3,0)
      unify_x_variable(0)
      unify_void(1)
      unify_x_variable(3)
      get_list(2)
      unify_x_variable(4)
      unify_x_variable(2)
      get_structure(X6C6162656C,1,4)
      unify_x_local_value(1)
      get_list(2)
      unify_constant(X74727573745F6D655F656C73655F6661696C)
      unify_x_variable(1)
      get_list(1)
      unify_x_variable(1)
      unify_x_value(3)
      get_structure(X6C6162656C,1,1)
      unify_x_value(0)
      proceed

label(4)
      trust_me_else_fail

label(5)
      allocate(6)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      get_structure(X636C,3,3)
      unify_y_variable(2)
      unify_void(1)
      unify_y_variable(1)
      get_y_variable(4,1)
      get_y_variable(5,2)
      put_y_variable(3,1)
      put_y_variable(0,2)
      call(Pred_Name(X67656E5F696E73747331,3),1,6,2,"gen_insts1",3)          /* begin sub 2 */
      put_y_value(5,0)
      get_list(0)
      unify_x_variable(1)
      unify_x_variable(0)
      get_structure(X6C6162656C,1,1)
      unify_y_local_value(4)
      get_list(0)
      unify_x_variable(1)
      unify_x_variable(0)
      get_structure(X72657472795F6D655F656C7365,1,1)
      unify_y_local_value(3)
      get_list(0)
      unify_x_variable(1)
      unify_x_variable(0)
      get_structure(X6C6162656C,1,1)
      unify_y_value(2)
      get_list(0)
      unify_y_value(1)
      unify_y_local_value(0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "alloc_labels"
#define PRED       X616C6C6F635F6C6162656C73
#define ARITY      3

Begin_Private_Pred
      try_me_else(7)
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),G_label(6))

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_x_value(1,2)
      proceed

label(3)
      retry_me_else(5)

label(4)
      allocate(3)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_y_variable(0,2)
      put_y_variable(1,2)
      call(Pred_Name(X616C6C6F635F6C6162656C73,3),1,3,1,"alloc_labels",3)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X616C6C6F635F6C6162656C73,3),1,"alloc_labels",3)

label(5)
      trust_me_else_fail

label(6)
      get_structure(X6C6162656C,1,0)
      unify_x_variable(0)
      get_x_value(0,1)
      math_load_x_value(0,0)
      function_1(inc,0,0)
      get_x_value(2,0)
      proceed

label(7)
      trust_me_else_fail
      get_x_value(1,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(wamcc6)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X696E6465786174696F6E,"indexation")
 Define_Atom(X66,"f")
 Define_Atom(X696E6465786174696F6E31,"indexation1")
 Define_Atom(X6C6162656C,"label")
 Define_Atom(X636865726368655F766172,"cherche_var")
 Define_Atom(X636C,"cl")
 Define_Atom(X636865726368655F7661725F2461757831,"cherche_var_$aux1")
 Define_Atom(X636865726368655F7661725F2461757832,"cherche_var_$aux2")
 Define_Atom(X696E6465786572,"indexer")
 Define_Atom(X74,"t")
 Define_Atom(X72657472795F6D655F656C7365,"retry_me_else")
 Define_Atom(X74727573745F6D655F656C73655F6661696C,"trust_me_else_fail")
 Define_Atom(X7377697463685F6F6E5F636F6E7374616E74,"switch_on_constant")
 Define_Atom(X7377697463685F6F6E5F696E7465676572,"switch_on_integer")
 Define_Atom(X7377697463685F6F6E5F737472756374757265,"switch_on_structure")
 Define_Atom(X696E64657865725F2461757833,"indexer_$aux3")
 Define_Atom(X7472795F6D655F656C7365,"try_me_else")
 Define_Atom(X696E64657865725F2461757834,"indexer_$aux4")
 Define_Atom(X696E64657865725F2461757835,"indexer_$aux5")
 Define_Atom(X696E64657865725F2461757836,"indexer_$aux6")
 Define_Atom(X696E64657865725F246175783132,"indexer_$aux12")
 Define_Atom(X6661696C,"fail")
 Define_Atom(X696E64657865725F246175783131,"indexer_$aux11")
 Define_Atom(X696E64657865725F246175783130,"indexer_$aux10")
 Define_Atom(X696E64657865725F2461757839,"indexer_$aux9")
 Define_Atom(X696E64657865725F2461757838,"indexer_$aux8")
 Define_Atom(X696E64657865725F2461757837,"indexer_$aux7")
 Define_Atom(X7377697463685F6F6E5F7465726D,"switch_on_term")
 Define_Atom(X6465636F75706572,"decouper")
 Define_Atom(X61,"a")
 Define_Atom(X6465636F7570657231,"decouper1")
 Define_Atom(X6465636F7570657232,"decouper2")
 Define_Atom(X2F,"/")
 Define_Atom(X2E,".")
 Define_Atom(X6465636F75706572325F246175783133,"decouper2_$aux13")
 Define_Atom(X637374,"cst")
 Define_Atom(X616A6F75745F656E5F6C69737465,"ajout_en_liste")
 Define_Atom(X66696E69725F6C69737465,"finir_liste")
 Define_Atom(X67656E5F737769746368,"gen_switch")
 Define_Atom(X67656E5F7377697463685F246175783134,"gen_switch_$aux14")
 Define_Atom(X6D6F64655F63,"mode_c")
 Define_Atom(X637265655F6C697374655F737769746368,"cree_liste_switch")
 Define_Atom(X2C,",")
 Define_Atom(X67656E5F6C69737465,"gen_liste")
 Define_Atom(X747279,"try")
 Define_Atom(X67656E5F6C6973746531,"gen_liste1")
 Define_Atom(X7472757374,"trust")
 Define_Atom(X7265747279,"retry")
 Define_Atom(X67656E5F696E737473,"gen_insts")
 Define_Atom(X67656E5F696E73747331,"gen_insts1")
 Define_Atom(X616C6C6F635F6C6162656C73,"alloc_labels")


 Define_Pred(X696E6465786174696F6E,2,1)

 Define_Pred(X696E6465786174696F6E31,4,0)

 Define_Pred(X636865726368655F766172,5,0)

 Define_Pred(X636865726368655F7661725F2461757831,2,0)

 Define_Pred(X636865726368655F7661725F2461757832,2,0)

 Define_Pred(X696E6465786572,6,0)

 Define_Pred(X696E64657865725F2461757833,3,0)

 Define_Pred(X696E64657865725F2461757834,3,0)

 Define_Pred(X696E64657865725F2461757835,3,0)

 Define_Pred(X696E64657865725F2461757836,3,0)

 Define_Pred(X696E64657865725F246175783132,4,0)

 Define_Pred(X696E64657865725F246175783131,4,0)

 Define_Pred(X696E64657865725F246175783130,4,0)

 Define_Pred(X696E64657865725F2461757839,4,0)

 Define_Pred(X696E64657865725F2461757838,4,0)

 Define_Pred(X696E64657865725F2461757837,8,0)

 Define_Pred(X6465636F75706572,5,0)

 Define_Pred(X6465636F7570657231,9,0)

 Define_Pred(X6465636F7570657232,10,0)
 Define_Switch_STC_Table(Swt_Table_Name(X6465636F7570657232,10,1,stc),1)
     Define_Switch_STC(X2F,2,Label_Pred_Name(X6465636F7570657232,10,2))

 Define_Pred(X6465636F75706572325F246175783133,7,0)

 Define_Pred(X616A6F75745F656E5F6C69737465,4,0)

 Define_Pred(X66696E69725F6C69737465,2,0)

 Define_Pred(X67656E5F737769746368,5,0)

 Define_Pred(X67656E5F7377697463685F246175783134,5,0)

 Define_Pred(X637265655F6C697374655F737769746368,5,0)

 Define_Pred(X67656E5F6C69737465,4,0)

 Define_Pred(X67656E5F6C6973746531,3,0)

 Define_Pred(X67656E5F696E737473,3,0)

 Define_Pred(X67656E5F696E73747331,3,0)

 Define_Pred(X616C6C6F635F6C6162656C73,3,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(wamcc6)



End_Exec_Directives
