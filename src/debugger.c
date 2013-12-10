/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* C Run-time                                           Daniel Diaz - 1994 */
/*                                                                         */
/* Prolog/Wam Debugger                                                     */
/*                                                                         */
/* debugger.c                                                              */
/*-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


#include "wam_engine.h"

#define DEBUGGER
#include "debugger.h"

extern vsprintf();
long strtol();



/*---------------------------------*/
/* Constants                       */
/*---------------------------------*/

#define CALL                       1
#define EXIT                       2
#define FAIL                       4
#define REDO                       8
#define WAMI                      16


#define MAX_SPY_TBL_SIZE           64


#define DEFAULT_DEBUG_STACK_SZ     10240                    /* in WamWords */
#define DEBUG_STACK_ENV_VAR_NAME   "DEBUGSZ"


#define BANK_NAME_OFFSET_LENGTH    13

#define HEXADECIMAL_LENGTH         10
#define DECIMAL_LENGTH             10
#define VALUE_PART_LENGTH          BANK_NAME_OFFSET_LENGTH



#define ERR_ALLOC_DEBUG            "Memory allocation fault (in debugger)"
#define ERR_DEBUG_STACK_OVERFLOW   "debug stack overflow"




#define SEPARATOR_LIST             " ,[]"



#define ABORT                      X61626F7274
#define DBG_EXEC                   X6462675F65786563




/*---------------------------------*/
/* Type Definitions                */
/*---------------------------------*/

typedef enum
    {
     DEBUGGED,
     EXTERNAL,
     DYNAMIC
    }PDbgTyp;

typedef struct runinf *PRunInf;

typedef struct runinf                      /* one env = info call of f/n   */
    {
     PRunInf  last_env;                    /* previous env in the stack    */
     PRunInf  caller_env;                  /* env caller of this one       */
     AtomInf *atom;                        /* functor atom (f)             */
     int      arity;                       /* arity        (n)             */
     PDbgTyp type;                        /* debugged(local)/external/dyn */
     Bool     aux_pred;                    /* is it an auxiliary predicate?*/
     WamCont  cp;                          /* copy of CP before the call   */
     WamWord *e;                           /* copy of E  before the call   */
     WamWord *b;                           /* copy of B  before the call   */
     int      invoc_nb;                    /* invocation number            */
     int      indice_nb;                   /* indice number                */
     WamWord  word;                        /* term: <STC,&f_n> or <CST,f>  */
     union                                 /* or heap term (if dynamic)    */
       {                                   /* if !dynamic and arity > 0    */
        WamWord  f_n;                      /*    word f/n                  */
        Bool     first_clause;             /*    first clause (try) if dyn */
       }x;
    }RunInf;




typedef Bool (*FctPtr)();

typedef struct
    {
     char  *name;
     FctPtr fct;
    }InfCmd;



/*---------------------------------*/
/* Global Variables                */
/*---------------------------------*/


static AtomInf *atom_debug;
static AtomInf *atom_nodebug;
static AtomInf *atom_trace;
static AtomInf *atom_call;
static AtomInf *atom_exit;
static AtomInf *atom_fail;
static AtomInf *atom_redo;

static AtomInf *debug_mode;

static RunInf  *debug_stack=NULL;
static RunInf  *end_debug_stack;
static RunInf  *top_stack;
static RunInf  *top_env;
static int      invoc_nb;

static char    *spy_tbl;
static int      skip_invoc_nb;
static Bool     leap_mode;
static Bool     exact_trace;
static int      wam_curr_inst;
static int      wam_next_inst;

static int      leash_option;

static int      depth;

static Bool     redo;
static Bool     catch_fail;

static int      nb_read_arg;
static char     read_arg[30][80];


static char     str_next_inst[80];

static char    *envir_name[]=ENVIR_NAMES;
static char    *choice_name[]=CHOICE_NAMES;
static char    *trail_tag_name[]=TRAIL_TAG_NAMES;
static WamWord  reg_copy[NB_OF_REGS];




/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/

static
RunInf   *Find_Non_Determin_Env (RunInf *top,WamWord *b);

static
void      Call_Port             (AtomInf *atom,int arity,PDbgTyp type);

static
void      Exit_Port             (Bool from_dynamic);

static
void      Fail_Port             (void);

static
void      Redo_Port             (void);

static
void      Read_Command          (int port,Bool read_cmd);

static
void      Scan_Command          (char *source_str);

static
FctPtr    Find_Function         (void);

static
Bool      Creep                 (void);

static
Bool      Skip                  (int port);

static
Bool      Leap                  (void);

static
Bool      Abort                 (void);

static
Bool      Goals_GoalsB          (void);
static
void      One_Goal              (int nb,RunInf *top_last_e,
                                 RunInf *top_caller_e,WamWord *b);

static
Bool      Leash                 (void);

static
Bool      NoDebug               (void);

static 
Bool      Debugging             (void);

static
Bool      Spy_NoSpy_NoSpyAll    (void);

static 
Bool      Exec_Prolog_Goal      (void);

static 
Bool      Depth                 (void);

static 
Bool      Exact_NoExact         (void);





static 
Bool      Write_Data_Modify     (void);

static 
Bool      Where                 (void);

static 
Bool      Dereference           (void);

static 
Bool      Environment           (void);

static 
Bool      Backtrack             (void);

static 
WamWord  *Read_Bank_Adr         (Bool only_stack,int arg_nb,
                                 char **bank_name);

static 
int       Read_Integer          (int arg_nb);

static 
void      Print_Bank_Name_Offset(char *prefix,char *bank_name,int offset);

static
void      Print_Wam_Word        (WamWord *word_adr);

static 
void      Modify_Wam_Word       (WamWord *word_adr);

static
WamWord  *Detect_Stack          (WamWord *adr,char **stack_name);

static 
Bool      Instruction           (void);

static 
Bool      Help                  (void);




#define math_max(x,y)           (((x)>(y)) ? (x) : (y))




#define Y_Storing_Invoc_Nb(e)   (Y(e,3))                   /* see call.pl */






/*-------------------------------------------------------------------------*/
/* INIT_DEBUGGER                                                           */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Init_Debugger(void)

