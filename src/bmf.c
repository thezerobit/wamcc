/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Application Manager                                  Daniel Diaz - 1991 */
/*                                                                         */
/* Build Make File                                                         */
/*                                                                         */
/* bmf.c                                                                   */
/*-------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

#include "bool.h"



/*---------------------------------*/
/* Constants                       */
/*---------------------------------*/

#define MAX_MODULES                256
#define MAX_OTHERS                 256
#define MAX_NAME_LG                65
#define MAX_FLAGS_LG               256

#define NB_NAME_PER_LINE           5

#define ERR_OPEN_FILE              "Error - cannot open %s file\n"




/*---------------------------------*/
/* Type Definitions                */
/*---------------------------------*/

/*---------------------------------*/
/* Global Variables                */
/*---------------------------------*/

char executable[MAX_NAME_LG]="";

char modules   [MAX_MODULES][MAX_NAME_LG];
int  nb_modules             =0;

char others    [MAX_OTHERS][MAX_NAME_LG];
int  nb_others              =0;

char pflags[MAX_FLAGS_LG]   ="";

char cflags[MAX_FLAGS_LG]   ="-O2";

char lflags[MAX_FLAGS_LG]   ="-s";

Bool verbose                =FALSE;




char *make_lines[]=
{
   "OBJS      = $(MODULES) $(OTHERS)"
   "",
   ".SUFFIXES:",
   ".SUFFIXES: .o .usr .c .pl $(SUFFIXES)",
   "",
   ".pl.c:",
   "\t$(COMPILER) $(PFLAGS) -c $*.pl",
   "",
   ".pl.usr:",
   "\tif [ -f $*.usr ]; then \\",
   "\ttouch $*.usr; \\",
   "\telse \\",
   "\t$(COMPILER) $(PFLAGS) -c $*.pl; \\",
   "\tfi",
   "",
   ".usr.o:",
   "\t$(WGCC) $(CFLAGS) -c $*.c",
   "",
   ".c.o:",
   "\t$(WGCC) $(CFLAGS) -c $*.c",
   "",
   "$(EXECUTABLE): $(OBJS)",
   "\t$(WGCC) -o $(EXECUTABLE)    $(CFLAGS) $(LFLAGS) $(OBJS) -l$(COMPILER)",
   "",
   "$(EXECUTABLE)_pp: $(OBJS)",
   "\t$(WGCC) -o $(EXECUTABLE)_pp $(CFLAGS) $(LFLAGS) $(OBJS) -l$(COMPILER)_pp",
   "",
   "@"
};




/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/

void      Read_Parameters       (int argc,char *argv[]);
void      Generate_Make_File    (void);
void      Display_Parameters    (void);
void      Display_Help_And_Exit (char *bmf_name);




/*-------------------------------------------------------------------------*/
/* MAIN                                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
main(int argc,char *argv[])

{
 char *p;

 Read_Parameters(argc,argv);

 if (verbose)
     printf("Build Make File\n\n");

 if (nb_modules==0)
    {
     printf("No module specified (use -h to get some help)\n");
     exit(1);
    }

 if (*executable=='\0')
    {
     strcpy(executable,modules[0]);
     if (p=strrchr(executable,'.'))
         *p='\0';
    }

 if (verbose)
     Display_Parameters();    /* Generate_Make_File erases .d in modules[] */

 Generate_Make_File();
 exit(0);
}




