Write program to set (1) bits CIS, C2OUT, C1OUT in register “CMCON” if bits CHS3, CHS2, CHS1 bits are
 set to 0x06 in register “ADCON0”

Algorithm:
1.Instilize and declare the varables.
2)We want to set CHS2, CHS1, CHS0 bits are set to 0x06 in register “ADCON0”
      -->right 2times should be equal to this bits CHS3, 
3)After that you can do  right shift with above register so this bits are in set the requirement
4)To take the output.
#include<stdio.h>
int main()
   {
    int num1=0x2f; //0010 1111
    int num2=0x2a; //0010 1010
    num1=num1>>2;
    if(num1==0x06){
        num2|=((1<<7)|(1<<6)|(1<<3));
        printf("%x",num2);
    }
   }
