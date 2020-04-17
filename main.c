#include "stm8s003f.h"
#include "mq.h"
#include "gpio.h"
#include "timer.h"
#include "uart.h"

#define ID_MSG_TIMER_1S        0x01
#define ID_MSG_UART_DATA_READY 0x02

typedef struct AtCmd {
	unsigned char *str;
	unsigned char len;
}AtCmd_t;

AtCmd_t at_cmd[]{
	{"AT\r\n", 4},
	{"AT+ICCID\r\n", 10},
	{"AT+CGATT?\r\n", 11},
	{"AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"\r\n", 31},
	{"AT+SAPBR=3,1,\"APN\",\"CMIOT\"\r\n", 28},
	{"AT+SAPBR=1,1\r\n", 14},
	{"AT+CLBS=4,1\r\n", 13},
	{"AT+SAPBR=0,1\r\n", 14},
	{"AT+SAPBR=1,1\r\n", 14},
	{"AT+HTTPINIT\r\n", 13},
	{"AT+HTTPPARA=\"URL\",\"blog.fish2bird.com:19999/\"\r\n", 49},
	{"AT+HTTPPARA=\"CID\",1\r\n", 21},
	{"AT+HTTPDATA=??,5000\r\n", 21},
	{"\r\n", 10},
	{"AT+HTTPACTION=1\r\n", 17},
	{"AT+HTTPTERM\r\n", 13},
	{"AT+SAPBR=0,1\r\n", 14}
}

@far @interrupt void EXTI_PORTA_IRQHandler(void) {
}

@far @interrupt void UART1_RCV_IRQHandler(void) {
	unsigned char u = UART1_DR;
	UART1_PutBuffer(u);
	if (u == '\r' || u == '\n') {
		MQ_PutMessage(ID_MSG_UART_DATA_READY);
	}
}

@far @interrupt void TIM4_UPD_OVF_IRQHandler(void) {
	static int cnt = 0;
	cnt++;
	
	TIM4_SR = 0x00;
	if (cnt >= 62) { // 16.128ms * 62 = 0.999936s
		cnt = 0;
		MQ_PutMessage(ID_MSG_TIMER_1S);
	}
}

char buf[60];

void main() {
  int sim800c_watchdog = 0;
  unsigned char msg;
  int len;
  int step = 0;

	if (MQ_Init() != 0) {
		return;
	}

	GPIO_Init();
	TIM4_Init();
	UART1_Init();
	
	_asm("rim");
	
	while (1) {
		if (MQ_GetMessage(&msg) == 0) {
			switch (msg) {
			case ID_MSG_TIMER_1S:
				GPIO_LEDReverse();
				sim800c_watchdog++;
				if (sim800c_watchdog > 600) {
				}
				break;
			case ID_MSG_UART_DATA_READY:
				sim800c_watchdog = 0;
				UART_ReceiveString(buf, &len);
				if (strncmp(buf, "OK", 2) == 0) {
					step++;
				} else if (strncmp(buf, "ERROR", 5) == 0) {
					if (step != 16) {
						step = 0;
						UART1_SendString("AT+SAPBR=0,1\r\n", 14);
					} else {
						step++;
					}
				} else if (strncmp(buf, "DOWNLOAD", 8) == 0) {
				} else if (strncmp(buf, "+ICCID:", 7) == 0) {
				} else if (strncmp(buf, "+CLBS:", 6) == 0) {
				} else if (strncmp(buf, "NORMAL POWER DOWN", 17) == 0) {
				}
				break;
			}
		}
	}
}