{
 char *p;
 int   x=DEFAULT_DEBUG_STACK_SZ;

 if (debug_stack==NULL)
    {
     p=(char *) Lib1(getenv,DEBUG_STACK_ENV_VAR_NAME);
     if (p && *p)
        {
         x=Lib1(atoi,p);
         x=KBytes_To_Wam_Words(x);
        }

     if ((debug_stack=(RunInf *) Lib1(malloc,x*sizeof(WamWord)))==NULL)
          Fatal_Error(ERR_ALLOC_DEBUG);

     end_debug_stack=(RunInf *) ((WamWord *) debug_stack+x);


     spy_tbl=Hash_Table(MAX_SPY_TBL_SIZE,sizeof(int),sizeof(int));
     if (spy_tbl==NULL)
         Fatal_Error(ERR_ALLOC_DEBUG);

     atom_debug  =Create_Atom("debug");
     atom_nodebug=Create_Atom("nodebug");
     atom_trace  =Create_Atom("trace");
     atom_call   =Create_Atom("call");
     atom_exit   =Create_Atom("exit");
     atom_fail   =Create_Atom("fail");
     atom_redo   =Create_Atom("redo");
    }

 top_stack=top_env=debug_stack;

 top_env->atom     =Create_Atom("????????");                  /* dummy env */
 top_env->arity    =0;
 top_env->type     =EXTERNAL;
 top_env->cp       =NULL;
 top_env->e        =NULL;
 top_env->b        =NULL;
 top_env->indice_nb=0;

 invoc_nb=1;

 debug_mode   =atom_nodebug;
 leap_mode    =FALSE;
 skip_invoc_nb=0;
 exact_trace  =FALSE;
 wam_curr_inst=0;
 wam_next_inst=0;
 depth        =10;
 leash_option =CALL|EXIT|FAIL|REDO;
 redo         =FALSE;
 catch_fail   =FALSE;
}




/*-------------------------------------------------------------------------*/
/* DEBUG_SET_MODE                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Debug_Set_Mode(AtomInf *mode)

{
 if (mode!=atom_debug && mode!=atom_trace && mode!=atom_nodebug)
     return FALSE;


 top_stack=top_env=debug_stack;

 leap_mode=(mode==atom_debug);                   /* always to reinitialize */
 skip_invoc_nb=0;
 invoc_nb     =1;
 wam_curr_inst=0;
 wam_next_inst=0;
 redo         =FALSE;
 catch_fail   =FALSE;

 if (mode!=debug_mode)
    {
     debug_mode=mode;
     Debug_Display_Mode();
    }

 return TRUE;
}




/*-------------------------------------------------------------------------*/
/* DEBUG_GET_MODE                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
AtomInf *Debug_Get_Mode(void)

{
 return debug_mode;
}




/*-------------------------------------------------------------------------*/
/* DEBUG_CLAUSE                                                            */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Debug_Clause(void)

{
 if (debug_mode==atom_nodebug)
     return;

 if (redo && exact_trace)
     Redo_Port();
}




/*-------------------------------------------------------------------------*/
/* DEBUG_BODY                                                              */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Debug_Body(void)

{
 if (debug_mode==atom_nodebug)
     return;

 catch_fail=TRUE;

 if (redo && !exact_trace)
     Redo_Port();
}




/*-------------------------------------------------------------------------*/
/* DEBUG_CALL                                                              */
/*                                                                         */
/* name==NULL if called predicate is dynamic (A(0) contains the pred)      */
/* debug_level: -1 (don't know)   0/1/2 (no/only Prolog/Prolog + WAM insts)*/
/*              (not used if called predicate is dynamic)                  */
/*-------------------------------------------------------------------------*/
void Debug_Call(char *name,int arity,int debug_level)

{
 AtomInf *atom;
 PredInf *pred;


 if (debug_mode==atom_nodebug)
     return;

 if (name==NULL)
    {
     Call_Port(NULL,arity,DYNAMIC);
     return;
    }

 atom=Create_Atom(name);

 if (debug_level== -1)               /* then the pred is static and public */
    {
     pred=Lookup_Pred(atom,arity,0);
     debug_level=module_tbl[pred->owner_mod_nb].debug_level;
    }

 Call_Port(atom,arity,(debug_level) ? DEBUGGED : EXTERNAL);
}




/*-------------------------------------------------------------------------*/
/* DEBUG_PROCEED                                                           */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Debug_Proceed(Bool from_dynamic)

{
 if (debug_mode==atom_nodebug)
     return;

 Exit_Port(from_dynamic);
}




/*-------------------------------------------------------------------------*/
/* DEBUG_FAIL                                                              */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Debug_Fail(void)

{
 if (debug_mode==atom_nodebug)
     return;

 if (exact_trace || catch_fail || top_env->b>=B)
     Fail_Port();
}




/*-------------------------------------------------------------------------*/
/* DEBUG_DYNAMIC_BODY                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Debug_Dynamic_Body(void)

{
 int     dyn_invoc_nb;
 RunInf *top_bkt;


 if (debug_mode==atom_nodebug)
     return;

 dyn_invoc_nb=Y_Storing_Invoc_Nb(E);

 if (top_env->invoc_nb==dyn_invoc_nb && top_env->x.first_clause)
    {                                                        /* first time */
     top_env->x.first_clause=FALSE;
     return;
    }

 top_bkt=top_stack;

 while(top_bkt->invoc_nb!=dyn_invoc_nb)
     top_bkt=top_bkt->last_env;


 while(top_env>debug_stack && top_env>top_bkt)
    {
     Read_Command(FAIL,TRUE);
     top_env=top_env->caller_env;
    }

 top_env=top_bkt;

 invoc_nb=top_env->invoc_nb+1;

 Read_Command(REDO,TRUE);
}





/*-------------------------------------------------------------------------*/
/* DEBUG_HAS_FAILED_REDO                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Debug_Has_Failed_Redo(void)

{                                                        /* used by call/1 */
 RunInf *top_bkt;

 if (debug_mode==atom_nodebug)
     return;

 top_bkt=Find_Non_Determin_Env(top_stack,B+1);  /* choice point deleted */

 if (top_bkt==debug_stack)
     top_bkt=top_env;

 if (top_bkt==debug_stack)
    {
     Lib1(printf,"Not enough debug information at Fail Port\n");
     return;
    }

 while(top_env>debug_stack && top_env>=top_bkt)
    {
     Read_Command(FAIL,TRUE);
     top_env=top_env->caller_env;
    }

 top_env=top_bkt;

 invoc_nb=top_env->invoc_nb+1;

 redo=FALSE;
 Read_Command(REDO,TRUE);
}




            /* synchronize with non debugged pred (after call/return/fail) */

/*-------------------------------------------------------------------------*/
/* DEBUG_PRED                                                              */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Debug_Pred(char *name,int arity)

