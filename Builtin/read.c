/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : read.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "read.h"
#include "read.usr"


#define ASCII_PRED "read_line"
#define PRED       X726561645F6C696E65
#define ARITY      1

Begin_Public_Pred
      pragma_c(Read_Line_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "read_word"
#define PRED       X726561645F776F7264
#define ARITY      1

Begin_Public_Pred
      pragma_c(Read_Word_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "read_integer"
#define PRED       X726561645F696E7465676572
#define ARITY      1

Begin_Public_Pred
      pragma_c(Read_Integer_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "read"
#define PRED       X72656164
#define ARITY      1

Begin_Public_Pred
      pragma_c(Read_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "read_term"
#define PRED       X726561645F7465726D
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
      execute(Pred_Name(X726561645F7465726D,5),1,"read_term",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "read_term"
#define PRED       X726561645F7465726D
#define ARITY      5

Begin_Private_Pred
      pragma_c(Read_Term_5)
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
      get_nil(1)
      get_nil(2)
      get_nil(3)
      get_constant(X6465633130,4)
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
      switch_on_structure(1,"[(variables/1,3),(variable_names/1,5),(singletons/1,7),(syntax_errors/1,9)]")

label(2)
      try_me_else(4)

label(3)
      get_structure(X7661726961626C6573,1,0)
      unify_x_variable(0)
      get_x_value(0,2)
      put_x_value(1,0)
      put_x_variable(1,1)
      put_x_value(3,2)
      put_x_value(4,3)
      put_x_value(5,4)
      execute(Pred_Name(X6765745F706172616D73,5),1,"get_params",5)

label(4)
      retry_me_else(6)

label(5)
      get_structure(X7661726961626C655F6E616D6573,1,0)
      unify_x_variable(0)
      get_x_value(0,3)
      put_x_value(1,0)
      put_x_value(2,1)
      put_x_variable(2,2)
      put_x_value(4,3)
      put_x_value(5,4)
      execute(Pred_Name(X6765745F706172616D73,5),1,"get_params",5)

label(6)
      retry_me_else(8)

label(7)
      get_structure(X73696E676C65746F6E73,1,0)
      unify_x_variable(0)
      get_x_value(0,4)
      put_x_value(1,0)
      put_x_value(2,1)
      put_x_value(3,2)
      put_x_variable(3,3)
      put_x_value(5,4)
      execute(Pred_Name(X6765745F706172616D73,5),1,"get_params",5)

label(8)
      trust_me_else_fail

label(9)
      get_structure(X73796E7461785F6572726F7273,1,0)
      unify_x_variable(0)
      get_x_value(0,5)
      put_x_value(1,0)
      put_x_value(2,1)
      put_x_value(3,2)
      put_x_value(4,3)
      put_x_variable(4,4)
      execute(Pred_Name(X6765745F706172616D73,5),1,"get_params",5)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(read)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X726561645F6C696E65,"read_line")
 Define_Atom(X726561645F776F7264,"read_word")
 Define_Atom(X726561645F696E7465676572,"read_integer")
 Define_Atom(X72656164,"read")
 Define_Atom(X726561645F7465726D,"read_term")
 Define_Atom(X6765745F706172616D73,"get_params")
 Define_Atom(X6465633130,"dec10")
 Define_Atom(X6765745F706172616D7331,"get_params1")
 Define_Atom(X7661726961626C6573,"variables")
 Define_Atom(X7661726961626C655F6E616D6573,"variable_names")
 Define_Atom(X73696E676C65746F6E73,"singletons")
 Define_Atom(X73796E7461785F6572726F7273,"syntax_errors")


 Define_Pred(X726561645F6C696E65,1,1)

 Define_Pred(X726561645F776F7264,1,1)

 Define_Pred(X726561645F696E7465676572,1,1)

 Define_Pred(X72656164,1,1)

 Define_Pred(X726561645F7465726D,2,1)

 Define_Pred(X726561645F7465726D,5,0)

 Define_Pred(X6765745F706172616D73,5,0)

 Define_Pred(X6765745F706172616D7331,6,0)
 Define_Switch_STC_Table(Swt_Table_Name(X6765745F706172616D7331,6,1,stc),4)
     Define_Switch_STC(X7661726961626C6573,1,Label_Pred_Name(X6765745F706172616D7331,6,3))
     Define_Switch_STC(X7661726961626C655F6E616D6573,1,Label_Pred_Name(X6765745F706172616D7331,6,5))
     Define_Switch_STC(X73696E676C65746F6E73,1,Label_Pred_Name(X6765745F706172616D7331,6,7))
     Define_Switch_STC(X73796E7461785F6572726F7273,1,Label_Pred_Name(X6765745F706172616D7331,6,9))

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(read)



End_Exec_Directives
