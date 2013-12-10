/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : const.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "const.h"
#include "const.usr"


#define ASCII_PRED "atom_length"
#define PRED       X61746F6D5F6C656E677468
#define ARITY      2

Begin_Public_Pred
      pragma_c(Atom_Length_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "atom_concat"
#define PRED       X61746F6D5F636F6E636174
#define ARITY      3

Begin_Public_Pred
      allocate(4)
      get_y_variable(3,0)
      get_y_variable(2,1)
      get_y_variable(1,2)
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_variable(0,3)
      call(Pred_Name(X61746F6D5F636F6E6361745F646574,4),1,4,1,"atom_concat_det",4)          /* begin sub 1 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_unsafe_value(0,3)
      deallocate
      execute(Pred_Name(X61746F6D5F636F6E6361745F2461757831,4),1,"atom_concat_$aux1",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "atom_concat_$aux1"
#define PRED       X61746F6D5F636F6E6361745F2461757831
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      put_integer(1,0)
      builtin_2(term_eq,3,0)
      neck_cut
      proceed

label(1)
      trust_me_else_fail
      put_integer(2,4)
      builtin_2(term_eq,3,4)
      execute(Pred_Name(X61746F6D5F636F6E6361745F6E6F6E5F646574,3),1,"atom_concat_non_det",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "atom_concat_det"
#define PRED       X61746F6D5F636F6E6361745F646574
#define ARITY      4

Begin_Private_Pred
      pragma_c(Atom_Concat_Det_4)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "atom_concat_non_det"
#define PRED       X61746F6D5F636F6E6361745F6E6F6E5F646574
#define ARITY      3

Begin_Private_Pred
      allocate(5)
      get_y_variable(3,0)
      get_y_variable(1,1)
      put_x_value(2,0)
      put_y_variable(4,1)
      call(Pred_Name(X61746F6D5F636F646573,2),1,5,1,"atom_codes",2)          /* begin sub 1 */
      put_y_variable(2,0)
      put_y_variable(0,1)
      put_y_unsafe_value(4,2)
      call(Pred_Name(X617070656E64,3),0,4,2,"append",3)          /* begin sub 2 */
      put_y_value(3,0)
      put_y_unsafe_value(2,1)
      call(Pred_Name(X61746F6D5F636F646573,2),1,2,3,"atom_codes",2)          /* begin sub 3 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X61746F6D5F636F646573,2),1,"atom_codes",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sub_atom"
#define PRED       X7375625F61746F6D
#define ARITY      4

Begin_Public_Pred
      allocate(11)
      get_y_variable(10,0)
      get_y_variable(9,1)
      get_y_variable(7,2)
      get_y_variable(1,3)
      put_y_value(10,0)
      put_y_variable(4,1)
      call(Pred_Name(X61746F6D5F636F646573,2),1,11,1,"atom_codes",2)          /* begin sub 1 */
      put_y_value(10,0)
      put_y_variable(8,1)
      call(Pred_Name(X61746F6D5F6C656E677468,2),1,10,2,"atom_length",2)          /* begin sub 2 */
      put_y_value(9,0)
      put_y_value(8,1)
      call(Pred_Name(X7375625F61746F6D5F2461757832,2),1,10,3,"sub_atom_$aux2",2)          /* begin sub 3 */
      math_load_y_value(9,0)
      function_1(dec,0,0)
      get_y_variable(6,0)
      put_y_value(7,0)
      put_y_value(8,1)
      put_y_value(6,2)
      call(Pred_Name(X7375625F61746F6D5F2461757833,3),1,9,4,"sub_atom_$aux3",3)          /* begin sub 4 */
      put_y_variable(0,0)
      put_y_value(7,1)
      call(Pred_Name(X6C656E677468,2),0,9,5,"length",2)          /* begin sub 5 */
      put_y_variable(3,0)
      put_y_value(6,1)
      call(Pred_Name(X6C656E677468,2),0,9,6,"length",2)          /* begin sub 6 */
      math_load_y_value(8,1)
      math_load_y_value(7,0)
      function_2(sub,1,1,0)
      math_load_y_value(6,0)
      function_2(sub,1,1,0)
      put_y_variable(5,0)
      call(Pred_Name(X6C656E677468,2),0,6,7,"length",2)          /* begin sub 7 */
      put_y_variable(2,0)
      put_y_unsafe_value(5,1)
      put_y_unsafe_value(4,2)
      call(Pred_Name(X617070656E64,3),0,4,8,"append",3)          /* begin sub 8 */
      put_y_unsafe_value(3,0)
      put_y_value(0,1)
      put_y_unsafe_value(2,2)
      call(Pred_Name(X617070656E64,3),0,2,9,"append",3)          /* begin sub 9 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X61746F6D5F636F646573,2),1,"atom_codes",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sub_atom_$aux3"
#define PRED       X7375625F61746F6D5F2461757833
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      builtin_1(integer,0)
      neck_cut
      proceed

label(1)
      trust_me_else_fail
      allocate(2)
      get_y_variable(1,0)
      math_load_x_value(1,1)
      math_load_x_value(2,2)
      function_2(sub,1,1,2)
      put_integer(0,0)
      put_y_variable(0,2)
      call(Pred_Name(X6C6973745F695F6A,3),1,2,1,"list_i_j",3)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X6D656D626572,2),0,"member",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sub_atom_$aux2"
#define PRED       X7375625F61746F6D5F2461757832
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      builtin_1(integer,0)
      neck_cut
      math_load_x_value(0,0)
      put_integer(1,2)
      builtin_2(gte,0,2)
      math_load_x_value(0,0)
      math_load_x_value(1,1)
      builtin_2(lte,0,1)
      proceed

label(1)
      trust_me_else_fail
      allocate(2)
      get_y_variable(1,0)
      put_integer(1,0)
      put_y_variable(0,2)
      call(Pred_Name(X6C6973745F695F6A,3),1,2,1,"list_i_j",3)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X6D656D626572,2),0,"member",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "list_i_j"
#define PRED       X6C6973745F695F6A
#define ARITY      3

Begin_Private_Pred
      execute(Pred_Name(X6C6973745F695F6A5F2461757834,3),1,"list_i_j_$aux4",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "list_i_j_$aux4"
#define PRED       X6C6973745F695F6A5F2461757834
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      math_load_x_value(0,0)
      math_load_x_value(1,1)
      builtin_2(gt,0,1)
      neck_cut
      get_nil(2)
      proceed

label(1)
      trust_me_else_fail
      get_x_variable(3,0)
      math_load_x_value(3,3)
      function_1(inc,0,3)
      get_list(2)
      unify_x_local_value(3)
      unify_x_variable(2)
      execute(Pred_Name(X6C6973745F695F6A,3),1,"list_i_j",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "char_code"
#define PRED       X636861725F636F6465
#define ARITY      2

Begin_Public_Pred
      pragma_c(Char_Code_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "number_atom"
#define PRED       X6E756D6265725F61746F6D
#define ARITY      2

Begin_Public_Pred
      pragma_c(Number_Atom_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "atom_codes"
#define PRED       X61746F6D5F636F646573
#define ARITY      2

Begin_Public_Pred
      pragma_c(Atom_Codes_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "chars_codes"
#define PRED       X63686172735F636F646573
#define ARITY      2

Begin_Public_Pred
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
      get_list(1)
      unify_x_variable(1)
      unify_y_variable(0)
      call(Pred_Name(X636861725F636F6465,2),1,2,1,"char_code",2)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X63686172735F636F646573,2),1,"chars_codes",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "number_codes"
#define PRED       X6E756D6265725F636F646573
#define ARITY      2

Begin_Public_Pred
      execute(Pred_Name(X6E756D6265725F636F6465735F2461757835,2),1,"number_codes_$aux5",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "number_codes_$aux5"
#define PRED       X6E756D6265725F636F6465735F2461757835
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      allocate(2)
      get_y_variable(0,1)
      builtin_1(nonvar,0)
      neck_cut
      put_y_variable(1,1)
      call(Pred_Name(X6E756D6265725F61746F6D,2),1,2,1,"number_atom",2)          /* begin sub 1 */
      put_y_unsafe_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X61746F6D5F636F646573,2),1,"atom_codes",2)

