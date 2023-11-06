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
	if (plist == NULL)
	{
		printf("NULL");
	}
	else
	{
		while (plist != NULL)
		{
			printf("%d->", plist->data);
			plist = plist->next;
		}
	}
	printf("NULL\n");
}
void SLTDestroy(SListNode** pplist)
{
	assert(pplist!=NULL);
	SListNode* p = *pplist;
	while (p != NULL)
	{
		SListNode* pc = p;
		p = p->next;
		free(pc);
		pc = NULL;
	}
	*pplist = NULL;
}
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist != NULL);
	if (*pplist == NULL)
	{
		SListNode* newNode = BuySListNode(x);
		*pplist = newNode;
	}
	else
	{
		SListNode* newNode = BuySListNode(x);
		SListNode* p = *pplist;
		*pplist = newNode;
		newNode->next = p;
	}
}
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist != NULL);
	SListNode* p = *pplist;
	if (p == NULL)
	{
		SListNode* newNode = BuySListNode(x);
		*pplist = newNode;
		return;
	}
	while (p ->next!= NULL)
	{
		p = p->next;
	}
	SListNode* newNode = BuySListNode(x);
	p->next = newNode;

}
void SListPopBack(SListNode** pplist)
{
	assert(pplist != NULL&&*pplist!=NULL);
	SListNode* p = *pplist;
	if (p->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		while (p->next->next != NULL)
		{
			p = p->next;
		}
		free(p->next);
		p->next = NULL;
	}
}
void SListPopFront(SListNode** pplist)
{
	assert(pplist != NULL&&*pplist!=NULL);
	SListNode* p = *pplist;
	if (p->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		*pplist = p->next;
		free(p);
	}
}
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	while (plist != NULL)
	{
		if (plist->data == x)
			return plist;
		plist = plist->next;
	}
	return NULL;
}
void SListInsertAfter(SListNode* pow, SLTDateType x)
{
	assert(pow != NULL);
	SListNode* newNode = BuySListNode(x);
	SListNode*p=pow->next;
	pow->next = newNode;
	newNode->next = p;
}
void SListEraseAfter(SListNode* pow)
{
	assert(pow != NULL);
	SListNode* p = NULL;
	if (pow->next != NULL)
	{
		p = pow->next->next;
	}
	free(pow->next);
	pow->next = p;
}
void SLTInsert(SListNode** pphead, SListNode* pow, SLTDateType x)
{
	assert(pphead != NULL);
	assert(pow != NULL);
	assert(*pphead != NULL);
	SListNode* p = *pphead;
	if (p == pow)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		while (p->next != pow)
		{
			p = p->next;
		}
		SListNode* newNode = BuySListNode(x);
		newNode->next = p->next;
		p->next = newNode;
	}
}
void SLTErase(SListNode** pphead, SListNode*pow)
{
	assert(pphead != NULL && *pphead != NULL);
	assert(pow != NULL);
	SListNode* p = *pphead;
	if (p == pow)
	{
		SListPopFront(pphead);
	}
	else
	{
		while (p->next != pow)
		{
			p = p->next;
		}
		SListNode* pc = p->next;
		p->next = p->next->next;
		free(pc);
		pc = NULL;
	}
}
void text1()
{
	SListNode* head = BuySListNode(1);
	head->next = BuySListNode(2);
	head->next->next = BuySListNode(3);
	head->next->next->next = BuySListNode(4);
	SListPrint(head);
	//SListPushFront(&head,1);
	//SListPushBack(&head, 3);
	//SListPrint(head);
	//SListPopBack(&head);
	//SListPopFront(&head);
	SListInsertAfter(SListFind(head, 4), 5);
	//SListEraseAfter(SListFind(head, 6));
	//SListEraseAfter(SListFind(head, 4));
	SListPrint(head);
	SLTInsert(&head, SListFind(head, 4),3);
	SListPrint(head);
	SLTErase(&head,SListFind(head, 4));
	SListPrint(head);
	SLTDestroy(&head);
}
int main()
{
	text1();
	return 0;
}