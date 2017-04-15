#ifndef __SPIFLASH_H__
#define __SPIFLASH_H__

#define DMA_NO_BUSY_CHECK  0
#define DMA_BUSY_CHECK  1

#define DMA_START  1

#define DMA_READ  0
#define DMA_WRITE  1

#define DMA_DEST_FONTRAM     0
#define DMA_DEST_CHIPREG     1
#define DMA_DEST_SOSD_LUT    2
#define DMA_DEST_MCU_XMEM    3

#define DMA_ACCESS_MODE_INC  0
#define DMA_ACCESS_MODE_DEC  1
#define DMA_ACCESS_MODE_FIX  2

#define DMA_CMD_COUNT_1  1
#define DMA_CMD_COUNT_2  2
#define DMA_CMD_COUNT_3  3
#define DMA_CMD_COUNT_4  4
#define DMA_CMD_COUNT_5  5

#define SPI_CMD_OPT_NONE          0x00
#define SPI_CMD_OPT_BUSY          0x04
#define SPI_CMD_OPT_WRITE         0x02
#define SPI_CMD_OPT_WRITE_BUSY    0x06
#define SPI_CMD_OPT_WRITE_BUSY_AUTO      0x16

/*
#-----------------------------------------------------------------------------
# SPI FLASH Command
#-----------------------------------------------------------------------------
*/
#define SPICMD_WRSR              0x01    //write status register
#define SPICMD_PP                0x02    //Page program
#define SPICMD_READ_SLOW         0x03    //Read data
#define SPICMD_WRDI              0x04    //write disable
#define SPICMD_RDSR              0x05    //read status register
#define SPICMD_WREN              0x06    //write enable
#define SPICMD_READ_FAST         0x0B    //fast read data
#define SPICMD_FASTDTRD          0x0D    //fast DT read
#define SPICMD_WRSR3             0x11    //write status register3(WB) 
#define SPICMD_RDCR              0x15    //read configuration register(Macronix)
#define SPICMD_RDSR3             0x15    //read status3 register(WB). dat[0]:4B
#define SPICMD_RDBR              0x16    //Read Volatile Bank Address Register (RDBR 16h/C8h) ISSI    
#define SPICMD_WRBRV             0x17    //Write Volatile Bank Address Register ISSI    
#define SPICMD_SE                0x20    //sector erase
#define SPICMD_RDINFO            0x2B    //read information register. S[2]=1:4byte mode 
#define SPICMD_RDSCUR            0x2B    //read security register
#define SPICMD_WRSCUR            0x2F    //write security register
#define SPICMD_CLSR              0x30    //clear SR fail flags
#define SPICMD_WRSR2             0x31    //write status register2(WB) 
#define SPICMD_RDSR2             0x35    //read status2 register(WB). dat[1]:QE
#define SPICMD_SBLK              0x36    //single block lock
#define SPICMD_4PP               0x38    //quad page program
#define SPICMD_SBULK             0x39    //single block unlock
#define SPICMD_READ_DUAL_O       0x3B    
#define SPICMD_RDBLOCK           0x3C    //block protect read
#define SPICMD_EXPLM             0x45    //exit parallel mode
#define SPICMD_CLRFREG           0x50    //clear flag status register(micron)
#define SPICMD_BE32K             0x52    //block erase 32KB
#define SPICMD_ENPLM             0x55    //enter parallel mode
#define SPICMD_CE                0x60    //chip erase. 0x60 or 0xC7
#define SPICMD_WDVEREG           0x61    //write volatile enhanced register(micron)
#define SPICMD_RDVEREG           0x65    //read volatile enhanced register(micron)
#define SPICMD_ENHBL             0x67    //enter high bank latch mode
#define SPICMD_WPSEL             0x68    //write protection selection
#define SPICMD_READ_QUAD_O       0x6B
#define SPICMD_RDFREG            0x70    //read flag status register(micron)
#define SPICMD_ESRY              0x70    //enable SO to output RY/BY#
#define SPICMD_GBLK              0x7E    //gang block lock
#define SPICMD_DSRY              0x80    //disable SO to output RY/BY#
#define SPICMD_WDVREG            0x81    //write volatile register(micron)
#define SPICMD_RDVREG            0x85    //read volatile register(micron)
#define SPICMD_REMS              0x90    //read electronic manufacturer & device ID
#define SPICMD_EXHBL             0x98    //exit high bank latch mode
#define SPICMD_GBULK             0x98    //gang block unlock
#define SPICMD_RDID              0x9F    //read identification.
#define SPICMD_HPM               0xA3    //high performance enable mode
#define SPICMD_RDP               0xAB    //Release from deep power down
#define SPICMD_RES               0xAB    //read electronic ID
#define SPICMD_CP                0xAD    //continusly program mode
#define SPICMD_QPIID             0xAF    //QPI ID read
#define SPICMD_WDNVREG           0xB1    //write non-volatile register(micron)
#define SPICMD_ENSO              0xB1    //enter secured OTP
#define SPICMD_RDNVREG           0xB5    //read non-volatile register(micron)
#define SPICMD_EN4B              0xB7    //enter 4Byte mode
#define SPICMD_DP                0xB9    //Deep power down
#define SPICMD_READ_DUAL_IO      0xBB    //2x I/O read command
#define SPICMD_2DTRD             0xBD    //dual I/O DT Read
#define SPICMD_EXSO              0xC1    //exit secured OTP
#define SPICMD_REMS4D            0xCF    //read ID for 4x I/O DT mode
#define SPICMD_BE                0xD8    //block erase 64KB
#define SPICMD_REMS4             0xDF    //read ID for 4x I/O mode
#define SPICMD_RDLOCK            0xE8    //read Lock register(micron)
#define SPICMD_EX4B              0xE9    //exit 4Byte mode
#define SPICMD_READ_QUAD_IO      0xEB    //4x I/O read command
#define SPICMD_4DTRD             0xED    //Quad I/O DT Read
#define SPICMD_REMS2             0xEF    //read ID for 2x I/O mode

void spi_flash_detect(void);

#endif

