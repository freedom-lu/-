#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 9               //��
#define WIDE 9              //��
#define countOfMine 10       //�׵ĸ���
#define LENS LEN+2    
#define WIDES WIDE+2
//��ʼ�����飬words����Ҫ��ʼ����ʲô
void initBoard(int board[LENS][WIDES],int len, int wide, char words);
//չʾ��
void displayBoard(int board[LENS][WIDES], int len, int wide);
//������        1Ϊ�ף�0Ϊ����
void setMine(int board[LENS][WIDES], int len, int wide);

//�鿴һ��������Χ�ж��ٸ���
int num_IsNotMine(int mineboard[LENS][WIDES], int len, int wide);

//ɨ��
void doMine(int mineboard[LENS][WIDES], int showboard[LENS][WIDES], int len, int wide);
