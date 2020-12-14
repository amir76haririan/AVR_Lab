#include <mega16.h>

static unsigned int count;

interrupt [TIM0_OVF] void timer0_ovf_isr(void){
	TCNT0 = 56;
	count ++;

	if(count == 3787){
		PORTA.0 = (PORTA.0 ^ 1);
		count = 0;
	}
}

void main(void){
	DDRA = 0x01;
  TCCR0 = 0x02;
	TCNT0 = 56;
  TIMSK = 0x01;

	#asm("sei");

	while(1){

	}
}
