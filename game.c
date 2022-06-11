#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"
//��ʼ��
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

//��ӡ����

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

//������
void setMine(int board[LENS][WIDES], int len, int wide)
{
	int num = countOfMine;
	while (num)
	{
		int a = rand() % len + 1;  //�����
		int b = rand() % wide + 1;  //�����
		if (board[a][b] == '0')   //�����0�������λ��û����
		{
			board[a][b] = '1';   //û�����ǾͷŸ���
			num--;
		}
	}
}

//�Ų�һ�������Ա��ж��ٸ���          ��Χ8������Ϊ�洢��ʱ���õ���char���ͣ����Ժ���Ҫ��ȥ8*'0'
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
	//if (showboard[a][b] == '0')                   //������ʵ�ַ���һ��0����һ��Ƭ�ģ������������ò��û���������ڴ�����˰ɡ���
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

//�û�ɨ��
void doMine(int mineboard[LENS][WIDES], int showboard[LENS][WIDES], int len, int wide)
{
	/*
	�����û���������
	������볬����Χ����������
	����Ϊ�ף�����
	���벻���ף������û���������Ա��м�����
	*/
	int a, b;

	while (c<len*wide - countOfMine)    //�ж��û��Ƿ���׸�ɨ����
	{
		printf("������һ������\n");
		scanf("%d%d", &a, &b);                       //�û�����
		if ((a >= 1 && a <= len) && b >= 1 && b <= wide)
		{
			if (mineboard[a][b] == '1')
			{
				printf("��ϲ��ɨ�����ˣ��㱻ը����\n");
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
			printf("�����������������\n");
			displayBoard(showboard, len, wide);
		}
	}
	if (c == len * wide - countOfMine)         //����û����׸�ɨ����Ҫ��ϲ�û�
	{
		printf("ɨ�׳ɹ�����ϲ��\n");
		displayBoard(showboard, LEN, WIDE);
	}
}
