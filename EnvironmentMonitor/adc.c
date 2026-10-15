#include"header.h"

void adc_init()
{
PINSEL1|=0x15400000;
ADCR=0X00200400;
}

#define DONE ((ADDR>>31)&1)
unsigned int adc_read(int ch_num)
{
unsigned int result=0;
ADCR|=(1<<ch_num);
ADCR|=(1<<24);
while(DONE==0);
ADCR^=(1<<24);
ADCR^=(1<<ch_num);
result=(ADDR>>6)&0x03ff;
return result;
}
