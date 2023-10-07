#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include <stdio.h>
void spence(char* str)
{
    char* str1 = str;
    int cout = 0;
    while (*str != '\n')
    {
        if (isspace(*str))
        {
            if (cout)
            {
                *str1++ = ' ';
                cout = 0;
            }
        }
        else if (ispunct(*str))
        {
            *str1++ = *str;
        }
        else
        {
            *str1++ = *str;
            cout = 1;
        }
        str++;
    }
    *str1 = '\0';
}
void spencef(char* str)
{
    char* s = str;
    char* temp = (char*)malloc(1002);
    temp[0] = '\0';
    char* t = temp;
    while (*str != '\0')
    {
        if (ispunct(*str))
        {
            while (*(t - 1) == ' ' && *t)
            {
                t--;
            }
        }
        *t = *str;
        t++;
        str++;
    }
    *t = '\0';
    strcpy(s, temp);
    free(temp);
}
void lower(char* str)
{
    while (*str != '\0')
    {
        if (isupper(*str)&&*str!='I')
        {
            *str = *str + 32;
        }
        str++;
    }
}
void strReplace(char* str, const char* s1, const char* s2)
{
    int Slen = strlen(str);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *temp=(char*)malloc(1002);
    temp[0] = '\0';
    char* s = str;
    int cout = 1;
    while (*s != '\0')
    {
        if (memcmp(s, s1, len1) == 0 && (*(s + len1) == ' ' || ispunct(*(s + len1)) || *(s + len1) == '\0')&&cout)
        {
            strcat(temp, s2);
            s += len1;
        }
        else
        {
            strncat(temp, s, 1);
            if (isspace(*s))
                cout = 1;
            else
                cout = 0;
            s++;
        }
    }
    
    strcpy(str, temp);
    free(temp);
}
void strf(char*str)
{
    while (*str != '\0')
    {
        if (*str == '?')
            *str = '!';
        str++;
    }
}
int main()
{
    /*int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {*/
        char *str = (char*)malloc(10002);
        assert(str);
        str[0] = '\0';
        fgets(str, 1002, stdin);
        fputs(str, stdout);
        spence(str);
        spencef(str);
       /* fputs(str, stdout);
        printf("\n");*/
        lower(str);
        strReplace(str, "I", "you");
        strReplace(str, "me", "you");
        strReplace(str, "can you", "I can");
        strReplace(str, "could you", "I could");
        strf(str);
        printf("AI: ");
        fputs(str, stdout);
        printf("\n");
        free(str);

    //}
}