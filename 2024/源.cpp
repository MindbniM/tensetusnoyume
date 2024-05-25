#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<windows.h>
int main()
{
	char arr[] = "********";
	char brr[] = "fuck you";
	int i, j;
	for (i = 0, j = strlen(arr) - 1; i <= j; i++, j--)
	{
		printf("%s\n", arr);
		arr[i] = brr[i];
		arr[j] = brr[j];
	}
	printf("%s", arr);
	return 0;
}