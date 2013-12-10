/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : wamcc0.c
Main : no_main
****************************************************************************/

#define FAST_MATH
#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "wamcc0.h"
#include "wamcc0.usr"


#define ASCII_PRED "lire_fichier"
#define PRED       X6C6972655F66696368696572
#define ARITY      2

Begin_Public_Pred
      allocate(5)
      get_y_variable(2,0)
      get_y_variable(1,1)
      get_y_bc_reg(0)
      put_constant(X66696C655F6E62,2)
      put_x_variable(0,1)
      builtin_2(g_read,2,1)
      math_load_x_value(0,0)
      function_1(inc,0,0)
      put_constant(X66696C655F6E62,1)
      builtin_2(g_assign,1,0)
      put_constant(X6669635F696E,2)
      put_x_variable(0,1)
      builtin_2(g_read,2,1)
      put_constant(X6E625F636C617573655F657865,2)
      put_integer(0,1)
      builtin_2(g_assign,2,1)
      put_constant(X6E625F636C617573655F64796E,2)
      put_integer(0,1)
      builtin_2(g_assign,2,1)
      call(Pred_Name(X736565,1),0,5,1,"see",1)          /* begin sub 1 */
      put_y_variable(4,0)
      put_structure(X73696E676C65746F6E73,1,3)
      unify_y_variable(3)
      put_structure(X73796E7461785F6572726F7273,1,1)
      unify_constant(X6661696C)
      put_list(2)
      unify_x_value(1)
      unify_nil
      put_list(1)
      unify_x_value(3)
      unify_x_value(2)
      call(Pred_Name(X726561645F7465726D,2),0,5,2,"read_term",2)          /* begin sub 2 */
      put_y_unsafe_value(4,0)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_value(1,3)
      call(Pred_Name(X6C6972655F636C6175736573,4),1,1,3,"lire_clauses",4)          /* begin sub 3 */
      cut_y(0)
      deallocate
      execute(Pred_Name(X7365656E,0),0,"seen",0)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "lire_clauses"
#define PRED       X6C6972655F636C6175736573
#define ARITY      4

Begin_Private_Pred
      try_me_else(11)
      switch_on_term(G_label(3),G_label(4),fail,fail,G_label(1))

label(1)
      switch_on_structure(1,"[((:-)/1,2)]")

label(2)
      try(6,1)          /* begin sub 1 */
      retry(8,2)          /* begin sub 2 */
      trust(10)

label(3)
      try_me_else(5)

label(4)
      get_constant(X656E645F6F665F66696C65,0)
      neck_cut
      put_x_value(2,0)
      put_x_value(3,1)
      execute(Pred_Name(X6C6972655F636C61757365735F2461757831,2),1,"lire_clauses_$aux1",2)

label(5)
      retry_me_else(7)

label(6)
      allocate(5)
      get_structure(X3A2D,1,0)
      unify_x_variable(0)
      get_structure(X7075626C6963,1,0)
      unify_y_variable(0)
      get_y_variable(2,2)
      get_y_variable(1,3)
      neck_cut
      put_y_variable(4,0)
      put_structure(X73696E676C65746F6E73,1,3)
      unify_y_variable(3)
      put_structure(X73796E7461785F6572726F7273,1,1)
      unify_constant(X6661696C)
      put_list(2)
      unify_x_value(1)
      unify_nil
      put_list(1)
      unify_x_value(3)
      unify_x_value(2)
      call(Pred_Name(X726561645F7465726D,2),0,5,3,"read_term",2)          /* begin sub 3 */
      put_y_unsafe_value(4,0)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_value(1,3)
      call(Pred_Name(X6C6972655F636C6175736573,4),1,1,4,"lire_clauses",4)          /* begin sub 4 */
      put_y_value(0,0)
      put_constant(X707562,1)
      deallocate
      execute(Pred_Name(X6465665F666C61675F666F725F7072656473,2),1,"def_flag_for_preds",2)

label(7)
      retry_me_else(9)

