/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : list.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "list.h"
#include "list.usr"


#define ASCII_PRED "append"
#define PRED       X617070656E64
#define ARITY      3

Begin_Public_Pred
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
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      get_list(2)
      unify_x_value(3)
      unify_x_variable(2)
      execute(Pred_Name(X617070656E64,3),1,"append",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "member"
#define PRED       X6D656D626572
#define ARITY      2

Begin_Public_Pred
      get_list(1)
      unify_x_variable(1)
      unify_x_variable(2)
      execute(Pred_Name(X6D656D6265725F2461757831,3),1,"member_$aux1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "member_$aux1"
#define PRED       X6D656D6265725F2461757831
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      get_x_value(1,0)
      proceed

label(1)
      trust_me_else_fail
      put_x_value(2,1)
      execute(Pred_Name(X6D656D626572,2),1,"member",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "memberchk"
#define PRED       X6D656D62657263686B
#define ARITY      2

Begin_Public_Pred
      get_list(1)
      unify_x_variable(1)
      unify_x_variable(2)
      get_x_bc_reg(3)
      execute(Pred_Name(X6D656D62657263686B5F2461757832,4),1,"memberchk_$aux2",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "memberchk_$aux2"
#define PRED       X6D656D62657263686B5F2461757832
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      get_x_value(1,0)
      cut_x(3)
      proceed

label(1)
      trust_me_else_fail
      put_x_value(2,1)
      execute(Pred_Name(X6D656D62657263686B,2),1,"memberchk",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "reverse"
#define PRED       X72657665727365
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
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      put_list(2)
      unify_x_value(3)
      unify_nil
      execute(Pred_Name(X7265766572736531,3),1,"reverse1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "reverse1"
#define PRED       X7265766572736531
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
      get_list(0)
      unify_x_variable(4)
      unify_x_variable(0)
      get_x_variable(3,2)
      put_list(2)
      unify_x_value(4)
      unify_x_local_value(3)
      execute(Pred_Name(X7265766572736531,3),1,"reverse1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "delete"
#define PRED       X64656C657465
#define ARITY      3

Begin_Public_Pred
      switch_on_term(G_label(2),G_label(3),fail,G_label(1),fail)

label(1)
      try(5,1)          /* begin sub 1 */
      trust(7)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      get_nil(2)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      builtin_2(term_eq,3,1)
      neck_cut
      execute(Pred_Name(X64656C657465,3),1,"delete",3)

label(6)
      trust_me_else_fail

label(7)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      get_list(2)
      unify_x_value(3)
      unify_x_variable(2)
      execute(Pred_Name(X64656C657465,3),1,"delete",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "select"
#define PRED       X73656C656374
#define ARITY      3

Begin_Public_Pred
      try_me_else(1)
      get_list(1)
      unify_x_local_value(0)
      unify_x_variable(0)
      get_x_value(0,2)
      proceed

label(1)
      trust_me_else_fail
      get_list(1)
      unify_x_variable(3)
      unify_x_variable(1)
      get_list(2)
      unify_x_value(3)
      unify_x_variable(2)
      execute(Pred_Name(X73656C656374,3),1,"select",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "permutation"
#define PRED       X7065726D75746174696F6E
#define ARITY      2

Begin_Public_Pred
      try_me_else(2)
      switch_on_term(G_label(1),G_label(1),fail,fail,fail)

label(1)
      get_nil(0)
      get_nil(1)
      proceed

label(2)
      trust_me_else_fail
      allocate(2)
      get_x_variable(2,0)
      get_list(1)
      unify_x_variable(0)
      unify_y_variable(0)
      put_x_value(2,1)
      put_y_variable(1,2)
      call(Pred_Name(X73656C656374,3),1,2,1,"select",3)          /* begin sub 1 */
      put_y_unsafe_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X7065726D75746174696F6E,2),1,"permutation",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "prefix"
#define PRED       X707265666978
#define ARITY      2

Begin_Public_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      proceed

label(3)
      trust_me_else_fail

label(4)
      get_list(0)
      unify_x_variable(2)
      unify_x_variable(0)
      get_list(1)
      unify_x_value(2)
      unify_x_variable(1)
      execute(Pred_Name(X707265666978,2),1,"prefix",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "suffix"
#define PRED       X737566666978
#define ARITY      2

Begin_Public_Pred
      try_me_else(1)
      get_x_value(0,1)
      proceed

label(1)
      trust_me_else_fail
      get_list(1)
      unify_void(1)
      unify_x_variable(1)
      execute(Pred_Name(X737566666978,2),1,"suffix",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sublist"
#define PRED       X7375626C697374
#define ARITY      2

Begin_Public_Pred
      try_me_else(1)
      get_x_value(0,1)
      proceed

label(1)
      trust_me_else_fail
      get_x_variable(2,0)
      get_list(1)
      unify_x_variable(1)
      unify_x_variable(0)
      execute(Pred_Name(X7375626C69737431,3),1,"sublist1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sublist1"
#define PRED       X7375626C69737431
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      get_x_value(0,2)
      proceed

label(1)
      trust_me_else_fail
      switch_on_term(G_label(3),fail,fail,G_label(2),fail)

label(2)
      try(4,1)          /* begin sub 1 */
      trust(6)

label(3)
      try_me_else(5)

label(4)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      put_x_value(3,1)
      execute(Pred_Name(X7375626C69737431,3),1,"sublist1",3)

label(5)
      trust_me_else_fail

label(6)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      get_list(2)
      unify_x_local_value(1)
      unify_x_variable(2)
      put_x_value(3,1)
      execute(Pred_Name(X7375626C69737431,3),1,"sublist1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "last"
#define PRED       X6C617374
#define ARITY      2

Begin_Public_Pred
      switch_on_term(G_label(1),fail,fail,G_label(1),fail)

label(1)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      get_x_variable(2,1)
      put_x_value(3,1)
      execute(Pred_Name(X6C61737431,3),1,"last1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "last1"
#define PRED       X6C61737431
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
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      put_x_value(3,1)
      execute(Pred_Name(X6C61737431,3),1,"last1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "length"
#define PRED       X6C656E677468
#define ARITY      2

Begin_Public_Pred
      try_me_else(1)
      get_x_variable(2,0)
      builtin_1(integer,1)
      neck_cut
      math_load_x_value(1,1)
      put_integer(0,0)
      builtin_2(gte,1,0)
      put_x_value(1,0)
      put_x_value(2,1)
      execute(Pred_Name(X6D616B655F6C697374,2),1,"make_list",2)

label(1)
      trust_me_else_fail
      get_x_variable(2,1)
      put_integer(0,1)
      execute(Pred_Name(X6C656E677468,3),1,"length",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "length"
#define PRED       X6C656E677468
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
      get_list(0)
      unify_void(1)
      unify_x_variable(0)
      math_load_x_value(1,1)
      function_1(inc,1,1)
      execute(Pred_Name(X6C656E677468,3),1,"length",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "make_list"
#define PRED       X6D616B655F6C697374
#define ARITY      2

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,G_label(1),fail,fail)

label(1)
      get_integer(0,0)
      get_nil(1)
      neck_cut
      proceed

label(2)
      trust_me_else_fail
      get_list(1)
      unify_void(1)
      unify_x_variable(1)
      math_load_x_value(0,0)
      function_1(dec,0,0)
      execute(Pred_Name(X6D616B655F6C697374,2),1,"make_list",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "nth"
#define PRED       X6E7468
#define ARITY      3

Begin_Public_Pred
      try_me_else(1)
      builtin_1(integer,0)
      neck_cut
      math_load_x_value(0,0)
      put_integer(1,3)
      builtin_2(gte,0,3)
      execute(Pred_Name(X6E746831,3),1,"nth1",3)

label(1)
      trust_me_else_fail
      get_x_variable(3,0)
      builtin_1(var,3)
      put_x_value(1,0)
      put_x_value(2,1)
      put_integer(1,2)
      execute(Pred_Name(X6E746832,4),1,"nth2",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "nth1"
#define PRED       X6E746831
#define ARITY      3

Begin_Private_Pred
      try_me_else(2)
      switch_on_term(G_label(1),fail,G_label(1),fail,fail)

label(1)
      get_integer(1,0)
      get_list(1)
      unify_x_variable(0)
      unify_void(1)
      get_x_value(0,2)
      neck_cut
      proceed

label(2)
      trust_me_else_fail
      get_list(1)
      unify_void(1)
      unify_x_variable(1)
      math_load_x_value(0,0)
      function_1(dec,0,0)
      execute(Pred_Name(X6E746831,3),1,"nth1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "nth2"
#define PRED       X6E746832
#define ARITY      4

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
      unify_void(1)
      get_x_value(0,1)
      get_x_value(2,3)
      proceed

label(4)
      trust_me_else_fail

label(5)
      get_list(0)
      unify_void(1)
      unify_x_variable(0)
      math_load_x_value(2,2)
      function_1(inc,2,2)
      execute(Pred_Name(X6E746832,4),1,"nth2",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "max_list"
#define PRED       X6D61785F6C697374
#define ARITY      2

Begin_Public_Pred
      switch_on_term(G_label(1),fail,fail,G_label(1),fail)

label(1)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      get_x_variable(2,1)
      put_x_value(3,1)
      execute(Pred_Name(X6D61785F6C69737431,3),1,"max_list1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "max_list1"
#define PRED       X6D61785F6C69737431
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
      math_load_x_value(3,3)
      math_load_x_value(1,1)
      builtin_2(lte,3,1)
      neck_cut
      execute(Pred_Name(X6D61785F6C69737431,3),1,"max_list1",3)

label(6)
      trust_me_else_fail

label(7)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      put_x_value(3,1)
      execute(Pred_Name(X6D61785F6C69737431,3),1,"max_list1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "min_list"
#define PRED       X6D696E5F6C697374
#define ARITY      2

Begin_Public_Pred
      switch_on_term(G_label(1),fail,fail,G_label(1),fail)

label(1)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      get_x_variable(2,1)
      put_x_value(3,1)
      execute(Pred_Name(X6D696E5F6C69737431,3),1,"min_list1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "min_list1"
#define PRED       X6D696E5F6C69737431
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
      math_load_x_value(3,3)
      math_load_x_value(1,1)
      builtin_2(gte,3,1)
      neck_cut
      execute(Pred_Name(X6D696E5F6C69737431,3),1,"min_list1",3)

label(6)
      trust_me_else_fail

label(7)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      put_x_value(3,1)
      execute(Pred_Name(X6D696E5F6C69737431,3),1,"min_list1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sum_list"
#define PRED       X73756D5F6C697374
#define ARITY      2

Begin_Public_Pred
      get_x_variable(2,1)
      put_integer(0,1)
      execute(Pred_Name(X73756D5F6C69737431,3),1,"sum_list1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "sum_list1"
#define PRED       X73756D5F6C69737431
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
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      math_load_x_value(3,3)
      math_load_x_value(1,1)
      function_2(add,1,3,1)
      execute(Pred_Name(X73756D5F6C69737431,3),1,"sum_list1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(list)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X617070656E64,"append")
 Define_Atom(X6D656D626572,"member")
 Define_Atom(X6D656D6265725F2461757831,"member_$aux1")
 Define_Atom(X6D656D62657263686B,"memberchk")
 Define_Atom(X6D656D62657263686B5F2461757832,"memberchk_$aux2")
 Define_Atom(X72657665727365,"reverse")
 Define_Atom(X7265766572736531,"reverse1")
 Define_Atom(X64656C657465,"delete")
 Define_Atom(X73656C656374,"select")
 Define_Atom(X7065726D75746174696F6E,"permutation")
 Define_Atom(X707265666978,"prefix")
 Define_Atom(X737566666978,"suffix")
 Define_Atom(X7375626C697374,"sublist")
 Define_Atom(X7375626C69737431,"sublist1")
 Define_Atom(X6C617374,"last")
 Define_Atom(X6C61737431,"last1")
 Define_Atom(X6C656E677468,"length")
 Define_Atom(X6D616B655F6C697374,"make_list")
 Define_Atom(X6E7468,"nth")
 Define_Atom(X6E746831,"nth1")
 Define_Atom(X6E746832,"nth2")
 Define_Atom(X6D61785F6C697374,"max_list")
 Define_Atom(X6D61785F6C69737431,"max_list1")
 Define_Atom(X6D696E5F6C697374,"min_list")
 Define_Atom(X6D696E5F6C69737431,"min_list1")
 Define_Atom(X73756D5F6C697374,"sum_list")
 Define_Atom(X73756D5F6C69737431,"sum_list1")


 Define_Pred(X617070656E64,3,1)

 Define_Pred(X6D656D626572,2,1)

 Define_Pred(X6D656D6265725F2461757831,3,0)

 Define_Pred(X6D656D62657263686B,2,1)

 Define_Pred(X6D656D62657263686B5F2461757832,4,0)

 Define_Pred(X72657665727365,2,1)

 Define_Pred(X7265766572736531,3,0)

 Define_Pred(X64656C657465,3,1)

 Define_Pred(X73656C656374,3,1)

 Define_Pred(X7065726D75746174696F6E,2,1)

 Define_Pred(X707265666978,2,1)

 Define_Pred(X737566666978,2,1)

 Define_Pred(X7375626C697374,2,1)

 Define_Pred(X7375626C69737431,3,0)

 Define_Pred(X6C617374,2,1)

 Define_Pred(X6C61737431,3,0)

 Define_Pred(X6C656E677468,2,1)

 Define_Pred(X6C656E677468,3,0)

 Define_Pred(X6D616B655F6C697374,2,0)

 Define_Pred(X6E7468,3,1)

 Define_Pred(X6E746831,3,0)

 Define_Pred(X6E746832,4,0)

 Define_Pred(X6D61785F6C697374,2,1)

 Define_Pred(X6D61785F6C69737431,3,0)

 Define_Pred(X6D696E5F6C697374,2,1)

 Define_Pred(X6D696E5F6C69737431,3,0)

 Define_Pred(X73756D5F6C697374,2,1)

 Define_Pred(X73756D5F6C69737431,3,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(list)



End_Exec_Directives
