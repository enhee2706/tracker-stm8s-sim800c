/*
 *  Register map addresses is from datasheet for STM8S003F3 STM8S003K3
 *  
 */

// Port A
volatile char PA_ODR @0x5000; // data output latch register
volatile char PA_IDR @0x5001; // input pin value register
volatile char PA_DDR @0x5002; // data direction register
volatile char PA_CR1 @0x5003; // control register 1
volatile char PA_CR2 @0x5004; // control register 2

// Port B
volatile char PB_ODR @0x5005;
volatile char PB_IDR @0x5006;
volatile char PB_DDR @0x5007;
volatile char PB_CR1 @0x5008;
volatile char PB_CR2 @0x5009;

// Port C
volatile char PC_ODR @0x500A;
volatile char PC_IDR @0x500B;
volatile char PC_DDR @0x500C;
volatile char PC_CR1 @0x500D;
volatile char PC_CR2 @0x500E;

// Port D
volatile char PD_ODR @0x500F;
volatile char PD_IDR @0x5010;
volatile char PD_DDR @0x5011;
volatile char PD_CR1 @0x5012;
volatile char PD_CR2 @0x5013;

// Port E
volatile char PE_ODR @0x5014;
volatile char PE_IDR @0x5015;
volatile char PE_DDR @0x5016;
volatile char PE_CR1 @0x5017;
volatile char PE_CR2 @0x5018;

// Port F
volatile char PF_ODR @0x5019;
volatile char PF_IDR @0x501A;
volatile char PF_DDR @0x501B;
volatile char PF_CR1 @0x501C;
volatile char PF_CR2 @0x501D;
/* ---- Reverved area (60 byte) ---- */

// FLASH;
volatile char FLASH_CR1   @0x505A;
volatile char FLASH_CR2   @0x505B;
volatile char FLASH_NCR2  @0x505C;
volatile char FLASH_FPR   @0x505D;
volatile char FLASH_NFPR  @0x505E;
volatile char FLASH_IAPSR @0x505F;
//volatile char REVERSED  @0x5060;
//volatile char REVERSED  @0x5061;
volatile char FLASH_PUKR  @0x5062;
//volatile char REVERSED  @0x5063;
volatile char FLASH_DUKR  @0x5064;
/* ---- Reverved area (59 byte) ---- */

// ITC
volatile char EXTI_CR1 @0x50A0;
volatile char EXTI_CR2 @0x50A1;
/* ---- Reverved area (17 byte) ---- */

// RST
volatile char RST_SR @0x50B3;
/* ---- Reverved area (12 byte) ---- */

// CLK
volatile char CLK_ICKR     @0x50C0;
volatile char CLK_ECKR     @0x50C1;
//volatile char REVERSED   @0x50C2;
volatile char CLK_CMSR     @0x50C3;
volatile char CLK_SWR      @0x50C4;
volatile char CLK_SWCR     @0x50C5;
volatile char CLK_CKDIVR   @0x50C6;
volatile char CLK_PCKENR1  @0x50C7;
volatile char CLK_CSSR     @0x50C8;
volatile char CLK_CCOR     @0x50C9;
volatile char CLK_PCKENR2  @0x50CA;
//volatile char REVERSED   @0x50CB;
volatile char CLK_HSITRIMR @0x50CC;
volatile char CLK_SWIMCCR  @0x50CD;
/* ---- Reverved area (3 byte) ---- */


// WWDG
volatile char WWDG_CR @0x50D1;
volatile char WWDG_WR @0x50D2;
/* ---- Reverved area (13 byte) ---- */

// IWDG
volatile char IWDG_KR  @0x50E0;
volatile char IWDG_PR  @0x50E1;
volatile char IWDG_RLR @0x50E2;
/* ---- Reverved area (12 byte) ---- */

// AWU
volatile char AWU_CSR1 @0x50F0;
volatile char AWU_APR  @0x50F1;
volatile char AWU_TBR  @0x50F2;

// BEEP
volatile char BEEP_CSR @0x50F3;

// SPI
volatile char SPI_CR1     @0x5200;
volatile char SPI_CR2     @0x5201;
volatile char SPI_ICR     @0x5202;
volatile char SPI_SR      @0x5203;
volatile char SPI_DR      @0x5204;
volatile char SPI_CRCPR   @0x5205;
volatile char SPI_RXCRCR  @0x5206;
volatile char SPI_TXCRCR  @0x5207;
/* ---- Reverved area (8 byte) ---- */

