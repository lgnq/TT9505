#ifndef __MCU_H__
#define __MCU_H__

#include "typedefs.h"

#define RS_BUF_MAX 	32

void mcu_init(void);
void putchar(BYTE c);

void gpio_control(U08 gpio_no, U08 pin_no, U08 onoff);

#endif

