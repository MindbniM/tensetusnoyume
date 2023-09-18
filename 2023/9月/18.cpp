#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include<assert.h>
struct List
{
	char data;
	struct List* next;
}*hread,*p,*q;
void InitializeList(struct List* p)
{
	struct List* Li = (struct List*)malloc(sizeof(struct List));
	Li=p;
	hread = Li;
	for (int i = 0; i < 26; i++) {
		struct List* newLi = (struct List*)malloc(sizeof(struct List));
		newLi->data = (char)('a' + i);
		Li->next = newLi;
		Li = Li->next;
	}
	Li->next = NULL;
}
void Print(struct List* Li)
{
	struct List* temp = Li->next;
	while (temp != NULL)
	{
		printf("%c ", temp->data);
		temp = temp->next;
	}
}
void AddList(struct List* Li,char ch)
{
	struct List* newList = (struct List*)malloc(sizeof(struct List));
	newList->data = ch;
	while (Li->next != NULL && Li->next->data > ch) {
		Li = Li->next;
	}
	struct List* p = Li->next;
	Li->next = newList;
	newList->next = p;
}
struct List* seekList(struct List* Li,char ch)
{
	struct List* temp = Li->next;
	while (temp != NULL)
	{
		if (temp->data == ch)
			return temp;
		temp = temp->next; 
	}
	return NULL;
}
void deleList(struct List* head, char ch)
{
	while (head->next != NULL && head->next->data != ch) {
		head = head->next;
	}
	if (head->next == NULL) {
		printf("Ã»ÕÒµ½\n");
		return;
	}
	struct List* p = head->next;
	head->next = head->next->next;
	free(p);
}
int main()
{
	struct List Li;
	InitializeList(&Li);
	Print(&Li);
}