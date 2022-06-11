#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 9               //行
#define WIDE 9              //列
#define countOfMine 10       //雷的个数
#define LENS LEN+2    
#define WIDES WIDE+2
//初始化数组，words代表要初始化成什么
void initBoard(int board[LENS][WIDES],int len, int wide, char words);
//展示表
void displayBoard(int board[LENS][WIDES], int len, int wide);
//布置雷        1为雷，0为非雷
void setMine(int board[LENS][WIDES], int len, int wide);

//查看一个坐标周围有多少个雷
int num_IsNotMine(int mineboard[LENS][WIDES], int len, int wide);

//扫雷
void doMine(int mineboard[LENS][WIDES], int showboard[LENS][WIDES], int len, int wide);
