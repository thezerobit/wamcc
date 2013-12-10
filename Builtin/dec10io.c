/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : dec10io.c
Main : no_main
****************************************************************************/

#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "dec10io.h"
#include "dec10io.usr"


#define ASCII_PRED "nl"
#define PRED       X6E6C
#define ARITY      0

Begin_Public_Pred
      pragma_c(Nl_0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "get0"
#define PRED       X67657430
#define ARITY      1

Begin_Public_Pred
      pragma_c(Get0_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "get"
#define PRED       X676574
#define ARITY      1

Begin_Public_Pred
      pragma_c(Get_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "skip"
#define PRED       X736B6970
#define ARITY      1

Begin_Public_Pred
      pragma_c(Skip_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "put"
#define PRED       X707574
#define ARITY      1

Begin_Public_Pred
      pragma_c(Put_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "tab"
#define PRED       X746162
#define ARITY      1

Begin_Public_Pred
      pragma_c(Tab_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "see"
#define PRED       X736565
#define ARITY      1

Begin_Public_Pred
      pragma_c(See_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "seen"
#define PRED       X7365656E
#define ARITY      0

Begin_Public_Pred
      pragma_c(Seen_0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "seeing"
#define PRED       X736565696E67
#define ARITY      1

Begin_Public_Pred
      pragma_c(Seeing_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "tell"
#define PRED       X74656C6C
#define ARITY      1

Begin_Public_Pred
      pragma_c(Tell_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "told"
#define PRED       X746F6C64
#define ARITY      0

Begin_Public_Pred
      pragma_c(Told_0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "telling"
#define PRED       X74656C6C696E67
#define ARITY      1

Begin_Public_Pred
      pragma_c(Telling_1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(dec10io)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X6E6C,"nl")
 Define_Atom(X67657430,"get0")
 Define_Atom(X676574,"get")
 Define_Atom(X736B6970,"skip")
 Define_Atom(X707574,"put")
 Define_Atom(X746162,"tab")
 Define_Atom(X736565,"see")
 Define_Atom(X7365656E,"seen")
 Define_Atom(X736565696E67,"seeing")
 Define_Atom(X74656C6C,"tell")
 Define_Atom(X746F6C64,"told")
 Define_Atom(X74656C6C696E67,"telling")


 Define_Pred(X6E6C,0,1)

 Define_Pred(X67657430,1,1)

 Define_Pred(X676574,1,1)

 Define_Pred(X736B6970,1,1)

 Define_Pred(X707574,1,1)

 Define_Pred(X746162,1,1)

 Define_Pred(X736565,1,1)

 Define_Pred(X7365656E,0,1)

 Define_Pred(X736565696E67,1,1)

 Define_Pred(X74656C6C,1,1)

 Define_Pred(X746F6C64,0,1)

 Define_Pred(X74656C6C696E67,1,1)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(dec10io)



End_Exec_Directives
