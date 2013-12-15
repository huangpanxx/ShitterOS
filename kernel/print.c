#include "print.h"

extern void put_chr(int x,int y,int chr); //from kernela.asm


void put_ch(int x,int y,BYTE chr,BYTE color) 
{
	put_chr(x, y, (color << 8) + (int)chr);
}


void put_str(int x,int y,BYTE color,const char* str) 
{
	int i;
	char c;
	for(i = 0; (c = str[i]) != 0;++i) {
		put_ch(x + i, y, c, color);
	}
}

