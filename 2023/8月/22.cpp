#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<math.h>
#include <stdio.h>
#include<stdlib.h>
int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
    int* arr = malloc(sizeof(int) * 2);
    *returnSize = 2;
    int sum = 0;
    int num = 0;
    for (int i = 0; i < numsSize; i++)
    {
        num += i + 1;
        sum += nums[i];
        for (int j = 0; j < numsSize; j++)
        {
            if (nums[i] == nums[j] && i != j)
            {
                arr[0] = nums[i];
            }
        }
    }
    int s = sum - arr[0];
    arr[1] = num - s;
    return arr;
}