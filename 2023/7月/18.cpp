#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int search(int* nums, int numsSize, int target)
{//左闭右开二分查找
    int left, right, mid;
    left = 0, right = numsSize;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (target > nums[mid])
        {
            left = mid + 1;
        }
        if (target < nums[mid])
        {
            right = mid;
        }
        if (target == nums[mid])
        {
            return mid;
        }
    }
    return -1;
}