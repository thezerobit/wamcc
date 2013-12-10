/*-------------------------------------------------------------------------*/
/* Prolog To Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* C Run-time                                           Daniel Diaz - 1991 */
/*                                                                         */
/* Atoms and Predicates Tables Management                                  */
/*                                                                         */
/* atom_pred.c                                                             */
/*-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ATOM_PRED

#include "wam_engine.h"




/*---------------------------------*/
/* Constants                       */
/*---------------------------------*/

#define BLOCK_SIZE                 32

#define NO_INDEX                   0
#define VAR_INDEX                  1
#define CST_INDEX                  2
#define INT_INDEX                  3
#define LST_INDEX                  4
#define STC_INDEX                  5




/*---------------------------------*/
/* Type Definitions                */
/*---------------------------------*/

/*---------------------------------*/
/* Global Variables                */
/*---------------------------------*/

int char_type[256]= {

/*  nul soh stx etx eot enq ack bel bs  ht  nl  vt  np  cr  so  si  */
    EOF,LA, LA, LA, LA, LA, LA, LA, LA, LA, LA, LA, LA, LA, LA, LA,

/*  dle dc1 dc2 dc3 dc4 nak syn etb can em sub esc  fs  gs  rs  us  */
    LA, LA, LA, LA, LA, LA, LA, LA, LA, LA, LA, LA, LA, LA, LA, LA,

/*  spc !   "   #   $   %   &   '   (   )   *   +   ,   -   .   /   */
    LA, SC, DQ, SY, SY, CM, SY, QT, PC, PC, SY, SY, PC, SY, SY, SY,

/*  0   1   2   3   4   5   6   7   8   9   :   ;   <   =   >   ?   */
    DI, DI, DI, DI, DI, DI, DI, DI, DI, DI, SY, SC, SY, SY, SY, SY,

/*  @   A   B   C   D   E   F   G   H   I   J   K   L   M   N   O   */
    SY, CL, CL, CL, CL, CL, CL, CL, CL, CL, CL, CL, CL, CL, CL, CL,

/*  P   Q   R   S   T   U   V   W   X   Y   Z   [   \   ]   ^   _   */
    CL, CL, CL, CL, CL, CL, CL, CL, CL, CL, CL, PC, SY, PC, SY, UL,

/*  `   a   b   c   d   e   f   g   h   i   j   k   l   m   n   o    */
    BQ, SL, SL, SL, SL, SL, SL, SL, SL, SL, SL, SL, SL, SL, SL, SL,

/*  p   q   r   s   t   u   v   w   x   y   z   {   |   }   ~   del  */
    SL, SL, SL, SL, SL, SL, SL, SL, SL, SL, SL, PC, PC, PC, SY, LA 

/*  0x80 ... 0xff = 0 (!=EOF since EOF== -1)  */
    };


          /* dynamic clause management variables */

#ifdef CDEBUG
static PredInf *last_pred;
#endif




/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/

static
Bool      G_Assign_Element     (GVarElt *g_elem,WamWord gval_word,
                                Bool backtrack,Bool copy);

static 
Bool      G_Assign_Array       (GVarElt *g_elem,WamWord *stc_adr,
                                Bool extend,Bool copy);

static 
void      G_Free_Element       (GVarElt *g_elem);

static 
void      G_Copy_Element       (GVarElt *dst_g_elem,GVarElt *src_g_elem);

static 
void      G_Untrail            (void);

static 
WamWord   G_Read_Element       (GVarElt *g_elem,WamWord gval_word);

static
GVarElt  *G_Get_Element        (WamWord gvar_word);



static
void      Extend_HTable         (char **t);

static 
PredInf  *Get_Pred_And_Index    (WamWord start_word,
                                 int *chain_nb,int *key,Bool create);

static 
void      Add_To_List           (int **list,int **to_add,Bool asserta);


#ifdef CDEBUG                                      /* to debug the program */

static
void      Verify_Dynamic_Clauses(void);
static
void      Verify_List           (int *p,int index_nb);
static
void      Verify_Hash           (char *t,int index_nb);

#endif


#define Init_Dynamic_Info(dyn)                                              \
    {                                                                       \
     dyn->seq_chain=dyn->var_ind_chain=dyn->lst_ind_chain=NULL;             \
     dyn->cst_htbl=dyn->int_htbl=dyn->stc_htbl=NULL;                        \
     dyn->count_a= -1;                                                      \
     dyn->count_z=  0;                                                      \
     dyn->consult_count=consult_count;                                      \
    }





