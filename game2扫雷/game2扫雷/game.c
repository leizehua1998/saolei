#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols,char x)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = x;
		}
	}
}
//void DisplayBoard(char board[ROWS][COLS], int row, int col)
//{
//	int i, j;
//	//��ӡ�к�
//	for (i = 0; i <= col; i++)
//	{
//		printf("%d ", i);
//	}
//	printf("\n");
//	for (i = 1; i <= row; i++)
//	{
//		printf("%d ", i);
//		for (j = 1; j <= col; j++)
//		{
//			printf("%c ", board[i][j]);
//		}
//	printf("\n");
//	}
//}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	//��ӡ�к�
	for (i = 0; i <= col; i++)
	{
		printf("%d   ", i);//�к�
	}
	printf("\n\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d  ", i);//�к�
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col)
			{
				printf("|");
			}
		}
		int k = 0;
		if (i < row )
		{
			printf("\n   ");
			for (k = 0; k < col; k++)
			{
				printf("---"); //��ӡ�ָ���
				if (k< col-1 )
				{
					printf("|"); //��ӡ�ָ���
				}
			}
			printf("\n");
		}
	}
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count != 0)
	{
		int a = (rand()%row)+1;//1-9
		int b = (rand()%col)+1;
		if (board[a][b] =='0')
		{
			board[a][b] = '1';
			count--;
		}
	}
}
int GetMine(char mine[ROWS][COLS],int x,int y)
{
	   //'3'-'0'=3
	   return  mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';

}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	int x = 0;
	int y = 0;
	while (win<row*col-EASY_COUNT)
	{
		printf("\n�������Ų��׵����꣺\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			//�Ϸ�
			//����
			if (mine[x][y] == '1')
			{
				printf("�㱻ը����\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else//������
			{
				//ͳ����Χ�м�����
				int  num = GetMine(mine,x,y);
				show[x][y] =  num+'0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
			printf("���Ϸ�����,���������롣\n");
	}
	if (win == row*col - EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ���\n");
		DisplayBoard(mine, row, col);
	}
}









