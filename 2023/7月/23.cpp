#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void reverse_string(char* string ,char*a,char*b)
{
	//编写一个函数 reverse_string(char * string)（递归实现）
	//实现：将参数字符串中的字符反向排列，不是逆序打印
	//要求：不能使用C函数库中的字符串操作函数。
	char c = *a;
	if (a > b)
		return;
	else
	{
		*a = *b, *b = c;
		reverse_string(string, a + 1, b - 1);
	}
}
int main()
{
	char string[20];
	char* a;
	char* b;
	fgets(string, sizeof(string), stdin);
	a = string;
	for (b = string; *b != '\0'; b++);
	b--;
	reverse_string(string,a,b);
	printf("%s", string);
	return 0;
}