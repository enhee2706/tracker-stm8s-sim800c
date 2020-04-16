#include "gpio.h"
#include "stm8s003f.h"

void GPIO_Init(void)
{
	PA_DDR &= ~0x02; // Set PA1 input
	PA_CR1 |= 0x02; // Set PA1 pull-up
	PA_CR2 |= 0x02; // Interrupt

	// PB5 -> TEST LED
	PB_DDR |= 0x20; // Set PB5 output
	PB_CR1 |= 0x20;
	PB_CR2 |= 0x20;
	PB_ODR |= 0x20; // Set PB5 high level
	
	PC_DDR |= 0x80;
	PC_CR1 |= 0x80;
	PC_CR2 |= 0x80;
	PC_ODR |= 0x80;
}

void GPIO_LEDReverse() {
	PB_ODR ^= 0x20;
}
