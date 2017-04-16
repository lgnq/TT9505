#include "main.h"

#include <stdarg.h>
//#include "inputctrl.h"

CODE BYTE Hex[] = "0123456789ABCDEF";	//static

BYTE FOsdMsgBuff[50];  //for FontOsd Message
					   //NOTE: If you have more than 40, system will be corrupted.

void DoPrint(const char *fmt, va_list ap)
{
	char  ch;
	char  i;
	long  value;
	bit   fl_zero;
	bit   fl_num;
	BYTE  fl_len;
	BYTE  cnt;
	DWORD mask=1;

	char *ptr;

	while (1)
    {
		//----- Find Formatter % -----

		switch (ch = *fmt++) 
        {
			case 0:		return;
			case '%':	if ( *fmt != '%' ) break;
						fmt++;
			default:	putchar(ch);
						continue;
		}

		//----- Get Count -------------
		
		fl_zero = 0;
		fl_num = 0;
		cnt = 0;

		ch = *fmt++;

		if (ch == '0') 
        {
			fl_zero = 1;
			ch = *fmt++;
			cnt = ch - '0';
			ch = *fmt++;
		}
		else if( ch>='0' && ch<='9' ) {
			cnt = ch - '0';
			ch = *fmt++;
		}

		//----- Get char(B) / int / long(L) ----------------

		fl_len = 2;

		switch(ch) 
        {
		case 'l':
		case 'L':	ch = *fmt++;	fl_len = 4;		break;
		case 'b':
		case 'B':	ch = *fmt++;	fl_len = 1;		break;
		}		

		//----- Get Type Discriptor -----
		
		switch( ch ) {

			case 'd':
			case 'u':

				switch (fl_len) {
				case 1:
					if( ch=='d' ) value = (char)va_arg( ap, char );
					else          value = (BYTE)va_arg( ap, BYTE );
					break;

				case 2:
					if( ch=='d' ) value = (int)va_arg( ap,  int );
					else          value = (WORD)va_arg( ap, WORD );
					break;

				case 4:
					if( ch=='d' ) value = (long)va_arg( ap, long );
					else          value = (DWORD)va_arg( ap, DWORD );
					break;
				}

				if( value<0 ) {
					putchar('-');
					value = value*(-1);
				}

				if(cnt==0) {
					if( value==0 ) { putchar('0'); continue; }

					for(cnt=0, mask=1; cnt<10; cnt++) {
						if( (value/mask)==0 ) break;
						mask = mask*10;
					}
				}

				for(i=0, mask=1; i<cnt-1; i++) mask = mask*10;

				while(1) {
					ch = (value / mask) + '0';
					if( ch=='0' && fl_zero==0 && mask!=1 ) ch=' ';
					else fl_zero = 1;
					putchar(ch);

					value = value % (mask);
					mask = mask / 10;
					
					if( mask==0 )
						break;
				}
				continue;

			case 'x':
			case 'X':

				switch (fl_len) {
				case 1:	value = (BYTE)va_arg( ap, BYTE );		break;
				case 2:	value = (WORD)va_arg( ap, WORD );		break;
				case 4:	value = (DWORD)va_arg( ap, DWORD );		break;
				}

				if(cnt==0) cnt = fl_len*2;

				for(i=0; i<cnt; i++) {
					putchar( Hex[(value >> (cnt-i-1)*4) & 0x000f] );
				}
				continue;

			case 's':

				ptr = (char *)va_arg( ap, char* );
				while(*ptr!='\0')
					putchar(*ptr++);
				continue;

			case 'c':
				value = va_arg( ap, char );
					putchar((BYTE)value);
				continue;

			default:
				value = (WORD)va_arg( ap, int );
				continue;
		}
	}
}

//=============================================================================
//                                                                           
//=============================================================================
//BKTODO: If compiler use a register parameter, it will have a trouble.
/**
* printf
*
* use %bx or %bd for BYTE.
*/
void printf(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	DoPrint(fmt, ap);
	va_end(ap);
}

void Puts( char *ptr )
{
	while (*ptr != '\0')
		putchar(*ptr++);
}

