#pragma config OSC = HS      // Oscillator Selection bits (RC oscillator w/ OSC2 configured as RA6)
#pragma config OSCS = OFF       // Oscillator System Clock Switch Enable bit (Oscillator system clock switch option is disabled (main oscillator is source))

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = OFF         // Brown-out Reset Enable bit (Brown-out Reset enabled)
#pragma config BORV = 25        // Brown-out Reset Voltage bits (VBOR set to 2.5V)

// CONFIG2H
#pragma config WDT = OFF         // Watchdog Timer Enable bit (WDT enabled)
#pragma config WDTPS = 128      // Watchdog Timer Postscale Select bits (1:128)

// CONFIG4L
#pragma config STVR = OFF        // Stack Full/Underflow Reset Enable bit (Stack Full/Underflow will cause Reset)
#pragma config LVP = OFF         // Low-Voltage ICSP Enable bit (Low-Voltage ICSP enabled)

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000200-001FFFh) not code protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) not code protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) not code protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) not code protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot Block (000000-0001FFh) not code protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000200-001FFFh) not write protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) not write protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) not write protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) not write protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0001FFh) not write protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000200-001FFFh) not protected from Table Reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) not protected from Table Reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) not protected from Table Reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) not protected from Table Reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0001FFh) not protected from Table Reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ  2000000
#define ConfigurationMode_0x80 0x80
#define ListenOnlyMode_0x60  0x60
#define LoopbackMode_0x40 0x40
#define DisableMode_0x20 0x20
#define NormalMode_0x00 0x00
#define CANCON_TransmitBuffer_0 0x08
#define CANCON_TransmitBuffer_1 0x06
#define CANCON_TransmitBuffer_2 0x04
#define TransmitAtHighPriority 0x0B
#define LED_1 RA0
#define LED_2 RA1

enum Tx_Buffer{Transfer_Buffer_0, Transfer_Buffer_1, Transfer_Buffer_2};  
enum Rx_Buffer{Receiver_Buffer_0, Receiver_Buffer_1};  

