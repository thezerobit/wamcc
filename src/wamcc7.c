/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : wamcc7.c
Main : no_main
****************************************************************************/

#define FAST_MATH
#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "wamcc7.h"
#include "wamcc7.usr"


#define ASCII_PRED "wam_emission"
#define PRED       X77616D5F656D697373696F6E
#define ARITY      1

Begin_Public_Pred
      allocate(1)
      get_y_variable(0,0)
      put_constant(X6669635F6F7574,2)
      put_x_variable(0,1)
      builtin_2(g_read,2,1)
      call(Pred_Name(X74656C6C,1),0,1,1,"tell",1)          /* begin sub 1 */
      put_y_value(0,0)
      call(Pred_Name(X77616D5F656D69745F6C73745F70726564,1),1,0,2,"wam_emit_lst_pred",1)          /* begin sub 2 */
      deallocate
      execute(Pred_Name(X746F6C64,0),0,"told",0)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wam_emit_lst_pred"
#define PRED       X77616D5F656D69745F6C73745F70726564
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
      unify_x_variable(0)
      unify_y_variable(0)
      get_structure(X706171,2,0)
      unify_x_variable(0)
      unify_x_variable(1)
      get_y_bc_reg(1)
      call(Pred_Name(X77616D5F656D69745F70726564,2),1,2,1,"wam_emit_pred",2)          /* begin sub 1 */
      cut_y(1)
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X77616D5F656D69745F6C73745F70726564,1),1,"wam_emit_lst_pred",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wam_emit_pred"
#define PRED       X77616D5F656D69745F70726564
#define ARITY      2

Begin_Private_Pred
      switch_on_term(G_label(1),fail,fail,fail,G_label(1))

label(1)
      allocate(4)
      get_structure(X2F,2,0)
      unify_y_variable(3)
      unify_y_variable(2)
      get_y_variable(1,1)
      get_y_bc_reg(0)
      call(Pred_Name(X6E6C,0),0,4,1,"nl",0)          /* begin sub 1 */
      call(Pred_Name(X6E6C,0),0,4,2,"nl",0)          /* begin sub 2 */
      put_y_value(3,0)
      put_y_value(2,1)
      call(Pred_Name(X77616D5F656D69745F707265645F2461757831,2),1,2,3,"wam_emit_pred_$aux1",2)          /* begin sub 3 */
      put_constant(X2E,0)
      call(Pred_Name(X7772697465,1),0,2,4,"write",1)          /* begin sub 4 */
      call(Pred_Name(X6E6C,0),0,2,5,"nl",0)          /* begin sub 5 */
      call(Pred_Name(X6E6C,0),0,2,6,"nl",0)          /* begin sub 6 */
      put_y_value(1,0)
      put_constant(X74,1)
      put_x_variable(2,2)
      call(Pred_Name(X77616D5F656D6974,3),1,1,7,"wam_emit",3)          /* begin sub 7 */
      cut_y(0)
      deallocate
      execute(Pred_Name(X77616D5F66696E69725F656D697373696F6E5F696E7374,0),1,"wam_finir_emission_inst",0)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wam_emit_pred_$aux1"
#define PRED       X77616D5F656D69745F707265645F2461757831
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      allocate(2)
      get_y_bc_reg(0)
      put_integer(0,2)
      builtin_2(term_eq,1,2)
      put_integer(1,1)
      put_integer(5,2)
      put_y_variable(1,3)
      call(Pred_Name(X7375625F61746F6D,4),0,2,1,"sub_atom",4)          /* begin sub 1 */
      put_y_unsafe_value(1,0)
      call(Pred_Name(X77616D5F656D69745F707265645F2461757832,1),1,1,2,"wam_emit_pred_$aux2",1)          /* begin sub 2 */
      cut_y(0)
      put_constant(X6465665F646972656374697665,0)
      deallocate
      execute(Pred_Name(X777269746571,1),0,"writeq",1)

