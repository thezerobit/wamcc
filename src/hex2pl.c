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
     printf("Hexa Name :");
     scanf("%s",p);
    }

 while(!isxdigit(*p))
     p++;

 printf("<");

 while(*p)
    {
     if (*p=='_')
        {
         printf("/%s",p+1);
         break;
        }

     printf("%c",Num(*p)*16+Num(p[1]));
     p+=2;
    }

 printf(">\n");

 return 0;
}
