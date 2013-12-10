
#include <stdio.h>
#include <ctype.h>


#define Num(c)  (isdigit(c) ? (c)-'0' : isupper(c) ? (c)-'A'+10 : (c)-'a'+10)

main(int argc,char *argv[])

{
 char  name[128];
 char *p;

 if (argc==2)
     p=argv[1];
  else
    {
     p=name;
     printf("Prolog Name :");
     scanf("%s",p);
    }

 printf("<X");

 while(*p)
    {
     if (*p=='/')
        {
         printf("_%s",p+1);
         break;
        }

     printf("%2X",*p);
     p++;
    }

 printf(">\n");

 return 0;
}
