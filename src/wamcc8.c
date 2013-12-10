/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : wamcc8.c
Main : no_main
****************************************************************************/

#define FAST_MATH
#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "wamcc8.h"
#include "wamcc8.usr"


#define ASCII_PRED "c_emission"
#define PRED       X635F656D697373696F6E
#define ARITY      2

Begin_Public_Pred
      allocate(4)
      get_y_bc_reg(3)
      put_y_variable(2,2)
      put_y_variable(1,3)
      put_y_variable(0,4)
      call(Pred_Name(X635F656D69745F6669635F63,5),1,4,1,"c_emit_fic_c",5)          /* begin sub 1 */
      cut_y(3)
      put_y_unsafe_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_unsafe_value(0,2)
      call(Pred_Name(X635F656D69745F6669635F68,3),1,0,2,"c_emit_fic_h",3)          /* begin sub 2 */
      put_constant(X6669635F757372,2)
      put_x_variable(0,1)
      builtin_2(g_read,2,1)
      deallocate
      execute(Pred_Name(X635F656D69745F6669635F757372,1),1,"c_emit_fic_usr",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_fic_c"
#define PRED       X635F656D69745F6669635F63
#define ARITY      5

Begin_Private_Pred
      allocate(7)
      get_y_variable(4,0)
      get_y_variable(0,1)
      get_y_variable(3,2)
      get_y_variable(2,3)
      get_y_variable(1,4)
      put_constant(X6669635F6F7574,1)
      put_y_variable(6,0)
      builtin_2(g_read,1,0)
      put_constant(X6D6F64756C65,1)
      put_y_variable(5,0)
      builtin_2(g_read,1,0)
      put_y_value(6,0)
      call(Pred_Name(X74656C6C,1),0,7,1,"tell",1)          /* begin sub 1 */
      put_constant(X2F2A7E2A637E6E,0)
      put_list(2)
      unify_integer(42)
      unify_nil
      put_list(1)
      unify_integer(75)
      unify_x_value(2)
      call(Pred_Name(X666F726D617461,2),0,7,2,"formata",2)          /* begin sub 2 */
      call(Pred_Name(X646973706C61795F76657273696F6E,0),0,7,3,"display_version",0)          /* begin sub 3 */
      put_constant(X46696C65203A207E617E6E,0)
      put_list(1)
      unify_y_local_value(6)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,6,4,"formata",2)          /* begin sub 4 */
      put_constant(X4D61696E203A207E777E6E,0)
      put_list(1)
      unify_y_local_value(0)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,6,5,"formata",2)          /* begin sub 5 */
      put_constant(X7E2A632A2F7E6E7E6E,0)
      put_list(2)
      unify_integer(42)
      unify_nil
      put_list(1)
      unify_integer(75)
      unify_x_value(2)
      call(Pred_Name(X666F726D617461,2),0,6,6,"formata",2)          /* begin sub 6 */
      call(Pred_Name(X635F656D69745F6669635F635F2461757831,0),1,6,7,"c_emit_fic_c_$aux1",0)          /* begin sub 7 */
      put_constant(X6465627567,1)
      put_x_variable(2,0)
      builtin_2(g_read,1,0)
      put_constant(X23646566696E652044454255475F4C4556454C202020207E647E6E,0)
      put_list(1)
      unify_x_value(2)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,6,8,"formata",2)          /* begin sub 8 */
      call(Pred_Name(X6E6C,0),0,6,9,"nl",0)          /* begin sub 9 */
      put_constant(X23696E636C756465202277616D5F656E67696E652E68227E6E7E6E,0)
      put_nil(1)
      call(Pred_Name(X666F726D617461,2),0,6,10,"formata",2)          /* begin sub 10 */
      put_constant(X23696E636C75646520227E612E68227E6E,0)
      put_list(1)
      unify_y_local_value(5)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,6,11,"formata",2)          /* begin sub 11 */
      put_constant(X23696E636C75646520227E612E75737222,0)
      put_list(1)
      unify_y_local_value(5)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,5,12,"formata",2)          /* begin sub 12 */
      put_y_value(3,0)
      put_nil(1)
      call(Pred_Name(X6164645F746F5F6469635F61746F6D,2),1,5,13,"add_to_dic_atom",2)          /* begin sub 13 */
      put_y_value(4,0)
      put_y_value(3,1)
      put_y_value(2,2)
      call(Pred_Name(X635F656D69745F6C73745F70726564,3),1,4,14,"c_emit_lst_pred",3)          /* begin sub 14 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      call(Pred_Name(X635F656D69745F6663745F696E69745F7461626C6573,3),1,1,15,"c_emit_fct_init_tables",3)          /* begin sub 15 */
      call(Pred_Name(X635F656D69745F6663745F657865635F64697265637469766573,0),1,1,16,"c_emit_fct_exec_directives",0)          /* begin sub 16 */
      put_y_value(0,0)
      call(Pred_Name(X635F656D69745F6669635F635F2461757832,1),1,0,17,"c_emit_fic_c_$aux2",1)          /* begin sub 17 */
      deallocate
      execute(Pred_Name(X746F6C64,0),0,"told",0)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_fic_c_$aux2"
#define PRED       X635F656D69745F6669635F635F2461757832
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      put_constant(X6E6F5F6D61696E,1)
      builtin_2(term_neq,0,1)
      neck_cut
      execute(Pred_Name(X635F656D69745F6663745F6D61696E,1),1,"c_emit_fct_main",1)

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_fic_c_$aux1"
#define PRED       X635F656D69745F6669635F635F2461757831
#define ARITY      0

Begin_Private_Pred
      try_me_else(1)
      put_constant(X666173745F6D617468,1)
      put_constant(X74,0)
      builtin_2(g_read,1,0)
      neck_cut
      put_constant(X23646566696E6520464153545F4D4154487E6E,0)
      put_nil(1)
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_lst_pred"
#define PRED       X635F656D69745F6C73745F70726564
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
      allocate(8)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_structure(X706171,2,0)
      unify_x_variable(0)
      unify_y_variable(4)
      get_structure(X2F,2,0)
      unify_y_variable(6)
      unify_y_variable(5)
      get_y_variable(1,1)
      get_y_variable(7,2)
      get_y_bc_reg(3)
      put_y_value(1,0)
      put_y_value(6,1)
      call(Pred_Name(X6164645F746F5F6469635F61746F6D,2),1,8,1,"add_to_dic_atom",2)          /* begin sub 1 */
      put_y_value(7,0)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(0)
      get_structure(X70,3,0)
      unify_x_variable(0)
      unify_x_variable(2)
      unify_x_variable(3)
      get_structure(X2F,2,0)
      unify_y_value(6)
      unify_y_value(5)
      put_y_value(6,0)
      put_y_value(5,1)
      put_y_value(4,4)
      put_y_value(1,5)
      call(Pred_Name(X635F656D69745F70726564,6),1,4,2,"c_emit_pred",6)          /* begin sub 2 */
      cut_y(3)
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X635F656D69745F6C73745F70726564,3),1,"c_emit_lst_pred",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_pred"
#define PRED       X635F656D69745F70726564
#define ARITY      6

Begin_Private_Pred
      allocate(7)
      get_y_variable(5,0)
      get_y_variable(4,1)
      get_y_variable(1,2)
      get_y_variable(0,3)
      get_y_variable(3,4)
      get_y_variable(2,5)
      neck_cut
      call(Pred_Name(X6E6C,0),0,7,1,"nl",0)          /* begin sub 1 */
      call(Pred_Name(X6E6C,0),0,7,2,"nl",0)          /* begin sub 2 */
      call(Pred_Name(X6E6C,0),0,7,3,"nl",0)          /* begin sub 3 */
      put_y_value(5,0)
      put_y_variable(6,1)
      call(Pred_Name(X635F737472696E67,2),1,7,4,"c_string",2)          /* begin sub 4 */
      put_constant(X23646566696E652041534349495F5052454420,0)
      call(Pred_Name(X7772697465,1),0,7,5,"write",1)          /* begin sub 5 */
      put_y_unsafe_value(6,0)
      call(Pred_Name(X7772697465,1),0,6,6,"write",1)          /* begin sub 6 */
      call(Pred_Name(X6E6C,0),0,6,7,"nl",0)          /* begin sub 7 */
      put_constant(X23646566696E65205052454420202020202020,0)
      call(Pred_Name(X7772697465,1),0,6,8,"write",1)          /* begin sub 8 */
      put_y_value(5,0)
      call(Pred_Name(X685F7772697465,1),1,6,9,"h_write",1)          /* begin sub 9 */
      call(Pred_Name(X6E6C,0),0,6,10,"nl",0)          /* begin sub 10 */
      put_constant(X23646566696E65204152495459202020202020,0)
      call(Pred_Name(X7772697465,1),0,6,11,"write",1)          /* begin sub 11 */
      put_y_value(4,0)
      call(Pred_Name(X7772697465,1),0,6,12,"write",1)          /* begin sub 12 */
      call(Pred_Name(X6E6C,0),0,6,13,"nl",0)          /* begin sub 13 */
      call(Pred_Name(X6E6C,0),0,6,14,"nl",0)          /* begin sub 14 */
      put_y_value(5,0)
      put_y_value(4,1)
      call(Pred_Name(X635F656D69745F707265645F2461757833,2),1,4,15,"c_emit_pred_$aux3",2)          /* begin sub 15 */
      call(Pred_Name(X6E6C,0),0,4,16,"nl",0)          /* begin sub 16 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_integer(1,2)
      put_x_variable(3,3)
      put_y_value(1,4)
      put_y_value(0,5)
      call(Pred_Name(X635F656D6974,6),1,0,17,"c_emit",6)          /* begin sub 17 */
      call(Pred_Name(X6E6C,0),0,0,18,"nl",0)          /* begin sub 18 */
      put_constant(X456E645F50726564,0)
      call(Pred_Name(X7772697465,1),0,0,19,"write",1)          /* begin sub 19 */
      call(Pred_Name(X6E6C,0),0,0,20,"nl",0)          /* begin sub 20 */
      call(Pred_Name(X6E6C,0),0,0,21,"nl",0)          /* begin sub 21 */
      put_constant(X23756E6465662041534349495F50524544,0)
      call(Pred_Name(X7772697465,1),0,0,22,"write",1)          /* begin sub 22 */
      call(Pred_Name(X6E6C,0),0,0,23,"nl",0)          /* begin sub 23 */
      put_constant(X23756E6465662050524544,0)
      call(Pred_Name(X7772697465,1),0,0,24,"write",1)          /* begin sub 24 */
      call(Pred_Name(X6E6C,0),0,0,25,"nl",0)          /* begin sub 25 */
      put_constant(X23756E646566204152495459,0)
      call(Pred_Name(X7772697465,1),0,0,26,"write",1)          /* begin sub 26 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_pred_$aux3"
#define PRED       X635F656D69745F707265645F2461757833
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      allocate(1)
      get_x_variable(3,0)
      get_x_variable(2,1)
      get_y_bc_reg(0)
      put_constant(X707562,0)
      put_x_value(3,1)
      call(Pred_Name(X746573745F707265645F696E666F,3),0,1,1,"test_pred_info",3)          /* begin sub 1 */
      cut_y(0)
      put_constant(X426567696E5F5075626C69635F50726564,0)
      deallocate
      execute(Pred_Name(X7772697465,1),0,"write",1)

