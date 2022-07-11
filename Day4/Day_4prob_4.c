1) SWAPPING OF TWO NUMBERS WITH USING THIRD VARIABLE




#include <stdio.h>



int main()
{
int a,b,k;
printf("enter the value a,b");
scanf("%d %d",&a,&b);
k=a;
a=b;
b=k;
printf("%d %d",a,b);
}
