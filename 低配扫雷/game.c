#include "game.h"
#define _CRT_SECURE_NO_WARNINGS

void initialize(char ar[hang][lie], char er[hangs][lies])
{
	int a, b, c;
	for ( c = 0; c <= hang; c++)
		printf("%d ", c);
	printf("\n");
	for (a = 0,c=1; a < hang; a++,c++)
	{
		printf("%d ", c);
		for (b = 0; b < lie; b++)
		{
			ar[a][b] = '*';
			printf("%c ", ar[a][b]);
		}
		printf("\n");
	}
	for (a = 0; a < hangs; a++)
	{
		for (b = 0; b < lies; b++)
		{
			er[a][b] = '0';
		}
	}
	bomds(er, zhadan);//雷的设置
}
void bomds(char er[hangs][lies], int bomd)
{
	int a, b;
	srand((unsigned int)time(NULL));
	while (bomd)
	{
		a = rand() % hang + 1;
		b = rand() % lie + 1;
		if (er[a][b] == '0')
		{
			er[a][b] = '1';
			bomd--;
		}
	}
}
void par(char ar[hang][lie])
{
	int a, b, c;
	for (c = 0; c <= hang; c++)
		printf("%d ", c);
	printf("\n");
	for (a = 0,c=1; a < hang; a++,c++)
	{
		printf("%d ", c);
		for (b = 0; b < lie; b++)
		{
			printf("%c ", ar[a][b]);
		}
		printf("\n");
	}
}
int handle(char ar[hang][lie], char er[hangs][lies], int a, int b)
{
	int sum;
	sum =hang*lie-zhadan;
	while (sum)
	{
		
			if (er[a][b] == '1')
			{
				printf("你太菜了\n");
				per(er);
				return 1;
			}
			else if (look(er, a, b))
			{
				ar[a - 1][b - 1] = look(er, a, b) + '0';
				par(ar);
				sum--;
				put(ar, er, &a, &b);
			}
			else
			{
				ar[a - 1][b - 1] = '0';
//				open(ar,er,a,b);
				par(ar);
				sum--;
				put(ar, er, &a, &b);
			}
			if (sum == 0)
			{
				printf("你赢了\n");
				per(er);
				return 1;
			}
			
	}
	
}
int look(char er[hangs][lies], int a, int b)
{
	return er[a - 1][b - 1] + er[a - 1][b] + er[a - 1][b + 1] + er[a][b - 1] + er[a][b + 1] + er[a + 1][b - 1] + er[a + 1][b] + er[a + 1][b + 1]-8*'0';
}
void per(char er[hangs][lies])
{
	int a, b;
	for (a = 1; a < hangs-1; a++)
	{
		for (b = 1; b < lies-1; b++)
		{
			printf("%c ", er[a][b]);
		}
		printf("\n");
	}
}
void put(char ar[hang][lie],char er[hangs][lies],int a,int b)
{
	do
	{
		printf("请输入探查坐标\n");
		scanf_s("%d%d", &a, &b);
		if (a >= 1 && a <= hang && b >= 1 && b <= lie)
		{
			if (handle(ar, er, a, b))
			{
				break;
			}
		}
		else
			printf("坐标非法，请重新输入\n");
	} while (1);
}


//void open(char ar[hang][lie], char er[hangs][lies], int a, int b)
//{
//	if (a >= 0 && b >= 0)
//	{
//
//		if (ar[a - 1][b - 1] != ' ' && look(er, a, b) + '0' == '0' && er[a][b] != '1')
//		{
//			ar[a - 1][b - 1] = ' ';
//			open(ar, er, a - 1, b - 1);
//			open(ar, er, a - 1, b);
//			open(ar, er, a - 1, b + 1);
//			open(ar, er, a, b - 1);
//			open(ar, er, a, b + 1);
//			open(ar, er, a + 1, b + 1);
//			open(ar, er, a + 1, b);
//			open(ar, er, a + 1, b - 1);
//		}
//		else
//		{
//			ar[a - 1][b - 1] = look(er, a, b) + '0';
//		}
//	}
//}