#include "main.h"

void header_parse(U32 spi_addr)
{
    rle2_header_t header;

    spi_flash_dma_read2xmem((U16)&header, spi_addr, 16);

    printf("\r\nid[0] = 0x%bx", header.id[0]);
    printf(" id[1] = 0x%bx", header.id[1]);
    printf("\r\nop_bmpbits = 0x%bx", header.op_bmpbits);
    printf("\r\nrledata_cnt = 0x%bx", header.rledata_cnt);
    printf("\r\nw = 0x%x", header.w);
    printf("\r\nh = 0x%x", header.h);
}

void img_display(BYTE winno, WORD spi_addr, WORD x, WORD y, BYTE alpha_mode, BYTE alpha, BYTE lut_offset)
{
}

