Assume that we have a car with 8 seats, and we are monitoring 8 seat belt status in a variable “G_Msg_switchstatus_Byte[]” as shown 
in pic1. Each switch status is combination of 2 bits as shown in pic2.
Write status of switches into variable “G_Msg_switchstatus_Byte[]” as below.
SWITCH1, SWITCH7 status is “faulty type 1 in switch”, SWITCH2, SWITCH5 status is ”switch unbuckle”, SWITCH3, SWITCH6 status is 
“switch buckle”, SWITCH4, SWITCH0 status is “faulty type 2 in switch” without disturbing the other bits.
Switch status valueMeaning
00 Fault type 1 in switch
01 switch is buckle
10 switch is unbuckle
11 Fault type 2 in switch
Algorithm:
1)Declare the variables depend on table
2) You have four different requirements then we are using switch case
3)Each case having some iterations (for loop) to check register until the first requirement satisfying. 
4)Repeat the steps for every register and every case.
5)Take which requirement you want.

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x,switch_status=0x00;
    int fault,f,n,n1,n2,reg0,reg1,reg2,i,faulty_type;
    int faulty_type1=1;
    int reg1_unbuckle=2;
    int buckle=3;
    int faulty_type2=4;
    int num;
    printf("enter the fault\n");
    fflush(stdout);
    scanf("%d",&num);
    switch(num){
    case 1:
        reg0=switch_status|((1<<0)|(1<<1)); 
          reg1=switch_status&(0x00);        // reg1 and reg2 are fault type1 and 0,1,4,5 bits set to 1
        reg2=switch_status|((1<<5)|(1<<4));
        for(i=7;i>=0;i--){
            n=(reg0>>i)&1;
            printf("%x",n);
        }
        n2=0x00;
        printf("\n");
               for(i=7;i>=0;i--){
                printf("%x",n2);
           }
           printf("\n");

        for(i=7;i>=0;i--){
               n1=(reg2>>i)&1;
               printf("%x",n1);
        }
               break;
        case 2:
        reg0=switch_status&(0x00);
        reg1=switch_status|((1<<7)|(1<<6)|(1<<0)|(1<<1));
        reg2=switch_status&(0x00);
        n=0x00;
        for(i=7;i>=0;i--){
            n=(reg0>>i)&1;
            printf("%x",n);
        }
        printf("\n");
               for(i=7;i>=0;i--){
                   n1=(reg1>>i)&1;
                printf("%x",n1);
           }
           printf("\n");
        for(i=7;i>=0;i--){
               n2=(reg2>>i)&1;
               printf("%x",n2);
        }
               break;
        case 3:
        reg0=switch_status&(0x00);
        reg1=switch_status|((1<<4)|(1<<5));
        reg2=switch_status|((1<<7)|(1<<6));
        n=0x00;
        for(i=7;i>=0;i--){
               n=(reg0>>i)&1;
               printf("%x",n);
        }
        printf("\n");
        for(i=7;i>=0;i--){
            n1=(reg1>>i)&1;
            printf("%x",n1);
        }
        printf("\n");
               for(i=7;i>=0;i--){
                   n2=(reg2>>i)&1;
                printf("%x",n2);
           }
               break;
        case 4:
        reg0=switch_status|(1<<2)|(1<<3);
        reg1=switch_status|((1<<2)|(1<<3));
        reg2=switch_status&(0x00);
        for(i=7;i>=0;i--){
            n1=(reg1>>i)&1;
            printf("%x",n1);
        }
        n2=0x00;
        printf("\n");
               for(i=7;i>=0;i--){
                   n=(reg0>>i)&1;
                printf("%x",n);
           }
           printf("\n");
        for(i=7;i>=0;i--){
               n2=(reg2>>i)&1;
               printf("%x",n2);
        }
               break;
    
    }
}