// I2C
volatile char I2C_CR1    @0x5210;
volatile char I2C_CR2    @0x5211;
volatile char I2C_FREQR  @0x5212;
volatile char I2C_OARL   @0x5213;
volatile char I2C_OARH   @0x5214;
//volatile char REVERSED @0x5215;
volatile char I2C_DR     @0x5216;
volatile char I2C_SR1    @0x5217;
volatile char I2C_SR2    @0x5218;
volatile char I2C_SR3    @0x5219;
volatile char I2C_ITR    @0x521A;
volatile char I2C_CCRL   @0x521B;
volatile char I2C_CCRH   @0x521C;
volatile char I2C_TRISER @0x521D;
volatile char I2C_PECR   @0x521E;
/* ---- Reverved area (17 byte) ---- */

// UART1
volatile char UART1_SR   @0x5230;
volatile char UART1_DR   @0x5231;
volatile char UART1_BRR1 @0x5232;
volatile char UART1_BRR2 @0x5233;
volatile char UART1_CR1  @0x5234;
volatile char UART1_CR2  @0x5235;
volatile char UART1_CR3  @0x5236;
volatile char UART1_CR4  @0x5237;
volatile char UART1_CR5  @0x5238;
volatile char UART1_GTR  @0x5239;
volatile char UART1_PSCR @0x523A;
/* ---- Reverved area (21 byte) ---- */

// TIM1
volatile char TIM1_CR1    @0x5250;
volatile char TIM1_CR2    @0x5251;
volatile char TIM1_SMCR   @0x5252;
volatile char TIM1_ETR    @0x5253;
volatile char TIM1_IER    @0x5254;
volatile char TIM1_SR1    @0x5255;
volatile char TIM1_SR2    @0x5256;
volatile char TIM1_EGR    @0x5257;
volatile char TIM1_CCMR1  @0x5258;
volatile char TIM1_CCMR2  @0x5259;
volatile char TIM1_CCMR3  @0x525A;
volatile char TIM1_CCMR4  @0x525B;
volatile char TIM1_CCER1  @0x525C;
volatile char TIM1_CCER2  @0x525D;
volatile char TIM1_CNTRH  @0x525E;
volatile char TIM1_CNTRL  @0x525F;
volatile char TIM1_PSCRH  @0x5260;
volatile char TIM1_PSCRL  @0x5261;
volatile char TIM1_ARRH   @0x5262;
volatile char TIM1_ARRL   @0x5263;
volatile char TIM1_RCR    @0x5264;
volatile char TIM1_CCR1H  @0x5265;
volatile char TIM1_CCR1L  @0x5266;
volatile char TIM1_CCR2H  @0x5267;
volatile char TIM1_CCR2L  @0x5268;
volatile char TIM1_CCR3H  @0x5269;
volatile char TIM1_CCR3L  @0x526A;
volatile char TIM1_CCR4H  @0x526B;
volatile char TIM1_CCR4L  @0x526C;
volatile char TIM1_BKR    @0x526D;
volatile char TIM1_DTR    @0x526E;
volatile char TIM1_OISR   @0x526F;
/* ---- Reverved area (147 byte) ---- */

// TIM2
volatile char TIM2_CR1    @0x5300;
//volatile char REVERSED  @0x5301;
//volatile char REVERSED  @0x5302;
volatile char TIM2_IER    @0x5303;
volatile char TIM2_SR1    @0x5304;
volatile char TIM2_SR2    @0x5305;
volatile char TIM2_EGR    @0x5306;
volatile char TIM2_CCMR1  @0x5307;
volatile char TIM2_CCMR2  @0x5308;
volatile char TIM2_CCMR3  @0x5309;
volatile char TIM2_CCER1  @0x530A;
volatile char TIM2_CCER2  @0x530B;
volatile char TIM2_CNTRH  @0x530C;
volatile char TIM2_CNTRL  @0x530D;
volatile char TIM2_PSCR   @0x530E;
volatile char TIM2_ARRH   @0x530F;
volatile char TIM2_ARRL   @0x5310;
volatile char TIM2_CCR1H  @0x5311;
volatile char TIM2_CCR1L  @0x5312;
volatile char TIM2_CCR2H  @0x5313;
volatile char TIM2_CCR2L  @0x5314;
volatile char TIM2_CCR3H  @0x5315;
volatile char TIM2_CCR3L  @0x5316;
/* ---- Reserved area(43 byte) ---- */

