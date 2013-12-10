/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : write.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "write.h"
#include "write.usr"


#define ASCII_PRED "write"
#define PRED       X7772697465
#define ARITY      1

Begin_Public_Pred
      pragma_c(Write_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "writeq"
#define PRED       X777269746571
#define ARITY      1

Begin_Public_Pred
      pragma_c(Writeq_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "write_canonical"
#define PRED       X77726974655F63616E6F6E6963616C
#define ARITY      1

Begin_Public_Pred
      pragma_c(Write_Canonical_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "write_term"
#define PRED       X77726974655F7465726D
#define ARITY      2

Begin_Public_Pred
      allocate(5)
      get_y_variable(4,0)
      put_x_value(1,0)
      put_y_variable(3,1)
      put_y_variable(2,2)
      put_y_variable(1,3)
      put_y_variable(0,4)
      call(Pred_Name(X6765745F706172616D73,5),1,5,1,"get_params",5)          /* begin sub 1 */
      put_y_value(4,0)
      put_y_unsafe_value(3,1)
      put_y_unsafe_value(2,2)
      put_y_unsafe_value(1,3)
      put_y_unsafe_value(0,4)
      deallocate
      execute(Pred_Name(X77726974655F7465726D,5),1,"write_term",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "write_term"
#define PRED       X77726974655F7465726D
#define ARITY      5

Begin_Private_Pred
      pragma_c(Write_Term_5)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "get_params"
#define PRED       X6765745F706172616D73
#define ARITY      5

Begin_Private_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_integer(-1,1)
      get_integer(0,2)
      get_integer(1,3)
      get_integer(1,4)
      proceed

label(3)
      trust_me_else_fail

label(4)
      get_list(0)
      unify_x_variable(0)
      unify_x_variable(9)
      get_x_variable(8,1)
      get_x_variable(7,2)
      get_x_variable(6,3)
      get_x_variable(5,4)
      put_x_value(9,1)
      put_x_value(8,2)
      put_x_value(7,3)
      put_x_value(6,4)
      execute(Pred_Name(X6765745F706172616D7331,6),1,"get_params1",6)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "get_params1"
#define PRED       X6765745F706172616D7331
#define ARITY      6

Begin_Private_Pred
      switch_on_term(G_label(2),fail,fail,fail,G_label(1))

label(1)
      switch_on_structure(1,"[(max_depth/1,3),(quoted/1,5),(ignore_ops/1,7),(numbervars/1,9)]")

label(2)
      try_me_else(4)

label(3)
      get_structure(X6D61785F6465707468,1,0)
      unify_x_variable(0)
      get_x_value(0,2)
      builtin_1(integer,0)
      put_x_value(1,0)
      put_x_variable(1,1)
      put_x_value(3,2)
      put_x_value(4,3)
      put_x_value(5,4)
      execute(Pred_Name(X6765745F706172616D73,5),1,"get_params",5)

label(4)
      retry_me_else(6)

label(5)
      allocate(4)
      get_structure(X71756F746564,1,0)
      unify_x_variable(0)
      get_y_variable(3,1)
      get_y_variable(2,2)
      get_y_variable(1,4)
      get_y_variable(0,5)
      put_x_value(3,1)
      call(Pred_Name(X6765745F706172616D73315F2461757831,2),1,4,1,"get_params1_$aux1",2)          /* begin sub 1 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_x_variable(2,2)
      put_y_value(1,3)
      put_y_value(0,4)
      deallocate
      execute(Pred_Name(X6765745F706172616D73,5),1,"get_params",5)

label(6)
      retry_me_else(8)

label(7)
      allocate(4)
      get_structure(X69676E6F72655F6F7073,1,0)
      unify_x_variable(0)
      get_y_variable(3,1)
      get_y_variable(2,2)
      get_y_variable(1,3)
      get_y_variable(0,5)
      put_x_value(4,1)
      call(Pred_Name(X6765745F706172616D73315F2461757832,2),1,4,2,"get_params1_$aux2",2)          /* begin sub 2 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_x_variable(3,3)
      put_y_value(0,4)
      deallocate
      execute(Pred_Name(X6765745F706172616D73,5),1,"get_params",5)

label(8)
      trust_me_else_fail

label(9)
      allocate(4)
      get_structure(X6E756D62657276617273,1,0)
      unify_x_variable(0)
      get_y_variable(3,1)
      get_y_variable(2,2)
      get_y_variable(1,3)
      get_y_variable(0,4)
      put_x_value(5,1)
      call(Pred_Name(X6765745F706172616D73315F2461757833,2),1,4,3,"get_params1_$aux3",2)          /* begin sub 3 */
      put_y_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      put_y_value(0,3)
      put_x_variable(4,4)
      deallocate
      execute(Pred_Name(X6765745F706172616D73,5),1,"get_params",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "get_params1_$aux1"
#define PRED       X6765745F706172616D73315F2461757831
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      put_constant(X66616C7365,2)
      builtin_2(term_eq,0,2)
      neck_cut
      get_integer(0,1)
      proceed

label(1)
      trust_me_else_fail
      get_integer(1,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "get_params1_$aux2"
#define PRED       X6765745F706172616D73315F2461757832
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      put_constant(X74727565,2)
      builtin_2(term_eq,0,2)
      neck_cut
      get_integer(0,1)
      proceed

label(1)
      trust_me_else_fail
      get_integer(1,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "get_params1_$aux3"
#define PRED       X6765745F706172616D73315F2461757833
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      put_constant(X66616C7365,2)
      builtin_2(term_eq,0,2)
      neck_cut
      get_integer(0,1)
      proceed

label(1)
      trust_me_else_fail
      get_integer(1,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "pp_clause"
#define PRED       X70705F636C61757365
#define ARITY      1

Begin_Public_Pred
      allocate(3)
      get_y_bc_reg(2)
      put_y_variable(1,1)
      put_y_variable(0,2)
      call(Pred_Name(X70705F636C617573655F2461757834,3),1,3,1,"pp_clause_$aux4",3)          /* begin sub 1 */
      cut_y(2)
      put_y_unsafe_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X70705F636C61757365,2),1,"pp_clause",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "pp_clause_$aux4"
#define PRED       X70705F636C617573655F2461757834
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



#define ASCII_PRED "pp_clause"
#define PRED       X70705F636C61757365
#define ARITY      2

Begin_Public_Pred
      allocate(3)
      get_y_variable(1,0)
      get_y_variable(0,1)
      put_y_value(1,0)
      put_integer(0,1)
      put_y_variable(2,2)
      call(Pred_Name(X6E756D62657276617273,3),1,3,1,"numbervars",3)          /* begin sub 1 */
      put_y_value(0,0)
      put_y_unsafe_value(2,1)
      put_x_variable(2,2)
      call(Pred_Name(X6E756D62657276617273,3),1,2,2,"numbervars",3)          /* begin sub 2 */
      put_y_value(1,0)
      call(Pred_Name(X777269746571,1),1,1,3,"writeq",1)          /* begin sub 3 */
      put_y_value(0,0)
      call(Pred_Name(X70705F636C617573655F2461757835,1),1,0,4,"pp_clause_$aux5",1)          /* begin sub 4 */
      put_constant(X2E,0)
      call(Pred_Name(X7772697465,1),1,0,5,"write",1)          /* begin sub 5 */
      deallocate
      execute(Pred_Name(X6E6C,0),0,"nl",0)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "pp_clause_$aux5"
#define PRED       X70705F636C617573655F2461757835
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      allocate(1)
      get_y_variable(0,0)
      put_y_value(0,1)
      put_constant(X74727565,0)
      builtin_2(term_neq,1,0)
      neck_cut
      put_constant(X203A2D,0)
      call(Pred_Name(X7772697465,1),1,1,1,"write",1)          /* begin sub 1 */
      call(Pred_Name(X6E6C,0),0,1,2,"nl",0)          /* begin sub 2 */
      put_integer(8,0)
      call(Pred_Name(X746162,1),0,1,3,"tab",1)          /* begin sub 3 */
      put_y_value(0,0)
      put_integer(8,1)
      deallocate
      execute(Pred_Name(X70705F626F6479,2),1,"pp_body",2)

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "pp_body"
#define PRED       X70705F626F6479
#define ARITY      2

Begin_Private_Pred
      try_me_else(8)
      switch_on_term(G_label(2),fail,fail,fail,G_label(1))

label(1)
      switch_on_structure(1,"[((,)/2,3),((->)/2,5),((;)/2,7)]")

label(2)
      try_me_else(4)

label(3)
      allocate(2)
      get_structure(X2C,2,0)
      unify_x_variable(0)
      unify_y_variable(1)
      get_y_variable(0,1)
      neck_cut
      put_y_value(0,1)
      call(Pred_Name(X70705F626F6479,2),1,2,1,"pp_body",2)          /* begin sub 1 */
      put_constant(X2C,0)
      call(Pred_Name(X7772697465,1),1,2,2,"write",1)          /* begin sub 2 */
      call(Pred_Name(X6E6C,0),0,2,3,"nl",0)          /* begin sub 3 */
      put_y_value(0,0)
      call(Pred_Name(X746162,1),0,2,4,"tab",1)          /* begin sub 4 */
      put_y_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X70705F626F6479,2),1,"pp_body",2)

label(4)
      retry_me_else(6)

label(5)
      allocate(2)
      get_structure(X2D3E,2,0)
      unify_x_variable(0)
      unify_y_variable(1)
      get_y_variable(0,1)
      neck_cut
      put_y_value(0,1)
      call(Pred_Name(X70705F626F6479,2),1,2,5,"pp_body",2)          /* begin sub 5 */
      put_constant(X202D3E,0)
      call(Pred_Name(X7772697465,1),1,2,6,"write",1)          /* begin sub 6 */
      call(Pred_Name(X6E6C,0),0,2,7,"nl",0)          /* begin sub 7 */
      put_y_value(0,0)
      call(Pred_Name(X746162,1),0,2,8,"tab",1)          /* begin sub 8 */
      put_y_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X70705F626F6479,2),1,"pp_body",2)

label(6)
      trust_me_else_fail

label(7)
      allocate(4)
      get_structure(X3B,2,0)
      unify_y_variable(3)
      unify_y_variable(1)
      get_y_variable(0,1)
      neck_cut
      math_load_y_value(0,1)
      put_integer(4,0)
      function_2(add,0,1,0)
      get_y_variable(2,0)
      put_constant(X28202020,0)
      call(Pred_Name(X7772697465,1),1,4,9,"write",1)          /* begin sub 9 */
      put_y_value(3,0)
      put_y_unsafe_value(2,1)
      call(Pred_Name(X70705F626F6479,2),1,2,10,"pp_body",2)          /* begin sub 10 */
      call(Pred_Name(X6E6C,0),0,2,11,"nl",0)          /* begin sub 11 */
      put_y_value(0,0)
      call(Pred_Name(X746162,1),0,2,12,"tab",1)          /* begin sub 12 */
      put_constant(X3B202020,0)
      call(Pred_Name(X7772697465,1),1,2,13,"write",1)          /* begin sub 13 */
      put_y_value(1,0)
      put_y_value(0,1)
      call(Pred_Name(X70705F626F64795F6F72,2),1,1,14,"pp_body_or",2)          /* begin sub 14 */
      call(Pred_Name(X6E6C,0),0,1,15,"nl",0)          /* begin sub 15 */
      put_y_value(0,0)
      call(Pred_Name(X746162,1),0,0,16,"tab",1)          /* begin sub 16 */
      put_constant(X29,0)
      deallocate
      execute(Pred_Name(X7772697465,1),1,"write",1)

label(8)
      trust_me_else_fail
      execute(Pred_Name(X777269746571,1),1,"writeq",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "pp_body_or"
#define PRED       X70705F626F64795F6F72
#define ARITY      2

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,fail,fail,G_label(1))

label(1)
      allocate(2)
      get_structure(X3B,2,0)
      unify_x_variable(0)
      unify_y_variable(1)
      get_y_variable(0,1)
      neck_cut
      math_load_y_value(0,2)
      put_integer(4,1)
      function_2(add,1,2,1)
      call(Pred_Name(X70705F626F6479,2),1,2,1,"pp_body",2)          /* begin sub 1 */
      call(Pred_Name(X6E6C,0),0,2,2,"nl",0)          /* begin sub 2 */
      put_y_value(0,0)
      call(Pred_Name(X746162,1),0,2,3,"tab",1)          /* begin sub 3 */
      put_constant(X3B202020,0)
      call(Pred_Name(X7772697465,1),1,2,4,"write",1)          /* begin sub 4 */
      put_y_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X70705F626F64795F6F72,2),1,"pp_body_or",2)

label(2)
      trust_me_else_fail
      execute(Pred_Name(X70705F626F6479,2),1,"pp_body",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "numbervars"
#define PRED       X6E756D62657276617273
#define ARITY      3

Begin_Public_Pred
      try_me_else(1)
      builtin_1(var,0)
      neck_cut
      get_structure(X24564152,1,0)
      unify_x_local_value(1)
      math_load_x_value(1,1)
      function_1(inc,0,1)
      get_x_value(2,0)
      proceed

label(1)
      retry_me_else(2)
      builtin_1(atomic,0)
      neck_cut
      get_x_value(1,2)
      proceed

label(2)
      retry_me_else(4)
      switch_on_term(G_label(3),fail,fail,G_label(3),fail)

label(3)
      allocate(3)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_y_variable(0,2)
      neck_cut
      put_y_variable(1,2)
      call(Pred_Name(X6E756D62657276617273,3),1,3,1,"numbervars",3)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X6E756D62657276617273,3),1,"numbervars",3)

