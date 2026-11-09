
#include "header.h"
void timer0_init(void)
{
   int a[]={15,60,30,15,15}; 
	
   T0PR = a[VPBDIV]*10000-1;
    T0PC=0;
    T0TCR = 0x02;      
    T0MR0 = 100;     
    T0MCR = 0x03;     
    T0IR = 0xff;
    T0TCR = 0x01;  
}


	unsigned int flag=0;
	int c=0;
void timer0_handler(void) __irq
{
flag=0;
    c++;
	if(c==3)
    flag=1;
	if(c==8)
	flag=2;
	if(c==18)
	flag=3;
	if(c>18)
	c=0;
    T0IR = 1;         
    VICVectAddr = 0;   
}

void config_vic(void)
{
    VICIntSelect = 0;              
    VICVectCntl0 = 4 | (1 << 5);  
    VICVectAddr0 = (unsigned int)timer0_handler;
    VICIntEnable = (1 << 4);  
}
