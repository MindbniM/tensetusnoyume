#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
int main()
{
    int a, sum=0;//判断一个整数的二进制有几个一
    scanf("%d", &a);
    while (a)
    {
       
        if ((a & 1) == 1)
        {
            sum++;
       }
        a = a >> 1;
    }
    printf("%d", sum);
    return 0;
}