/*-------------------------------------------------------------------------*/
/* INIT_ATOM_PRED                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Init_Atom_Pred(void)

{
 atom_tbl=Hash_Table(MAX_ATOM_TBL_SIZE,sizeof(AtomInf),0);
 if (atom_tbl==NULL)
     Fatal_Error(ERR_ALLOC_FAULT);

 atom_nil           =Create_Atom("[]");
 atom_dot           =Create_Atom(".");
 atom_curly_brackets=Create_Atom("{}");
 atom_fail          =Create_Atom("fail");

 atom_g_array       =Create_Atom("g_array");
 atom_g_array_extend=Create_Atom("g_array_extend");

 atom_inf           =Create_Atom("<");
 atom_eq            =Create_Atom("=");
 atom_sup           =Create_Atom(">");

 atom_compiler      =Create_Atom(COMPILER);
 atom_wam_version   =Create_Atom(WAM_VERSION);


 pred_tbl=Hash_Table(MAX_PRED_TBL_SIZE,sizeof(PredInf),sizeof(int));
 if (pred_tbl==NULL)
     Fatal_Error(ERR_ALLOC_FAULT);


 oper_tbl=Hash_Table(MAX_OPER_TBL_SIZE,sizeof(OperInf),sizeof(int));
 if (oper_tbl==NULL)
     Fatal_Error(ERR_ALLOC_FAULT);

 consult_count=0;
}




/*-------------------------------------------------------------------------*/
/* CREATE_ALLOCATE_ATOM                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/
AtomInf *Create_Allocate_Atom(char *name)

{
 char *name1;

 name1=(char *) Lib1(strdup,name);

 return Create_Atom(name1);
}




/*-------------------------------------------------------------------------*/
/* CREATE_ATOM                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/
AtomInf *Create_Atom(char *name)

{
 AtomInf  atom_info;
 AtomInf *atom;
 char    *p;
 int      c_type;
 int      lg;
 Bool     indentifier;
 Bool     symbols;

 if (atom=(AtomInf *) Hash_Lookup(atom_tbl,(char *) (&name),H_FIND))
     return atom;                                        /* already exists */

 atom_info.name       =name;
 atom_info.has_quote  =FALSE;

 indentifier=(*name && char_type[*name]==SL);              /* small letter */
 symbols    =(*name);

 for(lg=0,p=name;*p;p++)
    {
     c_type=char_type[*p];

     if ((c_type & (UL | CL | SL | DI))==0)
         indentifier=FALSE;

     if (c_type!=SY)
         symbols=FALSE;

     if (c_type==QT)
         atom_info.has_quote=TRUE;
    }

 lg=p-name;

 if (indentifier)
    {
     atom_info.type=IDENTIFIER_ATOM;
     atom_info.needs_quote=FALSE;
    }
  else
     if (symbols)
        {
         atom_info.type=SYMBOL_ATOM;
         atom_info.needs_quote=(lg==1 && *name=='.');
        }
      else
         if (lg==1 && char_type[*name]==SC)
            {
             atom_info.type=SOLO_ATOM;
             atom_info.needs_quote=FALSE;
            }
          else
            {
             atom_info.type=OTHER_ATOM;
             atom_info.needs_quote=! (lg==2 && 
                                     (name[0]=='[' &&  name[1]==']' ||
                                      name[0]=='{' &&  name[1]=='}')   );
            }


 atom_info.length=lg;

 atom_info.g_elem.size=0; 
 atom_info.g_elem.val =G_VAR_INITIAL_VALUE;

 atom=(AtomInf *) Hash_Lookup(atom_tbl,(char *) &atom_info,H_UPDATE);
 if ((int) atom == -1)
     Fatal_Error(ERR_ATOM_TBL_FULL);

 return atom;
}




/*-------------------------------------------------------------------------*/
/* LOOKUP_ATOM                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/
AtomInf *Lookup_Atom(char *name)

{
 return (AtomInf *) Hash_Lookup(atom_tbl,(char *) (&name),H_FIND);
}




/*-------------------------------------------------------------------------*/
/* CREATE_PRED_TABLE                                                       */
/*                                                                         */
/*-------------------------------------------------------------------------*/
PredTbl Create_Pred_Table(int size)

{
 PredTbl tbl;

 if (size==0)
     return NULL;

 tbl=Hash_Table(size,sizeof(PredInf),sizeof(int));
 if (tbl==NULL)
     Fatal_Error(ERR_ALLOC_FAULT);

 return tbl;
}




/*-------------------------------------------------------------------------*/
/* CREATE_PRED                                                             */
/*                                                                         */
/* if module_nb==0 lookup in the public table.                             */
/*-------------------------------------------------------------------------*/
PredInf *Create_Pred(AtomInf *functor,int arity,int module_nb,CodePtr codep)

{
 PredTbl  tbl=(module_nb==0) ? pred_tbl : module_tbl[module_nb].pred_tbl;
 PredInf  pred_info;
 PredInf *pred;


 pred_info.f_n         =Make_Pred_Key(functor,arity);
 pred_info.owner_mod_nb=module_nb;
 pred_info.codep       =codep;

 if (codep)
     pred_info.dynamic=NULL;
  else
    {
     if ((pred_info.dynamic=(DynPInf *) Lib1(malloc,sizeof(DynPInf)))==NULL)
         Fatal_Error(ERR_ALLOC_FAULT);

     Init_Dynamic_Info(pred_info.dynamic);
    }


 pred=(PredInf *) Hash_Lookup(tbl,(char *) &pred_info,H_UPDATE);

 if ((int) pred == -1)
     Fatal_Error(ERR_PRED_TBL_FULL);

 return pred;
}





/*-------------------------------------------------------------------------*/
/* LOOKUP_PRED                                                             */
/*                                                                         */
/* if module_nb==0 lookup in the public table.                             */
/*-------------------------------------------------------------------------*/
PredInf *Lookup_Pred(AtomInf *functor,int arity,int module_nb)

{
 PredTbl tbl=(module_nb==0) ? pred_tbl : module_tbl[module_nb].pred_tbl;

 return (PredInf *) Hash_Fast_Find_Int(tbl,Make_Pred_Key(functor,arity));
}




/*-------------------------------------------------------------------------*/
/* DELETE_PRED                                                             */
/*                                                                         */
/* if module_nb==0 delete in the public table.                             */
/*-------------------------------------------------------------------------*/
void Delete_Pred(AtomInf *functor,int arity,int module_nb)

{
 PredTbl tbl=(module_nb==0) ? pred_tbl : module_tbl[module_nb].pred_tbl;
 int     key=Make_Pred_Key(functor,arity);

 Hash_Lookup(tbl,(char *) &key,H_DELETE);
}




