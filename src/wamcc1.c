/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : wamcc1.c
Main : no_main
****************************************************************************/

#define FAST_MATH
#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "wamcc1.h"
#include "wamcc1.usr"


#define ASCII_PRED "sucre_syntaxique"
#define PRED       X73756372655F73796E74617869717565
#define ARITY      4

Begin_Public_Pred
      allocate(6)
      get_y_variable(4,0)
      get_y_variable(3,1)
      get_y_variable(2,2)
      get_y_variable(1,3)
      get_y_bc_reg(0)
      put_y_value(4,0)
      put_y_variable(5,1)
      call(Pred_Name(X73756372655F73796E746178697175655F2461757831,2),1,6,1,"sucre_syntaxique_$aux1",2)          /* begin sub 1 */
      put_y_value(5,2)
      put_x_variable(4,1)
      put_x_variable(5,0)
      builtin_3(functor,2,1,0)
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_value(1,3)
      call(Pred_Name(X73756372655F73796E746178697175655F2461757832,6),1,1,2,"sucre_syntaxique_$aux2",6)          /* begin sub 2 */
      cut_y(0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sucre_syntaxique_$aux2"
#define PRED       X73756372655F73796E746178697175655F2461757832
#define ARITY      6

Begin_Private_Pred
      try_me_else(1)
      allocate(5)
      get_y_variable(3,0)
      get_y_variable(0,1)
      get_y_variable(2,2)
      get_y_variable(1,3)
      get_y_bc_reg(4)
      put_constant(X64796E,0)
      put_x_value(4,1)
      put_x_value(5,2)
      call(Pred_Name(X746573745F707265645F696E666F,3),0,5,1,"test_pred_info",3)          /* begin sub 1 */
      cut_y(4)
      put_constant(X6E625F636C617573655F64796E,0)
      put_constant(X2464796E5F,1)
      put_structure(X6173736572747A,1,2)
      unify_y_local_value(3)
      put_y_value(2,3)
      call(Pred_Name(X6D616B655F7370656369616C5F636C61757365,4),0,2,2,"make_special_clause",4)          /* begin sub 2 */
      put_y_value(1,0)
      get_y_value(0,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      allocate(4)
      get_y_variable(2,1)
      get_y_variable(1,2)
      get_y_variable(0,3)
      put_y_variable(3,1)
      call(Pred_Name(X6E6F726D616C6973655F63757473,2),1,4,3,"normalise_cuts",2)          /* begin sub 3 */
      put_y_unsafe_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F616C7473,4),1,"normalise_alts",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sucre_syntaxique_$aux1"
#define PRED       X73756372655F73796E746178697175655F2461757831
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      get_structure(X3A2D,2,0)
      unify_x_local_value(1)
      unify_void(1)
      proceed

label(1)
      trust_me_else_fail
      get_x_value(1,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_cuts"
#define PRED       X6E6F726D616C6973655F63757473
#define ARITY      2

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,fail,fail,G_label(1))

label(1)
      allocate(5)
      get_structure(X3A2D,2,0)
      unify_y_variable(4)
      unify_x_variable(0)
      get_y_variable(3,1)
      put_y_variable(2,1)
      put_y_variable(1,2)
      put_y_variable(0,3)
      call(Pred_Name(X6E6F726D616C6973655F6375747331,4),1,5,1,"normalise_cuts1",4)          /* begin sub 1 */
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_unsafe_value(2,2)
      put_y_unsafe_value(1,3)
      put_y_unsafe_value(0,4)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F637574735F2461757833,5),1,"normalise_cuts_$aux3",5)

