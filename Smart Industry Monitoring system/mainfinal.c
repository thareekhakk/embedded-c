#include "header.h"

#define worker ((IOPIN0>>30)&1)
#define flame  ((IOPIN0>>5)&1)

int main()
{
    unsigned int adc_val;
    float vout=0,temp=0;
    char safe=0;

    adc_init();
    lcd_init();
    uart0_init(9600);

   IODIR0 = 1<<17 | 1<<18 | 1<<19;

   IOSET0 = 1<<17 | 1<<18 | 1<<19;

    while(1)
    {
        adc_val = adc_read(1);       // LM35 connected on P0.28
        delay_ms(10);
        vout = (adc_val * 3.3) / 1023;

        temp = vout / 0.01;

        delay_ms(20);     

        if((worker == 1) || (flame == 1))
        {
            safe = 0;
        }
        else
        {
            safe = 1;
        }


        // LCD 

        lcd_cmd(0x80);

        lcd_string("TEMP : ");
        lcd_float(temp);
        lcd_string(" C");

        lcd_cmd(0xC0);

        if(safe == 1)
        {
            lcd_string("STATUS: SAFE");
        }
        else
        {
            lcd_string("STATUS: NOT SAFE");
        }


        // UART

        uart0_tx_string("Temperature : ");
        uart0_tx_float(temp);
        uart0_tx_string(" C\r\n");

        uart0_tx_string("PIR Sensor : ");

        if(worker == 1)
        {
            uart0_tx_string("Worker Detected\r\n");
        }
        else
        {
            uart0_tx_string("Worker Not Detected\r\n");
        }


        uart0_tx_string("Flame Sensor : ");

        if(flame == 1)
        {
            uart0_tx_string("FIRE DETECTED\r\n");
        }
        else
        {
            uart0_tx_string("No Fire Detected\r\n");
        }


        uart0_tx_string("Machine Status : ");

        if(safe == 1)
        {
            uart0_tx_string("SAFE\r\n");
        }
        else
        {
            uart0_tx_string("NOT SAFE\r\n");
        }


        // LED 

       IOSET0 = 1<<17 | 1<<18 | 1<<19;
        if(safe == 0)
        {
            IOCLR0 = 1<<19;       // RED LED

            uart0_tx_string("LED Status : RED LED ON\r\n");
        }
        else if(temp > 40)
        {
            IOCLR0 = 1<<18;       // YELLOW LED

            uart0_tx_string("LED Status : YELLOW LED ON\r\n");
        }
        else
        {
            IOCLR0 = 1<<17;       // GREEN LED

            uart0_tx_string("LED Status : GREEN LED ON\r\n");
        }


        uart0_tx_string("\r\n");
    }
}
