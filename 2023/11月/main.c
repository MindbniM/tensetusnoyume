#include"text.h"
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