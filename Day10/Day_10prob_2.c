Write a function to store "G_Str_SteeringAngle_sint" to "G_Msg_SteeringInformation_Byte" as shown below.
signed int CG_Msg_EngineInformation_Byte[i];
unsigned char G_Msg_SteeringInformation_Byte[3u];"
Algorithm:
1.Declare the variable as G_Str_SteeringAngle_sint as -60
2.WE have to iterate the above variable in 12 times as per qustion
3.Take an a array for byte 0 to byte 2 and you have to acess those information as per qustion
 unsigned char G_Msg_SteeringInformation_Byte[3u]
4.You have to iterate statement 3
5.Note down the result.

#include<stdio.h>
int main(){
    signed int G_Str_SteeringAngle_sint = -60;
    for(int i=0;i<=12;i++){
        printf("%x ",(G_Str_SteeringAngle_sint>>i)&1);
    }
    unsigned char G_Msg_SteeringInformation_Byte[3u]={0x00,0x00,0x00};
    G_Msg_SteeringInformation_Byte[0]=((G_Str_SteeringAngle_sint>>0)&~(1<<2));
    G_Msg_SteeringInformation_Byte[1]=(G_Str_SteeringAngle_sint>>2);
    G_Msg_SteeringInformation_Byte[2]=(G_Str_SteeringAngle_sint<<6);
    for(int i=0;i<3;i++){
       printf("\nG_Msg_SteeringInformation_Byte[%d]:\n",i);
        for(int j=0;j<=7;j++)
            printf("%d ",(G_Msg_SteeringInformation_Byte[i]>>j)&1);
       }
}
