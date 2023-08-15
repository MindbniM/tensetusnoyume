#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<math.h>
#include <stdio.h>
#include<stdlib.h>
int fun(int i)
{
    int sum = 0;
    for (int a = 1; a <= i / 2; a++)
    {
        if (i % a == 0)
            sum += a;
    }
    if (sum == i)
        return 1;
    return 0;
}
int main() {
    int n, couts = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            if (fun(i))
                couts++;
        }
    }
    printf("%d", couts);
    return 0;
}