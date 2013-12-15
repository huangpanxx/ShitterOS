#ifndef PRINT_H
#define PRINT_H

#include "type.h"

//打印字符到屏幕
void put_ch(int x,int y,BYTE chr, BYTE color);

//打印字符串到屏幕
void put_str(int x,int y,BYTE color,const char* str);


#endif

