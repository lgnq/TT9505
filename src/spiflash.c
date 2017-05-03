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
        Puts("MXIC");
    }
}

void spi_flash_dma_read2xmem(U16 dest_loc, U32 src_loc, U16 length)
{
    BYTE i;
    BYTE dma_option;
    volatile BYTE vdata;

    WriteTW88(REG4C3, (DMA_DEST_MCU_XMEM << 6) | (DMA_ACCESS_MODE_INC << 4) | DMA_CMD_COUNT_7);

    WriteTW88(REG4C6, (BYTE)(dest_loc>>8));   //Buffer index page or memory start address high byte
    WriteTW88(REG4C7, (BYTE)(dest_loc));      //Buffer index or memory start address low byte

    WriteTW88(REG4DA, (BYTE)(length >> 16) );    //Read/Write data count high byte after command
    WriteTW88(REG4C8, (BYTE)(length >> 8));      //Read/Write data count mid byte after command
    WriteTW88(REG4C9, (BYTE)length);             //Read/Write data count low byte after command

    WriteTW88(REG4CA, SPICMD_READ_QUAD_IO);
#if 0    
    WriteTW88(REG4CB, (BYTE)(src_loc >> 24));
    WriteTW88(REG4CC, (BYTE)(src_loc >> 16));
    WriteTW88(REG4CD, (BYTE)(src_loc >> 8));
    WriteTW88(REG4CE, (BYTE)(src_loc));
#else
    WriteTW88(REG4CB, (BYTE)(src_loc >> 16));
    WriteTW88(REG4CC, (BYTE)(src_loc >> 8));
    WriteTW88(REG4CD, (BYTE)(src_loc));
#endif

    /*  dma option  */
    dma_option = 0x04;                          /*  SPIDMA_BUSYCHECK  */

    /*  DMA-start  */
    WriteTW88(REG4C4, 0x01 | dma_option);	

    /*  wait done  */
    for (i = 0; i < 200; i++)
    {
        vdata = ReadTW88(REG4C4);
        if ((vdata & 0x01) == 0)
        {
            break;
        }
        
        //OSTimeDly(1);
    }

    if (i == 200)
    {
        printf("\nSpiFlashDmaWait DMA Busy. LINE:%d", __LINE__);
        return;	                                /*   fail:busy  */
    }
}


