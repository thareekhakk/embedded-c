#include<lpc21xx.h>

extern void lcd_cmd(unsigned char cmd);
extern void lcd_data(unsigned char data);
extern void lcd_init(void);
extern void lcd_string(const char *p);
extern void lcd_integer(int num);
extern void lcd_float(float f);
extern void lcd_cgram(void);
extern void adc_init();
extern unsigned int adc_read(int ch_num);
extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx(void);
extern void uart0_tx_string(const char *p);
extern void uart0_rx_string(char *p,unsigned int max_size);
extern void uart0_tx_integer(int num);
extern void uart0_tx_float(float f);
extern int uart0_rx_integer();
extern float uart0_rx_float();
extern void delay_ms(unsigned int ms);
extern void delay_sec(unsigned int sec);
