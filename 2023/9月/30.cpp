#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include <stdio.h>
//int* lookof(int* arr,int sz,int*returnSize)
//{
//	int* base = (int*)malloc(sizeof(int) * 2);
//	*returnSize = 0;
//	int arr1[10000] = { 0 };
//	for (int i = 0; i < sz; i++)
//	{
//		arr1[arr[i]]++;
//	}
//	for (int i = 0; i < 10000; i++)
//	{
//		if (arr1[i] == 1)
//		{
//			base[*returnSize] =i;
//			(*returnSize)++;
//		}
//		if (*returnSize == 2)
//			return base;
//	}
//	free(base);
//	return NULL;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
//	int sz;
//	int* s = lookof(arr, sizeof(arr) / sizeof(int), &sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ",s[i]);
//	}
//	free(s);
//	return 0;
//}
char* my_strncpy(char* str1, const char* str2, size_t num)
{
	assert(str1 && str2);
	char* str = str1;
	for (int i = 0; i < num; i++)
	{
		*str1 = *str2;
		if (*str1 != '\0')
		{
			str1++, str2++;
		}
		else
		{
			str1++;
		}
	}
	*str1 = '\0';
	return str;
}
char* my_strncat(char* str1, const char* str2, size_t num)
{
	assert(str1 && str2);
	char* str = str1;
	while (*str1)
	{
		str1++;
	}
	for (int i = 0; i < num; i++)
	{
		*str1 = *str2;
		if (*str1 != '\0')
		{
			str1++, str2++;
		}
		else
		{
			str1++;
		}
	}
	*str1 = '\0';   
	return str;
}
int my_atoi(const char* str)
{
	int num = 0;
	int sign = 1;
	while(*str)
	{
		if (isdigit(*str))
		{
			num *= 10;
			num += *str - '0';
		}
		else
		{
			if (num||sign==-1)
				return num*sign;
		}
		if (*str == '-')
		{
			sign = -1;
		}
		str++;
	}
	return num*sign;
}
int main()
{
	char str[] = "-+4-++7";
	char str1[] = "    +426-++7";
	char str2[] = "+-+-+*456-++7";
	printf("%d\n", my_atoi(str));
	printf("%d\n", my_atoi(str1));
	printf("%d\n", my_atoi(str2));
	printf("\n");
	printf("%d\n", atoi(str));
	printf("%d\n", atoi(str1));
	printf("%d\n", atoi(str2));
}
