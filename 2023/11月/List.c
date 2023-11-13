#include"STL.h"
ListNode* NodeCreate(LTDataType x)
{
	ListNode* Node = (ListNode*)malloc(sizeof(ListNode));
	if (Node == NULL)
	{
		perror("malloc;");
		exit(-1);
	}
	Node->next = NULL;
	Node->prev = NULL;
	Node->data = x;
	return Node;
}
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	if (head == NULL)
	{
		perror("malloc;");
		return NULL;
	}
	head->data = 0;
	head->next = head;
	head->prev = head;
	return head;
}
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* pHeadnext = pHead->next;
	while (pHeadnext != pHead)
	{
		ListNode* p = pHeadnext;
		pHeadnext = pHeadnext->next;
		free(p);
	}
	free(pHead);
}
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* pHeadnext = pHead->next;
	printf("head");
	while (pHeadnext != pHead)
	{
		ListNode* p = pHeadnext;
		pHeadnext = pHeadnext->next;
		printf("<-->%d", p->data);
	}
	printf("\n");
}
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newNode = NodeCreate(x);
	newNode->prev = pHead->prev;
	pHead->prev->next = newNode;
	newNode->next = pHead;
	pHead->prev = newNode;
}
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListNode* pHeadprev = pHead->prev;
	if (pHeadprev == pHead)
		return;
	pHead->prev = pHeadprev->prev;
	pHeadprev->prev->next = pHead;
	free(pHeadprev);
	pHeadprev = NULL;
}
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newNode = NodeCreate(x);
	ListNode* pHeadnext = pHead->next;
	pHead->next = newNode;
	newNode->prev = pHead;
	newNode->next = pHeadnext;
	pHeadnext->prev = newNode;
}
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	ListNode* pHeadnext = pHead->next;
	if (pHeadnext == pHead)
		return;
	pHead->next = pHeadnext->next;
	pHeadnext->next->prev = pHead;
	free(pHeadnext);
	pHeadnext = NULL;
}