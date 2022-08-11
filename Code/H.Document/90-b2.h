/* 2152189 信04 汪林辉 */
#pragma once


#define BG_COLOR 14     //此处设置draw函数背景颜色为黄色
#define Coord_X 5       //此处设置deluxe_draw函数左上角第一个图案的横坐标
#define Coord_Y 3       //此处设置deluxe_draw函数左上角第一个图案的纵坐标


#include "lib_mto10_net_tools.h"
#include "cmd_console_tools.h"
#include <iomanip>
#include <conio.h>
#include <time.h>
#include <Windows.h>

//base函数声明
void in_which_huang(int ROW, int COLUMN, int X, int Y, int* Record_X, int* Record_Y);
void seek_same_1(int a[8][10], char sub_a[8][10], int ROW, int COLUMN, int X, int Y);
void drop(int a[8][10], char sub_a[8][10], int ROW, int COLUMN, int X, int Y);
void picture(int num, int X, int Y, int bg_color, int fg_color);
void seek_same_2(int a[8][10], char sub_a[8][10], int X, int Y);
void input_COORD(int* rows, int* cols, int ROW, int COLUMN);
void input_RCG(int* ROW, int* COLUMN, int* goal, int menu);
int score(int a[8][10], char sub_a[8][10], int X, int Y);
void pause(int ROW, const char* prompt, bool Enter);
bool in_kuang_ma(int ROW, int COLUMN, int X, int Y);
bool in_this_kuang_ma(int k, int i, int X, int Y);
int check(int a[8][10], int X, int Y);
void Enter(const char* prompt);
int Generate_num(int maxium);
void cover(int x, int y);
int a_max(int a[8][10]);
void End();


//tool函数声明
bool over(int a[8][10], int ROW, int COLUMN);
void initialize_array(int a[8][10], int ROW, int COLUMN);
void prepare(int menu, int a[8][10], char sub_a[8][10], int ROW, int COLUMN, int goal);
void deluxe_pre(int menu, int a[8][10], char sub_a[8][10], int ROW, int COLUMN, int goal);
