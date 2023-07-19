#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int removeDuplicates(int* nums, int numsSize)//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
{
    int newSize = 0, a;
    for (a = 0; a < numsSize; a++)
    {
        if (a == numsSize - 1)
        {
            nums[newSize++] = nums[a];
            break;
        }
        if (nums[a] < nums[a + 1])
        {
            nums[newSize++] = nums[a];
        }
    }
    return newSize;
}



int removeElement(int* nums, int numsSize, int val)//https://leetcode.cn/problems/remove-element/
{
    int newSize = 0;
    for (int a = 0; a < numsSize; a++)
    {
        if (nums[a] != val)
        {
            nums[newSize++] = nums[a];
        }
    }
    return newSize;
}