/*-------------------------------------------------------------------------*/
/* CREATE_OPER                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/
OperInf *Create_Oper(AtomInf *atom,int type,int prec,int left,int right)

{
 OperInf  oper_info;
 OperInf *oper;

 oper_info.a_t  =Make_Oper_Key(atom,type);
 oper_info.prec =prec;
 oper_info.left =left;
 oper_info.right=right;

 oper=(OperInf *) Hash_Lookup(oper_tbl,(char *) &oper_info,H_UPDATE);
 if ((int) oper == -1)
     Fatal_Error(ERR_OPER_TBL_FULL);

 return oper;
}




/*-------------------------------------------------------------------------*/
/* LOOKUP_OPER                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/
OperInf *Lookup_Oper(AtomInf *atom,int type)

{
 return (OperInf *) Hash_Fast_Find_Int(oper_tbl,Make_Oper_Key(atom,type));
}




/*-------------------------------------------------------------------------*/
/* DELETE_OPER                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/
OperInf *Delete_Oper(AtomInf *atom,int type)

{
 int key=Make_Oper_Key(atom,type);

 return (OperInf *) Hash_Lookup(oper_tbl,(char *) &key,H_DELETE);
}




/*-------------------------------------------------------------------------*/
/* CREATE_SWT_TABLE                                                        */
/*                                                                         */
/*-------------------------------------------------------------------------*/
SwtTbl Create_Swt_Table(int size)

{
 SwtTbl t;

 if ((t=Hash_Table(size+8,sizeof(SwtInf),sizeof(int)))==NULL)
     Fatal_Error(ERR_ALLOC_FAULT);

 return t;
}



/*-------------------------------------------------------------------------*/
/* CREATE_SWT_ELEMENT                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
void Create_Swt_Element(SwtTbl t,int key,CodePtr codep)

{
 SwtInf swt_info;

 swt_info.key  =key;
 swt_info.c.codep=codep;

 Hash_Lookup(t,(char *) &swt_info,H_CREATE);
}




/*-------------------------------------------------------------------------*/
/* GET_FUNCTOR_ARITY                                                       */
/*                                                                         */
/* returns the functor (NULL if the term is not callable), initializes the */
/* arity and the adress of the first argument (if arity>0).                */
/*-------------------------------------------------------------------------*/
AtomInf *Get_Functor_Arity(WamWord start_word,int *arity,WamWord **arg_adr)

{
 WamWord word,tag,*adr;

 Deref(start_word,word,tag,adr)

 switch(tag)
    {
     case CST:
         *arity=0;
         return UnTag_CST(word);

     case LST:
         adr=UnTag_LST(word);
         *arity=2;
         *arg_adr=&Car(adr);
         return atom_dot;

     case STC:
         adr=UnTag_STC(word);
         *arity=Arity(adr);
         *arg_adr=&Arg(adr,0);
         return Functor(adr);

     default:
         return NULL;
    }
}




/*-------------------------------------------------------------------------*/
/* GET_COMPOUND                                                            */
/*                                                                         */
/* as Get_Functor_Arity but the word is dereferenced and must be a compound*/
/* term (LST or a STC)                                                     */
/*-------------------------------------------------------------------------*/
AtomInf *Get_Compound(WamWord tag,WamWord word,int *arity,WamWord **arg_adr)

{
 WamWord *adr;

 switch(tag)
    {
     case LST:
         adr=UnTag_LST(word);
         *arity=2;
         *arg_adr=&Car(adr);
         return atom_dot;

     case STC:
         adr=UnTag_STC(word);
         *arity=Arity(adr);
         *arg_adr=&Arg(adr,0);
         return Functor(adr);

     default:
         return NULL;
    }
}




/*-------------------------------------------------------------------------*/
/* Global variable management                                              */
/*                                                                         */
/* A global variable allows the user to associate an information to an atom*/
/* There are 3 types of information (2 basic types + 1 constructor):       */
/*                                                                         */
/*   - copy of a term,   builtin: g_assign[b](Gvar,Term)                   */
/*   - link to a term,   builtin: g_link(Gvar,Term)                        */
/*   - array of k infos, builtin: g_{assign[b]/link}(Gvar,g_array(...))    */
/*                                                                         */
/* The assignments can be backtrackble (g_assignb/g_link) or not (g_assign)*/
/* (backtrackable meaning that assignments are undone backtracking occurs).*/
/*                                                                         */
/* Internal represention:                                                  */
/*                                                                         */
/* An information is has a type GVarElt which is a structure with 2 fields */
/* 'size' (indicationg the type of the element) and 'val':                 */
/*                                                                         */
/* size<0: an array of -size elements,                                     */
/*         val (GVarElt *) points the first element.                       */
/*                                                                         */
/* size=0: a link to a term,                                               */
/*         val (WamWord) is the staring word of the term.                  */
/*                                                                         */
/* size>0: a copy of a term whose size is 'size',                          */
/*         val (WamWord *) is the address of the copy of the term          */
/*         (space for the copy obtained by malloc).                        */
/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/
/* G_ASSIGN                                                                */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool G_Assign(WamWord gvar_word,WamWord gval_word,Bool backtrack,Bool copy)

{
 GVarElt *g_elem;


 if ((g_elem=G_Get_Element(gvar_word))==NULL)
     return FALSE;

 return G_Assign_Element(g_elem,gval_word,backtrack,copy);
}




/*-------------------------------------------------------------------------*/
/* G_ASSIGN_ELEMENT                                                        */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool G_Assign_Element(GVarElt *g_elem,WamWord gval_word,
                             Bool backtrack,Bool copy)

