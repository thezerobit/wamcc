/*-------------------------------------------------------------------------*/
/* Prolog To Wam Compiler                INRIA Rocquencourt - CLoE Project */
/* C Run-time                                           Daniel Diaz - 1994 */
/*                                                                         */
/* GCC and WAM Configuration                                               */
/*                                                                         */
/* configure.c                                                             */
/*-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#define CONFIGURE

#include "bool.h"
#include "machine.h"




/*---------------------------------*/
/* Constants                       */
/*---------------------------------*/

/*---------------------------------*/
/* Type Definitions                */
/*---------------------------------*/

typedef struct
    {
     char type[32];
     char name[32];
    }RegInf;



typedef enum
    {
     INTEGER,
     UNSIGNED,
     STACK,
     MALLOC
    }TypTag;


typedef struct
    {
     char   name[32];
     TypTag type;
     char   cast[32];
    }TagInf;




typedef struct
   {
    char name[32];
    int  def_size;
    char top_macro[128];
   }StackInf;




/*---------------------------------*/
/* Global Variables                */
/*---------------------------------*/
char save_str[256];




/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/
void      Generate_Gcc          (int nb_of_used_regs);

int       Generate_Archi        (void);
char     *Read_Identifier       (char *s,Bool fail_if_error,char **end);
int       Read_Integer          (char *s,char **end);
int       Generate_Regs         (FILE *f,FILE *g);
void      Generate_Tags         (FILE *f,FILE *g);
void      Generate_Stacks       (FILE *f,FILE *g);

void      Fatal_Error           (char *format,...);




/*-------------------------------------------------------------------------*/
/* MAIN                                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
main()

{
 int nb_of_used_regs;
#ifndef M_MACHINE

 printf("Error: unsupported machine\n");
 exit(-1);
 
#endif

 nb_of_used_regs=Generate_Archi();
 Generate_Gcc(nb_of_used_regs);
 
 exit(0);
}




/*-------------------------------------------------------------------------*/
/* GENERATE_GCC                                                            */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Generate_Gcc(int nb_of_used_regs)

{
 FILE  *f;
 char   str[4096];
 char  *used_regs[]=M_USED_REGS;
 int    i;
#ifdef NO_REGS
 char  *no_regs="-DNO_REGS";
#else
 char  *no_regs="";
#endif

 printf("Configuring %s for %s\n",COMPILER,M_MACHINE);
 if ((f=fopen(WGCC,"w"))==NULL)
     Fatal_Error("cannot open %s",WGCC);

 fprintf(f,"#!/bin/sh\n");
 sprintf(str,"gcc -DM_%s %s -DCOMPILER='\"'%s'\"' %s -I. -I%s -L. -L%s ",
         M_MACHINE,no_regs,COMPILER,EXTRA_CFLAGS,INCPATH,LIBPATH);

 for(i=0;i<nb_of_used_regs;i++)
     sprintf(str+strlen(str),"-ffixed-%s ",used_regs[i]);

 strcat(str,"$*");
 fprintf(f,"%s",str);
 fclose(f);
}




/*-------------------------------------------------------------------------*/
/* GENERATE_ARCHI                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
int Generate_Archi(void)

{
 FILE *f,*g;
 char  str[256];
 char *p1,*p2;
 int   nb_of_used_regs;

 if ((f=fopen("archi.def","r"))==NULL)
     Fatal_Error("cannot open archi.def",WGCC);

 if ((g=fopen("archi.h","w"))==NULL)
     Fatal_Error("cannot open archi.h",WGCC);

 while(!feof(f) && fgets(str,sizeof(str),f))
    {
     if (*str!='@')
        {
         fputs(str,g);
         continue;
        }

     strcpy(save_str,str);
     p1=Read_Identifier(str+1,TRUE,&p2);

     if (strcmp(p1,"begin")!=0)
         Fatal_Error("Syntax error: incorrect @ declaration in: %s",save_str);

     p1=Read_Identifier(p2+1,TRUE,&p2);

     if (strcmp(p1,"regs")==0)
        {
         nb_of_used_regs=Generate_Regs(f,g);
         continue;
        }

     if (strcmp(p1,"tags")==0)
        {
         Generate_Tags(f,g);
         continue;
        }

     if (strcmp(p1,"stacks")==0)
        {
         Generate_Stacks(f,g);
         continue;
        }


     Fatal_Error("Syntax error: unknown division in: %s",save_str);
    }

 fclose(f);
 fclose(g);

 return nb_of_used_regs;
}




/*-------------------------------------------------------------------------*/
/* READ_IDENTIFIER                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
char *Read_Identifier(char *s,Bool fail_if_error,char **end)

{
 while(isspace(*s))
     s++;

 *end=s;
 if (!isalpha(**end))
     if (fail_if_error)
         Fatal_Error("Syntax error: identifier expected in: %s",save_str);
      else
         return NULL;

 do
     (*end)++;
 while(isalnum(**end) || **end=='_');

 if (!isspace(**end))
     Fatal_Error("Syntax error: space expected after identifier in: %s",
                 save_str);

 **end='\0';

 return s;
}
 



/*-------------------------------------------------------------------------*/
/* READ_INTEGER                                                            */
/*                                                                         */
/*-------------------------------------------------------------------------*/
int Read_Integer(char *s,char **end)

