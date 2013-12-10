/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* C Run-time                                           Daniel Diaz - 1991 */
/*                                                                         */
/* Wam Implementation                                                      */
/*                                                                         */
/* wam_engine.c                                                            */
/*-------------------------------------------------------------------------*/
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>

#define WAM_ENGINE

#include "wam_engine.h"

extern sscanf();




/*---------------------------------*/
/* Constants                       */
/*---------------------------------*/

#define SIGNAL_HANDLER             X7369676E616C5F68616E646C6572

#define ERR_UNKNOWN_STACK          "Error: Unknown stack <%s>"





/*---------------------------------*/
/* Type Definitions                */
/*---------------------------------*/

/*---------------------------------*/
/* Global Variables                */
/*---------------------------------*/

#ifdef WAM_PROFILE

static int max_local_used_size      =0;
static int global_max_used_size     =0;
static int max_trail_used_size      =0;

static int nb_of_create_choice_point=0;
static int nb_of_update_choice_point=0;
static int nb_of_delete_choice_point=0;

#endif




          /* copy term variables */

static WamWord *base_copy;

static WamWord  vars[256];
static WamWord *top_vars;




/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/

static
void      Untrail               (WamWord *low_adr);

static
void      Signal_Handler        (int sig);

static 
void      Copy_Term_Rec         (WamWord *dst_adr,WamWord *src_adr,
                                 WamWord **p);




/*-------------------------------------------------------------------------*/
/* CREATE_CHOICE_POINT                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Create_Choice_Point(CodePtr codep_alt,int arity)

{
 WamWord *adr;
 int      i;

#ifdef WAM_PROFILE

 nb_of_create_choice_point++;

#endif

 adr=B;
 B=Local_Top+CHOICE_STATIC_SIZE+arity;

 ALTB(B)=codep_alt;
 CPB(B) =CP;
 EB(B)  =E;
 BB(B)  =adr;
 BCB(B) =BC;
 HB(B)  =H;
 TRB(B) =TR;

 for(i=0;i<arity;i++)
     AB(B,i)=A(i);
}




/*-------------------------------------------------------------------------*/
/* UPDATE_CHOICE_POINT                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Update_Choice_Point(CodePtr codep_alt,int arity)

{
 int i;

#ifdef WAM_PROFILE

 nb_of_update_choice_point++;

#endif

 ALTB(B)=(WamWord) codep_alt;

 Untrail(TRB(B));

 CP=CPB(B);
 E =EB(B);
 BC=BCB(B);
 H =HB(B);

 for(i=0;i<arity;i++)
     A(i)=AB(B,i);
}




/*-------------------------------------------------------------------------*/
/* DELETE_CHOICE_POINT                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Delete_Choice_Point(int arity)

{
 int i;

#ifdef WAM_PROFILE

 nb_of_delete_choice_point++;

#endif

 Untrail(TRB(B));

 CP=CPB(B);
 E =EB(B);
 BC=BCB(B);
 H =HB(B);

 for(i=0;i<arity;i++)
     A(i)=AB(B,i);

 B=BB(B);                   /* warning B must be the last element restored */
}





/*-------------------------------------------------------------------------*/
/* UNTRAIL                                                                 */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static void Untrail(WamWord *low_adr)

{
 WamWord  word;
 WamWord *adr;
 int      nb;


 while(TR>low_adr)
    {
     word=Trail_Pop;
     adr=(WamWord *) (Trail_Value_Of(word));

     switch(Trail_Tag_Of(word))
        {
         case TUV:
             *adr=Make_Self_Ref(adr);
             break;

         case TOV:
             *adr=Trail_Pop;
             break;

         case TMV:
             nb=Trail_Pop;
             TR-=nb;
             Mem_Word_Cpy(adr,TR,nb)
             break;

         default:                                                   /* TFC */
             (*  ((int (*)()) adr)) ();
        }
    }
}




/*-------------------------------------------------------------------------*/
/* GET_CONSTANT                                                            */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Get_Constant(AtomInf *atom,WamWord start_word)

