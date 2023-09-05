#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<stdlib.h>
#include <stdio.h>
#include<string.h>
int* masterMind(char* solution, char* guess, int* returnSize) 
{
    short guessBucket[26] = { 0 }, solutionBucket[26] = { 0 }, i;
    *returnSize = 2;
    int* res = (int*)calloc(2, sizeof(int));
    for (i = 0; i < 4; i++) {
        if (solution[i] != guess[i])
        {  
            guessBucket[guess[i] - 65]++;
            solutionBucket[solution[i] - 65]++;
        }
        else res[0]++;
    }
    for (i = 0; i < 26; i++) 
    { 
        if (guessBucket[i] > 0 && solutionBucket[i] > 0) {
            res[1] += guessBucket[i] > solutionBucket[i] ? solutionBucket[i] : guessBucket[i];
        }
    }
    return res;
}