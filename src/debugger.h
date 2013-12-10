/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* C Run-time                                           Daniel Diaz - 1994 */
/*                                                                         */
/* Prolog/Wam Debugger - Header file                                       */
/*                                                                         */
/* debugger.h                                                              */
/*-------------------------------------------------------------------------*/
#include "bool.h"

/*---------------------------------*/
/* Constants                       */
/*---------------------------------*/

/*---------------------------------*/
/* Type Definitions                */
/*---------------------------------*/

/*---------------------------------*/
/* Global Variables                */
/*---------------------------------*/

/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/

void      Init_Debugger         (void);
Bool      Debug_Set_Mode        (AtomInf *mode);
AtomInf  *Debug_Get_Mode        (void);

void      Debug_Clause          (void);
void      Debug_Body            (void);
void      Debug_Call            (char *name,int arity,int debug_level);
void      Debug_Proceed         (Bool from_dynamic);
void      Debug_Fail            (void);

void      Debug_Dynamic_Body    (void);
void      Debug_Has_Failed_Redo (void);

void      Debug_Pred            (char *name,int arity);
void      Debug_Sub_Pred        (char *name,int arity);
void      Debug_Retry           (void);

void      Debug_Wam_Inst        (char *format,...);

void      Debug_Display_Infos   (void);
void      Debug_Display_Mode    (void);
void      Debug_Display_Leashing(void);
void      Debug_Display_Exact   (void);
Bool      Debug_Add_Leash_Mode  (AtomInf *leash_mode);
void      Debug_Add_Spy_Point   (AtomInf *atom,int arity);

void      Debug_Remove_Spy_Point(AtomInf *atom,int arity);