label(8)
      allocate(5)
      get_structure(X3A2D,1,0)
      unify_x_variable(0)
      get_structure(X64796E616D6963,1,0)
      unify_y_variable(0)
      get_y_variable(2,2)
      get_y_variable(1,3)
      neck_cut
      put_y_variable(4,0)
      put_structure(X73696E676C65746F6E73,1,3)
      unify_y_variable(3)
      put_structure(X73796E7461785F6572726F7273,1,1)
      unify_constant(X6661696C)
      put_list(2)
      unify_x_value(1)
      unify_nil
      put_list(1)
      unify_x_value(3)
      unify_x_value(2)
      call(Pred_Name(X726561645F7465726D,2),0,5,5,"read_term",2)          /* begin sub 5 */
      put_y_unsafe_value(4,0)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_value(1,3)
      call(Pred_Name(X6C6972655F636C6175736573,4),1,1,6,"lire_clauses",4)          /* begin sub 6 */
      put_y_value(0,0)
      put_constant(X64796E,1)
      deallocate
      execute(Pred_Name(X6465665F666C61675F666F725F7072656473,2),1,"def_flag_for_preds",2)

label(9)
      trust_me_else_fail

label(10)
      allocate(4)
      get_structure(X3A2D,1,0)
      unify_x_variable(0)
      get_y_variable(0,3)
      neck_cut
      put_x_value(2,1)
      put_y_value(0,2)
      put_y_variable(1,3)
      call(Pred_Name(X6C6972655F636C61757365735F2461757832,4),1,4,7,"lire_clauses_$aux2",4)          /* begin sub 7 */
      put_y_variable(3,0)
      put_structure(X73696E676C65746F6E73,1,3)
      unify_y_variable(2)
      put_structure(X73796E7461785F6572726F7273,1,1)
      unify_constant(X6661696C)
      put_list(2)
      unify_x_value(1)
      unify_nil
      put_list(1)
      unify_x_value(3)
      unify_x_value(2)
      call(Pred_Name(X726561645F7465726D,2),0,4,8,"read_term",2)          /* begin sub 8 */
      put_y_unsafe_value(3,0)
      put_y_value(2,1)
      put_y_unsafe_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X6C6972655F636C6175736573,4),1,"lire_clauses",4)

label(11)
      trust_me_else_fail
      allocate(10)
      get_y_variable(7,1)
      get_list(2)
      unify_x_local_value(0)
      unify_y_variable(1)
      get_y_variable(0,3)
      get_y_bc_reg(8)
      put_y_variable(9,1)
      call(Pred_Name(X6C6972655F636C61757365735F2461757833,2),1,10,9,"lire_clauses_$aux3",2)          /* begin sub 9 */
      put_y_value(9,2)
      put_y_variable(6,1)
      put_y_variable(5,0)
      builtin_3(functor,2,1,0)
      cut_y(8)
      put_constant(X646566,0)
      put_y_value(6,1)
      put_y_value(5,2)
      call(Pred_Name(X7365745F707265645F696E666F,3),1,8,10,"set_pred_info",3)          /* begin sub 10 */
      put_y_value(7,0)
      put_y_variable(4,1)
      call(Pred_Name(X6765745F73696E676C65746F6E73,2),1,7,11,"get_singletons",2)          /* begin sub 11 */
      put_y_unsafe_value(6,0)
      put_y_unsafe_value(5,1)
      put_y_unsafe_value(4,2)
      call(Pred_Name(X6C6972655F636C61757365735F2461757834,3),1,4,12,"lire_clauses_$aux4",3)          /* begin sub 12 */
      put_y_variable(3,0)
      put_structure(X73696E676C65746F6E73,1,3)
      unify_y_variable(2)
      put_structure(X73796E7461785F6572726F7273,1,1)
      unify_constant(X6661696C)
      put_list(2)
      unify_x_value(1)
      unify_nil
      put_list(1)
      unify_x_value(3)
      unify_x_value(2)
      call(Pred_Name(X726561645F7465726D,2),0,4,13,"read_term",2)          /* begin sub 13 */
      put_y_unsafe_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X6C6972655F636C6175736573,4),1,"lire_clauses",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "lire_clauses_$aux1"
#define PRED       X6C6972655F636C61757365735F2461757831
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      builtin_1(var,1)
      neck_cut
      get_constant(X6E6F5F6D61696E,1)
      get_nil(0)
      proceed

