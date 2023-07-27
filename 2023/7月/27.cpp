#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int n;
    int arr[32] = {0};
    scanf("%d", &n);
    for (int a = 31; a >= 0; a--)
    {
        if ((n & 1) == 1)
            arr[a] = 1;
        else
            arr[a] = 0;
        n >>= 1;
    }
    printf("奇数位是:\n");
    for (int a = 0; a <= 31; a+=2)
    {
        printf("%d ", arr[a]);
    }
    printf("\n");
    printf("偶数位是:\n");
    for (int a = 1; a <= 31; a += 2)
    {
        printf("%d ", arr[a]);
    }
    printf("\n");
    printf("二进制是:\n");
    for (int a = 0; a <= 31; a ++)
    {
        printf("%d ", arr[a]);
    }
}