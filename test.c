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
	//��ʼ������
	initBoard(mine, LENS, WIDES, '0');
	initBoard(show, LENS, WIDES, '*');
	//������
	setMine(mine, LEN, WIDE);
	//��ӡ
	displayBoard(mine, LEN, WIDE);
	displayBoard(show, LEN, WIDE);
	//�û���ʼɨ��
	doMine(mine, show, LEN, WIDE);
}
int main()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		manu();
		printf("������->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("���������������\n");
			break;
		}
	} while (input);
}