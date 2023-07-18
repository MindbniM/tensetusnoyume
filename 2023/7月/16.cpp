#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a;
	double num = 0;
	for (a = 1; a <= 100; a++)
	{
		num += (a % 2 == 0 ? -1.0 / a : 1.0 / a);
	}
	printf("%lf", num);
	return 0;
}