label(1)
      trust_me_else_fail
      put_constant(X426567696E5F507269766174655F50726564,0)
      execute(Pred_Name(X7772697465,1),0,"write",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit"
#define PRED       X635F656D6974
#define ARITY      6

Begin_Private_Pred
      try_me_else(5)
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_x_value(2,3)
      get_nil(4)
      get_nil(5)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(13)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(10)
      get_y_variable(9,1)
      get_y_variable(11,2)
      get_y_variable(7,3)
      get_y_variable(3,4)
      get_y_variable(0,5)
      get_y_bc_reg(6)
      put_y_variable(12,1)
      call(Pred_Name(X635F656D69745F2461757834,2),1,13,1,"c_emit_$aux4",2)          /* begin sub 1 */
      cut_y(6)
      put_y_unsafe_value(12,0)
      put_y_value(9,1)
      put_y_value(11,2)
      put_y_variable(8,3)
      put_y_variable(5,4)
      put_y_variable(2,5)
      call(Pred_Name(X635F656D6974,6),1,11,2,"c_emit",6)          /* begin sub 2 */
      put_y_value(10,0)
      put_y_value(9,1)
      put_y_unsafe_value(8,2)
      put_y_value(7,3)
      put_y_variable(4,4)
      put_y_variable(1,5)
      call(Pred_Name(X635F656D6974,6),1,7,3,"c_emit",6)          /* begin sub 3 */
      cut_y(6)
      put_y_unsafe_value(5,0)
      put_y_unsafe_value(4,1)
      put_y_value(3,2)
      call(Pred_Name(X617070656E64,3),0,3,4,"append",3)          /* begin sub 4 */
      put_y_unsafe_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X617070656E64,3),0,"append",3)

label(5)
      retry_me_else(6)
      get_x_value(2,3)
      get_nil(4)
      get_nil(5)
      execute(Pred_Name(X64756D6D795F696E737472756374696F6E,1),0,"dummy_instruction",1)

label(6)
      retry_me_else(36)
      switch_on_term(G_label(8),fail,fail,fail,G_label(7))

label(7)
      switch_on_structure(7,"[(get_constant/2,9),(put_constant/2,11),(get_structure/2,13),(put_structure/2,15),(unify_constant/1,17),(call/2,19),(execute/1,21),(switch_on_term/5,23),(switch_on_constant/3,25),(switch_on_integer/3,27),(switch_on_structure/3,29),(try/1,31),(retry/1,33),(label/1,35)]")

label(8)
      try_me_else(10)

label(9)
      allocate(2)
      get_structure(X6765745F636F6E7374616E74,2,0)
      unify_y_variable(1)
      unify_y_variable(0)
      get_x_value(2,3)
      get_nil(4)
      get_nil(5)
      put_x_value(1,0)
      put_y_value(1,1)
      call(Pred_Name(X6164645F746F5F6469635F61746F6D,2),1,2,5,"add_to_dic_atom",2)          /* begin sub 5 */
      put_integer(6,0)
      call(Pred_Name(X746162,1),0,2,6,"tab",1)          /* begin sub 6 */
      put_constant(X6765745F636F6E7374616E7428,0)
      call(Pred_Name(X7772697465,1),0,2,7,"write",1)          /* begin sub 7 */
      put_y_value(1,0)
      call(Pred_Name(X685F7772697465,1),1,1,8,"h_write",1)          /* begin sub 8 */
      put_constant(X2C7E64297E6E,0)
      put_list(1)
      unify_y_value(0)
      unify_nil
      deallocate
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

label(10)
      retry_me_else(12)

label(11)
      allocate(2)
      get_structure(X7075745F636F6E7374616E74,2,0)
      unify_y_variable(1)
      unify_y_variable(0)
      get_x_value(2,3)
      get_nil(4)
      get_nil(5)
      put_x_value(1,0)
      put_y_value(1,1)
      call(Pred_Name(X6164645F746F5F6469635F61746F6D,2),1,2,9,"add_to_dic_atom",2)          /* begin sub 9 */
      put_integer(6,0)
      call(Pred_Name(X746162,1),0,2,10,"tab",1)          /* begin sub 10 */
      put_constant(X7075745F636F6E7374616E7428,0)
      call(Pred_Name(X7772697465,1),0,2,11,"write",1)          /* begin sub 11 */
      put_y_value(1,0)
      call(Pred_Name(X685F7772697465,1),1,1,12,"h_write",1)          /* begin sub 12 */
      put_constant(X2C7E64297E6E,0)
      put_list(1)
      unify_y_value(0)
      unify_nil
      deallocate
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

label(12)
      retry_me_else(14)

label(13)
      allocate(3)
      get_structure(X6765745F737472756374757265,2,0)
      unify_x_variable(0)
      unify_y_variable(0)
      get_structure(X2F,2,0)
      unify_y_variable(2)
      unify_y_variable(1)
      get_x_value(2,3)
      get_nil(4)
      get_nil(5)
      put_x_value(1,0)
      put_y_value(2,1)
      call(Pred_Name(X6164645F746F5F6469635F61746F6D,2),1,3,13,"add_to_dic_atom",2)          /* begin sub 13 */
      put_integer(6,0)
      call(Pred_Name(X746162,1),0,3,14,"tab",1)          /* begin sub 14 */
      put_constant(X6765745F73747275637475726528,0)
      call(Pred_Name(X7772697465,1),0,3,15,"write",1)          /* begin sub 15 */
      put_y_value(2,0)
      call(Pred_Name(X685F7772697465,1),1,2,16,"h_write",1)          /* begin sub 16 */
      put_constant(X2C7E642C7E64297E6E,0)
      put_list(2)
      unify_y_value(0)
      unify_nil
      put_list(1)
      unify_y_value(1)
      unify_x_value(2)
      deallocate
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

label(14)
      retry_me_else(16)

label(15)
      allocate(3)
      get_structure(X7075745F737472756374757265,2,0)
      unify_x_variable(0)
      unify_y_variable(0)
      get_structure(X2F,2,0)
      unify_y_variable(2)
      unify_y_variable(1)
      get_x_value(2,3)
      get_nil(4)
      get_nil(5)
      put_x_value(1,0)
      put_y_value(2,1)
      call(Pred_Name(X6164645F746F5F6469635F61746F6D,2),1,3,17,"add_to_dic_atom",2)          /* begin sub 17 */
      put_integer(6,0)
      call(Pred_Name(X746162,1),0,3,18,"tab",1)          /* begin sub 18 */
      put_constant(X7075745F73747275637475726528,0)
      call(Pred_Name(X7772697465,1),0,3,19,"write",1)          /* begin sub 19 */
      put_y_value(2,0)
      call(Pred_Name(X685F7772697465,1),1,2,20,"h_write",1)          /* begin sub 20 */
      put_constant(X2C7E642C7E64297E6E,0)
      put_list(2)
      unify_y_value(0)
      unify_nil
      put_list(1)
      unify_y_value(1)
      unify_x_value(2)
      deallocate
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

label(16)
      retry_me_else(18)

label(17)
      allocate(1)
      get_structure(X756E6966795F636F6E7374616E74,1,0)
      unify_y_variable(0)
      get_x_value(2,3)
      get_nil(4)
      get_nil(5)
      put_x_value(1,0)
      put_y_value(0,1)
      call(Pred_Name(X6164645F746F5F6469635F61746F6D,2),1,1,21,"add_to_dic_atom",2)          /* begin sub 21 */
      put_integer(6,0)
      call(Pred_Name(X746162,1),0,1,22,"tab",1)          /* begin sub 22 */
      put_constant(X756E6966795F636F6E7374616E7428,0)
      call(Pred_Name(X7772697465,1),0,1,23,"write",1)          /* begin sub 23 */
      put_y_value(0,0)
      call(Pred_Name(X685F7772697465,1),1,0,24,"h_write",1)          /* begin sub 24 */
      put_constant(X29,0)
      call(Pred_Name(X7772697465,1),0,0,25,"write",1)          /* begin sub 25 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

label(18)
      retry_me_else(20)

label(19)
      allocate(7)
      get_structure(X63616C6C,2,0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_structure(X2F,2,0)
      unify_y_variable(5)
      unify_y_variable(1)
      get_y_variable(0,2)
      get_y_variable(6,3)
      get_nil(4)
      get_nil(5)
      put_y_value(5,0)
      put_y_value(1,1)
      put_y_variable(4,2)
      call(Pred_Name(X635F656D69745F2461757835,3),1,7,26,"c_emit_$aux5",3)          /* begin sub 26 */
      math_load_y_value(0,0)
      function_1(inc,0,0)
      get_y_value(6,0)
      put_y_value(5,0)
      put_y_variable(2,1)
      call(Pred_Name(X635F737472696E67,2),1,6,27,"c_string",2)          /* begin sub 27 */
      put_integer(6,0)
      call(Pred_Name(X746162,1),0,6,28,"tab",1)          /* begin sub 28 */
      put_constant(X63616C6C28,0)
      call(Pred_Name(X7772697465,1),0,6,29,"write",1)          /* begin sub 29 */
      put_y_value(5,0)
      put_y_value(1,1)
      call(Pred_Name(X77726974655F707265645F6E616D65,2),1,5,30,"write_pred_name",2)          /* begin sub 30 */
      put_constant(X2C7E642C7E642C7E642C7E612C7E6429,0)
      put_list(1)
      unify_y_value(1)
      unify_nil
      put_list(2)
      unify_y_local_value(2)
      unify_x_value(1)
      put_list(1)
      unify_y_local_value(0)
      unify_x_value(2)
      put_list(2)
      unify_y_value(3)
      unify_x_value(1)
      put_list(1)
      unify_y_local_value(4)
      unify_x_value(2)
      call(Pred_Name(X666F726D617461,2),0,1,31,"formata",2)          /* begin sub 31 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X635F656D69745F6865616465725F7375625F70726564,1),1,"c_emit_header_sub_pred",1)

label(20)
      retry_me_else(22)

label(21)
      allocate(4)
      get_structure(X65786563757465,1,0)
      unify_x_variable(0)
      get_structure(X2F,2,0)
      unify_y_variable(3)
      unify_y_variable(0)
      get_x_value(2,3)
      get_nil(4)
      get_nil(5)
      put_y_value(3,0)
      put_y_value(0,1)
      put_y_variable(2,2)
      call(Pred_Name(X635F656D69745F2461757836,3),1,4,32,"c_emit_$aux6",3)          /* begin sub 32 */
      put_y_value(3,0)
      put_y_variable(1,1)
      call(Pred_Name(X635F737472696E67,2),1,4,33,"c_string",2)          /* begin sub 33 */
      put_integer(6,0)
      call(Pred_Name(X746162,1),0,4,34,"tab",1)          /* begin sub 34 */
      put_constant(X6578656375746528,0)
      call(Pred_Name(X7772697465,1),0,4,35,"write",1)          /* begin sub 35 */
      put_y_value(3,0)
      put_y_value(0,1)
      call(Pred_Name(X77726974655F707265645F6E616D65,2),1,3,36,"write_pred_name",2)          /* begin sub 36 */
      put_constant(X2C7E642C7E612C7E64297E6E,0)
      put_list(1)
      unify_y_value(0)
      unify_nil
      put_list(2)
      unify_y_local_value(1)
      unify_x_value(1)
      put_list(1)
      unify_y_local_value(2)
      unify_x_value(2)
      deallocate
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

label(22)
      retry_me_else(24)