/*-------------------------------------------------------------------------*/
/* READ_PARAMETERS                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Read_Parameters(int argc,char *argv[])

{
 char  c;
 char *p;
 int   i,j;
 int   x;

 if (argc==1)
     Display_Help_And_Exit(argv[0]);

 for(i=1;i<argc;i++)
    {
     if (argv[i][0]=='-')
        {
         c=argv[i][1];
         if (argv[i][2] || strchr("oPCLvh",c)==NULL)
            {
             printf("unknown option %s",argv[i]);
             printf(" (use -h to get some help)\n");
             exit(1);
            }

         switch(argv[i][1])
            {
             case 'o':
                 if (++i==argc)
                     break;

                 strcpy(executable,argv[i]);
                 continue;

             case 'P':
                 if (++i==argc)
                     break;

                 strcpy(pflags,argv[i]);
                 continue;

             case 'C':
                 if (++i==argc)
                     break;

                 strcpy(cflags,argv[i]);
                 continue;

             case 'L':
                 if (++i==argc)
                     break;

                 strcpy(lflags,argv[i]);
                 continue;

             case 'v':
                 verbose=TRUE;
                 continue;

             case 'h':
                 Display_Help_And_Exit(argv[0]);
                 continue;
            }

         printf("argument expected for option %s",argv[i-1]);
         printf(" (use -h to get some help)\n");
         exit(1);
        }

     p=strrchr(argv[i],'.');
     if (p==NULL)
         strcpy(modules[nb_modules++],argv[i]);
      else
         if (strcmp(p,".pl")==0)
             sprintf(modules[nb_modules++],"%.*s",p-argv[i],argv[i]);
          else
             strcpy(others[nb_others++],argv[i]);
    }

 if (verbose)
     strcat(pflags," -v");
}




/*-------------------------------------------------------------------------*/
/* GENERATE_MAKE_FILE                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Generate_Make_File(void)

{
 char name[1024];
 FILE *mf;
 int   i;
 char *p;

 sprintf(name,"%s.mk",executable);
 if ((mf=fopen(name,"w"))==NULL)
    {
     printf(ERR_OPEN_FILE,name);
     exit(1);
    }

 fprintf(mf,"# Executable's make file: %s\n\n",name);

 if (!verbose)
     fprintf(mf,".SILENT:\n\n");
 
 fprintf(mf,"EXECUTABLE= %s\n",executable);

 fprintf(mf,"MODULES   =");
 for(i=0;i<nb_modules;)
    {
     fprintf(mf," %s.o",modules[i]);
     if ((++i) % NB_NAME_PER_LINE==0 && i!=nb_modules)
         fprintf(mf," \\\n           ");
    }
 fprintf(mf,"\n");

 fprintf(mf,"OTHERS    =");
 for(i=0;i<nb_others;)
    {
     fprintf(mf," %s",others[i]);
     if ((++i) % NB_NAME_PER_LINE==0 && i!=nb_others)
         fprintf(mf," \\\n           ");
    }
 fprintf(mf,"\n\n");

 fprintf(mf,"COMPILER  = %s\n",COMPILER);           /* macro defined by -D */
 fprintf(mf,"WGCC      = %s\n",WGCC);
 fprintf(mf,"PFLAGS    = %s\n",pflags);
 fprintf(mf,"CFLAGS    = %s\n",cflags);
 fprintf(mf,"LFLAGS    = %s\n\n",lflags);


 for(i=0;*make_lines[i]!='@';i++)
     fprintf(mf,"%s\n",make_lines[i]);

 for(i=0;i<nb_modules;i++)
    {
     fprintf(mf,"%s.o: ",modules[i]);

     if (p=strrchr(modules[i],'.'))
        *p='\0';

     fprintf(mf,"%s.c %s.usr\n\n",modules[i],modules[i]);
    }
 fclose(mf);
}




/*-------------------------------------------------------------------------*/
/* DISPLAY_PARAMETERS                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Display_Parameters(void)

{
 int i;


 printf("   Make file generated       : %s.mk\n\n",executable);

 printf("   Executable name           : %s\n",executable);
 printf("   Executable name (profiled): %s_pp\n\n",executable);

 printf("   Modules                   :");
 for(i=0;i<nb_modules;)
    {
     printf(" %s",modules[i]);
     if ((++i) % NB_NAME_PER_LINE==0 && i!=nb_modules)
         printf("\n%30s","");
    }
 printf("\n\n");

 printf("   Others                    :");
 for(i=0;i<nb_others;)
    {
     printf(" %s",others[i]);
     if ((++i) % NB_NAME_PER_LINE==0 && i!=nb_others)
         printf("\n%30s","");
    }

 printf("\n\n");

 printf("   Prolog compiler flags     : %s\n\n",pflags);

 printf("   C compiler flags          : %s\n\n",cflags);

 printf("   Linker flags              : %s\n\n",lflags);

 printf("   use 'make -f %s.mk [%s]'  to create the executable %s\n",
        executable,executable,executable);
 printf("   use 'make -f %s.mk %s_pp' to create the executable %s_pp\n",
        executable,executable,executable);

 putchar('\n');
}




/*-------------------------------------------------------------------------*/
/* DISPLAY_HELP_AND_EXIT                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Display_Help_And_Exit(char *bmf_name)

{
 printf("Build Make File\n\n");

 printf("Usage:\n\n");
 printf("%s [option | filename]...\n\n",bmf_name);
 printf("Options:\n\n");
 printf("   -o file   choose file as executable file (default: first module name)\n");
 printf("   -P pflags use pflags for the Prolog compiler (default: %s)\n",pflags);
 printf("   -C cflags use cflags for the C compiler (default: %s)\n",cflags);
 printf("   -L lflags use lflags for the linker (default: %s)\n",lflags);
 printf("   -v        verbose mode\n");
 printf("   -h        display help\n");
 printf("\n");
 printf("A filename is a module name, an object file (.o) or an archive file (.a).\n");
 printf("\n");

 exit(0);
}




