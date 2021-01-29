#include <mega16.h>

int steps[4] = {9 , 10 , 6 , 5};
int delay;
int flag;
int nextStep;

void main(void)
{ 
    delay = 0;  
    nextStep = 0;
    flag=0;
    
    DDRC = 0x00;   
    PINC = 0x00;  
       
    DDRA = 0xff;  
    PORTA = 0x00;

    TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (1<<CS02) | (0<<CS01) | (0<<CS00);
    TCNT0=0x0C;
    OCR0=0x00;
    TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);


    #asm("sei")

    while (1) {
        if(PINC.2==0 &&  flag==0) { 
             delay = 0;  
             flag=1;
        }
    }
}

interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
    TCNT0=0x0C;

    if(flag == 1) {
        if(delay == 0)
        {
            PORTA.0 = steps[nextStep][0];  
            PORTA.1 = steps[nextStep][1];
            PORTA.2 = steps[nextStep][2];
            PORTA.3 = steps[nextStep][3];
        }
        
        if(delay>5 && delay<=10)
        {
            PORTA = 0x00;
        }  
        
        if(delay == 10)
        {
            delay = 0;  
            if(nextStep<3)
            {
                ++nextStep;
            } else
            {
                nextStep=0;
                flag=0;
            }
        } else
        {
            ++delay;
        }   
    }
}
