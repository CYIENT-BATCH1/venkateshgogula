3. Write program to clear(0) bits CIS, CM2, CM1, CM0 in register “CMCON” if bits CHS3, CHS2, CHS1, CHS0 bits are set to 0x07
 in register “ADCON0”
Image label

Image label

/*Algorithm
1.scan the registers
2.convert the registers bytes into binary
3.iterate the registers
4.write the o/p.
Program:
int main()
{
    char ADCON0bits_t, CMCONbits_t,i;

    ADCON0bits_t = 0x3C; //Intialize with 0x3C
    CMCONbits_t = 0x02;//Intialize with 0x02

   for(i=7;i>=0;i--)
        printf("%d", (ADCON0bits_t>>i)&1);
    puts("");
   if(((ADCON0bits_t>>2)&(0x0F)) == 0x07)
                CMCONbits_t = 0xF0;
   for(i=7;i>=0;i--)
        printf("%d", (CMCONbits_t>>i)&1);

    return 0;
}