{
 int x=0;

 while(isspace(*s))
     s++;

 *end=s;
 if (!isdigit(**end))
     Fatal_Error("Syntax error: integer expected in: %s",save_str);

 do
    {
     x=x*10+**end-'0';
     (*end)++;
    }
 while(isdigit(**end) || **end=='_');

 if (!isspace(**end))
     Fatal_Error("Syntax error: space expected after identifier in: %s",
                 save_str);
 **end='\0';
 return x;
}

 


/*-------------------------------------------------------------------------*/
/* GENERATE_REGS                                                           */
/*                                                                         */
/* initial filler description                                              */
/*    @filler size                                                         */
/*                                                                         */
/* register description:                                                   */
/*    @reg priority type name                                              */
/*         priority: 1-9 (1:high, 9:low)                                   */
/*         type must be machine word castable (ex int unsigned pointer...) */
/*                                                                         */
/*-------------------------------------------------------------------------*/
int Generate_Regs(FILE *f,FILE *g)

{
 char    *p1,*p2;
 char     str[256];
 char     offset[32]="";
 char    *used_regs[]=M_USED_REGS;
 int      nb_of_used_regs=0;
 RegInf   reg[10][128]={};
 int      nb_reg[10]={0,0,0,0,0,0,0,0,0,0};
 RegInf  *dp;
 char    **p;
 int      total_nb_reg=0;
 int      nb_not_alloc=0;
 int      i,j,k;


 for(;;)
    {
     if (feof(f) || !fgets(str,sizeof(str),f))
         Fatal_Error("Syntax error: end expected for @begin reg");

     if (*str!='@')
        {
         if (*str!='\n')
             fputs(str,g);
         continue;
        }

     strcpy(save_str,str);
     p1=Read_Identifier(str+1,TRUE,&p2);

     if (strcmp(p1,"end")==0)
         break;

     if (strcmp(p1,"filler")==0)
        {
         p1=Read_Identifier(p2+1,FALSE,&p2);
	 if (!p1)
            {
             i=Read_Integer(p2,&p2);
             p1=str;
             sprintf(p1,"%d",i);
            }

         sprintf(offset+strlen(offset),"%s+",p1);
         continue;
        }

     if (strcmp(p1,"reg")==0)
        {
         i=Read_Integer(p2+1,&p2);
         strcpy(reg[i][nb_reg[i]].type,Read_Identifier(p2+1,TRUE,&p2));
         strcpy(reg[i][nb_reg[i]].name,Read_Identifier(p2+1,TRUE,&p2));
         nb_reg[i]++;
         continue;
        }

     Fatal_Error("Syntax error: incorrect @ declaration in: %s",save_str);
    }



 fprintf(g,"\n\n   /*--- Begin Register Generation ---*/\n\n");

 p=used_regs;
 if (*p)
    {
     nb_of_used_regs++;
     fprintf(g,"register WamWord \t\t*reg_bank asm (\"%s\");\n\n",*p++);
    }
  else
    {
     fprintf(g,"#ifdef WAM_ENGINE\n\n");
     fprintf(g,"       WamWord \t\t\t*reg_bank;\n");
     fprintf(g,"\n#else\n\n");
     fprintf(g,"extern WamWord \t\t\t*reg_bank;\n");
     fprintf(g,"\n#endif\n\n");
    }

 for(i=0;i<10;i++)
     for(j=0,total_nb_reg+=nb_reg[i];j<nb_reg[i];j++)
        {
         dp= &reg[i][j];
         if (*p)
            {
             nb_of_used_regs++;
             fprintf(g,"register %s\t\t%-3s asm (\"%s\");\n",
                     dp->type,dp->name,*p++);
             if (!*p)
                 fprintf(g,"\n\n");
            }
          else
             fprintf(g,"#define %s\t\t\t((%s)\t (reg_bank[%s%d]))\n",
                     dp->name,dp->type,offset,nb_not_alloc++);
        }


 fprintf(g,"\n\n");
 fprintf(g,"#define NB_OF_REGS          \t%d\n",total_nb_reg);
 fprintf(g,"#define NB_OF_ALLOC_REGS    \t%d\n",total_nb_reg-nb_not_alloc);
 fprintf(g,"#define NB_OF_NOT_ALLOC_REGS\t%d\n",nb_not_alloc);
 fprintf(g,"#define REG_BANK_SIZE       \t(%sNB_OF_NOT_ALLOC_REGS)\n",offset);

 fprintf(g,"\n\n");
 fprintf(g,"#define Reg(i)\t\t\t(");
 k=0;
 for(i=0;i<10;i++)
     for(j=0;j<nb_reg[i];j++)
        {
         dp= &reg[i][j];
         if (k<total_nb_reg-1)
             fprintf(g,"((i)==%d) ? (WamWord) %-3s\t: \\\n\t\t\t\t ",
                     k++,dp->name);
          else
             fprintf(g,"           (WamWord) %s)\n",dp->name);
        }


 fprintf(g,"\n");
 fprintf(g,"#ifdef WAM_ENGINE\n\n");
 fprintf(g,"       char    *reg_tbl[]=\t{");
 k=0;
 for(i=0;i<10;i++)
     for(j=0;j<nb_reg[i];j++)
        {
         dp= &reg[i][j];
         fprintf(g,"\"%s\"%s",dp->name,k<total_nb_reg-1 ? "," : "};\n");
         k++;
        }

 fprintf(g,"\n#else\n\n");
 fprintf(g,"extern char    *reg_tbl[];\n");

 fprintf(g,"\n#endif\n");

 

 fprintf(g,"\n\n\n\n#define NB_OF_USED_MACHINE_REGS %d\n",nb_of_used_regs);
 fprintf(g,"\n\n\n\n#define Save_Machine_Regs(buff_save)\t\t\\\n");
 fprintf(g,"    {               \t\t\t\t\\\n");

 for(i=0;i<nb_of_used_regs;i++)
     fprintf(g,"     register int reg%d asm (\"%s\");\t\t\\\n",i,used_regs[i]);

 for(i=0;i<nb_of_used_regs;i++)
     fprintf(g,"     buff_save[%d]=reg%d;\t\t\t\t\\\n",i,i);

 fprintf(g,"    }\n");



 fprintf(g,"\n\n\n\n#define Restore_Machine_Regs(buff_save)\t\\\n");
 fprintf(g,"    {               \t\t\t\t\\\n");

 for(i=0;i<nb_of_used_regs;i++)
     fprintf(g,"     register int reg%d asm (\"%s\");\t\t\\\n",i,used_regs[i]);

 for(i=0;i<nb_of_used_regs;i++)
     fprintf(g,"     reg%d=buff_save[%d];\t\t\t\t\\\n",i,i);

 fprintf(g,"    }\n");



 fprintf(g,"\n\n   /*--- End Register Generation ---*/\n\n");

 return nb_of_used_regs;
}




