#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 10
int fun(int* p, size_t size, int n,int* temp)
{
	if (p == NULL) return 0;
	int** dp = (int**)malloc(sizeof(int*) * (size + 1));
	for (int i = 0; i <= size; i++) dp[i] = (int*)calloc(sizeof(int), n + 1);
	int** dest = (int**)malloc(sizeof(int*) * (size + 1));
	for (int i = 0; i <= size; i++) dest[i] = (int*)calloc(sizeof(int), n + 1);
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j - i >= 0 && (dp[i][j - i] + p[i - 1] > dp[i][j]))
			{
				dp[i][j] = dp[i][j - i] + p[i - 1];
				dest[i][j] = 1;
			}
		}
	}
	int r_ret = dp[size][n];
	int i = size, j = n;
	while (i > 0)
	{
		if (dest[i][j] == 1)
		{
			temp[i-1]++;
			j -= i;
		}
		else i--;
	}
	for (int i = 0; i <= size; i++) free(dp[i]);
	free(dp);
	for (int i = 0; i <= size; i++) free(dest[i]);
	free(dest);
	return r_ret;

}
int main()
{
	int p[N] = { 1,5,8,9,10,17,17,20,24,24 };
	int temp[N] = { 0 };
	int n = 0;
	scanf("%d", &n);
	printf("最大销售额:%d\n", fun(p, N, n,temp));
	printf("最优切割方案为:\n");
	for (int i = 0; i < N; i++)
	{
		if (temp[i] != 0) printf("\t %d 块 %d 米的\n", temp[i], i + 1);
	}

	return 0;
}