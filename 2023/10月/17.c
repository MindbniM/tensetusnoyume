#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include <stdio.h>
typedef struct MyLinkedList {
    int val;
    struct MyLinkedList* next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* p = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (p == NULL)
        return NULL;
    p->next = NULL;
    return p;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    int num = 0;
    if (obj == NULL)
        return -1;
    while (obj->next != NULL)
    {
        if (num == index)
            return obj->next->val;
        obj = obj->next;
        num++;
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* p = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (p == NULL)
        return;
    p->val = val;
    MyLinkedList* pl = obj->next;
    obj->next = p;
    p->next = pl;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* p = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (p == NULL)
        return;
    p->val = val;
    p->next = NULL;
    while (obj->next != NULL)
        obj = obj->next;
    obj->next = p;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    int sum = 0;
    MyLinkedList* pc = obj;
    while (obj->next != NULL)
    {
        if (sum == index)
        {
            MyLinkedList* p = (MyLinkedList*)malloc(sizeof(MyLinkedList));
            if (p == NULL)
                return;
            p->val = val;
            MyLinkedList* pl = obj->next;
            obj->next = p;
            p->next = pl;
        }
        else
            obj = obj->next;
        sum++;
    }
    if (sum == index)
    {
        MyLinkedList* p = (MyLinkedList*)malloc(sizeof(MyLinkedList));
        if (p == NULL)
            return;
        p->val = val;
        p->next = NULL;
        while (obj->next != NULL)
            obj = obj->next;
        obj->next = p;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    int num = 0;
    while (obj->next != NULL)
    {
        if (num == index)
        {
            MyLinkedList* p = obj->next;
            obj->next = obj->next->next;
            free(p);
        }
        else
            obj = obj->next;
        num++;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    while (obj != NULL)
    {
        MyLinkedList* p = obj;
        obj = obj->next;
        free(p);
    }

}
