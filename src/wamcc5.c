/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : wamcc5.c
Main : no_main
****************************************************************************/

#define FAST_MATH
#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "wamcc5.h"
#include "wamcc5.usr"


#define ASCII_PRED "allocation_varsX"
#define PRED       X616C6C6F636174696F6E5F7661727358
#define ARITY      1

Begin_Public_Pred
      allocate(3)
      get_y_variable(2,0)
      put_y_value(2,0)
      put_nil(1)
      put_y_variable(1,2)
      call(Pred_Name(X616C6961736573,3),1,3,1,"aliases",3)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_unsafe_value(1,1)
      put_x_variable(2,2)
      put_y_variable(0,3)
      call(Pred_Name(X6372656174655F6C73745F746D70,4),1,1,2,"create_lst_tmp",4)          /* begin sub 2 */
      put_y_unsafe_value(0,0)
      deallocate
      execute(Pred_Name(X61737369676E5F6C73745F746D70,1),1,"assign_lst_tmp",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "aliases"
#define PRED       X616C6961736573
#define ARITY      3

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_nil(2)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(3)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_list(2)
      unify_x_local_value(1)
      unify_y_variable(0)
      put_x_variable(3,4)
      put_x_variable(2,2)
      builtin_3(functor,0,4,2)
      get_x_bc_reg(2)
      put_y_variable(1,4)
      call(Pred_Name(X616C69617365735F2461757831,5),1,3,1,"aliases_$aux1",5)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X616C6961736573,3),1,"aliases",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "aliases_$aux1"
#define PRED       X616C69617365735F2461757831
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      allocate(2)
      get_y_variable(0,4)
      get_y_bc_reg(1)
      put_x_value(3,0)
      call(Pred_Name(X616C69617365735F2461757832,1),1,2,1,"aliases_$aux2",1)          /* begin sub 1 */
      cut_y(1)
      put_y_value(0,0)
      get_nil(0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      allocate(4)
      get_y_variable(1,1)
      get_y_variable(3,2)
      get_y_variable(0,4)
      put_y_variable(2,1)
      call(Pred_Name(X636F64696669636174696F6E,2),1,4,2,"codification",2)          /* begin sub 2 */
      cut_y(3)
      put_y_unsafe_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X616C696173657331,3),1,"aliases1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "aliases_$aux2"
#define PRED       X616C69617365735F2461757832
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      put_constant(X63616C6C,1)
      builtin_2(term_eq,0,1)
      proceed

label(1)
      trust_me_else_fail
      put_constant(X65786563757465,1)
      builtin_2(term_eq,0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "aliases1"
#define PRED       X616C696173657331
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
      allocate(4)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_y_variable(0,2)
      get_y_bc_reg(3)
      put_y_variable(1,2)
      call(Pred_Name(X616C6961736573315F2461757833,3),1,4,1,"aliases1_$aux3",3)          /* begin sub 1 */
      cut_y(3)
      put_y_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X616C696173657331,3),1,"aliases1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "aliases1_$aux3"
#define PRED       X616C6961736573315F2461757833
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      get_structure(X72,1,0)
      unify_void(1)
      get_x_value(1,2)
      proceed

label(1)
      retry_me_else(2)
      get_x_variable(3,0)
      get_x_variable(0,1)
      get_structure(X77,1,3)
      unify_x_variable(1)
      execute(Pred_Name(X72656D6F76655F616C69617365735F6F66,3),1,"remove_aliases_of",3)

label(2)
      trust_me_else_fail
      allocate(4)
      get_y_variable(0,2)
      get_structure(X63,2,0)
      unify_y_variable(2)
      unify_y_variable(1)
      put_x_value(1,0)
      put_y_value(1,1)
      put_y_variable(3,2)
      call(Pred_Name(X72656D6F76655F616C69617365735F6F66,3),1,4,1,"remove_aliases_of",3)          /* begin sub 1 */
      put_y_unsafe_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X6164645F616C696173,4),1,"add_alias",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "add_alias"
#define PRED       X6164645F616C696173
#define ARITY      4

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_list(3)
      unify_x_variable(0)
      unify_nil
      get_list(0)
      unify_x_local_value(1)
      unify_x_variable(0)
      get_list(0)
      unify_x_local_value(2)
      unify_nil
      proceed

label(3)
      trust_me_else_fail

label(4)
      get_list(0)
      unify_x_variable(0)
      unify_x_variable(8)
      get_x_variable(7,1)
      get_x_variable(6,2)
      get_list(3)
      unify_x_variable(4)
      unify_x_variable(5)
      put_x_value(8,1)
      put_x_value(7,2)
      put_x_value(6,3)
      execute(Pred_Name(X6164645F616C6961735F2461757834,6),1,"add_alias_$aux4",6)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "add_alias_$aux4"
#define PRED       X6164645F616C6961735F2461757834
#define ARITY      6