label(4)
      trust_me_else_fail
      get_x_variable(5,0)
      get_x_variable(3,1)
      get_x_variable(4,2)
      put_x_variable(0,2)
      put_x_variable(1,0)
      builtin_3(functor,5,2,0)
      put_integer(0,0)
      put_x_value(5,2)
      execute(Pred_Name(X6E756D62657276617273,5),1,"numbervars",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "numbervars"
#define PRED       X6E756D62657276617273
#define ARITY      5

Begin_Private_Pred
      execute(Pred_Name(X6E756D626572766172735F2461757836,5),1,"numbervars_$aux6",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "numbervars_$aux6"
#define PRED       X6E756D626572766172735F2461757836
#define ARITY      5

Begin_Private_Pred
      try_me_else(1)
      math_load_x_value(0,0)
      math_load_x_value(1,1)
      builtin_2(eq,0,1)
      neck_cut
      get_x_value(3,4)
      proceed

label(1)
      trust_me_else_fail
      allocate(5)
      get_y_variable(3,1)
      get_y_variable(2,2)
      get_y_variable(0,4)
      math_load_x_value(0,0)
      function_1(inc,0,0)
      get_y_variable(4,0)
      put_y_value(4,4)
      put_y_value(2,2)
      put_x_variable(0,1)
      builtin_3(arg,4,2,1)
      put_x_value(3,1)
      put_y_variable(1,2)
      call(Pred_Name(X6E756D62657276617273,3),1,5,1,"numbervars",3)          /* begin sub 1 */
      put_y_unsafe_value(4,0)
      put_y_value(3,1)
      put_y_value(2,2)
      put_y_unsafe_value(1,3)
      put_y_value(0,4)
      deallocate
      execute(Pred_Name(X6E756D62657276617273,5),1,"numbervars",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(write)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X7772697465,"write")
 Define_Atom(X777269746571,"writeq")
 Define_Atom(X77726974655F63616E6F6E6963616C,"write_canonical")
 Define_Atom(X77726974655F7465726D,"write_term")
 Define_Atom(X6765745F706172616D73,"get_params")
 Define_Atom(X6765745F706172616D7331,"get_params1")
 Define_Atom(X6D61785F6465707468,"max_depth")
 Define_Atom(X71756F746564,"quoted")
 Define_Atom(X69676E6F72655F6F7073,"ignore_ops")
 Define_Atom(X6E756D62657276617273,"numbervars")
 Define_Atom(X6765745F706172616D73315F2461757831,"get_params1_$aux1")
 Define_Atom(X66616C7365,"false")
 Define_Atom(X6765745F706172616D73315F2461757832,"get_params1_$aux2")
 Define_Atom(X74727565,"true")
 Define_Atom(X6765745F706172616D73315F2461757833,"get_params1_$aux3")
 Define_Atom(X70705F636C61757365,"pp_clause")
 Define_Atom(X70705F636C617573655F2461757834,"pp_clause_$aux4")
 Define_Atom(X3A2D,":-")
 Define_Atom(X2E,".")
 Define_Atom(X70705F636C617573655F2461757835,"pp_clause_$aux5")
 Define_Atom(X203A2D," :-")
 Define_Atom(X70705F626F6479,"pp_body")
 Define_Atom(X2C,",")
 Define_Atom(X2D3E,"->")
 Define_Atom(X202D3E," ->")
 Define_Atom(X3B,";")
 Define_Atom(X28202020,"(   ")
 Define_Atom(X3B202020,";   ")
 Define_Atom(X29,")")
 Define_Atom(X70705F626F64795F6F72,"pp_body_or")
 Define_Atom(X24564152,"$VAR")
 Define_Atom(X6E756D626572766172735F2461757836,"numbervars_$aux6")


 Define_Pred(X7772697465,1,1)

 Define_Pred(X777269746571,1,1)

 Define_Pred(X77726974655F63616E6F6E6963616C,1,1)

 Define_Pred(X77726974655F7465726D,2,1)

 Define_Pred(X77726974655F7465726D,5,0)

 Define_Pred(X6765745F706172616D73,5,0)

 Define_Pred(X6765745F706172616D7331,6,0)
 Define_Switch_STC_Table(Swt_Table_Name(X6765745F706172616D7331,6,1,stc),4)
     Define_Switch_STC(X6D61785F6465707468,1,Label_Pred_Name(X6765745F706172616D7331,6,3))
     Define_Switch_STC(X71756F746564,1,Label_Pred_Name(X6765745F706172616D7331,6,5))
     Define_Switch_STC(X69676E6F72655F6F7073,1,Label_Pred_Name(X6765745F706172616D7331,6,7))
     Define_Switch_STC(X6E756D62657276617273,1,Label_Pred_Name(X6765745F706172616D7331,6,9))

 Define_Pred(X6765745F706172616D73315F2461757831,2,0)

 Define_Pred(X6765745F706172616D73315F2461757832,2,0)

 Define_Pred(X6765745F706172616D73315F2461757833,2,0)

 Define_Pred(X70705F636C61757365,1,1)

 Define_Pred(X70705F636C617573655F2461757834,3,0)

 Define_Pred(X70705F636C61757365,2,1)

 Define_Pred(X70705F636C617573655F2461757835,1,0)

 Define_Pred(X70705F626F6479,2,0)
 Define_Switch_STC_Table(Swt_Table_Name(X70705F626F6479,2,1,stc),3)
     Define_Switch_STC(X2C,2,Label_Pred_Name(X70705F626F6479,2,3))
     Define_Switch_STC(X2D3E,2,Label_Pred_Name(X70705F626F6479,2,5))
     Define_Switch_STC(X3B,2,Label_Pred_Name(X70705F626F6479,2,7))

 Define_Pred(X70705F626F64795F6F72,2,0)

 Define_Pred(X6E756D62657276617273,3,1)

 Define_Pred(X6E756D62657276617273,5,0)

 Define_Pred(X6E756D626572766172735F2461757836,5,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(write)



End_Exec_Directives
