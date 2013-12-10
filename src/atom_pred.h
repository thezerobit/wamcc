/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* C Run-time                                           Daniel Diaz - 1991 */
/*                                                                         */
/* Atoms and Predicates Tables Management - Header file                    */
/*                                                                         */
/* atom_pred.h                                                             */
/*-------------------------------------------------------------------------*/
#include "bool.h"
#include "hash.h"




/*---------------------------------*/
/* Constants                       */
/*---------------------------------*/

#define MAX_ATOM_TBL_SIZE         32768           /* in number of elements */
#define MAX_PRED_TBL_SIZE         16384           /* in number of elements */
#define MAX_OPER_TBL_SIZE          1024           /* in number of elements */

#define MAX_MODULE                 256


#define NB_BITS_OF_ARITY           8
#define MAX_ARITY                  (1 << NB_BITS_OF_ARITY)



#define G_VAR_INITIAL_VALUE        Tag_Value(INT,0)




          /* Atom & Pred Manipulations */

#define Wam_Ptr(p)                 ((unsigned) (p)-MALLOC_START)
#define Real_Ptr(p)                ((unsigned) (p)+MALLOC_START)




          /* Characters */

#define UNKNOWN                    0              /* unknown character     */
#define LA                         1              /* layout character      */
#define SC                         2              /* solo character        */
#define QT                         4              /* quote                 */
#define DQ                         8              /* double quote          */
#define BQ                        16              /* back quote            */
#define SY                        32              /* symbol                */
#define PC                        64              /* ponctuation character */
#define DI                       128              /* digit                 */
#define UL                       256              /* underline             */
#define CL                       512              /* capital letter        */
#define SL                      1024              /* small letter          */
#define CM                      2048              /* comment character (%) */


          /* Atom */

#define NOT_AN_ATOM                0
#define IDENTIFIER_ATOM            1
#define SYMBOL_ATOM                2
#define SOLO_ATOM                  3
#define OTHER_ATOM                 4




          /* Predicate */

#define Make_Pred_Key(a,n)         Functor_Arity(a,n)
#define Atom_Of_Pred(p)            Functor_Of((p)->f_n)
#define Arity_Of_Pred(p)           Arity_Of((p)->f_n)



          /* Dynamic Clause */

#define DYNAMIC_CLAUSE_STATIC_SIZE 6


#define Clause_Number(clause)       (((int  *)    (clause))[0])
#define Seq_Chain_F(clause)         (((int **)    (clause))[1])
#define Seq_Chain_B(clause)         (((int **)    (clause))[2])
#define Ind_Chain_F(clause)         (((int **)    (clause))[3])
#define Ind_Chain_B(clause)         (((int **)    (clause))[4])
#define Clause_Size(clause)         (((int  *)    (clause))[5])

#define Clause(clause)              (((WamWord *) (clause))[6])



#define Clause_From_Seq_Chain_F(p) ((int *) (p)-1)
#define Clause_From_Seq_Chain_B(p) ((int *) (p)-2)
#define Clause_From_Ind_Chain_F(p) ((int *) (p)-3)
#define Clause_From_Ind_Chain_B(p) ((int *) (p)-4)




          /* Operator */

#define Make_Oper_Key(a,t)         ((unsigned) (a) | (t))
#define Atom_Of_Oper(o)            ((AtomInf *) (((o)->a_t) & (~0x3)))
#define Type_Of_Oper(o)            (((o)->a_t) & (0x3))


#define PREFIX                     0
#define POSTFIX                    1
#define INFIX                      2


#define MAX_PREC                   1200
#define MAX_ARG_OF_FUNCTOR_PREC    999




          /* Error Messages */

#define ERR_ILLEGAL_GOAL           "\nError: Illegal goal\n"

#define ERR_ILLEGAL_G_VAR_NAME     "\nError: Illegal variable name\n"
#define ERR_ILLEGAL_G_ARRAY_DECL   "\nError: Illegal array declaration\n"
#define ERR_ILLEGAL_G_ARRAY_INDEX  "\nError: Illegal array index"

#define ERR_STATIC_PREDICATE       "\nError: %s/%d is a static predicate\n"

#define ERR_ALLOC_FAULT            "atom_pred: Memory allocation fault"


#define ERR_ATOM_TBL_FULL          "Atom table full"
#define ERR_PRED_TBL_FULL          "Predicate table full"
#define ERR_OPER_TBL_FULL          "Operator table full"





/*---------------------------------*/
/* Type Definitions                */
/*---------------------------------*/

typedef char *AtomTbl;
typedef char *PredTbl;
typedef char *OperTbl;
typedef char *SwtTbl;




