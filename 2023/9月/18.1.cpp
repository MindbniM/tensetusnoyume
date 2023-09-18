#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include<assert.h>
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1&&*str2&&*str1 == *str2)
	{
		str1++, str2++;
	}
	return *str1 - *str2;
}
char* my_strcat(char* str1, const char* str2)
{
	assert(str1 && str2);
	char* str = str1;
	while (*str1)
	{
		str1++;
	}
	int temp = strlen(str2);
	for(int i=0;i<temp;i++)
	{
		*str1++ = *str2++;
	}
	return str;
}
const char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	if (str2 == "")
		return str1;
	const char* s1 = str1;
	const char* s2 = str2;
	const char* s = str1;
	while (*s1)
	{
		s = s1;
		while (*s1&&*s2&&*s1 == *s2)
		{
			s1++, s2++;
		}
		if (*s2 == '\0')
			return s;
		s1++;
	}
	return NULL;
}
int main()
{
	char arr[40] = "hello hello";
	char str[] = "";
	printf("%s\n", my_strcat(arr, arr));
	char string[] = { 'a','b','c' };
	printf("%zd", strlen(string));
	return 0;
}