Begin_Private_Pred
      try_me_else(1)
      allocate(6)
      get_y_variable(4,0)
      get_y_variable(0,1)
      get_y_variable(3,3)
      get_y_variable(2,4)
      get_y_variable(1,5)
      get_y_bc_reg(5)
      put_y_value(4,0)
      put_x_value(2,1)
      call(Pred_Name(X656E735F656C74,2),0,6,1,"ens_elt",2)          /* begin sub 1 */
      cut_y(5)
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_value(2,2)
      call(Pred_Name(X656E735F616A6F7574,3),0,2,2,"ens_ajout",3)          /* begin sub 2 */
      put_y_value(1,0)
      get_y_value(0,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      get_x_value(0,4)
      put_x_value(1,0)
      put_x_value(2,1)
      put_x_value(3,2)
      put_x_value(5,3)
      execute(Pred_Name(X6164645F616C696173,4),1,"add_alias",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "find_aliases_of"
#define PRED       X66696E645F616C69617365735F6F66
#define ARITY      3

Begin_Private_Pred
      switch_on_term(G_label(1),fail,fail,G_label(1),fail)

label(1)
      get_list(0)
      unify_x_variable(0)
      unify_x_variable(5)
      get_x_variable(4,1)
      get_x_variable(3,2)
      put_x_value(5,1)
      put_x_value(4,2)
      execute(Pred_Name(X66696E645F616C69617365735F6F665F2461757835,4),1,"find_aliases_of_$aux5",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "find_aliases_of_$aux5"
#define PRED       X66696E645F616C69617365735F6F665F2461757835
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      allocate(1)
      get_y_bc_reg(0)
      put_x_value(2,1)
      put_x_value(3,2)
      call(Pred_Name(X656E735F72657472616974,3),0,1,1,"ens_retrait",3)          /* begin sub 1 */
      cut_y(0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      put_x_value(1,0)
      put_x_value(2,1)
      put_x_value(3,2)
      execute(Pred_Name(X66696E645F616C69617365735F6F66,3),1,"find_aliases_of",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "remove_aliases_of"
#define PRED       X72656D6F76655F616C69617365735F6F66
#define ARITY      3

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_nil(2)
      proceed

label(3)
      trust_me_else_fail

label(4)
      get_list(0)
      unify_x_variable(0)
      unify_x_variable(5)
      get_x_variable(4,1)
      get_x_variable(3,2)
      put_x_value(5,1)
      put_x_value(4,2)
      execute(Pred_Name(X72656D6F76655F616C69617365735F6F665F2461757836,4),1,"remove_aliases_of_$aux6",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "remove_aliases_of_$aux6"
#define PRED       X72656D6F76655F616C69617365735F6F665F2461757836
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      allocate(4)
      get_y_variable(2,1)
      get_y_variable(1,3)
      get_y_bc_reg(3)
      put_x_value(2,1)
      put_y_variable(0,2)
      call(Pred_Name(X656E735F72657472616974,3),0,4,1,"ens_retrait",3)          /* begin sub 1 */
      cut_y(3)
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_unsafe_value(0,2)
      deallocate
      execute(Pred_Name(X72656D6F76655F616C69617365735F6F665F2461757837,3),1,"remove_aliases_of_$aux7",3)

label(1)
      trust_me_else_fail
      get_x_variable(4,0)
      get_x_variable(0,1)
      get_x_variable(1,2)
      get_list(3)
      unify_x_local_value(4)
      unify_x_variable(2)
      execute(Pred_Name(X72656D6F76655F616C69617365735F6F66,3),1,"remove_aliases_of",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "remove_aliases_of_$aux7"
#define PRED       X72656D6F76655F616C69617365735F6F665F2461757837
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      allocate(3)
      get_y_variable(0,0)
      get_y_variable(1,1)
      get_y_bc_reg(2)
      put_x_value(2,0)
      call(Pred_Name(X72656D6F76655F616C69617365735F6F665F2461757838,1),1,3,1,"remove_aliases_of_$aux8",1)          /* begin sub 1 */
      cut_y(2)
      put_y_value(1,0)
      get_y_value(0,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      get_list(1)
      unify_x_local_value(2)
      unify_x_local_value(0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "remove_aliases_of_$aux8"
#define PRED       X72656D6F76655F616C69617365735F6F665F2461757838
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      put_nil(1)
      builtin_2(term_eq,0,1)
      proceed

label(1)
      trust_me_else_fail
      get_list(0)
      unify_void(1)
      unify_nil
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "create_lst_tmp"
#define PRED       X6372656174655F6C73745F746D70
#define ARITY      4

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_nil(1)
      get_nil(2)
      get_nil(3)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(8)
      get_list(0)
      unify_y_variable(7)
      unify_x_variable(0)
      get_list(1)
      unify_y_variable(4)
      unify_x_variable(1)
      get_y_variable(2,2)
      get_y_variable(0,3)
      get_y_bc_reg(6)
      put_y_variable(3,2)
      put_y_variable(1,3)
      call(Pred_Name(X6372656174655F6C73745F746D70,4),1,8,1,"create_lst_tmp",4)          /* begin sub 1 */
      put_y_value(7,0)
      put_y_variable(5,1)
      call(Pred_Name(X636F64696669636174696F6E,2),1,7,2,"codification",2)          /* begin sub 2 */
      cut_y(6)
      put_y_unsafe_value(5,0)
      put_y_value(4,1)
      put_y_unsafe_value(3,2)
      put_y_value(2,3)
      put_y_unsafe_value(1,4)
      put_y_value(0,5)
      deallocate
      execute(Pred_Name(X68616E646C655F6C73745F636F6465,6),1,"handle_lst_code",6)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "handle_lst_code"
#define PRED       X68616E646C655F6C73745F636F6465
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
      allocate(6)
      get_list(0)
      unify_y_variable(5)
      unify_x_variable(0)
      get_y_variable(4,1)
      get_y_variable(2,3)
      get_y_variable(0,5)
      put_y_value(4,1)
      put_y_variable(3,3)
      put_y_variable(1,5)
      call(Pred_Name(X68616E646C655F6C73745F636F6465,6),1,6,1,"handle_lst_code",6)          /* begin sub 1 */
      put_y_value(5,0)
      put_y_value(4,1)
      put_nil(2)
      put_y_unsafe_value(3,3)
      put_y_value(2,4)
      put_y_unsafe_value(1,5)
      put_y_value(0,6)
      deallocate
      execute(Pred_Name(X68616E646C655F6F6E655F636F6465,7),1,"handle_one_code",7)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "handle_one_code"
#define PRED       X68616E646C655F6F6E655F636F6465
#define ARITY      7

Begin_Private_Pred
      switch_on_term(G_label(2),fail,fail,fail,G_label(1))

label(1)
      switch_on_structure(1,"[(r/1,3),(w/1,5),(c/2,7)]")

label(2)
      try_me_else(4)

label(3)
      get_structure(X72,1,0)
      unify_x_variable(0)
      execute(Pred_Name(X68616E646C655F6F6E655F636F64655F2461757839,7),1,"handle_one_code_$aux9",7)

label(4)
      retry_me_else(6)

label(5)
      get_structure(X77,1,0)
      unify_x_variable(0)
      execute(Pred_Name(X68616E646C655F6F6E655F636F64655F246175783132,7),1,"handle_one_code_$aux12",7)

label(6)
      trust_me_else_fail

label(7)
      allocate(7)
      get_structure(X63,2,0)
      unify_y_variable(6)
      unify_y_variable(4)
      get_y_variable(5,1)
      get_y_variable(2,4)
      get_y_variable(0,6)
      put_structure(X77,1,0)
      unify_y_value(4)
      put_y_value(5,1)
      put_list(2)
      unify_y_value(6)
      unify_nil
      put_y_variable(3,4)
      put_y_variable(1,6)
      call(Pred_Name(X68616E646C655F6F6E655F636F6465,7),1,7,1,"handle_one_code",7)          /* begin sub 1 */
      put_structure(X72,1,0)
      unify_y_value(6)
      put_y_value(5,1)
      put_list(2)
      unify_y_value(4)
      unify_nil
      put_y_unsafe_value(3,3)
      put_y_value(2,4)
      put_y_unsafe_value(1,5)
      put_y_value(0,6)
      deallocate
      execute(Pred_Name(X68616E646C655F6F6E655F636F6465,7),1,"handle_one_code",7)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "handle_one_code_$aux9"
#define PRED       X68616E646C655F6F6E655F636F64655F2461757839
#define ARITY      7

Begin_Private_Pred
      try_me_else(1)
      allocate(7)
      get_y_variable(3,0)
      get_y_variable(2,2)
      get_y_variable(4,3)
      get_y_variable(5,4)
      get_y_variable(1,5)
      get_y_variable(0,6)
      get_y_bc_reg(6)
      put_y_value(4,0)
      put_y_value(3,1)
      call(Pred_Name(X656E735F656C74,2),0,7,1,"ens_elt",2)          /* begin sub 1 */
      cut_y(6)
      put_y_value(5,0)
      get_y_value(4,0)
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X68616E646C655F6F6E655F636F64655F246175783130,4),1,"handle_one_code_$aux10",4)

label(1)
      trust_me_else_fail
      allocate(6)
      get_y_variable(4,0)
      get_x_variable(7,1)
      get_y_variable(3,2)
      get_y_variable(5,5)
      get_y_variable(2,6)
      get_list(4)
      unify_y_local_value(4)
      unify_x_local_value(3)
      put_y_value(4,0)
      put_x_value(3,1)
      put_x_value(7,2)
      put_y_variable(1,3)
      call(Pred_Name(X636F6E73747261696E7473,4),1,6,2,"constraints",4)          /* begin sub 2 */
      put_y_value(1,0)
      put_list(1)
      unify_y_local_value(4)
      unify_nil
      put_y_value(5,2)
      put_y_variable(0,3)
      call(Pred_Name(X6D616B655F696D706F7373,4),1,5,3,"make_imposs",4)          /* begin sub 3 */
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_unsafe_value(1,3)
      put_y_unsafe_value(0,4)
      deallocate
      execute(Pred_Name(X68616E646C655F6F6E655F636F64655F246175783131,5),1,"handle_one_code_$aux11",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "handle_one_code_$aux10"
#define PRED       X68616E646C655F6F6E655F636F64655F246175783130
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      get_x_variable(6,0)
      get_x_variable(5,1)
      get_x_variable(4,3)
      builtin_1(var,6)
      put_nil(0)
      builtin_2(term_neq,5,0)
      neck_cut
      put_x_value(2,0)
      put_x_value(6,1)
      put_nil(2)
      put_x_value(5,3)
      execute(Pred_Name(X7570646174655F746D70,5),1,"update_tmp",5)

label(1)
      trust_me_else_fail
      get_x_value(2,3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "handle_one_code_$aux11"
#define PRED       X68616E646C655F6F6E655F636F64655F246175783131
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      get_x_variable(7,0)
      get_x_variable(6,1)
      get_x_variable(5,2)
      builtin_1(var,7)
      neck_cut
      put_x_value(4,0)
      put_x_value(7,1)
      put_x_value(3,2)
      put_x_value(6,3)
      put_x_value(5,4)
      execute(Pred_Name(X7570646174655F746D70,5),1,"update_tmp",5)

label(1)
      trust_me_else_fail
      get_x_value(4,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "handle_one_code_$aux12"
#define PRED       X68616E646C655F6F6E655F636F64655F246175783132
#define ARITY      7

Begin_Private_Pred
      try_me_else(1)
      allocate(5)
      get_y_variable(3,0)
      get_y_variable(2,2)
      get_y_variable(1,5)
      get_y_variable(0,6)
      get_y_bc_reg(4)
      put_x_value(3,0)
      put_y_value(3,1)
      put_x_value(4,2)
      call(Pred_Name(X656E735F72657472616974,3),0,5,1,"ens_retrait",3)          /* begin sub 1 */
      cut_y(4)
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X68616E646C655F6F6E655F636F64655F246175783133,4),1,"handle_one_code_$aux13",4)

label(1)
      trust_me_else_fail
      get_x_value(3,4)
      put_x_value(4,3)
      put_x_value(5,4)
      put_x_value(6,5)
      execute(Pred_Name(X68616E646C655F6F6E655F636F64655F246175783134,6),1,"handle_one_code_$aux14",6)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "handle_one_code_$aux13"
#define PRED       X68616E646C655F6F6E655F636F64655F246175783133
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      get_x_variable(6,0)
      get_x_variable(5,1)
      get_x_variable(4,3)
      builtin_1(var,6)
      put_nil(0)
      builtin_2(term_neq,5,0)
      neck_cut
      put_x_value(2,0)
      put_x_value(6,1)
      put_nil(2)
      put_x_value(5,3)
      execute(Pred_Name(X7570646174655F746D70,5),1,"update_tmp",5)

label(1)
      trust_me_else_fail
      get_x_value(2,3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "handle_one_code_$aux14"
#define PRED       X68616E646C655F6F6E655F636F64655F246175783134
#define ARITY      6

Begin_Private_Pred
      try_me_else(1)
      allocate(7)
      get_y_variable(3,0)
      get_x_variable(6,1)
      get_y_variable(1,2)
      get_y_variable(5,4)
      get_y_variable(0,5)
      put_y_value(3,0)
      builtin_1(var,0)
      neck_cut
      put_y_value(3,0)
      put_x_value(3,1)
      put_x_value(6,2)
      put_y_variable(6,3)
      call(Pred_Name(X636F6E73747261696E7473,4),1,7,1,"constraints",4)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_unsafe_value(6,1)
      put_y_variable(2,2)
      call(Pred_Name(X68616E646C655F6F6E655F636F64655F246175783135,3),1,6,2,"handle_one_code_$aux15",3)          /* begin sub 2 */
      put_y_value(2,0)
      put_list(1)
      unify_y_local_value(3)
      unify_nil
      put_y_value(5,2)
      put_y_variable(4,3)
      call(Pred_Name(X6D616B655F696D706F7373,4),1,5,3,"make_imposs",4)          /* begin sub 3 */
      put_y_unsafe_value(4,0)
      put_y_value(3,1)
      put_y_unsafe_value(2,2)
      put_y_value(1,3)
      put_y_value(0,4)
      deallocate
      execute(Pred_Name(X7570646174655F746D70,5),1,"update_tmp",5)

label(1)
      trust_me_else_fail
      get_x_value(4,5)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "handle_one_code_$aux15"
#define PRED       X68616E646C655F6F6E655F636F64655F246175783135
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      get_x_variable(3,0)
      put_nil(0)
      builtin_2(term_neq,3,0)
      neck_cut
      put_x_value(1,0)
      put_x_value(3,1)
      execute(Pred_Name(X656E735F636F6D706C,3),0,"ens_compl",3)

label(1)
      trust_me_else_fail
      get_x_value(1,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "constraints"
#define PRED       X636F6E73747261696E7473
#define ARITY      4

Begin_Private_Pred
      execute(Pred_Name(X636F6E73747261696E74735F246175783136,4),1,"constraints_$aux16",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "constraints_$aux16"
#define PRED       X636F6E73747261696E74735F246175783136
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      allocate(4)
      get_x_variable(4,0)
      get_y_variable(2,1)
      get_y_variable(0,3)
      get_y_bc_reg(3)
      put_x_value(2,0)
      put_x_value(4,1)
      put_y_variable(1,2)
      call(Pred_Name(X66696E645F616C69617365735F6F66,3),1,4,1,"find_aliases_of",3)          /* begin sub 1 */
      cut_y(3)
      put_y_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X656E735F636F6D706C,3),0,"ens_compl",3)

label(1)
      trust_me_else_fail
      get_x_value(1,3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "update_tmp"
#define PRED       X7570646174655F746D70
#define ARITY      5

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_list(4)
      unify_x_variable(0)
      unify_nil
      get_structure(X746D70,3,0)
      unify_x_local_value(1)
      unify_x_local_value(2)
      unify_x_local_value(3)
      proceed

label(3)
      trust_me_else_fail

label(4)
      get_list(0)
      unify_x_variable(0)
      unify_x_variable(13)
      get_x_variable(12,1)
      get_x_variable(11,2)
      get_x_variable(10,3)
      get_list(4)
      unify_x_variable(5)
      unify_x_variable(6)
      get_structure(X746D70,3,0)
      unify_x_variable(7)
      unify_x_variable(8)
      unify_x_variable(9)
      put_x_value(13,1)
      put_x_value(12,2)
      put_x_value(11,3)
      put_x_value(10,4)
      execute(Pred_Name(X7570646174655F746D705F246175783137,10),1,"update_tmp_$aux17",10)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "update_tmp_$aux17"
#define PRED       X7570646174655F746D705F246175783137
#define ARITY      10

Begin_Private_Pred
      try_me_else(1)
      allocate(8)
      get_y_variable(0,1)
      get_y_variable(4,2)
      get_y_variable(7,4)
      get_y_variable(5,5)
      get_y_variable(1,6)
      get_y_variable(6,9)
      put_y_value(4,0)
      builtin_2(term_eq,0,7)
      neck_cut
      put_x_value(3,0)
      put_x_value(8,1)
      put_y_variable(3,2)
      call(Pred_Name(X656E735F756E696F6E,3),0,8,1,"ens_union",3)          /* begin sub 1 */
      put_y_value(7,0)
      put_y_value(6,1)
      put_y_variable(2,2)
      call(Pred_Name(X656E735F756E696F6E,3),0,6,2,"ens_union",3)          /* begin sub 2 */
      put_y_value(5,0)
      get_structure(X746D70,3,0)
      unify_y_local_value(4)
      unify_y_local_value(3)
      unify_y_local_value(2)
      put_y_value(1,0)
      get_y_value(0,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      get_x_value(0,5)
      put_x_value(1,0)
      put_x_value(2,1)
      put_x_value(3,2)
      put_x_value(4,3)
      put_x_value(6,4)
      execute(Pred_Name(X7570646174655F746D70,5),1,"update_tmp",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "remove_tmp"
#define PRED       X72656D6F76655F746D70
#define ARITY      5

Begin_Private_Pred
      switch_on_term(G_label(1),fail,fail,G_label(1),fail)

label(1)
      get_list(0)
      unify_x_variable(0)
      unify_x_variable(12)
      get_x_variable(11,1)
      get_x_variable(10,2)
      get_x_variable(9,3)
      get_x_variable(5,4)
      get_structure(X746D70,3,0)
      unify_x_variable(6)
      unify_x_variable(7)
      unify_x_variable(8)
      put_x_value(12,1)
      put_x_value(11,2)
      put_x_value(10,3)
      put_x_value(9,4)
      execute(Pred_Name(X72656D6F76655F746D705F246175783138,9),1,"remove_tmp_$aux18",9)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "remove_tmp_$aux18"
#define PRED       X72656D6F76655F746D705F246175783138
#define ARITY      9

Begin_Private_Pred
      try_me_else(1)
      builtin_2(term_eq,2,6)
      neck_cut
      get_x_value(7,3)
      get_x_value(8,4)
      get_x_value(1,5)
      proceed

label(1)
      trust_me_else_fail
      get_x_variable(9,0)
      get_x_variable(0,1)
      get_x_variable(1,2)
      get_x_variable(2,3)
      get_x_variable(3,4)
      get_list(5)
      unify_x_local_value(9)
      unify_x_variable(4)
      execute(Pred_Name(X72656D6F76655F746D70,5),1,"remove_tmp",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "make_imposs"
#define PRED       X6D616B655F696D706F7373
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
      allocate(4)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(2,1)
      get_y_variable(0,3)
      put_y_value(2,1)
      put_y_variable(1,3)
      call(Pred_Name(X6D616B655F696D706F73735F246175783139,4),1,4,1,"make_imposs_$aux19",4)          /* begin sub 1 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_unsafe_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X6D616B655F696D706F7373,4),1,"make_imposs",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "make_imposs_$aux19"
#define PRED       X6D616B655F696D706F73735F246175783139
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      get_x_variable(6,0)
      get_x_variable(5,1)
      get_x_variable(4,3)
      builtin_1(var,6)
      neck_cut
      put_x_value(2,0)
      put_x_value(6,1)
      put_x_value(5,2)
      put_nil(3)
      execute(Pred_Name(X7570646174655F746D70,5),1,"update_tmp",5)

label(1)
      trust_me_else_fail
      get_x_value(2,3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "assign_lst_tmp"
#define PRED       X61737369676E5F6C73745F746D70
#define ARITY      1

Begin_Private_Pred
      allocate(1)
      put_y_variable(0,1)
      call(Pred_Name(X61737369676E5F776973686573,2),1,1,1,"assign_wishes",2)          /* begin sub 1 */
      put_y_unsafe_value(0,0)
      deallocate
      execute(Pred_Name(X61737369676E5F76616C756573,1),1,"assign_values",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "assign_wishes"
#define PRED       X61737369676E5F776973686573
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
      allocate(6)
      get_list(0)
      unify_x_variable(0)
      unify_x_variable(2)
      get_structure(X746D70,3,0)
      unify_y_variable(4)
      unify_x_variable(3)
      unify_x_variable(0)
      get_y_variable(3,1)
      put_x_value(3,1)
      put_y_value(4,3)
      put_y_variable(5,4)
      put_y_variable(2,5)
      put_y_variable(1,6)
      call(Pred_Name(X636F6C6C617073655F746D7073,7),1,6,1,"collapse_tmps",7)          /* begin sub 1 */
      put_y_value(4,0)
      put_y_value(2,1)
      put_y_unsafe_value(5,2)
      call(Pred_Name(X7472795F615F7768697368,3),1,5,2,"try_a_whish",3)          /* begin sub 2 */
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_unsafe_value(2,2)
      put_y_variable(0,3)
      call(Pred_Name(X61737369676E5F7769736865735F246175783230,4),1,2,3,"assign_wishes_$aux20",4)          /* begin sub 3 */
      put_y_unsafe_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X61737369676E5F776973686573,2),1,"assign_wishes",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "assign_wishes_$aux20"
#define PRED       X61737369676E5F7769736865735F246175783230
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      builtin_1(var,0)
      neck_cut
      get_list(1)
      unify_x_variable(1)
      unify_x_local_value(3)
      get_structure(X746D70,2,1)
      unify_x_local_value(0)
      unify_x_local_value(2)
      proceed

label(1)
      trust_me_else_fail
      get_x_value(3,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "collapse_tmps"
#define PRED       X636F6C6C617073655F746D7073
#define ARITY      7

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(3),fail,G_label(1),fail)

label(1)
      try(5,1)          /* begin sub 1 */
      retry(7,2)          /* begin sub 2 */
      trust(9)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      get_nil(4)
      get_x_value(1,5)
      get_x_value(2,6)
      proceed

label(4)
      retry_me_else(6)

label(5)
      allocate(8)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(6)
      get_y_variable(5,1)
      get_y_variable(4,2)
      get_y_variable(3,3)
      get_y_variable(2,4)
      get_y_variable(1,5)
      get_y_variable(0,6)
      get_y_bc_reg(7)
      put_y_value(5,1)
      put_y_value(3,2)
      call(Pred_Name(X636F6C6C617073655F746D70735F246175783231,3),1,8,3,"collapse_tmps_$aux21",3)          /* begin sub 3 */
      cut_y(7)
      put_y_value(6,0)
      put_y_value(5,1)
      put_y_value(4,2)
      put_y_value(3,3)
      put_y_value(2,4)
      put_y_value(1,5)
      put_y_value(0,6)
      deallocate
      execute(Pred_Name(X636F6C6C617073655F746D7073,7),1,"collapse_tmps",7)

label(6)
      retry_me_else(8)

label(7)
      get_list(0)
      unify_x_variable(7)
      unify_x_variable(0)
      get_list(4)
      unify_x_value(7)
      unify_x_variable(4)
      builtin_1(integer,7)
      neck_cut
      execute(Pred_Name(X636F6C6C617073655F746D7073,7),1,"collapse_tmps",7)

label(8)
      trust_me_else_fail

label(9)
      allocate(12)
      get_list(0)
      unify_y_variable(7)
      unify_y_variable(9)
      get_y_variable(11,1)
      get_y_variable(3,3)
      get_y_variable(2,4)
      get_y_variable(1,5)
      get_y_variable(0,6)
      put_x_value(2,0)
      put_y_value(7,1)
      put_y_variable(10,2)
      put_y_variable(8,3)
      put_y_variable(4,4)
      call(Pred_Name(X72656D6F76655F746D70,5),1,12,4,"remove_tmp",5)          /* begin sub 4 */
      put_y_value(11,0)
      put_y_unsafe_value(10,1)
      put_y_variable(5,2)
      call(Pred_Name(X656E735F756E696F6E,3),0,10,5,"ens_union",3)          /* begin sub 5 */
      put_y_value(9,0)
      put_y_unsafe_value(8,1)
      put_y_variable(6,2)
      call(Pred_Name(X656E735F756E696F6E,3),0,8,6,"ens_union",3)          /* begin sub 6 */
      put_y_value(3,0)
      get_y_value(7,0)
      put_y_unsafe_value(6,0)
      put_y_unsafe_value(5,1)
      put_y_unsafe_value(4,2)
      put_y_value(3,3)
      put_y_value(2,4)
      put_y_value(1,5)
      put_y_value(0,6)
      deallocate
      execute(Pred_Name(X636F6C6C617073655F746D7073,7),1,"collapse_tmps",7)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "collapse_tmps_$aux21"
#define PRED       X636F6C6C617073655F746D70735F246175783231
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      builtin_2(term_eq,0,2)
      proceed

label(1)
      trust_me_else_fail
      get_x_variable(3,0)
      put_x_value(1,0)
      put_x_value(3,1)
      execute(Pred_Name(X656E735F656C74,2),0,"ens_elt",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "try_a_whish"
#define PRED       X7472795F615F7768697368
#define ARITY      3

Begin_Private_Pred
      allocate(3)
      get_y_variable(2,0)
      get_y_bc_reg(0)
      put_x_value(2,0)
      put_y_variable(1,2)
      call(Pred_Name(X656E735F636F6D706C,3),0,3,1,"ens_compl",3)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_unsafe_value(1,1)
      call(Pred_Name(X7472795F615F77686973685F246175783232,2),1,1,2,"try_a_whish_$aux22",2)          /* begin sub 2 */
      cut_y(0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "try_a_whish_$aux22"
#define PRED       X7472795F615F77686973685F246175783232
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      get_list(1)
      unify_x_local_value(0)
      unify_void(1)
      proceed

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "assign_values"
#define PRED       X61737369676E5F76616C756573
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
      allocate(3)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(0)
      get_structure(X746D70,2,0)
      unify_y_variable(1)
      unify_x_variable(0)
      put_y_variable(2,1)
      call(Pred_Name(X736F7274,2),0,3,1,"sort",2)          /* begin sub 1 */
      put_y_unsafe_value(2,0)
      put_integer(0,1)
      put_y_value(1,2)
      call(Pred_Name(X66696E645F686F6C65,3),1,1,2,"find_hole",3)          /* begin sub 2 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X61737369676E5F76616C756573,1),1,"assign_values",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "find_hole"
#define PRED       X66696E645F686F6C65
#define ARITY      3

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(3),fail,G_label(1),fail)

label(1)
      try(5,1)          /* begin sub 1 */
      trust(7)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      get_x_value(1,2)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      builtin_1(var,3)
      neck_cut
      execute(Pred_Name(X66696E645F686F6C65,3),1,"find_hole",3)

label(6)
      trust_me_else_fail

label(7)
      get_list(0)
      unify_x_variable(0)
      unify_x_variable(5)
      get_x_variable(4,1)
      get_x_variable(3,2)
      put_x_value(5,1)
      put_x_value(4,2)
      execute(Pred_Name(X66696E645F686F6C655F246175783233,4),1,"find_hole_$aux23",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "find_hole_$aux23"
#define PRED       X66696E645F686F6C655F246175783233
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      math_load_x_value(0,0)
      math_load_x_value(2,2)
      builtin_2(gt,0,2)
      neck_cut
      get_x_value(2,3)
      proceed

label(1)
      trust_me_else_fail
      allocate(3)
      get_y_variable(2,1)
      get_y_variable(0,3)
      put_x_value(2,1)
      put_y_variable(1,2)
      call(Pred_Name(X66696E645F686F6C655F246175783234,3),1,3,1,"find_hole_$aux24",3)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X66696E645F686F6C65,3),1,"find_hole",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "find_hole_$aux24"
#define PRED       X66696E645F686F6C655F246175783234
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      builtin_2(term_eq,0,1)
      neck_cut
      math_load_x_value(1,1)
      function_1(inc,0,1)
      get_x_value(2,0)
      proceed

label(1)
      trust_me_else_fail
      get_x_value(1,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "codification"
#define PRED       X636F64696669636174696F6E
#define ARITY      2

Begin_Private_Pred
      try_me_else(68)
      switch_on_term(G_label(2),fail,fail,fail,G_label(1))

label(1)
      switch_on_structure(1,"[(get_x_variable/2,3),(get_x_value/2,5),(get_y_variable/2,7),(get_y_value/2,9),(get_constant/2,11),(get_integer/2,13),(get_nil/1,15),(get_list/1,17),(get_structure/2,19),(put_x_variable/2,21),(put_x_value/2,23),(put_y_variable/2,25),(put_y_value/2,27),(put_y_unsafe_value/2,29),(put_constant/2,31),(put_integer/2,33),(put_nil/1,35),(put_list/1,37),(put_structure/2,39),(unify_x_variable/1,41),(unify_x_value/1,43),(unify_x_local_value/1,45),(call/2,47),(execute/1,49),(get_x_bc_reg/1,51),(cut_x/1,53),(math_load_x_value/2,55),(math_load_y_value/2,57),(function_1/3,59),(function_2/4,61),(builtin_1/2,63),(builtin_2/3,65),(builtin_3/4,67)]")

label(2)
      try_me_else(4)

label(3)
      get_structure(X6765745F785F7661726961626C65,2,0)
      unify_x_variable(0)
      unify_x_variable(2)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X63,2,1)
      unify_x_value(2)
      unify_x_value(0)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_structure(X6765745F785F76616C7565,2,0)
      unify_x_variable(2)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      get_structure(X72,1,3)
      unify_x_value(2)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X72,1,1)
      unify_x_value(0)
      proceed

label(6)
      retry_me_else(8)

label(7)
      get_structure(X6765745F795F7661726961626C65,2,0)
      unify_void(1)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X72,1,1)
      unify_x_value(0)
      proceed

label(8)
      retry_me_else(10)

label(9)
      get_structure(X6765745F795F76616C7565,2,0)
      unify_void(1)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X72,1,1)
      unify_x_value(0)
      proceed

label(10)
      retry_me_else(12)

label(11)
      get_structure(X6765745F636F6E7374616E74,2,0)
      unify_void(1)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X72,1,1)
      unify_x_value(0)
      proceed

label(12)
      retry_me_else(14)

label(13)
      get_structure(X6765745F696E7465676572,2,0)
      unify_void(1)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X72,1,1)
      unify_x_value(0)
      proceed

label(14)
      retry_me_else(16)

label(15)
      get_structure(X6765745F6E696C,1,0)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X72,1,1)
      unify_x_value(0)
      proceed

label(16)
      retry_me_else(18)

label(17)
      get_structure(X6765745F6C697374,1,0)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X72,1,1)
      unify_x_value(0)
      proceed

label(18)
      retry_me_else(20)

label(19)
      get_structure(X6765745F737472756374757265,2,0)
      unify_void(1)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X72,1,1)
      unify_x_value(0)
      proceed

label(20)
      retry_me_else(22)

label(21)
      get_structure(X7075745F785F7661726961626C65,2,0)
      unify_x_variable(2)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      get_structure(X77,1,3)
      unify_x_value(2)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X77,1,1)
      unify_x_value(0)
      proceed

label(22)
      retry_me_else(24)

label(23)
      get_structure(X7075745F785F76616C7565,2,0)
      unify_x_variable(2)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X63,2,1)
      unify_x_value(2)
      unify_x_value(0)
      proceed

label(24)
      retry_me_else(26)

label(25)
      get_structure(X7075745F795F7661726961626C65,2,0)
      unify_void(1)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X77,1,1)
      unify_x_value(0)
      proceed

label(26)
      retry_me_else(28)

label(27)
      get_structure(X7075745F795F76616C7565,2,0)
      unify_void(1)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X77,1,1)
      unify_x_value(0)
      proceed

label(28)
      retry_me_else(30)

label(29)
      get_structure(X7075745F795F756E736166655F76616C7565,2,0)
      unify_void(1)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X77,1,1)
      unify_x_value(0)
      proceed

label(30)
      retry_me_else(32)

label(31)
      get_structure(X7075745F636F6E7374616E74,2,0)
      unify_void(1)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X77,1,1)
      unify_x_value(0)
      proceed

label(32)
      retry_me_else(34)

label(33)
      get_structure(X7075745F696E7465676572,2,0)
      unify_void(1)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X77,1,1)
      unify_x_value(0)
      proceed

