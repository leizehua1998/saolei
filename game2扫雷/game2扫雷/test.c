#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void game()
//1.������2.�Ų���
{
	//�׵���Ϣ�洢
	char mine[ROWS][COLS] = { 0 };//��������Ϣ
	char show[ROWS][COLS] = { 0 };//�Ų�����Ϣ
	//��ʼ��
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');
	//��ӡ����
	//DisplayBoard(mine,ROW,COL);
	DisplayBoard(show, ROW, COL);
	//������
	SetMine(mine,ROW,COL);
	//DisplayBoard(mine, ROW, COL);
	//ɨ��
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
		printf("������:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳��ɹ�\n");
			break;
		default:
			printf("�������!����ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}








