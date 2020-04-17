#include "uart.h"
#include "kfifo.h"
#include "stm8s003f.h"

static struct kfifo fifo;
@near static char fifo_buffer[128];

void UART1_Init(void) {
	kfifo_init(&fifo, fifo_buffer, sizeof(fifo_buffer));
	
	// baud = 115200
	// 2MHz / 115200 = 17.36, 0x0011
	UART1_BRR2 = 0x01;
	UART1_BRR1 = 0x01;
	
	// Enable Receiver Interrupt  0x20
	// Enable TX                  0x08
	// Enable RX                  0x04
	UART1_CR2 = 0x2c;
}

void UART1_SendData8(unsigned char b) {
	UART1_DR = b;
}

void UART1_SendString(unsigned char *buf, int len) {
	int i;
	for (i = 0; i < len; i++) {
		UART1_SR &= ~UART1_SR_TC;
		UART1_DR = buf[i];
		while ((UART1_SR&UART1_SR_TC)==0) {}
	}
}

int UART1_ReceiveString(unsigned char *buf, int len) {
	int i = 0;
	unsigned char b;

	for (i=0;i<len-1;i++) {
		if (kfifo_get(&fifo, &b) == -1) break;
		buf[i] = b;
		if (b == '\n') {
			i++;
			break;
		}
	}
	buf[i] = '\0';

	if (i == 0) {
		return -1;
	}
	
	return 0;
}

int UART1_PutBuffer(unsigned char b) {
	return kfifo_put(&fifo, b);
}
