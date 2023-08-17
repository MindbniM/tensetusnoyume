#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<math.h>
#include <stdio.h>
#include<stdlib.h>
int temp(int a)
{
    int num = a;
    while (a)
    {
        int b = a % 10;
        if (b == 0 || num % b != 0)
        {
            return 0;
        }
        a /= 10;
    }
    return 1;
}
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int) * (right - left + 1));
    int a = 0;
    for (int i = left; i <= right; i++)
    {
        if (temp(i))
        {
            arr[a++] = i;
        }
    }
    *returnSize = a;
    return arr;
}