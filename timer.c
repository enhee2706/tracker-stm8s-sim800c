#include "timer.h"
#include "stm8s003f.h"

void TIM4_Init(void)
{
	TIM4_PSCR = 7;   // 2M/2^7 = 15.625k, 16.625kHz = 0.064ms
	TIM4_ARR  = 252; // 252 * 0.064ms = 16.128ms
	TIM4_CNTR = 252;

	TIM4_IER  |= TIM4_IER_UIE;
	TIM4_CR1  |= TIM4_CR1_APRE;

  // Enable TIM4
	TIM4_CR1 |= TIM4_CR1_CEN;
}
