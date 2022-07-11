1.Write a program to convert a data stream from Little Endian to Big Endian
/*Algorithm

1.Declare a variable "a" and assign any 8 bit value.
2.Using bit wise operaters first right shift the value of "a".
3.Use logical "and"operator with variable "a" and left shift the vlue.
4.Use logical "or" operator concatenate the right and left shift values.
5.check the result */
Program:

#include <stdio.h>
int main()
{
 int a=0x12;
 a=(a>>4)|((a&0x0f)<<4);
printf("%x",a);
}
