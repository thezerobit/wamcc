/*-------------------------------------------------------------------------*/
/* Prolog To Wam Compiler                INRIA Rocquencourt - CLoE Project */
/* C Run-time                                           Daniel Diaz - 1994 */
/*                                                                         */
/* Machine Dependent Features                                              */
/*                                                                         */
/* machine.c                                                               */
/*-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/param.h>

#define MACHINE_FILE

#include "wam_engine.h"




/*---------------------------------*/
/* Constants                       */
/*---------------------------------*/

          /* Error Messages */

#define ERR_STACKS_ALLOCATION      "Memory allocation fault"
#define ERR_STACK_OVERFLOW         "%s stack overflow (size: %d Kb, env. variable: %s)"

#define ERR_CANNOT_OPEN_DEV0       "Cannot open /dev/zero : %s"
#define ERR_CANNOT_UNMAP           "unmap failed : %s"
#define ERR_CANNOT_SHMGET          "shmget failed : %s"
#define ERR_CANNOT_SHMAT           "shmat failed : %s"





/*---------------------------------*/
/* Type Definitions                */
/*---------------------------------*/

/*---------------------------------*/
/* Global Variables                */
/*---------------------------------*/

#ifdef M_USE_MAGIC_NB_TO_DETECT_STACK_NAME

static WamWord *check_adr[NB_OF_STACKS+1];

#endif

extern char *sys_errlist[];





/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/

#ifdef M_USE_MAGIC_NB_TO_DETECT_STACK_NAME

static
void      Fill_Magic_Adr_Table  (void);

#endif

static
void      SIGSEGV_Handler       ();

static 
void      Stack_Overflow        (int stk_nb);



#define Round_Up(x,y)           M_Mul(M_Div(((x)+(y)-1),(y)),(y))
#define Round_Down(x,y)         M_Mul(M_Div((x),(y)),(y))






#ifdef M_USE_MALLOC

/*-------------------------------------------------------------------------*/
/* M_ALLOCATE_STACKS                                                       */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void M_Allocate_Stacks(void)

{
 int       len=0;
 WamWord  *addr;
 int       i;

 for(i=0;i<NB_OF_STACKS;i++)
     len+=stk_tbl[i].size;

 addr=(WamWord *) calloc(len,sizeof(WamWord));
 if (addr==NULL)
     Fatal_Error(ERR_STACKS_ALLOCATION);

 for(i=0;i<NB_OF_STACKS;i++)
    {
     stk_tbl[i].stack=addr;
     addr+=stk_tbl[i].size;
    }

#ifdef M_USE_MAGIC_NB_TO_DETECT_STACK_NAME
 Fill_Magic_Adr_Table();
#endif
}

#endif




#ifdef M_USE_MMAP

#include <sys/mman.h>

/*-------------------------------------------------------------------------*/
/* M_ALLOCATE_STACKS                                                       */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void M_Allocate_Stacks(void)

{
 int      fd;
 int      page_size;
 int      len=0;
 WamWord *addr;
 int      i;

 page_size=getpagesize()/sizeof(WamWord);
 fd=open("/dev/zero",0);

 if (fd== -1)
     Fatal_Error(ERR_CANNOT_OPEN_DEV0,sys_errlist[errno]);

 for(i=0;i<NB_OF_STACKS;i++)
    {
     stk_tbl[i].size=Round_Up(stk_tbl[i].size,page_size);
     len+=stk_tbl[i].size+page_size;
    }

 addr=(WamWord *) M_MMAP_HIGH_ADR;
 addr-=len;

 addr=(WamWord *) mmap((caddr_t) addr,len*sizeof(WamWord),
                       PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_FIXED,fd,0);
 if ((int) addr<0)
     Fatal_Error(ERR_STACKS_ALLOCATION);

 for(i=0;i<NB_OF_STACKS;i++)
    {
     stk_tbl[i].stack=addr;
     addr+=stk_tbl[i].size;
     if (munmap((caddr_t) addr,page_size)== -1)
         Fatal_Error(ERR_CANNOT_UNMAP,sys_errlist[errno]);

     addr+=page_size;
    }

#ifdef M_USE_MAGIC_NB_TO_DETECT_STACK_NAME
 Fill_Magic_Adr_Table();
#endif

 signal(SIGSEGV,(void (*)()) SIGSEGV_Handler);
}

#endif




#ifdef M_USE_SHM

#include <sys/ipc.h>
#include <sys/shm.h>

#ifdef M_dec_ultrix
#undef SHMLBA
#define SHMLBA 0x400000
#endif


/*-------------------------------------------------------------------------*/
/* M_ALLOCATE_STACKS                                                       */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void M_Allocate_Stacks(void)

