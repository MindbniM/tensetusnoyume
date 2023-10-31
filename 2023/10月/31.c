#define _CRT_SECURE_NO_WARNINGS
#include "text.h"
Tree* createTree(int date)
{
	Tree* T = (Tree*)malloc(sizeof(Tree));
	assert(T);
	T->date = date;
	T->lchild = NULL;
	T->rchild = NULL;
	return T;
}
void inSqQueue(SQ*S,Tree* date)
{
	S->front = (SLT*)malloc(sizeof(SLT));
	S->front->date = date;
	S->front->next = NULL;
}
Tree* popSqQueue(SQ* S)
{
	SLT* SL = (SLT*)malloc(sizeof(SLT));
	SL->next = S->front;
	while (SL->next!=NULL&&SL->next->next != NULL)
	{
		SL = SL->next;
	}
	S->back = SL;
	return SL->next->date;
}
int IsEmpty(SQ* S)
{
	if (S->front == S->back)
		return 1;
	return 0;
}
int main()
{
	Tree* T = createTree(1);
	T->lchild = createTree(2);
	T->rchild = createTree(3);
	T->lchild->lchild = createTree(4);
	T->lchild->rchild = createTree(5);
	T->rchild->lchild = createTree(6);
	T->rchild->rchild = createTree(7);
	SQ S;
	S.back = NULL;
	inSqQueue(&S, T);
	while (!IsEmpty(&S))
	{
		Tree* t= popSqQueue(&S);

		printf("%d",t->date);
		if (t->lchild != NULL)
			inSqQueue(&S, t->lchild);
		if (t->rchild != NULL)
			inSqQueue(&S, t->rchild);
		if (t->date == 7)
			break;
	}
}