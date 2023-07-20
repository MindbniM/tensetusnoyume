#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int* sortedSquares(int* nums, int numsSize, int* returnSize)//给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序
{
    *returnSize = numsSize;
    int* arr = (int*)malloc(sizeof(int) * numsSize);
    int i = 0;
    int j = numsSize - 1;
    int new;
    for (new = numsSize - 1; new >= 0; new--)
    {
        int a = nums[i] * nums[i];
        int b = nums[j] * nums[j];
        if (a > b)
        {
            arr[new] = a;
            i++;
        }
        if (a <= b)
        {
            arr[new] = b;
            j--;
        }
    }
    return arr;
}