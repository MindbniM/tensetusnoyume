#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include <stdio.h>

#define Max_Size 32
typedef struct Stack
{
	int arr[Max_Size];
	int top;
}Stack;
void InitStack(Stack* s)
{
	s->top = -1;
}
int isFull(Stack* s)
{
	if (s->top == Max_Size - 1)
		return 1;
	return 0;
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
		printf("Õ»ÒÑÎª¿Õ\n");
	int value= s->arr[s->top];
	s->top--;
	return value;
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