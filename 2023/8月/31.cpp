#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<stdlib.h>
#include <stdio.h>
#include<string.h>
void left(char* str, int n, int len)

{
	n = n % len;
	char* stg = str;
	for (; n > 0; n--)
	{
		str = stg;
		char a = *str;
		for (str; *(str + 1) != '\0'; str++)
		{
			*str = *(str + 1);
		}
		*str = a;
	}
}

int main()
{
	char str[] = "hello";
	int n;
	scanf("%d", &n);
	printf("Ô­×Ö·û´®Îª%s\n", str);
	left(str, n, strlen(str));
	printf("×óÐý%d¸ö×Ö·ûÎª%s\n", n, str);
	return 0;
}