{
 WamWord word,tag,*adr;

 Deref(start_word,word,tag,adr)
 switch(tag)
    {
     case REF:
         Bind_UV(adr,Tag_Value(CST,atom))
         return TRUE;

     case CST:
         return (UnTag_CST(word)==atom);
    }

 return FALSE;
}




/*-------------------------------------------------------------------------*/
/* GET_INTEGER                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Get_Integer(int n,WamWord start_word)

{
 WamWord word,tag,*adr;

 Deref(start_word,word,tag,adr)
 switch(tag)
    {
     case REF:
         Bind_UV(adr,Tag_Value(INT,n))
         return TRUE;

     case INT:
         return (UnTag_INT(word)==n);
    }

 return FALSE;
}




/*-------------------------------------------------------------------------*/
/* GET_NIL                                                                 */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Get_Nil(WamWord start_word)

{
 WamWord word,tag,*adr;

 Deref(start_word,word,tag,adr)
 if (tag==REF)
    {
     Bind_UV(adr,word_nil)
     return TRUE;
    }

 return (word==word_nil);
}




/*-------------------------------------------------------------------------*/
/* GET_LIST                                                                */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Get_List(WamWord start_word)

{
 WamWord word,tag,*adr;

 Deref(start_word,word,tag,adr)
 switch(tag)
    {
     case REF:
         Bind_UV(adr,Tag_Value(LST,H))
         S=WRITE_MODE; 
         return TRUE;

     case LST:                                   /* init S, i.e. MODE=READ */
         S=(WamWord *) UnTag_LST(word)+OFFSET_CAR;
         return TRUE;	 
    }

 return FALSE;
}




/*-------------------------------------------------------------------------*/
/* GET_STRUCTURE                                                           */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Get_Structure(AtomInf *f,int n,WamWord start_word)

{
 WamWord word,tag,*adr;

 Deref(start_word,word,tag,adr)
 switch(tag)
    {
     case REF:
         Bind_UV(adr,Tag_Value(STC,H))
         Global_Push(Functor_Arity(f,n));
         S=WRITE_MODE;
	 return TRUE;

     case STC:                                   /* init S, i.e. MODE=READ */
         adr=UnTag_STC(word);
         if (Functor_And_Arity(adr)!=Functor_Arity(f,n))
             return FALSE;

         S=adr+OFFSET_ARG;
	 return TRUE;
    }

 return FALSE;
}




/*-------------------------------------------------------------------------*/
/* PUT_X_VARIABLE                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Put_X_Variable(int x,int a)

{
 X(x)=A(a)=Make_Self_Ref(H);
 Global_Push(X(x));
}




/*-------------------------------------------------------------------------*/
/* PUT_Y_VARIABLE                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Put_Y_Variable(int y,int a)

{
 WamWord word,*adr;

 word=Make_Self_Ref(adr=&Y(E,y));
 A(a)= *adr=word;
}




/*-------------------------------------------------------------------------*/
/* PUT_Y_UNSAFE_VALUE                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Put_Y_Unsafe_Value(int y,int a)

{
 WamWord word,tag,*adr;

 Deref(Y(E,y),word,tag,adr)

 if (tag==REF && adr>=(WamWord *) EE(E))
    {
     A(a)=Tag_Value(REF,H);
     Globalize_Local_Unbound_Var(adr)
    }
  else
     A(a)=(Global_UnMove(tag)) ? Tag_Value(REF,adr) : word;
}




/*-------------------------------------------------------------------------*/
/* PUT_CONSTANT                                                            */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Put_Constant(AtomInf *atom,int a)

{
 A(a)=Tag_Value(CST,atom);
}




/*-------------------------------------------------------------------------*/
/* PUT_LIST                                                                */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Put_List(int a)

{
 A(a)=Tag_Value(LST,H);
 S=WRITE_MODE; 
}




/*-------------------------------------------------------------------------*/
/* PUT_STRUCTURE                                                           */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Put_Structure(AtomInf *f,int n,int a)

{
 A(a)=Tag_Value(STC,H);
 Global_Push(Functor_Arity(f,n));
 S=WRITE_MODE;
}




