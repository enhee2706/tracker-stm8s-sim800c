#ifndef _GPIO_H_
#define _GPIO_H_

#define GPIO_PC7 0x80

void GPIO_Init(void);
void GPIO_LEDReverse(void);
void GPIO_PCSetLow(unsigned char mask);
void GPIO_PCSetHigh(unsigned char mask);

#endif
