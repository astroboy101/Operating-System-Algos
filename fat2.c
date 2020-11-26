#include<stdio.h>
#include<stdlib.h>
float *a;
float circle(float *r)
{
    *a=3.14*(*r)*(*r);
    return *a;
}
float square(float *r)
{   float *a;
    *a=(*r)*(*r);
    return *a;
}
float rectangle(float *a,float *b)
{   float *f;
    *f=(*a)*(*b);

    return *f;
}
main()
{ a=(float *)(malloc(sizeof(float)));
  int choice;
  float a1,b,r,*result;
  result=(float *)(malloc(sizeof(float)));
  do
  {
      printf("Area Option: \n");
      printf("1.Circle\n2.Square\n3.rectangle\n4.Exit\n");
      printf("enter your choice");
      scanf("%d",&choice);
      switch(choice)
      {
      case 1:
          printf("enter the length of radius : ");
          scanf("%f",&r);
          *result=circle(&r);
          printf(" hello :%f",*result);
          break;
    case 2:
          printf("enter the length of side : ");
          scanf("%f",&r);
          *result=square(&r);
          printf("%f",*result);
          break;
    case 3:
          printf("enter the length and breadth : ");
          scanf("%f %f",&a1,&b);
          *result=rectangle(&a1,&b);
          printf("%f",*result);
          break;


      }


  }while(choice!=4);
}
