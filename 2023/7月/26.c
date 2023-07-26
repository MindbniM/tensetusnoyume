#include "game.h"
#define _CRT_SECURE_NO_WARNINGS

int sum;
sum = hang * lie - zhadan;
void initialize(char ar[hangs][lies], char er[hangs][lies])
{
	int a, b, c;
	
	for (a = 0; a < hangs; a++)
	{
		for (b = 0; b < lies; b++)
		{
			ar[a][b] = '*';
		}
	}
	for (c = 0; c <= hang; c++)
		printf("%d ", c);
	printf("\n");
	for (a = 1,c=1; a <= hang; a++, c++)
	{
		printf("%d ", c);
		for (b = 1; b <= lie; b++)
		{

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
void par(char ar[hangs][lies])
{
	int a, b, c;
	for (c = 0; c <= hang; c++)
		printf("%d ", c);
	printf("\n");
	for (a = 1,c=1; a <= hang; a++,c++)
	{
		printf("%d ", c);
		for (b = 1; b <= lie; b++)
		{
			printf("%c ", ar[a][b]);
		}
		printf("\n");
	}
}
int handle(char ar[hangs][lies], char er[hangs][lies], int a, int b)
{
	if (er[a][b] == '1')
	{
		printf("你输了\n");
		par(er);
		return 1;
	}
	else if (sum == 0)
	{
		printf("你赢了\n");
		par(er);
		return 1;
	}
	else if (look(er, a, b))
	{
		ar[a ][b ] = look(er, a, b) + '0';
		par(ar);
		sum--;
		if (sum == 0)
		{
			printf("你赢了");
			return 1;
		}
		put(ar, er, &a, &b);
	}
	else if(ar[a][b]=='*'&& ar[a][b]!=' ')
	{
		open(ar,er,a,b,sum);
		par(ar);
		put(ar, er, &a, &b);
	}
	
}
int look(char er[hangs][lies], int a, int b)
{
	return er[a - 1][b - 1] + er[a - 1][b] + er[a - 1][b + 1] + er[a][b - 1] + er[a][b + 1] + er[a + 1][b - 1] + er[a + 1][b] + er[a + 1][b + 1]-8*'0';
}
void put(char ar[hangs][lies],char er[hangs][lies],int a,int b)
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
void open(char ar[hangs][lies], char er[hangs][lies], int a, int b,int sum)
{
	if (a < 1 || a > hang || b < 1 || b > lie || ar[a][b] == ' ')
	{
		return;
	}
	if (look(er, a, b)&& er[a][b] != '1')
	{
		ar[a][b] = look(er, a, b) + '0';
		sum--;
		return;
	}
	ar[a][b] = ' ';  // 标记当前格子已经展开
	sum--;
	for (int i = -1; i <= 1; i++) 
	{
		for (int j = -1; j <= 1; j++) 
		{
			if (i == 0 && j == 0) continue;
			open(ar,er,a + i, b + j ,sum);  // 递归展开当前格子周围的方块
		}
	}
}