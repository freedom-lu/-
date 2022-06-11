#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"
void manu()
{
	printf("***************************************\n");
	printf("***************************************\n");
	printf("*******                           *****\n");
	printf("*******    Input 1:start game     *****\n");
	printf("*******      Input 0 : exit       *****\n");
	printf("*******                           *****\n");
	printf("***************************************\n");
	printf("***************************************\n");
}
void game()
{
	int mine[LENS][WIDES];
	int show[LENS][WIDES];
	//初始化棋盘
	initBoard(mine, LENS, WIDES, '0');
	initBoard(show, LENS, WIDES, '*');
	//布置雷
	setMine(mine, LEN, WIDE);
	//打印
	displayBoard(mine, LEN, WIDE);
	displayBoard(show, LEN, WIDE);
	//用户开始扫雷
	doMine(mine, show, LEN, WIDE);
}
int main()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		manu();
		printf("请输入->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，重新输入\n");
			break;
		}
	} while (input);
}