label(23)
      allocate(5)
      get_structure(X7377697463685F6F6E5F7465726D,5,0)
      unify_y_variable(4)
      unify_y_variable(3)
      unify_y_variable(2)
      unify_y_variable(1)
      unify_y_variable(0)
      get_x_value(2,3)
      get_nil(4)
      get_nil(5)
      put_integer(6,0)
      call(Pred_Name(X746162,1),0,5,37,"tab",1)          /* begin sub 37 */
      put_constant(X7377697463685F6F6E5F7465726D28,0)
      call(Pred_Name(X7772697465,1),0,5,38,"write",1)          /* begin sub 38 */
      put_y_value(4,0)
      call(Pred_Name(X635F656D69745F676F746F5F6F725F6661696C,1),1,4,39,"c_emit_goto_or_fail",1)          /* begin sub 39 */
      put_constant(X2C,0)
      call(Pred_Name(X7772697465,1),0,4,40,"write",1)          /* begin sub 40 */
      put_y_value(3,0)
      call(Pred_Name(X635F656D69745F676F746F5F6F725F6661696C,1),1,3,41,"c_emit_goto_or_fail",1)          /* begin sub 41 */
      put_constant(X2C,0)
      call(Pred_Name(X7772697465,1),0,3,42,"write",1)          /* begin sub 42 */
      put_y_value(2,0)
      call(Pred_Name(X635F656D69745F676F746F5F6F725F6661696C,1),1,2,43,"c_emit_goto_or_fail",1)          /* begin sub 43 */
      put_constant(X2C,0)
      call(Pred_Name(X7772697465,1),0,2,44,"write",1)          /* begin sub 44 */
      put_y_value(1,0)
      call(Pred_Name(X635F656D69745F676F746F5F6F725F6661696C,1),1,1,45,"c_emit_goto_or_fail",1)          /* begin sub 45 */
      put_constant(X2C,0)
      call(Pred_Name(X7772697465,1),0,1,46,"write",1)          /* begin sub 46 */
      put_y_value(0,0)
      call(Pred_Name(X635F656D69745F676F746F5F6F725F6661696C,1),1,0,47,"c_emit_goto_or_fail",1)          /* begin sub 47 */
      put_constant(X29,0)
      call(Pred_Name(X7772697465,1),0,0,48,"write",1)          /* begin sub 48 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

label(24)
      retry_me_else(26)

label(25)
      allocate(2)
      get_structure(X7377697463685F6F6E5F636F6E7374616E74,3,0)
      unify_y_variable(1)
      unify_x_variable(0)
      unify_y_variable(0)
      get_x_value(2,3)
      get_list(4)
      unify_x_variable(1)
      unify_nil
      get_structure(X63,3,1)
      unify_y_value(1)
      unify_x_value(0)
      unify_y_value(0)
      get_nil(5)
      put_integer(6,0)
      call(Pred_Name(X746162,1),0,2,49,"tab",1)          /* begin sub 49 */
      put_constant(X7377697463685F6F6E5F636F6E7374616E7428,0)
      call(Pred_Name(X7772697465,1),0,2,50,"write",1)          /* begin sub 50 */
      put_constant(X7E642C227E7722297E6E,0)
      put_list(2)
      unify_y_value(0)
      unify_nil
      put_list(1)
      unify_y_value(1)
      unify_x_value(2)
      deallocate
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

label(26)
      retry_me_else(28)

label(27)
      allocate(1)
      get_structure(X7377697463685F6F6E5F696E7465676572,3,0)
      unify_void(2)
      unify_y_variable(0)
      get_x_value(2,3)
      get_nil(4)
      get_nil(5)
      put_integer(6,0)
      call(Pred_Name(X746162,1),0,1,51,"tab",1)          /* begin sub 51 */
      put_constant(X7377697463685F6F6E5F696E7465676572286C737428,0)
      call(Pred_Name(X7772697465,1),0,1,52,"write",1)          /* begin sub 52 */
      put_y_value(0,0)
      call(Pred_Name(X635F656D69745F7377745F696E74,1),1,1,53,"c_emit_swt_int",1)          /* begin sub 53 */
      put_constant(X292C227E7722297E6E,0)
      put_list(1)
      unify_y_value(0)
      unify_nil
      deallocate
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

label(28)
      retry_me_else(30)

label(29)
      allocate(2)
      get_structure(X7377697463685F6F6E5F737472756374757265,3,0)
      unify_y_variable(1)
      unify_x_variable(0)
      unify_y_variable(0)
      get_x_value(2,3)
      get_nil(4)
      get_list(5)
      unify_x_variable(1)
      unify_nil
      get_structure(X73,3,1)
      unify_y_value(1)
      unify_x_value(0)
      unify_y_value(0)
      put_integer(6,0)
      call(Pred_Name(X746162,1),0,2,54,"tab",1)          /* begin sub 54 */
      put_constant(X7377697463685F6F6E5F73747275637475726528,0)
      call(Pred_Name(X7772697465,1),0,2,55,"write",1)          /* begin sub 55 */
      put_constant(X7E642C227E7722297E6E,0)
      put_list(2)
      unify_y_value(0)
      unify_nil
      put_list(1)
      unify_y_value(1)
      unify_x_value(2)
      deallocate
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

label(30)
      retry_me_else(32)

