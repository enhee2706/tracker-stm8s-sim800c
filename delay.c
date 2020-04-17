#include "delay.h"

void delay_1ms(void) {
	unsigned int i;
	for (i=0;i<130;i++) {
		_asm("nop");
	}
}

void delay_ms(unsigned int i)
{
	while (i--) {
		delay_1ms();
	}
}

void delay_s(unsigned int i)
{
	while (i--) {
		delay_ms(1000);
	}
}