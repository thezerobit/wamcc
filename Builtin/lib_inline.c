/*-------------------------------------------------------------------------*/
/* Prolog To Wam Compiler                INRIA Rocquencourt - CLoE Project */
/* C Run-time                                           Daniel Diaz - 1994 */
/*                                                                         */
/* Inline builtin library                                                  */
/*                                                                         */
/* lib_inline.c                                                            */
/*-------------------------------------------------------------------------*/
#include <stdlib.h>

#include "wam_engine.h"




/*---------------------------------*/
/* Constants                       */
/*---------------------------------*/

#define ERR_ILLEGAL_ARGUMENT       "\nError: Illegal argument\n"




/*---------------------------------*/
/* Type Definitions                */
/*---------------------------------*/

/*---------------------------------*/
/* Global Variables                */
/*---------------------------------*/

/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/


          /* Type tests */


#define Tag_Is_Var(t)              ((t)==REF)
#define Tag_Is_Nonvar(t)           (!Tag_Is_Var(t))
#define Tag_Is_Atom(t)             ((t)==CST)
#define Tag_Is_Integer(t)          ((t)==INT)
#define Tag_Is_Number(t)           (Tag_Is_Integer(t))
#define Tag_Is_Atomic(t)           (Tag_Is_Atom(t) || Tag_Is_Number(t))
#define Tag_Is_Compound(t)         ((t)==STC || (t)==LST)
#define Tag_Is_Callable(t)         ((t)==CST || (t)==STC || (t)==LST)




#define Type_Test(test,x)                                                   \
    {                                                                       \
     WamWord word,tag,*adr;                                                 \
                                                                            \
     Deref(x,word,tag,adr)                                                  \
     return CPP_CAT(test,(tag));                                            \
    }




/*-------------------------------------------------------------------------*/
/* BLT_1_VAR/...                                                           */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Blt_1_var     (WamWord x) { Type_Test(Tag_Is_Var,x)      }
Bool Blt_1_nonvar  (WamWord x) { Type_Test(Tag_Is_Nonvar,x)   }
Bool Blt_1_atom    (WamWord x) { Type_Test(Tag_Is_Atom,x)     }
Bool Blt_1_integer (WamWord x) { Type_Test(Tag_Is_Integer,x)  }
Bool Blt_1_number  (WamWord x) { Type_Test(Tag_Is_Number,x)   }
Bool Blt_1_atomic  (WamWord x) { Type_Test(Tag_Is_Atomic,x)   }
Bool Blt_1_compound(WamWord x) { Type_Test(Tag_Is_Compound,x) }
Bool Blt_1_callable(WamWord x) { Type_Test(Tag_Is_Callable,x) }




/*-------------------------------------------------------------------------*/
/* BLT_3_ARG                                                               */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Blt_3_arg(WamWord word_indice,WamWord word_term,WamWord sub_term)

{
 WamWord  word,tag,*adr;
 int      arity;
 WamWord *arg1_adr;
 int      no_arg;


 Deref(word_indice,word,tag,adr)

 if (tag!=INT)
    {
     Lib1(printf,ERR_ILLEGAL_ARGUMENT);
     return(FALSE);
    }

 no_arg=UnTag_INT(word)-1;

 Deref(word_term,word,tag,adr)

 if (tag==LST)
    {
     adr=UnTag_LST(word);
     return no_arg==0 && Unify(sub_term,Car(adr)) ||
            no_arg==1 && Unify(sub_term,Cdr(adr));
    }

 if (tag==STC)
    {
     adr=UnTag_STC(word);
     arity=Arity(adr);
     return (unsigned) no_arg<arity && Unify(sub_term,Arg(adr,no_arg));
    }

 Lib1(printf,ERR_ILLEGAL_ARGUMENT);
 return FALSE;
}




/*-------------------------------------------------------------------------*/
/* BLT_3_FUNCTOR                                                           */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Blt_3_functor(WamWord word_term,WamWord word_functor,WamWord word_arity)

{
 WamWord word,tag,*adr;
 WamWord tag_functor;
 int     arity;


 Deref(word_term,word,tag,adr)

 switch(tag)
    {
     case INT:
         return Get_Integer(UnTag_INT(word),word_functor) &&
                Get_Integer(0,word_arity);

     case CST:
         return Get_Constant(UnTag_CST(word),word_functor) &&
                Get_Integer(0,word_arity);

     case LST:
         return Get_Constant(atom_dot,word_functor) &&
                Get_Integer(2,word_arity);

     case STC:
         adr=UnTag_STC(word);
         return Get_Constant(Functor(adr),word_functor) &&
                Get_Integer(Arity(adr),word_arity);
    }


                                                               /* tag==REF */

 Deref(word_functor,word,tag,adr)
 if (tag!=CST && tag!=INT)
    {
     Lib1(printf,ERR_ILLEGAL_ARGUMENT);
     return FALSE;
    }

 tag_functor =tag;
 word_functor=word;

 Deref(word_arity,word,tag,adr)
 arity=UnTag_INT(word);

 if (tag!=INT || (unsigned) arity>MAX_ARITY)
    {
     Lib1(printf,ERR_ILLEGAL_ARGUMENT);
     return FALSE;
    }


 if (tag_functor==CST && UnTag_CST(word_functor)==atom_dot && arity==2)
     return (Get_List(word_term)) ? Unify_Void(2), TRUE : FALSE;


 if (tag_functor==CST && arity>0)
     return (Get_Structure(UnTag_CST(word_functor),arity,word_term)) ?
            Unify_Void(arity), TRUE : FALSE;

 if (arity!=0)
     return FALSE;

 switch(tag_functor)
    {
     case CST:
         return Get_Constant(UnTag_CST(word_functor),word_term);

     case INT:
         return Get_Integer(UnTag_INT(word_functor),word_term);
    }

 return FALSE;
}




