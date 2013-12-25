#ifndef PRINT_H
#define PRINT_H

#include "type.h"

//打印字符到屏幕
void put_ch(int x,int y, BYTE color, BYTE chr);

//打印字符串到屏幕
void put_str(int x,int y,BYTE color,const char* str);

//打印数字到屏幕
void put_int(int x,int y,BYTE color,int v);


#endif

