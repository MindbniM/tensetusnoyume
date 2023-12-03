#include"Tree.h"
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