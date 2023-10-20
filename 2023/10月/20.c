#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include <stdio.h>
char* replaceSpace(char* s) {
    int len = strlen(s);
    int cout = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == ' ')
            cout++;
    }
    int slen = len + cout * 2;
    char* str = (char*)malloc(slen);
    strcpy(str, "");
    int i = slen - 1;
    int j = len - 1;
    while (j >= 0)
    {
        if (s[j] == ' ')
        {
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
            j--;
        }
        else
            str[i--] = s[j--];
    }
    return str;

}
int duplicate(int* numbers, int numbersLen) {
    int arr[10000] = { 0 };
    for (int i = 0; i < numbersLen; i++)
    {
        arr[numbers[i]]++;
    }
    for (int i = 0; i < 10000; i++)
    {
        if (arr[i] > 1)
            return i;
    }
    return -1;
}