#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<math.h>
#include <stdio.h>
#include<stdlib.h>
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int) * numsSize);
    int i, j;
    for (i = 0; i < numsSize; i++)
    {
        arr[i] = 0;
    }
    for (i = 0; i < numsSize; i++)
    {
        arr[nums[i] - 1] = 1;
    }
    for (i = 0, j = 0; i < numsSize; i++)
    {
        if (arr[i] == 0)
        {
            arr[j++] = i + 1;
        }
    }
    *returnSize = j;
    return arr;
    free(arr);
}