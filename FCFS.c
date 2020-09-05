#include<stdio.h>
 struct process
 {
     float burst,arrival,waiting_time,comp;
 };
main()
{
int n,i,j;
float  avg=0,avg_turn=0;
printf("enter no of process");
scanf("%d",&n);
struct process p[n],temp;
for(i=0;i<n;i++)
{   printf("enter the burst time of process p[%d]\n",i);
    scanf("%f",&p[i].burst);
    printf("enter the arrival time of process p[%d]\n",i);
    scanf("%f",&p[i].arrival);
}
p[0].arrival=0;
p[0].waiting_time=0;
p[0].comp=p[0].burst;
avg_turn=p[0].comp;
printf("%s %s %s %s %s\n","Arrival","burst time","turn around","completion time","waiting_time");
i=0;
printf("%f %f %f %f %f\n",p[i].arrival,p[i].burst,p[i].comp-p[i].arrival,p[i].comp,p[i].waiting_time);
for(i=1;i<n;i++)
{
   p[i].comp=p[i-1].comp+p[i].burst;
   p[i].waiting_time=p[i].comp-p[i].arrival-p[i].burst;
   avg=avg+p[i].waiting_time;
   avg_turn=avg_turn+p[i].comp-p[i].arrival;
   printf("%f %f %f %f %f\n",p[i].arrival,p[i].burst,p[i].comp-p[i].arrival,p[i].comp,p[i].waiting_time);

}
avg=avg/n;
avg_turn=avg_turn/n;
printf("%f %f",avg,avg_turn);


}

