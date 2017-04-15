#include "main.h"

void spi_flash_detect(void)
{
    U08 manufacture_id;
    U08 device_id_1;
    U08 device_id_2;
    
    WriteTW88(0x4C3, (DMA_DEST_CHIPREG << 6) | DMA_CMD_COUNT_1);

    //read id command
    WriteTW88(0x4CA, SPICMD_RDID);

    WriteTW88(0x4C6, 0x04);    //I2C DMA buffer index page  0x4D0 
    WriteTW88(0x4C7, 0xD0);    //I2C DMA buffer index

    //read data length
    WriteTW88(0x4C5, 0x00);    //I2C DMA Read/Write data count high byte after command
    WriteTW88(0x4C8, 0x00);    //I2C DMA Read/Write data count mid byte after command
    WriteTW88(0x4C9, 0x03);    //I2C DMA Read/Write data count low byte after command

    //start DMA write (no BUSY check)
    WriteTW88(0x4C4, (DMA_NO_BUSY_CHECK<<2) | (DMA_READ<<1) | DMA_START);
    
    //wait while I2C DMA Start command execution bit is cleared
    while (ReadTW88(0x4C4) & 0x01)
        ;

    manufacture_id = ReadTW88(0x4D0);
    device_id_1    = ReadTW88(0x4D1);
    device_id_2    = ReadTW88(0x4D2);
    
    if (manufacture_id == 0xC2)
    {
        putchar('M');
        putchar('X');
    }
}

