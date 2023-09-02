#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<stdlib.h>
#include <stdio.h>
#include<string.h>
int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int mid;
    if (target > nums[right])
        return numsSize;
    if (target <= nums[0])
        return 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (nums[mid] > target)
            right = mid - 1;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            return mid;
    }
    return left;
}