/*-------------------------------------------------------------------------*/
/* GENERATE_TAGS                                                           */
/*                                                                         */
/* tag description:                                                        */
/*    @tag name type [cast_type]                                           */
/*         type of the value: int/unsigned/stack/malloc                    */
/*-------------------------------------------------------------------------*/
void Generate_Tags(FILE *f,FILE *g)

{
 char     str[256];
 char    *p1,*p2;
 TagInf   tag[128];
 int      nb_tag=0;
 int      tag_size;
 unsigned malloc_start;
 unsigned malloc_high_adr;
 unsigned high_tag_mask;
 int      i;


 for(;;)
    {
     if (feof(f) || !fgets(str,sizeof(str),f))
         Fatal_Error("Syntax error: end expected for @begin tag");

     if (*str!='@')
        {
         if (*str!='\n')
             fputs(str,g);
         continue;
        }

     strcpy(save_str,str);
     p1=Read_Identifier(str+1,TRUE,&p2);

     if (strcmp(p1,"end")==0)
         break;

     if (strcmp(p1,"tag")==0)
        {
         strcpy(tag[nb_tag].name,Read_Identifier(p2+1,TRUE,&p2));
         p1=Read_Identifier(p2+1,TRUE,&p2);

         if (strcmp(p1,"int")==0)
             tag[nb_tag].type=INTEGER;
          else
             if (strcmp(p1,"unsigned")==0)
                 tag[nb_tag].type=UNSIGNED;
              else
                 if (strcmp(p1,"stack")==0)
                     tag[nb_tag].type=STACK;
                  else
                     if (strcmp(p1,"malloc")==0)
                         tag[nb_tag].type=MALLOC;
                      else
                         Fatal_Error("Syntax error: wrong tag type in: %s",
                                      save_str);

         if (p1=Read_Identifier(p2+1,FALSE,&p2))
             strcpy(tag[nb_tag].cast,p1);
          else
             tag[nb_tag].cast[0]='\0';

         nb_tag++;
         continue;
        }

     Fatal_Error("Syntax error: incorrect @ declaration in: %s",save_str);
    }




 fprintf(g,"\n\n   /*--- Begin Tag Generation ---*/\n\n");

 for(tag_size=0;(1<<tag_size) < nb_tag;tag_size++)
     ;

 high_tag_mask= (int) 0x80000000 >> (tag_size-1);

 malloc_start=(unsigned) malloc(256);
 malloc_high_adr=malloc_start+16*1024*1024;

 fprintf(g,"#define TAG_SIZE  \t\t%d\n",tag_size);
 fprintf(g,"#define VALUE_SIZE \t\t%d\n",32-tag_size);

 fprintf(g,"\n");
 for(i=0;i<nb_tag;i++)
     fprintf(g,"#define %-10s \t\t%-2d\n",tag[i].name,i);
 
 fprintf(g,"\n");
 fprintf(g,"#define MALLOC_MASK \t\t%#x\n",malloc_high_adr & high_tag_mask);

#if defined(M_USE_MMAP)

 fprintf(g,"#define STACK_MASK  \t\t%#x\n",M_MMAP_HIGH_ADR & high_tag_mask);

#elif defined(M_USE_SHM)

 fprintf(g,"#define STACK_MASK  \t\t%#x\n",M_SHM_HIGH_ADR & high_tag_mask);

#else

 fprintf(g,"#define STACK_MASK  \t\tMALLOC_MASK\n");

#endif

 fprintf(g,"#define MALLOC_START \t\t%#x\n",malloc_start & 0xFF000000);

 fprintf(g,"\n");
 fprintf(g,"#define Tag_Value(t,v) \t\t(((unsigned) (v) << %d) | (t))\n",tag_size);
 fprintf(g,"#define Tag_Of(w)      \t\t((unsigned) (w) & %#x)\n",(1<<tag_size)-1);

 fprintf(g,"\n");
 fprintf(g,"#define UnTag_Integer(w) \t((int) (((int) (w) >> %d)))\n",
         tag_size);

 fprintf(g,"#define UnTag_Unsigned(w)\t((unsigned) (((unsigned) (w) >> %d)))\n",
         tag_size);

 fprintf(g,"#define UnTag_Stack(w)   \t((WamWord *) (((unsigned) (w) >> %d) | STACK_MASK))\n",
         tag_size);
 fprintf(g,"#define UnTag_Malloc(w)  \t((int) (((unsigned) (w) >> %d) | MALLOC_MASK))\n",
         tag_size);


 fprintf(g,"\n");

 fprintf(g,"#define NB_OF_TAGS       \t%d\n\n",nb_tag);

 for(i=0;i<nb_tag;i++)
    {
     fprintf(g,"#define Tag_%s(v)  \t\tTag_Value(%s,v)\n",
             tag[i].name,tag[i].name);
     fprintf(g,"#define UnTag_%s(w) \t\t",tag[i].name);

     if (tag[i].cast[0])
         fprintf(g,"((%s) ",tag[i].cast);

     fprintf(g,"UnTag_%s(w)%s\n\n",
             (tag[i].type==INTEGER) ? "Integer" :
             (tag[i].type==UNSIGNED) ? "Unsigned" :
             (tag[i].type==STACK) ? "Stack" : "Malloc",
             (tag[i].cast[0]) ? ")" : "");
    }


 fprintf(g,"\ntypedef enum\n");
 fprintf(g,"    {\n");
 fprintf(g,"     INTEGER,\n");
 fprintf(g,"     UNSIGNED,\n");
 fprintf(g,"     STACK,\n");
 fprintf(g,"     MALLOC\n");
 fprintf(g,"    }TypTag;\n");

 fprintf(g,"\ntypedef struct\n");
 fprintf(g,"    {\n");
 fprintf(g,"     char    *name;\n");
 fprintf(g,"     TypTag   type;\n");
 fprintf(g,"    }InfTag;\n\n\n");


 fprintf(g,"#ifdef WAM_ENGINE\n\n");
 fprintf(g,"       InfTag   tag_tbl[]=\t{");

 for(i=0;i<nb_tag;i++)
    {
     fprintf(g,"{\"%s\",%s}%s",tag[i].name,
             (tag[i].type==INTEGER) ? "INTEGER" :
             (tag[i].type==UNSIGNED) ? "UNSIGNED" :
             (tag[i].type==STACK) ? "STACK" : "MALLOC",
             (i<nb_tag-1) ? ",\n\t\t\t\t " : "};\n");
    }

 fprintf(g,"\n#else\n\n");
 fprintf(g,"extern InfTag   tag_tbl[];\n");
 fprintf(g,"\n#endif\n");


 fprintf(g,"\n\n   /*--- End Tag Generation ---*/\n\n");
}




