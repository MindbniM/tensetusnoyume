#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<stdlib.h>
#include <stdio.h>
#include<string.h>
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* arr = (int*)malloc(2 * sizeof(int));
    arr[0] = -1, arr[1] = -1;
    if (numsSize == 0 || target > nums[numsSize - 1] || target < nums[0])
        return arr;
    int left = 0, right = numsSize - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] > target)
            right = mid - 1;
        else if (nums[mid] < target)
            left = mid + 1;
        else
        {
            arr[0] = mid;
            right = mid - 1;
        }

    }
    left = 0, right = numsSize - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] > target)
            right = mid - 1;
        else if (nums[mid] < target)
            left = mid + 1;
        else
        {
            arr[1] = mid;
            left = mid + 1;
        }
    }
    return arr;
    free(arr);
}