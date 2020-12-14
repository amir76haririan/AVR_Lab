/*******************************************************
This program was created by the CodeWizardAVR V3.42 
Automatic Program Generator
© Copyright 1998-2020 Pavel Haiduc, HP InfoTech S.R.L.
http://www.hpinfotech.ro

Project : 
Version : 
Date    : 12/14/2020
Author  : 
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/
 #include <mega16.h>
#include <delay.h>

#define LED0 PORTB.0
#define LED1 PORTB.1
#define LED2 PORTB.2
#define LED3 PORTB.3
#define LED4 PORTB.4
#define LED5 PORTB.5
#define LED6 PORTB.6
#define LED7 PORTB.7

#define on 1
#define off 0

void main(void)
{
    DDRA = 0x00;
    PINA = 0x00;
    DDRB = 0xff;
    PORTB = 0x00;
    #asm("sei")
    
    while (1) {
        if(PINA.0==1)
        {
            //0
            LED0 = on;
            delay_ms(100);
            LED0 = off;
            //1
            LED1 = on;
            delay_ms(100);
            LED1 = off;
            //2
            LED2 = on;
            delay_ms(100);
            LED2 = off;
            //3
            LED3 = on;
            delay_ms(100);
            LED3 = off;
            //4
            LED4 = on;
            delay_ms(100);
            LED4 = off;
            //5
            LED5 = on;
            delay_ms(100);
            LED5 = off;
            //6
            LED6 = on;
            delay_ms(100);
            LED6 = off;
            //7
            LED7 = on;
            delay_ms(100);
            LED7 = off;
            //6
            LED6 = on;
            delay_ms(100);
            LED6 = off;
            //5
            LED5 = on;
            delay_ms(100);
            LED5 = off;
            //4
            LED4 = on;
            delay_ms(100);
            LED4 = off;
            //3
            LED3 = on;
            delay_ms(100);
            LED3 = off;
            //2
            LED2 = on;
            delay_ms(100);
            LED2 = off;
            //1
            LED1 = on;
            delay_ms(100);
            LED1 = off;
            //0
            LED0 = on;
            delay_ms(100);
            LED0 = off;
            
        } else {
            
            PORTB = 00000000;
            
        }
    }
}
