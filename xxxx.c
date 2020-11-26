#include<stdio.h>
main()
{
    int n,k;
    printf("enter the size of page frame :");
    scanf("%d",&n);
    //given the possible blocks are from 1 to 1000 page frames;
    //The contiguos memory allocated is
    printf("enter the size of memory allocated :");
    scanf("%d",&k);
    printf("therefore no of pages is :");
    int pages=k/n+1;
    printf("%d",pages);
}
