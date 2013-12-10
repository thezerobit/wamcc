/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* C Run-time                                           Daniel Diaz - 1994 */
/*                                                                         */
/* Hash tables Management                                                  */
/*                                                                         */
/* hash.c                                                                  */
/*-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>



#define HASH

#include "machine.h"
#include "wam_engine.h"




/*---------------------------------*/
/* Constants                       */
/*---------------------------------*/

#define HALF_WORD_SIZE             ((sizeof(int)>>1)*8)




/*---------------------------------*/
/* Type Definitions                */
/*---------------------------------*/
    
typedef struct
    {
     int tbl_size;
     int cell_size;
     int elem_size;
     int key_size;     /* -n if char [n], 0 if char *, or else sizeof(key) */
    }*Header;




typedef struct
    {
     unsigned int int1:HALF_WORD_SIZE;
     unsigned int int2:HALF_WORD_SIZE;
   }SplitInt;



/*---------------------------------*/
/* Global Variables                */
/*---------------------------------*/

/*---------------------------------*/
/* Function Prototypes             */
/*---------------------------------*/
static 
char     *Hash_Locate           (char *t,char *elem);

static 
int       Hash_Function         (int tbl_size,int key_size,char *elem);

static 
int       Hash_Same_Key         (int key_size,char *key1,char *key2);




/*-------------------------------------------------------------------------*/
/* HASH_TABLE                                                              */
/*                                                                         */
/* Allocates a hash table (calloc) of tbl_size elements. Each element needs*/
/* elem_size bytes and begins with the key whose size is key_size.         */
/* The key_size -n corresponds to char key[n] (i.e. -sizeof(key)).         */
/* The key_size 0 corresponds to char *key.                                */
/* The function returns a pointer to the table or NULL if calloc failed.   */
/*                                                                         */
/* The size of the table is rounded up to the next power of 2.             */
/* A cell consists of an indicator (int) an element (elem_size) and some   */
/* padding bytes s.t. elem_size+sizeof(int) >= sizeof(Header).             */
/* The first cell contains a Header (see Header type).                     */
/* The indicator is 0 for a never used cell (free cell), 1 for a data cell */
/* or -1 for a deleted cell (free cell).                                   */
/*-------------------------------------------------------------------------*/
char *Hash_Table(int tbl_size,int elem_size,int key_size)

{
 char  *t;
 Header h;
 int    i=1;
 int    cell_size;

 cell_size=(elem_size+sizeof(int) >= sizeof(*h)) ?
            elem_size+sizeof(int) :  sizeof(*h);       /* +1 for free word */

 while(i<tbl_size)                         /* round to the next power of 2 */
     i<<=1;
 tbl_size=i+1;                                       /* +1 for header cell */

 t=(char *) Lib2(calloc,tbl_size,cell_size);

 if (t==NULL)
     return NULL;

 h=(Header) t;

 h->tbl_size =tbl_size;
 h->cell_size=cell_size;
 h->elem_size=elem_size;
 h->key_size =key_size;

 return t;
}




/*-------------------------------------------------------------------------*/
/* HASH_DELETE_TABLE                                                       */
/*                                                                         */
/* This function deletes a hash table                                      */
/*-------------------------------------------------------------------------*/
void Hash_Delete_Table(char *t)

{
 Lib1(free,t);
}




/*-------------------------------------------------------------------------*/
/* HASH_TABLE_SIZE                                                         */
/*                                                                         */
/* This function returns the total size of the table                       */
/*-------------------------------------------------------------------------*/
int Hash_Table_Size(char *t)

{
 Header h=(Header) t;

 return h->tbl_size-1;
}




/*-------------------------------------------------------------------------*/
/* HASH_IS_AN_ELEMENT                                                      */
/*                                                                         */
/* This function returns 1 if elem is an element of t 0 otherwise          */
/*-------------------------------------------------------------------------*/
int Hash_Is_An_Element(char *t,char *elem)

