#include"text.h"
#define SIZE(N,M)(int)(((N*)0)->M)
//#define SIZE(N, M) (int)(&(((N*)0)->M))

int main()
{
	printf("%d",SIZE(Stack,top));
	return 0;
}
//typedef struct {
//    int* arr;
//    int front;
//    int back;
//    int k;
//} MyCircularQueue;
//
//
//MyCircularQueue* myCircularQueueCreate(int k) {
//    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//    q->arr = (int*)malloc(sizeof(int) * (k + 1));
//    q->front = 0;
//    q->back = 0;
//    q->k = k;
//    return q;
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
//    return obj->front == obj->back;
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj) {
//    return (obj->front - obj->back + obj->k) % (obj->k + 1) == 0;
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
//    if (myCircularQueueIsFull(obj))
//        return false;
//    obj->arr[obj->back++] = value;
//    obj->back %= (obj->k + 1);
//    return true;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj) {
//    if (myCircularQueueIsEmpty(obj))
//        return false;
//    obj->front++;
//    obj->front %= (obj->k + 1);
//    return true;
//}
//
//int myCircularQueueFront(MyCircularQueue* obj) {
//    if (myCircularQueueIsEmpty(obj))
//        return -1;
//    return obj->arr[obj->front];
//}
//
//int myCircularQueueRear(MyCircularQueue* obj) {
//    if (myCircularQueueIsEmpty(obj))
//        return -1;
//    int a = (obj->back + obj->k - 1) % obj->k;
//    return obj->arr[a];
//}
//
//
//void myCircularQueueFree(MyCircularQueue* obj) {
//    free(obj->arr);
//    free(obj);
//}
//int main()
//{
//    MyCircularQueue* q= myCircularQueueCreate(3);
//    myCircularQueueEnQueue(q,1);
//    myCircularQueueEnQueue(q, 2);
//    myCircularQueueEnQueue(q, 3);
//    myCircularQueueEnQueue(q, 4);
//    int a=myCircularQueueRear(q);
//    bool b = myCircularQueueIsFull(q);
//    myCircularQueueDeQueue(q);
//    myCircularQueueEnQueue(q, 4);
//    int c = myCircularQueueRear(q);
//    myCircularQueueFree(q);
//    //["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"]
//}
//void test1()
//{
//	Stack s;
//	StackInit(&s);
//	StackPush(&s, 1);
//	StackPush(&s, 2);
//	StackPush(&s, 3);
//	StackPush(&s, 4);
//	StackPush(&s, 5);
//	while (!StackEmpty(&s))
//	{
//		printf("%d ", StackTop(&s));
//		StackPop(&s);
//	}
//	StackDestroy(&s);
//}
//void test2()
//{
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	while (!QueueEmpty(&q))
//	{
//		printf("%d ", QueueFront(&q));
//		QueuePop(&q);
//	}
//	QueueDestroy(&q);
//}
//typedef struct {
//    Queue Q1;
//    Queue Q2;
//} MyStack;
//
//
//MyStack* myStackCreate() {
//    MyStack* s = (MyStack*)malloc(sizeof(MyStack));
//    QueueInit(&s->Q1);
//    QueueInit(&s->Q2);
//    return s;
//}
//
//void myStackPush(MyStack* obj, int x) {
//    if (!QueueEmpty(&obj->Q2))
//    {
//        QueuePush(&obj->Q2, x);
//        return;
//    }
//    QueuePush(&obj->Q1, x);
//}
//
//int myStackPop(MyStack* obj) {
//    if (QueueEmpty(&obj->Q1))
//    {
//        while (QueueEmpty(&obj->Q2) && (obj->Q2).size != 1)
//        {
//            QueuePush(&obj->Q1, QueueFront(&obj->Q2));
//            QueuePop(&obj->Q2);
//        }
//        int num = QueueFront(&obj->Q2);
//        QueuePop(&obj->Q2);
//        return num;
//    }
//    while (QueueEmpty(&obj->Q1) && (obj->Q1).size != 1)
//    {
//        QueuePush(&obj->Q2, QueueFront(&obj->Q1));
//        QueuePop(&obj->Q1);
//    }
//    int num = QueueFront(&obj->Q1);
//    QueuePop(&obj->Q1);
//    return num;
//}
//
//int myStackTop(MyStack* obj) {
//    if (QueueEmpty(&obj->Q1))
//        return QueueBack(&obj->Q2);
//    return QueueBack(&obj->Q1);
//}
//
//bool myStackEmpty(MyStack* obj) {
//    return QueueEmpty(&obj->Q1) && QueueEmpty(&obj->Q2);
//}
//
//void myStackFree(MyStack* obj) {
//    QueueDestroy(&obj->Q1);
//    QueueDestroy(&obj->Q2);
//    free(obj);
//}
//int main()
//{
//	test1();
//	printf("\n");
//	test2();
//    MyStack* s = myStackCreate();
//    myStackPush(s, 1);
//    myStackPush(s, 2);
//    int a = myStackTop(s);
//    myStackPop(s);
//    bool b = myStackEmpty(s);
//	return 0;
//}