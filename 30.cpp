#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
char* reverseStr(char* s, int k) {
    int a = strlen(s);
    for (int i = 0; i < a; i += (2 * k))
    {
        k = (i + k) > a ? a - i : k;
        int left = i;
        int right = i + k - 1;
        while (left < right)
        {
            char m = s[left];
            s[left] = s[right];
            s[right] = m;
            left++, right--;
        }
    }
    return s;
}
