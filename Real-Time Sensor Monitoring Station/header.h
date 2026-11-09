#include <lpc21xx.h>

extern void adc_init(void);
extern unsigned int adc_read(int );
extern void delay_ms(unsigned int );
extern void delay_sec(unsigned int);
extern void uart0_init(unsigned int);
extern void uart0_tx(unsigned char );
extern unsigned char uart0_rx(void);
extern void uart0_tx_string(const char *);
extern void uart0_tx_integer(int );
extern void uart0_tx_float(float );
extern void timer0_init(void);
extern void timer0_handler(void) __irq;
extern void config_vic(void);


