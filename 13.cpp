#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<math.h>
#include <stdio.h>
#include<stdlib.h>
int majorityElement(int* nums, int numsSize) {
    int i = 0;
    int couts = nums[i];
    int coutsnum = 1;
    for (i = 1; i < numsSize; i++)
    {
        if (coutsnum == 0)
        {
            couts = nums[i];
        }
        if (couts == nums[i])
            coutsnum++;
        else
            coutsnum--;
    }
    return couts;
}