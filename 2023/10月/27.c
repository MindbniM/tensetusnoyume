#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include <stdio.h>
typedef int typed;
typedef struct Tree
{
	typed date;
	struct Tree* lchild;
	struct Tree* rchild;
}Tree;
Tree* createTree(typed date)
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
	Tree* T = createTree(1);
	T->lchild = createTree(2);
	T->rchild = createTree(3);
	T->lchild->lchild = createTree(4);
	T->lchild->rchild = createTree(5);
	T->rchild->lchild = createTree(6);
	T->rchild->rchild = createTree(7);
	print_Tree(T);
	freeTree(T);
	return 0;
}