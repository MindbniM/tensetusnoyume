#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<stdlib.h>
#include <stdio.h>
#include<string.h>
void reversal(char* a, char* b)
{
    if (a > b)
        return;
    else
    {
        char s = *a;
        *a = *b;
        *b = s;
        reversal(a+1, b-1);
    }
}
void left(char* s)
{
    int len = strlen(s)-1;
    reversal(s + 1, s + len);
    reversal(s, s + len);
}
int leftpy(char* s1, char* s2) 
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 != len2) {
        return 0;
    }
    while (len1)
    {
        left(s1);
        if (strcmp(s1, s2) == 0)
            return 1;
        len1--;
    }
    return 0;
}

int main() {
    char s1[] = "AABCD";
    char s2[] = "BCDAA";
    int result = leftpy(s1, s2);
    printf("%d\n", result);

    char s3[] = "abcd";
    char s4[] = "ACBD";
    result = leftpy(s3, s4);
    printf("%d\n", result);

    return 0;
}