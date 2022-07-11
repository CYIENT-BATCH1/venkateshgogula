Set the register T0CON value such a way that bit TMR0ON and PSA bit are set (1), without disturbing the other bits.
#include<stdio.h>

int main(){
    int n=0x12;
    int pos=3;
    int pos1=7;
    n=n|(1<<pos)|(1<<pos1);
    
    printf("%x",n);
}
