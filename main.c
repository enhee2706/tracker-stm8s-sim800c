#include "stm8s003f.h"
#include "mq.h"
#include "gpio.h"
#include "timer.h"
#include "uart.h"
#include "delay.h"

#define ID_MSG_TIMER_1S        0x01
#define ID_MSG_UART_DATA_READY 0x02

typedef struct AtCmd {
	unsigned char *str;
	unsigned char len;
}AtCmd_t;

AtCmd_t at_cmd[17] = {
	{"AT\r\n", 4},
	{"AT+ICCID\r\n", 10},
	{"AT+CGATT?\r\n", 11},
	{"AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"\r\n", 31},
	{"AT+SAPBR=3,1,\"APN\",\"CMIOT\"\r\n", 28},
	{"AT+SAPBR=1,1\r\n", 14},
	{"AT+CLBS=4,1\r\n", 13},
	//{"AT+SAPBR=0,1\r\n", 14},
	//{"AT+SAPBR=1,1\r\n", 14},
	{"AT+HTTPINIT\r\n", 13},
	{"AT+HTTPPARA=\"URL\",\"blog.fish2bird.com:19999/\"\r\n", 49},
	{"AT+HTTPPARA=\"CID\",1\r\n", 21},
	{"AT+HTTPDATA=??,5000\r\n", 21},
	{"\r\n", 10},
	{"AT+HTTPACTION=1\r\n", 17},
	{"AT+HTTPTERM\r\n", 13},
	{"AT+SAPBR=0,1\r\n", 14}
};

@far @interrupt void EXTI_PORTA_IRQHandler(void) {
}

@far @interrupt void UART1_RCV_IRQHandler(void) {
	unsigned char u = UART1_DR;
	UART1_PutBuffer(u);
	if (u == '\n') {
		MQ_PutMessage(ID_MSG_UART_DATA_READY);
	}
}

@far @interrupt void TIM4_UPD_OVF_IRQHandler(void) {
	static int cnt = 0;
	cnt++;
	
	TIM4_SR = 0x00;
	if (cnt >= 62) { // 16.128ms * 62 = 0.999936s
		cnt = 0;
		GPIO_LEDReverse();
		MQ_PutMessage(ID_MSG_TIMER_1S);
	}
}

char buf[60];
char iccid[35];
char clbs[60];

void main() {
	int l;
	int sim800c_watchdog = 0;
	int sec = 300;
	unsigned char msg;
	unsigned char len;
	int step = 0;

	if (MQ_Init() != 0) {
		return;
	}

	GPIO_Init();
	TIM4_Init();
	UART1_Init();
	
	_asm("rim");
	
	delay_s(1);	
	GPIO_PCSetLow(GPIO_PC7);
	delay_s(2);
	GPIO_PCSetHigh(GPIO_PC7);
	delay_s(1);
	UART1_SendString("AT\r\n", 4);
	delay_ms(100);
	MQ_GetMessage(&msg);
	UART1_ReceiveString(buf, sizeof(buf));
	UART1_ReceiveString(buf, sizeof(buf));
	UART1_ReceiveString(buf, sizeof(buf));
	UART1_ReceiveString(buf, sizeof(buf));
	delay_s(4);
	MQ_GetMessage(&msg);
	UART1_ReceiveString(buf, sizeof(buf));
	UART1_ReceiveString(buf, sizeof(buf));
	UART1_ReceiveString(buf, sizeof(buf));
	UART1_ReceiveString(buf, sizeof(buf));
	delay_s(4);
	MQ_GetMessage(&msg);
	UART1_ReceiveString(buf, sizeof(buf));
	UART1_ReceiveString(buf, sizeof(buf));
	UART1_ReceiveString(buf, sizeof(buf));
	UART1_ReceiveString(buf, sizeof(buf));
	delay_s(4);
	MQ_GetMessage(&msg);
	UART1_ReceiveString(buf, sizeof(buf));
	UART1_ReceiveString(buf, sizeof(buf));
	UART1_ReceiveString(buf, sizeof(buf));
	UART1_ReceiveString(buf, sizeof(buf));
	
	while (1) {
		if (MQ_GetMessage(&msg) == 0) {
			switch (msg) {
			case ID_MSG_TIMER_1S:
				sim800c_watchdog++;
				if (sim800c_watchdog > 600) {
					sim800c_watchdog = 0;
					GPIO_PCSetLow(GPIO_PC7);
					delay_s(1);
					GPIO_PCSetHigh(GPIO_PC7);					
				}
				sec++;
				if (sec > 300) {
					sec = 0;
					step = 0;
					UART1_SendString(at_cmd[0].str, at_cmd[0].len);
				}
				break;
			case ID_MSG_UART_DATA_READY:
				sim800c_watchdog = 0;
				if (UART1_ReceiveString(buf, sizeof(buf)) == -1) {
					break;
				}
				if (strncmp(buf, "OK", 2) == 0) {
					if (step == 15) break;
					step++;
					if (step == 13) {
						delay_s(5);
					}
					UART1_SendString(at_cmd[step].str, at_cmd[step].len);
					// For a bug in SIM800C.
					if (step == 9) {
						delay_ms(500);
						step++;
						strcpy(buf, at_cmd[step].str);
						buf[at_cmd[step].len] = '\0';
						l = strlen(iccid) + strlen(clbs);
						buf[12] = l / 10 + '0';
						buf[13] = (l % 10) + '0';
						UART1_SendString(buf, strlen(buf));
					}
				} else if (strncmp(buf, "ERROR", 5) == 0) {
					GPIO_PCSetLow(GPIO_PC7);
					delay_s(2);
					GPIO_PCSetHigh(GPIO_PC7);
					step = 0;
				} else if (strncmp(buf, "DOWNLOAD", 8) == 0) {
					step++;
					UART1_SendString(iccid, strlen(iccid));
					UART1_SendString(clbs, strlen(clbs));					
				} else if (strncmp(buf, "+ICCID:", 7) == 0) {
					strncpy(iccid, buf, sizeof(iccid));
				} else if (strncmp(buf, "+CLBS:", 6) == 0) {
					strncpy(clbs, buf, sizeof(clbs));
				} else if (strncmp(buf, "NORMAL POWER DOWN", 17) == 0) {
					GPIO_PCSetLow(GPIO_PC7);
					delay_s(1);
					GPIO_PCSetHigh(GPIO_PC7);
				}
				break;
			}
		}
	}
}
