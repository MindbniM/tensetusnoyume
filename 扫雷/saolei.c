#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void kaishi()
{
	printf("**************************\n");
	printf("******** 1.��ʼ  *********\n");
	printf("******** 0.����  *********\n");
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
			printf("��ʼɨ��\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
		}
	} while (n);
	return 0;
}