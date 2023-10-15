#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include <stdio.h>
//#define _offsetof_(N,P) ((size_t)(&((N*)0)->P))
//typedef struct Node
//{
//	int a;
//	char b;
//	int c;
//
//}Node;
//int main()
//{
//	printf("%d\n", _offsetof_(Node,a));
//	printf("%d\n", _offsetof_(Node, b));
//	printf("%d\n", _offsetof_(Node, c));
//	return 0;
//}
//#define BINARY(N) ((size_t)(((N&0xAAAAAAAA)>>1)|((N&0x55555555)<<1)))
//void Print2(size_t num)
//{
//	static int a = -1 ;
//	a++;
//	if (num==0&&a==32)
//	{
//		a = -1;
//		return;
//	}
//	else
//	{
//		Print2(num / 2);
//		printf("%d ", num % 2);
//	}
//}
//int main()
//{
//	int num= 10;
//	Print2(num);
//	printf("\n");
//	Print2((num & 0xAAAAAAAA));
//	printf("\n");
//	Print2((num & 0xAAAAAAAA) >> 1);
//	printf("\n");
//	Print2((num & 0x55555555));
//	printf("\n");
//	Print2((num & 0x55555555) << 1);
//	printf("\n");
//	Print2(BINARY(num));
//	return 0;
//	//1010 1010 1010 1010 1010 1010 1010 1010
//	//0101 0101 0101 0101 0101 0101 0101 0101
//}
//int next[5];
int* Getnext(const char* str, int* returnSize)
{
	int len = strlen(str);
	int* next = (int*)malloc(sizeof(int) * len);
	assert(next);
	*returnSize = len;
	int i = 1;
	int j = 0;
	next[0] = 0;
	for (i = 1; i < len; i++)
	{
		while (j > 0 && str[i] != str[j])
			j = next[j - 1];
		if (str[i] == str[j])
			j++;
		next[i] = j;
	}
	return next;
}
//char* my_strstr(char* str, const char* str1)
//{
//	assert(str);
//	if (!str1)
//		return NULL;
//	int len = strlen(str);
//	int returnSize;
//	int* next=Getnext(str1, &returnSize);
//	for (int i = 0,j=0; i < len; i++)
//	{
//		while (j>0&&str[i] != str1[j])
//			j = next[j - 1];
//		if (str[i] == str1[j])
//			j++;
//		if (j ==strlen(str1))
//			return str+i-j+1;
//	}
//	return NULL;
//}
int my_strstr(char* str, const char* str1)
{
	assert(str);
	if (!str1)
		return NULL;
	int len = strlen(str);
	int returnSize;
	int* next = Getnext(str1, &returnSize);
	for (int i = 0, j = 0; i < len; i++)
	{
		while (j > 0 && str[i] != str1[j])
			j = next[j - 1];
		if (str[i] == str1[j])
			j++;
		if (j == strlen(str1))
			return i - j + 1;
	}
	return -1;
}
int main()
{
	char str[] = "aababaaaabbaa";
	char str1[] = "bbaa";
	int len = strlen(str);
	//int returnSize;
	//Getnext(str1, &returnSize);
	printf("%d", my_strstr(str, str1));
	//for (int i = 0; i < returnSize; i++)
	//{
	//	printf("%d ", next[i]);
	//}


}