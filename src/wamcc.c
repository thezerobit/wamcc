/****************************************************************************
Prolog to Wam Compiler                     INRIA Rocquencourt - ChLoE Project
Version 2.2                                                Daniel Diaz - 1994

File : wamcc.c
Main : main([wamcc0,wamcc1,wamcc2,wamcc3,wamcc4,wamcc5,wamcc6,wamcc7,wamcc8])
****************************************************************************/

#define FAST_MATH
#define DEBUG_LEVEL    0

#include "wam_engine.h"

#include "wamcc.h"
#include "wamcc.usr"


#define ASCII_PRED "wamcc"
#define PRED       X77616D6363
#define ARITY      1

Begin_Private_Pred
      execute(Pred_Name(X77616D63635F2461757831,1),1,"wamcc_$aux1",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wamcc_$aux1"
#define PRED       X77616D63635F2461757831
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      allocate(2)
      get_y_bc_reg(1)
      put_y_variable(0,1)
      call(Pred_Name(X636D645F6C696E65,2),1,2,1,"cmd_line",2)          /* begin sub 1 */
      cut_y(1)
      call(Pred_Name(X77616D63635F2461757832,0),1,1,2,"wamcc_$aux2",0)          /* begin sub 2 */
      put_y_unsafe_value(0,0)
      deallocate
      execute(Pred_Name(X636F6D70696C6531,1),1,"compile1",1)

label(1)
      trust_me_else_fail
      allocate(0)
      call(Pred_Name(X646973706C61795F76657273696F6E,0),1,0,3,"display_version",0)          /* begin sub 3 */
      call(Pred_Name(X646973706C61795F68656C70,0),1,0,4,"display_help",0)          /* begin sub 4 */
      put_constant(X,0)
      deallocate
      execute(Pred_Name(X6572726F72,1),1,"error",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "wamcc_$aux2"
#define PRED       X77616D63635F2461757832
#define ARITY      0

Begin_Private_Pred
      try_me_else(1)
      put_constant(X766572626F7365,1)
      put_constant(X74,0)
      builtin_2(g_read,1,0)
      neck_cut
      execute(Pred_Name(X646973706C61795F76657273696F6E,0),1,"display_version",0)

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "compile1"
#define PRED       X636F6D70696C6531
#define ARITY      1

Begin_Private_Pred
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
      call(Pred_Name(X636F6D70696C65315F2461757833,1),1,1,1,"compile1_$aux3",1)          /* begin sub 1 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X636F6D70696C6531,1),1,"compile1",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "compile1_$aux3"
#define PRED       X636F6D70696C65315F2461757833
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      allocate(0)
      call(Pred_Name(X636F6D70696C6532,1),1,0,1,"compile2",1)          /* begin sub 1 */
      fail

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "compile2"
#define PRED       X636F6D70696C6532
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      allocate(3)
      get_y_bc_reg(0)
      call(Pred_Name(X637265655F6E6F6D735F666963,1),1,3,1,"cree_noms_fic",1)          /* begin sub 1 */
      call(Pred_Name(X636F6D70696C65325F2461757834,0),1,3,2,"compile2_$aux4",0)          /* begin sub 2 */
      put_constant(X617578,1)
      put_integer(1,0)
      builtin_2(g_assign,1,0)
      put_y_variable(2,0)
      put_y_variable(1,1)
      call(Pred_Name(X6C6972655F66696368696572,2),0,3,3,"lire_fichier",2)          /* begin sub 3 */
      put_y_unsafe_value(2,0)
      put_y_unsafe_value(1,1)
      call(Pred_Name(X636F6D70696C6572,2),1,1,4,"compiler",2)          /* begin sub 4 */
      cut_y(0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      allocate(0)
      call(Pred_Name(X7365656E,0),0,0,5,"seen",0)          /* begin sub 5 */
      call(Pred_Name(X746F6C64,0),0,0,6,"told",0)          /* begin sub 6 */
      put_constant(X20202020202020202E2E2E204661696C,0)
      deallocate
      execute(Pred_Name(X6572726F72,1),1,"error",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "compile2_$aux4"
#define PRED       X636F6D70696C65325F2461757834
#define ARITY      0

Begin_Private_Pred
      try_me_else(1)
      put_constant(X766572626F7365,1)
      put_constant(X74,0)
      builtin_2(g_read,1,0)
      neck_cut
      put_constant(X6669635F696E,1)
      put_x_variable(2,0)
      builtin_2(g_read,1,0)
      put_constant(X436F6D70696C696E67207E772E2E2E7E6E,0)
      put_list(1)
      unify_x_value(2)
      unify_nil
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

label(1)
      trust_me_else_fail
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cree_noms_fic"
#define PRED       X637265655F6E6F6D735F666963
#define ARITY      1

Begin_Private_Pred
      allocate(8)
      get_y_variable(6,0)
      put_y_value(6,0)
      put_y_variable(7,1)
      call(Pred_Name(X61746F6D5F6C656E677468,2),0,8,1,"atom_length",2)          /* begin sub 1 */
      math_load_y_value(7,1)
      put_integer(2,0)
      function_2(sub,1,1,0)
      put_y_value(6,0)
      put_y_variable(5,2)
      put_y_variable(3,3)
      call(Pred_Name(X637265655F6E6F6D735F6669635F2461757835,4),1,6,2,"cree_noms_fic_$aux5",4)          /* begin sub 2 */
      put_y_value(5,0)
      put_y_variable(2,1)
      put_y_variable(1,2)
      put_y_variable(0,3)
      call(Pred_Name(X637265655F6E6F6D735F6669635F2461757836,4),1,6,3,"cree_noms_fic_$aux6",4)          /* begin sub 3 */
      put_y_unsafe_value(5,0)
      put_y_variable(4,1)
      call(Pred_Name(X626173655F6E616D65,2),1,5,4,"base_name",2)          /* begin sub 4 */
      put_constant(X6D6F64756C65,1)
      put_y_value(4,0)
      builtin_2(g_assign,1,0)
      put_constant(X6669635F696E,1)
      put_y_value(3,0)
      builtin_2(g_assign,1,0)
      put_constant(X6669635F6F7574,1)
      put_y_value(2,0)
      builtin_2(g_assign,1,0)
      put_constant(X6669635F68,1)
      put_y_value(1,0)
      builtin_2(g_assign,1,0)
      put_constant(X6669635F757372,1)
      put_y_value(0,0)
      builtin_2(g_assign,1,0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cree_noms_fic_$aux6"
#define PRED       X637265655F6E6F6D735F6669635F2461757836
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      allocate(3)
      get_y_variable(1,0)
      get_x_variable(4,1)
      get_y_variable(2,2)
      get_y_variable(0,3)
      put_constant(X6D6F64655F63,1)
      put_constant(X74,0)
      builtin_2(g_read,1,0)
      neck_cut
      put_y_value(1,0)
      put_constant(X2E63,1)
      put_x_value(4,2)
      call(Pred_Name(X61746F6D5F636F6E636174,3),0,3,1,"atom_concat",3)          /* begin sub 1 */
      put_y_value(1,0)
      put_constant(X2E68,1)
      put_y_value(2,2)
      call(Pred_Name(X61746F6D5F636F6E636174,3),0,2,2,"atom_concat",3)          /* begin sub 2 */
      put_y_value(1,0)
      put_constant(X2E757372,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X61746F6D5F636F6E636174,3),0,"atom_concat",3)

label(1)
      trust_me_else_fail
      allocate(2)
      get_x_variable(4,1)
      get_y_variable(1,2)
      get_y_variable(0,3)
      put_constant(X2E77616D,1)
      put_x_value(4,2)
      call(Pred_Name(X61746F6D5F636F6E636174,3),0,2,3,"atom_concat",3)          /* begin sub 3 */
      put_y_value(1,0)
      get_constant(X6E756C6C,0)
      put_y_value(0,0)
      get_constant(X6E756C6C,0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cree_noms_fic_$aux5"
#define PRED       X637265655F6E6F6D735F6669635F2461757835
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      allocate(5)
      get_y_variable(0,0)
      get_y_variable(3,1)
      get_y_variable(2,2)
      get_y_variable(1,3)
      get_y_bc_reg(4)
      put_y_value(0,0)
      put_y_value(3,1)
      put_integer(3,2)
      put_constant(X2E706C,3)
      call(Pred_Name(X7375625F61746F6D,4),0,5,1,"sub_atom",4)          /* begin sub 1 */
      cut_y(4)
      math_load_y_value(3,0)
      function_1(dec,2,0)
      put_y_value(0,0)
      put_integer(1,1)
      put_y_value(2,3)
      call(Pred_Name(X7375625F61746F6D,4),0,2,2,"sub_atom",4)          /* begin sub 2 */
      put_y_value(1,0)
      get_y_value(0,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      get_x_value(0,2)
      put_x_value(2,0)
      put_constant(X2E706C,1)
      put_x_value(3,2)
      execute(Pred_Name(X61746F6D5F636F6E636174,3),0,"atom_concat",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "base_name"
#define PRED       X626173655F6E616D65
#define ARITY      2

Begin_Private_Pred
      execute(Pred_Name(X626173655F6E616D655F2461757837,2),1,"base_name_$aux7",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "base_name_$aux7"
#define PRED       X626173655F6E616D655F2461757837
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      allocate(6)
      get_y_variable(2,0)
      get_y_variable(0,1)
      get_y_bc_reg(5)
      put_y_value(2,0)
      put_y_variable(3,1)
      put_integer(1,2)
      put_constant(X2F,3)
      call(Pred_Name(X7375625F61746F6D,4),0,6,1,"sub_atom",4)          /* begin sub 1 */
      cut_y(5)
      put_y_value(2,0)
      put_y_variable(4,1)
      call(Pred_Name(X61746F6D5F6C656E677468,2),0,5,2,"atom_length",2)          /* begin sub 2 */
      math_load_y_value(3,0)
      function_1(inc,1,0)
      math_load_y_value(4,2)
      math_load_y_value(3,0)
      function_2(sub,2,2,0)
      put_y_value(2,0)
      put_y_variable(1,3)
      call(Pred_Name(X7375625F61746F6D,4),0,2,3,"sub_atom",4)          /* begin sub 3 */
      put_y_unsafe_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X626173655F6E616D65,2),1,"base_name",2)

label(1)
      trust_me_else_fail
      get_x_value(0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cmd_line"
#define PRED       X636D645F6C696E65
#define ARITY      2

Begin_Private_Pred
      allocate(2)
      get_y_variable(0,1)
      put_y_variable(1,1)
      call(Pred_Name(X636D645F6C696E655F2461757838,2),1,2,1,"cmd_line_$aux8",2)          /* begin sub 1 */
      call(Pred_Name(X7365745F64656661756C745F6F7074696F6E73,0),1,2,2,"set_default_options",0)          /* begin sub 2 */
      put_y_unsafe_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X636D645F6C696E6531,2),1,"cmd_line1",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cmd_line_$aux8"
#define PRED       X636D645F6C696E655F2461757838
#define ARITY      2

Begin_Private_Pred
      try_me_else(1)
      allocate(3)
      get_y_variable(0,0)
      get_y_variable(1,1)
      get_y_bc_reg(2)
      put_y_value(0,0)
      call(Pred_Name(X636D645F6C696E655F2461757839,1),1,3,1,"cmd_line_$aux9",1)          /* begin sub 1 */
      cut_y(2)
      put_y_value(1,0)
      get_y_value(0,0)
      deallocate
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



#define ASCII_PRED "cmd_line_$aux9"
#define PRED       X636D645F6C696E655F2461757839
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      get_list(0)
      unify_void(2)
      proceed

label(1)
      trust_me_else_fail
      put_nil(1)
      builtin_2(term_eq,0,1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cmd_line1"
#define PRED       X636D645F6C696E6531
#define ARITY      2

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(3),fail,G_label(1),fail)

label(1)
      try(5,1)          /* begin sub 1 */
      trust(7)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      get_nil(1)
      proceed

label(4)
      retry_me_else(6)

label(5)
      allocate(3)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(1)
      get_y_variable(0,1)
      get_x_bc_reg(1)
      put_y_variable(2,2)
      call(Pred_Name(X636D645F6C696E65315F246175783130,3),1,3,2,"cmd_line1_$aux10",3)          /* begin sub 2 */
      put_y_unsafe_value(2,0)
      call(Pred_Name(X7472616974655F6F7074,1),1,2,3,"traite_opt",1)          /* begin sub 3 */
      put_y_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X636D645F6C696E6531,2),1,"cmd_line1",2)

label(6)
      trust_me_else_fail

label(7)
      get_list(0)
      unify_x_variable(2)
      unify_x_variable(0)
      get_list(1)
      unify_x_value(2)
      unify_x_variable(1)
      execute(Pred_Name(X636D645F6C696E6531,2),1,"cmd_line1",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cmd_line1_$aux10"
#define PRED       X636D645F6C696E65315F246175783130
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      get_structure(X2D,1,0)
      unify_x_local_value(2)
      cut_x(1)
      proceed

label(1)
      trust_me_else_fail
      allocate(4)
      get_y_variable(1,0)
      get_y_variable(3,1)
      get_y_variable(0,2)
      put_y_value(1,0)
      put_integer(1,1)
      put_integer(1,2)
      put_constant(X2D,3)
      call(Pred_Name(X7375625F61746F6D,4),0,4,1,"sub_atom",4)          /* begin sub 1 */
      cut_y(3)
      put_y_value(1,0)
      put_y_variable(2,1)
      call(Pred_Name(X61746F6D5F6C656E677468,2),0,3,2,"atom_length",2)          /* begin sub 2 */
      math_load_y_value(2,0)
      function_1(dec,2,0)
      put_y_value(1,0)
      put_integer(2,1)
      put_y_value(0,3)
      deallocate
      execute(Pred_Name(X7375625F61746F6D,4),0,"sub_atom",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "set_default_options"
#define PRED       X7365745F64656661756C745F6F7074696F6E73
#define ARITY      0

Begin_Private_Pred
      put_constant(X6D6F64655F63,1)
      put_constant(X74,0)
      builtin_2(g_assign,1,0)
      put_constant(X666173745F6D617468,1)
      put_constant(X66,0)
      builtin_2(g_assign,1,0)
      put_constant(X6E6F5F696E6C696E65,1)
      put_constant(X66,0)
      builtin_2(g_assign,1,0)
      put_constant(X6465627567,1)
      put_integer(0,0)
      builtin_2(g_assign,1,0)
      put_constant(X766572626F7365,1)
      put_constant(X66,0)
      builtin_2(g_assign,1,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "traite_opt"
#define PRED       X7472616974655F6F7074
#define ARITY      1

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(1),fail,fail,fail)

label(1)
      switch_on_constant(1,"[(c,3),(wam,5),(fast_math,7),(no_inline,9),(dbg0,11),(dbg,13),(dbg1,15),(dbg2,17),(v,19)]")

label(2)
      try_me_else(4)

label(3)
      get_constant(X63,0)
      put_constant(X6D6F64655F63,1)
      put_constant(X74,0)
      builtin_2(g_assign,1,0)
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_constant(X77616D,0)
      put_constant(X6D6F64655F63,1)
      put_constant(X66,0)
      builtin_2(g_assign,1,0)
      proceed

label(6)
      retry_me_else(8)

label(7)
      get_constant(X666173745F6D617468,0)
      put_constant(X666173745F6D617468,1)
      put_constant(X74,0)
      builtin_2(g_assign,1,0)
      proceed

label(8)
      retry_me_else(10)

label(9)
      get_constant(X6E6F5F696E6C696E65,0)
      put_constant(X6E6F5F696E6C696E65,1)
      put_constant(X74,0)
      builtin_2(g_assign,1,0)
      proceed

label(10)
      retry_me_else(12)

label(11)
      get_constant(X64626730,0)
      put_constant(X6465627567,1)
      put_integer(0,0)
      builtin_2(g_assign,1,0)
      proceed

label(12)
      retry_me_else(14)

label(13)
      get_constant(X646267,0)
      put_constant(X6465627567,1)
      put_integer(1,0)
      builtin_2(g_assign,1,0)
      proceed

label(14)
      retry_me_else(16)

label(15)
      get_constant(X64626731,0)
      put_constant(X6465627567,1)
      put_integer(1,0)
      builtin_2(g_assign,1,0)
      proceed

label(16)
      retry_me_else(18)

label(17)
      get_constant(X64626732,0)
      put_constant(X6465627567,1)
      put_integer(2,0)
      builtin_2(g_assign,1,0)
      proceed

label(18)
      trust_me_else_fail

label(19)
      get_constant(X76,0)
      put_constant(X766572626F7365,1)
      put_constant(X74,0)
      builtin_2(g_assign,1,0)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "display_version"
#define PRED       X646973706C61795F76657273696F6E
#define ARITY      0

Begin_Public_Pred
      allocate(8)
      neck_cut
      put_y_variable(7,0)
      get_constant(X50726F6C6F6720746F2057616D20436F6D70696C6572,0)
      put_y_variable(6,0)
      call(Pred_Name(X77616D5F76657273696F6E,1),0,8,1,"wam_version",1)          /* begin sub 1 */
      put_y_variable(0,0)
      call(Pred_Name(X77616D5F79656172,1),0,8,2,"wam_year",1)          /* begin sub 2 */
      put_y_unsafe_value(7,0)
      put_y_variable(3,1)
      call(Pred_Name(X6E616D65,2),0,7,3,"name",2)          /* begin sub 3 */
      put_y_value(3,0)
      put_y_variable(5,1)
      call(Pred_Name(X6C656E677468,2),0,7,4,"length",2)          /* begin sub 4 */
      put_y_unsafe_value(6,0)
      put_y_variable(2,1)
      call(Pred_Name(X6E616D65,2),0,6,5,"name",2)          /* begin sub 5 */
      put_y_value(2,0)
      put_y_variable(4,1)
      call(Pred_Name(X6C656E677468,2),0,6,6,"length",2)          /* begin sub 6 */
      put_integer(40,1)
      math_load_y_value(5,0)
      function_2(sub,3,1,0)
      put_integer(45,1)
      math_load_y_value(4,0)
      function_2(sub,0,1,0)
      get_y_variable(1,0)
      put_constant(X7E737E2A63202020494E52494120526F637175656E636F757274202D2043684C6F452050726F6A6563747E6E,0)
      put_list(1)
      unify_integer(32)
      unify_nil
      put_list(2)
      unify_x_value(3)
      unify_x_value(1)
      put_list(1)
      unify_y_local_value(3)
      unify_x_value(2)
      call(Pred_Name(X666F726D617461,2),0,3,7,"formata",2)          /* begin sub 7 */
      put_constant(X56657273696F6E207E737E2A6320202020202044616E69656C204469617A202D207E647E6E7E6E,0)
      put_list(2)
      unify_y_local_value(0)
      unify_nil
      put_list(1)
      unify_integer(32)
      unify_x_value(2)
      put_list(2)
      unify_y_local_value(1)
      unify_x_value(1)
      put_list(1)
      unify_y_local_value(2)
      unify_x_value(2)
      deallocate
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "display_help"
#define PRED       X646973706C61795F68656C70
#define ARITY      0

Begin_Private_Pred
      allocate(1)
      put_y_variable(0,0)
      call(Pred_Name(X636F6D70696C65725F6E616D65,1),0,1,1,"compiler_name",1)          /* begin sub 1 */
      put_constant(X55736167653A7E6E7E6E,0)
      put_nil(1)
      call(Pred_Name(X666F726D617461,2),0,1,2,"formata",2)          /* begin sub 2 */
      put_constant(X2020207E77205B6F7074696F6E207C2066696C656E616D655D2E2E2E7E6E7E6E,0)
      put_list(1)
      unify_y_local_value(0)
      unify_nil
      call(Pred_Name(X666F726D617461,2),0,0,3,"formata",2)          /* begin sub 3 */
      put_constant(X4F7074696F6E733A7E6E7E6E,0)
      put_nil(1)
      call(Pred_Name(X666F726D617461,2),0,0,4,"formata",2)          /* begin sub 4 */
      put_constant(X2020202D6320202020202020202070726F647563652061202E6320202066696C657E6E,0)
      put_nil(1)
      call(Pred_Name(X666F726D617461,2),0,0,5,"formata",2)          /* begin sub 5 */
      put_constant(X2020202D77616D2020202020202070726F647563652061202E77616D2066696C657E6E,0)
      put_nil(1)
      call(Pred_Name(X666F726D617461,2),0,0,6,"formata",2)          /* begin sub 6 */
      put_constant(X2020202D666173745F6D61746820646F206E6F74207465737420747970657320696E206D6174682065787072657373696F6E737E6E,0)
      put_nil(1)
      call(Pred_Name(X666F726D617461,2),0,0,7,"formata",2)          /* begin sub 7 */
      put_constant(X2020202D6E6F5F696E6C696E6520646F206E6F7420696E6C696E6520616E79206275696C74696E20707265646963617465737E6E,0)
      put_nil(1)
      call(Pred_Name(X666F726D617461,2),0,0,8,"formata",2)          /* begin sub 8 */
      put_constant(X2020202D64626720202020202020636F6D70696C6520666F722070726F6C6F6720646562756767696E677E6E,0)
      put_nil(1)
      call(Pred_Name(X666F726D617461,2),0,0,9,"formata",2)          /* begin sub 9 */
      put_constant(X2020202D64626732202020202020636F6D70696C6520666F722070726F6C6F6720616E642077616D20646562756767696E677E6E,0)
      put_nil(1)
      call(Pred_Name(X666F726D617461,2),0,0,10,"formata",2)          /* begin sub 10 */
      put_constant(X2020202D76202020202020202020766572626F7365206D6F64657E6E,0)
      put_nil(1)
      call(Pred_Name(X666F726D617461,2),0,0,11,"formata",2)          /* begin sub 11 */
      put_constant(X2020202D68202020202020202020646973706C61792068656C707E6E,0)
      put_nil(1)
      deallocate
      execute(Pred_Name(X666F726D617461,2),0,"formata",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "compiler"
#define PRED       X636F6D70696C6572
#define ARITY      2

Begin_Private_Pred
      allocate(6)
      get_y_variable(2,1)
      get_y_bc_reg(3)
      put_constant(X6D6F64655F63,2)
      put_y_variable(1,1)
      builtin_2(g_read,2,1)
      put_y_variable(5,1)
      call(Pred_Name(X657865635F706173736573,2),1,6,1,"exec_passes",2)          /* begin sub 1 */
      cut_y(3)
      put_y_unsafe_value(5,0)
      put_y_variable(4,1)
      call(Pred_Name(X637265655F70617175657473,2),1,5,2,"cree_paquets",2)          /* begin sub 2 */
      cut_y(3)
      put_y_unsafe_value(4,0)
      put_y_variable(0,1)
      call(Pred_Name(X657865635F696E6465786174696F6E,2),1,4,3,"exec_indexation",2)          /* begin sub 3 */
      cut_y(3)
      put_y_value(2,0)
      put_y_unsafe_value(1,1)
      put_y_unsafe_value(0,2)
      deallocate
      execute(Pred_Name(X636F6D70696C65725F246175783131,3),1,"compiler_$aux11",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "compiler_$aux11"
#define PRED       X636F6D70696C65725F246175783131
#define ARITY      3

Begin_Private_Pred
      try_me_else(1)
      put_constant(X66,0)
      builtin_2(term_eq,1,0)
      neck_cut
      put_x_value(2,0)
      execute(Pred_Name(X77616D5F656D697373696F6E,1),0,"wam_emission",1)

label(1)
      trust_me_else_fail
      get_x_variable(3,0)
      put_x_value(2,0)
      put_x_value(3,1)
      execute(Pred_Name(X635F656D697373696F6E,2),0,"c_emission",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "exec_passes"
#define PRED       X657865635F706173736573
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
      allocate(10)
      get_list(0)
      unify_x_variable(0)
      unify_x_variable(2)
      get_list(1)
      unify_x_variable(1)
      unify_y_variable(0)
      get_structure(X636C636F6D70,3,1)
      unify_y_variable(4)
      unify_y_variable(8)
      unify_y_variable(3)
      get_y_bc_reg(2)
      put_x_value(2,1)
      put_y_variable(9,2)
      put_y_variable(1,3)
      call(Pred_Name(X73756372655F73796E74617869717565,4),0,10,1,"sucre_syntaxique",4)          /* begin sub 1 */
      cut_y(2)
      put_y_unsafe_value(9,0)
      put_y_value(8,1)
      put_y_variable(7,2)
      put_y_variable(6,3)
      put_y_variable(5,4)
      call(Pred_Name(X666F726D61745F696E7465726E65,5),0,8,2,"format_interne",5)          /* begin sub 2 */
      cut_y(2)
      put_y_value(7,0)
      put_y_value(6,1)
      call(Pred_Name(X636C61737369665F7661726961626C6573,2),0,8,3,"classif_variables",2)          /* begin sub 3 */
      cut_y(2)
      put_y_unsafe_value(7,0)
      put_y_unsafe_value(6,1)
      put_y_unsafe_value(5,2)
      put_y_value(4,3)
      put_y_value(3,4)
      call(Pred_Name(X67656E65726174696F6E5F636F6465,5),0,4,4,"generation_code",5)          /* begin sub 4 */
      cut_y(2)
      put_y_value(3,0)
      call(Pred_Name(X616C6C6F636174696F6E5F7661727358,1),0,3,5,"allocation_varsX",1)          /* begin sub 5 */
      cut_y(2)
      put_y_unsafe_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X657865635F706173736573,2),1,"exec_passes",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "cree_paquets"
#define PRED       X637265655F70617175657473
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
      allocate(4)
      get_list(0)
      unify_y_variable(2)
      unify_x_variable(0)
      get_y_variable(1,1)
      get_y_bc_reg(0)
      put_y_variable(3,1)
      call(Pred_Name(X637265655F70617175657473,2),1,4,1,"cree_paquets",2)          /* begin sub 1 */
      put_y_unsafe_value(3,0)
      put_y_value(2,1)
      put_y_value(1,2)
      call(Pred_Name(X616A6F75745F636C61757365,3),1,1,2,"ajout_clause",3)          /* begin sub 2 */
      cut_y(0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "ajout_clause"
#define PRED       X616A6F75745F636C61757365
#define ARITY      3

Begin_Private_Pred
      get_list(2)
      unify_x_variable(2)
      unify_x_variable(3)
      execute(Pred_Name(X74726F7576655F706171756574,4),1,"trouve_paquet",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "trouve_paquet"
#define PRED       X74726F7576655F706171756574
#define ARITY      4

Begin_Private_Pred
      switch_on_term(G_label(2),G_label(3),fail,G_label(1),fail)

label(1)
      try(5,1)          /* begin sub 1 */
      trust(7)

label(2)
      try_me_else(4)

label(3)
      get_nil(0)
      get_structure(X636C636F6D70,3,1)
      unify_x_variable(4)
      unify_x_variable(0)
      unify_x_variable(1)
      get_structure(X706171,2,2)
      unify_x_value(4)
      unify_x_variable(2)
      get_list(2)
      unify_x_variable(2)
      unify_nil
      get_nil(3)
      execute(Pred_Name(X666F726D61745F696E646578,3),1,"format_index",3)

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_x_variable(0)
      unify_x_variable(4)
      get_structure(X706171,2,0)
      unify_x_variable(6)
      unify_x_variable(5)
      get_structure(X636C636F6D70,3,1)
      unify_x_value(6)
      unify_x_variable(0)
      unify_x_variable(1)
      get_structure(X706171,2,2)
      unify_x_value(6)
      unify_x_variable(2)
      get_list(2)
      unify_x_variable(2)
      unify_x_value(5)
      get_x_value(4,3)
      execute(Pred_Name(X666F726D61745F696E646578,3),1,"format_index",3)

label(6)
      trust_me_else_fail

label(7)
      get_list(0)
      unify_x_variable(4)
      unify_x_variable(0)
      get_list(3)
      unify_x_value(4)
      unify_x_variable(3)
      execute(Pred_Name(X74726F7576655F706171756574,4),1,"trouve_paquet",4)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "format_index"
#define PRED       X666F726D61745F696E646578
#define ARITY      3

Begin_Private_Pred
      get_structure(X636C,3,2)
      unify_void(1)
      unify_x_local_value(0)
      unify_x_local_value(1)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "exec_indexation"
#define PRED       X657865635F696E6465786174696F6E
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
      allocate(3)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(1)
      get_structure(X706171,2,0)
      unify_x_variable(2)
      unify_x_variable(0)
      get_list(1)
      unify_x_variable(1)
      unify_y_variable(0)
      get_structure(X706171,2,1)
      unify_x_value(2)
      unify_x_variable(1)
      get_y_bc_reg(2)
      call(Pred_Name(X696E6465786174696F6E,2),0,3,1,"indexation",2)          /* begin sub 1 */
      cut_y(2)
      put_y_value(1,0)
      put_y_value(0,1)
      deallocate
      execute(Pred_Name(X657865635F696E6465786174696F6E,2),1,"exec_indexation",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "ens_ajout"
#define PRED       X656E735F616A6F7574
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
      get_list(2)
      unify_x_local_value(1)
      unify_nil
      proceed

label(4)
      retry_me_else(6)

label(5)
      get_list(0)
      unify_x_variable(0)
      unify_x_variable(3)
      get_list(2)
      unify_x_value(0)
      unify_x_value(3)
      builtin_2(term_eq,1,0)
      neck_cut
      proceed

label(6)
      trust_me_else_fail

label(7)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      get_list(2)
      unify_x_value(3)
      unify_x_variable(2)
      execute(Pred_Name(X656E735F616A6F7574,3),1,"ens_ajout",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "ens_retrait"
#define PRED       X656E735F72657472616974
#define ARITY      3

Begin_Public_Pred
      switch_on_term(G_label(2),fail,fail,G_label(1),fail)

label(1)
      try(3,1)          /* begin sub 1 */
      trust(5)

label(2)
      try_me_else(4)

label(3)
      get_list(0)
      unify_x_variable(0)
      unify_x_variable(3)
      get_x_value(3,2)
      builtin_2(term_eq,1,0)
      neck_cut
      proceed

label(4)
      trust_me_else_fail

label(5)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      get_list(2)
      unify_x_value(3)
      unify_x_variable(2)
      execute(Pred_Name(X656E735F72657472616974,3),1,"ens_retrait",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "ens_elt"
#define PRED       X656E735F656C74
#define ARITY      2

Begin_Public_Pred
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
      builtin_2(term_eq,1,0)
      neck_cut
      proceed

label(4)
      trust_me_else_fail

label(5)
      get_list(0)
      unify_void(1)
      unify_x_variable(0)
      execute(Pred_Name(X656E735F656C74,2),1,"ens_elt",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "ens_inter"
#define PRED       X656E735F696E746572
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
      allocate(4)
      get_list(0)
      unify_x_variable(3)
      unify_y_variable(2)
      get_y_variable(1,1)
      get_list(2)
      unify_x_value(3)
      unify_y_variable(0)
      get_y_bc_reg(3)
      put_y_value(1,0)
      put_x_value(3,1)
      call(Pred_Name(X656E735F656C74,2),1,4,2,"ens_elt",2)          /* begin sub 2 */
      cut_y(3)
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X656E735F696E746572,3),1,"ens_inter",3)

label(6)
      trust_me_else_fail

label(7)
      get_list(0)
      unify_void(1)
      unify_x_variable(0)
      execute(Pred_Name(X656E735F696E746572,3),1,"ens_inter",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "ens_union"
#define PRED       X656E735F756E696F6E
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
      get_x_value(1,2)
      proceed

label(4)
      retry_me_else(6)

label(5)
      allocate(4)
      get_list(0)
      unify_x_variable(3)
      unify_y_variable(2)
      get_y_variable(1,1)
      get_y_variable(0,2)
      get_y_bc_reg(3)
      put_y_value(1,0)
      put_x_value(3,1)
      call(Pred_Name(X656E735F656C74,2),1,4,2,"ens_elt",2)          /* begin sub 2 */
      cut_y(3)
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_value(0,2)
      deallocate
      execute(Pred_Name(X656E735F756E696F6E,3),1,"ens_union",3)

label(6)
      trust_me_else_fail

label(7)
      get_list(0)
      unify_x_variable(3)
      unify_x_variable(0)
      get_list(2)
      unify_x_value(3)
      unify_x_variable(2)
      execute(Pred_Name(X656E735F756E696F6E,3),1,"ens_union",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "ens_compl"
#define PRED       X656E735F636F6D706C
#define ARITY      3

Begin_Public_Pred
      switch_on_term(G_label(1),G_label(2),fail,G_label(4),fail)

label(1)
      try_me_else(3)

label(2)
      get_nil(0)
      get_nil(2)
      proceed

label(3)
      trust_me_else_fail

label(4)
      allocate(3)
      get_list(0)
      unify_x_variable(0)
      unify_y_variable(2)
      get_y_variable(1,1)
      put_y_value(1,1)
      put_y_variable(0,3)
      call(Pred_Name(X656E735F636F6D706C5F246175783132,4),1,3,1,"ens_compl_$aux12",4)          /* begin sub 1 */
      put_y_value(2,0)
      put_y_value(1,1)
      put_y_unsafe_value(0,2)
      deallocate
      execute(Pred_Name(X656E735F636F6D706C,3),1,"ens_compl",3)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "ens_compl_$aux12"
#define PRED       X656E735F636F6D706C5F246175783132
#define ARITY      4

Begin_Private_Pred
      try_me_else(1)
      allocate(3)
      get_x_variable(4,0)
      get_y_variable(1,2)
      get_y_variable(0,3)
      get_y_bc_reg(2)
      put_x_value(1,0)
      put_x_value(4,1)
      call(Pred_Name(X656E735F656C74,2),1,3,1,"ens_elt",2)          /* begin sub 1 */
      cut_y(2)
      put_y_value(1,0)
      get_y_value(0,0)
      deallocate
      proceed

label(1)
      trust_me_else_fail
      get_list(2)
      unify_x_local_value(0)
      unify_x_local_value(3)
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "error"
#define PRED       X6572726F72
#define ARITY      1

Begin_Public_Pred
      allocate(0)
      call(Pred_Name(X7772697465,1),0,0,1,"write",1)          /* begin sub 1 */
      call(Pred_Name(X6E6C,0),0,0,2,"nl",0)          /* begin sub 2 */
      deallocate
      execute(Pred_Name(X61626F7274,0),0,"abort",0)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "go"
#define PRED       X676F
#define ARITY      0

Begin_Private_Pred
      allocate(1)
      put_structure(X61726776,1,0)
      unify_y_variable(0)
      call(Pred_Name(X756E6978,1),0,1,1,"unix",1)          /* begin sub 1 */
      put_y_value(0,0)
      deallocate
      execute(Pred_Name(X676F5F246175783133,1),1,"go_$aux13",1)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "go_$aux13"
#define PRED       X676F5F246175783133
#define ARITY      1

Begin_Private_Pred
      try_me_else(1)
      allocate(0)
      put_nil(1)
      builtin_2(term_neq,0,1)
      neck_cut
      call(Pred_Name(X77616D6363,1),1,0,1,"wamcc",1)          /* begin sub 1 */
      put_integer(0,0)
      put_constant(X74727565,1)
      deallocate
      execute(Pred_Name(X68616C745F6F725F656C7365,2),0,"halt_or_else",2)

label(1)
      trust_me_else_fail
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
      call(Pred_Name(X676F,0),1,1,1,"go",0)          /* begin sub 1 */
      cut_y(0)
      deallocate
      proceed

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY



#define ASCII_PRED "$exe_2"
#define PRED       X246578655F32
#define ARITY      0

Begin_Private_Pred
      put_constant(X74727565,0)
      put_constant(X74727565,1)
      execute(Pred_Name(X746F705F6C6576656C,2),0,"top_level",2)

End_Pred

#undef ASCII_PRED
#undef PRED
#undef ARITY


Begin_Init_Tables(wamcc)

 Define_Atom(X5B5D,"[]")
 Define_Atom(X77616D6363,"wamcc")
 Define_Atom(X77616D63635F2461757831,"wamcc_$aux1")
 Define_Atom(X,"")
 Define_Atom(X77616D63635F2461757832,"wamcc_$aux2")
 Define_Atom(X766572626F7365,"verbose")
 Define_Atom(X74,"t")
 Define_Atom(X636F6D70696C6531,"compile1")
 Define_Atom(X636F6D70696C65315F2461757833,"compile1_$aux3")
 Define_Atom(X636F6D70696C6532,"compile2")
 Define_Atom(X617578,"aux")
 Define_Atom(X20202020202020202E2E2E204661696C,"        ... Fail")
 Define_Atom(X636F6D70696C65325F2461757834,"compile2_$aux4")
 Define_Atom(X6669635F696E,"fic_in")
 Define_Atom(X436F6D70696C696E67207E772E2E2E7E6E,"Compiling ~w...~n")
 Define_Atom(X637265655F6E6F6D735F666963,"cree_noms_fic")
 Define_Atom(X6D6F64756C65,"module")
 Define_Atom(X6669635F6F7574,"fic_out")
 Define_Atom(X6669635F68,"fic_h")
 Define_Atom(X6669635F757372,"fic_usr")
 Define_Atom(X637265655F6E6F6D735F6669635F2461757836,"cree_noms_fic_$aux6")
 Define_Atom(X6D6F64655F63,"mode_c")
 Define_Atom(X2E63,".c")
 Define_Atom(X2E68,".h")
 Define_Atom(X2E757372,".usr")
 Define_Atom(X2E77616D,".wam")
 Define_Atom(X6E756C6C,"null")
 Define_Atom(X637265655F6E6F6D735F6669635F2461757835,"cree_noms_fic_$aux5")
 Define_Atom(X2E706C,".pl")
 Define_Atom(X626173655F6E616D65,"base_name")
 Define_Atom(X626173655F6E616D655F2461757837,"base_name_$aux7")
 Define_Atom(X2F,"/")
 Define_Atom(X636D645F6C696E65,"cmd_line")
 Define_Atom(X636D645F6C696E655F2461757838,"cmd_line_$aux8")
 Define_Atom(X636D645F6C696E655F2461757839,"cmd_line_$aux9")
 Define_Atom(X636D645F6C696E6531,"cmd_line1")
 Define_Atom(X636D645F6C696E65315F246175783130,"cmd_line1_$aux10")
 Define_Atom(X2D,"-")
 Define_Atom(X7365745F64656661756C745F6F7074696F6E73,"set_default_options")
 Define_Atom(X666173745F6D617468,"fast_math")
 Define_Atom(X66,"f")
 Define_Atom(X6E6F5F696E6C696E65,"no_inline")
 Define_Atom(X6465627567,"debug")
 Define_Atom(X7472616974655F6F7074,"traite_opt")
 Define_Atom(X63,"c")
 Define_Atom(X77616D,"wam")
 Define_Atom(X64626730,"dbg0")
 Define_Atom(X646267,"dbg")
 Define_Atom(X64626731,"dbg1")
 Define_Atom(X64626732,"dbg2")
 Define_Atom(X76,"v")
 Define_Atom(X646973706C61795F76657273696F6E,"display_version")
 Define_Atom(X50726F6C6F6720746F2057616D20436F6D70696C6572,"Prolog to Wam Compiler")
 Define_Atom(X7E737E2A63202020494E52494120526F637175656E636F757274202D2043684C6F452050726F6A6563747E6E,"~s~*c   INRIA Rocquencourt - ChLoE Project~n")
 Define_Atom(X56657273696F6E207E737E2A6320202020202044616E69656C204469617A202D207E647E6E7E6E,"Version ~s~*c      Daniel Diaz - ~d~n~n")
 Define_Atom(X646973706C61795F68656C70,"display_help")
 Define_Atom(X55736167653A7E6E7E6E,"Usage:~n~n")
 Define_Atom(X2020207E77205B6F7074696F6E207C2066696C656E616D655D2E2E2E7E6E7E6E,"   ~w [option | filename]...~n~n")
 Define_Atom(X4F7074696F6E733A7E6E7E6E,"Options:~n~n")
 Define_Atom(X2020202D6320202020202020202070726F647563652061202E6320202066696C657E6E,"   -c         produce a .c   file~n")
 Define_Atom(X2020202D77616D2020202020202070726F647563652061202E77616D2066696C657E6E,"   -wam       produce a .wam file~n")
 Define_Atom(X2020202D666173745F6D61746820646F206E6F74207465737420747970657320696E206D6174682065787072657373696F6E737E6E,"   -fast_math do not test types in math expressions~n")
 Define_Atom(X2020202D6E6F5F696E6C696E6520646F206E6F7420696E6C696E6520616E79206275696C74696E20707265646963617465737E6E,"   -no_inline do not inline any builtin predicates~n")
 Define_Atom(X2020202D64626720202020202020636F6D70696C6520666F722070726F6C6F6720646562756767696E677E6E,"   -dbg       compile for prolog debugging~n")
 Define_Atom(X2020202D64626732202020202020636F6D70696C6520666F722070726F6C6F6720616E642077616D20646562756767696E677E6E,"   -dbg2      compile for prolog and wam debugging~n")
 Define_Atom(X2020202D76202020202020202020766572626F7365206D6F64657E6E,"   -v         verbose mode~n")
 Define_Atom(X2020202D68202020202020202020646973706C61792068656C707E6E,"   -h         display help~n")
 Define_Atom(X636F6D70696C6572,"compiler")
 Define_Atom(X636F6D70696C65725F246175783131,"compiler_$aux11")
 Define_Atom(X657865635F706173736573,"exec_passes")
 Define_Atom(X636C636F6D70,"clcomp")
 Define_Atom(X637265655F70617175657473,"cree_paquets")
 Define_Atom(X616A6F75745F636C61757365,"ajout_clause")
 Define_Atom(X74726F7576655F706171756574,"trouve_paquet")
 Define_Atom(X706171,"paq")
 Define_Atom(X666F726D61745F696E646578,"format_index")
 Define_Atom(X636C,"cl")
 Define_Atom(X657865635F696E6465786174696F6E,"exec_indexation")
 Define_Atom(X656E735F616A6F7574,"ens_ajout")
 Define_Atom(X656E735F72657472616974,"ens_retrait")
 Define_Atom(X656E735F656C74,"ens_elt")
 Define_Atom(X656E735F696E746572,"ens_inter")
 Define_Atom(X656E735F756E696F6E,"ens_union")
 Define_Atom(X656E735F636F6D706C,"ens_compl")
 Define_Atom(X656E735F636F6D706C5F246175783132,"ens_compl_$aux12")
 Define_Atom(X6572726F72,"error")
 Define_Atom(X676F,"go")
 Define_Atom(X61726776,"argv")
 Define_Atom(X676F5F246175783133,"go_$aux13")
 Define_Atom(X74727565,"true")
 Define_Atom(X246578655F31,"$exe_1")
 Define_Atom(X246578655F32,"$exe_2")


 Define_Pred(X77616D6363,1,0)

 Define_Pred(X77616D63635F2461757831,1,0)

 Define_Pred(X77616D63635F2461757832,0,0)

 Define_Pred(X636F6D70696C6531,1,0)

 Define_Pred(X636F6D70696C65315F2461757833,1,0)

 Define_Pred(X636F6D70696C6532,1,0)

 Define_Pred(X636F6D70696C65325F2461757834,0,0)

 Define_Pred(X637265655F6E6F6D735F666963,1,0)

 Define_Pred(X637265655F6E6F6D735F6669635F2461757836,4,0)

 Define_Pred(X637265655F6E6F6D735F6669635F2461757835,4,0)

 Define_Pred(X626173655F6E616D65,2,0)

 Define_Pred(X626173655F6E616D655F2461757837,2,0)

 Define_Pred(X636D645F6C696E65,2,0)

 Define_Pred(X636D645F6C696E655F2461757838,2,0)

 Define_Pred(X636D645F6C696E655F2461757839,1,0)

 Define_Pred(X636D645F6C696E6531,2,0)

 Define_Pred(X636D645F6C696E65315F246175783130,3,0)

 Define_Pred(X7365745F64656661756C745F6F7074696F6E73,0,0)

 Define_Pred(X7472616974655F6F7074,1,0)
 Define_Switch_CST_Table(Swt_Table_Name(X7472616974655F6F7074,1,1,cst),9)
     Define_Switch_CST(X63,Label_Pred_Name(X7472616974655F6F7074,1,3))
     Define_Switch_CST(X77616D,Label_Pred_Name(X7472616974655F6F7074,1,5))
     Define_Switch_CST(X666173745F6D617468,Label_Pred_Name(X7472616974655F6F7074,1,7))
     Define_Switch_CST(X6E6F5F696E6C696E65,Label_Pred_Name(X7472616974655F6F7074,1,9))
     Define_Switch_CST(X64626730,Label_Pred_Name(X7472616974655F6F7074,1,11))
     Define_Switch_CST(X646267,Label_Pred_Name(X7472616974655F6F7074,1,13))
     Define_Switch_CST(X64626731,Label_Pred_Name(X7472616974655F6F7074,1,15))
     Define_Switch_CST(X64626732,Label_Pred_Name(X7472616974655F6F7074,1,17))
     Define_Switch_CST(X76,Label_Pred_Name(X7472616974655F6F7074,1,19))

 Define_Pred(X646973706C61795F76657273696F6E,0,1)

 Define_Pred(X646973706C61795F68656C70,0,0)

 Define_Pred(X636F6D70696C6572,2,0)

 Define_Pred(X636F6D70696C65725F246175783131,3,0)

 Define_Pred(X657865635F706173736573,2,0)

 Define_Pred(X637265655F70617175657473,2,0)

 Define_Pred(X616A6F75745F636C61757365,3,0)

 Define_Pred(X74726F7576655F706171756574,4,0)

 Define_Pred(X666F726D61745F696E646578,3,0)

 Define_Pred(X657865635F696E6465786174696F6E,2,0)

 Define_Pred(X656E735F616A6F7574,3,1)

 Define_Pred(X656E735F72657472616974,3,1)

 Define_Pred(X656E735F656C74,2,1)

 Define_Pred(X656E735F696E746572,3,1)

 Define_Pred(X656E735F756E696F6E,3,1)

 Define_Pred(X656E735F636F6D706C,3,1)

 Define_Pred(X656E735F636F6D706C5F246175783132,4,0)

 Define_Pred(X6572726F72,1,1)

 Define_Pred(X676F,0,0)

 Define_Pred(X676F5F246175783133,1,0)

 Define_Pred(X246578655F31,0,0)

 Define_Pred(X246578655F32,0,0)

 Init_Usr_File

End_Init_Tables


Begin_Exec_Directives(wamcc)


 Exec_Directive(1,Pred_Name(X246578655F31,0))
 Exec_Directive(2,Pred_Name(X246578655F32,0))

End_Exec_Directives


/*** MAIN ***/

int main(int argc,char *argv[])

{
 unix_argc=argc;
 unix_argv=argv;


 Init_Wam_Engine();

 Init_Tables_Of_Module(Builtin)
 Init_Tables_Of_Module(wamcc0)
 Init_Tables_Of_Module(wamcc1)
 Init_Tables_Of_Module(wamcc2)
 Init_Tables_Of_Module(wamcc3)
 Init_Tables_Of_Module(wamcc4)
 Init_Tables_Of_Module(wamcc5)
 Init_Tables_Of_Module(wamcc6)
 Init_Tables_Of_Module(wamcc7)
 Init_Tables_Of_Module(wamcc8)
 Init_Tables_Of_Module(wamcc)

 Exec_Directives_Of_Module(Builtin)
 Exec_Directives_Of_Module(wamcc0)
 Exec_Directives_Of_Module(wamcc1)
 Exec_Directives_Of_Module(wamcc2)
 Exec_Directives_Of_Module(wamcc3)
 Exec_Directives_Of_Module(wamcc4)
 Exec_Directives_Of_Module(wamcc5)
 Exec_Directives_Of_Module(wamcc6)
 Exec_Directives_Of_Module(wamcc7)
 Exec_Directives_Of_Module(wamcc8)
 Exec_Directives_Of_Module(wamcc)

 Term_Wam_Engine();

 return 0;
}