/*-------------------------------------------------------------------------*/
/* UNIFY_VARIABLE                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Unify_Variable(WamWord *start_adr)

{
 WamWord word,tag;

 if (S!=WRITE_MODE)
    {
     tag=Tag_Of(word= *S);
     *start_adr=(Global_UnMove(tag)) ? Tag_Value(REF,S) : word;
     S++;
    }
  else
    {
     *start_adr=word=Make_Self_Ref(H);
     Global_Push(word);
    }
}




/*-------------------------------------------------------------------------*/
/* UNIFY_VALUE                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Unify_Value(WamWord start_word)

{
 if (S!=WRITE_MODE)
    {
     if (!Unify(start_word,*S))
         return FALSE;
     S++;
     return TRUE;
    }

 Global_Push(start_word);
 return TRUE;
}




/*-------------------------------------------------------------------------*/
/* UNIFY_LOCAL_VALUE                                                       */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Unify_Local_Value(WamWord start_word)

{
 WamWord word,tag,*adr;

 if (S!=WRITE_MODE)
     return Unify(start_word,*S++);

 Deref(start_word,word,tag,adr)

 if (tag==REF && Is_A_Local_Adr(adr))
     Globalize_Local_Unbound_Var(adr)
  else
     Global_Push((Global_UnMove(tag)) ? Tag_Value(REF,adr) : word);

 return TRUE;
}




/*-------------------------------------------------------------------------*/
/* UNIFY_VOID                                                              */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Unify_Void(int n)

{
 WamWord *end_adr;

 if (S!=WRITE_MODE)
     S+=n;
  else
     for(end_adr=H+(n);H<end_adr;++H)
         *H=Make_Self_Ref(H);
}




/*-------------------------------------------------------------------------*/
/* UNIFY_CONSTANT                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Unify_Constant(AtomInf *atom)

{
 WamWord word,tag,*adr;

 if (S!=WRITE_MODE)
    {
     Deref(*S,word,tag,adr)
     S++;
     switch(tag)
        {
         case REF:
             Bind_UV(adr,Tag_Value(CST,atom))
	     return TRUE;

         case CST:
	     return (UnTag_CST(word)==atom);
        }

     return FALSE;
    }

 Global_Push(Tag_Value(CST,atom));

 return TRUE;
}




/*-------------------------------------------------------------------------*/
/* UNIFY_INTEGER                                                           */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Unify_Integer(int n)

{
 WamWord word,tag,*adr;

 if (S!=WRITE_MODE)
    {
     Deref(*S,word,tag,adr)
     S++;     
     switch(tag)
        {
         case REF:
             Bind_UV(adr,Tag_Value(INT,n))
             return TRUE;

         case INT:
             return (UnTag_INT(word)==n);
        }

     return FALSE;
    }

 Global_Push(Tag_Value(INT,n));

 return TRUE;
}




/*-------------------------------------------------------------------------*/
/* UNIFY_NIL                                                               */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Unify_Nil(void)

{
 WamWord word,tag,*adr;

 if (S!=WRITE_MODE)
    {
     Deref(*S,word,tag,adr)
     S++;
     if (tag==REF)
        {
         Bind_UV(adr,word_nil)
         return TRUE;
        }
      else
         return (word==word_nil);
    }

 Global_Push(word_nil);

 return TRUE;
}




/*-------------------------------------------------------------------------*/
/* ALLOCATE                                                                */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Allocate(int n)

{
 WamWord *adr;

 adr=E;
 E=Local_Top+ENVIR_STATIC_SIZE+n;
                                                                            \
 CPE(E)=(WamWord) CP;
 EE(E) =(WamWord) adr;
}




