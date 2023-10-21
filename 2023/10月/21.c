#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include <stdio.h>
//void res(int* left, int* right)
//{
//    assert(left != NULL && right != NULL);
//    if (left > right)
//        return;
//    else
//    {
//        int num = *left;
//        *left = *right;
//        *right = num;
//        res(left + 1, right - 1);
//    }
//}
//void rotate(int* nums, int numsSize, int k) {
//    k = k % numsSize;
//    k = numsSize - k;
//    res(nums, nums + k - 1);
//    res(nums + k, nums + numsSize - 1);
//    res(nums, nums + numsSize - 1);
//}
//int Fibonacci(int n) {
//    int f1 = 1;
//    int f2 = 1;
//    if (n == 1 || n == 2)
//        return f1;
//    while (n > 2)
//    {
//        f1 = f1 + f2;
//        f2 = f1 + f2;
//        n -= 2;
//    }
//    if (n % 2 == 1)
//        return f1;
//    else
//        return f2;
//}