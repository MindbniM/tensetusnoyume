#include"text.h"
void StackInit(Stack* ps)
{
	assert(ps);
	STDataType* arr = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (arr == NULL)
	{
		perror("malloc;");
		return;
	}
	ps->arr = arr;
	ps->capacity = 4;
	ps->top = -1;
}
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->top+1 == ps->capacity)
	{
		int newcapactily = ps->capacity + 2;
		STDataType* newarr = (STDataType*)realloc(ps->arr, sizeof(STDataType) * newcapactily);
		if (newarr == NULL)
		{
			perror("malloc;");
			return;
		}
		ps->arr = newarr;
		ps->capacity = newcapactily;
	}
	ps->arr[++ps->top] = data;
}
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > -1);
	ps->top--;
}
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > -1);
	return ps->arr[ps->top];
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == -1;
}
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = 0;
	ps->top = -1;
}



void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
	q->size = 0;
}

void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* node = (QNode*)malloc(sizeof(QNode));
	if (node == NULL)
	{
		perror("malloc;");
		return;
	}
	node->data = data;
	node->next = NULL;
	if (q->front == NULL)
	{
		q->front = node;
		q->rear = node;
	}
	else
	{
		q->rear->next = node;
		q->rear = node;
	}
	q->size++;
}

void QueuePop(Queue* q)
{
	assert(q);
	assert(q->front);
	QNode* p = q->front->next;
	free(q->front);
	q->front = p;
	p = NULL;
	if (q->front == NULL)
	{
		q->rear = NULL;
	}
	q->size--;
}
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->front);
	return q->front->data;
}
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->rear);
	return q->rear->data;
}
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->size == 0;
}
void QueueDestroy(Queue* q)
{
	assert(q);
	while (!QueueEmpty(q))
	{
		QueuePop(q);
	}
	q->front = q->rear = NULL;
}