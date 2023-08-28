#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<math.h>
#include <stdio.h>
#include<stdlib.h>
int dichotomy(int* nums, int numsLen, double k) {
    int left = 0;
    int right = numsLen - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] > k)
            right = mid - 1;
        else if (nums[mid] < k)
            left = mid + 1;
    }
    return left;
}
int GetNumberOfK(int* nums, int numsLen, int k) {
    return dichotomy(nums, numsLen, k + 0.5) - dichotomy(nums, numsLen, k - 0.5);
}