// TIM4
volatile char TIM4_CR1    @0x5340; // control register
//volatile char REVERSED  @0x5401;
//volatile char REVERSED  @0x5402;
volatile char TIM4_IER    @0x5343; // interrupt enable register;
volatile char TIM4_SR     @0x5344; // status register ;
volatile char TIM4_EGR    @0x5345; // event generation register;
volatile char TIM4_CNTR   @0x5346; // counter;
volatile char TIM4_PSCR   @0x5347; // prescaler register;
volatile char TIM4_ARR    @0x5348; // auto-reload register
/* ---- Reserved area(153 byte) ---- */

// ADC1
volatile char ADC_DB1R    @0x53E0;
volatile char ADC_DB2R    @0x53E1;
volatile char ADC_DB3R    @0x53E2;
volatile char ADC_DB4R    @0x53E3;
volatile char ADC_DB5R    @0x53E4;
volatile char ADC_DB6R    @0x53E5;
volatile char ADC_DB7R    @0x53E6;
volatile char ADC_DB8R    @0x53E7;
volatile char ADC_DB9R    @0x53E8;
volatile char ADC_DB10R   @0x53E9;
volatile char ADC_DB11R   @0x53EA;
volatile char ADC_DB12R   @0x53EB;
volatile char ADC_DB13R   @0x53EC;
volatile char ADC_DB14R   @0x53ED;
volatile char ADC_DB15R   @0x53EE;
volatile char ADC_DB16R   @0x53EF;
volatile char ADC_DB17R   @0x53F0;
volatile char ADC_DB18R   @0x53F1;
volatile char ADC_DB19R   @0x53F2;
volatile char ADC_DB20R   @0x53F3;
/* ---- Reserved area(12 byte) ---- */
volatile char ADC_SCR     @0x5400;
volatile char ADC_CR1     @0x5401;
volatile char ADC_CR2     @0x5402;
volatile char ADC_CR3     @0x5403;
volatile char ADC_DRH     @0x5404;
volatile char ADC_DRL     @0x5405;
volatile char ADC_TDRH    @0x5406;
volatile char ADC_TDRL    @0x5407;
volatile char ADC_HTRH    @0x5408;
volatile char ADC_HTRL    @0x5409;
volatile char ADC_LTRH    @0x540A;
volatile char ADC_LTRL    @0x540B;
volatile char ADC_AWSRH   @0x540C;
volatile char ADC_AWSRL   @0x540D;
volatile char ADC_AWCRH   @0x540E;
volatile char ADC_AWCRL   @0x540F;
/* ---- Reserved area(1008 byte) ---- */

// CPU
volatile char CFG_CGR @0x7F60;

// ITC
volatile char ITC_SPR1 @0x7F70;
volatile char ITC_SPR2 @0x7F71;
volatile char ITC_SPR3 @0x7F72;
volatile char ITC_SPR4 @0x7F73;
volatile char ITC_SPR5 @0x7F74;
volatile char ITC_SPR6 @0x7F75;
volatile char ITC_SPR7 @0x7F76;
volatile char ITC_SPR8 @0x7F77;
/* ---- Reserved area(2 byte) ---- */

// SWIM
volatile char SWIM @0x7F80;
/* ---- Reserved area(15 byte) ---- */

// DM
volatile char DM_BK1RE  @0x7F90;
volatile char DM_BK1RH  @0x7F91;
volatile char DM_BK1RL  @0x7F92;
volatile char DM_BK2RE  @0x7F93;
volatile char DM_BK2RH  @0x7F94;
volatile char DM_BK2RL  @0x7F95;
volatile char DM_CR1    @0x7F96;
volatile char DM_CR2    @0x7F97;
volatile char DM_CSR1   @0x7F98;
volatile char DM_CSR2   @0x7F99;
volatile char DM_ENFCTR @0x7F9A;
/* ---- Reserved area(5 byte) ---- */