/*-------------------------------------------------------------------------*/
/* SET_STACK_DEFAULTS                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Set_Stack_Defaults(char *name,char *env_var_name,int default_size_kb)

{
 int i;

 for(i=0;i<NB_OF_STACKS;i++)
     if (Lib2(strcmp,name,stk_tbl[i].name)==0)
         break;

 if (i==NB_OF_STACKS)
     Fatal_Error(ERR_UNKNOWN_STACK,name);

 stk_tbl[i].env_var_name=env_var_name;
 stk_tbl[i].default_size=KBytes_To_Wam_Words(default_size_kb);
}




/*-------------------------------------------------------------------------*/
/* INIT_WAM_ENGINE                                                         */
/*                                                                         */
/* the top of stack are initialized and space for feint first choice point */
/* must be reserved (see Call_Prolog). It's achieved by set B with a value */
/* greater than E (see Local_Top in wam_engine.h). The first real choice   */
/* point (try / try_me_else) or the first environment (allocate) will not  */
/* use words 0..CHOICE_STATIC_SIZE in local stack. So the space for a feint*/
/* choice point is preserved.                                              */
/*-------------------------------------------------------------------------*/
void Init_Wam_Engine(void)

{
 int   i,x;
 char *p;

 for(i=0;i<NB_OF_STACKS;i++)
    {
     stk_tbl[i].size=stk_tbl[i].default_size;

     if (*stk_tbl[i].env_var_name)
        {
         p=(char *) Lib1(getenv,stk_tbl[i].env_var_name);
         if (p && *p)
            {
             Lib3(sscanf,p,"%d",&x);
             stk_tbl[i].size=KBytes_To_Wam_Words(x);
            }
        }
    }

 M_Allocate_Stacks();

 reg_bank=Global_Stack;        /* allocated X regs +  other non alloc regs */
 Global_Stack+=REG_BANK_SIZE;  /* at the beginning of the heap             */
 Global_Size-=REG_BANK_SIZE;

 Init_Atom_Pred();
 word_nil=Tag_Value(CST,atom_nil);     /* defined as a reg (see archi.def) */

 E=B=BC=Local_Stack;
 H=Global_Stack;
 TR=Trail_Stack;
 CP=NULL;

 Create_Choice_Point(NULL,0);                        /* dummy choice point */
}




/*-------------------------------------------------------------------------*/
/* TERM_WAM_ENGINE                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Term_Wam_Engine(void)

{
#ifdef WAM_PROFILE
 int      used,max_used;
 WamWord *w;
 int      i;

#endif


#ifdef WAM_PROFILE

 Lib1(printf,"\n");
 Lib1(printf,"WAM Profile informations\n\n");
 Lib1(printf,"Stacks:\n");

 for(i=0;i<NB_OF_STACKS;i++)
    {
     used=Stack_Top(i)-stk_tbl[i].stack;

     w=stk_tbl[i].stack+stk_tbl[i].size-1;

     while(w >= stk_tbl[i].stack && (*w==0 || *w==M_MAGIC))
         w--;

     max_used=w-stk_tbl[i].stack+1;

     if (Global_Stack==stk_tbl[i].stack)
        {
         used    +=REG_BANK_SIZE;                   /* see Init_Wam_Engine */
         max_used+=REG_BANK_SIZE;
        }

     used*=sizeof(WamWord);
     max_used*=sizeof(WamWord);

     Lib5(printf,"   %-6s stack:%10d bytes   %10d end use   %10d max use\n",
        stk_tbl[i].name,stk_tbl[i].size*sizeof(WamWord),used,max_used);
    }

 Lib1(printf,"\n");

 Lib1(printf,"\n");
 Lib1(printf,"Choice points:\n");
 Lib2(printf,"   create      :%10d (try)\n",  nb_of_create_choice_point);
 Lib2(printf,"   update      :%10d (retry)\n",nb_of_update_choice_point);
 Lib2(printf,"   delete      :%10d (trust)\n",nb_of_delete_choice_point);

 Lib1(printf,"\n");


#endif

}




