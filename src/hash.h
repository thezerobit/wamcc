/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* C Run-time                                           Daniel Diaz - 1994 */
/*                                                                         */
/* Hash Tables Management - Header file                                    */
/*                                                                         */
/* hash.h                                                                  */
/*-------------------------------------------------------------------------*/

/*---------------------------------*/
/* Constants                       */
/*---------------------------------*/

#define H_ADD                      0
#define H_CREATE                   1
#define H_UPDATE                   2
#define H_REPLACE                  3
#define H_FIND                     4
#define H_DELETE                   5
#define H_NEXT                     6




/*---------------------------------*/
/* Type Definitions                */
/*---------------------------------*/

/*---------------------------------*/
/* Global Variables                */
/*---------------------------------*/

/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/

char     *Hash_Table            (int tbl_size,int elem_size,int key_size);
char     *Hash_Create_Copy_Table(char *t,int new_tbl_size);
void      Hash_Delete_Table     (char *t);
int       Hash_Table_Size       (char *t);
int       Hash_Is_An_Element    (char *t,char *elem);
char     *Hash_Lookup           (char *t,char *elem,int oper);
char     *Hash_Fast_Find_Int    (char *t,int key);
void      Hash_Delete_All       (char *t);



