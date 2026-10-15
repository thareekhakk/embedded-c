#include"header.h"

void delay_ms(unsigned int ms)
{
int a[]={15,60,30,15,15};
T0PC=0;//STARTING VALUE
T0PR=a[VPBDIV]*1000-1;//ending value
T0TC=0;
T0TCR=1;//start timer
while(T0TC<ms);//count overflow
T0TCR=0;//stop timer
}

void delay_sec(unsigned int sec)
{
int a[]={15,60,30,15,15};
T0PC=0;//STARTING VALUE
T0PR=a[VPBDIV]*1000000-1;
T0TC=0;
T0TCR=1;
while(T0TC<sec);
T0TCR=0;
}
