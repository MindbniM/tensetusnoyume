#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<limits.h>
int minSubArrayLen(int target, int* nums, int numsSize)
{//给定一个含有 n 个正整数的数组和一个正整数 target 。
 //   找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl + 1, ..., numsr - 1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
    int left = 0, right = 0;
    int num = 0, min = INT_MAX;
    while (left <= numsSize - 1 && right <= numsSize - 1)
    {
        num += nums[right];
        while (num >= target)
        {
            if (min > right - left + 1)
            {
                min = right - left + 1;
            }
            if (left <= numsSize - 1 && right <= numsSize - 1)
            {
                num -= nums[left];
                left++;
            }
        }
        right++;
    }
    if (min == INT_MAX)
        min = 0;
    return min;

}