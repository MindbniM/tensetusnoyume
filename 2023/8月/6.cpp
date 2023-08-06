#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int n;
	scanf("%d", &n);
	int a[100000];
	int i;
	for (i = 1; i < pow(10, n); i++)
	{
		a[i - 1] = i;
	}
	return 0;
}