label(34)
      retry_me_else(36)

label(35)
      get_structure(X7075745F6E696C,1,0)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X77,1,1)
      unify_x_value(0)
      proceed

label(36)
      retry_me_else(38)

label(37)
      get_structure(X7075745F6C697374,1,0)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X77,1,1)
      unify_x_value(0)
      proceed

label(38)
      retry_me_else(40)

label(39)
      get_structure(X7075745F737472756374757265,2,0)
      unify_void(1)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X77,1,1)
      unify_x_value(0)
      proceed

label(40)
      retry_me_else(42)

label(41)
      get_structure(X756E6966795F785F7661726961626C65,1,0)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X77,1,1)
      unify_x_value(0)
      proceed

label(42)
      retry_me_else(44)

label(43)
      get_structure(X756E6966795F785F76616C7565,1,0)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X72,1,1)
      unify_x_value(0)
      proceed

label(44)
      retry_me_else(46)

label(45)
      get_structure(X756E6966795F785F6C6F63616C5F76616C7565,1,0)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X72,1,1)
      unify_x_value(0)
      proceed

label(46)
      retry_me_else(48)

label(47)
      get_structure(X63616C6C,2,0)
      unify_x_variable(0)
      unify_void(1)
      get_structure(X2F,2,0)
      unify_void(1)
      unify_x_variable(3)
      get_list(1)
      unify_x_variable(0)
      unify_x_variable(2)
      get_structure(X77,1,0)
      unify_integer(255)
      put_integer(0,0)
      put_x_value(3,1)
      execute(Pred_Name(X637265655F6C697374655F72,3),1,"cree_liste_r",3)