label(1)
      trust_me_else_fail
      allocate(2)
      get_y_variable(1,0)
      put_constant(X6E625F636C617573655F657865,0)
      put_constant(X246578655F,1)
      put_structure(X746F705F6C6576656C,2,2)
      unify_constant(X74727565)
      unify_constant(X74727565)
      put_y_variable(0,3)
      call(Pred_Name(X6D616B655F7370656369616C5F636C61757365,4),1,2,1,"make_special_clause",4)          /* begin sub 1 */
      put_y_value(1,0)
      get_list(0)
      unify_y_local_value(0)
      unify_nil
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "lire_clauses_$aux2"
#define PRED       X6C6972655F636C61757365735F2461757832
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      put_constant(X6D61696E,5)
      put_x_variable(4,4)
      builtin_3(functor,0,5,4)
      neck_cut
      get_x_value(0,2)
      get_x_value(3,1)
      proceed

label(1)
      trust_me_else_fail
      allocate(4)
      get_y_variable(3,0)
      get_y_variable(2,1)
      get_y_variable(0,3)
      put_y_value(3,0)
      call(Pred_Name(X7472616974655F6F70,1),1,4,1,"traite_op",1)          /* begin sub 1 */
      put_constant(X6E625F636C617573655F657865,0)
      put_constant(X246578655F,1)
      put_structure(X2C,2,2)
      unify_y_local_value(3)
      unify_constant(X21)
      put_y_variable(1,3)
      call(Pred_Name(X6D616B655F7370656369616C5F636C61757365,4),1,3,2,"make_special_clause",4)          /* begin sub 2 */
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



#define ASCII_PRED "lire_clauses_$aux4"
#define PRED       X6C6972655F636C61757365735F2461757834
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      get_x_variable(5,0)
      put_nil(0)
      builtin_2(term_neq,2,0)
      neck_cut
      put_constant(X7B5761726E696E673A207E77202D2073696E676C65746F6E207661726961626C657320696E207E612F7E647D7E6E,0)
      put_list(4)
      unify_x_local_value(1)
      unify_nil
      put_list(3)
      unify_x_local_value(5)
      unify_x_value(4)
      put_list(1)
      unify_x_local_value(2)
      unify_x_value(3)
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "lire_clauses_$aux3"
#define PRED       X6C6972655F636C61757365735F2461757833
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



#define ASCII_PRED "traite_op"
#define PRED       X7472616974655F6F70
#define ARITY      1

Begin_Private_Pred
      try_me_else(6)
      switch_on_term(G_label(2),fail,fail,fail,G_label(1))

label(1)
      switch_on_structure(1,"[((,)/2,3),(op/3,5)]")

label(2)
      try_me_else(4)

label(3)
      allocate(1)
      get_structure(X2C,2,0)
      unify_x_variable(0)
      unify_y_variable(0)
      call(Pred_Name(X7472616974655F6F70,1),1,1,1,"traite_op",1)          /* begin sub 1 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X7472616974655F6F70,1),1,"traite_op",1)

label(4)
      trust_me_else_fail

label(5)
      get_structure(X6F70,3,0)
      unify_x_variable(0)
      unify_x_variable(1)
      unify_x_variable(2)
      execute(Pred_Name(X6F70,3),0,"op",3)

label(6)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "get_singletons"
#define PRED       X6765745F73696E676C65746F6E73
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
      allocate(2)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(1)
      get_structure(X3D,2,0)
      unify_x_variable(0)
      unify_void(1)
      put_y_variable(0,2)
      call(Pred_Name(X6765745F73696E676C65746F6E735F2461757835,3),1,2,1,"get_singletons_$aux5",3)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X6765745F73696E676C65746F6E73,2),1,"get_singletons",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "get_singletons_$aux5"
#define PRED       X6765745F73696E676C65746F6E735F2461757835
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      allocate(3)
      get_y_variable(1,1)
      get_y_variable(0,2)
      get_y_bc_reg(2)
      put_integer(1,1)
      put_integer(1,2)
      put_constant(X5F,3)
      call(Pred_Name(X7375625F61746F6D,4),0,3,1,"sub_atom",4)          /* begin sub 1 */
      cut_y(2)
      put_y_value(1,0)
      get_y_value(0,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      get_list(1)
      unify_x_local_value(0)
      unify_x_local_value(2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "def_flag_for_preds"
#define PRED       X6465665F666C61675F666F725F7072656473
#define ARITY      2

Begin_Private_Pred
      switch_on_term(G_label(2),fail,fail,fail,G_label(1))

label(1)
      switch_on_structure(1,"[((,)/2,3),(/ /2,5)]")

label(2)
      try_me_else(4)

label(3)
      allocate(2)
      get_structure(X2C,2,0)
      unify_x_variable(0)
      unify_y_variable(1)
      get_y_variable(0,1)
      put_y_value(0,1)
      call(Pred_Name(X6465665F666C61675F666F725F7072656473,2),1,2,1,"def_flag_for_preds",2)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X6465665F666C61675F666F725F7072656473,2),1,"def_flag_for_preds",2)