{
 int      page_size;
 int      seg_size;
 int      len=0;
 WamWord *addr;
 int      shmid,shmat_ret;
 int      i;

 page_size=getpagesize()/sizeof(WamWord);
 seg_size =SHMLBA/sizeof(WamWord);

 for(i=0;i<NB_OF_STACKS;i++)
    {
     stk_tbl[i].size=Round_Up(stk_tbl[i].size,page_size);
     len+=Round_Up(stk_tbl[i].size+page_size,seg_size);
    }

 addr=(WamWord *) M_SHM_HIGH_ADR;
 addr=(WamWord *) Round_Down((int) addr, SHMLBA);
 addr-=len;


 for(i=0;i<NB_OF_STACKS;i++)
    {
     shmid=shmget(IPC_PRIVATE,stk_tbl[i].size*sizeof(WamWord),0600);
     if (shmid== -1)
         Fatal_Error(ERR_CANNOT_SHMGET,sys_errlist[errno]);

     stk_tbl[i].stack=addr;
     shmat_ret=(int) shmat(shmid,addr,0);
     shmctl(shmid,IPC_RMID,0);
     if (shmat_ret== -1)
         Fatal_Error(ERR_CANNOT_SHMAT,sys_errlist[errno]);

     addr+=stk_tbl[i].size;
     addr+=page_size;
     addr = (WamWord *) Round_Up((int) addr, SHMLBA);
    }

#ifdef M_USE_MAGIC_NB_TO_DETECT_STACK_NAME
 Fill_Magic_Adr_Table();
#endif

 signal(SIGSEGV,(void (*)())SIGSEGV_Handler);
}

#endif




#ifdef M_USE_MAGIC_NB_TO_DETECT_STACK_NAME

/*-------------------------------------------------------------------------*/
/* FILL_MAGIC_ADR_TABLE                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static void Fill_Magic_Adr_Table(void)

{
 int i;

 for(i=0;i<NB_OF_STACKS;i++)
    {
     check_adr[i]=stk_tbl[i].stack+stk_tbl[i].size-M_SECURITY_MARGIN;
     *check_adr[i]=M_MAGIC;
    }

 check_adr[NB_OF_STACKS]=NULL;
}

#endif




/*-------------------------------------------------------------------------*/
/* SIGSEGV_HANDLER                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
#ifdef M_dec_ultrix

static void SIGSEGV_Handler(int sig,int code,struct sigcontext *scp)

#else

static void SIGSEGV_Handler(int sig,int code,int scp,WamWord *addr)

#endif

{
#ifdef M_USE_MAGIC_NB_TO_DETECT_STACK_NAME

 M_Check_Magic_Words();

#else

#ifdef M_dec_ultrix

 WamWord *addr=(WamWord *) (scp->sc_badvaddr);

#endif

 int i;

#ifdef CDEBUG
 printf("BAD ADDRESS:%x\n",addr);
#endif


 for(i=NB_OF_STACKS;i-- >0;)
    {
#ifdef CDEBUG
     printf("STACK[%d].stack + size: %x\n",
            i,stk_tbl[i].stack+stk_tbl[i].size);
#endif
     if (addr>=stk_tbl[i].stack+stk_tbl[i].size)
         Stack_Overflow(i);
    }
#endif

 Fatal_Error("Segmentation Violation");
}




#ifdef M_USE_MAGIC_NB_TO_DETECT_STACK_NAME

/*-------------------------------------------------------------------------*/
/* M_CHECK_MAGIC_WORDS                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void M_Check_Magic_Words(void)

{
 WamWord **p=(WamWord **) check_adr;

 for(p=(WamWord **) check_adr;*p;p++)
     if (**p != M_MAGIC)
         Stack_Overflow(p-(WamWord **) check_adr);
}

#endif





/*-------------------------------------------------------------------------*/
/* STACK_OVERFLOW                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static void Stack_Overflow(int stk_nb)

{
 InfStack *s=stk_tbl+stk_nb;
 char     *var=(*(s->env_var_name)) ? s->env_var_name : "none";
 int       size=s->size;

 if (s->stack==Global_Stack)
     s->size+=REG_BANK_SIZE;                         /*see Init_Wam_Engine */

 Fatal_Error(ERR_STACK_OVERFLOW,s->name,Wam_Words_To_KBytes(s->size),var);
}



#ifdef M_SAVE_REGS_BEFORE_LIB_C_CALLS

/*-------------------------------------------------------------------------*/
/* LIB_CALL                                                                */
/*                                                                         */
/*-------------------------------------------------------------------------*/
int Lib_Call(int i0,int i1,int i2,int i3,int i4,int i5)

{
 int res;
 WamWord buff_save_machine_regs[NB_OF_USED_MACHINE_REGS];


 Save_Machine_Regs(buff_save_machine_regs)

 buff_save_machine_regs[NB_OF_USED_MACHINE_REGS]=1;  /* I'm in a LibCall */
 res=(* ((int (*)()) i0))(i1,i2,i3,i4,i5);

 Restore_Machine_Regs(buff_save_machine_regs)
 buff_save_machine_regs[NB_OF_USED_MACHINE_REGS]=0;   /* no longer in it */

 return res;
}


#endif
