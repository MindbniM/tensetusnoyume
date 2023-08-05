#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
int data(int i, int j)
{
	if ((j == 1 )|| (i == j))
		return 1;
	else
		return data(i - 1, j - 1) + data(i - 1, j);
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("\n");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d ", data(i, j));
		}
		printf("\n");
	}
	return 0;
}