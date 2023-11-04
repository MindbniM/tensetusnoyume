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
			printf("%d ", plist->data);
			plist = plist->next;
		}
	}
	printf("\n");
}
void SListFree(SListNode** pplist)
{
	assert(pplist!=NULL);
	SListNode* p = *pplist;
	while (p != NULL)
	{
		SListNode* pc = p;
		p = p->next;
		free(pc);
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
	assert(plist != NULL );
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
	if (pow == NULL)
	{
		printf("该结点不存在\n");
		return;
	}
	SListNode* newNode = BuySListNode(x);
	SListNode*p=pow->next;
	pow->next = newNode;
	newNode->next = p;
}
void SListEraseAfter(SListNode* pow)
{
	if (pow == NULL)
	{
		printf("该结点不存在\n");
		return;
	}
	SListNode* p = NULL;
	if (pow->next != NULL)
	{
		p = pow->next->next;
	}
	free(pow->next);
	pow->next = p;
}
SListNode* SLTInsert(SListNode** pphead, SListNode* pow, SLTDateType x)
{

}
void text1()
{
	SListNode* head = BuySListNode(1);
	head->next = BuySListNode(2);
	head->next->next = BuySListNode(3);
	head->next->next->next = BuySListNode(4);
	//SListPushFront(&head,1);
	//SListPushBack(&head, 3);
	//SListPrint(head);
	//SListPopBack(&head);
	//SListPopFront(&head);
	SListInsertAfter(SListFind(head, 4), 5);
	SListPrint(head);
	SListEraseAfter(SListFind(head, 6));
	SListPrint(head);
	SListFree(&head);
}
int main()
{
	text1();
	return 0;
}