/*-------------------------------------------------------------------------*/
/* CAPTURE_SIGNAL                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Capture_Signal(int sig)

{
 Lib2(signal,sig,Signal_Handler);
}




/*-------------------------------------------------------------------------*/
/* SWITCH_REG_BANK                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Switch_Reg_Bank(WamWord *new_reg_bank)

{
 int i;
 WamWord *p1,*p2;

 if (reg_bank!=new_reg_bank)
    {
     p1=reg_bank+NB_OF_X_REGS;
     p2=new_reg_bank+NB_OF_X_REGS;

     for(i=0;i<NB_OF_NOT_ALLOC_REGS;i++)
         *p2++=*p1++;

     reg_bank=new_reg_bank;
    }
}




/*-------------------------------------------------------------------------*/
/* CALL_PROLOG                                                             */
/*                                                                         */
/* Call_Prolog runs the execution of one prolog goal.                      */
/* The current choice point is updated to set ALTB to Call_Prolog_Fail and */
/* CP is set to Call_Prolog_Success. At the end ALTB and CP are restored.  */
/* To ensure that a choice point always exists before invoking Call_Prolog,*/
/* Init_Wam_Engine reserve the space for a feint choice point, i.e ALTB can*/
/* be modified safely.                                                     */
/* The intermediate call to Call_Next1 allocates on the C stack enough     */
/* space for local variables declared in the called (i.e. with goto) fcts  */
/*                                                                         */
/* Call_Prolog returns TRUE if the predicate has succeed, FALSE otherwise. */
/* The called predicate can be non-deterministic.                          */
/*-------------------------------------------------------------------------*/
Bool Call_Prolog(CodePtr codep)

{
 Prototype(Prefix(Call_Prolog_Success))
 Prototype(Prefix(Call_Prolog_Fail))
 Bool     Call_Next();
 WamWord *cur_chc_pt=B;
 WamCont  save_CP   =CP;
 WamCont  save_ALTB =ALTB(cur_chc_pt);
 Bool     ok;

 ALTB(cur_chc_pt)=(WamWord) Prefix(Call_Prolog_Fail); /* modify choice pnt */
 Call_Execute_Prefix
 CP=(WamCont) Prefix(Call_Prolog_Success);

 ok=Call_Next(codep);

 CP=save_CP;                                       /* restore continuation */
 ALTB(cur_chc_pt)=save_ALTB;                       /* restore choice point */

 return ok;
}




          /*------------------------------------------------------------*/
          /* Call_Next: save the context with setjmp. Since Call_Prolog */
          /* can be nexted, I handle a stack of jumpers (i.e. contexts) */
          /* directely in the C stack. The global variables p_jumper is */
          /* the top of the stack and points to the current jumper.     */
          /* Similarly for the stack of machine register save buffers.  */
          /* When a (captured) signal X is received the prolog predicate*/
          /* signal_handler(X) is called (see call.pl)                  */
          /*------------------------------------------------------------*/

Bool Call_Next(CodePtr codep)

{
 Prototype(Prefix(Pred_Name(SIGNAL_HANDLER,1)))
 Prototype(Prefix(Pred_Name(ABORT,0)))
 void     Call_Next1();
 int      jmp_val;
 jmp_buf *old_jumper=p_jumper;
 jmp_buf  new_jumper;
 WamWord *old_buff_save=p_buff_save;
 WamWord  buff_save_machine_regs[NB_OF_USED_MACHINE_REGS];

 p_jumper= &new_jumper;
 p_buff_save=buff_save_machine_regs;

 Save_Machine_Regs(buff_save_machine_regs)

 jmp_val=setjmp(*p_jumper);

 Restore_Machine_Regs(buff_save_machine_regs)

 if (jmp_val==0)                                   /* normal call to codep */
     Call_Next1(codep);

 if (jmp_val<0)                              /* return from signal handler */
    {
     put_integer(-jmp_val,0)
     Call_Next1(Prefix(Pred_Name(SIGNAL_HANDLER,1)));
    }

 if (jmp_val>TRUE+1)              /* return with a continuation in jmp_val */
     Call_Next1((CodePtr) jmp_val);


                                                          /* normal return */
 p_jumper=old_jumper;
 p_buff_save=old_buff_save;

 return jmp_val-1;
}




          /*------------------------------------------------------------*/
          /* Call_Next1: to be sure that $sp at setjmp < $sp at longjmp */
          /* reserve space for local variables of called (gotoed) fct   */
          /*------------------------------------------------------------*/

