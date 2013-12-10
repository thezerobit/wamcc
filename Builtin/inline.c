/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : ../Builtin/inline.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "inline.h"
#include "inline.usr"


#define ASCII_PRED "="
#define PRED       X3D
#define ARITY      2

Begin_Public_Pred
      get_x_value(0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "arg"
#define PRED       X617267
#define ARITY      3

Begin_Public_Pred
      builtin_3(arg,0,1,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "functor"
#define PRED       X66756E63746F72
#define ARITY      3

Begin_Public_Pred
      builtin_3(functor,0,1,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "=.."
#define PRED       X3D2E2E
#define ARITY      2

Begin_Public_Pred
      builtin_2(term_univ,0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "compare"
#define PRED       X636F6D70617265
#define ARITY      3

Begin_Public_Pred
      builtin_3(compare,0,1,2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "=="
#define PRED       X3D3D
#define ARITY      2

Begin_Public_Pred
      builtin_2(term_eq,0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "\\=="
#define PRED       X5C3D3D
#define ARITY      2

Begin_Public_Pred
      builtin_2(term_neq,0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "@<"
#define PRED       X403C
#define ARITY      2

Begin_Public_Pred
      builtin_2(term_lt,0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "@=<"
#define PRED       X403D3C
#define ARITY      2

Begin_Public_Pred
      builtin_2(term_lte,0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "@>"
#define PRED       X403E
#define ARITY      2

Begin_Public_Pred
      builtin_2(term_gt,0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "@>="
#define PRED       X403E3D
#define ARITY      2

Begin_Public_Pred
      builtin_2(term_gte,0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "var"
#define PRED       X766172
#define ARITY      1

Begin_Public_Pred
      builtin_1(var,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "nonvar"
#define PRED       X6E6F6E766172
#define ARITY      1

Begin_Public_Pred
      builtin_1(nonvar,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "atom"
#define PRED       X61746F6D
#define ARITY      1

Begin_Public_Pred
      builtin_1(atom,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "integer"
#define PRED       X696E7465676572
#define ARITY      1

Begin_Public_Pred
      builtin_1(integer,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "number"
#define PRED       X6E756D626572
#define ARITY      1

Begin_Public_Pred
      builtin_1(number,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "atomic"
#define PRED       X61746F6D6963
#define ARITY      1

Begin_Public_Pred
      builtin_1(atomic,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "compound"
#define PRED       X636F6D706F756E64
#define ARITY      1

Begin_Public_Pred
      builtin_1(compound,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "callable"
#define PRED       X63616C6C61626C65
#define ARITY      1

Begin_Public_Pred
      builtin_1(callable,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "is"
#define PRED       X6973
#define ARITY      2

Begin_Public_Pred
      allocate(2)
      get_y_variable(1,0)
      put_x_value(1,0)
      put_y_variable(0,1)
      call(Pred_Name(X6576616C,2),1,2,1,"eval",2)          /* begin sub 1 */
      put_y_value(1,0)
      get_y_value(0,0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "=:="
#define PRED       X3D3A3D
#define ARITY      2

Begin_Public_Pred
      allocate(3)
      get_y_variable(2,1)
      put_y_variable(1,1)
      call(Pred_Name(X6576616C,2),1,3,1,"eval",2)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_variable(0,1)
      call(Pred_Name(X6576616C,2),1,2,2,"eval",2)          /* begin sub 2 */
      math_load_y_value(1,1)
      math_load_y_value(0,0)
      builtin_2(eq,1,0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "=\\="
#define PRED       X3D5C3D
#define ARITY      2

Begin_Public_Pred
      allocate(3)
      get_y_variable(2,1)
      put_y_variable(1,1)
      call(Pred_Name(X6576616C,2),1,3,1,"eval",2)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_variable(0,1)
      call(Pred_Name(X6576616C,2),1,2,2,"eval",2)          /* begin sub 2 */
      math_load_y_value(1,1)
      math_load_y_value(0,0)
      builtin_2(neq,1,0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "<"
#define PRED       X3C
#define ARITY      2

Begin_Public_Pred
      allocate(3)
      get_y_variable(2,1)
      put_y_variable(1,1)
      call(Pred_Name(X6576616C,2),1,3,1,"eval",2)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_variable(0,1)
      call(Pred_Name(X6576616C,2),1,2,2,"eval",2)          /* begin sub 2 */
      math_load_y_value(1,1)
      math_load_y_value(0,0)
      builtin_2(lt,1,0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "=<"
#define PRED       X3D3C
#define ARITY      2

Begin_Public_Pred
      allocate(3)
      get_y_variable(2,1)
      put_y_variable(1,1)
      call(Pred_Name(X6576616C,2),1,3,1,"eval",2)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_variable(0,1)
      call(Pred_Name(X6576616C,2),1,2,2,"eval",2)          /* begin sub 2 */
      math_load_y_value(1,1)
      math_load_y_value(0,0)
      builtin_2(lte,1,0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED ">"
#define PRED       X3E
#define ARITY      2

Begin_Public_Pred
      allocate(3)
      get_y_variable(2,1)
      put_y_variable(1,1)
      call(Pred_Name(X6576616C,2),1,3,1,"eval",2)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_variable(0,1)
      call(Pred_Name(X6576616C,2),1,2,2,"eval",2)          /* begin sub 2 */
      math_load_y_value(1,1)
      math_load_y_value(0,0)
      builtin_2(gt,1,0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED ">="
#define PRED       X3E3D
#define ARITY      2

Begin_Public_Pred
      allocate(3)
      get_y_variable(2,1)
      put_y_variable(1,1)
      call(Pred_Name(X6576616C,2),1,3,1,"eval",2)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_variable(0,1)
      call(Pred_Name(X6576616C,2),1,2,2,"eval",2)          /* begin sub 2 */
      math_load_y_value(1,1)
      math_load_y_value(0,0)
      builtin_2(gte,1,0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "eval"
#define PRED       X6576616C
#define ARITY      2

Begin_Public_Pred
      try_me_else(1)
      allocate(1)
      get_y_bc_reg(0)
      call(Pred_Name(X6576616C31,2),1,1,1,"eval1",2)          /* begin sub 1 */
      cut_y(0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      allocate(1)
      get_y_variable(0,0)
      put_constant(X4572726F723A20,0)
      call(Pred_Name(X7772697465,1),0,1,2,"write",1)          /* begin sub 2 */
      put_y_value(0,0)
      call(Pred_Name(X7772697465,1),0,0,3,"write",1)          /* begin sub 3 */
      put_constant(X20496C6C6567616C2061726974686D657469632065787072657373696F6E,0)
      call(Pred_Name(X7772697465,1),0,0,4,"write",1)          /* begin sub 4 */
      call(Pred_Name(X6E6C,0),0,0,5,"nl",0)          /* begin sub 5 */
      fail

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "eval1"
#define PRED       X6576616C31
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      builtin_1(var,0)
      neck_cut
      fail

label(1)
      retry_me_else(2)
      get_x_value(0,1)
      builtin_1(integer,0)
      proceed

label(2)
      trust_me_else_fail
      switch_on_term(G_label(4),fail,fail,G_label(5),G_label(3))

label(3)
      switch_on_structure(3,"[((+)/1,7),((-)/1,9),((+)/2,11),((-)/2,13),(* /2,15),(// /2,17),(mod/2,19),(/\ /2,21),(\/ /2,23),(^ /2,25),(\ /1,27),(<< /2,29),(>> /2,31)]")

label(4)
      try_me_else(6)

label(5)
      get_list(0)
      unify_x_variable(0)
      unify_nil
      execute(Pred_Name(X6576616C31,2),1,"eval1",2)

label(6)
      retry_me_else(8)

label(7)
      get_structure(X2B,1,0)
      unify_x_variable(0)
      execute(Pred_Name(X6576616C31,2),1,"eval1",2)

label(8)
      retry_me_else(10)

label(9)
      allocate(2)
      get_structure(X2D,1,0)
      unify_x_variable(0)
      get_y_variable(1,1)
      put_y_variable(0,1)
      call(Pred_Name(X6576616C31,2),1,2,1,"eval1",2)          /* begin sub 1 */
      math_load_y_value(0,0)
      function_1(neg,0,0)
      get_y_value(1,0)
      deallocate
      proceed

label(10)
      retry_me_else(12)

label(11)
      allocate(4)
      get_structure(X2B,2,0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(2,1)
      put_y_variable(1,1)
      call(Pred_Name(X6576616C31,2),1,4,2,"eval1",2)          /* begin sub 2 */
      put_y_value(3,0)
      put_y_variable(0,1)
      call(Pred_Name(X6576616C31,2),1,3,3,"eval1",2)          /* begin sub 3 */
      math_load_y_value(1,1)
      math_load_y_value(0,0)
      function_2(add,0,1,0)
      get_y_value(2,0)
      deallocate
      proceed

label(12)
      retry_me_else(14)

label(13)
      allocate(4)
      get_structure(X2D,2,0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(2,1)
      put_y_variable(1,1)
      call(Pred_Name(X6576616C31,2),1,4,4,"eval1",2)          /* begin sub 4 */
      put_y_value(3,0)
      put_y_variable(0,1)
      call(Pred_Name(X6576616C31,2),1,3,5,"eval1",2)          /* begin sub 5 */
      math_load_y_value(1,1)
      math_load_y_value(0,0)
      function_2(sub,0,1,0)
      get_y_value(2,0)
      deallocate
      proceed

label(14)
      retry_me_else(16)

label(15)
      allocate(4)
      get_structure(X2A,2,0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(2,1)
      put_y_variable(1,1)
      call(Pred_Name(X6576616C31,2),1,4,6,"eval1",2)          /* begin sub 6 */
      put_y_value(3,0)
      put_y_variable(0,1)
      call(Pred_Name(X6576616C31,2),1,3,7,"eval1",2)          /* begin sub 7 */
      math_load_y_value(1,1)
      math_load_y_value(0,0)
      function_2(mul,0,1,0)
      get_y_value(2,0)
      deallocate
      proceed

label(16)
      retry_me_else(18)

label(17)
      allocate(4)
      get_structure(X2F2F,2,0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(2,1)
      put_y_variable(1,1)
      call(Pred_Name(X6576616C31,2),1,4,8,"eval1",2)          /* begin sub 8 */
      put_y_value(3,0)
      put_y_variable(0,1)
      call(Pred_Name(X6576616C31,2),1,3,9,"eval1",2)          /* begin sub 9 */
      math_load_y_value(1,1)
      math_load_y_value(0,0)
      function_2(div,0,1,0)
      get_y_value(2,0)
      deallocate
      proceed

label(18)
      retry_me_else(20)

label(19)
      allocate(4)
      get_structure(X6D6F64,2,0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(2,1)
      put_y_variable(1,1)
      call(Pred_Name(X6576616C31,2),1,4,10,"eval1",2)          /* begin sub 10 */
      put_y_value(3,0)
      put_y_variable(0,1)
      call(Pred_Name(X6576616C31,2),1,3,11,"eval1",2)          /* begin sub 11 */
      math_load_y_value(1,1)
      math_load_y_value(0,0)
      function_2(mod,0,1,0)
      get_y_value(2,0)
      deallocate
      proceed

label(20)
      retry_me_else(22)

label(21)
      allocate(4)
      get_structure(X2F5C,2,0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(2,1)
      put_y_variable(1,1)
      call(Pred_Name(X6576616C31,2),1,4,12,"eval1",2)          /* begin sub 12 */
      put_y_value(3,0)
      put_y_variable(0,1)
      call(Pred_Name(X6576616C31,2),1,3,13,"eval1",2)          /* begin sub 13 */
      math_load_y_value(1,1)
      math_load_y_value(0,0)
      function_2(and,0,1,0)
      get_y_value(2,0)
      deallocate
      proceed

label(22)
      retry_me_else(24)

label(23)
      allocate(4)
      get_structure(X5C2F,2,0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(2,1)
      put_y_variable(1,1)
      call(Pred_Name(X6576616C31,2),1,4,14,"eval1",2)          /* begin sub 14 */
      put_y_value(3,0)
      put_y_variable(0,1)
      call(Pred_Name(X6576616C31,2),1,3,15,"eval1",2)          /* begin sub 15 */
      math_load_y_value(1,1)
      math_load_y_value(0,0)
      function_2(or,0,1,0)
      get_y_value(2,0)
      deallocate
      proceed

label(24)
      retry_me_else(26)

label(25)
      allocate(4)
      get_structure(X5E,2,0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(2,1)
      put_y_variable(1,1)
      call(Pred_Name(X6576616C31,2),1,4,16,"eval1",2)          /* begin sub 16 */
      put_y_value(3,0)
      put_y_variable(0,1)
      call(Pred_Name(X6576616C31,2),1,3,17,"eval1",2)          /* begin sub 17 */
      math_load_y_value(1,1)
      math_load_y_value(0,0)
      function_2(xor,0,1,0)
      get_y_value(2,0)
      deallocate
      proceed

label(26)
      retry_me_else(28)

label(27)
      allocate(2)
      get_structure(X5C,1,0)
      unify_x_variable(0)
      get_y_variable(1,1)
      put_y_variable(0,1)
      call(Pred_Name(X6576616C31,2),1,2,18,"eval1",2)          /* begin sub 18 */
      math_load_y_value(0,0)
      function_1(not,0,0)
      get_y_value(1,0)
      deallocate
      proceed

label(28)
      retry_me_else(30)

label(29)
      allocate(4)
      get_structure(X3C3C,2,0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(2,1)
      put_y_variable(1,1)
      call(Pred_Name(X6576616C31,2),1,4,19,"eval1",2)          /* begin sub 19 */
      put_y_value(3,0)
      put_y_variable(0,1)
      call(Pred_Name(X6576616C31,2),1,3,20,"eval1",2)          /* begin sub 20 */
      math_load_y_value(1,1)
      math_load_y_value(0,0)
      function_2(shl,0,1,0)
      get_y_value(2,0)
      deallocate
      proceed

label(30)
      trust_me_else_fail

label(31)
      allocate(4)
      get_structure(X3E3E,2,0)
      unify_x_variable(0)
      unify_y_variable(3)
      get_y_variable(2,1)
      put_y_variable(1,1)
      call(Pred_Name(X6576616C31,2),1,4,21,"eval1",2)          /* begin sub 21 */
      put_y_value(3,0)
      put_y_variable(0,1)
      call(Pred_Name(X6576616C31,2),1,3,22,"eval1",2)          /* begin sub 22 */
      math_load_y_value(1,1)
      math_load_y_value(0,0)
      function_2(shr,0,1,0)
      get_y_value(2,0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "g_assign"
#define PRED       X675F61737369676E
#define ARITY      2

Begin_Public_Pred
      builtin_2(g_assign,0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "g_assignb"
#define PRED       X675F61737369676E62
#define ARITY      2

Begin_Public_Pred
      builtin_2(g_assignb,0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "g_link"
#define PRED       X675F6C696E6B
#define ARITY      2

Begin_Public_Pred
      builtin_2(g_link,0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "g_read"
#define PRED       X675F72656164
#define ARITY      2

Begin_Public_Pred
      builtin_2(g_read,0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "g_array_size"
#define PRED       X675F61727261795F73697A65
#define ARITY      2

Begin_Public_Pred
      builtin_2(g_array_size,0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(inline)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X3D,"=")
 Define_Atom(X617267,"arg")
 Define_Atom(X66756E63746F72,"functor")
 Define_Atom(X3D2E2E,"=..")
 Define_Atom(X636F6D70617265,"compare")
 Define_Atom(X3D3D,"==")
 Define_Atom(X5C3D3D,"\\==")
 Define_Atom(X403C,"@<")
 Define_Atom(X403D3C,"@=<")
 Define_Atom(X403E,"@>")
 Define_Atom(X403E3D,"@>=")
 Define_Atom(X766172,"var")
 Define_Atom(X6E6F6E766172,"nonvar")
 Define_Atom(X61746F6D,"atom")
 Define_Atom(X696E7465676572,"integer")
 Define_Atom(X6E756D626572,"number")
 Define_Atom(X61746F6D6963,"atomic")
 Define_Atom(X636F6D706F756E64,"compound")
 Define_Atom(X63616C6C61626C65,"callable")
 Define_Atom(X6973,"is")
 Define_Atom(X3D3A3D,"=:=")
 Define_Atom(X3D5C3D,"=\\=")
 Define_Atom(X3C,"<")
 Define_Atom(X3D3C,"=<")
 Define_Atom(X3E,">")
 Define_Atom(X3E3D,">=")
 Define_Atom(X6576616C,"eval")
 Define_Atom(X4572726F723A20,"Error: ")
 Define_Atom(X20496C6C6567616C2061726974686D657469632065787072657373696F6E," Illegal arithmetic expression")
 Define_Atom(X6576616C31,"eval1")
 Define_Atom(X2B,"+")
 Define_Atom(X2D,"-")
 Define_Atom(X2A,"*")
 Define_Atom(X2F2F,"//")
 Define_Atom(X6D6F64,"mod")
 Define_Atom(X2F5C,"/\\")
 Define_Atom(X5C2F,"\\/")
 Define_Atom(X5E,"^")
 Define_Atom(X5C,"\\")
 Define_Atom(X3C3C,"<<")
 Define_Atom(X3E3E,">>")
 Define_Atom(X675F61737369676E,"g_assign")
 Define_Atom(X675F61737369676E62,"g_assignb")
 Define_Atom(X675F6C696E6B,"g_link")
 Define_Atom(X675F72656164,"g_read")
 Define_Atom(X675F61727261795F73697A65,"g_array_size")


 Define_Pred(X3D,2,1)

 Define_Pred(X617267,3,1)

 Define_Pred(X66756E63746F72,3,1)

 Define_Pred(X3D2E2E,2,1)

 Define_Pred(X636F6D70617265,3,1)

 Define_Pred(X3D3D,2,1)

 Define_Pred(X5C3D3D,2,1)

 Define_Pred(X403C,2,1)

 Define_Pred(X403D3C,2,1)

 Define_Pred(X403E,2,1)

 Define_Pred(X403E3D,2,1)

 Define_Pred(X766172,1,1)

 Define_Pred(X6E6F6E766172,1,1)

 Define_Pred(X61746F6D,1,1)

 Define_Pred(X696E7465676572,1,1)

 Define_Pred(X6E756D626572,1,1)

 Define_Pred(X61746F6D6963,1,1)

 Define_Pred(X636F6D706F756E64,1,1)

 Define_Pred(X63616C6C61626C65,1,1)

 Define_Pred(X6973,2,1)

 Define_Pred(X3D3A3D,2,1)

 Define_Pred(X3D5C3D,2,1)

 Define_Pred(X3C,2,1)

 Define_Pred(X3D3C,2,1)

 Define_Pred(X3E,2,1)

 Define_Pred(X3E3D,2,1)

 Define_Pred(X6576616C,2,1)

 Define_Pred(X6576616C31,2,0)
 Define_Switch_STC_Table(Swt_Table_Name(X6576616C31,2,3,stc),13)
     Define_Switch_STC(X2B,1,Label_Pred_Name(X6576616C31,2,7))
     Define_Switch_STC(X2D,1,Label_Pred_Name(X6576616C31,2,9))
     Define_Switch_STC(X2B,2,Label_Pred_Name(X6576616C31,2,11))
     Define_Switch_STC(X2D,2,Label_Pred_Name(X6576616C31,2,13))
     Define_Switch_STC(X2A,2,Label_Pred_Name(X6576616C31,2,15))
     Define_Switch_STC(X2F2F,2,Label_Pred_Name(X6576616C31,2,17))
     Define_Switch_STC(X6D6F64,2,Label_Pred_Name(X6576616C31,2,19))
     Define_Switch_STC(X2F5C,2,Label_Pred_Name(X6576616C31,2,21))
     Define_Switch_STC(X5C2F,2,Label_Pred_Name(X6576616C31,2,23))
     Define_Switch_STC(X5E,2,Label_Pred_Name(X6576616C31,2,25))
     Define_Switch_STC(X5C,1,Label_Pred_Name(X6576616C31,2,27))
     Define_Switch_STC(X3C3C,2,Label_Pred_Name(X6576616C31,2,29))
     Define_Switch_STC(X3E3E,2,Label_Pred_Name(X6576616C31,2,31))

 Define_Pred(X675F61737369676E,2,1)

 Define_Pred(X675F61737369676E62,2,1)

 Define_Pred(X675F6C696E6B,2,1)

 Define_Pred(X675F72656164,2,1)

 Define_Pred(X675F61727261795F73697A65,2,1)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(inline)



End_Exec_Directives
