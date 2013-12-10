/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : format.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "format.h"
#include "format.usr"


#define ASCII_PRED "format"
#define PRED       X666F726D6174
#define ARITY      2

Begin_Public_Pred
      allocate(3)
      get_x_variable(2,0)
      get_y_variable(2,1)
      put_y_variable(1,0)
      put_x_value(2,1)
      call(Pred_Name(X61746F6D5F636F646573,2),0,3,1,"atom_codes",2)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_variable(0,1)
      call(Pred_Name(X666F726D61745F2461757831,2),1,2,2,"format_$aux1",2)          /* begin sub 2 */
      put_y_unsafe_value(1,0)
      put_y_unsafe_value(0,1)
      deallocate
      execute(Pred_Name(X666F726D617461,2),1,"formata",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "format_$aux1"
#define PRED       X666F726D61745F2461757831
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      get_list(0)
      unify_void(2)
      neck_cut
      get_x_value(0,1)
      proceed

label(1)
      trust_me_else_fail
      get_list(1)
      unify_x_local_value(0)
      unify_nil
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "formata"
#define PRED       X666F726D617461
#define ARITY      2

Begin_Public_Pred
      pragma_c(Formata_2)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(format)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X666F726D6174,"format")
 Define_Atom(X666F726D61745F2461757831,"format_$aux1")
 Define_Atom(X666F726D617461,"formata")


 Define_Pred(X666F726D6174,2,1)

 Define_Pred(X666F726D61745F2461757831,2,0)

 Define_Pred(X666F726D617461,2,1)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(format)



End_Exec_Directives
