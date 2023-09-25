#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include <stdio.h>
typedef struct Node
{
	int num;
	struct Node* next;
}Node;
typedef struct Stack
{
	Node* hread;//Í·Ö¸Õë
	Node* ebp;//Õ»¶¥Ö¸Õë
};
void InitStack(Stack* s)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (!p)
	{
		perror("malloc:");
		return;
	}
	s->hread = p;
	s->hread->next = NULL;
	s->ebp = p;
}
void Push(Stack* s, int value)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (!p)
	{
		perror("malloc:");
		return;
	}
	p->num = value;
	p->next = s->ebp;
	s->ebp = p;
}
int IsEmpty(Stack* s)
{
	return (s->ebp == s->hread);
}
int Pop(Stack* s)
{
	if (IsEmpty(s))
	{
		printf("Õ»¿Õ\n");
		return -1;
	}
	int value = s->ebp->num;
	Node* p = s->ebp;
	s->ebp = s->ebp->next;
	free(p);
	return value;
}
void DeStack(Stack* s)
{
	while (!IsEmpty(s)) 
	{
		Node* temp = s->ebp;
		s->ebp = s->ebp->next;
		free(temp);
	}
}
int main()
{
	Stack s;
	InitStack(&s);
	int a = 128;
	while (a)
	{
		Push(&s, a % 2);
		a /= 2;
	}
	while (!IsEmpty(&s))
	{
		printf("%d ", Pop(&s));
	}
	DeStack(&s);
	return 0;
}