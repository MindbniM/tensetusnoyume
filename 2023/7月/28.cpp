#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int ar[1000] = { 0 };
    int br[1000] = { 0 };
    int cr[2000] = { 0 };
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &ar[i]);
    }
    for (int i = 0; i < b; i++)
    {
        scanf("%d", &br[i]);
    }
    int m = 0, n = 0, j = 0;
    while (j < (a + b))
    {
        if (m == a || n == b)
        {
            if (m == a)
            {
                cr[j] = br[n];
                n++;
            }
            else if (n == b)
            {
                cr[j] = ar[m];
                m++;
            }
        }
        else
        {
            if (ar[m] < br[n])
            {
                cr[j] = ar[m];
                m++;
            }
            else
            {
                cr[j] = br[n];
                n++;
            }
        }
        j++;
    }
    for (int i = 0; i < (a + b); i++)
        printf("%d ", cr[i]);

    return 0;
}