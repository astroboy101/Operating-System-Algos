#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{   int i=0;
    char *f,*l,k[100],f1[100];
    printf("enter the string");
    scanf("%s",k);
    l=&k;
    f=l;
    while(*f!='\0')
        f++;
    f--;
    while(*f!=0)
    {   if(*f>='A' && *f<='Z')
        f1[i]=*f;
        i++;
        f--;

    }
    printf("%s",f1);

}