typedef struct                           /* Module information             */
    {                                    /* ------------------------------ */
     char    *name;                      /* module name                    */
     int      debug_level;               /* 0: no debugged, 1: pl, 2:pl+wam*/
     PredTbl  pred_tbl;                  /* private predicate table        */
    }ModulInf;




typedef struct                           /* Glabal Variable Element        */
    {                                    /* ------------------------------ */
     int      size;                      /* <0:-array dim 0:link, >0:copy  */
     WamWord  val;                       /* ptr to GVarElt or term or adr  */
    }GVarElt;




typedef struct                           /* Atom information               */
    {                                    /* ------------------------------ */
     char    *name;                      /* key is <name> (the string)     */
     int      type;                      /* IDENTIFIER, SYMBOL, SOLO, OTHER*/
     Bool     has_quote;                 /* does name contain any ' ?      */
     Bool     needs_quote;               /* does name need ' around it ?   */
     int      length;                    /* its length (in characters)     */
     GVarElt  g_elem;                    /* global variable element        */
    }AtomInf;




typedef struct                           /* Dynamic predicate information  */
    {                                    /* ------------------------------ */
     int     *seq_chain;                 /* sequential chain     (->clause)*/
     int     *var_ind_chain;             /* index if 1st arg=VAR (->clause)*/
     char    *cst_htbl;                  /* index if 1st arg=CST (->htable)*/
     char    *int_htbl;                  /* index if 1st arg=INT (->htable)*/
     int     *lst_ind_chain;             /* index if 1st arg=LST (->clause)*/
     char    *stc_htbl;                  /* index if 1st arg=STC (->htable)*/
     int      count_a;                   /* next clause nb for asserta     */
     int      count_z;                   /* next clause nb for assertz     */
     int      consult_count;             /* counter for reinit. at consult */
    }DynPInf;




typedef struct                           /* Predicate information          */
    {                                    /* ------------------------------ */
     int      f_n;                       /* key is <functor_atom,arity>    */
     int      owner_mod_nb;              /* module nb where it is defined  */
     CodePtr  codep;                     /* compiled code (NULL if dynamic)*/
     DynPInf *dynamic;                   /* dynamic info (or NULL)         */
    }PredInf;




typedef struct                           /* Dynamic clause scanning info   */
    {                                    /* --------- input data --------- */
     Bool     xxx_is_seq_chain;          /* scan all clauses ?             */
     int     *xxx_ind_chain;             /* current assoc index (->*clause)*/
     int     *var_ind_chain;             /* current var   index (->*clause)*/
                                         /* --------- output data -------- */
     int     *cur_clause;                /* current clause address         */
     int      cur_word;                  /* current clause ([Head|Body])   */
     Bool     is_last;                   /* another clause after this one ?*/
    }DynScan;




typedef struct                           /* Operator information           */
    {                                    /* ------------------------------ */
     int      a_t;                       /* key is <atom,operator_type>    */
     int      prec;                      /* precedence of the operator     */
     int      left;                      /* precedence of the operator lhs */
     int      right;                     /* precedence of the operator rhs */
    }OperInf;




typedef struct                           /* Switch item information        */
    {                                    /* ------------------------------ */
     int      key;                       /* key: cst, int, f/n (see below) */
     union
        {
         CodePtr  codep;                 /* compiled code pointer if static*/
         int     *ind_chain;             /* index if dynamic    (->clause) */
        }c;
    }SwtInf;




/*---------------------------------*/
/* Global Variables                */
/*---------------------------------*/

#ifdef ATOM_PRED


       int       nb_of_module=0;
       ModulInf  module_tbl[MAX_MODULE];

       AtomTbl   atom_tbl;
       AtomInf  *atom_nil;
       AtomInf  *atom_dot;
       AtomInf  *atom_curly_brackets;
       AtomInf  *atom_fail;

       AtomInf  *atom_g_array;
       AtomInf  *atom_g_array_extend;

       AtomInf  *atom_inf;
       AtomInf  *atom_eq;
       AtomInf  *atom_sup;

       AtomInf  *atom_compiler;
       AtomInf  *atom_wam_version;


       PredTbl   pred_tbl;

       OperTbl   oper_tbl;

    /* int       char_type[256];             see definition in atom_prec.c */

       int       consult_count;

#else


extern int       nb_of_module;
extern ModulInf  module_tbl[MAX_MODULE];

extern AtomTbl   atom_tbl;
extern AtomInf  *atom_nil;
extern AtomInf  *atom_dot;
extern AtomInf  *atom_curly_brackets;
extern AtomInf  *atom_fail;

extern AtomInf  *atom_g_array;
extern AtomInf  *atom_g_array_extend;