label(48)
      retry_me_else(50)

label(49)
      get_structure(X65786563757465,1,0)
      unify_x_variable(0)
      get_structure(X2F,2,0)
      unify_void(1)
      unify_x_variable(3)
      get_list(1)
      unify_x_variable(0)
      unify_x_variable(2)
      get_structure(X77,1,0)
      unify_integer(255)
      put_integer(0,0)
      put_x_value(3,1)
      execute(Pred_Name(X637265655F6C697374655F72,3),1,"cree_liste_r",3)

label(50)
      retry_me_else(52)

label(51)
      get_structure(X6765745F785F62635F726567,1,0)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X63,2,1)
      unify_integer(255)
      unify_x_value(0)
      proceed

label(52)
      retry_me_else(54)

label(53)
      get_structure(X6375745F78,1,0)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X72,1,1)
      unify_x_value(0)
      proceed

label(54)
      retry_me_else(56)

label(55)
      get_structure(X6D6174685F6C6F61645F785F76616C7565,2,0)
      unify_x_variable(2)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X63,2,1)
      unify_x_value(2)
      unify_x_value(0)
      proceed

label(56)
      retry_me_else(58)

label(57)
      get_structure(X6D6174685F6C6F61645F795F76616C7565,2,0)
      unify_void(1)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X77,1,1)
      unify_x_value(0)
      proceed