label(1)
      trust_me_else_fail
      allocate(3)
      get_y_variable(2,0)
      get_y_variable(1,1)
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_variable(0,2)
      call(Pred_Name(X77616D5F656D69745F707265645F2461757833,3),1,3,3,"wam_emit_pred_$aux3",3)          /* begin sub 3 */
      put_structure(X2F,2,1)
      unify_y_local_value(2)
      unify_y_local_value(1)
      put_structure(X6465665F707265646963617465,2,0)
      unify_x_value(1)
      unify_y_local_value(0)
      deallocate
      execute(Pred_Name(X777269746571,1),0,"writeq",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wam_emit_pred_$aux2"
#define PRED       X77616D5F656D69745F707265645F2461757832
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      put_constant(X246578655F,1)
      builtin_2(term_eq,0,1)
      proceed

label(1)
      trust_me_else_fail
      put_constant(X2464796E5F,1)
      builtin_2(term_eq,0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wam_emit_pred_$aux3"
#define PRED       X77616D5F656D69745F707265645F2461757833
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
      put_y_value(0,0)
      get_constant(X7075626C6963,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      get_constant(X70726976617465,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wam_emit"
#define PRED       X77616D5F656D6974
#define ARITY      3

Begin_Private_Pred
      try_me_else(5)
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
      allocate(6)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_y_variable(3,1)
      get_y_variable(0,2)
      get_y_bc_reg(5)
      put_y_variable(4,1)
      call(Pred_Name(X77616D5F656D69745F2461757834,2),1,6,1,"wam_emit_$aux4",2)          /* begin sub 1 */
      cut_y(5)
      put_y_unsafe_value(4,0)
      put_y_value(3,1)
      put_y_variable(1,2)
      call(Pred_Name(X77616D5F656D6974,3),1,3,2,"wam_emit",3)          /* begin sub 2 */
      put_y_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X77616D5F656D6974,3),1,"wam_emit",3)

label(5)
      retry_me_else(6)
      get_x_value(1,2)
      execute(Pred_Name(X64756D6D795F696E737472756374696F6E,1),0,"dummy_instruction",1)

label(6)
      retry_me_else(8)
      switch_on_term(G_label(7),fail,fail,fail,G_label(7))

label(7)
      allocate(1)
      get_structure(X6C6162656C,1,0)
      unify_y_variable(0)
      get_constant(X74,2)
      put_y_value(0,0)
      call(Pred_Name(X77616D5F656D69745F2461757835,1),1,1,3,"wam_emit_$aux5",1)          /* begin sub 3 */
      put_constant(X77616D287E772C20,0)
      put_list(1)
      unify_y_value(0)
      unify_nil
      deallocate
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

label(8)
      trust_me_else_fail
      allocate(1)
      get_y_variable(0,0)
      get_constant(X66,2)
      put_x_value(1,0)
      call(Pred_Name(X77616D5F656D69745F2461757836,1),1,1,4,"wam_emit_$aux6",1)          /* begin sub 4 */
      call(Pred_Name(X6E6C,0),0,1,5,"nl",0)          /* begin sub 5 */
      put_integer(4,0)
      call(Pred_Name(X746162,1),0,1,6,"tab",1)          /* begin sub 6 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X777269746571,1),0,"writeq",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wam_emit_$aux4"
#define PRED       X77616D5F656D69745F2461757834
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      execute(Pred_Name(X7370656369616C5F666F726D,2),1,"special_form",2)

label(1)
      trust_me_else_fail
      get_x_value(0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wam_emit_$aux5"
#define PRED       X77616D5F656D69745F2461757835
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      put_integer(0,1)
      builtin_2(term_neq,0,1)
      neck_cut
      execute(Pred_Name(X77616D5F66696E69725F656D697373696F6E5F696E7374,0),1,"wam_finir_emission_inst",0)

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wam_emit_$aux6"
#define PRED       X77616D5F656D69745F2461757836
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      put_constant(X74,1)
      builtin_2(term_eq,0,1)
      neck_cut
      put_constant(X5B,0)
      execute(Pred_Name(X7772697465,1),0,"write",1)

label(1)
      trust_me_else_fail
      put_constant(X2C,0)
      execute(Pred_Name(X7772697465,1),0,"write",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wam_finir_emission_inst"
#define PRED       X77616D5F66696E69725F656D697373696F6E5F696E7374
#define ARITY      0

Begin_Private_Pred
      allocate(0)
      put_constant(X5D292E,0)
      call(Pred_Name(X7772697465,1),0,0,1,"write",1)          /* begin sub 1 */
      call(Pred_Name(X6E6C,0),0,0,2,"nl",0)          /* begin sub 2 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "special_form"
#define PRED       X7370656369616C5F666F726D
#define ARITY      2

Begin_Public_Pred
      switch_on_term(G_label(2),fail,fail,fail,G_label(1))

label(1)
      switch_on_structure(1,"[(put_x_value/2,3),(cut_x/1,5),(get_x_bc_reg/1,7)]")

label(2)
      try_me_else(4)

label(3)
      get_structure(X7075745F785F76616C7565,2,0)
      unify_integer(255)
      unify_x_variable(0)
      get_structure(X6765745F785F62635F726567,1,1)
      unify_x_value(0)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_structure(X6375745F78,1,0)
      unify_integer(255)
      get_constant(X6E65636B5F637574,1)
      proceed

label(6)
      trust_me_else_fail

label(7)
      get_structure(X6765745F785F62635F726567,1,0)
      unify_integer(255)
      get_structure(X6765745F785F7661726961626C65,2,1)
      unify_integer(255)
      unify_integer(255)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(wamcc7)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X77616D5F656D697373696F6E,"wam_emission")
 Define_Atom(X6669635F6F7574,"fic_out")
 Define_Atom(X77616D5F656D69745F6C73745F70726564,"wam_emit_lst_pred")
 Define_Atom(X706171,"paq")
 Define_Atom(X77616D5F656D69745F70726564,"wam_emit_pred")
 Define_Atom(X2F,"/")
 Define_Atom(X2E,".")
 Define_Atom(X74,"t")
 Define_Atom(X77616D5F656D69745F707265645F2461757831,"wam_emit_pred_$aux1")
 Define_Atom(X6465665F646972656374697665,"def_directive")
 Define_Atom(X6465665F707265646963617465,"def_predicate")
 Define_Atom(X77616D5F656D69745F707265645F2461757832,"wam_emit_pred_$aux2")
 Define_Atom(X246578655F,"$exe_")
 Define_Atom(X2464796E5F,"$dyn_")
 Define_Atom(X77616D5F656D69745F707265645F2461757833,"wam_emit_pred_$aux3")
 Define_Atom(X707562,"pub")
 Define_Atom(X7075626C6963,"public")
 Define_Atom(X70726976617465,"private")
 Define_Atom(X77616D5F656D6974,"wam_emit")
 Define_Atom(X6C6162656C,"label")
 Define_Atom(X77616D287E772C20,"wam(~w, ")
 Define_Atom(X66,"f")
 Define_Atom(X77616D5F656D69745F2461757834,"wam_emit_$aux4")
 Define_Atom(X77616D5F656D69745F2461757835,"wam_emit_$aux5")
 Define_Atom(X77616D5F656D69745F2461757836,"wam_emit_$aux6")
 Define_Atom(X5B,"[")
 Define_Atom(X2C,",")
 Define_Atom(X77616D5F66696E69725F656D697373696F6E5F696E7374,"wam_finir_emission_inst")
 Define_Atom(X5D292E,"]).")
 Define_Atom(X7370656369616C5F666F726D,"special_form")
 Define_Atom(X7075745F785F76616C7565,"put_x_value")
 Define_Atom(X6765745F785F62635F726567,"get_x_bc_reg")
 Define_Atom(X6375745F78,"cut_x")
 Define_Atom(X6E65636B5F637574,"neck_cut")
 Define_Atom(X6765745F785F7661726961626C65,"get_x_variable")


 Define_Pred(X77616D5F656D697373696F6E,1,1)

 Define_Pred(X77616D5F656D69745F6C73745F70726564,1,0)

 Define_Pred(X77616D5F656D69745F70726564,2,0)

 Define_Pred(X77616D5F656D69745F707265645F2461757831,2,0)

 Define_Pred(X77616D5F656D69745F707265645F2461757832,1,0)

 Define_Pred(X77616D5F656D69745F707265645F2461757833,3,0)

 Define_Pred(X77616D5F656D6974,3,0)

 Define_Pred(X77616D5F656D69745F2461757834,2,0)

 Define_Pred(X77616D5F656D69745F2461757835,1,0)

 Define_Pred(X77616D5F656D69745F2461757836,1,0)

 Define_Pred(X77616D5F66696E69725F656D697373696F6E5F696E7374,0,0)

 Define_Pred(X7370656369616C5F666F726D,2,1)
 Define_Switch_STC_Table(Swt_Table_Name(X7370656369616C5F666F726D,2,1,stc),3)
     Define_Switch_STC(X7075745F785F76616C7565,2,Label_Pred_Name(X7370656369616C5F666F726D,2,3))
     Define_Switch_STC(X6375745F78,1,Label_Pred_Name(X7370656369616C5F666F726D,2,5))
     Define_Switch_STC(X6765745F785F62635F726567,1,Label_Pred_Name(X7370656369616C5F666F726D,2,7))

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(wamcc7)



End_Exec_Directives
