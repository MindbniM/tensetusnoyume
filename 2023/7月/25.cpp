#include"game.h"
void game()
{
	char arr[I][J];
	initialize(arr);
	while (1)
	{
		board(arr);
		if (win(arr))
			break;
		printf("玩家下棋\n");
		my_play(arr);
		board(arr);
	    if (win(arr))
			break;
		printf("电脑下棋\n");
		AI_play(arr);
	}

}
void initialize(char arr[][J])
{
	int i, j;
	for (i = 0; i < I; i++) 
	{
		for (j = 0; j < J; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void board(char arr[][J])
{
	int i, j;
	for (i = 0; i < I; i++) 
	{
		for (j = 0; j < J; j++) 
		{
			if (j < J - 1)
				printf(" %c |", arr[i][j]);
			else
				printf(" %c \n", arr[i][j]);
		}
		if (i < J - 1)
		{
			for (j = 0; j < J; j++)
			{
				if (j < J - 1)
					printf("---|");
				else
					printf("---\n");
			}
		}
	}
}
void my_play(char arr[][J])
{
	while (1)
	{
		int a, b;
		printf("请输入下棋位置\n");
		scanf("%d%d", &a, &b);
		if (arr[a - 1][b - 1] == ' ')
		{
			arr[a - 1][b - 1] = '*';
			break;
		}
		else
			printf("已占用,重新输入\n");
	}	
}
void AI_play(char arr[][J])
{
	while (1)
	{
		srand((unsigned int)time(NULL));
		int a = rand() % 3;
		int b = rand() % 3;
		if (arr[a][b] == ' ')
		{
			arr[a][b] = '#';
			break;
		}
	}
	
}
int win(char arr[][J])
{
	if (wins(arr) != ' ')
	{
		if (wins(arr) == 'q')
		{
			printf("平局\n");
		}
		else if (wins(arr) == '*')
		{
			printf("玩家赢\n");
		}
		else
			printf("电脑赢\n");
		return 1;
	}
	return 0;
}
char wins(char arr[][J])
{
	int a=0, b=0;
	if (arr[a][b] == arr[a + 1][b + 1] && arr[a][b] == arr[a + 2][b+2])
		return arr[a][b];
	if (arr[a+2][b] == arr[a + 1][b + 1] && arr[a+2][b] == arr[a][b + 2])
		return arr[a+2][b];
	if (arr[a][b] == arr[a ][b + 1] && arr[a][b] == arr[a ][b + 2])
		return arr[a][b];
	if (arr[a+1][b] == arr[a+1][b + 1] && arr[a+1][b] == arr[a+1][b + 2])
		return arr[a+1][b];
	if (arr[a+2][b] == arr[a+2][b + 1] && arr[a+2][b] == arr[a+2][b + 2])
		return arr[a+2][b];
	if (arr[a][b] == arr[a+1][b] && arr[a][b] == arr[a+2][b])
		return arr[a][b];
	if (arr[a][b+1] == arr[a+1][b +1] && arr[a][b+1] == arr[a+2][b + 1])
		return arr[a][b+2];
	if (arr[a][b+2] == arr[a+1][b+2] && arr[a][b+2] == arr[a+2][b + 2])
		return arr[a][b+2];
	for (a = 0; a < I; a++)
	{
		for (b = 0; b < J; b++)
		{
			if (arr[a][b] == ' ')
				return ' ';
		}
	}
	return 'q';
}