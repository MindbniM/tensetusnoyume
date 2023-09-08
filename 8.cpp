#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
int comp(const void* a,const void* b)
{
	return (int)b - (int)a;
}

int main()
{
	char arr[10];
	char n = 'z';
	for (int i = 0; i < 10; i++)
	{
		arr[i] = n--;
		printf("%c ", arr[i]);
	}
	printf("\n");
	qsort(arr, sizeof(arr), sizeof(arr[0]), comp);
	printf("ÅÅÐòºó\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%c ", arr[i]);
	}
	printf("\n");
}