{
 AtomInf *atom;

 if (debug_mode==atom_nodebug)
     return;

 if (top_env->type!=DEBUGGED)
    {
     atom=Create_Atom(name);
     Call_Port(atom,arity,DEBUGGED);
    }
}




/*-------------------------------------------------------------------------*/
/* DEBUG_SUB_PRED                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Debug_Sub_Pred(char *name,int arity)

{
 RunInf *top;

 if (debug_mode==atom_nodebug)
     return;

 top=top_stack;

 while(top>debug_stack && (top->cp!=CP || top->e!=E))
     top=top->last_env;

 if (top==debug_stack || top<top_env)
    {
     Lib1(printf,"Not enough debug information (Redo) Exit Port\n");
     return;
    }

 if (top->type==DEBUGGED)
     return;

 if (top>top_env)
    {                                              /* fail/redo in outside */
     top_env=top;
     invoc_nb=top_env->invoc_nb+1;
     Read_Command(REDO,FALSE);
    }
                                                   /* proceed from outside */

 Exit_Port(FALSE);
}




/*-------------------------------------------------------------------------*/
/* DEBUG_RETRY                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Debug_Retry(void)

{
 if (debug_mode==atom_nodebug)
     return;

 if (top_env->type!=DEBUGGED)                         /* fail from outside */
     Fail_Port();
}




/*-------------------------------------------------------------------------*/
/* DEBUG_WAM_INST                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Debug_Wam_Inst(char *format,...)

{
 va_list arg_ptr;

 if (++wam_curr_inst!=wam_next_inst)
     return;

 va_start(arg_ptr,format);
 Lib3(vsprintf,str_next_inst,format,arg_ptr);
 va_end(arg_ptr);

 Read_Command(WAMI,TRUE);
}




/*-------------------------------------------------------------------------*/
/* FIND_NON_DETERMIN_ENV                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static RunInf *Find_Non_Determin_Env(RunInf *top,WamWord *b)

{
 while(top->b >= b)
     top=top->last_env;

 return top;
}




/*-------------------------------------------------------------------------*/
/* CALL_PORT                                                               */
/*                                                                         */
/* if type==DYNAMIC A(0) contains the called predicate                     */
/*-------------------------------------------------------------------------*/
static void Call_Port(AtomInf *atom,int arity,PDbgTyp type)

{
 RunInf  *top,*cur_top;
 WamWord *adr;
 int      indice_nb;
 char    *p=NULL;
 int      i;

 while(top_env>debug_stack && top_env->type==EXTERNAL)
    {                             /* the caller cannot be EXTERNAL         */
     Read_Command(EXIT,TRUE);     /* so they have suceeded (dynamic calls) */
     top_env=top_env->caller_env;
    }

 indice_nb=top_env->indice_nb+1;

 top_stack=Find_Non_Determin_Env(top_stack,B);

 cur_top=math_max(top_stack,top_env);

 top=(RunInf *) ((WamWord *) (cur_top+1)+cur_top->arity);

 if (top>=end_debug_stack)
     Fatal_Error(ERR_DEBUG_STACK_OVERFLOW);

 if (type==DYNAMIC)
     atom=Get_Functor_Arity(A(0),&arity,&adr);                /* init atom */
  else
     p=(char *) Lib2(strchr,atom->name,'$');

 top->last_env  =cur_top;
 top->caller_env=top_env;
 top->atom      =atom;
 top->arity     =arity;
 top->type      =type;
 top->aux_pred  =(p!=NULL && Lib3(strncmp,p,"$aux",4)==0 && type!=DYNAMIC);
 top->cp        =CP;
 top->e         =E;
 top->b         =B;
 top->invoc_nb  =invoc_nb++;
 top->indice_nb =indice_nb;

 if (type!=DYNAMIC)
    {
     if (top->arity>0)
        {
         top->x.f_n=Functor_Arity(top->atom,top->arity);
         top->word=Tag_Value(STC,&(top->x.f_n));
    
         adr=(WamWord *) (top+1);
    
         for(i=0;i<top->arity;i++)
             *adr++ = X(i);
        }
      else
         top->word=Tag_Value(CST,top->atom);
    }
  else
    {
     Y_Storing_Invoc_Nb(E)=top->invoc_nb;             /* see call.{pl,usr} */
     top->word=A(0);
     top->x.first_clause=TRUE;
    }

 top_stack=top_env=top;

 catch_fail=FALSE;
 redo=FALSE;

 Read_Command(CALL,TRUE);
}




/*-------------------------------------------------------------------------*/
/* EXIT_PORT                                                               */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static void Exit_Port(Bool from_dynamic)

{
 Bool last;
 int  dyn_invoc_nb;

 redo=FALSE;

 if (!from_dynamic)
     while(top_env>debug_stack && top_env->cp==CP && top_env->e==E)
        {
         Read_Command(EXIT,TRUE);
         top_env=top_env->caller_env;
        }
  else
    {
     dyn_invoc_nb=Y_Storing_Invoc_Nb(E);

     do
        {
         Read_Command(EXIT,TRUE);
         last=(top_env->invoc_nb==dyn_invoc_nb);

         top_env=top_env->caller_env;
        }
     while(!last);
    }
}




/*-------------------------------------------------------------------------*/
/* FAIL_PORT                                                               */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static void Fail_Port(void)

{
 RunInf *top_bkt;

 top_bkt=Find_Non_Determin_Env(top_stack,B);

 if (top_bkt==debug_stack)
     top_bkt=top_env;

 if (top_bkt==debug_stack)
    {
     Lib1(printf,"Not enough debug information at Fail Port\n");
     return;
    }

 redo=TRUE;

 while(top_env>debug_stack && top_env>=top_bkt)
    {
     Read_Command(FAIL,TRUE);
     top_env=top_env->caller_env;
    }

 top_env=top_bkt;

 invoc_nb=top_env->invoc_nb+1;
}




/*-------------------------------------------------------------------------*/
/* REDO_PORT                                                               */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static void Redo_Port(void)

{
 redo=FALSE;
 Read_Command(REDO,TRUE);
}




/*-------------------------------------------------------------------------*/
/* READ_COMMAND                                                            */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static void Read_Command(int port,Bool read_cmd)

