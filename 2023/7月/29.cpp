#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int py(int n)
{
    int a = 0;
    int b = n;
    int sum = 0;
    while (b)
    {
        b /= 10;
        a++;
    }
    b = n;
    while (b)
    {
        sum += pow(b % 10, a);
        b /= 10;
    }
    if (sum == n)
        return 1;
    return 0;
}
int main()
{
    for (int a = 0; a < 100000; a++)
    {
        if (py(a))
            printf("%d\n", a);
    }
    return 0;
}