void Call_Next1(CodePtr codep)

{
 int t[1024];

 Foo(t);
 M_Indirect_Goto(codep)
}




          /*------------------------------------------------------------*/
          /* Foo: to be sure that gcc does not suppress the local array */
          /* t in Call_Next1 (if yes I'll put Foo in another file !)    */
          /*------------------------------------------------------------*/

int Foo(int *t)
{
}



          /*------------------------------------------------------------*/
          /* Call_Prolog_Fail: Prolog continuation after failure.       */
          /* Return in Call_Next with a longjmp (value 1)               */
          /*------------------------------------------------------------*/

Begin_Static_Wam_Code(Call_Prolog_Fail)

 Save_Machine_Regs(p_buff_save)
 longjmp(*p_jumper,FALSE+1);

End_Pred




          /*------------------------------------------------------------*/
          /* Call_Prolog_Success: Prolog continuation after success.    */
          /* Return in Call_Next with a longjmp (value 2)               */
          /*------------------------------------------------------------*/

Begin_Static_Wam_Code(Call_Prolog_Success)

 Save_Machine_Regs(p_buff_save)
 longjmp(*p_jumper,TRUE+1);

End_Pred




          /*------------------------------------------------------------*/
          /* Execute_A_Continuation:                                    */
          /* Similar to a nested Call_Prolog but faster, and if a fail  */
          /* occurs it is normally handled by the prolog engine, i.e.   */
          /* the last choice point is reconsidered.                     */
          /* Return in Call_Next with a longjmp (value = codep)         */
          /*------------------------------------------------------------*/

void Execute_A_Continuation(CodePtr codep)

{
 Save_Machine_Regs(p_buff_save)

 longjmp(*p_jumper,(int) codep);
}




          /*------------------------------------------------------------*/
          /* Signal_Handler: must restore some registers (e.g. on sparc)*/
          /* get them form the last choice point (a fail will occurs)   */
          /* Return in Call_Next with a longjmp (value 256+sig)         */
          /*------------------------------------------------------------*/

static void Signal_Handler(int sig)

{
 reg_bank=Global_Stack-REG_BANK_SIZE;             /* restore reg_bank */
 Update_Choice_Point(ALTB(B),0);                  /* restore WAM Registers */

 Save_Machine_Regs(p_buff_save)

 longjmp(*p_jumper,-sig);
}




/*-------------------------------------------------------------------------*/
/* UNIFY                                                                   */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Unify(WamWord start_u_word,WamWord start_v_word)

{
 WamWord u_word,u_tag,*u_adr;
 WamWord v_word,v_tag,*v_adr;
 int     i;

 Deref(start_u_word,u_word,u_tag,u_adr)
 Deref(start_v_word,v_word,v_tag,v_adr)


 if (u_tag==REF)
    {
     if (v_tag==REF)
        {
         if (u_adr>v_adr)
             Bind_UV(u_adr,Tag_Value(REF,v_adr))
          else
             if (v_adr>u_adr)
                 Bind_UV(v_adr,Tag_Value(REF,u_adr))
        }
      else
         if (Global_UnMove(v_tag))
             Bind_UV(u_adr,Tag_Value(REF,v_adr))
          else
             Bind_UV(u_adr,v_word)

     return TRUE;
    }

 switch(v_tag)
    {
     case REF:
         if (Global_UnMove(u_tag))
             Bind_UV(v_adr,Tag_Value(REF,u_adr))
          else
             Bind_UV(v_adr,u_word)

         return TRUE;


     case INT:
     case CST:
         return (u_word==v_word);                    /* test tag and value */


     case LST:
         if (u_tag!=LST)
             return FALSE;

         u_adr=UnTag_LST(u_word);
         v_adr=UnTag_LST(v_word);

         if (u_adr==v_adr)
             return TRUE;

         return Unify(Car(u_adr),Car(v_adr)) &&
                Unify(Cdr(u_adr),Cdr(v_adr));


     default:                                                /* v_tag==STC */
         if (u_tag!=STC)
             return FALSE;
         
         u_adr=UnTag_STC(u_word);
         v_adr=UnTag_STC(v_word);

         if (u_adr==v_adr)
             return TRUE;

         if (Functor_And_Arity(u_adr) != Functor_And_Arity(v_adr))
             return FALSE;

         i=Arity(u_adr);
         do
            {
             --i;
             if (!Unify(Arg(u_adr,i),Arg(v_adr,i)))
                 return FALSE;
            }
         while(i);

         return TRUE;
    }
}