{
 Header  h=(Header) t;
 char   *endt;
 int     n;

 endt=t+M_Mul(h->tbl_size,h->cell_size);

 elem-=sizeof(int);
 
 if (elem<t+h->cell_size || elem>=endt)
     return 0;

 n=elem-t;

 return (M_Mod(n,h->cell_size)==0);
}




/*-------------------------------------------------------------------------*/
/* HASH_LOOKUP                                                             */
/*                                                                         */
/* This function manages the elements of a hash table. t is a pointer to   */
/* the table, elem a pointer to an element and oper is the operation to    */
/* apply and can be:                                                       */
/*                                                                         */
/*   H_ADD     add elem to t if does not exist                             */
/*   H_CREATE  add elem to t (error if already exists)                     */
/*   H_UPDATE  like H_CREATE if the key does not exist else like H_REPLACE */
/*   H_REPLACE replace the information associated to the key               */
/*   H_FIND    search the element corresponding to the key passed in elem  */
/*   H_DELETE  delete the element corresponding to the key passed in elem  */
/*   H_NEXT    search the next element sequentially after elem             */
/*             or the first if elem==NULL                                  */
/*                                                                         */
/* The function returns a pointer to the element added/searched/deleted    */
/* or   -1 if: t is full (H_CREATE)                                        */
/* or NULL if: the key already exists (H_CREATE)                           */
/*             the key does not exist (H_REPLACE, H_FIND, H_DELETE)        */
/*             the end of the table is reached (H_NEXT)                    */
/*                                                                         */
/* example of use of H_NEXT:                                               */
/*                                                                         */
/* char *buff_ptr;                                                         */
/* for (buff_ptr=Hash_Lookup(t,NULL,H_NEXT);buff_ptr;                      */
/*      buff_ptr=Hash_Lookup(t,buff_ptr,H_NEXT))                           */
/*     Display_Element(buff_ptr);                                          */
/*-------------------------------------------------------------------------*/
char *Hash_Lookup(char *t,char *elem,int oper)

{
 Header  h=(Header) t;
 char   *cell,*endt;
 int    *used;
 char   *s,*d;
 int     n;

 if (oper==H_NEXT)
    {
     cell=(elem==NULL) ? t : elem-sizeof(int);
     endt=t+M_Mul(h->tbl_size,h->cell_size);
     for(cell += h->cell_size;cell<endt;cell += h->cell_size)
        {
         used=(int *) cell;
         if (*used==1)
             return (char *) (used+1);
        }
     return NULL;
    }

 if ((cell=Hash_Locate(t,elem))==NULL)
     return (oper<=H_UPDATE) ? (char *) -1 : NULL;

 used=(int *) cell;

 if (oper==H_UPDATE)
     oper=(*used==1) ? H_REPLACE : H_CREATE;
  else
     if (*used==1)
        {
         if (oper==H_CREATE)
             return NULL;
        }
      else
         if (oper>H_CREATE)
             return NULL;

 switch(oper)
    {
     case H_ADD:
         if (*used==1)
             break;

     case H_CREATE:
         *used=1;
         Lib3(memcpy,(char *) (used+1),elem,h->elem_size);
         break;

     case H_REPLACE:
         if ((n=h->key_size)<0)
             n= -n;
          else
             if (n==0)
                 n=sizeof(char *);

         s=elem+n;                               /* do not replace the key */
         d=(char *) (used+1)+n;
         Lib3(memcpy,d,s,h->elem_size-n);
         break;

     case H_DELETE:
         *used= -1;
         break;
    }


 return (char *) (used+1);
}