label(31)
      allocate(2)
      get_structure(X747279,1,0)
      unify_y_variable(1)
      get_y_variable(0,2)
      get_nil(4)
      get_nil(5)
      math_load_y_value(0,0)
      function_1(inc,0,0)
      get_x_value(3,0)
      put_integer(6,0)
      call(Pred_Name(X746162,1),0,2,56,"tab",1)          /* begin sub 56 */
      put_structure(X747279,2,0)
      unify_y_value(1)
      unify_y_local_value(0)
      call(Pred_Name(X7772697465,1),0,1,57,"write",1)          /* begin sub 57 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X635F656D69745F6865616465725F7375625F70726564,1),1,"c_emit_header_sub_pred",1)

label(32)
      retry_me_else(34)

label(33)
      allocate(2)
      get_structure(X7265747279,1,0)
      unify_y_variable(1)
      get_y_variable(0,2)
      get_nil(4)
      get_nil(5)
      math_load_y_value(0,0)
      function_1(inc,0,0)
      get_x_value(3,0)
      put_integer(6,0)
      call(Pred_Name(X746162,1),0,2,58,"tab",1)          /* begin sub 58 */
      put_structure(X7265747279,2,0)
      unify_y_value(1)
      unify_y_local_value(0)
      call(Pred_Name(X7772697465,1),0,1,59,"write",1)          /* begin sub 59 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X635F656D69745F6865616465725F7375625F70726564,1),1,"c_emit_header_sub_pred",1)

label(34)
      trust_me_else_fail

label(35)
      get_structure(X6C6162656C,1,0)
      unify_x_variable(0)
      get_x_value(2,3)
      get_nil(4)
      get_nil(5)
      execute(Pred_Name(X635F656D69745F2461757838,1),1,"c_emit_$aux8",1)

label(36)
      trust_me_else_fail
      allocate(1)
      get_y_variable(0,0)
      get_x_value(2,3)
      get_nil(4)
      get_nil(5)
      put_integer(6,0)
      call(Pred_Name(X746162,1),0,1,60,"tab",1)          /* begin sub 60 */
      put_y_value(0,0)
      call(Pred_Name(X7772697465,1),0,0,61,"write",1)          /* begin sub 61 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_$aux4"
#define PRED       X635F656D69745F2461757834
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      execute(Pred_Name(X7370656369616C5F666F726D,2),0,"special_form",2)

label(1)
      trust_me_else_fail
      get_x_value(0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_$aux5"
#define PRED       X635F656D69745F2461757835
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      allocate(2)
      get_x_variable(4,0)
      get_x_variable(3,1)
      get_y_variable(0,2)
      get_y_bc_reg(1)
      put_constant(X646566,0)
      put_x_value(4,1)
      put_x_value(3,2)
      call(Pred_Name(X746573745F707265645F696E666F,3),0,2,1,"test_pred_info",3)          /* begin sub 1 */
      cut_y(1)
      put_y_value(0,0)
      get_integer(1,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      get_integer(0,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_$aux6"
#define PRED       X635F656D69745F2461757836
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      allocate(2)
      get_x_variable(4,0)
      get_x_variable(3,1)
      get_y_variable(0,2)
      get_y_bc_reg(1)
      put_constant(X646566,0)
      put_x_value(4,1)
      put_x_value(3,2)
      call(Pred_Name(X746573745F707265645F696E666F,3),0,2,1,"test_pred_info",3)          /* begin sub 1 */
      cut_y(1)
      put_y_value(0,0)
      get_integer(1,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      get_integer(0,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_goto_or_fail"
#define PRED       X635F656D69745F676F746F5F6F725F6661696C
#define ARITY      1

Begin_Private_Pred
      execute(Pred_Name(X635F656D69745F676F746F5F6F725F6661696C5F2461757837,1),1,"c_emit_goto_or_fail_$aux7",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_goto_or_fail_$aux7"
#define PRED       X635F656D69745F676F746F5F6F725F6661696C5F2461757837
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      put_constant(X6661696C,1)
      builtin_2(term_eq,0,1)
      neck_cut
      put_constant(X6661696C,0)
      execute(Pred_Name(X7772697465,1),0,"write",1)

label(1)
      trust_me_else_fail
      get_x_variable(1,0)
      put_structure(X475F6C6162656C,1,0)
      unify_x_local_value(1)
      execute(Pred_Name(X7772697465,1),0,"write",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_swt_int"
#define PRED       X635F656D69745F7377745F696E74
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
      allocate(1)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(0)
      get_structure(X2C,2,0)
      unify_x_variable(2)
      unify_x_variable(1)
      put_structure(X69,2,0)
      unify_x_value(2)
      unify_x_value(1)
      call(Pred_Name(X7772697465,1),0,1,1,"write",1)          /* begin sub 1 */
      put_constant(X20,0)
      call(Pred_Name(X7772697465,1),0,1,2,"write",1)          /* begin sub 2 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X635F656D69745F7377745F696E74,1),1,"c_emit_swt_int",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_$aux8"
#define PRED       X635F656D69745F2461757838
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      get_integer(0,0)
      neck_cut
      proceed

label(1)
      trust_me_else_fail
      allocate(1)
      get_y_variable(0,0)
      call(Pred_Name(X6E6C,0),0,1,1,"nl",0)          /* begin sub 1 */
      put_structure(X6C6162656C,1,0)
      unify_y_local_value(0)
      call(Pred_Name(X7772697465,1),0,0,2,"write",1)          /* begin sub 2 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_header_sub_pred"
#define PRED       X635F656D69745F6865616465725F7375625F70726564
#define ARITY      1

Begin_Private_Pred
      get_x_variable(2,0)
      put_constant(X202020202020202020202F2A20626567696E20737562207E64202A2F7E6E,0)
      put_list(1)
      unify_x_local_value(2)
      unify_nil
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_fct_init_tables"
#define PRED       X635F656D69745F6663745F696E69745F7461626C6573
#define ARITY      3

Begin_Private_Pred
      allocate(4)
      get_y_variable(2,0)
      get_y_variable(1,1)
      get_y_variable(0,2)
      put_constant(X6D6F64756C65,1)
      put_y_variable(3,0)
      builtin_2(g_read,1,0)
      call(Pred_Name(X6E6C,0),0,4,1,"nl",0)          /* begin sub 1 */
      call(Pred_Name(X6E6C,0),0,4,2,"nl",0)          /* begin sub 2 */
      put_structure(X426567696E5F496E69745F5461626C6573,1,0)
      unify_y_local_value(3)
      call(Pred_Name(X7772697465,1),0,3,3,"write",1)          /* begin sub 3 */
      call(Pred_Name(X6E6C,0),0,3,4,"nl",0)          /* begin sub 4 */
      call(Pred_Name(X6E6C,0),0,3,5,"nl",0)          /* begin sub 5 */
      put_y_value(2,0)
      call(Pred_Name(X635F656D69745F696E69745F7461626C65735F61746F6D,1),1,2,6,"c_emit_init_tables_atom",1)          /* begin sub 6 */
      call(Pred_Name(X6E6C,0),0,2,7,"nl",0)          /* begin sub 7 */
      put_y_value(1,0)
      put_y_value(0,1)
      call(Pred_Name(X635F656D69745F696E69745F7461626C65735F70726564,2),1,0,8,"c_emit_init_tables_pred",2)          /* begin sub 8 */
      call(Pred_Name(X6E6C,0),0,0,9,"nl",0)          /* begin sub 9 */
      put_constant(X20496E69745F5573725F46696C65,0)
      call(Pred_Name(X7772697465,1),0,0,10,"write",1)          /* begin sub 10 */
      call(Pred_Name(X6E6C,0),0,0,11,"nl",0)          /* begin sub 11 */
      call(Pred_Name(X6E6C,0),0,0,12,"nl",0)          /* begin sub 12 */
      put_constant(X456E645F496E69745F5461626C6573,0)
      call(Pred_Name(X7772697465,1),0,0,13,"write",1)          /* begin sub 13 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_init_tables_atom"
#define PRED       X635F656D69745F696E69745F7461626C65735F61746F6D
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
      unify_y_variable(2)
      unify_y_variable(0)
      put_y_value(2,0)
      put_y_variable(1,1)
      call(Pred_Name(X635F737472696E67,2),1,3,1,"c_string",2)          /* begin sub 1 */
      put_constant(X20446566696E655F41746F6D28,0)
      call(Pred_Name(X7772697465,1),0,3,2,"write",1)          /* begin sub 2 */
      put_y_value(2,0)
      call(Pred_Name(X685F7772697465,1),1,2,3,"h_write",1)          /* begin sub 3 */
      put_constant(X2C7E61297E6E,0)
      put_list(1)
      unify_y_local_value(1)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,1,4,"formata",2)          /* begin sub 4 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X635F656D69745F696E69745F7461626C65735F61746F6D,1),1,"c_emit_init_tables_atom",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_init_tables_pred"
#define PRED       X635F656D69745F696E69745F7461626C65735F70726564
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
      allocate(8)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_structure(X70,3,0)
      unify_x_variable(0)
      unify_y_variable(7)
      unify_y_variable(6)
      get_structure(X2F,2,0)
      unify_y_variable(5)
      unify_y_variable(4)
      get_y_variable(2,1)
      call(Pred_Name(X6E6C,0),0,8,1,"nl",0)          /* begin sub 1 */
      put_constant(X20446566696E655F5072656428,0)
      call(Pred_Name(X7772697465,1),0,8,2,"write",1)          /* begin sub 2 */
      put_y_value(5,0)
      call(Pred_Name(X685F7772697465,1),1,8,3,"h_write",1)          /* begin sub 3 */
      put_constant(X2C7E642C,0)
      put_list(1)
      unify_y_value(4)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,8,4,"formata",2)          /* begin sub 4 */
      put_y_value(5,0)
      put_y_value(4,1)
      put_y_variable(0,2)
      call(Pred_Name(X635F656D69745F696E69745F7461626C65735F707265645F2461757839,3),1,8,5,"c_emit_init_tables_pred_$aux9",3)          /* begin sub 5 */
      put_constant(X29,0)
      call(Pred_Name(X7772697465,1),0,8,6,"write",1)          /* begin sub 6 */
      call(Pred_Name(X6E6C,0),0,8,7,"nl",0)          /* begin sub 7 */
      put_y_value(7,0)
      put_y_value(5,1)
      put_y_value(4,2)
      call(Pred_Name(X635F656D69745F696E69745F74626C5F7377745F637374,3),1,7,8,"c_emit_init_tbl_swt_cst",3)          /* begin sub 8 */
      put_y_value(6,0)
      put_y_value(5,1)
      put_y_value(4,2)
      call(Pred_Name(X635F656D69745F696E69745F74626C5F7377745F737463,3),1,4,9,"c_emit_init_tbl_swt_stc",3)          /* begin sub 9 */
      put_y_value(3,0)
      put_y_variable(1,1)
      call(Pred_Name(X635F656D69745F696E69745F7461626C65735F70726564,2),1,3,10,"c_emit_init_tables_pred",2)          /* begin sub 10 */
      math_load_y_value(1,1)
      math_load_y_value(0,0)
      function_2(add,0,1,0)
      get_y_value(2,0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_init_tables_pred_$aux9"
#define PRED       X635F656D69745F696E69745F7461626C65735F707265645F2461757839
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      allocate(2)
      get_x_variable(4,0)
      get_x_variable(3,1)
      get_y_variable(0,2)
      get_y_bc_reg(1)
      put_constant(X707562,0)
      put_x_value(4,1)
      put_x_value(3,2)
      call(Pred_Name(X746573745F707265645F696E666F,3),0,2,1,"test_pred_info",3)          /* begin sub 1 */
      cut_y(1)
      put_integer(1,0)
      call(Pred_Name(X7772697465,1),0,1,2,"write",1)          /* begin sub 2 */
      put_y_value(0,0)
      get_integer(0,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      allocate(1)
      get_y_variable(0,2)
      put_integer(0,0)
      call(Pred_Name(X7772697465,1),0,1,3,"write",1)          /* begin sub 3 */
      put_y_value(0,0)
      get_integer(1,0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_init_tbl_swt_cst"
#define PRED       X635F656D69745F696E69745F74626C5F7377745F637374
#define ARITY      3

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
      allocate(6)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_structure(X63,3,0)
      unify_y_variable(5)
      unify_y_variable(4)
      unify_y_variable(3)
      get_y_variable(1,1)
      get_y_variable(0,2)
      put_constant(X20446566696E655F5377697463685F4353545F5461626C6528,0)
      call(Pred_Name(X7772697465,1),0,6,1,"write",1)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_value(0,1)
      put_y_value(5,2)
      put_constant(X637374,3)
      call(Pred_Name(X77726974655F7377745F7461626C655F6E616D65,4),1,5,2,"write_swt_table_name",4)          /* begin sub 2 */
      put_constant(X2C7E64297E6E,0)
      put_list(1)
      unify_y_value(4)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,4,3,"formata",2)          /* begin sub 3 */
      put_y_value(3,0)
      put_y_value(1,1)
      put_y_value(0,2)
      call(Pred_Name(X635F656D69745F696E69745F7377745F637374,3),1,3,4,"c_emit_init_swt_cst",3)          /* begin sub 4 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X635F656D69745F696E69745F74626C5F7377745F637374,3),1,"c_emit_init_tbl_swt_cst",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_init_swt_cst"
#define PRED       X635F656D69745F696E69745F7377745F637374
#define ARITY      3

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
      allocate(5)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_structure(X2C,2,0)
      unify_y_variable(4)
      unify_y_variable(3)
      get_y_variable(1,1)
      get_y_variable(0,2)
      put_constant(X2020202020446566696E655F5377697463685F43535428,0)
      call(Pred_Name(X7772697465,1),0,5,1,"write",1)          /* begin sub 1 */
      put_y_value(4,0)
      call(Pred_Name(X685F7772697465,1),1,4,2,"h_write",1)          /* begin sub 2 */
      put_constant(X2C,0)
      call(Pred_Name(X7772697465,1),0,4,3,"write",1)          /* begin sub 3 */
      put_y_value(1,0)
      put_y_value(0,1)
      put_y_value(3,2)
      call(Pred_Name(X77726974655F6C6162656C5F707265645F6E616D65,3),1,3,4,"write_label_pred_name",3)          /* begin sub 4 */
      put_constant(X29,0)
      call(Pred_Name(X7772697465,1),0,3,5,"write",1)          /* begin sub 5 */
      call(Pred_Name(X6E6C,0),0,3,6,"nl",0)          /* begin sub 6 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X635F656D69745F696E69745F7377745F637374,3),1,"c_emit_init_swt_cst",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_init_tbl_swt_stc"
#define PRED       X635F656D69745F696E69745F74626C5F7377745F737463
#define ARITY      3

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
      allocate(6)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_structure(X73,3,0)
      unify_y_variable(5)
      unify_y_variable(4)
      unify_y_variable(3)
      get_y_variable(1,1)
      get_y_variable(0,2)
      put_constant(X20446566696E655F5377697463685F5354435F5461626C6528,0)
      call(Pred_Name(X7772697465,1),0,6,1,"write",1)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_value(0,1)
      put_y_value(5,2)
      put_constant(X737463,3)
      call(Pred_Name(X77726974655F7377745F7461626C655F6E616D65,4),1,5,2,"write_swt_table_name",4)          /* begin sub 2 */
      put_constant(X2C7E64297E6E,0)
      put_list(1)
      unify_y_value(4)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,4,3,"formata",2)          /* begin sub 3 */
      put_y_value(3,0)
      put_y_value(1,1)
      put_y_value(0,2)
      call(Pred_Name(X635F656D69745F696E69745F7377745F737463,3),1,3,4,"c_emit_init_swt_stc",3)          /* begin sub 4 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X635F656D69745F696E69745F74626C5F7377745F737463,3),1,"c_emit_init_tbl_swt_stc",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_init_swt_stc"
#define PRED       X635F656D69745F696E69745F7377745F737463
#define ARITY      3

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
      allocate(6)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_structure(X2C,2,0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_structure(X2F,2,0)
      unify_y_variable(5)
      unify_y_variable(4)
      get_y_variable(1,1)
      get_y_variable(0,2)
      put_constant(X2020202020446566696E655F5377697463685F53544328,0)
      call(Pred_Name(X7772697465,1),0,6,1,"write",1)          /* begin sub 1 */
      put_y_value(5,0)
      call(Pred_Name(X685F7772697465,1),1,5,2,"h_write",1)          /* begin sub 2 */
      put_constant(X2C7E642C,0)
      put_list(1)
      unify_y_value(4)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,4,3,"formata",2)          /* begin sub 3 */
      put_y_value(1,0)
      put_y_value(0,1)
      put_y_value(3,2)
      call(Pred_Name(X77726974655F6C6162656C5F707265645F6E616D65,3),1,3,4,"write_label_pred_name",3)          /* begin sub 4 */
      put_constant(X29,0)
      call(Pred_Name(X7772697465,1),0,3,5,"write",1)          /* begin sub 5 */
      call(Pred_Name(X6E6C,0),0,3,6,"nl",0)          /* begin sub 6 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X635F656D69745F696E69745F7377745F737463,3),1,"c_emit_init_swt_stc",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_fct_exec_directives"
#define PRED       X635F656D69745F6663745F657865635F64697265637469766573
#define ARITY      0

Begin_Private_Pred
      allocate(1)
      put_constant(X6D6F64756C65,1)
      put_y_variable(0,0)
      builtin_2(g_read,1,0)
      call(Pred_Name(X6E6C,0),0,1,1,"nl",0)          /* begin sub 1 */
      call(Pred_Name(X6E6C,0),0,1,2,"nl",0)          /* begin sub 2 */
      put_structure(X426567696E5F457865635F44697265637469766573,1,0)
      unify_y_local_value(0)
      call(Pred_Name(X7772697465,1),0,0,3,"write",1)          /* begin sub 3 */
      call(Pred_Name(X6E6C,0),0,0,4,"nl",0)          /* begin sub 4 */
      call(Pred_Name(X6E6C,0),0,0,5,"nl",0)          /* begin sub 5 */
      put_constant(X6E625F636C617573655F64796E,2)
      put_x_variable(1,0)
      builtin_2(g_read,2,0)
      put_integer(1,0)
      put_constant(X2464796E5F,2)
      call(Pred_Name(X635F656D69745F657865635F64697265637469766573,3),1,0,6,"c_emit_exec_directives",3)          /* begin sub 6 */
      call(Pred_Name(X6E6C,0),0,0,7,"nl",0)          /* begin sub 7 */
      put_constant(X6E625F636C617573655F657865,2)
      put_x_variable(1,0)
      builtin_2(g_read,2,0)
      put_integer(1,0)
      put_constant(X246578655F,2)
      call(Pred_Name(X635F656D69745F657865635F64697265637469766573,3),1,0,8,"c_emit_exec_directives",3)          /* begin sub 8 */
      call(Pred_Name(X6E6C,0),0,0,9,"nl",0)          /* begin sub 9 */
      put_constant(X456E645F457865635F44697265637469766573,0)
      call(Pred_Name(X7772697465,1),0,0,10,"write",1)          /* begin sub 10 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_exec_directives"
#define PRED       X635F656D69745F657865635F64697265637469766573
#define ARITY      3

Begin_Private_Pred
      execute(Pred_Name(X635F656D69745F657865635F646972656374697665735F246175783130,3),1,"c_emit_exec_directives_$aux10",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_exec_directives_$aux10"
#define PRED       X635F656D69745F657865635F646972656374697665735F246175783130
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      allocate(4)
      get_y_variable(2,0)
      get_y_variable(1,1)
      get_y_variable(0,2)
      math_load_y_value(2,1)
      math_load_y_value(1,0)
      builtin_2(lte,1,0)
      neck_cut
      put_y_value(0,0)
      put_y_value(2,1)
      put_y_variable(3,2)
      call(Pred_Name(X6D616B655F7370656369616C5F636C617573655F68656164,3),0,4,1,"make_special_clause_head",3)          /* begin sub 1 */
      put_constant(X20457865635F446972656374697665287E642C,0)
      put_list(1)
      unify_y_local_value(2)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,4,2,"formata",2)          /* begin sub 2 */
      put_y_unsafe_value(3,0)
      put_integer(0,1)
      call(Pred_Name(X77726974655F707265645F6E616D65,2),1,3,3,"write_pred_name",2)          /* begin sub 3 */
      put_constant(X29,0)
      call(Pred_Name(X7772697465,1),0,3,4,"write",1)          /* begin sub 4 */
      call(Pred_Name(X6E6C,0),0,3,5,"nl",0)          /* begin sub 5 */
      math_load_y_value(2,0)
      function_1(inc,0,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X635F656D69745F657865635F64697265637469766573,3),1,"c_emit_exec_directives",3)

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_fct_main"
#define PRED       X635F656D69745F6663745F6D61696E
#define ARITY      1

Begin_Private_Pred
      allocate(6)
      get_y_bc_reg(5)
      put_constant(X6D6F64756C65,2)
      put_y_variable(3,1)
      builtin_2(g_read,2,1)
      put_y_variable(4,1)
      put_y_variable(1,2)
      call(Pred_Name(X635F656D69745F6663745F6D61696E5F246175783131,3),1,6,1,"c_emit_fct_main_$aux11",3)          /* begin sub 1 */
      cut_y(5)
      put_y_unsafe_value(4,0)
      put_list(1)
      unify_y_local_value(3)
      unify_nil
      put_y_variable(2,2)
      call(Pred_Name(X617070656E64,3),0,3,2,"append",3)          /* begin sub 2 */
      put_y_variable(0,0)
      get_list(0)
      unify_constant(X4275696C74696E)
      unify_y_local_value(2)
      put_constant(X7E6E7E6E2F2A2A2A204D41494E202A2A2A2F7E6E7E6E,0)
      put_nil(1)
      call(Pred_Name(X666F726D617461,2),0,2,3,"formata",2)          /* begin sub 3 */
      put_constant(X696E74206D61696E28696E7420617267632C63686172202A617267765B5D297E6E7E6E7B7E6E,0)
      put_nil(1)
      call(Pred_Name(X666F726D617461,2),0,2,4,"formata",2)          /* begin sub 4 */
      put_constant(X20756E69785F617267633D617267633B7E6E,0)
      put_nil(1)
      call(Pred_Name(X666F726D617461,2),0,2,5,"formata",2)          /* begin sub 5 */
      put_constant(X20756E69785F617267763D617267763B7E6E7E6E,0)
      put_nil(1)
      call(Pred_Name(X666F726D617461,2),0,2,6,"formata",2)          /* begin sub 6 */
      put_y_unsafe_value(1,0)
      call(Pred_Name(X635F656D69745F6663745F6D61696E5F646566696E655F737461636B73,1),1,1,7,"c_emit_fct_main_define_stacks",1)          /* begin sub 7 */
      call(Pred_Name(X6E6C,0),0,1,8,"nl",0)          /* begin sub 8 */
      put_constant(X20496E69745F57616D5F456E67696E6528293B7E6E7E6E,0)
      put_nil(1)
      call(Pred_Name(X666F726D617461,2),0,1,9,"formata",2)          /* begin sub 9 */
      put_y_value(0,0)
      call(Pred_Name(X635F656D69745F6663745F6D61696E5F696E69745F7461626C65735F6D6F64756C6573,1),1,1,10,"c_emit_fct_main_init_tables_modules",1)          /* begin sub 10 */
      call(Pred_Name(X6E6C,0),0,1,11,"nl",0)          /* begin sub 11 */
      put_y_unsafe_value(0,0)
      call(Pred_Name(X635F656D69745F6663745F6D61696E5F657865635F646972656374697665735F6D6F64756C6573,1),1,0,12,"c_emit_fct_main_exec_directives_modules",1)          /* begin sub 12 */
      call(Pred_Name(X6E6C,0),0,0,13,"nl",0)          /* begin sub 13 */
      put_constant(X205465726D5F57616D5F456E67696E6528293B7E6E7E6E,0)
      put_nil(1)
      call(Pred_Name(X666F726D617461,2),0,0,14,"formata",2)          /* begin sub 14 */
      put_constant(X2072657475726E20303B7E6E7D7E6E,0)
      put_nil(1)
      deallocate
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_fct_main_$aux11"
#define PRED       X635F656D69745F6663745F6D61696E5F246175783131
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      get_constant(X6D61696E,0)
      get_nil(1)
      get_nil(2)
      proceed

label(1)
      retry_me_else(2)
      get_structure(X6D61696E,1,0)
      unify_x_local_value(1)
      get_nil(2)
      proceed

label(2)
      trust_me_else_fail
      get_structure(X6D61696E,2,0)
      unify_x_local_value(1)
      unify_x_local_value(2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_fct_main_define_stacks"
#define PRED       X635F656D69745F6663745F6D61696E5F646566696E655F737461636B73
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
      allocate(1)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(0)
      get_structure(X737461636B,3,0)
      unify_x_variable(3)
      unify_x_variable(4)
      unify_x_variable(2)
      put_constant(X205365745F537461636B5F44656661756C747328227E61222C227E61222C7E64293B7E6E,0)
      put_list(1)
      unify_x_value(2)
      unify_nil
      put_list(2)
      unify_x_value(4)
      unify_x_value(1)
      put_list(1)
      unify_x_value(3)
      unify_x_value(2)
      call(Pred_Name(X666F726D617461,2),0,1,1,"formata",2)          /* begin sub 1 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X635F656D69745F6663745F6D61696E5F646566696E655F737461636B73,1),1,"c_emit_fct_main_define_stacks",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_fct_main_init_tables_modules"
#define PRED       X635F656D69745F6663745F6D61696E5F696E69745F7461626C65735F6D6F64756C6573
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
      allocate(1)
      get_list(0)
      unify_x_variable(1)
      unify_y_variable(0)
      put_structure(X20496E69745F5461626C65735F4F665F4D6F64756C65,1,0)
      unify_x_value(1)
      call(Pred_Name(X7772697465,1),0,1,1,"write",1)          /* begin sub 1 */
      call(Pred_Name(X6E6C,0),0,1,2,"nl",0)          /* begin sub 2 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X635F656D69745F6663745F6D61696E5F696E69745F7461626C65735F6D6F64756C6573,1),1,"c_emit_fct_main_init_tables_modules",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_fct_main_exec_directives_modules"
#define PRED       X635F656D69745F6663745F6D61696E5F657865635F646972656374697665735F6D6F64756C6573
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
      allocate(1)
      get_list(0)
      unify_x_variable(1)
      unify_y_variable(0)
      put_structure(X20457865635F446972656374697665735F4F665F4D6F64756C65,1,0)
      unify_x_value(1)
      call(Pred_Name(X7772697465,1),0,1,1,"write",1)          /* begin sub 1 */
      call(Pred_Name(X6E6C,0),0,1,2,"nl",0)          /* begin sub 2 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X635F656D69745F6663745F6D61696E5F657865635F646972656374697665735F6D6F64756C6573,1),1,"c_emit_fct_main_exec_directives_modules",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "add_to_dic_atom"
#define PRED       X6164645F746F5F6469635F61746F6D
#define ARITY      2

Begin_Private_Pred
      get_x_variable(2,0)
      put_x_value(1,0)
      put_x_value(2,1)
      execute(Pred_Name(X6D656D626572,2),0,"member",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_string"
#define PRED       X635F737472696E67
#define ARITY      2

Begin_Private_Pred
      allocate(3)
      get_y_variable(1,1)
      put_y_variable(2,1)
      call(Pred_Name(X61746F6D5F636F646573,2),0,3,1,"atom_codes",2)          /* begin sub 1 */
      put_y_unsafe_value(2,0)
      put_y_variable(0,1)
      call(Pred_Name(X70726F6C6F675F746F5F635F737472696E67,2),1,2,2,"prolog_to_c_string",2)          /* begin sub 2 */
      put_y_value(1,0)
      put_list(1)
      unify_integer(34)
      unify_y_local_value(0)
      deallocate
      execute(Pred_Name(X61746F6D5F636F646573,2),0,"atom_codes",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "prolog_to_c_string"
#define PRED       X70726F6C6F675F746F5F635F737472696E67
#define ARITY      2

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_list(1)
      unify_integer(34)
      unify_nil
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(2)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(1)
      put_y_variable(0,2)
      call(Pred_Name(X70726F6C6F675F746F5F635F737472696E675F246175783132,3),1,2,1,"prolog_to_c_string_$aux12",3)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X70726F6C6F675F746F5F635F737472696E67,2),1,"prolog_to_c_string",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "prolog_to_c_string_$aux12"
#define PRED       X70726F6C6F675F746F5F635F737472696E675F246175783132
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      allocate(4)
      get_y_variable(1,0)
      get_y_variable(2,1)
      get_y_variable(0,2)
      get_y_bc_reg(3)
      put_y_value(1,0)
      call(Pred_Name(X70726F6C6F675F746F5F635F737472696E675F246175783133,1),1,4,1,"prolog_to_c_string_$aux13",1)          /* begin sub 1 */
      cut_y(3)
      put_y_value(2,0)
      get_list(0)
      unify_integer(92)
      unify_x_variable(0)
      get_list(0)
      unify_y_local_value(1)
      unify_y_local_value(0)
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



#define ASCII_PRED "prolog_to_c_string_$aux13"
#define PRED       X70726F6C6F675F746F5F635F737472696E675F246175783133
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      get_integer(92,0)
      proceed

label(1)
      trust_me_else_fail
      get_integer(34,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_fic_h"
#define PRED       X635F656D69745F6669635F68
#define ARITY      3

Begin_Private_Pred
      allocate(6)
      get_y_variable(1,0)
      get_y_variable(0,1)
      get_y_variable(4,2)
      put_constant(X6D6F64756C65,1)
      put_y_variable(3,0)
      builtin_2(g_read,1,0)
      put_constant(X6669635F68,1)
      put_y_variable(5,0)
      builtin_2(g_read,1,0)
      put_y_value(5,0)
      call(Pred_Name(X74656C6C,1),0,6,1,"tell",1)          /* begin sub 1 */
      put_constant(X2F2A7E2A637E6E,0)
      put_list(2)
      unify_integer(42)
      unify_nil
      put_list(1)
      unify_integer(75)
      unify_x_value(2)
      call(Pred_Name(X666F726D617461,2),0,6,2,"formata",2)          /* begin sub 2 */
      call(Pred_Name(X646973706C61795F76657273696F6E,0),0,6,3,"display_version",0)          /* begin sub 3 */
      put_constant(X66696C65203A207E617E6E,0)
      put_list(1)
      unify_y_local_value(5)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,5,4,"formata",2)          /* begin sub 4 */
      put_constant(X7E2A632A2F7E6E7E6E,0)
      put_list(2)
      unify_integer(42)
      unify_nil
      put_list(1)
      unify_integer(75)
      unify_x_value(2)
      call(Pred_Name(X666F726D617461,2),0,5,5,"formata",2)          /* begin sub 5 */
      put_constant(X23646566696E65204E425F4F465F505249564154455F5052454453202020207E647E6E7E6E,0)
      put_list(1)
      unify_y_local_value(4)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,4,6,"formata",2)          /* begin sub 6 */
      put_y_unsafe_value(3,0)
      put_y_variable(2,1)
      call(Pred_Name(X635F737472696E67,2),1,3,7,"c_string",2)          /* begin sub 7 */
      put_constant(X7374617469632063686172202020202A6D6F64756C655F6E616D653D7E613B7E6E,0)
      put_list(1)
      unify_y_local_value(2)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,2,8,"formata",2)          /* begin sub 8 */
      put_constant(X73746174696320696E742020202020206D6F64756C655F6E623B7E6E7E6E,0)
      put_nil(1)
      call(Pred_Name(X666F726D617461,2),0,2,9,"formata",2)          /* begin sub 9 */
      put_y_value(1,0)
      call(Pred_Name(X635F656D69745F6465636C5F7661725F61746F6D,1),1,1,10,"c_emit_decl_var_atom",1)          /* begin sub 10 */
      call(Pred_Name(X6E6C,0),0,1,11,"nl",0)          /* begin sub 11 */
      put_y_value(0,0)
      call(Pred_Name(X635F656D69745F6465636C5F7661725F70726564,1),1,0,12,"c_emit_decl_var_pred",1)          /* begin sub 12 */
      call(Pred_Name(X6E6C,0),0,0,13,"nl",0)          /* begin sub 13 */
      deallocate
      execute(Pred_Name(X746F6C64,0),0,"told",0)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_decl_var_atom"
#define PRED       X635F656D69745F6465636C5F7661725F61746F6D
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
      unify_y_variable(1)
      unify_y_variable(0)
      put_constant(X7374617469632041746F6D496E66202A,0)
      call(Pred_Name(X7772697465,1),0,2,1,"write",1)          /* begin sub 1 */
      put_y_value(1,0)
      call(Pred_Name(X685F7772697465,1),1,1,2,"h_write",1)          /* begin sub 2 */
      put_constant(X3B,0)
      call(Pred_Name(X7772697465,1),0,1,3,"write",1)          /* begin sub 3 */
      call(Pred_Name(X6E6C,0),0,1,4,"nl",0)          /* begin sub 4 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X635F656D69745F6465636C5F7661725F61746F6D,1),1,"c_emit_decl_var_atom",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_decl_var_pred"
#define PRED       X635F656D69745F6465636C5F7661725F70726564
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
      allocate(4)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(0)
      get_structure(X70,3,0)
      unify_x_variable(1)
      unify_x_variable(0)
      unify_y_variable(3)
      get_structure(X2F,2,1)
      unify_y_variable(2)
      unify_y_variable(1)
      put_constant(X637374,1)
      put_y_value(2,2)
      put_y_value(1,3)
      call(Pred_Name(X635F656D69745F6465636C5F74626C5F737774,4),1,4,1,"c_emit_decl_tbl_swt",4)          /* begin sub 1 */
      put_y_value(3,0)
      put_constant(X737463,1)
      put_y_value(2,2)
      put_y_value(1,3)
      call(Pred_Name(X635F656D69745F6465636C5F74626C5F737774,4),1,1,2,"c_emit_decl_tbl_swt",4)          /* begin sub 2 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X635F656D69745F6465636C5F7661725F70726564,1),1,"c_emit_decl_var_pred",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_decl_tbl_swt"
#define PRED       X635F656D69745F6465636C5F74626C5F737774
#define ARITY      4

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
      allocate(5)
      get_list(0)
      unify_x_variable(4)
      unify_y_variable(3)
      get_y_variable(2,1)
      get_y_variable(1,2)
      get_y_variable(0,3)
      put_integer(1,1)
      put_y_variable(4,0)
      builtin_3(arg,1,4,0)
      put_constant(X7374617469632053777454626C202020,0)
      call(Pred_Name(X7772697465,1),0,5,1,"write",1)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_value(0,1)
      put_y_unsafe_value(4,2)
      put_y_value(2,3)
      call(Pred_Name(X77726974655F7377745F7461626C655F6E616D65,4),1,4,2,"write_swt_table_name",4)          /* begin sub 2 */
      put_constant(X3B,0)
      call(Pred_Name(X7772697465,1),0,4,3,"write",1)          /* begin sub 3 */
      call(Pred_Name(X6E6C,0),0,4,4,"nl",0)          /* begin sub 4 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X635F656D69745F6465636C5F74626C5F737774,4),1,"c_emit_decl_tbl_swt",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_fic_usr"
#define PRED       X635F656D69745F6669635F757372
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      get_x_variable(1,0)
      put_structure(X616363657373,2,0)
      unify_x_local_value(1)
      unify_integer(0)
      execute(Pred_Name(X756E6978,1),0,"unix",1)

label(1)
      trust_me_else_fail
      allocate(1)
      get_y_variable(0,0)
      put_y_value(0,0)
      call(Pred_Name(X74656C6C,1),0,1,1,"tell",1)          /* begin sub 1 */
      put_constant(X2F2A7E2A637E6E,0)
      put_list(2)
      unify_integer(42)
      unify_nil
      put_list(1)
      unify_integer(75)
      unify_x_value(2)
      call(Pred_Name(X666F726D617461,2),0,1,2,"formata",2)          /* begin sub 2 */
      call(Pred_Name(X646973706C61795F76657273696F6E,0),0,1,3,"display_version",0)          /* begin sub 3 */
      put_constant(X66696C65203A207E617E6E,0)
      put_list(1)
      unify_y_local_value(0)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,0,4,"formata",2)          /* begin sub 4 */
      put_constant(X7E2A632A2F7E6E7E6E,0)
      put_list(2)
      unify_integer(42)
      unify_nil
      put_list(1)
      unify_integer(75)
      unify_x_value(2)
      call(Pred_Name(X666F726D617461,2),0,0,5,"formata",2)          /* begin sub 5 */
      call(Pred_Name(X635F656D69745F6D6F6469665F6661696C,0),1,0,6,"c_emit_modif_fail",0)          /* begin sub 6 */
      call(Pred_Name(X635F656D69745F656E5F746574655F696E69745F757372,0),1,0,7,"c_emit_en_tete_init_usr",0)          /* begin sub 7 */
      call(Pred_Name(X6E6C,0),0,0,8,"nl",0)          /* begin sub 8 */
      call(Pred_Name(X6E6C,0),0,0,9,"nl",0)          /* begin sub 9 */
      put_constant(X7B7E6E7D7E6E,0)
      put_nil(1)
      call(Pred_Name(X666F726D617461,2),0,0,10,"formata",2)          /* begin sub 10 */
      call(Pred_Name(X635F656D69745F726573746F72655F6661696C,0),1,0,11,"c_emit_restore_fail",0)          /* begin sub 11 */
      deallocate
      execute(Pred_Name(X746F6C64,0),0,"told",0)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_modif_fail"
