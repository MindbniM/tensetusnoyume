#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int max = 13 * n;
    char s[] = "redbloodcell";
    char str1[max];
    char str2[max];
    scanf("%s", str2);
    strcpy(str1, "");
    for (int i = 0; i < n; i++)
    {
        strcat(str1, s);
    }
    char* a = str1;
    char* b = str2;
    int num = 0;
    while (*a)
    {
        if (*a == *b || *a == *b + 32)
            a++, b++;
        else
        {
            printf("%c", *a);
            num++;
            a++;
        }
    }
    if (!num)
        printf("NULL");

}