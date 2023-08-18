#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<math.h>
#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
void py(char* left, char* right)
{
    if (left >= right)
        return;
    else
    {
        char a = *left;
        *left = *right;
        *right = a;
        py(left + 1, right - 1);
    }
}
int main() {
    char str[10000];
    char* left = str, * right = str;
    fgets(str, 10000, stdin);
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        if (!isalpha(str[i]))
            str[i] = ' ';
    }
    py(str, str + strlen(str) - 2);
    while (*left == ' ')
        left++;
    right = left;
    for (; *right != '\n'; right++)
    {
        if (*(right + 1) == ' ' || *(right + 1) == '\n')
        {
            py(left, right);
            left = right + 1;
            while (*left == ' ')
                left++;
        }
    }
    fputs(str, stdout);
    return 0;
}