/*-------------------------------------------------------------------------*/
/* BLT_2_TERM_UNIV                                                         */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Blt_2_term_univ(WamWord u_word,WamWord v_word)

{
 WamWord  word,tag,*adr;
 WamWord  car_word;
 int      lst_length;
 WamWord *arg1_adr;
 WamWord *u_adr,*lst_adr,*stc_adr;
 WamWord  functor_word,functor_tag;
 AtomInf *functor;
 int      arity;


 Deref(u_word,word,tag,u_adr)

 switch(tag)
    {
     case REF:
         goto list_to_term;

                                         /* from term to list functor+args */
     case INT:
     case CST:
         car_word=word;
         lst_length=1+0;
         break;

     case LST:
         adr=UnTag_LST(word);
         car_word=Tag_Value(CST,atom_dot);
         lst_length=1+2;
         arg1_adr=&Car(adr);
         break;

     case STC:
         adr=UnTag_LST(word);
         car_word=Tag_Value(CST,Functor(adr));
         lst_length=1+Arity(adr);
         arg1_adr=&Arg(adr,0);
         break;
    }


 for(;;)
    {
     if (!Get_List(v_word) || !Unify_Value(car_word))
         return FALSE;

     Unify_Variable(&v_word);

     if (--lst_length==0)
         break;

     car_word=*arg1_adr++;
    }

 return Get_Nil(v_word);


                                         /* from list functor+args to term */

list_to_term:

 Deref(v_word,word,tag,adr)
 if (tag!=LST)
     goto error;

 lst_adr=UnTag_LST(word);
 Deref(Car(lst_adr),functor_word,functor_tag,adr)
 if (functor_tag!=CST && functor_tag!=INT)
     goto error;

 Deref(Cdr(lst_adr),word,tag,adr)

 if (word==word_nil)
    {
     Bind_UV(u_adr,functor_word);
     return TRUE;
    }
  else
     if (functor_tag==INT || tag!=LST)
         goto error;


 functor=UnTag_CST(functor_word);

 stc_adr=H;

 H++;                        /* reserve space for f/n maybe lost if a list */
 arity=0;

 for(;;)
    {
     arity++;
     lst_adr=UnTag_LST(word);
     Deref(Car(lst_adr),word,tag,adr)
     Global_Push(word);

     Deref(Cdr(lst_adr),word,tag,adr)
     if (word==word_nil)
         break;

     if (tag!=LST)
         goto error;
    }

 if (functor==atom_dot && arity==2)                              /* a list */
     u_word=Tag_Value(LST,stc_adr+1);
  else
    {
     *stc_adr=Functor_Arity(functor,arity);
     u_word=Tag_Value(STC,stc_adr);
    }

 Bind_UV(u_adr,u_word);
 return TRUE;

error:

 Lib1(printf,ERR_ILLEGAL_ARGUMENT);
 return FALSE;
}




          /* Term Comparison (see also ../src/builtin.h) */


/*-------------------------------------------------------------------------*/
/* BLT_3_COMPARE                                                           */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Blt_3_compare(WamWord word_cmp,WamWord x,WamWord y)

{
 int c=Term_Compare(x,y);
 AtomInf *atom;

 atom=(c<0) ? atom_inf : (c==0) ? atom_eq : atom_sup;

 return Get_Constant(atom,word_cmp);
}




          /* Mathematics (see also ../src/builtin.h) */


/*-------------------------------------------------------------------------*/
/* LOAD_MATH_EXPRESSION                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Load_Math_Expression(WamWord exp,WamWord *result)

#define Eval_2   Prefix(X6576616C_2)

{
 Prototype(Eval_2)
 WamWord  word,tag,*adr;
 Bool     ret;
 WamWord  a1;
 WamWord *save_reg_bank=reg_bank;
 WamWord  local_reg_bank[REG_BANK_SIZE];

 Switch_Reg_Bank(local_reg_bank);

 A(0)=exp;
 put_x_variable(1,1)
 a1=A(1);
 ret=Call_Prolog((CodePtr) Eval_2);

 Deref(a1,word,tag,adr)

 *result=word;

 Switch_Reg_Bank(save_reg_bank);

 return ret;
}
