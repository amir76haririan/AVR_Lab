#include <mega16.h>
#include <delay.h>
int steps[4] = {9 , 10 , 6 , 5};
int max , min;
int flag;
int step;
int counter;
int delay;
int nextStep;

void main(void)
{
    nextStep = 0;
    flag = 1; 
    step = -1;
    max = 75;
    min = -150;
    delay = max;
    counter = 0;
    
    DDRC = 0x00;   
    PINC = 0x00;  
       
    DDRA = 0xff;  
    PORTA = 0x00; 

    TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (1<<CS01) | (0<<CS00);
    TCNT0=0x0C;
    OCR0=0x00;

    TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);

    #asm("sei")

    while (1) {
        while (1) {
            if(PINC.2==0 &&  flag==0) {   
                 delay = max;
                 counter = 0; 
                 step = -1; 
                 flag=1;
            }
        }
    }
}

interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
    TCNT0=0x0C;
    
    if(flag==1)
    {
          
        if(counter>=delay)
        {
            PORTA.0 = steps[nextStep][0];  
            PORTA.1 = steps[nextStep][1];
            PORTA.2 = steps[nextStep][2];
            PORTA.3 = steps[nextStep][3];   
            
            if(nextStep<3)
            {
                ++nextStep;
            } else
            {
                nextStep=0;
            }
             
            if(step<0)
            {
                if(delay>min)
                {
                    delay--;
                } else
                {
                    step = 1;
                }
            } else
            {
                if(delay<max)
                {
                    delay++;
                } else
                {
                    step = -1;
                    flag = 0;
                }    
            }
            
            counter = 0;
        }
        
        counter++;   
    }
}

