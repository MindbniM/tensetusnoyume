#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include <stdio.h>
typedef struct Str
{
	char str[100];
	int num;
	struct Str* next;
}Sr;
Sr* InitStr()
{
	Sr* s = (Sr*)malloc(sizeof(Sr));
	assert(s);
	s->next = NULL;
	strcpy(s->str, "");
	return s;
}
char* strn(char* str)
{
	while (*str++ != ' ');
	char* s = str;
	while (*str != ' ')
		str++;
	*str = '\0';
	return s;
}
void AddStr(Sr* S,char*str)
{
	Sr* s = (Sr*)malloc(sizeof(Sr));
	assert(s);
	s->next = NULL;
	s->num = 1;
	while (S->next != NULL)
		S = S->next;
	strcpy(s->str, str);
	S->next = s;
}
void StrS(char* str, Sr* S)
{
	Sr* Sr = S;
	while (S != NULL)
	{
		if (!strcmp(str, S->str))
		{
			S->num+=1;
			return;
		}
		S = S->next;
	}
	AddStr(Sr,str);
}
void Sprintf(Sr* S)
{
	int max = 0;
	char arr[100] = "";
	while (S != NULL)
	{
		if (S->num > max)
		{
			max = S->num;
			strcpy(arr, S->str);
		}
		S = S->next;
	}
	printf("%s %d", arr, max);
}
void strspace(char* str)
{
	char* s = str;
	int cout = 0;
	while (*str != '\0')
	{
		if (*str != ' ')
		{
			*s++ = *str++;
			cout = 1;
			
		}
		else
		{
			str++;
			if (cout)
			{
				*s++ = ' ';
				cout = 0;
			}
		}
	}
	*s = '\0';
}
int main()
{
	Sr* S = InitStr();
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		char str1[100] = {0};
		fgets(str1, 100, stdin);
		strspace(str1);
		char* s = strn(str1);
		StrS(s, S);
	}
	Sprintf(S);
	Sr* current = S;
	while (current != NULL) {
		Sr* temp = current;
		current = current->next;
		free(temp);
	}
	return 0;
}