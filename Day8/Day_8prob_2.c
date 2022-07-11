 Find out the value of T0PS2, T0PS1, T0PS0 bits in T0CON register if the value of the register is 0xF3



#include <stdio.h>

int main()
{
   int n=0xf3,x,i;
   for(i=2;i>=0;i--){
    x=(n>>i)&1;

   printf("%x",x);
   }
}
