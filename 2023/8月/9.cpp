#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<math.h>
#include <stdio.h>
#include<stdlib.h>
int judge(int* arr, int couts, int a)
{
    for (int i = 0; i < a; i++)
    {
        if (arr[i] == couts)
            return 0;
    }
    return 1;
}
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int a = 0;
    int* arr = malloc(sizeof(int) * 1000);
    *returnSize = 0;
    for (int i = 0; i < nums1Size; i++)
    {
        for (int j = 0; j < nums2Size; j++)
        {
            if (nums1[i] == nums2[j] && judge(arr, nums1[i], a))
                arr[a++] = nums1[i];
        }
    }
    *returnSize = a;
    return arr;
    free(arr);
}