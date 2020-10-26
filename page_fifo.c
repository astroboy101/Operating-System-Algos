#include<stdio.h>
#include<string.h>
void page_replace(int n,char a[])
{
int no,i,j,hit=0,flag=0;
char check[n];
no=0;
for(i=0;a[i]!='\0';i++)
{
    for(j=0;j<n;j++)
    {
        if (a[i]==check[j])
        {

            hit++;
            flag=1;
            break;
        }
    }
       if (flag==0)
        {check[no]=a[i];
        no=(no+1)%n;}
        flag=0;

        for(j=0;j<n;j++)
        {
            if (check[j]!='\0')
            printf("%c ",check[j]);
            else
                printf(" ");
        }
        printf("\n");

}
printf(" no of hits :%d\n",hit);
printf("no of page faults : %d",strlen(a)-hit);
}
main()
{
    int size;
    printf("Enter the size of the page table");
    scanf("%d",&size);
    char table[size],k[100];
    printf("enter the process sequence as a string");
    scanf("%s",k);
   // printf("commit---\n");
    page_replace(size,k);

}
