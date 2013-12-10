/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Application Manager                                  Daniel Diaz - 1991 */
/*                                                                         */
/* BuiltIn Starter File Builder                                            */
/*                                                                         */
/* build_starter.c                                                         */
/*-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*---------------------------------*/
/* Constants                       */
/*---------------------------------*/

/*---------------------------------*/
/* Type Definitions                */
/*---------------------------------*/

/*---------------------------------*/
/* Global Variables                */
/*---------------------------------*/

/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/


/*-------------------------------------------------------------------------*/
/* MAIN                                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
main(int argc, char *argv[])

{
 int  i;
 char name[256];

 printf("#include \"wam_engine.h\"\n\n");
 printf("#define  DEBUG_LEVEL         0\n");
 printf("#define  NB_OF_PRIVATE_PREDS 0\n\n");

 printf("static char *module_name=\"Builtin\";\n");
 printf("static int   module_nb= -1;\n\n");

 printf("Begin_Init_Tables(Builtin)\n\n");
 for(i=1;;)
    {
     strcpy(name,argv[i++]);
     name[strlen(name)-2]='\0';
     printf(" Init_Tables_Of_Module(%s)\n",name);
     if (i==argc)
         break;
    }
 printf("\nEnd_Init_Tables\n\n");


 printf("Begin_Exec_Directives(Builtin)\n\n");
 for(i=1;;)
    {
     strcpy(name,argv[i++]);
     name[strlen(name)-2]='\0';
     printf(" Exec_Directives_Of_Module(%s)\n",name);
     if (i==argc)
         break;
    }
 printf("\nEnd_Exec_Directives\n\n");

 return 0;
}

