/*-------------------------------------------------------------------------*/
/* Prolog To Wam Compiler                INRIA Rocquencourt - CLoE Project */
/* C Run-time                                           Daniel Diaz - 1994 */
/*                                                                         */
/* Builtins - Header file                                                  */
/*                                                                         */
/* builtin.h                                                               */
/*-------------------------------------------------------------------------*/

/*---------------------------------*/
/* Constants                       */
/*---------------------------------*/

/*---------------------------------*/
/* Type Definitions                */
/*---------------------------------*/

/*---------------------------------*/
/* Global Variables                */
/*---------------------------------*/

          /* from dec10io.h */

extern FILE *input;
extern char  input_name[];
extern FILE *output;
extern char  output_name[];




/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/

void      Simple_Write_Term     (WamWord start_word);

void      Complex_Write_Term    (FILE *out,int depth,
                                 Bool quote,Bool op,Bool number_vars,
                                 WamWord start_word);

WamWord   Read_Term             (FILE *in);

int       Compare_Term          (WamWord start_u_word,WamWord start_v_word);




          /* Test type inlines */

Bool      Blt_1_var             (WamWord x);
Bool      Blt_1_nonvar          (WamWord x);
Bool      Blt_1_atom            (WamWord x);
Bool      Blt_1_integer         (WamWord x);
Bool      Blt_1_number          (WamWord x);
Bool      Blt_1_atomic          (WamWord x);
Bool      Blt_1_compound        (WamWord x);


Bool      Blt_3_arg             (WamWord word_indice,WamWord word_term,
                                 WamWord sub_term);
Bool      Blt_3_functor         (WamWord word_term,WamWord word_functor,
                                 WamWord word_arity);
Bool      Blt_2_term_univ       (WamWord u_word,WamWord v_word);




          /* Term comparison inlines */

Bool      Blt_3_compare         (WamWord word_cmp,WamWord x,WamWord y);

#define Blt_2_term_eq(x,y)         (Term_Compare(x,y)==0)
#define Blt_2_term_neq(x,y)        (Term_Compare(x,y)!=0)
#define Blt_2_term_lt(x,y)         (Term_Compare(x,y)< 0)
#define Blt_2_term_lte(x,y)        (Term_Compare(x,y)<=0)
#define Blt_2_term_gt(x,y)         (Term_Compare(x,y)> 0)
#define Blt_2_term_gte(x,y)        (Term_Compare(x,y)>=0)




          /* Math expression inlines (math on integers as macros) */

#define Fct_1_neg(x)               (-x)
#define Fct_1_inc(x)               (x+Tag_Value(INT,1))
#define Fct_1_dec(x)               (x-Tag_Value(INT,1))
#define Fct_2_add(x,y)             (x+y)
#define Fct_2_sub(x,y)             (x-y)
#define Fct_2_mul(x,y)             (M_Mul(x,(y>>TAG_SIZE)))
#define Fct_2_div(x,y)             (M_Div(x,y)<<TAG_SIZE)
#define Fct_2_mod(x,y)             (M_Mod(x,y))
#define Fct_2_and(x,y)             (x&y)
#define Fct_2_or(x,y)              (x|y)
#define Fct_2_xor(x,y)             (Tag_INT(UnTag_INT(x)^UnTag_INT(y)))
#define Fct_1_not(x)               ((~x)-((1<<TAG_SIZE)-1))
#define Fct_2_shl(x,y)             (x<<UnTag_INT(y))
#define Fct_2_shr(x,y)             (Tag_INT(UnTag_INT(x) >> UnTag_INT(y)))


Bool      Load_Math_Expression  (WamWord exp,WamWord *result);


          /* Math comparison inlines */

#define Blt_2_eq(x,y)              (x==y)
#define Blt_2_neq(x,y)             (x!=y)
#define Blt_2_lt(x,y)              (x< y)
#define Blt_2_lte(x,y)             (x<=y)
#define Blt_2_gt(x,y)              (x> y)
#define Blt_2_gte(x,y)             (x>=y)




          /* Global variable inlines */

#define Blt_2_g_assign(x,y)        G_Assign(x,y,FALSE,TRUE)
#define Blt_2_g_assignb(x,y)       G_Assign(x,y,TRUE,TRUE)
#define Blt_2_g_link(x,y)          G_Assign(x,y,TRUE,FALSE)
#define Blt_2_g_read(x,y)          G_Read(x,y)
#define Blt_2_g_array_size(x,y)    G_Array_Size(x,y)