{
 WamWord  word,tag,*adr;
 AtomInf *atom;
 int      size;
 int      size_base=0;
 GVarElt  save_g_elem;


 save_g_elem=*g_elem;

 Deref(gval_word,word,tag,adr)

 if (tag==STC)                                      
    {
     adr=UnTag_STC(word);
     atom=Functor(adr);

     if (atom==atom_g_array || atom==atom_g_array_extend)      /* an array */
        {
         if (!G_Assign_Array(g_elem,adr,atom==atom_g_array_extend,copy))
             return FALSE;

         goto finish;
        }
    }



 if (!copy || tag==CST || tag==INT)                              /* a link */
    {
     if (tag==REF && Is_A_Local_Adr(adr))
        {
         word=Tag_Value(REF,H);
         Globalize_Local_Unbound_Var(adr);
        }

     g_elem->size=0;
     g_elem->val=Global_UnMove(tag) ? Tag_Value(REF,adr) : word;
     goto finish;
    }

                                                                 /* a copy */
 size=Term_Size(word);

 if ((adr=(WamWord *) Lib1(malloc,size*sizeof(WamWord)))==NULL)
     Fatal_Error(ERR_ALLOC_FAULT);

 g_elem->size=size+size_base; 
 g_elem->val=(WamWord) adr;

 Copy_Term(adr,&word);



finish:

 if (backtrack)
    {
     Trail_Push(save_g_elem.val);            /* push frame (see G_Untrail) */
     Trail_Push(save_g_elem.size);
     Trail_Push(g_elem);
     Trail_FC(G_Untrail)
    }
  else
     G_Free_Element(&save_g_elem);


 return TRUE;
}




/*-------------------------------------------------------------------------*/
/* G_GET_ELEMENT                                                           */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static GVarElt *G_Get_Element(WamWord gvar_word)

{
 WamWord  word,tag,*adr;
 WamWord  word1;
 AtomInf *atom;
 int      arity;
 WamWord *arg_adr;
 GVarElt  *g_elem;
 int      i,index,size;

 if ((atom=Get_Functor_Arity(gvar_word,&arity,&arg_adr))==NULL)
    {
     Lib1(printf,ERR_ILLEGAL_G_VAR_NAME);
     return NULL;
    }

 g_elem=&(atom->g_elem);

 for(i=0;i<arity;i++)
    {
     size=g_elem->size;

     word1=*arg_adr;
deref:
     Deref(word1,word,tag,adr)

     if (tag!=INT)
        {
         Global_Push(word1=Tag_Value(REF,H));
         if (!G_Read(word,word1))
             return NULL;

         goto deref;
	}

     index=UnTag_INT(word);

     if (tag!=INT || size>=0 || (unsigned) index>= -size)
        {
         Lib1(printf,ERR_ILLEGAL_G_ARRAY_INDEX);
         Lib2(printf," <%d>",index);
         if (word1!=*arg_adr)
            {
             Lib1(printf," given by <");
             Simple_Write_Term(*arg_adr);
             Lib1(printf,">");
            }
         Lib2(printf," for <%s>\n",atom->name);
         return NULL;
        }

     g_elem=(GVarElt *) (g_elem->val)+index;
     arg_adr++;
    }

 return g_elem;
}




/*-------------------------------------------------------------------------*/
/* G_ASSIGN_ARRAY                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static Bool G_Assign_Array(GVarElt *g_elem,WamWord *stc_adr,Bool extend,
                           Bool copy)

{
 WamWord  word,tag,*adr;
 int      arity;
 Bool     same_init_value;
 WamWord  init_word;
 WamWord  lst_word;
 int      src_size,new_size;
 GVarElt  save_g_elem;
 GVarElt *p,*src_p;
 int      i;

 arity=Arity(stc_adr);

 Deref(Arg(stc_adr,0),word,tag,adr)
 new_size=(tag==LST) ? Proper_List_Length(word) : UnTag_INT(word);

 if (!(new_size>0 && (tag==INT && arity<=2 || tag==LST && arity==1)))
    {
     Lib1(printf,ERR_ILLEGAL_G_ARRAY_DECL);
     return FALSE;
    }

 if (tag==INT)
    {
     same_init_value=TRUE;
     init_word=(arity==1) ? G_VAR_INITIAL_VALUE : Arg(stc_adr,1);
    }
  else
    {
     same_init_value=FALSE;
     lst_word=word;
    }

 if (extend && g_elem->size<0)
    {
     src_size=-g_elem->size;
     src_p=(GVarElt *) (g_elem->val);
    }
  else
     src_size=0;


 save_g_elem=*g_elem;

 if ((p=(GVarElt *) Lib1(malloc,new_size*sizeof(GVarElt)))==NULL)
     Fatal_Error(ERR_ALLOC_FAULT);

 g_elem->size=-new_size;
 g_elem->val=(WamWord) p;


 for(i=0;i<new_size;i++)
    {
     if (!same_init_value)
        {
         Get_List(lst_word);
         Unify_Variable(&init_word);
         Unify_Variable(&lst_word);
        }

     if (src_size>0)
        {
         src_size--;
         G_Copy_Element(p++,src_p++);
        }
      else
        {
         p->size=0;
         p->val=G_VAR_INITIAL_VALUE;
         if (!G_Assign_Element(p++,init_word,FALSE,copy))
            {
             Lib1(free,(char *) g_elem->val);
             *g_elem=save_g_elem;
             return FALSE;
            }
        }
    }

 return TRUE;
}




/*-------------------------------------------------------------------------*/
/* G_FREE_ELEMENT                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static void G_Free_Element(GVarElt *g_elem)

{
 int      size;
 GVarElt *p;
 int      i;
 
 size=g_elem->size;

 if (size==0)                                           /* a link: nothing */
     return;

 if (size<0)                            /* an array: recursively free elts */
    {
     size=-size;
     p=(GVarElt *)(g_elem->val);

     for(i=0;i<size;i++)
         G_Free_Element(p++);
    }

                                               /* a copy or an array: free */
 Lib1(free,(char *) g_elem->val);
}




