
#include <string.h>

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

AtCmd_t at_cmd[14] = {
	{"AT\r\n", 4},                                    // 0
	{"AT+ICCID\r\n", 10},                             // 1
	{"AT+CGATT?\r\n", 11},                            // 2
	{"AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"\r\n", 31},    // 3
	{"AT+SAPBR=3,1,\"APN\",\"CMIOT\"\r\n", 28},       // 4
	{"AT+SAPBR=1,1\r\n", 14},                         // 5
	{"AT+CLBS=4,1\r\n", 13},                          // 6
	{"AT+HTTPINIT\r\n", 13},                          // 7
	{"AT+HTTPPARA=\"URL\",\"blog.fish2bird.com:19999/set\"\r\n", 52},
	{"AT+HTTPPARA=\"CID\",1\r\n", 21},                // 9
	{"AT+HTTPDATA=??,5000\r\n", 21},                  // 10
	{"AT+HTTPACTION=1\r\n", 17},                      // 11
	{"AT+HTTPTERM\r\n", 13},                          // 12
	{"AT+SAPBR=0,1\r\n", 14}                          // 13
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
	int sec = 280;
	unsigned char msg;
	unsigned char len;
	int current_step = -1;
	int next_step = -1;

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
	
	while (1) {
		if (MQ_GetMessage(&msg) == 0) {
			switch (msg) {
			case ID_MSG_TIMER_1S:
				sim800c_watchdog++;
				if (sim800c_watchdog > 600) {
					sim800c_watchdog = 0;
					GPIO_PCSetLow(GPIO_PC7);
					delay_s(2);
					GPIO_PCSetHigh(GPIO_PC7);					
				}
				sec++;
				if (sec > 300) {
					sec = 0;
					current_step = 0;
					next_step = 0;
					UART1_SendString(at_cmd[0].str, at_cmd[0].len);
				}
				break;
			case ID_MSG_UART_DATA_READY:
				sim800c_watchdog = 0;
				if (UART1_ReceiveString(buf, sizeof(buf)) == -1) {
					break;
				}
				if (strncmp(buf, "ERROR", 5) == 0) {
					GPIO_PCSetLow(GPIO_PC7);
					delay_s(2);
					GPIO_PCSetHigh(GPIO_PC7);
					current_step = 0;
					next_step = 0;
				} else if (strncmp(buf, "OK", 2) == 0) {
					switch (current_step) {
					case 0:
					case 1:
					case 3:
					case 4:
					case 5:
					case 7:
					case 10:
					case 12:
						next_step = current_step + 1;
						UART1_SendString(at_cmd[next_step].str, at_cmd[next_step].len);
						current_step = next_step;
						break;					
					case 2:
					case 6:
						UART1_SendString(at_cmd[next_step].str, at_cmd[next_step].len);
						current_step = next_step;					
					  break;
					case 8:
						next_step = current_step + 1;
						UART1_SendString(at_cmd[next_step].str, at_cmd[next_step].len);
						current_step = next_step;
						// For a bug, no response for step 9 
						delay_ms(500);
						next_step = 10;
						strcpy(buf, at_cmd[next_step].str);
						buf[at_cmd[next_step].len] = '\0';
						l = strlen(iccid) + strlen(clbs);
						buf[12] = l / 10 + '0';
						buf[13] = (l % 10) + '0';
						UART1_SendString(buf, strlen(buf));
						current_step = next_step;
						break;
					case 11:
						next_step = 12;
						break;
					case 13:
						next_step = 14;
						current_step = 14;
						break;
					}
				} else if (strncmp(buf, "+ICCID:", 7) == 0) {
					strncpy(iccid, buf, sizeof(iccid));
				} else if (strncmp(buf, "+CGATT:", 7) == 0) {
					if (buf[8] == '1') {
						next_step = 3;
					} else {
						next_step = 14;
					}
				} else if (strncmp(buf, "+CLBS:", 6) == 0) {
					if (buf[7] == '0') {
						strncpy(clbs, buf, sizeof(clbs));
						next_step = 7;
					} else {
						next_step = 13;
					}					
				} else if (strncmp(buf, "DOWNLOAD", 8) == 0) {
					UART1_SendString(iccid, strlen(iccid));
					UART1_SendString(clbs, strlen(clbs));
				} else if (strncmp(buf, "+HTTPACTION:", 12) == 0) {
					UART1_SendString(at_cmd[next_step].str, at_cmd[next_step].len);
					current_step = next_step;
				} else if (strncmp(buf, "NORMAL POWER DOWN", 17) == 0) {
					GPIO_PCSetLow(GPIO_PC7);
					delay_s(2);
					GPIO_PCSetHigh(GPIO_PC7);
				}
				break;
			}
		}
	}
}
