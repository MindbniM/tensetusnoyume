#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#define row 6
#define line 6
int seek(int(*p)[row], int seeknum)
{
	int left = 0, right = line - 1, mind=(left + right) / 2;
	while (left <= right)
	{
		if (p[mind][0] < seeknum)
		{
			left = mind + 1;
		}
		else if (p[mind][0] > seeknum)
		{
			right = mind - 1;
		}
		else
			return 1;
		mind = (left + right) / 2;
	}
	int  line1 = mind;
	left = 0, right = row - 1;
	while (left <= right)
	{
		int mind = (left + right) / 2;
		if (p[line1][mind] < seeknum)
		{
			left = mind + 1;
		}
		else if (p[line1][mind] > seeknum)
		{
			right = mind - 1;
		}
		else
			return 1;
	}
	return 0;
}
int main()
{
	int arr[6][6];
	int n = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			arr[i][j] = n;
			n += 3;
			printf("%-8d", arr[i][j]);
		}
		printf("\n");
	}
	int seeknum;
	printf("\n");
	while (scanf("%d", &seeknum)!=EOF)
	{
		if (seek(arr, seeknum))
			printf("找到了\n");
		else
			printf("没找到\n");
	}
}