char Rx_data_11bytes_Buffer_0[11]={0};
char Rx_data_11bytes_Buffer_1[11]={0};
char Rx_data_11bytes_Buffer_2[11]={0};
char Tx_data_8bytes_Buffer_0[8]= {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
char Tx_data_8bytes_Buffer_1[8]= {0x11,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
char Tx_data_8bytes_Buffer_2[8]= {0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80};

int Sys_Init()
{
    GIE=1;//Global Interrupt Enable
    PEIE=1;//Peripheral Interrupt Enable

}
int CANSTAT_Get_Mode(void)
{
    if((CANSTAT == NormalMode_0x00))
    {
        return 1;
    }
    else if((CANSTAT == DisableMode_0x20))
    {
        return 1;
    }
    else if ((CANSTAT == LoopbackMode_0x40))
    {
        return 1;
    }
    else if ((CANSTAT == ListenOnlyMode_0x60))
    {
        return 1;
    }
    else if ((CANSTAT == ConfigurationMode_0x80))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void CANCON_Set_Mode(int mode)
{

    switch(mode)
    {
        case 0:
            CANCON = ConfigurationMode_0x80;// CANCON Register set to configure mode
            break;
        case 1:
            CANCON = ListenOnlyMode_0x60; // CANCON Register set to listen mode
            break;
        case 2:
            CANCON = LoopbackMode_0x40;// CANCON Register set to loop back mode
        case 3:
            CANCON = DisableMode_0x20;// CANCON Register set to disable mode
        case 4:
            CANCON = NormalMode_0x00;// CANCON Register set to normal mode
    }
}  
void Can_Init(){    
                                     //Trisa bits are set to high for LED as an Output
    TRISBbits.RB2=0;                        //Rb2 bit is set for output
    TRISBbits.RB3=1;                        //Rb3 bit is set for input
                                            //IPR3 register is set to enable 
    PIE3bits.RXB0IE = 1;           /*Enable receiver buffer 0 interrupt*/
    IPR3bits.RXB0IP = 1;           /*Enable receiver buffer 0 as high priority*/


}
void Set_BaudRate()  // baud rate function
{
    BRGCON1=0xC1;  //BRGCON1 register set to be 0xc1 for 250kbps.
    BRGCON2=0xAE;   //BRGCON2 register set to be 0xAE for 250kbps.
    BRGCON3=0x45;   //BRGCON3 register set to be 0x45 for 250kbps.

}
void Set_Filter()    //acceptance filter function
{
    RXF0SIDH=0x00;  // RXF0SIDH register set to 0x00.
    RXF0SIDL=0x00;  // RXF0SIDL register set to 0x00.

}
void Set_Mask()     //acceptance mack function
{
    RXM0SIDH=0x00;  //RXM0SIDH register set to 0x00;
    RXM0SIDL=0x00;  //RXM0SIDL register set to 0x00;

}

int Tx_Buffer(char Transfer_buffer)
{ 

            CANCON = CANCON_TransmitBuffer_0;
            TXB0SIDH=0x13;         //TRANSMIT BUFFER n STANDARD IDENTIFIER, HIGH BYTE REGISTERS is set to be 0x13;
            TXB0SIDL=0x20;         //TRANSMIT BUFFER n STANDARD IDENTIFIER, LOW BYTE REGISTERS is set to be 0x20;
                                    //TRANSMIT MSG ID IS 0X99;
            TXB0DLC = 0x08;        //TRANSMIT BUFFER n DATA LENGTH CODE is set to be 0x08; 
            TXB0D0 = Tx_data_8bytes_Buffer_0[0];
            TXB0D1 = Tx_data_8bytes_Buffer_0[1];
            TXB0D2 = Tx_data_8bytes_Buffer_0[2];
            TXB0D3 = Tx_data_8bytes_Buffer_0[3];
            TXB0D4 = Tx_data_8bytes_Buffer_0[4];
            TXB0D5 = Tx_data_8bytes_Buffer_0[5];
            TXB0D6 = Tx_data_8bytes_Buffer_0[6];
            TXB0D7 = Tx_data_8bytes_Buffer_0[7];
            //enable the TXBnCON  such that the transmitter buffer and assign the highest priority to the chosen buffer.
            TXB0CON = TransmitAtHighPriority;  
            CANCON=NormalMode_0x00;
}

void CAN_Read_fun()
{
   
    CANCON=0x0C;//Select Normal Mode and Select Receive Buffer_0.   
    Rx_data_11bytes_Buffer_0[8] =  RXB0SIDL;//LowByte_3bits
    Rx_data_11bytes_Buffer_0[9] =  RXB0SIDH ;//HigherByte_8bits
    
    if((Rx_data_11bytes_Buffer_0[8] == 0x00) && (Rx_data_11bytes_Buffer_0[9] == 0x20 ))    //RECIVER BUFER WILL BE SET TO 0X100;
    {
        Rx_data_11bytes_Buffer_0[0] =  RXB0D0;//data_byte_0
        Rx_data_11bytes_Buffer_0[1] =  RXB0D1;//data_byte_1
        Rx_data_11bytes_Buffer_0[2] =  RXB0D2;//data_byte_2
        Rx_data_11bytes_Buffer_0[3] =  RXB0D3;//data_byte_3
        Rx_data_11bytes_Buffer_0[4] =  RXB0D4;//data_byte_4
        Rx_data_11bytes_Buffer_0[5] =  RXB0D5;//data_byte_5
        Rx_data_11bytes_Buffer_0[6] =  RXB0D6;//data_byte_6
        Rx_data_11bytes_Buffer_0[7] =  RXB0D7;//data_byte_7 

        Rx_data_11bytes_Buffer_0[10] =  RXB0DLC;//DLC 
    }
   
    RXB0CONbits.RXB0FUL = 0;
    CANCON=NormalMode_0x00;//Resetting the Receiver Buffer_0 000 and set mode to Normal Mode  to get next data
}
__interrupt () ISR1()
{
    CANCON=NormalMode_0x00;
    if(RXB0IF)
    {
        RXB0IF=0;//Clear The Interrupt enable flag
        CAN_Read_fun();//CAN Rx is called
        /*LED Blink for Notification of Interrupt LED 1*/
        LED_1 = 1;
        __delay_ms(1000);
        LED_1 = 0;
    }
}

void main(void) {

    //TRISA=0x00;//Set LED_1 & LED_2 as an Output
    Sys_Init();
    Can_Init();
    
    CANCON_Set_Mode(0);              //Set Configuration Mode  the CANCON Register 
    Set_Mask();
    Set_Filter();
    Set_BaudRate();
    CANCON_Set_Mode(4);              //Set Normal Mode
    TRISC=0x00;                      //PORTC will be taken as a output;
    TRISBbits.RB0=1;                 //PORTRB0 will be taken as a input for switch s2 ;
    TRISBbits.RB1=1;                 //PORTRB1 will be taken as a input for switch s3 ;
    PORTCbits.RC0=0;                 //PORTC0 will be taken as a output for LED;
    PORTCbits.RC1=0;                 //PORTRC1 will be taken as a output for warning LED;
    RBPU = 0;                        //pull up resistor set to zero;
    
 Tx_data_8bytes_Buffer_0[7]=0x00;     //TRANSIMITER DATA BYTE BUFFER BIT 7 will be taken as transmission;
  PORTCbits.RC1=0;                       //PORTRC1 will be taken as a output for warning LED;
    while(1)
    {
       
    if((PORTBbits.RB0 == 0) && (PORTBbits.RB1 == 0))    //Checking the condition for RB0 and RB1 both are off;
    {
       if(Rx_data_11bytes_Buffer_0[0] == 0x00){          //Receiver will receives the data from byte0 is set to 0x00;
            Tx_data_8bytes_Buffer_0[7]=0x00;             //Transmitting will transmits the data to byte7 is set to 0x00;
           // Tx_Buffer(Tx_data_8bytes_Buffer_0);
        }  
        RC0=1; 
        RC1=1;//led will be ON.
        Tx_data_8bytes_Buffer_0[0]=0x00;                 //Transmitting will transmits the data to byte0 is set to 0x00;
        Tx_Buffer(Tx_data_8bytes_Buffer_0);              //Calling the transmission function
    }
    if((PORTBbits.RB0 == 0x00) && (PORTBbits.RB1 == 0x01)) //Checking the condition for RB0 is OFF and RB1 is ON ;
    {
        if(Rx_data_11bytes_Buffer_0[0] == 0x01){         //Receiver will receives the data from byte0 is set to 0x01;
            Tx_data_8bytes_Buffer_0[7]=0x01;             //Transmitting will transmits the data to byte7 is set to 0x01;
            //RC1=1;
        }
        else
        {
            Tx_data_8bytes_Buffer_0[7]=0x00;               //Transmitting will transmits the data to byte7 is set to 0x00;
        
        }
        RC0=0;
        RC1=0;                                              //LED oOFF for air bag enable 
        Tx_data_8bytes_Buffer_0[0]=0x01;                    //Transmitting will transmits the data to byte0 is set to 0x00;                   
        Tx_Buffer(Tx_data_8bytes_Buffer_0);                 //calling the transmission function                                 
    }
    if((PORTBbits.RB0 == 0x01) && (PORTBbits.RB1 == 0x00))  //Checking the condition for RB0 is ON and RB1 is OFF ;
    {
        if(Rx_data_11bytes_Buffer_0[0] == 0x00){            //Receiver will receives the data from byte0 is set to 0x00;
            Tx_data_8bytes_Buffer_0[7]=0x00;                //Transmitting will transmits the data to byte7 is set to 0x00;
        }
        RC0=1;                                              //LED is ON with delay 500 m sec
        __delay_ms(5000);
        RC0=0;                                              //LED is OFF with delay 500 m sec
        __delay_ms(5000);
        Tx_data_8bytes_Buffer_0[0]=0x00;                     //Transmitting will transmits the data from byte0 is set to 0x00;     
        Tx_Buffer(Tx_data_8bytes_Buffer_0);                  //calling the transmission function 
        RC1=1;                                               //LED ON for air bag disable             
    }
    if((PORTBbits.RB0 == 0x01) && (PORTBbits.RB1 == 0x01))   //Checking the condition for RB0 and RB1 both are ON ;
    {
         if(Rx_data_11bytes_Buffer_0[0] == 0x00){            //Receiver will receives the data from byte0 is set to 0x00;               
            Tx_data_8bytes_Buffer_0[7]=0x00;                 //Transmitting will transmits the data to byte7 is set to 0x00;
        }
          Tx_data_8bytes_Buffer_0[7]=0x00; 
       RC0=1;                                                //LED is ON with delay 1 sec
        __delay_ms(10000);
        RC0=0;                                               //LED is OFF with delay 1 sec
        __delay_ms(10000);
        RC1=1;                                                //LED ON for air bag disable 
        Tx_data_8bytes_Buffer_0[0]=0x00;                     //Transmitting will transmits the data to byte0 is set to 0x00;
        Tx_Buffer(Tx_data_8bytes_Buffer_0);                  //calling the transmission function 
    }
        
  
        
        __delay_ms(5000);                                    //delay with 5 sec.       
    }
}
