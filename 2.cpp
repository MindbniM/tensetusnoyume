#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char* replaceSpace(char* s)//ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��
{
    int space_num = 0;
    int len = strlen(s);
    for (int a = 0; a < len; a++)
    {
        if (s[a] == ' ')
            space_num++;
    }
    int newlen = len + 2 * space_num;
    char* str = malloc(sizeof(char) * newlen + 1);
    for (int i = newlen - 1, j = len - 1; j >= 0; i--, j--)
    {
        if (s[j] != ' ')
            str[i] = s[j];
        else
        {
            str[i--] = '0';
            str[i--] = '2';
            str[i] = '%';
        }
    }
    str[newlen] = '\0';
    return str;
}
int main()
{
    char str[] = "abc anb sfr";
	printf("%zd", replaceSpace(str));
	return 0;
}