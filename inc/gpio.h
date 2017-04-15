#ifndef __GPIO_H__
#define __GPIO_H__

# include "main.h"

void gpio_control(U08 gpio_no, U08 pin_no, U08 onoff);
void led1_control(U08 onoff);
void backlight_control(U08 onoff);
void avdd_control(U08 onoff);
void lcd_reset_control(U08 onoff);

#endif

