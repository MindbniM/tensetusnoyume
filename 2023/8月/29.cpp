#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<math.h>
#include <stdio.h>
#include<stdlib.h>
int main() {
    int b;
    double a, sum = 0;
    while (scanf("%lf%d", &a, &b) != EOF)
    {
        while (b)
        {
            sum += a;
            a = sqrt(a);
            b--;
        }
        printf("%.2lf\n", sum);
        sum = 0;
    }
    return 0;
}