/*-------------------------------------------------------------------------*/
/* G_COPY_ELEMENT                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static void G_Copy_Element(GVarElt *dst_g_elem,GVarElt *src_g_elem)

{
 WamWord *adr;
 int      size;
 GVarElt *p;
 int      i;
 
 size=dst_g_elem->size=src_g_elem->size;

 if (size==0)                                              /* a link: copy */
    {
     dst_g_elem->val=src_g_elem->val;
     return;
    }

 if (size<0)                    /* an array: alloc + recursively copy elts */
    {
     size=-size;

     if ((p=(GVarElt *) Lib1(malloc,size*sizeof(GVarElt)))==NULL)
         Fatal_Error(ERR_ALLOC_FAULT);

     dst_g_elem->val=(WamWord) p;
     dst_g_elem=p;

     src_g_elem=(GVarElt *)(src_g_elem->val);

     for(i=0;i<size;i++)
         G_Copy_Element(dst_g_elem++,src_g_elem++);

     return;
    }

                                                   /* a copy: alloc + copy */

 if ((adr=(WamWord *) Lib1(malloc,size*sizeof(WamWord)))==NULL)
     Fatal_Error(ERR_ALLOC_FAULT);

 dst_g_elem->val=(WamWord) adr;

 Copy_Contiguous_Term(adr,(WamWord *) src_g_elem->val);
}




/*-------------------------------------------------------------------------*/
/* G_UNTRAIL                                                               */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static void G_Untrail(void)

{
 GVarElt *g_elem;

 g_elem=(GVarElt *) Trail_Pop;         /* pop frame (see G_Assign_Element) */
 G_Free_Element(g_elem);
 g_elem->size=Trail_Pop;
 g_elem->val =Trail_Pop;
}




/*-------------------------------------------------------------------------*/
/* G_READ                                                                  */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool G_Read(WamWord gvar_word,WamWord gval_word)

{
 GVarElt *g_elem;

 if ((g_elem=G_Get_Element(gvar_word))==NULL)
     return FALSE;

 return G_Read_Element(g_elem,gval_word);
}




/*-------------------------------------------------------------------------*/
/* G_READ_ELEMENT                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static WamWord G_Read_Element(GVarElt *g_elem,WamWord gval_word)

{
 WamWord  word;
 int      size=g_elem->size;
 GVarElt *p;
 int      i;


 if (size==0)                                             /* a link: unify */
     return Unify(g_elem->val,gval_word);

 if (size>0)                                         /* a copy: copy+unify */
    {
     Copy_Contiguous_Term(H,(WamWord *) g_elem->val);
     word=*H;
     if (Global_UnMove(Tag_Of(word)))
         word=Tag_Value(REF,H);
     H+=size;
     return Unify(word,gval_word);
    }

                                 /* an array: unify with array([elt1,...]) */
 size=-size;
 p=(GVarElt *) g_elem->val;

 if (!Get_Structure(atom_g_array,1,gval_word))
     return FALSE;

 Unify_Variable(&gval_word);

 for(i=0;i<size;i++)
    {
     if (!Get_List(gval_word))
         return FALSE;

     Unify_Variable(&word);
     Unify_Variable(&gval_word);

     if (!G_Read_Element(p++,word))
         return FALSE;
    }

 return Get_Nil(gval_word);
}




/*-------------------------------------------------------------------------*/
/* G_ARRAY_SIZE                                                            */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool G_Array_Size(WamWord gvar_word,WamWord size_word)

{
 GVarElt *g_elem;

 if ((g_elem=G_Get_Element(gvar_word))==NULL || g_elem->size>=0)
     return FALSE;

 return Get_Integer(-g_elem->size,size_word);
}




/*-------------------------------------------------------------------------*/
/* Dynamic clause management                                               */
/*                                                                         */
/* Dynamic clauses are stored in clause frames allocated by malloc.        */
/* The frame consists of:                                                  */
/*                                                                         */
/*   - a number (<0 if asserta >=0 if assertz) to order them.              */
/*   - a forward  sequential chain (chronological chain).                  */
/*   - a backward sequential chain (chronological chain).                  */
/*   - a forward  indexing   chain                                         */
/*   - a backward indexing   chain                                         */
/*   - the size of the Prolog term                                         */
/*   - the corresponding Prolog term of the form [Head|Body] for Head:-Body*/
/*                                                                         */
/* For a dynamic predicate the structure DynPInfo has 6 entry-points for   */
/* clause chaining: 1 for the sequential chain, 5 for indexing chains,     */
/* depending on the first argument of the Head:                            */
/*                                                                         */
/*   - seq_chain    : a chain to the first clause                          */
/*   - var_ind_chain: a chain to the first clause with a var as 1st arg    */
/*   - cst_htbl     : a hash table: key=cst/info=chain to the first clause */
/*   - int_htbl     : a hash table: key=int/info=chain to the first clause */
/*   - lst_ind_chain: a chain to the first clause with a list as 1st arg   */
/*   - stc_htbl     : a hash table: key=f_n/info=chain to the first clause */
/*                                                                         */
/* dynamic predicate are always public (should be improved)                */
/*-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------*/
/* ADD_NEW_CLAUSE                                                          */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Add_New_Clause(WamWord start_word,Bool asserta)


