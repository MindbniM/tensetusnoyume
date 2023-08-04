#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
int main() {
    char s[] = "a good   example";
    int sum = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] != ' ' && sum == 0)
        {
            s[sum] = s[i];
            sum++;
            if (s[i + 1] == ' ')
                s[sum++] = ' ';
        }
        else if (s[i] != ' ')
        {
            s[sum++] = s[i];
            if (s[i + 1] == ' ')
                s[sum++] = ' '; 
        }
        
    }
    s[sum-1] = '\0';
    fputs(s, stdout);
}