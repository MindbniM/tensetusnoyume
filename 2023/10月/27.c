#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include <stdio.h>
typedef int ElenType;
typedef struct Tree
{
	ElenType date;
	struct Tree* lchild;
	struct Tree* rchild;
}Tree;
typedef struct Node
{
	Tree* date;
	struct Node* top;
}Node;
typedef struct Stack
{
	struct Node* Node;
	int num;
}Stack;
Stack* InitStack()
{
	Stack* S =(Stack*) malloc(sizeof(Stack));
	if (S == NULL)
	{
		perror("malloc:");
		return NULL;
	}
	S->num = 0;
	S->Node = NULL;
	return S;
}
void push(Stack* St, Tree* data)
{
	if (St == NULL)
		return ;
	Node* S = (Node*)malloc(sizeof(Node));
	if (S == NULL)
	{
		perror("malloc:");
		return ;
	}
	Node* p = St->Node;
	St->Node = S;
	S->date = data;
	S->top = p;
	St->num++;
}
Tree* pop(Stack* St)
{
	if (St == NULL)
		return NULL;
	Node* p = St->Node;
	Tree* num = p->date;
	St->Node = St->Node->top;
	free(p);
	St->num--;
	return num;
}
void freeStack(Stack* St)
{
	if (St == NULL)
		return ;
	while (St->Node != NULL)
	{
		pop(St);
	}
	free(St);
}
Tree* createTree(ElenType date)
{
	Tree* T = (Tree*)malloc(sizeof(Tree));
	if (T == NULL)
	{
		perror("malloc:");
		return NULL;
	}
	T->date = date;
	T->lchild = NULL;
	T->rchild = NULL;
	return T;
}
void Stack_print_Tree(Stack* St, Tree* T)
{
	if (St == NULL||T==NULL)
		return ;
	Tree* t = T;
	while (t != NULL || St->num > 0)
	{
		if (t != NULL)
		{
			push(St, t);
			t = t->lchild;
		}
		else
		{
			Tree* Tr = pop(St);
			printf("%d", Tr->date);
			t = Tr->rchild;
		}
	}
}
void print_Tree(Tree* T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		print_Tree(T->lchild);
		printf("%d", T->date);
		print_Tree(T->rchild);
	}
}
void freeTree(Tree* T)
{
	if (T == NULL)
	{
		return;
	}
	freeTree(T->lchild);
	freeTree(T->rchild);
	free(T);
	T = NULL;
}
int main()
{
	Stack* S = InitStack();
	Tree* T = createTree(1);
	T->lchild = createTree(2);
	T->rchild = createTree(3);
	T->lchild->lchild = createTree(4);
	T->lchild->rchild = createTree(5);
	T->rchild->lchild = createTree(6);
	T->rchild->rchild = createTree(7);
	Stack_print_Tree(S, T);
	printf("\n");
	print_Tree(T);
	freeTree(T);
	T = NULL;
	return 0;
}