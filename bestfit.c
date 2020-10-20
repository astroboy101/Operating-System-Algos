#include<stdio.h>
struct process_block
{   int process_no;
    int block_no;
    int process_size;
    int block_size;
    int flag;
};
main()
{
    int min,no,i,pcount,j,count=0,flag1=0,temp_mem,temp,k;
    printf("enter no of blocks in main memory");
    scanf("%d",&no);
    int allocate[no],mem_block[no];

    printf("enter the each block size : \n");
    for(i=0;i<no;i++)
    {
        printf("enter the %d.block size : ",i);
        scanf("%d",&mem_block[i]);
        allocate[i]=mem_block[i];
    }
    printf("enter no of process :");
    scanf("%d",&pcount);
    struct process_block process[pcount],temp1;
    for(i=0;i<pcount;i++)
    {
        printf("enter the size of the process %d :",i);
        scanf("%d",&process[i].process_size);
        process[i].flag=0;
    }
    for(i=0;i<pcount;i++){
            min=9999999;
     for(j=0;j<no;j++)
        {
            temp_mem=allocate[j];
            if (process[i].process_size<=temp_mem && temp_mem<min)
            {
                temp=j;
                flag1=1;
                min=temp_mem;

            }
        }
            if(flag1==1){
            count++;
            flag1=0;
            process[i].process_no=i;
            process[i].flag=1;
            process[i].block_size=mem_block[temp];
            process[i].block_no=temp;
            allocate[temp]=allocate[temp]-process[i].process_size;
            }
            if (count==no)
                break;
    }
    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size");
    for(i=0;i<pcount;i++)
    {

        temp1=process[i];
        if (temp1.flag==1)
        printf("\n%d\t\t%d\t\t%d\t\t%d\n",i,temp1.process_size,temp1.block_no,temp1.block_size);
    }
}

