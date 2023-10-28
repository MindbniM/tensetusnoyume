#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include <stdio.h>
int jutr(char* str, const char* s)
{
    char* s1 = str;
    const char* s2 = s;
    int num = 0;
    while (*s1 != '\0')
    {
        char* s3 = s1;
        s2 = s;
        while (*s3 == *s2)
        {
            s3++;
            s2++;
            if (*s2 == '\0')
            {
                num++;
                break;
            }
        }
        s1++;
    }
    return num;
}
int maxnum(int* arr, int size)
{
    int a = -1;
    int b = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > a)
        {
            a = arr[i];
            b = i;
        }
    }
    return b;
}
int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    char str[1000];
    const char s[5][10] = { "check-in","easy","medium","hard","nightmare" };
    for (int i = 0; i < n; i++)
    {
        int arr[5] = { 0 };
        fgets(str,1000,stdin);
        arr[0] = jutr(str, "check-in");
        arr[1] = jutr(str, "easy");
        arr[2] = jutr(str, "medium");
        arr[3] = jutr(str, "hard");
        arr[4] = jutr(str, "nightmare");
        printf("%s\n", s[maxnum(arr, 5)]);
    }
}