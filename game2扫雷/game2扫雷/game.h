#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2 
#define EASY_COUNT 10//À×Êý
void InitBoard(char mine[ROWS][COLS], int rows, int cols,char x);
void DisplayBoard(char mine[ROWS][COLS],int row,int col);
void SetMine(char mine[ROWS][COLS],int row,int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