{
 FctPtr command;
 char   c_spy;
 Bool   disp_full_term;
 char  *port_name;
 char   str[80];
 int    key;

 if (debug_mode==atom_nodebug || wam_curr_inst<wam_next_inst)
     return;

 key=Functor_Arity(top_env->atom,top_env->arity);
 c_spy=(Hash_Fast_Find_Int(spy_tbl,key)) ? '+' : ' ';

 if (leap_mode && c_spy==' ')
     return;

 if (skip_invoc_nb>0)                                              /* skip */
    {
     if (top_env->invoc_nb!=skip_invoc_nb)
         return;

     if (port!=EXIT && (port!=FAIL || B>top_env->b))
         return;
    }

 if (!exact_trace && top_env->aux_pred)
     return;

 if (read_cmd && port!=WAMI && 
     !(leash_option & port) && !leap_mode && skip_invoc_nb==0)
     read_cmd=FALSE;

 leap_mode    =FALSE;
 skip_invoc_nb=0;
 wam_next_inst=0;

 switch(port)
    {
     case CALL:
         port_name="Call";
         disp_full_term=TRUE;
         break;

     case EXIT:
         port_name="Exit";
         disp_full_term=TRUE;
         break;

     case FAIL:
         port_name="Fail";
/*         disp_full_term=TRUE; */
         disp_full_term=(top_env->type!=DYNAMIC);
         break;

     case REDO:
         port_name="Redo";
         disp_full_term=(exact_trace && top_env->type!=EXTERNAL);
         break;
    }


 if (port!=WAMI)
    {
     Lib5(printf," %c %4d %4d %s: ",c_spy,top_env->invoc_nb,
          top_env->indice_nb,port_name);

     if (top_env->type==EXTERNAL)
         Lib1(printf,"(external) ");

     if (disp_full_term)
         Complex_Write_Term(stdout,depth,FALSE,TRUE,TRUE,top_env->word);
      else
         Lib3(printf,"%s/%d",top_env->atom->name,top_env->arity);
    }
  else
     Lib3(printf,"Wam Inst. (%5d) : %s",wam_curr_inst,str_next_inst);

 if (!read_cmd)
    {
     Lib1(printf,"\n");
     return;
    }


 Lib1(printf," ? ");

 *str='\0';
 Lib1(gets,str);
 if (*str=='\0')
     Lib2(strcpy,str,"creep");

 Scan_Command(str);

 if ((command=Find_Function())==NULL || !(*command)(port))
     Read_Command(port,TRUE);
}




/*-------------------------------------------------------------------------*/
/* SCAN_COMMAND                                                            */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static void Scan_Command(char *source_str)

{
 char  str[80];
 char *p,*q;

 Lib2(strcpy,str,source_str);
 nb_read_arg=0;
 p=(char *) Lib2(strtok,str,SEPARATOR_LIST);

 while(p)
    {
     q=p;
     p=(char *) Lib2(strtok,NULL,SEPARATOR_LIST);
     Lib2(strcpy,read_arg[nb_read_arg++],q);
    }
}




/*-------------------------------------------------------------------------*/
/* FIND_FUNCTION                                                           */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static FctPtr Find_Function(void)

{
 int    lg;
 int    i;
 static
 InfCmd cmd[]= { { "creep",       Creep              },
                 { "skip",        Skip               },
                 { "leap",        Leap               },
                 { "abort",       Abort              },
                 { "goalsb",      Goals_GoalsB       },
                 { "gb",          Goals_GoalsB       },
                 { "leash",       Leash              },
                 { "nodebug",     NoDebug            },
                 { "notrace",     NoDebug            },
                 { "=",           Debugging          },
                 { "+",           Spy_NoSpy_NoSpyAll },
                 { "-",           Spy_NoSpy_NoSpyAll },
                 { "@",           Exec_Prolog_Goal   },
                 { "<",           Depth              },
                 { "exact",       Exact_NoExact      },
                 { "noexact",     Exact_NoExact      },

                 { "write",       Write_Data_Modify  },
                 { "data",        Write_Data_Modify  },
                 { "modify",      Write_Data_Modify  },
                 { "where",       Where              },
                 { "deref",       Dereference        },
                 { "envir",       Environment        },
                 { "backtrack",   Backtrack          },
                 { "instruction", Instruction        },

                 { "help",        Help               }
               };

 if (nb_read_arg==0)
     return NULL;

 lg=Lib1(strlen,read_arg[0]);

 for(i=0;i<sizeof(cmd)/sizeof(InfCmd);i++)
     if (Lib3(strncmp,cmd[i].name,read_arg[0],lg)==0)
         return cmd[i].fct;

 Lib1(printf,"Unknown command - try help\n");

 return NULL;
}




/*-------------------------------------------------------------------------*/
/* CREEP                                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool Creep(void)

{
 return TRUE;
}




/*-------------------------------------------------------------------------*/
/* SKIP                                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool Skip(int port)

{
 RunInf *top=top_env;
 int     invoc;

 invoc=(nb_read_arg==1) ? top->invoc_nb : Lib1(atoi,read_arg[1]);

 if (invoc==top->invoc_nb && (port==EXIT || port==FAIL) && 
     invoc==top->invoc_nb)
    {
     Lib1(printf,"Option not applicable at this port\n");
     return FALSE;
    }

 if (invoc<top->invoc_nb)
    {
     while(top>debug_stack && top->invoc_nb>invoc)
         top=top->caller_env;

     if (top->invoc_nb!=invoc)
        {
         Lib1(printf,"Incorrect invocation number (try goals)\n");
         return FALSE;
        }

     Lib1(printf,"Skip backward\n");
    }
  else
     if (invoc>top->invoc_nb)
         Lib1(printf,"Skip forward\n");


 skip_invoc_nb=invoc;

 return TRUE;
}




/*-------------------------------------------------------------------------*/
/* LEAP                                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool Leap(void)

{
 leap_mode=TRUE;
 return TRUE;
}





/*-------------------------------------------------------------------------*/
/* ABORT                                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool Abort(void)

{
 Prototype(Prefix(Pred_Name(ABORT,0)))

 Execute_A_Continuation((CodePtr) Prefix(Pred_Name(ABORT,0)));
}




/*-------------------------------------------------------------------------*/
/* GOALS_GOALSB                                                            */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool Goals_GoalsB(void)

{
 int nb= -1;

 if (nb_read_arg>1)
     nb=Lib1(atoi,read_arg[1]);

 Lib1(printf,"Ancestors:\n");

 if (Lib2(strchr,read_arg[0],'b')==NULL)
     One_Goal(nb,NULL,top_env,NULL);
  else
     One_Goal(nb,Find_Non_Determin_Env(top_stack,B),top_env,B);

 Lib1(printf,"\n");

 return FALSE;
}




/*-------------------------------------------------------------------------*/
/* ONE_GOAL                                                                */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static void One_Goal(int nb,RunInf *top_bkt_e,RunInf *top_caller_e,
                     WamWord *b)

