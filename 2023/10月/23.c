#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include <stdio.h>
//double SC(double num, int exponent)
//{
//    if (exponent == 1)
//        return num;
//    if (exponent % 2 == 1)
//        return num * SC(num, exponent - 1);
//    else
//        return SC(num, exponent / 2) * SC(num, exponent / 2);
//}
//double Power(double base, int exponent) {
//    // write code here
//    if (exponent == 0)
//        return 1;
//    if (exponent < 0)
//    {
//        base = 1.0 / base;
//        exponent = -exponent;
//    }
//    double num = SC(base, exponent);
//    return num;
//}
bool hasPath(char** matrix, int matrixRowLen, int* matrixColLen, char* word) {
    char* s = word;
    for (int i = 0; i < matrixRowLen; i++)
    {
        for (int j = 0; j < matrixColLen[i]; j++)
        {
            if (matrix[i][j] == *word)
            {
                int a = i;
                int b = j;
                s = word;
                s++;
                while (true)
                {
                    if (*s == '\0')
                        return true;
                    if (a > 0 && *s == matrix[a - 1][b])
                    {
                        a -= 1;
                        s++;
                    }
                    else if (a < matrixRowLen - 1 && *s == matrix[a + 1][b])
                    {
                        a += 1;
                        s++;
                    }
                    else if (b > 0 && *s == matrix[a][b - 1])
                    {
                        b -= 1;
                        s++;
                    }
                    else if (b < matrixColLen[a] - 1 && *s == matrix[a][b + 1])
                    {
                        b += 1;
                        s++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    return false;
}