{
 PredInf  *pred;
 int       index_nb,key;
 int      *clause;
 DynPInf  *dyn;
 char    **p_htbl;
 SwtInf    swt_info;
 SwtInf   *swt;
 int       size;


 if ((pred=Get_Pred_And_Index(start_word,&index_nb,&key,TRUE))==NULL)
     return FALSE;

 dyn=pred->dynamic;

 size=Term_Size(start_word);
 clause=(int *) 
           Lib1(malloc,(DYNAMIC_CLAUSE_STATIC_SIZE+size)*sizeof(WamWord));

 if (clause==NULL)
     Fatal_Error(ERR_ALLOC_FAULT);


 Clause_Number(clause)=(asserta) ? dyn->count_a-- : dyn->count_z++;
 Add_To_List(&dyn->seq_chain,(int **) &Seq_Chain_F(clause),asserta);

 Clause_Size(clause)=size;
 Copy_Term(&Clause(clause),&start_word);


 if (index_nb==NO_INDEX)
    {
     Ind_Chain_F(clause)=NULL;
     Ind_Chain_B(clause)=NULL;

#ifdef CDEBUG
     last_pred=pred;
     Verify_Dynamic_Clauses();
#endif

     return TRUE;
    }


 if (index_nb==VAR_INDEX || index_nb==LST_INDEX)
    {
     Add_To_List((int **) dyn+index_nb,
                 (int **) &Ind_Chain_F(clause),asserta);

#ifdef CDEBUG
     last_pred=pred;
     Verify_Dynamic_Clauses();
#endif

     return TRUE;
    }

 p_htbl=(char **) dyn+index_nb;

 if (*p_htbl==NULL)
     if ((*p_htbl=Hash_Table(BLOCK_SIZE,sizeof(SwtInf),sizeof(int)))==NULL)
         Fatal_Error(ERR_ALLOC_FAULT);

 swt_info.key=key;
 swt_info.c.ind_chain=NULL;

 swt=(SwtInf *) Hash_Lookup(*p_htbl,(char *) &swt_info,H_ADD);
 if ((int) swt== -1)
    {
     Extend_HTable(p_htbl);
     swt=(SwtInf *) Hash_Lookup(*p_htbl,(char *) &swt_info,H_ADD);
    }

 Add_To_List(&(swt->c.ind_chain),(int **) &Ind_Chain_F(clause),asserta);

#ifdef CDEBUG
 last_pred=pred;
 Verify_Dynamic_Clauses();
#endif

 return TRUE;
}




/*-------------------------------------------------------------------------*/
/* GET_PRED_AND_INDEX                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static PredInf *Get_Pred_And_Index(WamWord start_word,
                                   int *index_nb,int *key,Bool create)

{
 WamWord  word,tag,*adr;
 WamWord *first_arg_adr;
 AtomInf *functor;
 int      arity;
 PredInf *pred;


 Deref(start_word,word,tag,adr)
 adr=UnTag_LST(word);

 if ((functor=Get_Functor_Arity(Car(adr),&arity,&first_arg_adr))==NULL)
    {
     Lib1(printf,ERR_ILLEGAL_GOAL);
     return NULL;
    }

 if ((pred=Lookup_Pred(functor,arity,0))==NULL && create)
     pred=Create_Pred(functor,arity,0,NULL);

 if (pred && pred->codep)
    {
     Lib3(printf,ERR_STATIC_PREDICATE,functor->name,arity);
     return NULL;
    }

 if (arity==0)
     *index_nb=NO_INDEX;
  else
    {
     Deref(*first_arg_adr,word,tag,adr)
     switch(tag)
        {
         case REF:
             *index_nb=VAR_INDEX;
             break;
    
         case CST:
             *index_nb=CST_INDEX;
             *key=(int) UnTag_CST(word);
             break;
    
         case INT:
             *index_nb=INT_INDEX;
             *key=UnTag_INT(word);
             break;
    
         case LST:
             *index_nb=LST_INDEX;
             break;
    
         default:                                              /* tag==STC */
             *index_nb=STC_INDEX;
             *key=(int) Functor_And_Arity(UnTag_STC(word));
             break;
        }
    }

 return pred;
}




/*-------------------------------------------------------------------------*/
/* ADD_TO_LIST                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static void Add_To_List(int **list,int **to_add,Bool asserta)

{
 if (!asserta)
     while(*list)
         list=(int **) *list;

 if ((to_add[0]=*list)!=NULL)
     (*list)[1]=(int) to_add;

 to_add[1]=(int *) list;
 *list=(int *) to_add;
}




/*-------------------------------------------------------------------------*/
/* EXTEND_HTABLE                                                           */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static void Extend_HTable(char **t)

{
 char   *t1;
 SwtInf *swt;
 SwtInf *swt1;
 int    *clause;

 t1=Hash_Table(Hash_Table_Size(*t)+BLOCK_SIZE,sizeof(SwtInf),sizeof(int));

 if (t1==NULL)
     Fatal_Error(ERR_ALLOC_FAULT);

 for(swt=(SwtInf *) Hash_Lookup(*t,NULL,H_NEXT);swt;
     swt=(SwtInf *) Hash_Lookup(*t,(char *) swt,H_NEXT))
    {
     if (swt->c.ind_chain)       /* do not copy if no entries longer exist */
        {
         swt1=(SwtInf *) Hash_Lookup(t1,(char *) swt,H_CREATE);
         clause=Clause_From_Ind_Chain_F(swt1->c.ind_chain);
         Ind_Chain_B(clause)=(int *) &(swt1->c.ind_chain);
        }
    }     

 Hash_Delete_Table(*t);
 *t=t1;
}




/*-------------------------------------------------------------------------*/
/* SCAN_FIRST_CLAUSE                                                       */
/*                                                                         */
/*-------------------------------------------------------------------------*/
Bool Scan_First_Clause(WamWord start_word,DynScan *scan)

