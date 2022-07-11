 I). Set the register SSPSTAT value such a way that bit CKE, P and S bit are cleared (0), without disturbing the other bits.

II). Find out the value of UA, BF, SMP bits in SSPSTAT register if the value of the register is 0x55
Algorithm:
1.Instilize and daclare the variables.
2)If we want the first requirement  to take right bit position times should be equal to this bits 
UA, BF, SMP bits in SSPSTAT register if the value of the register is 0x55
4)After that we can do  right shift with this register to get the bits clear CKE, P and S  so this bits are in clear the requirement.
5)Take the o/p.
  
  
#include<stdio.h>
int main()
   {
    int num1,num2;//num1=0001 1100,default you can take num2 as 0x55 
    int num2=0x55;
printf("%d%d",num1,num2);
scanf("%d%d",&num1,&num2);
        num1&=~((1<<3)|(1<<4)|(1<<6)); //1 requirement in qustion no.7
         printf("%x\n",num1);
    printf("%x %x %x",(num2>>7)&1,(num2>>1)&1,(num2>>0)&1);   //2 requirement in qustion no.7

   }
