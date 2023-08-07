#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<math.h>
#include <stdio.h>
int minNumberInRotateArray(int* nums, int numsLen)
{
    int left = 0, right = numsLen - 1;
    int mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (nums[mid] > nums[right])
        {
            left = mid + 1;
        }
        else if (nums[mid] == nums[right])
        {
            right--;
        }
        else
        {
            right = mid;
        }
    }
    return nums[left];
}
