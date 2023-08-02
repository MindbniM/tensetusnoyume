#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<assert.h>
size_t my_strlen(const char* str)
{
	assert(str);
	const char* a = str;
	while (*str++ != '\0');
	return str - 1 - a;
}
int main()
{
	char str[20];
	scanf("%s", str);
	printf("%zd",my_strlen(str));
	return 0;
}