// UART register mask
#define UART1_SR_TXE    0x80 // Transmit Data Register Empty mask 
#define UART1_SR_TC     0x40 // Transmission Complete mask
#define UART1_SR_RXNE   0x20 // Read Data Register Not Empty mask
#define UART1_SR_IDLE   0x10 // IDLE line detected mask
#define UART1_SR_OR     0x08 // OverRun error mask
#define UART1_SR_NF     0x04 // Noise Flag mask
#define UART1_SR_FE     0x02 // Framing Error mask
#define UART1_SR_PE     0x01 // Parity Error mask

#define UART1_BRR1_DIVM 0xFF // LSB mantissa of UART1DIV [7:0] mask

#define UART1_BRR2_DIVM 0xF0 // MSB mantissa of UART1DIV [11:8] mask
#define UART1_BRR2_DIVF 0x0F // Fraction bits of UART1DIV [3:0] mask

#define UART1_CR1_R8    0x80 // Receive Data bit 8 */
#define UART1_CR1_T8    0x40 // Transmit data bit 8 */
#define UART1_CR1_UARTD 0x20 // UART1 Disable (for low power consumption) */
#define UART1_CR1_M     0x10 // Word length mask
#define UART1_CR1_WAKE  0x08 // Wake-up method mask
#define UART1_CR1_PCEN  0x04 // Parity Control Enable mask
#define UART1_CR1_PS    0x02 // UART1 Parity Selection */
#define UART1_CR1_PIEN  0x01 // UART1 Parity Interrupt Enable mask

#define UART1_CR2_TIEN  0x80 // Transmitter Interrupt Enable mask
#define UART1_CR2_TCIEN 0x40 // Transmission Complete Interrupt Enable mask
#define UART1_CR2_RIEN  0x20 // Receiver Interrupt Enable mask
#define UART1_CR2_ILIEN 0x10 // IDLE Line Interrupt Enable mask
#define UART1_CR2_TEN   0x08 // Transmitter Enable mask
#define UART1_CR2_REN   0x04 // Receiver Enable mask
#define UART1_CR2_RWU   0x02 // Receiver Wake-Up mask
#define UART1_CR2_SBK   0x01 // Send Break mask

#define UART1_CR3_LINEN 0x40 // Alternate Function output mask
#define UART1_CR3_STOP  0x30 // STOP bits [1:0] mask
#define UART1_CR3_CKEN  0x08 // Clock Enable mask
#define UART1_CR3_CPOL  0x04 // Clock Polarity mask
#define UART1_CR3_CPHA  0x02 // Clock Phase mask
#define UART1_CR3_LBCL  0x01 // Last Bit Clock pulse mask

#define UART1_CR4_LBDIEN 0x40 // LIN Break Detection Interrupt Enable mask
#define UART1_CR4_LBDL   0x20 // LIN Break Detection Length mask
#define UART1_CR4_LBDF   0x10 // LIN Break Detection Flag mask
#define UART1_CR4_ADD    0x0F // Address of the UART1 node mask

#define UART1_CR5_SCEN  0x20 // Smart Card Enable mask
#define UART1_CR5_NACK  0x10 // Smart Card Nack Enable mask
#define UART1_CR5_HDSEL 0x08 // Half-Duplex Selection mask
#define UART1_CR5_IRLP  0x04 // Irda Low Power Selection mask
#define UART1_CR5_IREN  0x02 // Irda Enable mask


// TIM4 register mask
#define TIM4_CR1_CEN  0x01 // Counter Enable mask
#define TIM4_CR1_UDIS 0x02 // Update Disable mask
#define TIM4_CR1_URS  0x04 // Update Request Source mask
#define TIM4_CR1_OPM  0x08 // One Pulse Mode mask
#define TIM4_CR1_APRE 0x80 // Auto-Reload Preload Enable mask
#define TIM4_IER_UIE  0x01 // Update Interrupt Enable mask
#define TIM4_SR1_UIF  0x01 // Update Interrupt Flag mask
#define TIM4_EGR_UG   0x01 // Update Generation mask
#define TIM4_CNTR_CNT 0xFF // Counter Value mask
#define TIM4_PSCR_PSC 0x07 // Prescaler Value mask
#define TIM4_ARR_ARR  0xFF // Autoreload Value mask