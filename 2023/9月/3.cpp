#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<stdlib.h>
#include <stdio.h>
#include<string.h>
int minSubArrayLen(int target, int* nums, int numsSize) {
    int i = 0, j = 0, num = 0;
    int res = INT_MAX;
    for (j = 0; j < numsSize; j++)
    {
        num += nums[j];
        while (num >= target)
        {
            int sum = j - i + 1;
            res = res < sum ? res : sum;
            num -= nums[i++];
        }
    }
    if (res == INT_MAX)
        return 0;
    return res;
}