label(58)
      retry_me_else(60)

label(59)
      get_structure(X66756E6374696F6E5F31,3,0)
      unify_void(1)
      unify_x_variable(0)
      unify_x_variable(2)
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      get_structure(X72,1,3)
      unify_x_value(2)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X77,1,1)
      unify_x_value(0)
      proceed

label(60)
      retry_me_else(62)

label(61)
      get_structure(X66756E6374696F6E5F32,4,0)
      unify_void(1)
      unify_x_variable(0)
      unify_x_variable(3)
      unify_x_variable(2)
      get_list(1)
      unify_x_variable(4)
      unify_x_variable(1)
      get_structure(X72,1,4)
      unify_x_value(3)
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      get_structure(X72,1,3)
      unify_x_value(2)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X77,1,1)
      unify_x_value(0)
      proceed

label(62)
      retry_me_else(64)

label(63)
      get_structure(X6275696C74696E5F31,2,0)
      unify_void(1)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X72,1,1)
      unify_x_value(0)
      proceed

label(64)
      retry_me_else(66)

label(65)
      get_structure(X6275696C74696E5F32,3,0)
      unify_void(1)
      unify_x_variable(2)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      get_structure(X72,1,3)
      unify_x_value(2)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X72,1,1)
      unify_x_value(0)
      proceed

