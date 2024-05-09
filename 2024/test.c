#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
int func(char* text1, char* text2,char* dest) //新增第三个输出型参数,存最长公共序列
{
    int s1 = strlen(text1), s2 = strlen(text2);
    int** dp = (int**)malloc(sizeof(int*) * (s1 + 1));
    int* temp = (int*)calloc(fmax(s1, s2) + 1);
    for (int i = 0; i <= s1; i++) dp[i] = (int*)calloc(s2 + 1, sizeof(int));
    for (int i = 1; i <= s1; i++)
    {
        for (int j = 1; j <= s2; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1; 
                temp[]
            }
            else
            {
                dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int ret = dp[s1][s2];
    int m = ret-1;
    int i = s1, j = s2;//从最长公共子序列的长度逆推最长公共子序列
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            dest[m--] = text1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }
    for (int i = 0; i <= s1; i++) free(dp[i]);
    free(dp);
    return ret;
}
int main()
{
    char str1[1000] = { 0 }, str2[1000] = { 0 };
    char str[1000] = { 0 };
    fgets(str1, 1000, stdin);
    fgets(str2, 1000, stdin);
    if(strlen(str1)!=0)
    str1[strlen(str1)-1] = '\0';
    str2[strlen(str2)-1] = '\0';
    printf("%d\n", func(str1, str2,str));
    printf("最长公共序列为%s\n", str);
    return 0;
}