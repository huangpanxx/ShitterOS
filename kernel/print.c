#include "print.h"

extern void put_chr(int x,int y,int chr); //from kernela.asm


void put_ch(int x,int y,BYTE color,BYTE chr)
{
	put_chr(x, y, (color << 8) + (int)chr);
}


void put_str(int x,int y,BYTE color,const char* str) 
{
	int i;
	char c;
	for(i = 0; (c = str[i]) != 0;++i) {
		put_ch(x + i, y, color, c);
	}
}

void put_int(int x,int y,BYTE color,int v)
{
	int i = 0, n = x, b = v;
	while(b /= 10) ++n;
	if(v < 0) {
		put_ch(x, y, color, '-');
		v = -v;
		n += 1;
	}
	for(i = n; v != 0; --i) {
		put_ch(x + i, y, color, v % 10+'0');
		v /= 10;
	}
}

