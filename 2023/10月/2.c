#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include <stdio.h>
bool Find(int target, int** array, int arrayRowLen, int* arrayColLen) {
    int i, j = 0;
    i = arrayRowLen - 1;
    while (i >= 0 && j < *arrayColLen)
    {
        if (array[i][j] == target)
            return true;
        if (array[i][j] < target)
            j++;
        else if (array[i][j] > target)
            i--;
    }
    return false;
}