{
 RunInf *top;
 int     nb_chc_pnt=0;
 Bool    disp_env;

 top=math_max(top_bkt_e,top_caller_e);

 if (top==debug_stack || nb==0)
     return;

 while(b>top->b)
    {
     b=(WamWord *) BB(b);
     nb_chc_pnt++;
    }

 if (top==top_bkt_e)
     top_bkt_e=Find_Non_Determin_Env(top_bkt_e,b);

 if (top==top_caller_e)
    {
     disp_env=TRUE;
     top_caller_e=top->caller_env;
    }
  else
     disp_env=FALSE;

 One_Goal(--nb,top_bkt_e,top_caller_e,b);


 if (!exact_trace && top->aux_pred)
     return;

 if (nb_chc_pnt==0)
     Lib1(printf,"   ");
  else
     Lib2(printf,"%2d ",nb_chc_pnt);

 Lib3(printf,"%4d %4d ",top->invoc_nb,top->indice_nb);

 if (disp_env)
     Complex_Write_Term(stdout,depth,FALSE,TRUE,TRUE,top->word);
  else
     Lib3(printf,"   %s/%d",top->atom->name,top->arity);

 Lib1(printf,"\n");
}




/*-------------------------------------------------------------------------*/
/* LEASH                                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool Leash(void)

{
 int i;

 Debug_Add_Leash_Mode(NULL);

 for(i=1;i<nb_read_arg;i++)
     switch(*read_arg[i])
        {
         case 'c':
             Debug_Add_Leash_Mode(atom_call);
             break;

         case 'e':
             Debug_Add_Leash_Mode(atom_exit);
             break;

         case 'f':
             Debug_Add_Leash_Mode(atom_fail);
             break;

         case 'r':
             Debug_Add_Leash_Mode(atom_redo);
             break;
        }

 Debug_Display_Leashing();

 return FALSE;
}




/*-------------------------------------------------------------------------*/
/* DEBUG_ADD_LEASH_MODE                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Debug_Add_Leash_Mode(AtomInf *leash_mode)

{
 if (leash_mode==NULL)
    {
     leash_option=0;
     return TRUE;
    }

 if (leash_mode==atom_call)
    {
     leash_option|=CALL;
     return TRUE;
    }

 if (leash_mode==atom_exit)
    {
     leash_option|=EXIT;
     return TRUE;
    }

 if (leash_mode==atom_fail)
    {
     leash_option|=FAIL;
     return TRUE;
    }

 if (leash_mode==atom_redo)
    {
     leash_option|=REDO;
     return TRUE;
    }

 return FALSE;
}






/*-------------------------------------------------------------------------*/
/* NODEBUG                                                                 */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool NoDebug(void)

{
 Debug_Set_Mode(atom_nodebug);

 return TRUE;
}




/*-------------------------------------------------------------------------*/
/* DEBUGGING                                                               */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool Debugging(void)

{
 Debug_Display_Infos();

 return FALSE;
}




/*-------------------------------------------------------------------------*/
/* DEBUG_DISPLAY_INFOS                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Debug_Display_Infos(void)

{
 WamWord *pkey;
 int      nb_spy=0;
 AtomInf *atom;
 int      arity;

 Debug_Display_Mode();
 Debug_Display_Leashing();
 Debug_Display_Exact();
 pkey=(WamWord *) Hash_Lookup(spy_tbl,NULL,H_NEXT);
 while(pkey)
    {
     if (nb_spy++ == 0)
         Lib1(printf,"Spypoints:\n");

     atom=Functor_Of(*pkey);
     arity=Arity_Of(*pkey);

     Lib3(printf,"   %s/%d\n",atom->name,arity);

     pkey=(int *) Hash_Lookup(spy_tbl,(char *) pkey,H_NEXT);
    }

 if (nb_spy==0)
     Lib1(printf,"There are no spypoints\n");

 Lib1(printf,"\n");
}




/*-------------------------------------------------------------------------*/
/* DEBUG_DISPLAY_MODE                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Debug_Display_Mode(void)

{
 char *s;

 if (debug_mode==atom_debug)
     s="The debugger will first leap -- showing spypoints (debug)\n";

 if (debug_mode==atom_trace)
     s="The debugger will first creep -- showing everything (trace)\n";

 if (debug_mode==atom_nodebug)
     s="The debugger is switched off\n";

 Lib1(printf,s);
}




/*-------------------------------------------------------------------------*/
/* DEBUG_DISPLAY_LEASHING                                                  */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Debug_Display_Leashing(void)

{
 Bool first=TRUE;

 if (leash_option==0)
     Lib1(printf,"No leashing\n");
  else
    {
     Lib1(printf,"Using leashing stopping at ");

     first=TRUE;

     if (leash_option & CALL)
         Lib2(printf,"%ccall",first ? '[' : ','), first=FALSE;

     if (leash_option & EXIT)
         Lib2(printf,"%cexit",first ? '[' : ','), first=FALSE;

     if (leash_option & FAIL)
         Lib2(printf,"%cfail",first ? '[' : ','), first=FALSE;

     if (leash_option & REDO)
         Lib2(printf,"%credo",first ? '[' : ','), first=FALSE;
     Lib1(printf,"] ports\n");
    }
}





/*-------------------------------------------------------------------------*/
/* DEBUG_DISPLAY_EXACT                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Debug_Display_Exact(void)

{
 if (exact_trace)
     Lib1(printf,"trace: exact (showing all visible failures)\n");
  else
     Lib1(printf,"trace: noexact (not showing failures when unifying heads)\n");
}




/*-------------------------------------------------------------------------*/
/* SPY_NOSPY_NOSPYALL                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool Spy_NoSpy_NoSpyAll(void)

{
 AtomInf *atom;
 int      arity;
 char    *p;
 int      i;
 void    (*f)();

 if (nb_read_arg==2 && Lib2(strcmp,read_arg[1],"all")==0)
     Debug_Remove_Spy_Point(NULL,0);
  else
    {
     f=(*read_arg[0]=='+' ) ? Debug_Add_Spy_Point : Debug_Remove_Spy_Point;
    
     if (nb_read_arg==1)
         (*f)(top_env->atom,top_env->arity);
      else
         for(i=1;i<nb_read_arg;i++)
            {
             p=(char *) Lib2(strchr,read_arg[i],'/');
             if (!p)
                 Lib2(printf,"arity missing for %s\n",read_arg[i]);
              else
                {
                 *p='\0';
                 arity=Lib1(atoi,p+1);
                 atom=Create_Allocate_Atom(read_arg[i]);
                 (*f)(atom,arity);
                }
            }
    }

 return FALSE;
}




/*-------------------------------------------------------------------------*/
/* DEBUG_ADD_SPY_POINT                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Debug_Add_Spy_Point(AtomInf *atom,int arity)

{
 int   key=Functor_Arity(atom,arity);
 char *s;

 if (Hash_Lookup(spy_tbl,(char *) &key,H_CREATE))
     s="Spypoint placed on %s/%d\n";
  else
     s="There already is a spypoint on %s/%d\n";

 Lib3(printf,s,atom->name,arity);
}




/*-------------------------------------------------------------------------*/
/* DEBUG_REMOVE_SPY_POINT                                                  */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Debug_Remove_Spy_Point(AtomInf *atom,int arity)


