#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include<assert.h>
size_t my_strlen(const char* str)
{
	assert(str);
	const char* str1 = str;
	while (*str++);
	return str - str1 - 1;
}
char* my_strcmp(char*str1,const char* str2)
{
	assert(str1&&str2);
	char* str = str1;
	while (*str1++ = *str2++);
	return str;
}