#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 20;
	int b = a;
	while (b >= 2)
	{
		a += b / 2;
		b = b / 2 + b % 2;
	}
	printf("%d", a);
}