#define PRED       X635F656D69745F6D6F6469665F6661696C
#define ARITY      0

Begin_Private_Pred
      allocate(0)
      call(Pred_Name(X6E6C,0),0,0,1,"nl",0)          /* begin sub 1 */
      put_constant(X2F2A2041626F76652074686973206C696E652C2070757420796F7572206669727374206D6163726F7320,0)
      call(Pred_Name(X7772697465,1),0,0,2,"write",1)          /* begin sub 2 */
      put_constant(X28746865736520696E636C7564656420627920707261676D615F6329202A2F,0)
      call(Pred_Name(X7772697465,1),0,0,3,"write",1)          /* begin sub 3 */
      call(Pred_Name(X6E6C,0),0,0,4,"nl",0)          /* begin sub 4 */
      call(Pred_Name(X6E6C,0),0,0,5,"nl",0)          /* begin sub 5 */
      put_constant(X23756E64656620206661696C,0)
      call(Pred_Name(X7772697465,1),0,0,6,"write",1)          /* begin sub 6 */
      call(Pred_Name(X6E6C,0),0,0,7,"nl",0)          /* begin sub 7 */
      put_constant(X23646566696E65206661696C204661696C5F4C696B655F426F6F6C,0)
      call(Pred_Name(X7772697465,1),0,0,8,"write",1)          /* begin sub 8 */
      call(Pred_Name(X6E6C,0),0,0,9,"nl",0)          /* begin sub 9 */
      call(Pred_Name(X6E6C,0),0,0,10,"nl",0)          /* begin sub 10 */
      put_constant(X2F2A2042656C6F772074686973206C696E652C2070757420796F7572206F7468657273206D6163726F7320,0)
      call(Pred_Name(X7772697465,1),0,0,11,"write",1)          /* begin sub 11 */
      put_constant(X616E6420796F75722066756E6374696F6E73202A2F,0)
      call(Pred_Name(X7772697465,1),0,0,12,"write",1)          /* begin sub 12 */
      call(Pred_Name(X6E6C,0),0,0,13,"nl",0)          /* begin sub 13 */
      call(Pred_Name(X6E6C,0),0,0,14,"nl",0)          /* begin sub 14 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_restore_fail"
#define PRED       X635F656D69745F726573746F72655F6661696C
#define ARITY      0

Begin_Private_Pred
      allocate(0)
      call(Pred_Name(X6E6C,0),0,0,1,"nl",0)          /* begin sub 1 */
      put_constant(X2F2A20656E64206F6620757365722066696C65202A2F,0)
      call(Pred_Name(X7772697465,1),0,0,2,"write",1)          /* begin sub 2 */
      call(Pred_Name(X6E6C,0),0,0,3,"nl",0)          /* begin sub 3 */
      call(Pred_Name(X6E6C,0),0,0,4,"nl",0)          /* begin sub 4 */
      put_constant(X23756E64656620206661696C,0)
      call(Pred_Name(X7772697465,1),0,0,5,"write",1)          /* begin sub 5 */
      call(Pred_Name(X6E6C,0),0,0,6,"nl",0)          /* begin sub 6 */
      put_constant(X23646566696E65206661696C204661696C5F4C696B655F57616D,0)
      call(Pred_Name(X7772697465,1),0,0,7,"write",1)          /* begin sub 7 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "c_emit_en_tete_init_usr"
#define PRED       X635F656D69745F656E5F746574655F696E69745F757372
#define ARITY      0

Begin_Private_Pred
      put_constant(X73746174696320766F696420496E697469616C697A655F55737228766F696429,0)
      execute(Pred_Name(X7772697465,1),0,"write",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "write_pred_name"
#define PRED       X77726974655F707265645F6E616D65
#define ARITY      2

Begin_Private_Pred
      allocate(2)
      get_y_variable(1,0)
      get_y_variable(0,1)
      put_constant(X507265645F4E616D6528,0)
      call(Pred_Name(X7772697465,1),0,2,1,"write",1)          /* begin sub 1 */
      put_y_value(1,0)
      call(Pred_Name(X685F7772697465,1),1,1,2,"h_write",1)          /* begin sub 2 */
      put_constant(X2C7E6429,0)
      put_list(1)
      unify_y_local_value(0)
      unify_nil
      deallocate
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "write_label_pred_name"
#define PRED       X77726974655F6C6162656C5F707265645F6E616D65
#define ARITY      3

