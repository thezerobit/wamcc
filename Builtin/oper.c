/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : oper.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "oper.h"
#include "oper.usr"


#define ASCII_PRED "op"
#define PRED       X6F70
#define ARITY      3

Begin_Public_Pred
      try_me_else(1)
      get_x_variable(4,0)
      get_x_variable(3,1)
      builtin_1(atom,2)
      neck_cut
      put_x_value(2,0)
      put_x_value(4,1)
      put_x_value(3,2)
      execute(Pred_Name(X6F7032,3),1,"op2",3)

label(1)
      trust_me_else_fail
      get_x_variable(4,0)
      get_x_variable(3,1)
      put_x_value(2,0)
      put_x_value(4,1)
      put_x_value(3,2)
      execute(Pred_Name(X6F7031,3),1,"op1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "op1"
#define PRED       X6F7031
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
      allocate(3)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_y_variable(1,1)
      get_y_variable(0,2)
      put_y_value(1,1)
      put_y_value(0,2)
      call(Pred_Name(X6F7032,3),1,3,1,"op2",3)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X6F7031,3),1,"op1",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "op2"
#define PRED       X6F7032
#define ARITY      3

Begin_Private_Pred
      pragma_c(Op2_3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "$exe_1"
#define PRED       X246578655F31
#define ARITY      0

Begin_Private_Pred
      allocate(1)
      get_y_bc_reg(0)
      call(Pred_Name(X246578655F315F2461757831,0),1,1,1,"$exe_1_$aux1",0)          /* begin sub 1 */
      cut_y(0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "$exe_1_$aux1"
#define PRED       X246578655F315F2461757831
#define ARITY      0

Begin_Private_Pred
      try_me_else(1)
      allocate(0)
      put_integer(1200,0)
      put_constant(X786678,1)
      put_list(2)
      unify_constant(X3A2D)
      unify_nil
      call(Pred_Name(X6F70,3),1,0,1,"op",3)          /* begin sub 1 */
      put_integer(1200,0)
      put_constant(X6678,1)
      put_list(2)
      unify_constant(X3A2D)
      unify_nil
      call(Pred_Name(X6F70,3),1,0,2,"op",3)          /* begin sub 2 */
      put_integer(1150,0)
      put_constant(X6678,1)
      put_list(3)
      unify_constant(X64796E616D6963)
      unify_nil
      put_list(2)
      unify_constant(X7075626C6963)
      unify_x_value(3)
      call(Pred_Name(X6F70,3),1,0,3,"op",3)          /* begin sub 3 */
      put_integer(1100,0)
      put_constant(X786679,1)
      put_list(2)
      unify_constant(X3B)
      unify_nil
      call(Pred_Name(X6F70,3),1,0,4,"op",3)          /* begin sub 4 */
      put_integer(1050,0)
      put_constant(X786679,1)
      put_list(2)
      unify_constant(X2D3E)
      unify_nil
      call(Pred_Name(X6F70,3),1,0,5,"op",3)          /* begin sub 5 */
      put_integer(1000,0)
      put_constant(X786679,1)
      put_list(2)
      unify_constant(X2C)
      unify_nil
      call(Pred_Name(X6F70,3),1,0,6,"op",3)          /* begin sub 6 */
      put_integer(900,0)
      put_constant(X6679,1)
      put_list(2)
      unify_constant(X6E6F737079)
      unify_nil
      put_list(3)
      unify_constant(X737079)
      unify_x_value(2)
      put_list(2)
      unify_constant(X5C2B)
      unify_x_value(3)
      call(Pred_Name(X6F70,3),1,0,7,"op",3)          /* begin sub 7 */
      put_integer(700,0)
      put_constant(X786678,1)
      put_list(2)
      unify_constant(X3E3D)
      unify_nil
      put_list(3)
      unify_constant(X3E)
      unify_x_value(2)
      put_list(2)
      unify_constant(X3D3C)
      unify_x_value(3)
      put_list(3)
      unify_constant(X3C)
      unify_x_value(2)
      put_list(2)
      unify_constant(X3D5C3D)
      unify_x_value(3)
      put_list(3)
      unify_constant(X3D3A3D)
      unify_x_value(2)
      put_list(2)
      unify_constant(X403E3D)
      unify_x_value(3)
      put_list(3)
      unify_constant(X403D3C)
      unify_x_value(2)
      put_list(2)
      unify_constant(X403E)
      unify_x_value(3)
      put_list(3)
      unify_constant(X403C)
      unify_x_value(2)
      put_list(2)
      unify_constant(X5C3D3D)
      unify_x_value(3)
      put_list(3)
      unify_constant(X3D3D)
      unify_x_value(2)
      put_list(2)
      unify_constant(X3D2E2E)
      unify_x_value(3)
      put_list(3)
      unify_constant(X6973)
      unify_x_value(2)
      put_list(2)
      unify_constant(X3D)
      unify_x_value(3)
      call(Pred_Name(X6F70,3),1,0,8,"op",3)          /* begin sub 8 */
      put_integer(500,0)
      put_constant(X796678,1)
      put_list(3)
      unify_constant(X5C2F)
      unify_nil
      put_list(2)
      unify_constant(X2F5C)
      unify_x_value(3)
      put_list(3)
      unify_constant(X2D)
      unify_x_value(2)
      put_list(2)
      unify_constant(X2B)
      unify_x_value(3)
      call(Pred_Name(X6F70,3),1,0,9,"op",3)          /* begin sub 9 */
      put_integer(500,0)
      put_constant(X6678,1)
      put_list(3)
      unify_constant(X2D)
      unify_nil
      put_list(2)
      unify_constant(X2B)
      unify_x_value(3)
      call(Pred_Name(X6F70,3),1,0,10,"op",3)          /* begin sub 10 */
      put_integer(400,0)
      put_constant(X796678,1)
      put_list(2)
      unify_constant(X3E3E)
      unify_nil
      put_list(3)
      unify_constant(X3C3C)
      unify_x_value(2)
      put_list(2)
      unify_constant(X2F2F)
      unify_x_value(3)
      put_list(3)
      unify_constant(X2F)
      unify_x_value(2)
      put_list(2)
      unify_constant(X2A)
      unify_x_value(3)
      call(Pred_Name(X6F70,3),1,0,11,"op",3)          /* begin sub 11 */
      put_integer(300,0)
      put_constant(X786678,1)
      put_list(2)
      unify_constant(X6D6F64)
      unify_nil
      call(Pred_Name(X6F70,3),1,0,12,"op",3)          /* begin sub 12 */
      put_integer(200,0)
      put_constant(X786679,1)
      put_list(2)
      unify_constant(X5E)
      unify_nil
      call(Pred_Name(X6F70,3),1,0,13,"op",3)          /* begin sub 13 */
      fail

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(oper)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X6F70,"op")
 Define_Atom(X6F7031,"op1")
 Define_Atom(X6F7032,"op2")
 Define_Atom(X246578655F31,"$exe_1")
 Define_Atom(X246578655F315F2461757831,"$exe_1_$aux1")
 Define_Atom(X786678,"xfx")
 Define_Atom(X3A2D,":-")
 Define_Atom(X6678,"fx")
 Define_Atom(X64796E616D6963,"dynamic")
 Define_Atom(X7075626C6963,"public")
 Define_Atom(X786679,"xfy")
 Define_Atom(X3B,";")
 Define_Atom(X2D3E,"->")
 Define_Atom(X2C,",")
 Define_Atom(X6679,"fy")
 Define_Atom(X6E6F737079,"nospy")
 Define_Atom(X737079,"spy")
 Define_Atom(X5C2B,"\\+")
 Define_Atom(X3E3D,">=")
 Define_Atom(X3E,">")
 Define_Atom(X3D3C,"=<")
 Define_Atom(X3C,"<")
 Define_Atom(X3D5C3D,"=\\=")
 Define_Atom(X3D3A3D,"=:=")
 Define_Atom(X403E3D,"@>=")
 Define_Atom(X403D3C,"@=<")
 Define_Atom(X403E,"@>")
 Define_Atom(X403C,"@<")
 Define_Atom(X5C3D3D,"\\==")
 Define_Atom(X3D3D,"==")
 Define_Atom(X3D2E2E,"=..")
 Define_Atom(X6973,"is")
 Define_Atom(X3D,"=")
 Define_Atom(X796678,"yfx")
 Define_Atom(X5C2F,"\\/")
 Define_Atom(X2F5C,"/\\")
 Define_Atom(X2D,"-")
 Define_Atom(X2B,"+")
 Define_Atom(X3E3E,">>")
 Define_Atom(X3C3C,"<<")
 Define_Atom(X2F2F,"//")
 Define_Atom(X2F,"/")
 Define_Atom(X2A,"*")
 Define_Atom(X6D6F64,"mod")
 Define_Atom(X5E,"^")


 Define_Pred(X6F70,3,1)

 Define_Pred(X6F7031,3,0)

 Define_Pred(X6F7032,3,0)

 Define_Pred(X246578655F31,0,0)

 Define_Pred(X246578655F315F2461757831,0,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(oper)


 Exec_Directive(1,Pred_Name(X246578655F31,0))

End_Exec_Directives
