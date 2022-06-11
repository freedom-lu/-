#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"
//初始化
void initBoard(int board[LENS][WIDES], int len, int wide, char words)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < wide; j++)
		{
			board[i][j] = words;
		}
	}
}

//打印雷盘

void displayBoard(int board[LENS][WIDES], int len, int wide)
{
	for (int i = 0; i <= len; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= len; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= wide; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

//布置雷
void setMine(int board[LENS][WIDES], int len, int wide)
{
	int num = countOfMine;
	while (num)
	{
		int a = rand() % len + 1;  //随机数
		int b = rand() % wide + 1;  //随机数
		if (board[a][b] == '0')   //如果是0，代表此位置没有雷
		{
			board[a][b] = '1';   //没有雷那就放个雷
			num--;
		}
	}
}

//排查一个坐标旁边有多少个雷          周围8个，因为存储的时候用的是char类型，所以后面要减去8*'0'
num_IsNotMine(int mineboard[LENS][WIDES], int len, int wide)
{
	return mineboard[len][wide + 1] + mineboard[len][wide - 1]
		+ mineboard[len - 1][wide] + mineboard[len - 1][wide + 1] + mineboard[len - 1][wide - 1]
		+ mineboard[len + 1][wide] + mineboard[len + 1][wide + 1] + mineboard[len + 1][wide - 1] - 8 * '0';
}

int c = 0;
void dozero(int mineboard[LENS][WIDES], int showboard[LENS][WIDES], int a, int b)
{
	int num = num_IsNotMine(mineboard, a, b) + '0';
	showboard[a][b] = num;
	c++;
	//if (showboard[a][b] == '0')                   //本来想实现翻出一个0开出一大片的，但是这个代码貌似没错，可能是内存溢出了吧。。
	//{
	//	dozero(mineboard, showboard, a, b + 1);
	//	dozero(mineboard, showboard, a, b - 1);
	//	dozero(mineboard, showboard, a + 1, b);
	//	dozero(mineboard, showboard, a + 1, b-1);
	//	dozero(mineboard, showboard, a + 1, b+1);
	//	dozero(mineboard, showboard, a - 1, b);
	//	dozero(mineboard, showboard, a - 1, b+1);
	//	dozero(mineboard, showboard, a - 1, b-1);

	//}
	//else
	//{
	//	return;
	//}
}

//用户扫雷
void doMine(int mineboard[LENS][WIDES], int showboard[LENS][WIDES], int len, int wide)
{
	/*
	先让用户输入坐标
	如果输入超出范围，重新输入
	输入为雷，结束
	输入不是雷，告诉用户这个坐标旁边有几个雷
	*/
	int a, b;

	while (c<len*wide - countOfMine)    //判断用户是否把雷给扫完了
	{
		printf("请输入一个坐标\n");
		scanf("%d%d", &a, &b);                       //用户输入
		if ((a >= 1 && a <= len) && b >= 1 && b <= wide)
		{
			if (mineboard[a][b] == '1')
			{
				printf("恭喜你扫到雷了，你被炸死了\n");
				break;
			}
			else
			{
				dozero(mineboard, showboard, a, b);
				displayBoard(showboard, LEN, WIDE);
			}
		}
		else
		{
			printf("输入错误，请重新输入\n");
			displayBoard(showboard, len, wide);
		}
	}
	if (c == len * wide - countOfMine)         //如果用户把雷给扫完了要恭喜用户
	{
		printf("扫雷成功，恭喜你\n");
		displayBoard(showboard, LEN, WIDE);
	}
}
