#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<math.h>
#include <stdio.h>
#include<stdlib.h>
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int arr[numsSize + 1];
    int i, j, num = 0;
    for (i = 0; i < numsSize; i++)
    {
        arr[i] = nums[i];
    }
    arr[i] = 0;
    for (i = 0, j = 0; i <= numsSize; i++)
    {
        if (arr[j] == 1 && arr[i] == 0 && i > j)
        {
            num = num > i - j ? num : i - j;
            j = i;
        }
        if (arr[j] == 0)
        {
            j++;
        }
    }
    return num;
}