{
 PredInf *pred;
 int      index_nb,key;
 DynPInf *dyn;
 char    *htbl;
 SwtInf  *swt;


 if ((pred=Get_Pred_And_Index(start_word,&index_nb,&key,FALSE))==NULL)
     return FALSE;

 dyn=pred->dynamic;

 switch(index_nb)
    {
     case NO_INDEX:
     case VAR_INDEX:
         scan->xxx_is_seq_chain=TRUE;
         scan->xxx_ind_chain=dyn->seq_chain;
         scan->var_ind_chain=NULL;
         break;

     case LST_INDEX:
         scan->xxx_is_seq_chain=FALSE;
         scan->xxx_ind_chain=dyn->lst_ind_chain;
         scan->var_ind_chain=dyn->var_ind_chain;
         break;

     default:
         scan->xxx_is_seq_chain=FALSE;
         htbl=((char **) dyn)[index_nb];
         if (htbl && (swt=(SwtInf *) Hash_Fast_Find_Int(htbl,key))!=NULL)
             scan->xxx_ind_chain=swt->c.ind_chain;
          else
             scan->xxx_ind_chain=NULL;

         scan->var_ind_chain=dyn->var_ind_chain;
    }


#ifdef CDEBUG
 last_pred=pred;
#endif

 return Scan_Next_Clause(scan);
}





/*-------------------------------------------------------------------------*/
/* SCAN_NEXT_CLAUSE                                                        */
/*                                                                         */
/* This function uses the structure DynScan pointed by scan to get dynamic */
/* clauses. This structure contains 3 input cells (must be set):           */
/*                                                                         */
/*    - xxx_is_seq_chain: the cell xxx_ind_chain points to seq_chain       */
/*    - xxx_ind_chain   : current cst/int/lst/stc indexing chain           */
/*    - var_ind_chain   : current var indexing chain                       */
/*                                                                         */
/* Since a clause with a variable as 1st argument can be used by all       */
/* callers, two chains are traversed: var_ind_chain and xxx_ind_chain      */
/* (xxx=cst/int/lst/stc). scan->var_ind_chain points the next clause with a*/
/* var as 1st arg and scan->xxx_ind_chain points the next clause with the  */
/* appropriate index. the clause choosen is the one with the smaller clause*/
/* number between var_clause and xxx_clause.                               */
/* There is a special case when the first argument of the caller is a var  */
/* or when the arity is 0: then all clauses must be taken into account.    */
/* To do this xxx_ind_chain=seq_chain (and scan->xxx_is_seq_chain is TRUE) */
/* and var_ind_chain points to NULL                                        */
/*                                                                         */
/* When a clause is found, 3 output cells are set:                         */
/*                                                                         */
/*   - cur_clause: points the current clause frame                         */
/*   - cur_word  : a Prolog term corresponding to the clause [Head|Body]   */
/*   - is_last   : is there another possible clause after this one ?       */
/*-------------------------------------------------------------------------*/
Bool Scan_Next_Clause(DynScan *scan)

{
 int *xxx_ind_chain,*var_ind_chain;
 int *xxx_clause,   *var_clause;
 int  xxx_nb,        var_nb;
 int *clause;
 int  n;


 xxx_ind_chain=scan->xxx_ind_chain;
 if (xxx_ind_chain)
    {
     xxx_clause=(scan->xxx_is_seq_chain)
                       ? Clause_From_Seq_Chain_F(xxx_ind_chain)
                       : Clause_From_Ind_Chain_F(xxx_ind_chain);

     xxx_nb    =Clause_Number(xxx_clause);
    }
  else
     xxx_nb    =INT_GREATEST_VALUE;
     
 var_ind_chain =scan->var_ind_chain;
 if (var_ind_chain)
    {
     var_clause=Clause_From_Ind_Chain_F(var_ind_chain);
     var_nb    =Clause_Number(var_clause);
    }
  else
     var_nb    =INT_GREATEST_VALUE;

 if (xxx_nb<=var_nb)
    {
     if (xxx_nb==INT_GREATEST_VALUE)
        { 
#ifdef CDEBUG
         Verify_Dynamic_Clauses();
#endif
         return FALSE;
        }
     clause=xxx_clause;
     scan->xxx_ind_chain=(int *) (*xxx_ind_chain);
    }
  else
    {
     clause=var_clause;
     scan->var_ind_chain=(int *) (*var_ind_chain);
    }

 scan->cur_clause=clause;

 scan->is_last=(scan->xxx_ind_chain==NULL && scan->var_ind_chain==NULL);
 

 n=Clause_Size(clause);
 Copy_Contiguous_Term(H,&Clause(clause));
 scan->cur_word=*H;

 H+=n;


#ifdef CDEBUG
 Verify_Dynamic_Clauses();
#endif

 return TRUE;
}




/*-------------------------------------------------------------------------*/
/* DELETE_CURRENT_CLAUSE                                                   */
/*                                                                         */
/* This function deletes the current clause pointed by scan->cur_clause.   */
/*-------------------------------------------------------------------------*/
void Delete_Current_Clause(DynScan *scan_info)

{
 int  *clause=scan_info->cur_clause;
 int  *clause1;
 int **seq_chain_back;
 int **ind_chain_back;

 seq_chain_back=(int **) Seq_Chain_B(clause);
 ind_chain_back=(int **) Ind_Chain_B(clause);

 if ((*seq_chain_back=Seq_Chain_F(clause))!=NULL)
    {
     clause1=Clause_From_Seq_Chain_F(*seq_chain_back);
     Seq_Chain_B(clause1)=(int *) seq_chain_back;
    }

                                                  /* test also if no index */
 if (ind_chain_back && (*ind_chain_back=Ind_Chain_F(clause))!=NULL)
    {
     clause1=Clause_From_Ind_Chain_F(*ind_chain_back);
     Ind_Chain_B(clause1)=(int *) ind_chain_back;
    }
 
 Lib1(free,clause);

#ifdef CDEBUG
 Verify_Dynamic_Clauses();
#endif
}


     

#ifdef CDEBUG

