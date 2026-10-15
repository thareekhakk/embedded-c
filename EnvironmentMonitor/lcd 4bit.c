#include"header.h"
#define RS (1<<17)
#define RW (1<<18)
#define EN (1<<19)
void lcd_cmd(unsigned char cmd)
{
unsigned int temp;
IOCLR1=0X00FE0000;
temp=(cmd&0xf0)<<16;
IOSET1=temp;
IOCLR1=RS;
IOCLR1=RW;
IOSET1=EN;
delay_ms(2);
IOCLR1=EN;
IOCLR1=0X00FE0000;
temp=(cmd&0x0f)<<20;
IOSET1=temp;
IOCLR1=RS;
IOCLR1=RW;
IOSET1=EN;
delay_ms(2);
IOCLR1=EN;
}

void lcd_data(unsigned char data)
{
unsigned int temp;
IOCLR1=0X00FE0000;
temp=(data&0xf0)<<16;
IOSET1=temp;
IOSET1=RS;
IOCLR1=RW;
IOSET1=EN;
delay_ms(2);
IOCLR1=EN;
IOCLR1=0X00FE0000;
temp=(data&0x0f)<<20;
IOSET1=temp;
IOSET1=RS;
IOCLR1=RW;
IOSET1=EN;
delay_ms(2);
IOCLR1=EN;
}

void lcd_init(void)
{
IODIR1|=0X00FE0000;
PINSEL2=0;
lcd_cmd(0x02);
lcd_cmd(0x03);
lcd_cmd(0x28);
lcd_cmd(0x0e);
lcd_cmd(0x01);
}

void lcd_string(const char *p)
{
while(*p)
{
lcd_data(*p);
p++;
}
}

void lcd_integer(int num)
{
int i;
char a[10];
if(num<0)
{
lcd_data('-');
num=-num;
}
if(num==0)
{
lcd_data('0');
return;
}
for(i=0;num;i++,num=num/10)
a[i]=num%10+48;
for(i--;i>=0;i--)
lcd_data(a[i]);
}

void lcd_float(float f)
{
int num;
if(f<0)
{
lcd_data('-');
f=-f;
}
if(f==0)
{
lcd_string("0.0");
return;
}
num=f;
lcd_integer(num);
lcd_data('.');
num=(f-num)*100;
lcd_integer(num);
}

unsigned char a[]={0x0e,0x1f,0x15,0x1f,0x15,0x15,0x11,0x0e};
unsigned char a1[]={0x17,0x14,0x14,0x1f,0x05,0x05,0x1D,0x00};

void lcd_cgram(void)
{
int i;
lcd_cmd(0x40);
for(i=0;i<8;i++)
lcd_data(a[i]);
lcd_cmd(0x48);
for(i=0;i<8;i++)
lcd_data(a1[i]);
}
