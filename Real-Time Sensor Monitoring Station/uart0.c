#include"header.h"

void uart0_init(unsigned int baud)
{
int a[]={15,60,30,15,15};
unsigned int pclk=a[VPBDIV]*1000000;
unsigned int result=pclk/(16*baud);
PINSEL0|=0X05;
U0LCR=0X83;
U0DLL=result&0xff;
U0DLM=(result>>8)&0xff;
U0LCR=0X03;
}

#define THRE ((U0LSR>>5)&1)
#define RDR (U0LSR&1)

void uart0_tx(unsigned char data)
{
U0THR=data;
while(THRE==0);
}

unsigned char uart0_rx(void)
{
while(RDR==0);
return U0RBR;
}

void uart0_tx_string(const char *p)
{
while(*p)
{
U0THR=*p;
while(THRE==0);
p++;
}
}

void uart0_rx_string(char *p,unsigned int max_size)
{
int i;
for(i=0;i<max_size;i++)
{
while(RDR==0);
p[i]=U0RBR;
if(p[i]=='\r')
break;
}
p[i]='\0';
}


void uart0_tx_integer(int num)
{
char a[10];
int i;
if(num<0)
{
uart0_tx('-');
num=-num;
}
if(num==0)
{
uart0_tx('0');
return;
}
for(i=0;num;num=num/10,i++)
a[i]=num%10+48;
for(--i;i>=0;i--)
uart0_tx(a[i]);
}

void uart0_tx_float(float f)
{
int num;
if(f<0)
{
uart0_tx('-');
f=-f;
}
if(f==0)
{
uart0_tx_string("0.0");
return;
}
num=f;
uart0_tx_integer(num);
uart0_tx('.');
num=(f-num)*100;
uart0_tx_integer(num);
}

 /*
int uart0_rx_integer()
{
int i,num1;
char s[10];
uart0_rx_string(s,10);
if(s[0]=='-' || s[0]=='+')
i=1;
else
i=0;

for(i,num1=0;s[i];i++)
{
num1=num1*10+(s[i]-48);
}
if(s[0]=='-')
num1=-num1;
return num1;
}*/


