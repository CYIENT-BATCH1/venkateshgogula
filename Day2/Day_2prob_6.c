6.Write a program to convert Celsius form of temperature into Fahrenheit and vice versa. 
#include <stdio.h>

int main()
{
   int f,c,t;
   scanf("%f",&c);
   f=c*9/5+32;
   c=5/9*(f-32);
   printf("convert Celsius to Fahrenheit %f\n",f);
   printf(" convert Fahrenheit to Celsius  %f\n",c);
}