label(4)
      trust_me_else_fail

label(5)
      get_structure(X2F,2,0)
      unify_x_variable(3)
      unify_x_variable(2)
      put_x_value(1,0)
      put_x_value(3,1)
      execute(Pred_Name(X7365745F707265645F696E666F,3),1,"set_pred_info",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "make_special_clause"
#define PRED       X6D616B655F7370656369616C5F636C61757365
#define ARITY      4

Begin_Public_Pred
      get_x_variable(4,0)
      get_x_variable(0,1)
      get_x_variable(1,2)
      get_structure(X3A2D,2,3)
      unify_x_variable(2)
      unify_x_local_value(1)
      put_x_variable(1,3)
      builtin_2(g_read,4,3)
      math_load_x_value(1,1)
      function_1(inc,1,1)
      builtin_2(g_assign,4,1)
      execute(Pred_Name(X6D616B655F7370656369616C5F636C617573655F68656164,3),1,"make_special_clause_head",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "make_special_clause_head"
#define PRED       X6D616B655F7370656369616C5F636C617573655F68656164
#define ARITY      3

Begin_Public_Pred
      allocate(3)
      get_y_variable(2,0)
      get_y_variable(0,2)
      put_x_value(1,0)
      put_y_variable(1,1)
      call(Pred_Name(X6E756D6265725F61746F6D,2),0,3,1,"number_atom",2)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X61746F6D5F636F6E636174,3),0,"atom_concat",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "pred_name_to_gvar_name"
#define PRED       X707265645F6E616D655F746F5F677661725F6E616D65
#define ARITY      3

Begin_Public_Pred
      allocate(4)
      get_y_variable(3,0)
      get_y_variable(0,2)
      put_x_value(1,0)
      put_y_variable(1,1)
      call(Pred_Name(X6E756D6265725F61746F6D,2),0,4,1,"number_atom",2)          /* begin sub 1 */
      put_y_value(3,0)
      put_constant(X2F,1)
      put_y_variable(2,2)
      call(Pred_Name(X61746F6D5F636F6E636174,3),0,3,2,"atom_concat",3)          /* begin sub 2 */
      put_y_unsafe_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X61746F6D5F636F6E636174,3),0,"atom_concat",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "set_pred_info"
#define PRED       X7365745F707265645F696E666F
#define ARITY      3

Begin_Public_Pred
      allocate(3)
      get_y_variable(2,1)
      get_y_variable(1,2)
      put_y_variable(0,1)
      call(Pred_Name(X666C61675F626974,2),1,3,1,"flag_bit",2)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_unsafe_value(0,2)
      deallocate
      execute(Pred_Name(X7365745F626974,3),1,"set_bit",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "flag_bit"
#define PRED       X666C61675F626974
#define ARITY      2

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(1),fail,fail,fail)

label(1)
      switch_on_constant(1,"[(def,3),(pub,5),(dyn,7)]")

label(2)
      try_me_else(4)

label(3)
      get_constant(X646566,0)
      get_integer(16,1)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_constant(X707562,0)
      get_integer(17,1)
      proceed

label(6)
      trust_me_else_fail

