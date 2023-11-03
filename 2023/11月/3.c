#define _CRT_SECURE_NO_WARNINGS
#include "text.h"
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		perror("malloc:");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void SListPrint(SListNode* plist)
{
	assert(plist != NULL);
	while (plist != NULL)
	{
		printf("%d", plist->data);
		plist = plist->next;
	}
}
void SListFree(SListNode** pplist)
{
	assert(*pplist!=NULL);
	SListNode** p = pplist;
	while (*p != NULL)
	{
		SListNode* pc = *p;
		*p = (*p)->next;
		free(pc);
	}
	*pplist = NULL;
}
void text1()
{
	SListNode* head = BuySListNode(1);
	head->next = BuySListNode(2);
	head->next->next = BuySListNode(3);
	head->next->next->next = BuySListNode(4);
	SListPrint(head);
	SListFree(&head);
}
int main()
{
	text1();
	return 0;
}