#include<stdio.h>
int semaphore=1,empty=10,full=0;//buffer
buffer_size=10;
struct process
{
    int pid;

} a[10],wait_line[100],pdum;
int top=-1,in=0,out=0;
int up(int k)
{
   return ++k;
}
int down(int k)
{
     return --k;
}
void producer(struct process p,int i)
{
    empty=down(empty);
    semaphore=down(semaphore);
    if(semaphore>=0)
    {
        a[in]=p;
        printf("producer %d inserted the process pid %d in buffer\n",i,p.pid);
        full=up(full);
    }
    in=up(in);
    in=in%buffer_size;
    semaphore=up(semaphore);

}
void consumer(int i)
{pdum.pid='\0';
    full=down(full);
    semaphore=down(semaphore);
    if(semaphore>=0 && empty!=buffer_size)
    {
        printf("the process pid %d is out from buffer\n",a[out].pid);
        a[out]=pdum;
    }
    empty=up(empty);
    out=up(out);
    semaphore=up(semaphore);
}
main()
{
int k,i;
printf("1.producer\n2.consumer\n3.exit\n");
int g,k1,n1=0,i1=0;
do
{struct process p;
    printf("----------%d---------%d-----------\n",empty,full);
     printf("enter your operation:");
    scanf("%d",&g);

    switch(g)
    {
    case 1:
        printf("enter the process pid ");
        scanf("%d",&p.pid);
        printf("enter the producer number");
        scanf("%d",&k1);
        if(empty>0)
            producer(p,k1);

        else
            {printf("the buffer is full %d\n",empty);
            top=(top+1)%buffer_size;
            wait_line[top]=p;
        }

        break;
    case 2:
        printf("enter the consumer number");
        scanf("%d",&k1);
        if(full>0)
            {
                consumer(k1);
                if(top>=0)
                {
                    producer(wait_line[top],k1);
                    top=(top+1)%buffer_size;
                }
            }
        else
            printf("the buffer is empty %d \n",empty);
        break;
    }
    printf("\n------------------------\n");
    printf("buffer values");
    for(i=0;i<buffer_size;i++)
    {
        if (a[i].pid=='\0')
            printf("empty\n");
        else
            printf("%d---%d\n",i,a[i].pid);
    }
}while(g!=3);
}


