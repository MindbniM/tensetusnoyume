#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include <stdio.h>
int Max_Size = 10;
typedef struct Stack
{
	int *arr;
	int top;
}Stack;
void InitStack(Stack* s)
{
	int*p = (int*)malloc(sizeof(int) * Max_Size);
	if (p)
	{
		s->arr = p;
	}
	else
	{
		perror("malloc:");
		return;
	}
	s->top = -1;
}
int isFull(Stack* s)
{
	if (s->top == Max_Size - 1)
	{
		return 1;
	}
	return 0;
}
void resize(Stack* s) {
	Max_Size += 10;
	int* p = (int*)realloc(s->arr, Max_Size * sizeof(int));
	if (p)
		s->arr = p;
	else
		perror("realloc:");
}
int isEmpty(Stack* s)
{
	if (s->top==-1)
		return 1;
	return 0;
}
void push(Stack* s,int value)
{
	if (isFull(s))
	{
		printf("Õ»Âú\n");
		return;
	}
	s->top++;
	s->arr[s->top] = value;
	
}
int pop(Stack* s)
{
	if (isEmpty(s))
	{
		printf("Õ»ÒÑÎª¿Õ\n");
		return;
	}
	int value= s->arr[s->top];
	s->top--;
	return value;
}
void destroyStack(Stack *s)
{
	free(s->arr);
	s->arr = NULL;
	s->top = -1;
}
int main()
{
	Stack s;
	InitStack(&s);
	int a;
	scanf("%d", &a);
	while (a)
	{
		push(&s,a % 2);
		a /= 2;
	}
	while (!isEmpty(&s))
	{
		printf("%d",pop(&s));
	}
	return 0;
}