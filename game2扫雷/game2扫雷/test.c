#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void game()
//1.布置雷2.排查雷
{
	//雷的信息存储
	char mine[ROWS][COLS] = { 0 };//布置雷信息
	char show[ROWS][COLS] = { 0 };//排查雷信息
	//初始化
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');
	//打印棋盘
	//DisplayBoard(mine,ROW,COL);
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine,ROW,COL);
	//DisplayBoard(mine, ROW, COL);
	//扫雷
	FindMine(mine,show,ROW,COL);
}
void mean()
{
	printf("####################\n");
	printf("####   1.paly   ####\n");
	printf("####   0.exit   ####\n");
	printf("####################\n");
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do{
		mean();
		printf("请输入:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出成功\n");
			break;
		default:
			printf("输入错误!重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}








