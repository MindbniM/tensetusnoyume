#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void kaishi()
{
	printf("**************************\n");
	printf("******** 1.开始  *********\n");
	printf("******** 0.结束  *********\n");
	printf("**************************\n");
}
void game()
{
	int a, b;
	char ar[hangs][lies], er[hangs][lies];
	initialize(ar,  er);
	//par(er);
	put(ar,er,&a,&b);
	//par(ar);
}
int main()
{
	int n;
	do
	{
		kaishi();
		scanf("%d", &n);
		switch(n)
		{
		case 1:
			printf("开始扫雷\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
		}
	} while (n);
	return 0;
}