label(7)
      get_constant(X64796E,0)
      get_integer(18,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "set_bit"
#define PRED       X7365745F626974
#define ARITY      3

Begin_Private_Pred
      allocate(3)
      get_y_variable(2,2)
      put_y_variable(1,2)
      call(Pred_Name(X707265645F6E616D655F746F5F677661725F6E616D65,3),1,3,1,"pred_name_to_gvar_name",3)          /* begin sub 1 */
      put_y_value(1,2)
      put_x_variable(1,0)
      builtin_2(g_read,2,0)
      put_constant(X66696C655F6E62,3)
      put_x_variable(2,0)
      builtin_2(g_read,3,0)
      put_y_value(2,0)
      put_y_variable(0,3)
      call(Pred_Name(X7365745F6269745F2461757836,4),1,2,2,"set_bit_$aux6",4)          /* begin sub 2 */
      put_y_value(1,1)
      put_y_value(0,0)
      builtin_2(g_assign,1,0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "set_bit_$aux6"
#define PRED       X7365745F6269745F2461757836
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      math_load_x_value(2,2)
      math_load_x_value(1,1)
      put_integer(65535,4)
      function_2(and,4,1,4)
      builtin_2(eq,2,4)
      neck_cut
      put_integer(1,2)
      math_load_x_value(0,0)
      function_2(shl,0,2,0)
      math_load_x_value(1,1)
      function_2(or,0,0,1)
      get_x_value(3,0)
      proceed

label(1)
      trust_me_else_fail
      put_integer(1,1)
      math_load_x_value(0,0)
      function_2(shl,0,1,0)
      math_load_x_value(2,2)
      function_2(or,0,0,2)
      get_x_value(3,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "test_pred_info"
#define PRED       X746573745F707265645F696E666F
#define ARITY      3

Begin_Public_Pred
      allocate(3)
      get_y_variable(2,1)
      get_y_variable(1,2)
      put_y_variable(0,1)
      call(Pred_Name(X666C61675F626974,2),1,3,1,"flag_bit",2)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_unsafe_value(0,2)
      deallocate
      execute(Pred_Name(X746573745F626974,3),1,"test_bit",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "test_bit"
#define PRED       X746573745F626974
#define ARITY      3

Begin_Private_Pred
      allocate(2)
      get_y_variable(0,2)
      put_y_variable(1,2)
      call(Pred_Name(X707265645F6E616D655F746F5F677661725F6E616D65,3),1,2,1,"pred_name_to_gvar_name",3)          /* begin sub 1 */
      put_y_value(1,2)
      put_x_variable(1,0)
      builtin_2(g_read,2,0)
      put_constant(X66696C655F6E62,3)
      put_x_variable(2,0)
      builtin_2(g_read,3,0)
      math_load_x_value(2,2)
      math_load_x_value(1,1)
      put_integer(65535,0)
      function_2(and,0,1,0)
      builtin_2(eq,2,0)
      math_load_x_value(1,1)
      put_integer(1,2)
      math_load_y_value(0,0)
      function_2(shl,0,2,0)
      function_2(and,1,1,0)
      put_integer(0,0)
      builtin_2(gt,1,0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(wamcc0)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X6C6972655F66696368696572,"lire_fichier")
 Define_Atom(X66696C655F6E62,"file_nb")
 Define_Atom(X6669635F696E,"fic_in")
 Define_Atom(X6E625F636C617573655F657865,"nb_clause_exe")
 Define_Atom(X6E625F636C617573655F64796E,"nb_clause_dyn")
 Define_Atom(X73696E676C65746F6E73,"singletons")
 Define_Atom(X73796E7461785F6572726F7273,"syntax_errors")
 Define_Atom(X6661696C,"fail")
 Define_Atom(X6C6972655F636C6175736573,"lire_clauses")
 Define_Atom(X656E645F6F665F66696C65,"end_of_file")
 Define_Atom(X3A2D,":-")
 Define_Atom(X7075626C6963,"public")
 Define_Atom(X707562,"pub")
 Define_Atom(X64796E616D6963,"dynamic")
 Define_Atom(X64796E,"dyn")
 Define_Atom(X646566,"def")
 Define_Atom(X6C6972655F636C61757365735F2461757831,"lire_clauses_$aux1")
 Define_Atom(X6E6F5F6D61696E,"no_main")
 Define_Atom(X246578655F,"$exe_")
 Define_Atom(X746F705F6C6576656C,"top_level")
 Define_Atom(X74727565,"true")
 Define_Atom(X6C6972655F636C61757365735F2461757832,"lire_clauses_$aux2")
 Define_Atom(X6D61696E,"main")
 Define_Atom(X2C,",")
 Define_Atom(X21,"!")
 Define_Atom(X6C6972655F636C61757365735F2461757834,"lire_clauses_$aux4")
 Define_Atom(X7B5761726E696E673A207E77202D2073696E676C65746F6E207661726961626C657320696E207E612F7E647D7E6E,"{Warning: ~w - singleton variables in ~a/~d}~n")
 Define_Atom(X6C6972655F636C61757365735F2461757833,"lire_clauses_$aux3")
 Define_Atom(X7472616974655F6F70,"traite_op")
 Define_Atom(X6F70,"op")
 Define_Atom(X6765745F73696E676C65746F6E73,"get_singletons")
 Define_Atom(X3D,"=")
 Define_Atom(X6765745F73696E676C65746F6E735F2461757835,"get_singletons_$aux5")
 Define_Atom(X5F,"_")
 Define_Atom(X6465665F666C61675F666F725F7072656473,"def_flag_for_preds")
 Define_Atom(X2F,"/")
 Define_Atom(X6D616B655F7370656369616C5F636C61757365,"make_special_clause")
 Define_Atom(X6D616B655F7370656369616C5F636C617573655F68656164,"make_special_clause_head")
 Define_Atom(X707265645F6E616D655F746F5F677661725F6E616D65,"pred_name_to_gvar_name")
 Define_Atom(X7365745F707265645F696E666F,"set_pred_info")
 Define_Atom(X666C61675F626974,"flag_bit")
 Define_Atom(X7365745F626974,"set_bit")
 Define_Atom(X7365745F6269745F2461757836,"set_bit_$aux6")
 Define_Atom(X746573745F707265645F696E666F,"test_pred_info")
 Define_Atom(X746573745F626974,"test_bit")


 Define_Pred(X6C6972655F66696368696572,2,1)

 Define_Pred(X6C6972655F636C6175736573,4,0)
 Define_Switch_STC_Table(Swt_Table_Name(X6C6972655F636C6175736573,4,1,stc),1)
     Define_Switch_STC(X3A2D,1,Label_Pred_Name(X6C6972655F636C6175736573,4,2))

 Define_Pred(X6C6972655F636C61757365735F2461757831,2,0)

 Define_Pred(X6C6972655F636C61757365735F2461757832,4,0)

 Define_Pred(X6C6972655F636C61757365735F2461757834,3,0)

 Define_Pred(X6C6972655F636C61757365735F2461757833,2,0)

 Define_Pred(X7472616974655F6F70,1,0)
 Define_Switch_STC_Table(Swt_Table_Name(X7472616974655F6F70,1,1,stc),2)
     Define_Switch_STC(X2C,2,Label_Pred_Name(X7472616974655F6F70,1,3))
     Define_Switch_STC(X6F70,3,Label_Pred_Name(X7472616974655F6F70,1,5))

 Define_Pred(X6765745F73696E676C65746F6E73,2,0)

 Define_Pred(X6765745F73696E676C65746F6E735F2461757835,3,0)

 Define_Pred(X6465665F666C61675F666F725F7072656473,2,0)
 Define_Switch_STC_Table(Swt_Table_Name(X6465665F666C61675F666F725F7072656473,2,1,stc),2)
     Define_Switch_STC(X2C,2,Label_Pred_Name(X6465665F666C61675F666F725F7072656473,2,3))
     Define_Switch_STC(X2F,2,Label_Pred_Name(X6465665F666C61675F666F725F7072656473,2,5))

 Define_Pred(X6D616B655F7370656369616C5F636C61757365,4,1)

 Define_Pred(X6D616B655F7370656369616C5F636C617573655F68656164,3,1)

 Define_Pred(X707265645F6E616D655F746F5F677661725F6E616D65,3,1)

 Define_Pred(X7365745F707265645F696E666F,3,1)

 Define_Pred(X666C61675F626974,2,0)
 Define_Switch_CST_Table(Swt_Table_Name(X666C61675F626974,2,1,cst),3)
     Define_Switch_CST(X646566,Label_Pred_Name(X666C61675F626974,2,3))
     Define_Switch_CST(X707562,Label_Pred_Name(X666C61675F626974,2,5))
     Define_Switch_CST(X64796E,Label_Pred_Name(X666C61675F626974,2,7))

 Define_Pred(X7365745F626974,3,0)

 Define_Pred(X7365745F6269745F2461757836,4,0)

 Define_Pred(X746573745F707265645F696E666F,3,1)

 Define_Pred(X746573745F626974,3,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(wamcc0)



End_Exec_Directives
