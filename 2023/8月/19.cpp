#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<math.h>
#include <stdio.h>
#include<stdlib.h>
int main() {
    int n;
    char str[32];
    int i = 0;
    scanf("%d", &n);
    do
    {
        str[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    str[i] = '\0';
    printf("%s", str);
    return 0;
}