/*-------------------------------------------------------------------------*/
/* TERM_COMPARE                                                            */
/*                                                                         */
/*-------------------------------------------------------------------------*/
int Term_Compare(WamWord start_u_word,WamWord start_v_word)

{
 WamWord  u_word,u_tag,*u_adr;
 WamWord  v_word,v_tag,*v_adr;
 AtomInf *u_functor;
 int      u_arity;
 WamWord *u_arg_adr;
 AtomInf *v_functor;
 int      v_arity;
 WamWord *v_arg_adr;
 int      i,x;



 Deref(start_u_word,u_word,u_tag,u_adr)
 Deref(start_v_word,v_word,v_tag,v_adr)

 switch(u_tag)
    {
     case REF:
         return (v_tag!=REF) ? -1 : u_adr-v_adr;

     case INT:
         if (v_tag==REF)
             return 1;

         return (v_tag!=INT) ? -1 : u_word-v_word;

     case CST:
         if (v_tag==REF || v_tag==INT)
             return 1;

         return (v_tag!=CST) ? -1 : Lib2(strcmp,UnTag_CST(u_word)->name,
                                                UnTag_CST(v_word)->name);
    }

                                                         /* u_tag==LST/STC */

 if ((v_functor=Get_Compound(v_tag,v_word,&v_arity,&v_arg_adr))==NULL)
     return 1;                                           /* v_tag!=LST/STC */

 u_functor=Get_Compound(u_tag,u_word,&u_arity,&u_arg_adr);

 if (u_arity!=v_arity)
     return u_arity-v_arity;

 if (u_functor!=v_functor)
     return Lib2(strcmp,u_functor->name,v_functor->name);

 for(i=0;i<u_arity;i++)
     if ((x=Term_Compare(*u_arg_adr++,*v_arg_adr++))!=0)
         return x;

 return 0;
}




/*-------------------------------------------------------------------------*/
/* PROPER_LIST_LENGTH                                                      */
/*                                                                         */
/* returns the length of a list ended with [] or -1 if it not a proper list*/
/*-------------------------------------------------------------------------*/
int Proper_List_Length(WamWord start_word)

{
 WamWord word,tag,*adr;
 int n=0;

 for(;;)
    {
     Deref(start_word,word,tag,adr)

     if (word==word_nil)
         return n;

     if (tag!=LST)
         return -1;

     n++;
     adr=UnTag_LST(word);
     start_word=Cdr(adr);
    }
}




/*-------------------------------------------------------------------------*/
/* TERM_SIZE                                                               */
/*                                                                         */
/*-------------------------------------------------------------------------*/
int Term_Size(WamWord start_word)

{
 WamWord  word,tag,*adr;
 int      i;
 int      n;


 Deref(start_word,word,tag,adr)

 switch(tag)
    {
     case REF:
     case INT:
     case CST:
         return 1;

     case LST:
         adr=UnTag_LST(word);
         return 1+Term_Size(Car(adr))+Term_Size(Cdr(adr));

     default:                                                  /* tag==STC */
         adr=UnTag_STC(word);
         n=2;                                         /* tagged word + f_n */

         i=Arity(adr);
         do
            {
             --i;
             n+=Term_Size(Arg(adr,i));
            }
         while(i);
         return n;
    }

}




/*-------------------------------------------------------------------------*/
/* COPY_TERM                                                               */
/*                                                                         */
/* Copies a non contiguous term, the result is a contiguous term.          */
/*-------------------------------------------------------------------------*/
void Copy_Term(WamWord *dst_adr,WamWord *src_adr)