{
 int   key=Functor_Arity(atom,arity);
 char *s;

 if (atom==NULL)                     /* for builtin nospyall/0 in trace.pl */
    {
     Hash_Delete_All(spy_tbl);
     Lib1(printf,"All spypoints removed\n");
     return;
    }

 if (Hash_Lookup(spy_tbl,(char *) &key,H_DELETE))
     s="Spypoint removed from %s/%d\n";
  else
     s="There is no spypoint on %s/%d\n";

 Lib3(printf,s,atom->name,arity);
}




/*-------------------------------------------------------------------------*/
/* EXEC_PROLOG_GOAL                                                        */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool Exec_Prolog_Goal(void)

{
 Prototype(Prefix(Pred_Name(DBG_EXEC,0)))
 AtomInf *save_debug_mode=debug_mode;
 WamWord *save_reg_bank=reg_bank;
 WamWord  local_reg_bank[REG_BANK_SIZE];

 Switch_Reg_Bank(local_reg_bank);

 debug_mode=atom_nodebug;

 Call_Prolog((CodePtr) Prefix(Pred_Name(DBG_EXEC,0)));

 debug_mode=save_debug_mode;

 Switch_Reg_Bank(save_reg_bank);

 return FALSE;
}




/*-------------------------------------------------------------------------*/
/* DEPTH                                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool Depth(void)

{
 if (nb_read_arg==1)
     depth=10;
  else
     depth=Lib1(atoi,read_arg[1]);

 return FALSE;
}




/*-------------------------------------------------------------------------*/
/* EXACT_NOEXACT                                                           */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool Exact_NoExact(void)

{
 exact_trace= *read_arg[0]=='e';

 Debug_Display_Exact();
 return FALSE;
}




/*-------------------------------------------------------------------------*/
/* WRITE_DATA_MODIFY                                                       */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool Write_Data_Modify(void)

{
 WamWord *adr;
 char    *bank_name;
 int      offset;
 int      nb;
 int      i;

 if (adr=Read_Bank_Adr(FALSE,1,&bank_name))
    {
     offset=(nb_read_arg<3) ? 0 : Read_Integer(2);
     nb    =(nb_read_arg<4) ? 1 : Read_Integer(3);

     if (adr==reg_copy)
        {
         if (offset>=NB_OF_REGS)
             offset=0;

         if (nb_read_arg<4  && *read_arg[0]!='m')
             nb=NB_OF_REGS-offset;
          else
             if (nb>NB_OF_REGS-offset)
                 nb=NB_OF_REGS-offset;
        }

     while(nb--)
        {
         Print_Bank_Name_Offset((adr==reg_copy) ? reg_tbl[offset] : "",
                                bank_name,offset);
         Lib1(printf,":");

         if (*read_arg[0]=='w')
             Complex_Write_Term(stdout,depth,FALSE,TRUE,TRUE,adr[offset]);
          else
            {
             Print_Wam_Word(adr+offset);
             if (*read_arg[0]=='m')
                 Modify_Wam_Word(adr+offset);
            }

         Lib1(printf,"\n");
         offset++;
        }
    }


 if (adr==reg_copy)                              /* saved by Read_Bank_Adr */
     for(i=0;i<NB_OF_REGS;i++)
         Reg(i)=reg_copy[i];

 return FALSE;
}




/*-------------------------------------------------------------------------*/
/* WHERE                                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool Where(void)

{
 char    *stack_name;
 int      offset;
 WamWord  word,tag,*adr;

 if (adr=Read_Bank_Adr(TRUE,1,&stack_name))
    {
     offset=(nb_read_arg<3) ? 0 : Read_Integer(2);

     Print_Bank_Name_Offset((adr==reg_copy) ? reg_tbl[offset] : "",
                            stack_name,offset);
     Lib2(printf," at %#x\n",adr+offset);
    }

 return FALSE;
}




/*-------------------------------------------------------------------------*/
/* DEREFERENCE                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool Dereference(void)

{
 char    *bank_name;
 char    *stack_name;
 int      offset;
 WamWord  word,tag,*adr;
 WamWord *d_adr;

 if (adr=Read_Bank_Adr(FALSE,1,&bank_name))
    {
     offset=(nb_read_arg<3) ? 0 : Read_Integer(2);

     Deref(adr[offset],word,tag,d_adr);

     Print_Bank_Name_Offset((adr==reg_copy) ? reg_tbl[offset] : "",
                            bank_name,offset);
     Lib1(printf,":");

     if (adr=Detect_Stack(d_adr,&stack_name))
        {
         Lib1(printf," --> \n");
         Print_Bank_Name_Offset("",stack_name,d_adr-adr);
         Lib1(printf,":");
        }

     Print_Wam_Word(d_adr);
     Lib1(printf,"\n");
    }

 return FALSE;
}




/*-------------------------------------------------------------------------*/
/* ENVIRONMENT                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool Environment(void)

{
 WamWord *adr;
 int      offset;
 char    *stack_name;
 int      i;

 if (nb_read_arg==1)
    {
     adr=Detect_Stack(E,&stack_name);
     offset=E-adr;
     adr=E;
    }
  else
    {
     if ((adr=Read_Bank_Adr(TRUE,1,&stack_name))==NULL)
         return FALSE;

     offset=(nb_read_arg<3) ? 0 : Read_Integer(2);
     adr+=offset;
    }

 for(i=ENVIR_STATIC_SIZE;i>0;i--)
    {
     Print_Bank_Name_Offset(envir_name[i-1],stack_name,offset-i);
     Lib1(printf,":");
     Print_Wam_Word(adr-i);
     Lib1(printf,"\n");
    }

 return FALSE;
}



/*-------------------------------------------------------------------------*/
/* BACKTRACK                                                               */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool Backtrack(void)