/*-------------------------------------------------------------------------*/
/* HASH_LOCATE                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static char *Hash_Locate(char *t,char *elem)

{
 Header  h=(Header) t;
 char   *cell,*endt,*w;
 int    *used;
 char   *cell_else=NULL;
 int     n;


 endt=t+M_Mul(h->tbl_size,h->cell_size);
 n=Hash_Function(h->tbl_size-1,h->key_size,elem)+1;     /* +1 since header */
 w=cell=t+M_Mul(n,h->cell_size);
 
 for(;;)
    {
     used=(int *) cell;
     if (*used==0)
         return (cell_else) ? cell_else : cell;   /* recove deleted cell ? */

     if (*used==1 && Hash_Same_Key(h->key_size,(char *) (used+1),elem))
         return cell;

     if (*used== -1 && cell_else==NULL)
         cell_else=cell;

     cell += h->cell_size;
     if (cell == endt)
         if (endt!=w && (cell=t+h->cell_size)!=w)
             endt=w;
          else
             break;
    }

    /* here the key is not found and no never used cell (*used==0) exists. */
    /* cell_else points to the first deleted cell (*used== -1) or NULL.    */

 return cell_else;
}




/*-------------------------------------------------------------------------*/
/* HASH_FUNCTION                                                           */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static int Hash_Function(int tbl_size,int key_size,char *elem)

{
 int       n;
 SplitInt *k;
 char      c;

 if (key_size<0)
     key_size= -1;

 switch(key_size)
    {
     case 0:
         elem= *((char **) elem);
     case -1:
         n=0;
         while(*elem)
            {
             c=*elem++;
             n=(n<<5)+(n<<6)+n+c-' ';                 /* i.e. n=n*97+c-spc */
            }
         break;

     case sizeof(int):
         k=(SplitInt *) elem;
         n=(k->int1)^(k->int2);
         break;

     default:
         n=0;
         do
            {
             c=*elem++;
             n=(n<<5)+(n<<6)+n+c;                         /* i.e. n=n*97+c */
            }
         while(--key_size);
    }


 return n & (tbl_size-1);
}




/*-------------------------------------------------------------------------*/
/* HASH_SAME_KEY                                                           */
/*                                                                         */
/*-------------------------------------------------------------------------*/
static int Hash_Same_Key(int key_size,char *key1,char *key2)

{
 int n;

 if (key_size<0)
     key_size= -1;

 switch(key_size)
    {
     case 0:
         key1= *((char **) key1);
         key2= *((char **) key2);
     case -1:
         n=Lib2(strcmp,key1,key2);
         return (n==0);

     case sizeof(n):
         return (*((int *) key1)== *((int *) key2));

     default:
         n=Lib3(memcmp,key1,key2,key_size);
         return (n==0);
    }
}




/*-------------------------------------------------------------------------*/
/* HASH_FAST_FIND_INT                                                      */
/*                                                                         */
/* This function fastly finds an integer key.                              */
/*-------------------------------------------------------------------------*/
char *Hash_Fast_Find_Int(char *t,int key)

{
 Header    h=(Header) t;
 char     *cell,*endt,*w;
 int      *used;
 int       n;
 SplitInt *k;

 endt=t+M_Mul(h->tbl_size,h->cell_size);

 k=(SplitInt *) &key;
 n=(k->int1)^(k->int2);

 n=(n & (h->tbl_size-2))+1;                             /* +1 since header */


 w=cell=t+M_Mul(n,h->cell_size);
 for(;;)
    {
     used=(int *) cell;

     if (*used==1 && used[1]==key)
         return (char *) (used+1);

     if (*used==0)
         break;

     cell += h->cell_size;
     if (cell == endt)
         if (endt!=w && (cell=t+h->cell_size)!=w)
             endt=w;
          else
             break;
    }

 return NULL;
}





/*-------------------------------------------------------------------------*/
/* HASH_DELETE_ALL                                                         */
/*                                                                         */
/* This function deletes all elements in the table.                        */
/*-------------------------------------------------------------------------*/
void Hash_Delete_All(char *t)

{
 Header h      =(Header) t;
 unsigned  size=M_Mul(h->tbl_size-1,h->cell_size);
 int      *p   =(int *) (t+h->cell_size);

 size/=sizeof(int);

 do
     *p++=0;
 while(--size);
}
