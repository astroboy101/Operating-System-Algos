#include<stdio.h>
#include<stdlib.h>
struct process
{
    float arrival,burst_time;
};
int main()
{
    int n,m;
    printf("enter no of process: ");
    scanf("%d",&n);
    printf("enter no of resource type");
    scanf("%d",&m);
    int max[m],i,sum[m],p[n];
    struct process p1[n];
    //printf("Enter arrival time and burst time of the process\n");
    //for(i=0;i<n;i++)
    //{
      //  scanf("%d %d",&p1[i].arrival,&p1[i].burst_time);
    //}
    printf("\nenter maximum number of each resource: ");
    for(i=0;i<m;i++)
    scanf("%d",&max[i]);
    int allocated[n][m],j,k,max_need[n][m],available[n][m];
    printf("enter no of resources of each type are allocated to the process\n");
    for(i=0;i<m;i++)
    printf("resource-%d\t",i);
    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
                scanf("%d",&allocated[i][j]);
    }
    printf("enter the max no of each resource type needed for each process\n");
     for(i=0;i<m;i++)
    printf("resource-%d\t",i);
    printf("\n");
     for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            {
                scanf("%d",&max_need[i][j]);
            }
    }

   for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            {
                available[i][j]= max_need[i][j]-allocated[i][j];
                printf("%d\t",available[i][j]);
            }
            printf("\n");
    }
    for(i=0;i<m;i++)
    {
        sum[i]=0;
        for(j=0;j<n;j++)
            {
                sum[i]=sum[i]+allocated[j][i];
            }
            sum[i]=max[i]-sum[i];
    }
    int flag=0,total=0,index=0,prop=0,gg=0;
    while(total<n)
    {
        for(j=0;j<m;j++)
        {
            if(available[index][j]<=sum[j]&&available[index][j]>=0)
                flag++;
            else
                break;
        }

        if (flag==m)
        {
            for(j=0;j<m;j++)
            {sum[j]=sum[j]+allocated[index][j];
            available[index][j]=-1;
            }
            total++;
            p[prop]=index;
            prop++;
            flag=0;
            gg=0;
            printf("\n");
        }
        if(gg>=n)
        {

            printf("It is unsafe state");
            exit(0);
        }
        gg++;
        index++;
        index=index%n;
    }
    for(i=0;i<n;i++)
        printf("P%d  ",p[i]);


}