{
 WamWord *adr;
 int      offset;
 char    *stack_name;
 int      i;

 if (nb_read_arg==1)
    {
     adr=Detect_Stack(B,&stack_name);
     offset=B-adr;
     adr=B;
    }
  else
    {
     if ((adr=Read_Bank_Adr(TRUE,1,&stack_name))==NULL)
         return FALSE;

     offset=(nb_read_arg<3) ? 0 : Read_Integer(2);
     adr+=offset;
    }

 for(i=CHOICE_STATIC_SIZE;i>0;i--)
    {
     Print_Bank_Name_Offset(choice_name[i-1],stack_name,offset-i);
     Lib1(printf,":");
     Print_Wam_Word(adr-i);
     Lib1(printf,"\n");
    }

 return FALSE;
}




/*-------------------------------------------------------------------------*/
/* READ_BANK_ADR                                                           */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static WamWord *Read_Bank_Adr(Bool only_stack,int arg_nb,char **bank_name)

{
 int lg;
 int offset;
 int i;

 if (nb_read_arg<arg_nb+1)
    {
     Lib2(printf,"%s name expected\n",(only_stack) ? "Stack" : "Bank");
     return NULL;
    }

 lg=Lib1(strlen,read_arg[arg_nb]);

 if (!only_stack)
    {
     if (read_arg[arg_nb][0]=='x' && lg==1)
        {
         *bank_name="x";
         return &X(0);
        }
    
     if (read_arg[arg_nb][0]=='y' && lg==1)
        {
         *bank_name="y";
         return &Y(E,0);
        }
    
     if (Lib3(strncmp,"reg",read_arg[arg_nb],lg)==0)
        {
         *bank_name="reg";
         for(i=0;i<NB_OF_REGS;i++)
             reg_copy[i]=Reg(i);
         return reg_copy;
        }
    }


 for(i=0;i<NB_OF_STACKS;i++)
    if (Lib3(strncmp,stk_tbl[i].name,read_arg[arg_nb],lg)==0)
       {
        *bank_name=stk_tbl[i].name;
        return stk_tbl[i].stack;
       }

 Lib2(printf,"Incorrect %s name\n",(only_stack) ? "stack" : "bank");

 return NULL;
}




/*-------------------------------------------------------------------------*/
/* READ_INTEGER                                                            */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static int Read_Integer(int arg_nb)

{
 char *p;
 int   val=0;

 val=Lib3(strtol,read_arg[arg_nb],&p,0);
 if (*p)
     Lib1(printf,"Incorrect integer\n");

 return val;
}




/*-------------------------------------------------------------------------*/
/* PRINT_BANK_NAME_OFFSET                                                  */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static void Print_Bank_Name_Offset(char *prefix,char *bank_name,int offset)

{
 char str[80];
 int  lg=Lib1(strlen,prefix);

 if (lg)
     Lib2(printf,"%s",prefix);

 Lib4(sprintf,str,"%s[%d]",bank_name,offset);
 lg+=Lib1(strlen,str);

 if (lg>BANK_NAME_OFFSET_LENGTH)
     lg=BANK_NAME_OFFSET_LENGTH-1;

 Lib4(printf,"%*s%s",BANK_NAME_OFFSET_LENGTH-lg,"",str);
}




