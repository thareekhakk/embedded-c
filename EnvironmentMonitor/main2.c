#include "header.h"

#define water ((IOPIN0>>5)&1)

int main()
{
    unsigned int temp_adc;
    unsigned int ldr_adc;
    unsigned int soil_adc;

    float vout,temp;
    unsigned int soil_percent;

    char status;

    adc_init();
    lcd_init();
    uart0_init(9600);

    IODIR0 = 1<<17 | 1<<18 | 1<<19;

    IOSET0 = 1<<17 | 1<<18 | 1<<19;


    while(1)
    {
        // Read LM35

        temp_adc = adc_read(1);

        vout = (temp_adc * 3.3) / 1023;

        temp = vout / 0.01;


        // Read LDR 

        ldr_adc = adc_read(2);


        // Read Soil Moisture 

        soil_adc = adc_read(3);

        soil_percent = (soil_adc * 100) / 1023;


        /*
          Status
         
          0 = SAFE
          1 = HOT
          2 = DARK
          3 = WATER
         */

        status = 0;


        if(temp > 40)
        {
            status = 1;
        }
        else if(ldr_adc > 700)
        {
            status = 2;
        }
        else if(soil_percent < 30)
        {
            status = 3;
        }
        else if(water == 1)
        {
            status = 4;
        }


        // LCD 

        lcd_cmd(0x80);

        lcd_string("TEMP : ");
        lcd_float(temp);
        lcd_string(" C");


        lcd_cmd(0xC0);

        if(status == 0)
        {
            lcd_string("STATUS: SAFE");
        }
        else if(status == 1)
        {
            lcd_string("STATUS: HOT");
        }
        else if(status == 2)
        {
            lcd_string("STATUS: DARK");
        }
        else if(status == 3)
        {
            lcd_string("STATUS: WATER");
        }
        else if(status == 4)
        {
            lcd_string("STATUS: ALERT");
        }


        // UART 

        uart0_tx_string("Temperature : ");
        uart0_tx_float(temp);
        uart0_tx_string(" C\r\n");


        uart0_tx_string("Light Level : ");

        if(ldr_adc > 700)
        {
            uart0_tx_string("LOW\r\n");
        }
        else
        {
            uart0_tx_string("NORMAL\r\n");
        }


        uart0_tx_string("Soil Moisture : ");
        uart0_tx_float(soil_percent);
        uart0_tx_string(" %\r\n");


        uart0_tx_string("Water Sensor : ");

        if(water == 1)
        {
            uart0_tx_string("DETECTED\r\n");
        }
        else
        {
            uart0_tx_string("NOT DETECTED\r\n");
        }


        uart0_tx_string("System Status : ");

        if(status == 0)
        {
            uart0_tx_string("SAFE\r\n");
        }
        else if(status == 1)
        {
            uart0_tx_string("HOT\r\n");
        }
        else if(status == 2)
        {
            uart0_tx_string("DARK\r\n");
        }
        else if(status == 3)
        {
            uart0_tx_string("WATER\r\n");
        }
        else
        {
            uart0_tx_string("ALERT\r\n");
        }


        // LED Indication 

        IOSET0 = 1<<17 | 1<<18 | 1<<19;


        if(status == 0)
        {
            IOCLR0 = 1<<17;

            uart0_tx_string("LED Status : GREEN\r\n");
        }
        else if(status == 1)
        {
            IOCLR0 = 1<<18;

            uart0_tx_string("LED Status : YELLOW\r\n");
        }
        else
        {
            IOCLR0 = 1<<19;

            uart0_tx_string("LED Status : RED\r\n");
        }


        uart0_tx_string("\r\n");
    }
}
