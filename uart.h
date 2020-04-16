#ifndef _UART_H_
#define _UART_H_

void UART1_Init(void);
void UART1_SendData8(unsigned char Data);
void UART1_SendString(unsigned char *buf, unsigned char len);
void UART1_ReceiveString(unsigned char *buf, unsigned char *len);
int  UART1_PutBuffer(unsigned char b);

#endif