/*-------------------------------------------------------------------------*/
/* GENERATE_STACKS                                                         */
/*                                                                         */
/* stack description:                                                      */
/*    @stack name default_size stack_top_macro                             */
/*-------------------------------------------------------------------------*/
void Generate_Stacks(FILE *f,FILE *g)

{
 char     str[256];
 char    *p1,*p2;
 int      i;
 StackInf stack[128];
 int      nb_stack=0;

 for(;;)
    {
     if (feof(f) || !fgets(str,sizeof(str),f))
         Fatal_Error("Syntax error: end expected for @begin stack");

     if (*str!='@')
        {
         if (*str!='\n')
             fputs(str,g);
         continue;
        }

     strcpy(save_str,str);
     p1=Read_Identifier(str+1,TRUE,&p2);

     if (strcmp(p1,"end")==0)
         break;

     if (strcmp(p1,"stack")==0)
        {
         strcpy(stack[nb_stack].name,Read_Identifier(p2+1,TRUE,&p2));
         i=Read_Integer(p2+1,&p2);
         stack[nb_stack].def_size=i*1024/sizeof(int);
         strcpy(stack[nb_stack].top_macro,Read_Identifier(p2+1,TRUE,&p2));
         nb_stack++;
         continue;
        }

     Fatal_Error("Syntax error: incorrect @ declaration in: %s",save_str);
    }


 fprintf(g,"\n\n   /*--- Begin Stack Generation ---*/\n\n");

 fprintf(g,"#define NB_OF_STACKS \t\t%d\n\n",nb_stack);


 for(i=0;i<nb_stack;i++)
    {
     strcpy(str,stack[i].name);
     *str=toupper(*str);

     fprintf(g,"#define %s_Stack       \t(stk_tbl[%d].stack)\n",str,i);
     fprintf(g,"#define %s_Size        \t(stk_tbl[%d].size)\n", str,i);
     fprintf(g,"#define %s_Offset(adr) \t((WamWord *)(adr)-%s_Stack)\n",
             str,str);
     fprintf(g,"#define %s_Used_Size   \t%s_Offset(%s)\n\n",str,str,
             stack[i].top_macro);
    }

 fprintf(g,"\n#define Stack_Top(s)       \t(");
 for(i=0;i<nb_stack-1;i++)
     fprintf(g,"((s)==%d) ? %s : ",i,stack[i].top_macro);

 fprintf(g,"%s)\n",stack[nb_stack-1].top_macro);


 fprintf(g,"\ntypedef struct\n");
 fprintf(g,"    {\n");
 fprintf(g,"     char    *name;\n");
 fprintf(g,"     char    *env_var_name;\n");
 fprintf(g,"     int      default_size; \t/* in WamWords */\n");
 fprintf(g,"     int      size;         \t/* in WamWords */\n");
 fprintf(g,"     WamWord *stack;\n");
 fprintf(g,"    }InfStack;\n\n\n");


 fprintf(g,"#ifdef WAM_ENGINE\n\n");
 fprintf(g,"       InfStack  stk_tbl[]=\t{");

 for(i=0;i<nb_stack;i++)
    {
     strcpy(str,stack[i].name);
     for(p1=str;*p1;p1++)
         *p1=toupper(*p1);

     fprintf(g,"{\"%s\",\"%sSZ\",%d,0,NULL}%s",
             stack[i].name,str,stack[i].def_size,
             (i<nb_stack-1) ? ",\n\t\t\t\t " : "};\n");
    }

 fprintf(g,"\n#else\n\n");
 fprintf(g,"extern InfStack stk_tbl[];\n");
 fprintf(g,"\n#endif\n");


 fprintf(g,"\n\n   /*--- End Stack Generation ---*/\n\n");
}




/*-------------------------------------------------------------------------*/
/* FATAL_ERROR                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Fatal_Error(char *format,...)

{
 va_list arg_ptr;

 va_start(arg_ptr,format);
 vprintf(format,arg_ptr);
 va_end(arg_ptr);

 printf("\n");
 exit(1);
}
