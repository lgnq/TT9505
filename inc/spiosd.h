#ifndef __SPIOSD_H__
#define __SPIOSD_H__

#include "main.h"

typedef struct rle2_header_s
{
    U08 id[2];        /*  IT : Intersil Techwell  */

    U08 op_bmpbits;
    U08 rledata_cnt;

    U16 w;
    U16 h;

    U32 size;

    U08 LUT_format;   /*  Bit0- 0:RGBa, 1:BGRa, bit1- 0:LUTS, 1:LUT;  */
    U08 LUT_colors;   /*  0xff:256 colors,  0x7F:128 colors,...  */

    U08 dummy0;
    U08 dummy1;
} rle2_header_t;

typedef struct image_header_s
{
    U32 lut_loc;
    U32 img_loc;

    U08 lut_type;     /*  1: luts, byte pointer method ; 0: lut , address method  */
    U08 bpp;          /*  bit per pixel  */
    U08 rle;          /*  compression ration,  upper: bpp , bottom : rle counter  */
    U16 dx, dy;       /*  width , height ( pixel )  */
    U16 lut_size;     /*  we don't need it. we can assume LUT size & image size.  */
} image_header_t;

#endif

