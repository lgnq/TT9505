#include "main.h"

void gpio_control(U08 gpio_no, U08 pin_no, U08 onoff)
{
    switch (gpio_no)
    {
        case 0:
            WriteTW88((GPIO_EN0), ReadTW88(GPIO_EN0) | 1<<pin_no);
            WriteTW88((GPIO_OE0), ReadTW88(GPIO_OE0) | 1<<pin_no);

            if (onoff == ON)
                WriteTW88(GPIO_OD0, ReadTW88(GPIO_OD0) | 1<<pin_no);
            else
                WriteTW88(GPIO_OD0, ReadTW88(GPIO_OD0) & ~(1<<pin_no));
            break;
        case 1:
            WriteTW88((GPIO_EN1), ReadTW88(GPIO_EN1) | 1<<pin_no);
            WriteTW88((GPIO_OE1), ReadTW88(GPIO_OE1) | 1<<pin_no);

            if (onoff == ON)
                WriteTW88(GPIO_OD1, ReadTW88(GPIO_OD1) | 1<<pin_no);
            else
                WriteTW88(GPIO_OD1, ReadTW88(GPIO_OD1) & ~(1<<pin_no));
            break;
        case 2:
            WriteTW88((GPIO_EN2), ReadTW88(GPIO_EN2) | 1<<pin_no);
            WriteTW88((GPIO_OE2), ReadTW88(GPIO_OE2) | 1<<pin_no);

            if (onoff == ON)
                WriteTW88(GPIO_OD2, ReadTW88(GPIO_OD2) | 1<<pin_no);
            else
                WriteTW88(GPIO_OD2, ReadTW88(GPIO_OD2) & ~(1<<pin_no));
            break;
        case 3:
            WriteTW88((GPIO_EN3), ReadTW88(GPIO_EN3) | 1<<pin_no);
            WriteTW88((GPIO_OE3), ReadTW88(GPIO_OE3) | 1<<pin_no);

            if (onoff == ON)
                WriteTW88(GPIO_OD3, ReadTW88(GPIO_OD3) | 1<<pin_no);
            else
                WriteTW88(GPIO_OD3, ReadTW88(GPIO_OD3) & ~(1<<pin_no));
            break;
        case 4:
            WriteTW88((GPIO_EN4), ReadTW88(GPIO_EN4) | 1<<pin_no);
            WriteTW88((GPIO_OE4), ReadTW88(GPIO_OE4) | 1<<pin_no);

            if (onoff == ON)
                WriteTW88(GPIO_OD4, ReadTW88(GPIO_OD4) | 1<<pin_no);
            else
                WriteTW88(GPIO_OD4, ReadTW88(GPIO_OD4) & ~(1<<pin_no));
            break;
        case 5:
            WriteTW88((GPIO_EN5), ReadTW88(GPIO_EN5) | 1<<pin_no);
            WriteTW88((GPIO_OE5), ReadTW88(GPIO_OE5) | 1<<pin_no);

            if (onoff == ON)
                WriteTW88(GPIO_OD5, ReadTW88(GPIO_OD5) | 1<<pin_no);
            else
                WriteTW88(GPIO_OD5, ReadTW88(GPIO_OD5) & ~(1<<pin_no));
            break;            
        case 6:
            WriteTW88((GPIO_EN6), ReadTW88(GPIO_EN6) | 1<<pin_no);
            WriteTW88((GPIO_OE6), ReadTW88(GPIO_OE6) | 1<<pin_no);
        
            if (onoff == ON)
                WriteTW88(GPIO_OD6, ReadTW88(GPIO_OD6) | 1<<pin_no);
            else
                WriteTW88(GPIO_OD6, ReadTW88(GPIO_OD6) & ~(1<<pin_no));
            break;  
    }
}

void led1_control(U08 onoff)
{
    gpio_control(2, 0, onoff);
}

void backlight_control(U08 onoff)
{
    if (onoff == ON)
        gpio_control(2, 7, 0);
    else
        gpio_control(2, 7, 1);
}

void avdd_control(U08 onoff)
{
    gpio_control(3, 5, onoff);
}

void lcd_reset_control(U08 onoff)
{
    gpio_control(2, 6, onoff);
}

