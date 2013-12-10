/*-------------------------------------------------------------------------*/
/* Prolog To Wam Compiler                INRIA Rocquencourt - CLoE Project */
/* C Run-time                                           Daniel Diaz - 1994 */
/*                                                                         */
/* Machine Dependent Features - Header file                                */
/*                                                                         */
/* machine.h                                                               */
/*-------------------------------------------------------------------------*/

/*---------------------------------*/
/* Machine Type (for configure.c)  */
/*---------------------------------*/

#ifdef CONFIGURE

#   if defined(sparc)

#      define M_MACHINE            "sparc"
#      define M_sparc

#   elif defined(__mips__) && defined(sony_news)

#      define M_MACHINE            "sony_news"
#      define M_sony_news

#   elif defined(__mips__) && defined(ultrix)

#      define M_MACHINE            "dec_ultrix"
#      define M_dec_ultrix

#   elif defined(__linux__)

#      define M_MACHINE            "pc_linux"
#      define M_pc_linux

#   endif

#endif




/*---------------------------------*/
/* Gcc Specific Options            */
/*---------------------------------*/

#if defined(M_sony_news) || defined(M_dec_ultrix)

#    define EXTRA_CFLAGS           "-fomit-frame-pointer"

#elif defined(pc_linux)

#    define EXTRA_CFLAGS           "-m486"

#else

#    define EXTRA_CFLAGS           ""

#endif




/*---------------------------------*/
/* Asm Labels, Symbols and Gotos   */
/*---------------------------------*/

#if defined(M_sony_news) || defined(M_dec_ultrix)

#   define M_Asm_Symbol1(name)     #name
#   define M_Asm_Symbol(name)      M_Asm_Symbol1(name)

#else

#   define M_Asm_Symbol1(name)     "_"#name
#   define M_Asm_Symbol(name)      M_Asm_Symbol1(name)

#endif




#define M_Decl_Global_Label(name)  asm(".globl " M_Asm_Symbol(name));
#define M_Def_Label(name)          asm(M_Asm_Symbol(name) ":");




#if defined(M_sparc) || defined(M_dec_ultrix) || defined(M_sony_news)

#    define M_Direct_Goto(lab)     {lab(); return;}
#    define M_Indirect_Goto(p_lab) {(* ((void (*)()) p_lab))();return;}

#elif defined(M_pc_linux)

int lab_adr;

#    define M_Direct_Goto(lab)     {asm("jmp " M_Asm_Symbol(lab));return;}
#    define M_Indirect_Goto(p_lab) {lab_adr=(int) p_lab;                    \
                                    asm("movl _lab_adr,%eax");              \
                                    asm("jmp *%eax"); return;}

#endif




/*---------------------------------*/
/* Register Definitions            */
/*---------------------------------*/

#if defined(M_sparc) && !defined(NO_REGS)

#    define M_USED_REGS            {"g1","g2","g3","g4","g5","g6","g7",0}
#    define M_SAVE_REGS_BEFORE_LIB_C_CALLS


#elif (defined(M_dec_ultrix) || defined(M_sony_news)) && !defined(NO_REGS)

#    define M_USED_REGS            {"s0","s1","s2","s3","s4","s5","s6","s7",\
                                    0}

#else

#    define M_USED_REGS            {0}

#endif




          /* C library calls default macros */


#ifdef M_SAVE_REGS_BEFORE_LIB_C_CALLS

#    define Lib_CallD               (* ((double (*)()) Lib_Call))

     int    Lib_Call();

#    define Lib0(f)                 Lib_Call(f)
#    define Lib1(f,a1)              Lib_Call(f,a1)
#    define Lib2(f,a1,a2)           Lib_Call(f,a1,a2)
#    define Lib3(f,a1,a2,a3)        Lib_Call(f,a1,a2,a3)
#    define Lib4(f,a1,a2,a3,a4)     Lib_Call(f,a1,a2,a3,a4)
#    define Lib5(f,a1,a2,a3,a4,a5)  Lib_Call(f,a1,a2,a3,a4,a5)


#    define LibD0(f)                Lib_CallD(f)               
#    define LibD1(f,a1)             Lib_CallD(f,a1)            
#    define LibD2(f,a1,a2)          Lib_CallD(f,a1,a2)         
#    define LibD3(f,a1,a2,a3)       Lib_CallD(f,a1,a2,a3)      
#    define LibD4(f,a1,a2,a3,a4)    Lib_CallD(f,a1,a2,a3,a4)   
#    define LibD5(f,a1,a2,a3,a4,a5) Lib_CallD(f,a1,a2,a3,a4,a5)

#else

#    define Lib0(f)                 f()
#    define Lib1(f,a1)              f(a1)
#    define Lib2(f,a1,a2)           f(a1,a2)
#    define Lib3(f,a1,a2,a3)        f(a1,a2,a3)
#    define Lib4(f,a1,a2,a3,a4)     f(a1,a2,a3,a4)
#    define Lib5(f,a1,a2,a3,a4,a5)  f(a1,a2,a3,a4,a5)

#    define LibD0(f)                f()
#    define LibD1(f,a1)             f(a1)
#    define LibD2(f,a1,a2)          f(a1,a2)
#    define LibD3(f,a1,a2,a3)       f(a1,a2,a3)
#    define LibD4(f,a1,a2,a3,a4)    f(a1,a2,a3,a4)
#    define LibD5(f,a1,a2,a3,a4,a5) f(a1,a2,a3,a4,a5)

#endif




/*---------------------------------*/
/* Stacks Management               */
/*---------------------------------*/

#if defined(M_sparc) || defined(M_pc_linux)

#   define M_USE_MMAP
#   define M_MMAP_HIGH_ADR         0x0ffff000
#   define M_Check_Stacks()

#elif defined(M_dec_ultrix)

#   define M_USE_SHM
#   define M_SHM_HIGH_ADR          0x0ffff000
#   define M_Check_Stacks()

#else

#   define M_USE_MALLOC
#   define M_Check_Stacks()       M_Check_Magic_Words()

#endif




#if defined(M_USE_MALLOC) || defined(M_pc_linux)

#   define M_USE_MAGIC_NB_TO_DETECT_STACK_NAME
    void   M_Check_Magic_Words(void);

#endif

#define M_SECURITY_MARGIN          128                      /* in WamWords */
#define M_MAGIC                    0x12345678




/*---------------------------------*/
/* Mul, Div and Rem                */
/*---------------------------------*/

#ifdef M_sparc

    double fmod(double x,double y);

#   define M_Mul(x,y)   ((int) ((double) (x) * (y)))
#   define M_Div(x,y)   ((int) ((double) (x) / (y)))
#   define M_Mod(x,y)   ((x) - M_Mul(M_Div((x),(y)),(y)))

#else

#   define M_Mul(x,y)   ((x) * (y))
#   define M_Div(x,y)   ((x) / (y))
#   define M_Mod(x,y)   ((x) % (y))

#endif




/*---------------------------------*/
/* Miscellaneous (compatibility)   */
/*---------------------------------*/

#if defined(M_sony_news) || defined(M_dec_ultrix)

#   define strdup(s)  strcpy(malloc(strlen(s)+1),s)

#endif




/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/
void      M_Allocate_Stacks     (void);
