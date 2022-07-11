2. Write a code to swap even bits with odd bits in unsigned long variable(uint64).
Example: bit 0 with bit 1; bit 2 with bit 3; bit 4 with bit
/*Algorithm
1.scan the variables
2.To check and convert even into odd with above example formate
3.To swap the even into odd with bits
4.Take one tempararory variable and store as evenbit|oddbit.
5.Take the o/p

Program:
#include <stdio.h>
 int main()
{
    unsigned int x;
    printf("enter as number");
    scanf("%u",&x);
    unsigned  int evenbit=x&0xAAAAAAAAAAAAAAAA;
    unsigned int oddbit=x&0x5555555555555555;
    evenbit=evenbit>>1;
    oddbit=oddbit<<1;
    x=evenbit|oddbit;
    printf("%u",x);
}