extern AtomInf  *atom_inf;
extern AtomInf  *atom_eq;
extern AtomInf  *atom_sup;

extern AtomInf  *atom_compiler;
extern AtomInf  *atom_wam_version;

extern PredTbl   pred_tbl;

extern OperTbl   oper_tbl;

extern int       char_type[];

extern int       consult_count;

#endif




/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/

void      Init_Atom_Pred        (void);

AtomInf  *Create_Allocate_Atom  (char *name);
AtomInf  *Create_Atom           (char *name);
AtomInf  *Lookup_Atom           (char *name);


PredTbl   Create_Pred_Table     (int size);
PredInf  *Create_Pred           (AtomInf *functor,int arity,int module_nb,
                                 CodePtr codep);
PredInf  *Lookup_Pred           (AtomInf *functor,int arity,int module_nb);
void      Delete_Pred           (AtomInf *functor,int arity,int module_nb);


OperInf  *Create_Oper           (AtomInf *atom,int type,
                                 int prec,int left,int right);
OperInf  *Lookup_Oper           (AtomInf *atom,int type);
OperInf  *Delete_Oper           (AtomInf *atom,int type);


SwtTbl    Create_Swt_Table      (int size);
void      Create_Swt_Element    (SwtTbl t,int key,CodePtr codep);


AtomInf  *Get_Functor_Arity     (WamWord start_word,int *arity,
                                 WamWord **arg_adr);
AtomInf  *Get_Compound          (WamWord tag,WamWord word,int *arity,
                                 WamWord **arg_adr);


Bool      G_Assign              (WamWord gvar_word,WamWord gval_word,
                                 Bool backtrack,Bool copy);
Bool      G_Read                (WamWord gvar_word,WamWord gval_word);
Bool      G_Array_Size          (WamWord gvar_word,WamWord size_word);


Bool      Add_New_Clause        (WamWord start_word,Bool asserta);
Bool      Scan_First_Clause     (WamWord start_word,DynScan *scan);
Bool      Scan_Next_Clause      (DynScan *scan);
void      Delete_Current_Clause (DynScan *scan);
Bool      Reinit_Dynamic_Pred    (AtomInf *functor,int arity,int what_to_do);





/*---------------------------------*/
/* Interface with C files          */
/*---------------------------------*/

#define Init_Tables_Of_Module(module)                                       \
    {                                                                       \
     Init_Tables_Prototyp(module)                                           \
     CPP_CAT(module,_Init_Tables)();                                        \
    }




#define Init_Tables_Prototyp(module)                                        \
    void CPP_CAT(module,_Init_Tables)(void);




#define Begin_Init_Tables(module)                                           \
    void CPP_CAT(module,_Init_Tables)(void)                                 \
    {                                                                       \
     char *t;                                                               \
                                                                            \
     module_tbl[nb_of_module].name       =module_name;                      \
     module_tbl[nb_of_module].debug_level=DEBUG_LEVEL;                      \
     module_tbl[nb_of_module].pred_tbl   =                                  \
                                    Create_Pred_Table(NB_OF_PRIVATE_PREDS); \
     module_nb= nb_of_module++;




          /* Atom Hash Table : key is the C string associated to the atom */

#define Define_Atom(atom,name)                                              \
     atom=Create_Atom(name);




          /* Pred Hash Table : key is atom info adr / arity */

#define Define_Pred(atom,n,public)                                          \
    {                                                                       \
     Prototype(Prefix(Pred_Name(atom,n)))                                   \
     Create_Pred(atom,n,(public) ? 0 : module_nb,                           \
                 (CodePtr) Prefix(Pred_Name(atom,n)));                      \
    }




          /* Switch Hash Table : key always is an integer     */
          /*    for constants  : key is the atom info adr     */
          /*    for integer    : key is the integer           */
          /*    for structure  : key is atom info adr / arity */

#define Define_Switch_CST_Table(tbl,size)                                   \
     t=tbl=Create_Swt_Table(size);



#define Define_Switch_CST(atom,codep)                                       \
    {                                                                       \
     Prototype(Prefix(codep))                                               \
     Create_Swt_Element(t,(int) atom,(CodePtr) Prefix(codep));              \
    }




#define Define_Switch_STC_Table(tbl,size)                                   \
     t=tbl=Create_Swt_Table(size);




#define Define_Switch_STC(atom,n,codep)                                     \
    {                                                                       \
     Prototype(Prefix(codep))                                               \
     Create_Swt_Element(t,Functor_Arity(atom,n),                            \
                        (CodePtr) Prefix(codep));                           \
    }




#define Init_Usr_File                                                       \
     Initialize_Usr();




#define End_Init_Tables                                                     \
    }