/*-------------------------------------------------------------------------*/
/* VERIFY_DYNAMIC_CLAUSES                                                  */
/*                                                                         */
/* (debug function)                                                        */
/*-------------------------------------------------------------------------*/
static void Verify_Dynamic_Clauses(void)

{
 PredInf *pred=last_pred;
 AtomInf *functor=Atom_Of_Pred(pred);
 int      arity=Arity_Of_Pred(pred);
 DynPInf *dyn=pred->dynamic;

 Lib4(printf,"\nPred %s/%d (dyn:0x%06x)",functor->name,arity,pred->dynamic);
 Lib4(printf,"  count_a:%d   count_z:%d   consult:%d\n",
             dyn->count_a,dyn->count_z,dyn->consult_count); 

 Lib1(printf,"\nSEQ:\n");
 Verify_List(dyn->seq_chain,NO_INDEX);

 Lib1(printf,"\nVAR:\n");
 Verify_List(dyn->var_ind_chain,VAR_INDEX);

 Lib1(printf,"\nCST:\n");
 Verify_Hash(dyn->cst_htbl,CST_INDEX);

 Lib1(printf,"\nINT:\n");
 Verify_Hash(dyn->int_htbl,INT_INDEX);

 Lib1(printf,"\nLST:\n");
 Verify_List(dyn->lst_ind_chain,LST_INDEX);

 Lib1(printf,"\nSTC:\n");
 Verify_Hash(dyn->stc_htbl,STC_INDEX);
}




/*-------------------------------------------------------------------------*/
/* VERIFY_HASH                                                             */
/*                                                                         */
/* (debug function)                                                        */
/*-------------------------------------------------------------------------*/
static void Verify_Hash(char *t,int index_nb)

{
 SwtInf *buff_ptr;

 if (t==NULL)
     return;

 for(buff_ptr=(SwtInf *) Hash_Lookup(t,NULL,H_NEXT);buff_ptr;
     buff_ptr=(SwtInf *) Hash_Lookup(t,(char *) buff_ptr,H_NEXT))
    {
     Lib2(printf," val (0x%06x)",&(buff_ptr->c.ind_chain));

     if (index_nb==CST_INDEX)
         Lib2(printf," <%s>\n",((AtomInf *) (buff_ptr->key))->name);

     if (index_nb==INT_INDEX)
         Lib2(printf," <%d>\n",buff_ptr->key);

     if (index_nb==STC_INDEX)
         Lib3(printf," <%s/%d>\n",Functor_Name(buff_ptr->key),
                                  Arity_Of(buff_ptr->key));

     Verify_List(buff_ptr->c.ind_chain,index_nb);
    }

}




/*-------------------------------------------------------------------------*/
/* VERIFY_LIST                                                             */
/*                                                                         */
/* (debug function)                                                        */
/*-------------------------------------------------------------------------*/
static void Verify_List(int *p,int index_nb)

{
 int *clause;
 int *ind_chain_b;
 int *ind_chain_f;
 int *clause_b;
 int *clause_f;

 while(p)
    {
     clause_f=clause_b=NULL;
     if (index_nb==NO_INDEX)
        {
         clause=Clause_From_Seq_Chain_F(p);

         if ((ind_chain_b=Seq_Chain_B(clause))!=NULL)
             clause_b=Clause_From_Seq_Chain_F(ind_chain_b);

         if ((ind_chain_f=Seq_Chain_F(clause))!=NULL)
             clause_f=Clause_From_Seq_Chain_F(ind_chain_f);
        }
      else
        {
         clause=Clause_From_Ind_Chain_F(p);

         if ((ind_chain_b=Ind_Chain_B(clause))!=NULL)
             clause_b=Clause_From_Ind_Chain_F(ind_chain_b);

         if ((ind_chain_f=Ind_Chain_F(clause))!=NULL)
             clause_f=Clause_From_Ind_Chain_F(ind_chain_f);
        }

     Lib4(printf," %3d  %3d 0x%06x  ",
          Clause_Number(clause),Clause_Size(clause),clause);
     Lib3(printf," 0x%06x <-> 0x%06x   ",clause_b,clause_f);
     Simple_Write_Term(Clause(clause));
     Lib2(printf,"\n",clause);

     p=(int *) (*p);
    }
}

#endif




/*-------------------------------------------------------------------------*/
/* REINIT_DYNAMIC_PRED                                                     */
/*                                                                         */
/* what_to_do : 0 = abolish / 1 = init consult / 2 = retract all clauses   */
/*-------------------------------------------------------------------------*/
Bool Reinit_Dynamic_Pred(AtomInf *functor,int arity,int what_to_do)

{
 PredInf *pred;
 DynPInf *dyn;
 int     *seq_chain;
 int     *clause;


 if ((pred=Lookup_Pred(functor,arity,0))==NULL)
     return TRUE;                                          /* like sicstus */

 if (pred->codep)
    {
     Lib3(printf,ERR_STATIC_PREDICATE,functor->name,arity);
     return FALSE;
    }

 dyn=pred->dynamic;

 if (what_to_do==1 && dyn->consult_count==consult_count)
     return TRUE;

 seq_chain=dyn->seq_chain;
 while(seq_chain)                                    /* remove all clauses */
    {
     clause=Clause_From_Seq_Chain_F(seq_chain);
     seq_chain=Seq_Chain_F(clause);
     Lib1(free,clause);
    }

 if (dyn->cst_htbl)
     Hash_Delete_Table(dyn->cst_htbl);

 if (dyn->int_htbl)
     Hash_Delete_Table(dyn->int_htbl);

 if (dyn->stc_htbl)
     Hash_Delete_Table(dyn->stc_htbl);

 if (what_to_do==0)
     Delete_Pred(functor,arity,0);
  else
     Init_Dynamic_Info(dyn)


 return TRUE;
}