Begin_Private_Pred
      allocate(3)
      get_y_variable(2,0)
      get_y_variable(1,1)
      get_y_variable(0,2)
      put_constant(X4C6162656C5F507265645F4E616D6528,0)
      call(Pred_Name(X7772697465,1),0,3,1,"write",1)          /* begin sub 1 */
      put_y_value(2,0)
      call(Pred_Name(X685F7772697465,1),1,2,2,"h_write",1)          /* begin sub 2 */
      put_constant(X2C7E642C7E6429,0)
      put_list(2)
      unify_y_local_value(0)
      unify_nil
      put_list(1)
      unify_y_local_value(1)
      unify_x_value(2)
      deallocate
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "write_swt_table_name"
#define PRED       X77726974655F7377745F7461626C655F6E616D65
#define ARITY      4

Begin_Private_Pred
      allocate(4)
      get_y_variable(3,0)
      get_y_variable(2,1)
      get_y_variable(1,2)
      get_y_variable(0,3)
      put_constant(X5377745F5461626C655F4E616D6528,0)
      call(Pred_Name(X7772697465,1),0,4,1,"write",1)          /* begin sub 1 */
      put_y_value(3,0)
      call(Pred_Name(X685F7772697465,1),1,3,2,"h_write",1)          /* begin sub 2 */
      put_constant(X2C7E642C7E642C7E6129,0)
      put_list(1)
      unify_y_local_value(0)
      unify_nil
      put_list(2)
      unify_y_local_value(1)
      unify_x_value(1)
      put_list(1)
      unify_y_local_value(2)
      unify_x_value(2)
      deallocate
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "h_write"
#define PRED       X685F7772697465
#define ARITY      1

