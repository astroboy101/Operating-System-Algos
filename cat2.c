#include<stdio.h>
void firstfit(int blocksize[],int m,int processsize[],int n)
{
int allocation[n],i,j;
for(i=0;i<n;i++)
{
        allocation[i]=-1;
}
for(i=0;i<n;i++)
{
        for(j=0;j<m;j++)
        {
                if(blocksize[j]>processsize[i])
                {
                        allocation[i]=j;
                        blocksize[j]-=processsize[i];
                        break;
                }
        }
}
printf("\nProcess No.\tProcess Size\tBlock No.\n");

for(i=0;i<n;i++)
{
        printf(" %d \t\t%d\t\t",i+1,processsize[i]);
        if(allocation[i]==-1)
                printf("No memory allocated\n");
        else
                printf("%d\n",allocation[i]+1);

}
printf("\nBlock Status\n");
for(i=0;i<m;i++)
{
        printf("B%d remaining is %d\n",i+1,blocksize[i]);
}
};
void bestfit(int blocksize[],int m,int processsize[],int n)
{
int allocation[n],i,j,best;
for(i=0;i<n;i++)
{
                allocation[i]=-1;
}
for(i=0;i<n;i++)
{
best=-1;
for(j=0;j<m;j++)
{
if(blocksize[j]>processsize[i])
{
        if(best==-1)
                best=j;
        else if(blocksize[best]>blocksize[j])
                best=j;

}
}
allocation[i]=best;
if(best!=-1)
{
        blocksize[best]-=processsize[i];
}
}

printf("\nProcess No.\tProcess Size\tBlock No.\n");

for(i=0;i<n;i++)
{
                printf(" %d \t\t%d\t\t",i+1,processsize[i]);
                 if(allocation[i]==-1)
                                        printf("No memory allocated\n");
                 else
                                       printf("%d\n",allocation[i]+1);

}
printf("\nBlock Status\n");
for(i=0;i<m;i++)
{
        printf("B%d remaining is %d\n",i+1,blocksize[i]);
}
};
void worstfit(int blocksize[],int m,int processsize[],int n)
{
int allocation[n],i,j,worst;
for(i=0;i<n;i++)
{
                        allocation[i]=-1;
}
for(i=0;i<n;i++)
{
        worst=-1;
                for(j=0;j<m;j++)
        {
                if(blocksize[j]>processsize[i])
                {
                                if(worst==-1)
                                worst=j;
                    else if(blocksize[worst]<blocksize[j])
                        worst=j;

                }
        }
        allocation[i]=worst;
        if(worst!=-1)
        {
                        blocksize[worst]-=processsize[i];
        }
}

printf("\nProcess No.\tProcess Size\tBlock No.\n");

for(i=0;i<n;i++)
{
                        printf(" %d \t\t%d\t\t",i+1,processsize[i]);
                            if(allocation[i]==-1)
                                   printf("No memory allocated\n");
                      else
                                 printf("%d\n",allocation[i]+1);

}
printf("\nBlock Status\n");
for(i=0;i<m;i++)
{
                printf("B%d remaining is %d\n",i+1,blocksize[i]);
}
};
int main()
{
        int m,n,i,j,option;
printf("Enter number of blocks: ");
scanf("%d",&m);
printf("Enter number of processes: ");
scanf("%d",&n);
printf("Enter each block size: ");
int blocksize[m],processsize[n];
for(i=0;i<m;i++)
{
scanf("%d",&blocksize[i]);
}
printf("Enter Process size: ");
for(i=0;i<n;i++)
{
        scanf("%d",&processsize[i]);
}
printf("Enter your option\n1.first fit\n2.best fit\n3.worst fit\n");
scanf("%d",&option);
switch(option)
{
        case 1:
                firstfit(blocksize,m,processsize,n);
                break;
        case 2:
                        bestfit(blocksize,m,processsize,n);
                        break;
        case 3:
                        worstfit(blocksize,m,processsize,n);
                        break;


}

return 0;
}
