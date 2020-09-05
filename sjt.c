#include<stdio.h>
struct process{
int pro_no;
float arrival,burst;
};
float sjf(struct process p[],int n,int max)
{  int gg=-1,max1=max;
   int i,j;;
   float arrival=0;
   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
           if(p[j].arrival<=arrival && p[j].arrival!=-1)
           {
               if (p[j].burst<=max)
               {
                   max=p[j].burst;
                   gg=j;
               }

           }


       }
       if(gg==-1)
        arrival++;
        else{
       arrival=arrival+p[gg].burst;
       p[gg].arrival=-1;
       max=max1;
       printf("%d\n",p[gg].pro_no);
       gg=-1;
        }
   }

}
main()
{
    int n,i,bur=0;
    scanf("%d",&n);
    struct process p[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i].pro_no);
        scanf("%f",&p[i].arrival);
        scanf("%f",&p[i].burst);
        bur=bur+p[i].burst;
    }
    sjf(p,n,bur);
}