Begin_Private_Pred
      allocate(1)
      put_y_variable(0,1)
      call(Pred_Name(X61746F6D5F636F646573,2),0,1,1,"atom_codes",2)          /* begin sub 1 */
      put_constant(X58,0)
      call(Pred_Name(X7772697465,1),0,1,2,"write",1)          /* begin sub 2 */
      put_y_unsafe_value(0,0)
      deallocate
      execute(Pred_Name(X685F77726974655F68657861,1),1,"h_write_hexa",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "h_write_hexa"
#define PRED       X685F77726974655F68657861
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
      allocate(1)
      get_list(0)
      unify_x_variable(2)
      unify_y_variable(0)
      put_constant(X7E313652,0)
      put_list(1)
      unify_x_value(2)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,1,1,"formata",2)          /* begin sub 1 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X685F77726974655F68657861,1),1,"h_write_hexa",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(wamcc8)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X635F656D697373696F6E,"c_emission")
 Define_Atom(X6669635F757372,"fic_usr")
 Define_Atom(X635F656D69745F6669635F63,"c_emit_fic_c")
 Define_Atom(X6669635F6F7574,"fic_out")
 Define_Atom(X6D6F64756C65,"module")
 Define_Atom(X2F2A7E2A637E6E,"/*~*c~n")
 Define_Atom(X46696C65203A207E617E6E,"File : ~a~n")
 Define_Atom(X4D61696E203A207E777E6E,"Main : ~w~n")
 Define_Atom(X7E2A632A2F7E6E7E6E,"~*c*/~n~n")
 Define_Atom(X6465627567,"debug")
 Define_Atom(X23646566696E652044454255475F4C4556454C202020207E647E6E,"#define DEBUG_LEVEL    ~d~n")
 Define_Atom(X23696E636C756465202277616D5F656E67696E652E68227E6E7E6E,"#include \"wam_engine.h\"~n~n")
 Define_Atom(X23696E636C75646520227E612E68227E6E,"#include \"~a.h\"~n")
 Define_Atom(X23696E636C75646520227E612E75737222,"#include \"~a.usr\"")
 Define_Atom(X635F656D69745F6669635F635F2461757832,"c_emit_fic_c_$aux2")
 Define_Atom(X6E6F5F6D61696E,"no_main")
 Define_Atom(X635F656D69745F6669635F635F2461757831,"c_emit_fic_c_$aux1")
 Define_Atom(X666173745F6D617468,"fast_math")
 Define_Atom(X74,"t")
 Define_Atom(X23646566696E6520464153545F4D4154487E6E,"#define FAST_MATH~n")
 Define_Atom(X635F656D69745F6C73745F70726564,"c_emit_lst_pred")
 Define_Atom(X706171,"paq")
 Define_Atom(X2F,"/")
 Define_Atom(X70,"p")
 Define_Atom(X635F656D69745F70726564,"c_emit_pred")
 Define_Atom(X23646566696E652041534349495F5052454420,"#define ASCII_PRED ")
 Define_Atom(X23646566696E65205052454420202020202020,"#define PRED       ")
 Define_Atom(X23646566696E65204152495459202020202020,"#define ARITY      ")
 Define_Atom(X456E645F50726564,"End_Pred")
 Define_Atom(X23756E6465662041534349495F50524544,"#undef ASCII_PRED")
 Define_Atom(X23756E6465662050524544,"#undef PRED")
 Define_Atom(X23756E646566204152495459,"#undef ARITY")
 Define_Atom(X635F656D69745F707265645F2461757833,"c_emit_pred_$aux3")
 Define_Atom(X707562,"pub")
 Define_Atom(X426567696E5F5075626C69635F50726564,"Begin_Public_Pred")
 Define_Atom(X426567696E5F507269766174655F50726564,"Begin_Private_Pred")
 Define_Atom(X635F656D6974,"c_emit")
 Define_Atom(X6765745F636F6E7374616E74,"get_constant")
 Define_Atom(X6765745F636F6E7374616E7428,"get_constant(")
 Define_Atom(X2C7E64297E6E,",~d)~n")
 Define_Atom(X7075745F636F6E7374616E74,"put_constant")
 Define_Atom(X7075745F636F6E7374616E7428,"put_constant(")
 Define_Atom(X6765745F737472756374757265,"get_structure")
 Define_Atom(X6765745F73747275637475726528,"get_structure(")
 Define_Atom(X2C7E642C7E64297E6E,",~d,~d)~n")
 Define_Atom(X7075745F737472756374757265,"put_structure")
 Define_Atom(X7075745F73747275637475726528,"put_structure(")
 Define_Atom(X756E6966795F636F6E7374616E74,"unify_constant")
 Define_Atom(X756E6966795F636F6E7374616E7428,"unify_constant(")
 Define_Atom(X29,")")
 Define_Atom(X63616C6C,"call")
 Define_Atom(X63616C6C28,"call(")
 Define_Atom(X2C7E642C7E642C7E642C7E612C7E6429,",~d,~d,~d,~a,~d)")
 Define_Atom(X65786563757465,"execute")
 Define_Atom(X6578656375746528,"execute(")
 Define_Atom(X2C7E642C7E612C7E64297E6E,",~d,~a,~d)~n")
 Define_Atom(X7377697463685F6F6E5F7465726D,"switch_on_term")
 Define_Atom(X7377697463685F6F6E5F7465726D28,"switch_on_term(")
 Define_Atom(X2C,",")
 Define_Atom(X7377697463685F6F6E5F636F6E7374616E74,"switch_on_constant")
 Define_Atom(X63,"c")
 Define_Atom(X7377697463685F6F6E5F636F6E7374616E7428,"switch_on_constant(")
 Define_Atom(X7E642C227E7722297E6E,"~d,\"~w\")~n")
 Define_Atom(X7377697463685F6F6E5F696E7465676572,"switch_on_integer")
 Define_Atom(X7377697463685F6F6E5F696E7465676572286C737428,"switch_on_integer(lst(")
 Define_Atom(X292C227E7722297E6E,"),\"~w\")~n")
 Define_Atom(X7377697463685F6F6E5F737472756374757265,"switch_on_structure")
 Define_Atom(X73,"s")
 Define_Atom(X7377697463685F6F6E5F73747275637475726528,"switch_on_structure(")
 Define_Atom(X747279,"try")
 Define_Atom(X7265747279,"retry")
 Define_Atom(X6C6162656C,"label")
 Define_Atom(X635F656D69745F2461757834,"c_emit_$aux4")
 Define_Atom(X635F656D69745F2461757835,"c_emit_$aux5")
 Define_Atom(X646566,"def")
 Define_Atom(X635F656D69745F2461757836,"c_emit_$aux6")
 Define_Atom(X635F656D69745F676F746F5F6F725F6661696C,"c_emit_goto_or_fail")
 Define_Atom(X635F656D69745F676F746F5F6F725F6661696C5F2461757837,"c_emit_goto_or_fail_$aux7")
 Define_Atom(X6661696C,"fail")
 Define_Atom(X475F6C6162656C,"G_label")
 Define_Atom(X635F656D69745F7377745F696E74,"c_emit_swt_int")
 Define_Atom(X69,"i")
 Define_Atom(X20," ")
 Define_Atom(X635F656D69745F2461757838,"c_emit_$aux8")
 Define_Atom(X635F656D69745F6865616465725F7375625F70726564,"c_emit_header_sub_pred")
 Define_Atom(X202020202020202020202F2A20626567696E20737562207E64202A2F7E6E,"          /* begin sub ~d */~n")
 Define_Atom(X635F656D69745F6663745F696E69745F7461626C6573,"c_emit_fct_init_tables")
 Define_Atom(X426567696E5F496E69745F5461626C6573,"Begin_Init_Tables")
 Define_Atom(X20496E69745F5573725F46696C65," Init_Usr_File")
 Define_Atom(X456E645F496E69745F5461626C6573,"End_Init_Tables")
 Define_Atom(X635F656D69745F696E69745F7461626C65735F61746F6D,"c_emit_init_tables_atom")
 Define_Atom(X20446566696E655F41746F6D28," Define_Atom(")
 Define_Atom(X2C7E61297E6E,",~a)~n")
 Define_Atom(X635F656D69745F696E69745F7461626C65735F70726564,"c_emit_init_tables_pred")
 Define_Atom(X20446566696E655F5072656428," Define_Pred(")
 Define_Atom(X2C7E642C,",~d,")
 Define_Atom(X635F656D69745F696E69745F7461626C65735F707265645F2461757839,"c_emit_init_tables_pred_$aux9")
 Define_Atom(X635F656D69745F696E69745F74626C5F7377745F637374,"c_emit_init_tbl_swt_cst")
 Define_Atom(X20446566696E655F5377697463685F4353545F5461626C6528," Define_Switch_CST_Table(")
 Define_Atom(X637374,"cst")
 Define_Atom(X635F656D69745F696E69745F7377745F637374,"c_emit_init_swt_cst")
 Define_Atom(X2020202020446566696E655F5377697463685F43535428,"     Define_Switch_CST(")
 Define_Atom(X635F656D69745F696E69745F74626C5F7377745F737463,"c_emit_init_tbl_swt_stc")
 Define_Atom(X20446566696E655F5377697463685F5354435F5461626C6528," Define_Switch_STC_Table(")
 Define_Atom(X737463,"stc")
 Define_Atom(X635F656D69745F696E69745F7377745F737463,"c_emit_init_swt_stc")
 Define_Atom(X2020202020446566696E655F5377697463685F53544328,"     Define_Switch_STC(")
 Define_Atom(X635F656D69745F6663745F657865635F64697265637469766573,"c_emit_fct_exec_directives")
 Define_Atom(X426567696E5F457865635F44697265637469766573,"Begin_Exec_Directives")
 Define_Atom(X6E625F636C617573655F64796E,"nb_clause_dyn")
 Define_Atom(X2464796E5F,"$dyn_")
 Define_Atom(X6E625F636C617573655F657865,"nb_clause_exe")
 Define_Atom(X246578655F,"$exe_")
 Define_Atom(X456E645F457865635F44697265637469766573,"End_Exec_Directives")
 Define_Atom(X635F656D69745F657865635F64697265637469766573,"c_emit_exec_directives")
 Define_Atom(X635F656D69745F657865635F646972656374697665735F246175783130,"c_emit_exec_directives_$aux10")
 Define_Atom(X20457865635F446972656374697665287E642C," Exec_Directive(~d,")
 Define_Atom(X635F656D69745F6663745F6D61696E,"c_emit_fct_main")
 Define_Atom(X4275696C74696E,"Builtin")
 Define_Atom(X7E6E7E6E2F2A2A2A204D41494E202A2A2A2F7E6E7E6E,"~n~n/*** MAIN ***/~n~n")
 Define_Atom(X696E74206D61696E28696E7420617267632C63686172202A617267765B5D297E6E7E6E7B7E6E,"int main(int argc,char *argv[])~n~n{~n")
 Define_Atom(X20756E69785F617267633D617267633B7E6E," unix_argc=argc;~n")
 Define_Atom(X20756E69785F617267763D617267763B7E6E7E6E," unix_argv=argv;~n~n")
 Define_Atom(X20496E69745F57616D5F456E67696E6528293B7E6E7E6E," Init_Wam_Engine();~n~n")
 Define_Atom(X205465726D5F57616D5F456E67696E6528293B7E6E7E6E," Term_Wam_Engine();~n~n")
 Define_Atom(X2072657475726E20303B7E6E7D7E6E," return 0;~n}~n")
 Define_Atom(X635F656D69745F6663745F6D61696E5F246175783131,"c_emit_fct_main_$aux11")
 Define_Atom(X6D61696E,"main")
 Define_Atom(X635F656D69745F6663745F6D61696E5F646566696E655F737461636B73,"c_emit_fct_main_define_stacks")
 Define_Atom(X737461636B,"stack")
 Define_Atom(X205365745F537461636B5F44656661756C747328227E61222C227E61222C7E64293B7E6E," Set_Stack_Defaults(\"~a\",\"~a\",~d);~n")
 Define_Atom(X635F656D69745F6663745F6D61696E5F696E69745F7461626C65735F6D6F64756C6573,"c_emit_fct_main_init_tables_modules")
 Define_Atom(X20496E69745F5461626C65735F4F665F4D6F64756C65," Init_Tables_Of_Module")
 Define_Atom(X635F656D69745F6663745F6D61696E5F657865635F646972656374697665735F6D6F64756C6573,"c_emit_fct_main_exec_directives_modules")
 Define_Atom(X20457865635F446972656374697665735F4F665F4D6F64756C65," Exec_Directives_Of_Module")
 Define_Atom(X6164645F746F5F6469635F61746F6D,"add_to_dic_atom")
 Define_Atom(X635F737472696E67,"c_string")
 Define_Atom(X70726F6C6F675F746F5F635F737472696E67,"prolog_to_c_string")
 Define_Atom(X70726F6C6F675F746F5F635F737472696E675F246175783132,"prolog_to_c_string_$aux12")
 Define_Atom(X70726F6C6F675F746F5F635F737472696E675F246175783133,"prolog_to_c_string_$aux13")
 Define_Atom(X635F656D69745F6669635F68,"c_emit_fic_h")
 Define_Atom(X6669635F68,"fic_h")
 Define_Atom(X66696C65203A207E617E6E,"file : ~a~n")
 Define_Atom(X23646566696E65204E425F4F465F505249564154455F5052454453202020207E647E6E7E6E,"#define NB_OF_PRIVATE_PREDS    ~d~n~n")
 Define_Atom(X7374617469632063686172202020202A6D6F64756C655F6E616D653D7E613B7E6E,"static char    *module_name=~a;~n")
 Define_Atom(X73746174696320696E742020202020206D6F64756C655F6E623B7E6E7E6E,"static int      module_nb;~n~n")
 Define_Atom(X635F656D69745F6465636C5F7661725F61746F6D,"c_emit_decl_var_atom")
 Define_Atom(X7374617469632041746F6D496E66202A,"static AtomInf *")
 Define_Atom(X3B,";")
 Define_Atom(X635F656D69745F6465636C5F7661725F70726564,"c_emit_decl_var_pred")
 Define_Atom(X635F656D69745F6465636C5F74626C5F737774,"c_emit_decl_tbl_swt")
 Define_Atom(X7374617469632053777454626C202020,"static SwtTbl   ")
 Define_Atom(X635F656D69745F6669635F757372,"c_emit_fic_usr")
 Define_Atom(X616363657373,"access")
 Define_Atom(X7B7E6E7D7E6E,"{~n}~n")
 Define_Atom(X635F656D69745F6D6F6469665F6661696C,"c_emit_modif_fail")
 Define_Atom(X2F2A2041626F76652074686973206C696E652C2070757420796F7572206669727374206D6163726F7320,"/* Above this line, put your first macros ")
 Define_Atom(X28746865736520696E636C7564656420627920707261676D615F6329202A2F,"(these included by pragma_c) */")
 Define_Atom(X23756E64656620206661696C,"#undef  fail")
 Define_Atom(X23646566696E65206661696C204661696C5F4C696B655F426F6F6C,"#define fail Fail_Like_Bool")
 Define_Atom(X2F2A2042656C6F772074686973206C696E652C2070757420796F7572206F7468657273206D6163726F7320,"/* Below this line, put your others macros ")
 Define_Atom(X616E6420796F75722066756E6374696F6E73202A2F,"and your functions */")
 Define_Atom(X635F656D69745F726573746F72655F6661696C,"c_emit_restore_fail")
 Define_Atom(X2F2A20656E64206F6620757365722066696C65202A2F,"/* end of user file */")
 Define_Atom(X23646566696E65206661696C204661696C5F4C696B655F57616D,"#define fail Fail_Like_Wam")
 Define_Atom(X635F656D69745F656E5F746574655F696E69745F757372,"c_emit_en_tete_init_usr")
 Define_Atom(X73746174696320766F696420496E697469616C697A655F55737228766F696429,"static void Initialize_Usr(void)")
 Define_Atom(X77726974655F707265645F6E616D65,"write_pred_name")
 Define_Atom(X507265645F4E616D6528,"Pred_Name(")
 Define_Atom(X2C7E6429,",~d)")
 Define_Atom(X77726974655F6C6162656C5F707265645F6E616D65,"write_label_pred_name")
 Define_Atom(X4C6162656C5F507265645F4E616D6528,"Label_Pred_Name(")
 Define_Atom(X2C7E642C7E6429,",~d,~d)")
 Define_Atom(X77726974655F7377745F7461626C655F6E616D65,"write_swt_table_name")
 Define_Atom(X5377745F5461626C655F4E616D6528,"Swt_Table_Name(")
 Define_Atom(X2C7E642C7E642C7E6129,",~d,~d,~a)")
 Define_Atom(X685F7772697465,"h_write")
 Define_Atom(X58,"X")
 Define_Atom(X685F77726974655F68657861,"h_write_hexa")
 Define_Atom(X7E313652,"~16R")


 Define_Pred(X635F656D697373696F6E,2,1)

 Define_Pred(X635F656D69745F6669635F63,5,0)

 Define_Pred(X635F656D69745F6669635F635F2461757832,1,0)

 Define_Pred(X635F656D69745F6669635F635F2461757831,0,0)

 Define_Pred(X635F656D69745F6C73745F70726564,3,0)

 Define_Pred(X635F656D69745F70726564,6,0)

 Define_Pred(X635F656D69745F707265645F2461757833,2,0)

 Define_Pred(X635F656D6974,6,0)
 Define_Switch_STC_Table(Swt_Table_Name(X635F656D6974,6,7,stc),14)
     Define_Switch_STC(X6765745F636F6E7374616E74,2,Label_Pred_Name(X635F656D6974,6,9))
     Define_Switch_STC(X7075745F636F6E7374616E74,2,Label_Pred_Name(X635F656D6974,6,11))
     Define_Switch_STC(X6765745F737472756374757265,2,Label_Pred_Name(X635F656D6974,6,13))
     Define_Switch_STC(X7075745F737472756374757265,2,Label_Pred_Name(X635F656D6974,6,15))
     Define_Switch_STC(X756E6966795F636F6E7374616E74,1,Label_Pred_Name(X635F656D6974,6,17))
     Define_Switch_STC(X63616C6C,2,Label_Pred_Name(X635F656D6974,6,19))
     Define_Switch_STC(X65786563757465,1,Label_Pred_Name(X635F656D6974,6,21))
     Define_Switch_STC(X7377697463685F6F6E5F7465726D,5,Label_Pred_Name(X635F656D6974,6,23))
     Define_Switch_STC(X7377697463685F6F6E5F636F6E7374616E74,3,Label_Pred_Name(X635F656D6974,6,25))
     Define_Switch_STC(X7377697463685F6F6E5F696E7465676572,3,Label_Pred_Name(X635F656D6974,6,27))
     Define_Switch_STC(X7377697463685F6F6E5F737472756374757265,3,Label_Pred_Name(X635F656D6974,6,29))
     Define_Switch_STC(X747279,1,Label_Pred_Name(X635F656D6974,6,31))
     Define_Switch_STC(X7265747279,1,Label_Pred_Name(X635F656D6974,6,33))
     Define_Switch_STC(X6C6162656C,1,Label_Pred_Name(X635F656D6974,6,35))

 Define_Pred(X635F656D69745F2461757834,2,0)

 Define_Pred(X635F656D69745F2461757835,3,0)

 Define_Pred(X635F656D69745F2461757836,3,0)

 Define_Pred(X635F656D69745F676F746F5F6F725F6661696C,1,0)

 Define_Pred(X635F656D69745F676F746F5F6F725F6661696C5F2461757837,1,0)

 Define_Pred(X635F656D69745F7377745F696E74,1,0)

 Define_Pred(X635F656D69745F2461757838,1,0)

 Define_Pred(X635F656D69745F6865616465725F7375625F70726564,1,0)

 Define_Pred(X635F656D69745F6663745F696E69745F7461626C6573,3,0)

 Define_Pred(X635F656D69745F696E69745F7461626C65735F61746F6D,1,0)

 Define_Pred(X635F656D69745F696E69745F7461626C65735F70726564,2,0)

 Define_Pred(X635F656D69745F696E69745F7461626C65735F707265645F2461757839,3,0)

 Define_Pred(X635F656D69745F696E69745F74626C5F7377745F637374,3,0)

 Define_Pred(X635F656D69745F696E69745F7377745F637374,3,0)

 Define_Pred(X635F656D69745F696E69745F74626C5F7377745F737463,3,0)

 Define_Pred(X635F656D69745F696E69745F7377745F737463,3,0)

 Define_Pred(X635F656D69745F6663745F657865635F64697265637469766573,0,0)

 Define_Pred(X635F656D69745F657865635F64697265637469766573,3,0)

 Define_Pred(X635F656D69745F657865635F646972656374697665735F246175783130,3,0)

 Define_Pred(X635F656D69745F6663745F6D61696E,1,0)

 Define_Pred(X635F656D69745F6663745F6D61696E5F246175783131,3,0)

 Define_Pred(X635F656D69745F6663745F6D61696E5F646566696E655F737461636B73,1,0)

 Define_Pred(X635F656D69745F6663745F6D61696E5F696E69745F7461626C65735F6D6F64756C6573,1,0)

 Define_Pred(X635F656D69745F6663745F6D61696E5F657865635F646972656374697665735F6D6F64756C6573,1,0)

 Define_Pred(X6164645F746F5F6469635F61746F6D,2,0)

 Define_Pred(X635F737472696E67,2,0)

 Define_Pred(X70726F6C6F675F746F5F635F737472696E67,2,0)

 Define_Pred(X70726F6C6F675F746F5F635F737472696E675F246175783132,3,0)

 Define_Pred(X70726F6C6F675F746F5F635F737472696E675F246175783133,1,0)

 Define_Pred(X635F656D69745F6669635F68,3,0)

 Define_Pred(X635F656D69745F6465636C5F7661725F61746F6D,1,0)

 Define_Pred(X635F656D69745F6465636C5F7661725F70726564,1,0)

 Define_Pred(X635F656D69745F6465636C5F74626C5F737774,4,0)

 Define_Pred(X635F656D69745F6669635F757372,1,0)

 Define_Pred(X635F656D69745F6D6F6469665F6661696C,0,0)

 Define_Pred(X635F656D69745F726573746F72655F6661696C,0,0)

 Define_Pred(X635F656D69745F656E5F746574655F696E69745F757372,0,0)

 Define_Pred(X77726974655F707265645F6E616D65,2,0)

 Define_Pred(X77726974655F6C6162656C5F707265645F6E616D65,3,0)

 Define_Pred(X77726974655F7377745F7461626C655F6E616D65,4,0)

 Define_Pred(X685F7772697465,1,0)

 Define_Pred(X685F77726974655F68657861,1,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(wamcc8)



End_Exec_Directives