{
 WamWord *qtop,*base;
 WamWord *p;


 base_copy=dst_adr++;

 base=top_vars=vars;

 Copy_Term_Rec(base_copy,src_adr,&dst_adr);


                                       /* restore original self references */
 qtop=top_vars;
 while(qtop!=base)
    {
     p=(WamWord *) (*--qtop);                        /* address to restore */
     *p=*--qtop;                                     /* word    to restore */
    }
}




/*-------------------------------------------------------------------------*/
/* COPY_TERM_REC                                                           */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static void Copy_Term_Rec(WamWord *dst_adr,WamWord *src_adr,WamWord **p)

{
 WamWord  word,tag,*adr;
 WamWord *q;
 int      i;
 int      n;

 Deref(*src_adr,word,tag,adr)

 switch(tag)
    {
     case REF:
         q=*p;
         if (adr<q && adr>=base_copy)                    /* already a copy */
            {
             *dst_adr=word;
             return;
            }

         *top_vars++ = word;                         /* word to restore    */
         *top_vars++ = (WamWord) adr;                /* address to restore */
         *adr=*dst_adr=Tag_Value(REF,dst_adr);       /* bind to a new copy */
         return;

     case INT:
     case CST:
          *dst_adr=word;
          return;


     case LST:
         adr=UnTag_LST(word);
         q=*p;
         *p=&Cdr(q)+1;
         Copy_Term_Rec(&Car(q),&Car(adr),p);
         Copy_Term_Rec(&Cdr(q),&Cdr(adr),p);
         *dst_adr=Tag_Value(LST,q);
         return;

     default:                                                  /* tag==STC */
         adr=UnTag_STC(word);
         q=*p;
         Functor_And_Arity(q)=Functor_And_Arity(adr);

         n=Arity(adr);

         *p=&Arg(q,n-1)+1;
         for(i=0;i<n;i++)
             Copy_Term_Rec(&Arg(q,i),&Arg(adr,i),p);

         *dst_adr=Tag_Value(STC,q);
         return;
    }
}




/*-------------------------------------------------------------------------*/
/* COPY_CONTIGUOUS_TERM                                                    */
/*                                                                         */
/* Copies a contiguous term, the result is a contiguous term.              */
/*-------------------------------------------------------------------------*/
void Copy_Contiguous_Term(WamWord *dst_adr,WamWord *src_adr)

#define Old_Adr_To_New_Adr(adr)  ((dst_adr)+((adr)-(src_adr)))

{
 WamWord  word,*adr;
 WamWord *q;
 int      i;
 int      n;

 word=*src_adr;

 switch(Tag_Of(word))
    {
     case REF:
         adr=UnTag_REF(word);
         q=Old_Adr_To_New_Adr(adr);
         *dst_adr=Tag_Value(REF,q);
         if (adr>src_adr)               /* only useful for Global_UnMove() */
             Copy_Contiguous_Term(q,adr);
         return;

     case INT:
     case CST:
          *dst_adr=word;
          return;


     case LST:
         adr=UnTag_LST(word);
         q=Old_Adr_To_New_Adr(adr);
         Copy_Contiguous_Term(&Car(q),&Car(adr));
         Copy_Contiguous_Term(&Cdr(q),&Cdr(adr));

         *dst_adr=Tag_Value(LST,q);
         return;

     default:                                                  /* tag==STC */
         adr=UnTag_STC(word);
         q=Old_Adr_To_New_Adr(adr);
         Functor_And_Arity(q)=Functor_And_Arity(adr);

         n=Arity(adr);

         for(i=0;i<n;i++)
             Copy_Contiguous_Term(&Arg(q,i),&Arg(adr,i));

         *dst_adr=Tag_Value(STC,q);
         return;
    }
}




/*-------------------------------------------------------------------------*/
/* FATAL_ERROR                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Fatal_Error(char *format,...)

{
 va_list arg_ptr;


 printf("\nFatal Error: ");
 va_start(arg_ptr,format);
 vprintf(format,arg_ptr);
 va_end(arg_ptr);

 printf("\n");
 exit(1);
}
