#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include <stdio.h>
//typedef struct tim
//{
//    int arr;
//    int date;
//}ti;
//int comp(const void* arr1, const void* arr2)
//{
//    int s1 = abs(((ti*)arr1)->date);
//    int s2 = abs(((ti*)arr2)->date);
//    if (((ti*)arr1)->date < 0 && s1 == s2)
//        return -1;
//    if (((ti*)arr2)->date < 0 && s1 == s2)
//        return 1;
//    return s1 - s2;
//}
//int sort(int Date)
//{
//    int Year = Date / 10000;
//    int Month = (Date % 10000) / 100;
//    int Day = Date % 100;
//    struct tm date = { 0, 0, 0, Day, Month - 1, Year - 1900 };
//    struct tm date1 = { 0, 0, 0, 19, 10, 122 };
//    time_t time = mktime(&date);
//    time_t now = mktime(&date1);
//    double tomp = difftime(now, time) / (24 * 60 * 60);
//    return (int)tomp;
//}
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    ti arr[10];
//    int num;
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &num);
//        arr[i].arr = num;
//        arr[i].date = sort(num);
//    }
//    qsort(arr, n, sizeof(ti), comp);
//    for (int i = 0; i < n; i++)
//    {
//        printf("%08d\n", arr[i].arr);
//    }
//}
int comp(int (*arr)[9], int i, int j, int c)
{
    int arr1[10] = { 0 };
    if (c)
    {
        for (int i = 0; i < 9; i++)
        {
            arr1[arr[i][j]] += 1;
        }
        for (int i = 1; i < 9; i++)
        {
            if (arr1[i] == 0)
                return 0;
        }
        return 1;
    }
    else
    {
        for (int j = 0; j < 9; j++)
        {
            arr1[arr[i][j]] += 1;
        }
        for (int i = 1; i < 9; i++)
        {
            if (arr1[i] == 0)
                return 0;
        }
        return 1;
    }
}
int main()
{
    int arr[9][9];
    int a, b;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &arr[i][j]);
            if (!arr[i][j])
            {
                a = i, b = j;
            }
        }
    }
    int num = 0, sum = 0;
    for (int i = 0; i < 9; i++)
    {
        num += arr[a][i];
        sum += arr[i][b];
    }
    arr[a][b] = 45 - num;
    if (num == sum && comp(arr, a, b, 1) && comp(arr, a, b, 0))
        printf("%d", 45 - num);
    else
        printf("NO");
}