label(2)
      trust_me_else_fail
      get_x_value(0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_cuts_$aux3"
#define PRED       X6E6F726D616C6973655F637574735F2461757833
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      put_constant(X74,5)
      builtin_2(term_eq,4,5)
      neck_cut
      get_structure(X3A2D,2,1)
      unify_x_local_value(0)
      unify_x_variable(0)
      get_structure(X2C,2,0)
      unify_x_variable(0)
      unify_x_local_value(3)
      get_structure(X246765745F62635F726567,1,0)
      unify_x_local_value(2)
      proceed

label(1)
      trust_me_else_fail
      get_structure(X3A2D,2,1)
      unify_x_local_value(0)
      unify_x_local_value(3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_cuts1"
#define PRED       X6E6F726D616C6973655F6375747331
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      get_structure(X63616C6C,1,2)
      unify_x_local_value(0)
      builtin_1(var,0)
      proceed

label(1)
      retry_me_else(16)
      switch_on_term(G_label(4),G_label(15),fail,fail,G_label(2))

label(2)
      switch_on_structure(2,"[((;)/2,3),((->)/2,7),((\+)/1,9),((,)/2,11)]")

label(3)
      try(5,1)          /* begin sub 1 */
      trust(13)

label(4)
      try_me_else(6)

label(5)
      allocate(4)
      get_structure(X3B,2,0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_structure(X2D3E,2,0)
      unify_x_variable(4)
      unify_x_variable(0)
      get_y_variable(2,1)
      get_y_variable(0,3)
      get_structure(X3B,2,2)
      unify_x_variable(1)
      unify_y_variable(1)
      get_structure(X2C,2,1)
      unify_x_variable(1)
      unify_x_variable(2)
      get_structure(X246765745F62635F726567,1,1)
      unify_x_variable(1)
      get_structure(X2C,2,2)
      unify_x_value(4)
      unify_x_variable(2)
      get_structure(X2C,2,2)
      unify_x_variable(3)
      unify_x_variable(2)
      get_structure(X24637574,1,3)
      unify_x_value(1)
      put_y_value(2,1)
      put_y_value(0,3)
      call(Pred_Name(X6E6F726D616C6973655F6375747331,4),1,4,2,"normalise_cuts1",4)          /* begin sub 2 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F6375747331,4),1,"normalise_cuts1",4)

label(6)
      retry_me_else(8)

label(7)
      get_structure(X2D3E,2,0)
      unify_x_variable(5)
      unify_x_variable(0)
      get_structure(X3B,2,2)
      unify_x_variable(2)
      unify_constant(X6661696C)
      get_structure(X2C,2,2)
      unify_x_variable(4)
      unify_x_variable(2)
      get_structure(X246765745F62635F726567,1,4)
      unify_x_variable(4)
      get_structure(X2C,2,2)
      unify_x_value(5)
      unify_x_variable(2)
      get_structure(X2C,2,2)
      unify_x_variable(5)
      unify_x_variable(2)
      get_structure(X24637574,1,5)
      unify_x_value(4)
      execute(Pred_Name(X6E6F726D616C6973655F6375747331,4),1,"normalise_cuts1",4)

label(8)
      retry_me_else(10)

label(9)
      get_structure(X5C2B,1,0)
      unify_x_variable(0)
      put_structure(X2D3E,2,4)
      unify_x_value(0)
      unify_constant(X6661696C)
      put_structure(X3B,2,0)
      unify_x_value(4)
      unify_constant(X74727565)
      execute(Pred_Name(X6E6F726D616C6973655F6375747331,4),1,"normalise_cuts1",4)

label(10)
      retry_me_else(12)

label(11)
      allocate(4)
      get_structure(X2C,2,0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(2,1)
      get_structure(X2C,2,2)
      unify_x_variable(2)
      unify_y_variable(1)
      get_y_variable(0,3)
      put_y_value(2,1)
      put_y_value(0,3)
      call(Pred_Name(X6E6F726D616C6973655F6375747331,4),1,4,3,"normalise_cuts1",4)          /* begin sub 3 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F6375747331,4),1,"normalise_cuts1",4)

label(12)
      retry_me_else(14)

label(13)
      allocate(4)
      get_structure(X3B,2,0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(2,1)
      get_structure(X3B,2,2)
      unify_x_variable(2)
      unify_y_variable(1)
      get_y_variable(0,3)
      put_y_value(2,1)
      put_y_value(0,3)
      call(Pred_Name(X6E6F726D616C6973655F6375747331,4),1,4,4,"normalise_cuts1",4)          /* begin sub 4 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F6375747331,4),1,"normalise_cuts1",4)

label(14)
      trust_me_else_fail

label(15)
      get_constant(X21,0)
      get_structure(X24637574,1,2)
      unify_x_local_value(1)
      get_constant(X74,3)
      proceed

label(16)
      trust_me_else_fail
      get_x_variable(1,2)
      put_x_variable(2,5)
      put_x_variable(3,4)
      builtin_3(functor,0,5,4)
      execute(Pred_Name(X6E6F726D616C6973655F63757473315F2461757834,4),1,"normalise_cuts1_$aux4",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_cuts1_$aux4"
#define PRED       X6E6F726D616C6973655F63757473315F2461757834
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      allocate(3)
      get_y_variable(0,0)
      get_y_variable(1,1)
      get_y_bc_reg(2)
      put_constant(X64796E,0)
      put_x_value(2,1)
      put_x_value(3,2)
      call(Pred_Name(X746573745F707265645F696E666F,3),0,3,1,"test_pred_info",3)          /* begin sub 1 */
      cut_y(2)
      put_y_value(1,0)
      get_structure(X63616C6C,1,0)
      unify_y_local_value(0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      get_x_value(0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_alts"
#define PRED       X6E6F726D616C6973655F616C7473
#define ARITY      4

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,fail,fail,G_label(1))

label(1)
      allocate(3)
      get_structure(X3A2D,2,0)
      unify_x_variable(4)
      unify_x_variable(0)
      get_structure(X3A2D,2,2)
      unify_x_value(4)
      unify_y_variable(2)
      get_x_variable(5,3)
      put_x_variable(2,6)
      put_x_variable(3,3)
      builtin_3(functor,4,6,3)
      put_x_value(4,3)
      put_y_variable(1,4)
      put_y_variable(0,6)
      call(Pred_Name(X6E6F726D616C6973655F616C747331,7),1,3,1,"normalise_alts1",7)          /* begin sub 1 */
      put_constant(X6465627567,1)
      put_x_variable(3,0)
      builtin_2(g_read,1,0)
      put_y_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_unsafe_value(0,2)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F616C74735F2461757835,4),1,"normalise_alts_$aux5",4)

label(2)
      trust_me_else_fail
      get_x_value(0,2)
      get_x_value(1,3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_alts_$aux5"
#define PRED       X6E6F726D616C6973655F616C74735F2461757835
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      math_load_x_value(3,3)
      put_integer(0,2)
      builtin_2(eq,3,2)
      neck_cut
      get_x_value(1,0)
      proceed

label(1)
      trust_me_else_fail
      get_x_variable(6,2)
      put_x_variable(2,5)
      put_x_variable(3,4)
      builtin_3(functor,6,5,4)
      execute(Pred_Name(X6E6F726D616C6973655F616C74735F2461757836,4),1,"normalise_alts_$aux6",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_alts_$aux6"
#define PRED       X6E6F726D616C6973655F616C74735F2461757836
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      allocate(3)
      get_y_variable(1,0)
      get_y_variable(0,1)
      get_y_bc_reg(2)
      put_constant(X646566,0)
      put_x_value(2,1)
      put_x_value(3,2)
      call(Pred_Name(X746573745F707265645F696E666F,3),0,3,1,"test_pred_info",3)          /* begin sub 1 */
      cut_y(2)
      put_y_value(1,0)
      get_y_value(0,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      get_structure(X2C,2,0)
      unify_x_local_value(1)
      unify_constant(X246462675F74727565)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_alts1"
#define PRED       X6E6F726D616C6973655F616C747331
#define ARITY      7

Begin_Private_Pred
      try_me_else(1)
      get_structure(X63616C6C,1,4)
      unify_x_local_value(0)
      get_x_value(1,5)
      get_structure(X63616C6C,1,6)
      unify_void(1)
      builtin_1(var,0)
      proceed

label(1)
      retry_me_else(7)
      switch_on_term(G_label(3),fail,fail,fail,G_label(2))

label(2)
      switch_on_structure(2,"[((,)/2,4),((;)/2,6)]")

label(3)
      try_me_else(5)

label(4)
      allocate(8)
      get_structure(X2C,2,0)
      unify_y_variable(3)
      unify_y_variable(7)
      get_y_variable(5,2)
      get_y_variable(4,3)
      get_structure(X2C,2,4)
      unify_x_variable(4)
      unify_y_variable(2)
      get_y_variable(1,5)
      get_y_variable(0,6)
      put_y_value(3,0)
      put_y_value(5,2)
      put_structure(X2C,2,3)
      unify_y_local_value(4)
      unify_y_value(7)
      put_y_variable(6,5)
      put_x_variable(6,6)
      call(Pred_Name(X6E6F726D616C6973655F616C747331,7),1,8,1,"normalise_alts1",7)          /* begin sub 1 */
      put_y_value(7,0)
      put_y_unsafe_value(6,1)
      put_y_value(5,2)
      put_structure(X2C,2,3)
      unify_y_local_value(4)
      unify_y_value(3)
      put_y_value(2,4)
      put_y_value(1,5)
      put_y_value(0,6)
      deallocate
      execute(Pred_Name(X6E6F726D616C6973655F616C747331,7),1,"normalise_alts1",7)

label(5)
      trust_me_else_fail

label(6)
      allocate(15)
      get_structure(X3B,2,0)
      unify_y_variable(4)
      unify_y_variable(3)
      get_y_variable(1,1)
      get_y_variable(9,3)
      get_y_variable(2,4)
      get_y_variable(0,5)
      get_y_value(2,6)
      put_constant(X617578,1)
      put_y_variable(14,0)
      builtin_2(g_read,1,0)
      math_load_y_value(14,0)
      function_1(inc,0,0)
      put_constant(X617578,1)
      builtin_2(g_assign,1,0)
      put_x_value(2,0)
      put_y_variable(12,1)
      call(Pred_Name(X6E6F726D616C6973655F616C7473315F2461757837,2),1,15,2,"normalise_alts1_$aux7",2)          /* begin sub 2 */
      put_y_unsafe_value(14,0)
      put_y_variable(13,1)
      call(Pred_Name(X6E756D6265725F61746F6D,2),0,14,3,"number_atom",2)          /* begin sub 3 */
      put_constant(X24617578,0)
      put_y_unsafe_value(13,1)
      put_y_variable(10,2)
      call(Pred_Name(X61746F6D5F636F6E636174,3),0,13,4,"atom_concat",3)          /* begin sub 4 */
      put_y_unsafe_value(12,0)
      put_constant(X5F,1)
      put_y_variable(11,2)
      call(Pred_Name(X61746F6D5F636F6E636174,3),0,12,5,"atom_concat",3)          /* begin sub 5 */
      put_y_unsafe_value(11,0)
      put_y_unsafe_value(10,1)
      put_y_variable(6,2)
      call(Pred_Name(X61746F6D5F636F6E636174,3),0,10,6,"atom_concat",3)          /* begin sub 6 */
      put_y_value(9,0)
      put_nil(1)
      put_y_variable(8,2)
      call(Pred_Name(X6C73745F766172,3),1,9,7,"lst_var",3)          /* begin sub 7 */
      put_structure(X3B,2,0)
      unify_y_value(4)
      unify_y_value(3)
      put_nil(1)
      put_y_variable(7,2)
      call(Pred_Name(X6C73745F766172,3),1,9,8,"lst_var",3)          /* begin sub 8 */
      put_y_unsafe_value(8,0)
      put_y_unsafe_value(7,1)
      put_y_variable(5,2)
      call(Pred_Name(X656E735F696E746572,3),0,7,9,"ens_inter",3)          /* begin sub 9 */
      put_y_value(2,1)
      put_list(0)
      unify_y_local_value(6)
      unify_y_local_value(5)
      builtin_2(term_univ,1,0)
      put_y_value(2,4)
      put_x_variable(1,3)
      put_x_variable(2,0)
      builtin_3(functor,4,3,0)
      put_constant(X646566,0)
      call(Pred_Name(X7365745F707265645F696E666F,3),0,5,10,"set_pred_info",3)          /* begin sub 10 */
      put_structure(X3B,2,0)
      unify_y_value(4)
      unify_y_value(3)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X6C696E656172697365,4),1,"linearise",4)

label(7)
      trust_me_else_fail
      get_x_value(0,4)
      get_x_value(1,5)
      get_x_value(0,6)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "normalise_alts1_$aux7"
#define PRED       X6E6F726D616C6973655F616C7473315F2461757837
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      allocate(4)
      get_y_variable(1,0)
      get_y_variable(0,1)
      get_y_bc_reg(3)
      put_y_value(1,0)
      put_y_variable(2,1)
      put_integer(5,2)
      put_constant(X5F24617578,3)
      call(Pred_Name(X7375625F61746F6D,4),0,4,1,"sub_atom",4)          /* begin sub 1 */
      cut_y(3)
      math_load_y_value(2,0)
      function_1(dec,2,0)
      put_y_value(1,0)
      put_integer(1,1)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X7375625F61746F6D,4),0,"sub_atom",4)

label(1)
      trust_me_else_fail
      get_x_value(0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "linearise"
#define PRED       X6C696E656172697365
#define ARITY      4

Begin_Private_Pred
      execute(Pred_Name(X6C696E6561726973655F2461757838,4),1,"linearise_$aux8",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "linearise_$aux8"
#define PRED       X6C696E6561726973655F2461757838
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      allocate(4)
      get_y_variable(2,1)
      get_y_variable(0,3)
      get_structure(X3B,2,0)
      unify_y_variable(3)
      unify_x_variable(0)
      neck_cut
      put_y_value(2,1)
      put_y_variable(1,3)
      call(Pred_Name(X6C696E656172697365,4),1,4,1,"linearise",4)          /* begin sub 1 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_unsafe_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X6C696E65617269736531,4),1,"linearise1",4)

label(1)
      trust_me_else_fail
      execute(Pred_Name(X6C696E65617269736531,4),1,"linearise1",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "linearise1"
#define PRED       X6C696E65617269736531
#define ARITY      4

Begin_Private_Pred
      execute(Pred_Name(X6C696E656172697365315F2461757839,4),1,"linearise1_$aux9",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "linearise1_$aux9"
#define PRED       X6C696E656172697365315F2461757839
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      put_constant(X6661696C,1)
      builtin_2(term_eq,0,1)
      neck_cut
      get_x_value(2,3)
      proceed

label(1)
      trust_me_else_fail
      allocate(3)
      get_x_variable(4,0)
      get_y_variable(0,2)
      get_y_variable(2,3)
      put_structure(X3A2D,2,0)
      unify_x_local_value(1)
      unify_x_local_value(4)
      put_y_variable(1,1)
      call(Pred_Name(X636F70795F7465726D,2),0,3,1,"copy_term",2)          /* begin sub 1 */
      put_y_value(2,0)
      get_list(0)
      unify_y_local_value(1)
      unify_y_local_value(0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "lst_var"
#define PRED       X6C73745F766172
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      get_x_variable(3,0)
      builtin_1(var,3)
      neck_cut
      put_x_value(1,0)
      put_x_value(3,1)
      execute(Pred_Name(X656E735F616A6F7574,3),0,"ens_ajout",3)

label(1)
      trust_me_else_fail
      get_x_variable(5,0)
      get_x_variable(3,1)
      get_x_variable(4,2)
      put_x_variable(0,2)
      put_x_variable(1,0)
      builtin_3(functor,5,2,0)
      put_integer(1,0)
      put_x_value(5,2)
      execute(Pred_Name(X6C73745F7661725F61726773,5),1,"lst_var_args",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "lst_var_args"
#define PRED       X6C73745F7661725F61726773
#define ARITY      5

Begin_Private_Pred
      execute(Pred_Name(X6C73745F7661725F617267735F246175783130,5),1,"lst_var_args_$aux10",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "lst_var_args_$aux10"
#define PRED       X6C73745F7661725F617267735F246175783130
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      allocate(5)
      get_y_variable(4,0)
      get_y_variable(3,1)
      get_y_variable(2,2)
      get_y_variable(0,4)
      math_load_y_value(4,1)
      math_load_y_value(3,0)
      builtin_2(lte,1,0)
      neck_cut
      put_y_value(4,4)
      put_y_value(2,2)
      put_x_variable(0,1)
      builtin_3(arg,4,2,1)
      put_x_value(3,1)
      put_y_variable(1,2)
      call(Pred_Name(X6C73745F766172,3),1,5,1,"lst_var",3)          /* begin sub 1 */
      math_load_y_value(4,0)
      function_1(inc,0,0)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_unsafe_value(1,3)
      put_y_value(0,4)
      deallocate
      execute(Pred_Name(X6C73745F7661725F61726773,5),1,"lst_var_args",5)

label(1)
      trust_me_else_fail
      get_x_value(3,4)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(wamcc1)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X73756372655F73796E74617869717565,"sucre_syntaxique")
 Define_Atom(X73756372655F73796E746178697175655F2461757832,"sucre_syntaxique_$aux2")
 Define_Atom(X64796E,"dyn")
 Define_Atom(X6E625F636C617573655F64796E,"nb_clause_dyn")
 Define_Atom(X2464796E5F,"$dyn_")
 Define_Atom(X6173736572747A,"assertz")
 Define_Atom(X73756372655F73796E746178697175655F2461757831,"sucre_syntaxique_$aux1")
 Define_Atom(X3A2D,":-")
 Define_Atom(X6E6F726D616C6973655F63757473,"normalise_cuts")
 Define_Atom(X6E6F726D616C6973655F637574735F2461757833,"normalise_cuts_$aux3")
 Define_Atom(X74,"t")
 Define_Atom(X2C,",")
 Define_Atom(X246765745F62635F726567,"$get_bc_reg")
 Define_Atom(X6E6F726D616C6973655F6375747331,"normalise_cuts1")
 Define_Atom(X63616C6C,"call")
 Define_Atom(X3B,";")
 Define_Atom(X2D3E,"->")
 Define_Atom(X24637574,"$cut")
 Define_Atom(X6661696C,"fail")
 Define_Atom(X5C2B,"\\+")
 Define_Atom(X74727565,"true")
 Define_Atom(X21,"!")
 Define_Atom(X6E6F726D616C6973655F63757473315F2461757834,"normalise_cuts1_$aux4")
 Define_Atom(X6E6F726D616C6973655F616C7473,"normalise_alts")
 Define_Atom(X6465627567,"debug")
 Define_Atom(X6E6F726D616C6973655F616C74735F2461757835,"normalise_alts_$aux5")
 Define_Atom(X6E6F726D616C6973655F616C74735F2461757836,"normalise_alts_$aux6")
 Define_Atom(X646566,"def")
 Define_Atom(X246462675F74727565,"$dbg_true")
 Define_Atom(X6E6F726D616C6973655F616C747331,"normalise_alts1")
 Define_Atom(X617578,"aux")
 Define_Atom(X24617578,"$aux")
 Define_Atom(X5F,"_")
 Define_Atom(X6E6F726D616C6973655F616C7473315F2461757837,"normalise_alts1_$aux7")
 Define_Atom(X5F24617578,"_$aux")
 Define_Atom(X6C696E656172697365,"linearise")
 Define_Atom(X6C696E6561726973655F2461757838,"linearise_$aux8")
 Define_Atom(X6C696E65617269736531,"linearise1")
 Define_Atom(X6C696E656172697365315F2461757839,"linearise1_$aux9")
 Define_Atom(X6C73745F766172,"lst_var")
 Define_Atom(X6C73745F7661725F61726773,"lst_var_args")
 Define_Atom(X6C73745F7661725F617267735F246175783130,"lst_var_args_$aux10")


 Define_Pred(X73756372655F73796E74617869717565,4,1)

 Define_Pred(X73756372655F73796E746178697175655F2461757832,6,0)

 Define_Pred(X73756372655F73796E746178697175655F2461757831,2,0)

 Define_Pred(X6E6F726D616C6973655F63757473,2,0)

 Define_Pred(X6E6F726D616C6973655F637574735F2461757833,5,0)

 Define_Pred(X6E6F726D616C6973655F6375747331,4,0)
 Define_Switch_STC_Table(Swt_Table_Name(X6E6F726D616C6973655F6375747331,4,2,stc),4)
     Define_Switch_STC(X3B,2,Label_Pred_Name(X6E6F726D616C6973655F6375747331,4,3))
     Define_Switch_STC(X2D3E,2,Label_Pred_Name(X6E6F726D616C6973655F6375747331,4,7))
     Define_Switch_STC(X5C2B,1,Label_Pred_Name(X6E6F726D616C6973655F6375747331,4,9))
     Define_Switch_STC(X2C,2,Label_Pred_Name(X6E6F726D616C6973655F6375747331,4,11))

 Define_Pred(X6E6F726D616C6973655F63757473315F2461757834,4,0)

 Define_Pred(X6E6F726D616C6973655F616C7473,4,0)

 Define_Pred(X6E6F726D616C6973655F616C74735F2461757835,4,0)

 Define_Pred(X6E6F726D616C6973655F616C74735F2461757836,4,0)

 Define_Pred(X6E6F726D616C6973655F616C747331,7,0)
 Define_Switch_STC_Table(Swt_Table_Name(X6E6F726D616C6973655F616C747331,7,2,stc),2)
     Define_Switch_STC(X2C,2,Label_Pred_Name(X6E6F726D616C6973655F616C747331,7,4))
     Define_Switch_STC(X3B,2,Label_Pred_Name(X6E6F726D616C6973655F616C747331,7,6))

 Define_Pred(X6E6F726D616C6973655F616C7473315F2461757837,2,0)

 Define_Pred(X6C696E656172697365,4,0)

 Define_Pred(X6C696E6561726973655F2461757838,4,0)

 Define_Pred(X6C696E65617269736531,4,0)

 Define_Pred(X6C696E656172697365315F2461757839,4,0)

 Define_Pred(X6C73745F766172,3,0)

 Define_Pred(X6C73745F7661725F61726773,5,0)

 Define_Pred(X6C73745F7661725F617267735F246175783130,5,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(wamcc1)



End_Exec_Directives
