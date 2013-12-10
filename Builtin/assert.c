/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : assert.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "assert.h"
#include "assert.usr"


#define ASCII_PRED "asserta"
#define PRED       X61737365727461
#define ARITY      1

Begin_Public_Pred
      allocate(3)
      get_y_bc_reg(2)
      put_y_variable(1,1)
      put_y_variable(0,2)
      call(Pred_Name(X617373657274615F2461757831,3),1,3,1,"asserta_$aux1",3)          /* begin sub 1 */
      cut_y(2)
      put_list(0)
      unify_y_local_value(1)
      unify_y_local_value(0)
      deallocate
      execute(Pred_Name(X6173736572746131,1),1,"asserta1",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "asserta_$aux1"
#define PRED       X617373657274615F2461757831
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      get_structure(X3A2D,2,0)
      unify_x_local_value(1)
      unify_x_local_value(2)
      proceed

label(1)
      trust_me_else_fail
      get_x_value(1,0)
      get_constant(X74727565,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "asserta1"
#define PRED       X6173736572746131
#define ARITY      1

Begin_Private_Pred
      pragma_c(Asserta1_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "assertz"
#define PRED       X6173736572747A
#define ARITY      1

Begin_Public_Pred
      allocate(3)
      get_y_bc_reg(2)
      put_y_variable(1,1)
      put_y_variable(0,2)
      call(Pred_Name(X6173736572747A5F2461757832,3),1,3,1,"assertz_$aux2",3)          /* begin sub 1 */
      cut_y(2)
      put_list(0)
      unify_y_local_value(1)
      unify_y_local_value(0)
      deallocate
      execute(Pred_Name(X6173736572747A31,1),1,"assertz1",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "assertz_$aux2"
#define PRED       X6173736572747A5F2461757832
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      get_structure(X3A2D,2,0)
      unify_x_local_value(1)
      unify_x_local_value(2)
      proceed

label(1)
      trust_me_else_fail
      get_x_value(1,0)
      get_constant(X74727565,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "assertz1"
#define PRED       X6173736572747A31
#define ARITY      1

Begin_Private_Pred
      pragma_c(Assertz1_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "clause"
#define PRED       X636C61757365
#define ARITY      2

Begin_Public_Pred
      get_x_variable(2,0)
      put_list(0)
      unify_x_local_value(2)
      unify_x_local_value(1)
      execute(Pred_Name(X636C6175736531,1),1,"clause1",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "clause1"
#define PRED       X636C6175736531
#define ARITY      1

Begin_Public_Pred
      pragma_c(Clause1_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "retract"
#define PRED       X72657472616374
#define ARITY      1

Begin_Public_Pred
      allocate(3)
      get_y_bc_reg(2)
      put_y_variable(1,1)
      put_y_variable(0,2)
      call(Pred_Name(X726574726163745F2461757833,3),1,3,1,"retract_$aux3",3)          /* begin sub 1 */
      cut_y(2)
      put_list(0)
      unify_y_local_value(1)
      unify_y_local_value(0)
      call(Pred_Name(X636C6175736531,1),1,0,2,"clause1",1)          /* begin sub 2 */
      pragma_c(Retract_0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "retract_$aux3"
#define PRED       X726574726163745F2461757833
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      get_structure(X3A2D,2,0)
      unify_x_local_value(1)
      unify_x_local_value(2)
      proceed

label(1)
      trust_me_else_fail
      get_x_value(1,0)
      get_constant(X74727565,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "abolish"
#define PRED       X61626F6C697368
#define ARITY      1

Begin_Public_Pred
      switch_on_term(G_label(1),fail,fail,fail,G_label(1))

label(1)
      get_structure(X2F,2,0)
      unify_x_variable(0)
      unify_x_variable(1)
      execute(Pred_Name(X61626F6C697368,2),1,"abolish",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "abolish"
#define PRED       X61626F6C697368
#define ARITY      2

Begin_Public_Pred
      pragma_c(Abolish_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "reinit_predicate"
#define PRED       X7265696E69745F707265646963617465
#define ARITY      1

Begin_Public_Pred
      switch_on_term(G_label(1),fail,fail,fail,G_label(1))

label(1)
      get_structure(X2F,2,0)
      unify_x_variable(0)
      unify_x_variable(1)
      put_integer(2,2)
      execute(Pred_Name(X7265696E69745F707265646963617465,3),1,"reinit_predicate",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "reinit_predicate"
#define PRED       X7265696E69745F707265646963617465
#define ARITY      2

Begin_Public_Pred
      put_integer(2,2)
      execute(Pred_Name(X7265696E69745F707265646963617465,3),1,"reinit_predicate",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "reinit_predicate"
#define PRED       X7265696E69745F707265646963617465
#define ARITY      3

Begin_Private_Pred
      pragma_c(Reinit_Predicate_3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "."
#define PRED       X2E
#define ARITY      2

Begin_Public_Pred
      allocate(1)
      get_y_variable(0,1)
      call(Pred_Name(X636F6E73756C74,1),1,1,1,"consult",1)          /* begin sub 1 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X636F6E73756C74,1),1,"consult",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "consult"
#define PRED       X636F6E73756C74
#define ARITY      1

Begin_Public_Pred
      try_me_else(5)
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      neck_cut
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(1)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(0)
      neck_cut
      call(Pred_Name(X636F6E73756C74,1),1,1,1,"consult",1)          /* begin sub 1 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X636F6E73756C74,1),1,"consult",1)

label(5)
      trust_me_else_fail
      allocate(4)
      get_y_bc_reg(2)
      pragma_c(New_Consult_0)
      put_y_variable(3,1)
      call(Pred_Name(X636F6E73756C745F2461757834,2),1,4,2,"consult_$aux4",2)          /* begin sub 2 */
      put_y_unsafe_value(3,0)
      call(Pred_Name(X736565,1),0,3,3,"see",1)          /* begin sub 3 */
      call(Pred_Name(X726570656174,0),0,3,4,"repeat",0)          /* begin sub 4 */
      put_y_variable(1,0)
      put_structure(X73696E676C65746F6E73,1,2)
      unify_y_variable(0)
      put_list(1)
      unify_x_value(2)
      unify_nil
      call(Pred_Name(X726561645F7465726D,2),0,3,5,"read_term",2)          /* begin sub 5 */
      put_y_unsafe_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X636F6E73756C745F2461757835,3),1,"consult_$aux5",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "consult_$aux5"
#define PRED       X636F6E73756C745F2461757835
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      allocate(0)
      put_constant(X656E645F6F665F66696C65,0)
      builtin_2(term_neq,1,0)
      neck_cut
      put_x_value(1,0)
      put_x_value(2,1)
      call(Pred_Name(X636F6E73756C745F2461757836,2),1,0,1,"consult_$aux6",2)          /* begin sub 1 */
      fail

label(1)
      trust_me_else_fail
      cut_x(0)
      execute(Pred_Name(X7365656E,0),0,"seen",0)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "consult_$aux6"
#define PRED       X636F6E73756C745F2461757836
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      get_structure(X3A2D,1,0)
      unify_x_variable(0)
      neck_cut
      execute(Pred_Name(X657865635F646972656374697665,1),1,"exec_directive",1)

label(1)
      trust_me_else_fail
      execute(Pred_Name(X6164645F636C61757365,2),1,"add_clause",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "consult_$aux4"
#define PRED       X636F6E73756C745F2461757834
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      put_constant(X75736572,2)
      builtin_2(term_eq,0,2)
      neck_cut
      get_constant(X75736572,1)
      proceed

label(1)
      trust_me_else_fail
      execute(Pred_Name(X70726F6C6F675F66696C655F6E616D65,2),1,"prolog_file_name",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "prolog_file_name"
#define PRED       X70726F6C6F675F66696C655F6E616D65
#define ARITY      2

Begin_Private_Pred
      allocate(3)
      get_y_variable(1,0)
      get_y_variable(0,1)
      put_y_value(1,0)
      put_y_variable(2,1)
      call(Pred_Name(X61746F6D5F6C656E677468,2),0,3,1,"atom_length",2)          /* begin sub 1 */
      math_load_y_value(2,1)
      put_integer(2,0)
      function_2(sub,2,1,0)
      put_y_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X70726F6C6F675F66696C655F6E616D655F2461757837,3),1,"prolog_file_name_$aux7",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "prolog_file_name_$aux7"
#define PRED       X70726F6C6F675F66696C655F6E616D655F2461757837
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      allocate(3)
      get_y_variable(0,0)
      get_y_variable(1,1)
      get_y_bc_reg(2)
      put_y_value(0,0)
      put_x_value(2,1)
      put_integer(3,2)
      put_constant(X2E706C,3)
      call(Pred_Name(X7375625F61746F6D,4),0,3,1,"sub_atom",4)          /* begin sub 1 */
      cut_y(2)
      put_y_value(1,0)
      get_y_value(0,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      get_x_variable(3,1)
      put_constant(X2E706C,1)
      put_x_value(3,2)
      execute(Pred_Name(X61746F6D5F636F6E636174,3),0,"atom_concat",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "exec_directive"
#define PRED       X657865635F646972656374697665
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      allocate(2)
      get_y_variable(1,0)
      get_y_bc_reg(0)
      put_y_value(1,4)
      put_x_variable(0,3)
      put_x_variable(1,2)
      builtin_3(functor,4,3,2)
      call(Pred_Name(X657865635F6469726563746976655F2461757838,2),1,2,1,"exec_directive_$aux8",2)          /* begin sub 1 */
      put_constant(X5761726E696E673A20646972656374697665203C7E773E2069676E6F7265647E6E,0)
      put_list(1)
      unify_y_local_value(1)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,1,2,"formata",2)          /* begin sub 2 */
      cut_y(0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      execute(Pred_Name(X657865635F6469726563746976655F2461757839,1),1,"exec_directive_$aux9",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "exec_directive_$aux8"
#define PRED       X657865635F6469726563746976655F2461757838
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      put_constant(X6D61696E,2)
      builtin_2(term_eq,0,2)
      math_load_x_value(1,1)
      put_integer(2,0)
      builtin_2(lte,1,0)
      proceed

label(1)
      trust_me_else_fail
      put_constant(X7075626C6963,2)
      builtin_2(term_eq,0,2)
      put_integer(1,0)
      builtin_2(term_eq,1,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "exec_directive_$aux9"
#define PRED       X657865635F6469726563746976655F2461757839
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      allocate(1)
      get_y_bc_reg(0)
      call(Pred_Name(X63616C6C,1),0,1,1,"call",1)          /* begin sub 1 */
      cut_y(0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      get_x_variable(2,0)
      put_constant(X5761726E696E673A20646972656374697665203C7E773E206661696C65647E6E,0)
      put_list(1)
      unify_x_local_value(2)
      unify_nil
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "add_clause"
#define PRED       X6164645F636C61757365
#define ARITY      2

Begin_Private_Pred
      allocate(7)
      get_y_variable(5,1)
      get_y_bc_reg(6)
      put_y_variable(1,1)
      put_y_variable(0,2)
      call(Pred_Name(X6164645F636C617573655F246175783130,3),1,7,1,"add_clause_$aux10",3)          /* begin sub 1 */
      cut_y(6)
      put_y_value(1,2)
      put_y_variable(3,1)
      put_y_variable(2,0)
      builtin_3(functor,2,1,0)
      put_y_value(5,0)
      put_y_variable(4,1)
      call(Pred_Name(X6765745F73696E676C65746F6E73,2),1,5,2,"get_singletons",2)          /* begin sub 2 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_unsafe_value(4,2)
      call(Pred_Name(X6164645F636C617573655F246175783131,3),1,4,3,"add_clause_$aux11",3)          /* begin sub 3 */
      put_y_unsafe_value(3,0)
      put_y_unsafe_value(2,1)
      put_integer(1,2)
      call(Pred_Name(X7265696E69745F707265646963617465,3),1,2,4,"reinit_predicate",3)          /* begin sub 4 */
      put_list(0)
      unify_y_local_value(1)
      unify_y_local_value(0)
      deallocate
      execute(Pred_Name(X6173736572747A31,1),1,"assertz1",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "add_clause_$aux11"
#define PRED       X6164645F636C617573655F246175783131
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



#define ASCII_PRED "add_clause_$aux10"
#define PRED       X6164645F636C617573655F246175783130
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      get_structure(X3A2D,2,0)
      unify_x_local_value(1)
      unify_x_local_value(2)
      proceed

label(1)
      trust_me_else_fail
      get_x_value(1,0)
      get_constant(X74727565,2)
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
      call(Pred_Name(X6765745F73696E676C65746F6E735F246175783132,3),1,2,1,"get_singletons_$aux12",3)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X6765745F73696E676C65746F6E73,2),1,"get_singletons",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "get_singletons_$aux12"
#define PRED       X6765745F73696E676C65746F6E735F246175783132
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



#define ASCII_PRED "listing"
#define PRED       X6C697374696E67
#define ARITY      1

Begin_Public_Pred
      switch_on_term(G_label(1),fail,fail,fail,G_label(1))

label(1)
      get_structure(X2F,2,0)
      unify_x_variable(2)
      unify_x_variable(1)
      put_x_variable(0,3)
      builtin_3(functor,3,2,1)
      execute(Pred_Name(X6C697374696E675F246175783133,1),1,"listing_$aux13",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "listing_$aux13"
#define PRED       X6C697374696E675F246175783133
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      allocate(2)
      get_y_variable(1,0)
      put_y_value(1,0)
      put_y_variable(0,1)
      call(Pred_Name(X636C61757365,2),1,2,1,"clause",2)          /* begin sub 1 */
      put_y_value(1,0)
      put_y_unsafe_value(0,1)
      call(Pred_Name(X70705F636C61757365,2),0,0,2,"pp_clause",2)          /* begin sub 2 */
      fail

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(assert)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X61737365727461,"asserta")
 Define_Atom(X617373657274615F2461757831,"asserta_$aux1")
 Define_Atom(X3A2D,":-")
 Define_Atom(X74727565,"true")
 Define_Atom(X6173736572746131,"asserta1")
 Define_Atom(X6173736572747A,"assertz")
 Define_Atom(X6173736572747A5F2461757832,"assertz_$aux2")
 Define_Atom(X6173736572747A31,"assertz1")
 Define_Atom(X636C61757365,"clause")
 Define_Atom(X636C6175736531,"clause1")
 Define_Atom(X72657472616374,"retract")
 Define_Atom(X726574726163745F2461757833,"retract_$aux3")
 Define_Atom(X61626F6C697368,"abolish")
 Define_Atom(X2F,"/")
 Define_Atom(X7265696E69745F707265646963617465,"reinit_predicate")
 Define_Atom(X2E,".")
 Define_Atom(X636F6E73756C74,"consult")
 Define_Atom(X73696E676C65746F6E73,"singletons")
 Define_Atom(X636F6E73756C745F2461757835,"consult_$aux5")
 Define_Atom(X656E645F6F665F66696C65,"end_of_file")
 Define_Atom(X636F6E73756C745F2461757836,"consult_$aux6")
 Define_Atom(X636F6E73756C745F2461757834,"consult_$aux4")
 Define_Atom(X75736572,"user")
 Define_Atom(X70726F6C6F675F66696C655F6E616D65,"prolog_file_name")
 Define_Atom(X70726F6C6F675F66696C655F6E616D655F2461757837,"prolog_file_name_$aux7")
 Define_Atom(X2E706C,".pl")
 Define_Atom(X657865635F646972656374697665,"exec_directive")
 Define_Atom(X5761726E696E673A20646972656374697665203C7E773E2069676E6F7265647E6E,"Warning: directive <~w> ignored~n")
 Define_Atom(X657865635F6469726563746976655F2461757838,"exec_directive_$aux8")
 Define_Atom(X6D61696E,"main")
 Define_Atom(X7075626C6963,"public")
 Define_Atom(X657865635F6469726563746976655F2461757839,"exec_directive_$aux9")
 Define_Atom(X5761726E696E673A20646972656374697665203C7E773E206661696C65647E6E,"Warning: directive <~w> failed~n")
 Define_Atom(X6164645F636C61757365,"add_clause")
 Define_Atom(X6164645F636C617573655F246175783131,"add_clause_$aux11")
 Define_Atom(X7B5761726E696E673A207E77202D2073696E676C65746F6E207661726961626C657320696E207E612F7E647D7E6E,"{Warning: ~w - singleton variables in ~a/~d}~n")
 Define_Atom(X6164645F636C617573655F246175783130,"add_clause_$aux10")
 Define_Atom(X6765745F73696E676C65746F6E73,"get_singletons")
 Define_Atom(X3D,"=")
 Define_Atom(X6765745F73696E676C65746F6E735F246175783132,"get_singletons_$aux12")
 Define_Atom(X5F,"_")
 Define_Atom(X6C697374696E67,"listing")
 Define_Atom(X6C697374696E675F246175783133,"listing_$aux13")


 Define_Pred(X61737365727461,1,1)

 Define_Pred(X617373657274615F2461757831,3,0)

 Define_Pred(X6173736572746131,1,0)

 Define_Pred(X6173736572747A,1,1)

 Define_Pred(X6173736572747A5F2461757832,3,0)

 Define_Pred(X6173736572747A31,1,0)

 Define_Pred(X636C61757365,2,1)

 Define_Pred(X636C6175736531,1,1)

 Define_Pred(X72657472616374,1,1)

 Define_Pred(X726574726163745F2461757833,3,0)

 Define_Pred(X61626F6C697368,1,1)

 Define_Pred(X61626F6C697368,2,1)

 Define_Pred(X7265696E69745F707265646963617465,1,1)

 Define_Pred(X7265696E69745F707265646963617465,2,1)

 Define_Pred(X7265696E69745F707265646963617465,3,0)

 Define_Pred(X2E,2,1)

 Define_Pred(X636F6E73756C74,1,1)

 Define_Pred(X636F6E73756C745F2461757835,3,0)

 Define_Pred(X636F6E73756C745F2461757836,2,0)

 Define_Pred(X636F6E73756C745F2461757834,2,0)

 Define_Pred(X70726F6C6F675F66696C655F6E616D65,2,0)

 Define_Pred(X70726F6C6F675F66696C655F6E616D655F2461757837,3,0)

 Define_Pred(X657865635F646972656374697665,1,0)

 Define_Pred(X657865635F6469726563746976655F2461757838,2,0)

 Define_Pred(X657865635F6469726563746976655F2461757839,1,0)

 Define_Pred(X6164645F636C61757365,2,0)

 Define_Pred(X6164645F636C617573655F246175783131,3,0)

 Define_Pred(X6164645F636C617573655F246175783130,3,0)

 Define_Pred(X6765745F73696E676C65746F6E73,2,0)

 Define_Pred(X6765745F73696E676C65746F6E735F246175783132,3,0)

 Define_Pred(X6C697374696E67,1,1)

 Define_Pred(X6C697374696E675F246175783133,1,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(assert)



End_Exec_Directives