label(1)
      trust_me_else_fail
      allocate(2)
      get_y_variable(1,0)
      builtin_1(nonvar,1)
      put_y_variable(0,0)
      call(Pred_Name(X61746F6D5F636F646573,2),1,2,2,"atom_codes",2)          /* begin sub 2 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X6E756D6265725F61746F6D,2),1,"number_atom",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "number_chars"
#define PRED       X6E756D6265725F6368617273
#define ARITY      2

Begin_Public_Pred
      execute(Pred_Name(X6E756D6265725F63686172735F2461757836,2),1,"number_chars_$aux6",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "number_chars_$aux6"
#define PRED       X6E756D6265725F63686172735F2461757836
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      allocate(2)
      get_y_variable(1,1)
      builtin_1(nonvar,0)
      neck_cut
      put_y_variable(0,1)
      call(Pred_Name(X6E756D6265725F636F646573,2),1,2,1,"number_codes",2)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X63686172735F636F646573,2),1,"chars_codes",2)

label(1)
      trust_me_else_fail
      allocate(2)
      get_y_variable(1,0)
      builtin_1(nonvar,1)
      put_x_value(1,0)
      put_y_variable(0,1)
      call(Pred_Name(X63686172735F636F646573,2),1,2,2,"chars_codes",2)          /* begin sub 2 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X6E756D6265725F636F646573,2),1,"number_codes",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "atom_chars"
#define PRED       X61746F6D5F6368617273
#define ARITY      2

Begin_Public_Pred
      execute(Pred_Name(X61746F6D5F63686172735F2461757837,2),1,"atom_chars_$aux7",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "atom_chars_$aux7"
#define PRED       X61746F6D5F63686172735F2461757837
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      allocate(2)
      get_y_variable(1,1)
      builtin_1(nonvar,0)
      neck_cut
      put_y_variable(0,1)
      call(Pred_Name(X61746F6D5F636F646573,2),1,2,1,"atom_codes",2)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X63686172735F636F646573,2),1,"chars_codes",2)

label(1)
      trust_me_else_fail
      allocate(2)
      get_y_variable(1,0)
      builtin_1(nonvar,1)
      put_x_value(1,0)
      put_y_variable(0,1)
      call(Pred_Name(X63686172735F636F646573,2),1,2,2,"chars_codes",2)          /* begin sub 2 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X61746F6D5F636F646573,2),1,"atom_codes",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "name"
#define PRED       X6E616D65
#define ARITY      2

Begin_Public_Pred
      execute(Pred_Name(X6E616D655F2461757838,2),1,"name_$aux8",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "name_$aux8"
#define PRED       X6E616D655F2461757838
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      allocate(1)
      get_y_bc_reg(0)
      call(Pred_Name(X6E756D6265725F636F646573,2),1,1,1,"number_codes",2)          /* begin sub 1 */
      cut_y(0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      execute(Pred_Name(X61746F6D5F636F646573,2),1,"atom_codes",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(const)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X61746F6D5F6C656E677468,"atom_length")
 Define_Atom(X61746F6D5F636F6E636174,"atom_concat")
 Define_Atom(X61746F6D5F636F6E6361745F2461757831,"atom_concat_$aux1")
 Define_Atom(X61746F6D5F636F6E6361745F646574,"atom_concat_det")
 Define_Atom(X61746F6D5F636F6E6361745F6E6F6E5F646574,"atom_concat_non_det")
 Define_Atom(X7375625F61746F6D,"sub_atom")
 Define_Atom(X7375625F61746F6D5F2461757833,"sub_atom_$aux3")
 Define_Atom(X7375625F61746F6D5F2461757832,"sub_atom_$aux2")
 Define_Atom(X6C6973745F695F6A,"list_i_j")
 Define_Atom(X6C6973745F695F6A5F2461757834,"list_i_j_$aux4")
 Define_Atom(X636861725F636F6465,"char_code")
 Define_Atom(X6E756D6265725F61746F6D,"number_atom")
 Define_Atom(X61746F6D5F636F646573,"atom_codes")
 Define_Atom(X63686172735F636F646573,"chars_codes")
 Define_Atom(X6E756D6265725F636F646573,"number_codes")
 Define_Atom(X6E756D6265725F636F6465735F2461757835,"number_codes_$aux5")
 Define_Atom(X6E756D6265725F6368617273,"number_chars")
 Define_Atom(X6E756D6265725F63686172735F2461757836,"number_chars_$aux6")
 Define_Atom(X61746F6D5F6368617273,"atom_chars")
 Define_Atom(X61746F6D5F63686172735F2461757837,"atom_chars_$aux7")
 Define_Atom(X6E616D65,"name")
 Define_Atom(X6E616D655F2461757838,"name_$aux8")


 Define_Pred(X61746F6D5F6C656E677468,2,1)

 Define_Pred(X61746F6D5F636F6E636174,3,1)

 Define_Pred(X61746F6D5F636F6E6361745F2461757831,4,0)

 Define_Pred(X61746F6D5F636F6E6361745F646574,4,0)

 Define_Pred(X61746F6D5F636F6E6361745F6E6F6E5F646574,3,0)

 Define_Pred(X7375625F61746F6D,4,1)

 Define_Pred(X7375625F61746F6D5F2461757833,3,0)

 Define_Pred(X7375625F61746F6D5F2461757832,2,0)

 Define_Pred(X6C6973745F695F6A,3,0)

 Define_Pred(X6C6973745F695F6A5F2461757834,3,0)

 Define_Pred(X636861725F636F6465,2,1)

 Define_Pred(X6E756D6265725F61746F6D,2,1)

 Define_Pred(X61746F6D5F636F646573,2,1)

 Define_Pred(X63686172735F636F646573,2,1)

 Define_Pred(X6E756D6265725F636F646573,2,1)

 Define_Pred(X6E756D6265725F636F6465735F2461757835,2,0)

 Define_Pred(X6E756D6265725F6368617273,2,1)

 Define_Pred(X6E756D6265725F63686172735F2461757836,2,0)

 Define_Pred(X61746F6D5F6368617273,2,1)

 Define_Pred(X61746F6D5F63686172735F2461757837,2,0)

 Define_Pred(X6E616D65,2,1)

 Define_Pred(X6E616D655F2461757838,2,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(const)



End_Exec_Directives