/*-------------------------------------------------------------------------*/
/* PRINT_WAM_WORD                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static void Print_Wam_Word(WamWord *word_adr)

{
 WamWord word= *word_adr;
 WamWord tag;
 WamWord value;
 char    *stack_name;
 WamWord *adr;
 AtomInf *functor;
 int      arity;

 Lib5(printf,"%#*x  %*d  ",HEXADECIMAL_LENGTH,word,DECIMAL_LENGTH,word);

 if (adr=Detect_Stack((WamWord *) word,&stack_name))
     Print_Bank_Name_Offset("",stack_name,(WamWord *) word-adr);
  else
     Lib3(printf,"%*s",BANK_NAME_OFFSET_LENGTH,"?[?]");

 Lib1(printf,"  ");

 tag=Tag_Of(word);
 if (tag<NB_OF_TAGS)
    {
     switch(tag_tbl[tag].type)
        {
         case INTEGER:
             value=(WamWord) UnTag_Integer(word);
             Lib4(printf,"%s,%*d",tag_tbl[tag].name,VALUE_PART_LENGTH,value);
             break;

         case UNSIGNED:
             value=(WamWord) UnTag_Unsigned(word);
             Lib4(printf,"%s,%*u",tag_tbl[tag].name,VALUE_PART_LENGTH,value);
             break;
             
         case STACK:
             value=(WamWord) UnTag_Stack(word);
	     if (adr=Detect_Stack((WamWord *) value,&stack_name))
                {
                 Lib2(printf,"%s,",tag_tbl[tag].name);
                 Print_Bank_Name_Offset("",stack_name,(WamWord *) value-adr);
                }
              else
                 tag= -1;
             break;

         case MALLOC:
             value=(WamWord) UnTag_Malloc(word);
             if (Hash_Is_An_Element(atom_tbl,(char *) value))
                 Lib4(printf,"%s,%*s",tag_tbl[tag].name,
                      VALUE_PART_LENGTH,((AtomInf *)value)->name);
              else
                 Lib4(printf,"%s,%#*x",tag_tbl[tag].name,
                      VALUE_PART_LENGTH,value);
             break;
        }
    }
 else
    tag= -1;

 if (tag== -1)
     Lib3(printf,"???,%*s",VALUE_PART_LENGTH,"?");

 Lib1(printf,"  ");

 if (word_adr>=Trail_Stack && word_adr<Trail_Stack+Trail_Size)
    {
     tag  =Trail_Tag_Of(word);
     value=Trail_Value_Of(word);

     if (tag==TFC)
         Lib4(printf,"%s,%#*x",trail_tag_name[tag],VALUE_PART_LENGTH,value);
      else
         if (tag<NB_OF_TRAIL_TAGS && 
             (adr=Detect_Stack((WamWord *) value,&stack_name))!=NULL &&
             *stack_name!='t')
            {
             Lib2(printf,"%s,",trail_tag_name[tag]);
             Print_Bank_Name_Offset("",stack_name,(WamWord *) value-adr);
            }
          else
             Lib3(printf,"???,%*s",VALUE_PART_LENGTH,"?");

     Lib1(printf,"  ");
    }

 functor=Functor_Of(word);
 arity  =Arity_Of(word);

 if (Hash_Is_An_Element(atom_tbl,(char *) functor) && 
     arity>=0 && arity<=MAX_ARITY)
     Lib3(printf,"%12s/%-3d",functor->name,arity);
}




/*-------------------------------------------------------------------------*/
/* MODIFY_WAM_WORD                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static void Modify_Wam_Word(WamWord *word_adr)

{
 WamWord  word;
 char    *bank_name;
 WamWord *adr;
 int      offset;
 char     str[80];
 char    *comma;
 char    *slash;
 char    *p;
 int      i;

 for(;;)
    {
     Lib1(printf,"\nNew value: ");

     *str='\0';
     Lib1(gets,str);
     if (*str=='\0')
         return;


     Scan_Command(str);

     if (comma=(char *) Lib2(strchr,str,','))
         goto tag_value;

     if (slash=(char *) Lib2(strchr,read_arg[0],'/'))
         goto functor_arity;


integer:
     if (nb_read_arg==1 && *read_arg[0]>='0' && *read_arg[0]<='9')
        {
         word=Lib3(strtol,read_arg[0],&p,0);
         if (*p=='\0')
            {
             *word_adr=word;
             return;
            }
          else
             goto err;
        }


stack_adr:
     if (adr=Read_Bank_Adr(TRUE,0,&bank_name))
        {
         offset=(nb_read_arg<2) ? 0 : Read_Integer(1);
         *word_adr=(WamWord) (adr+offset);
         return;
        }

     goto err;


tag_value:
     comma++;

     for(i=0;i<NB_OF_TAGS;i++)
         if (Lib2(strcmp,tag_tbl[i].name,read_arg[0])==0)
             break;

     if (i<NB_OF_TAGS)
        {
         switch(tag_tbl[i].type)
            {
	     case INTEGER:
             case UNSIGNED:
                 *word_adr=Tag_Value(i,Read_Integer(1));                 
                 return;

             case STACK:
                 if (adr=Read_Bank_Adr(TRUE,1,&bank_name))
                    {
                     offset=(nb_read_arg<3) ? 0 : Read_Integer(2);
                     *word_adr=Tag_Value(i,adr+offset);
                     return;
                    }
                 goto err;

             case MALLOC:
                 word=Lib3(strtol,comma,&p,0);
                 if (*p=='\0')
                    {
                     *word_adr=Tag_Value(i,word);
                     return;
                    }
                  else
                     if (Lib2(strcmp,read_arg[0],"CST")==0)
                        {
                         *word_adr=Tag_Value(i,Create_Allocate_Atom(comma));
                         return;
                        }
                 goto err;
            }
        }


trail_tag_value:
     for(i=0;i<NB_OF_TRAIL_TAGS;i++)
         if (Lib2(strcmp,trail_tag_name[i],read_arg[0])==0)
             if (adr=Read_Bank_Adr(TRUE,1,&bank_name))
                {
                 offset=(nb_read_arg<3) ? 0 : Read_Integer(2);
                 *word_adr=Trail_Tag_Value(i,adr+offset);
                 return;
                }

    goto err;


functor_arity:
     *slash='\0';
     i=Lib3(strtol,slash+1,&p,0);
     if (*p!='\0' || i<1 || i>MAX_ARITY)
         goto err;

     word=Lib3(strtol,read_arg[0],&p,0);
     if (*p!='\0')
         word=(int) Create_Allocate_Atom(read_arg[0]);
      else
         if (!Hash_Is_An_Element(atom_tbl,(char *) word))
             goto err;

     *word_adr=Functor_Arity(word,i);
     Lib3(printf,"--> %s/%d",((AtomInf *) word)->name,i);
     return;


err:
     Lib1(printf,"Error...");
    }
}




/*-------------------------------------------------------------------------*/
/* DETECT_STACK                                                            */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static WamWord *Detect_Stack(WamWord *adr,char **stack_name)

{
 int i;

 for(i=0;i<NB_OF_STACKS;i++)
     if (adr>=stk_tbl[i].stack && adr<stk_tbl[i].stack+stk_tbl[i].size)
        {
         *stack_name=stk_tbl[i].name;
         return stk_tbl[i].stack;
        }

 return NULL;
}





/*-------------------------------------------------------------------------*/
/* INSTRUCTION                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool Instruction(void)

{
 wam_next_inst=(nb_read_arg==1) ? wam_curr_inst+1 : Read_Integer(1);

 return TRUE;
}




/*-------------------------------------------------------------------------*/
/* HELP                                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool Help(void)

{
 int    i;

#define L(str)  Lib2(printf,"%s\n",str);


    L("Prolog level")
    L("")
    L("creep or ENTER   single-step to the very next port")
    L("skip <n>         skip and stop at return of the <n> invocated pred")
    L("leap             resume running (only stopping on spy-points)")
    L("abort            abort the current execution")
    L("goals  <n>       print <n> ancestor goals")
    L("goalsb <n>       print <n> ancestor goals and choice points")
    L("leash  <l>...    set the leashing mode to <l> (call/exit/fail/redo)")
    L("nodebug          switch the debugger off")
    L("notrace          equivalent to nodebug")
    L("=                output information concerning the debugger")
    L("+ <f/n>...       place a spy-point on each <f/n> (or current)")
    L("- <f/n>...       remove  spy-point on each <f/n> (or current)")
    L("@                call arbitrary Prolog goal")
    L("< <n>            set the print depth limit to <n> (or reset)")
    L("exact            trace all failures (and auxiliary predicates)")
    L("noexact          do not trace fail when unifying the head")
    L("")
    L("Wam level")
    L("")
    L("write  adr <n>   write <n> Prolog terms starting at <adr>")
    L("data   adr <n>   display <n> words starting at <adr>")
    L("modify adr <n>   display and modify <n> words starting at <adr>")
    L("where  sadr      display the exact address corresponding to <adr>")
    L("deref  adr       display the dereferenced word started at <adr>")
    L("envir     <sadr> display an environment located at <adr> (or current)")
    L("backtrack <sadr> display a choice point located at <adr> (or current)")
    L("instruction <n>  execute one instruction or until instruction <n>")
    L("")
    L("An address (adr) has the following syntax: bank_name < [n] >")
    L("   bank_name is either reg/x/y/stack_name (see below)")
    L("   n         is an optional offset specifier (integer)")
    L("")
    L("A stack address (sadr) has the following syntax: stack_name < [n] >")


 Lib1(printf,"   stack_name is either");

 for(i=0;i<NB_OF_STACKS;i++)
     Lib2(printf," %s",stk_tbl[i].name);

 Lib1(printf,"\n\n");

 return FALSE;
}