label(66)
      trust_me_else_fail

label(67)
      get_structure(X6275696C74696E5F33,4,0)
      unify_void(1)
      unify_x_variable(3)
      unify_x_variable(2)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(4)
      unify_x_variable(1)
      get_structure(X72,1,4)
      unify_x_value(3)
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      get_structure(X72,1,3)
      unify_x_value(2)
      get_list(1)
      unify_x_variable(1)
      unify_nil
      get_structure(X72,1,1)
      unify_x_value(0)
      proceed

label(68)
      trust_me_else_fail
      get_nil(1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cree_liste_r"
#define PRED       X637265655F6C697374655F72
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      get_x_value(0,1)
      get_nil(2)
      proceed

label(1)
      trust_me_else_fail
      get_list(2)
      unify_x_variable(3)
      unify_x_variable(2)
      get_structure(X72,1,3)
      unify_x_local_value(0)
      math_load_x_value(0,0)
      function_1(inc,0,0)
      execute(Pred_Name(X637265655F6C697374655F72,3),1,"cree_liste_r",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "dummy_instruction"
#define PRED       X64756D6D795F696E737472756374696F6E
#define ARITY      1

Begin_Public_Pred
      switch_on_term(G_label(2),fail,fail,fail,G_label(1))

label(1)
      switch_on_structure(1,"[(get_x_variable/2,3),(put_x_value/2,5)]")

label(2)
      try_me_else(4)

label(3)
      get_structure(X6765745F785F7661726961626C65,2,0)
      unify_x_variable(0)
      unify_x_value(0)
      proceed

label(4)
      trust_me_else_fail

label(5)
      get_structure(X7075745F785F76616C7565,2,0)
      unify_x_variable(0)
      unify_x_value(0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(wamcc5)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X616C6C6F636174696F6E5F7661727358,"allocation_varsX")
 Define_Atom(X616C6961736573,"aliases")
 Define_Atom(X616C69617365735F2461757831,"aliases_$aux1")
 Define_Atom(X616C69617365735F2461757832,"aliases_$aux2")
 Define_Atom(X63616C6C,"call")
 Define_Atom(X65786563757465,"execute")
 Define_Atom(X616C696173657331,"aliases1")
 Define_Atom(X616C6961736573315F2461757833,"aliases1_$aux3")
 Define_Atom(X72,"r")
 Define_Atom(X77,"w")
 Define_Atom(X63,"c")
 Define_Atom(X6164645F616C696173,"add_alias")
 Define_Atom(X6164645F616C6961735F2461757834,"add_alias_$aux4")
 Define_Atom(X66696E645F616C69617365735F6F66,"find_aliases_of")
 Define_Atom(X66696E645F616C69617365735F6F665F2461757835,"find_aliases_of_$aux5")
 Define_Atom(X72656D6F76655F616C69617365735F6F66,"remove_aliases_of")
 Define_Atom(X72656D6F76655F616C69617365735F6F665F2461757836,"remove_aliases_of_$aux6")
 Define_Atom(X72656D6F76655F616C69617365735F6F665F2461757837,"remove_aliases_of_$aux7")
 Define_Atom(X72656D6F76655F616C69617365735F6F665F2461757838,"remove_aliases_of_$aux8")
 Define_Atom(X6372656174655F6C73745F746D70,"create_lst_tmp")
 Define_Atom(X68616E646C655F6C73745F636F6465,"handle_lst_code")
 Define_Atom(X68616E646C655F6F6E655F636F6465,"handle_one_code")
 Define_Atom(X68616E646C655F6F6E655F636F64655F2461757839,"handle_one_code_$aux9")
 Define_Atom(X68616E646C655F6F6E655F636F64655F246175783130,"handle_one_code_$aux10")
 Define_Atom(X68616E646C655F6F6E655F636F64655F246175783131,"handle_one_code_$aux11")
 Define_Atom(X68616E646C655F6F6E655F636F64655F246175783132,"handle_one_code_$aux12")
 Define_Atom(X68616E646C655F6F6E655F636F64655F246175783133,"handle_one_code_$aux13")
 Define_Atom(X68616E646C655F6F6E655F636F64655F246175783134,"handle_one_code_$aux14")
 Define_Atom(X68616E646C655F6F6E655F636F64655F246175783135,"handle_one_code_$aux15")
 Define_Atom(X636F6E73747261696E7473,"constraints")
 Define_Atom(X636F6E73747261696E74735F246175783136,"constraints_$aux16")
 Define_Atom(X7570646174655F746D70,"update_tmp")
 Define_Atom(X746D70,"tmp")
 Define_Atom(X7570646174655F746D705F246175783137,"update_tmp_$aux17")
 Define_Atom(X72656D6F76655F746D70,"remove_tmp")
 Define_Atom(X72656D6F76655F746D705F246175783138,"remove_tmp_$aux18")
 Define_Atom(X6D616B655F696D706F7373,"make_imposs")
 Define_Atom(X6D616B655F696D706F73735F246175783139,"make_imposs_$aux19")
 Define_Atom(X61737369676E5F6C73745F746D70,"assign_lst_tmp")
 Define_Atom(X61737369676E5F776973686573,"assign_wishes")
 Define_Atom(X61737369676E5F7769736865735F246175783230,"assign_wishes_$aux20")
 Define_Atom(X636F6C6C617073655F746D7073,"collapse_tmps")
 Define_Atom(X636F6C6C617073655F746D70735F246175783231,"collapse_tmps_$aux21")
 Define_Atom(X7472795F615F7768697368,"try_a_whish")
 Define_Atom(X7472795F615F77686973685F246175783232,"try_a_whish_$aux22")
 Define_Atom(X61737369676E5F76616C756573,"assign_values")
 Define_Atom(X66696E645F686F6C65,"find_hole")
 Define_Atom(X66696E645F686F6C655F246175783233,"find_hole_$aux23")
 Define_Atom(X66696E645F686F6C655F246175783234,"find_hole_$aux24")
 Define_Atom(X636F64696669636174696F6E,"codification")
 Define_Atom(X6765745F785F7661726961626C65,"get_x_variable")
 Define_Atom(X6765745F785F76616C7565,"get_x_value")
 Define_Atom(X6765745F795F7661726961626C65,"get_y_variable")
 Define_Atom(X6765745F795F76616C7565,"get_y_value")
 Define_Atom(X6765745F636F6E7374616E74,"get_constant")
 Define_Atom(X6765745F696E7465676572,"get_integer")
 Define_Atom(X6765745F6E696C,"get_nil")
 Define_Atom(X6765745F6C697374,"get_list")
 Define_Atom(X6765745F737472756374757265,"get_structure")
 Define_Atom(X7075745F785F7661726961626C65,"put_x_variable")
 Define_Atom(X7075745F785F76616C7565,"put_x_value")
 Define_Atom(X7075745F795F7661726961626C65,"put_y_variable")
 Define_Atom(X7075745F795F76616C7565,"put_y_value")
 Define_Atom(X7075745F795F756E736166655F76616C7565,"put_y_unsafe_value")
 Define_Atom(X7075745F636F6E7374616E74,"put_constant")
 Define_Atom(X7075745F696E7465676572,"put_integer")
 Define_Atom(X7075745F6E696C,"put_nil")
 Define_Atom(X7075745F6C697374,"put_list")
 Define_Atom(X7075745F737472756374757265,"put_structure")
 Define_Atom(X756E6966795F785F7661726961626C65,"unify_x_variable")
 Define_Atom(X756E6966795F785F76616C7565,"unify_x_value")
 Define_Atom(X756E6966795F785F6C6F63616C5F76616C7565,"unify_x_local_value")
 Define_Atom(X2F,"/")
 Define_Atom(X6765745F785F62635F726567,"get_x_bc_reg")
 Define_Atom(X6375745F78,"cut_x")
 Define_Atom(X6D6174685F6C6F61645F785F76616C7565,"math_load_x_value")
 Define_Atom(X6D6174685F6C6F61645F795F76616C7565,"math_load_y_value")
 Define_Atom(X66756E6374696F6E5F31,"function_1")
 Define_Atom(X66756E6374696F6E5F32,"function_2")
 Define_Atom(X6275696C74696E5F31,"builtin_1")
 Define_Atom(X6275696C74696E5F32,"builtin_2")
 Define_Atom(X6275696C74696E5F33,"builtin_3")
 Define_Atom(X637265655F6C697374655F72,"cree_liste_r")
 Define_Atom(X64756D6D795F696E737472756374696F6E,"dummy_instruction")


 Define_Pred(X616C6C6F636174696F6E5F7661727358,1,1)

 Define_Pred(X616C6961736573,3,0)

 Define_Pred(X616C69617365735F2461757831,5,0)

 Define_Pred(X616C69617365735F2461757832,1,0)

 Define_Pred(X616C696173657331,3,0)

 Define_Pred(X616C6961736573315F2461757833,3,0)

 Define_Pred(X6164645F616C696173,4,0)

 Define_Pred(X6164645F616C6961735F2461757834,6,0)

 Define_Pred(X66696E645F616C69617365735F6F66,3,0)

 Define_Pred(X66696E645F616C69617365735F6F665F2461757835,4,0)

 Define_Pred(X72656D6F76655F616C69617365735F6F66,3,0)

 Define_Pred(X72656D6F76655F616C69617365735F6F665F2461757836,4,0)

 Define_Pred(X72656D6F76655F616C69617365735F6F665F2461757837,3,0)

 Define_Pred(X72656D6F76655F616C69617365735F6F665F2461757838,1,0)

 Define_Pred(X6372656174655F6C73745F746D70,4,0)

 Define_Pred(X68616E646C655F6C73745F636F6465,6,0)

 Define_Pred(X68616E646C655F6F6E655F636F6465,7,0)
 Define_Switch_STC_Table(Swt_Table_Name(X68616E646C655F6F6E655F636F6465,7,1,stc),3)
     Define_Switch_STC(X72,1,Label_Pred_Name(X68616E646C655F6F6E655F636F6465,7,3))
     Define_Switch_STC(X77,1,Label_Pred_Name(X68616E646C655F6F6E655F636F6465,7,5))
     Define_Switch_STC(X63,2,Label_Pred_Name(X68616E646C655F6F6E655F636F6465,7,7))

 Define_Pred(X68616E646C655F6F6E655F636F64655F2461757839,7,0)

 Define_Pred(X68616E646C655F6F6E655F636F64655F246175783130,4,0)

 Define_Pred(X68616E646C655F6F6E655F636F64655F246175783131,5,0)

 Define_Pred(X68616E646C655F6F6E655F636F64655F246175783132,7,0)

 Define_Pred(X68616E646C655F6F6E655F636F64655F246175783133,4,0)

 Define_Pred(X68616E646C655F6F6E655F636F64655F246175783134,6,0)

 Define_Pred(X68616E646C655F6F6E655F636F64655F246175783135,3,0)

 Define_Pred(X636F6E73747261696E7473,4,0)

 Define_Pred(X636F6E73747261696E74735F246175783136,4,0)

 Define_Pred(X7570646174655F746D70,5,0)

 Define_Pred(X7570646174655F746D705F246175783137,10,0)

 Define_Pred(X72656D6F76655F746D70,5,0)

 Define_Pred(X72656D6F76655F746D705F246175783138,9,0)

 Define_Pred(X6D616B655F696D706F7373,4,0)

 Define_Pred(X6D616B655F696D706F73735F246175783139,4,0)

 Define_Pred(X61737369676E5F6C73745F746D70,1,0)

 Define_Pred(X61737369676E5F776973686573,2,0)

 Define_Pred(X61737369676E5F7769736865735F246175783230,4,0)

 Define_Pred(X636F6C6C617073655F746D7073,7,0)

 Define_Pred(X636F6C6C617073655F746D70735F246175783231,3,0)

 Define_Pred(X7472795F615F7768697368,3,0)

 Define_Pred(X7472795F615F77686973685F246175783232,2,0)

 Define_Pred(X61737369676E5F76616C756573,1,0)

 Define_Pred(X66696E645F686F6C65,3,0)

 Define_Pred(X66696E645F686F6C655F246175783233,4,0)

 Define_Pred(X66696E645F686F6C655F246175783234,3,0)

 Define_Pred(X636F64696669636174696F6E,2,0)
 Define_Switch_STC_Table(Swt_Table_Name(X636F64696669636174696F6E,2,1,stc),33)
     Define_Switch_STC(X6765745F785F7661726961626C65,2,Label_Pred_Name(X636F64696669636174696F6E,2,3))
     Define_Switch_STC(X6765745F785F76616C7565,2,Label_Pred_Name(X636F64696669636174696F6E,2,5))
     Define_Switch_STC(X6765745F795F7661726961626C65,2,Label_Pred_Name(X636F64696669636174696F6E,2,7))
     Define_Switch_STC(X6765745F795F76616C7565,2,Label_Pred_Name(X636F64696669636174696F6E,2,9))
     Define_Switch_STC(X6765745F636F6E7374616E74,2,Label_Pred_Name(X636F64696669636174696F6E,2,11))
     Define_Switch_STC(X6765745F696E7465676572,2,Label_Pred_Name(X636F64696669636174696F6E,2,13))
     Define_Switch_STC(X6765745F6E696C,1,Label_Pred_Name(X636F64696669636174696F6E,2,15))
     Define_Switch_STC(X6765745F6C697374,1,Label_Pred_Name(X636F64696669636174696F6E,2,17))
     Define_Switch_STC(X6765745F737472756374757265,2,Label_Pred_Name(X636F64696669636174696F6E,2,19))
     Define_Switch_STC(X7075745F785F7661726961626C65,2,Label_Pred_Name(X636F64696669636174696F6E,2,21))
     Define_Switch_STC(X7075745F785F76616C7565,2,Label_Pred_Name(X636F64696669636174696F6E,2,23))
     Define_Switch_STC(X7075745F795F7661726961626C65,2,Label_Pred_Name(X636F64696669636174696F6E,2,25))
     Define_Switch_STC(X7075745F795F76616C7565,2,Label_Pred_Name(X636F64696669636174696F6E,2,27))
     Define_Switch_STC(X7075745F795F756E736166655F76616C7565,2,Label_Pred_Name(X636F64696669636174696F6E,2,29))
     Define_Switch_STC(X7075745F636F6E7374616E74,2,Label_Pred_Name(X636F64696669636174696F6E,2,31))
     Define_Switch_STC(X7075745F696E7465676572,2,Label_Pred_Name(X636F64696669636174696F6E,2,33))
     Define_Switch_STC(X7075745F6E696C,1,Label_Pred_Name(X636F64696669636174696F6E,2,35))
     Define_Switch_STC(X7075745F6C697374,1,Label_Pred_Name(X636F64696669636174696F6E,2,37))
     Define_Switch_STC(X7075745F737472756374757265,2,Label_Pred_Name(X636F64696669636174696F6E,2,39))
     Define_Switch_STC(X756E6966795F785F7661726961626C65,1,Label_Pred_Name(X636F64696669636174696F6E,2,41))
     Define_Switch_STC(X756E6966795F785F76616C7565,1,Label_Pred_Name(X636F64696669636174696F6E,2,43))
     Define_Switch_STC(X756E6966795F785F6C6F63616C5F76616C7565,1,Label_Pred_Name(X636F64696669636174696F6E,2,45))
     Define_Switch_STC(X63616C6C,2,Label_Pred_Name(X636F64696669636174696F6E,2,47))
     Define_Switch_STC(X65786563757465,1,Label_Pred_Name(X636F64696669636174696F6E,2,49))
     Define_Switch_STC(X6765745F785F62635F726567,1,Label_Pred_Name(X636F64696669636174696F6E,2,51))
     Define_Switch_STC(X6375745F78,1,Label_Pred_Name(X636F64696669636174696F6E,2,53))
     Define_Switch_STC(X6D6174685F6C6F61645F785F76616C7565,2,Label_Pred_Name(X636F64696669636174696F6E,2,55))
     Define_Switch_STC(X6D6174685F6C6F61645F795F76616C7565,2,Label_Pred_Name(X636F64696669636174696F6E,2,57))
     Define_Switch_STC(X66756E6374696F6E5F31,3,Label_Pred_Name(X636F64696669636174696F6E,2,59))
     Define_Switch_STC(X66756E6374696F6E5F32,4,Label_Pred_Name(X636F64696669636174696F6E,2,61))
     Define_Switch_STC(X6275696C74696E5F31,2,Label_Pred_Name(X636F64696669636174696F6E,2,63))
     Define_Switch_STC(X6275696C74696E5F32,3,Label_Pred_Name(X636F64696669636174696F6E,2,65))
     Define_Switch_STC(X6275696C74696E5F33,4,Label_Pred_Name(X636F64696669636174696F6E,2,67))

 Define_Pred(X637265655F6C697374655F72,3,0)

 Define_Pred(X64756D6D795F696E737472756374696F6E,1,1)
 Define_Switch_STC_Table(Swt_Table_Name(X64756D6D795F696E737472756374696F6E,1,1,stc),2)
     Define_Switch_STC(X6765745F785F7661726961626C65,2,Label_Pred_Name(X64756D6D795F696E737472756374696F6E,1,3))
     Define_Switch_STC(X7075745F785F76616C7565,2,Label_Pred_Name(X64756D6D795F696E737472756374696F6E,1,5))

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(wamcc5)



End_Exec_Directives
