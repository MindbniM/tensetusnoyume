#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include <stdio.h>
//struct ListNode* swapPairs(struct ListNode* head) {
//    struct ListNode* p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* p = p1;
//    p->next = head;
//    if (head == NULL)
//        return NULL;
//    while (p->next != NULL && p->next->next != NULL)
//    {
//        struct ListNode* pc = p->next;
//        struct ListNode* pl = p->next->next->next;
//        p->next = p->next->next;
//        p->next->next = pc;
//        pc->next = pl;
//        p = p->next->next;
//    }
//    return p1->next;
//}
//struct ListNode* reverseList(struct ListNode* head) {
//    struct ListNode* p = NULL;
//    while (head != NULL)
//    {
//        struct ListNode* pc = head->next;
//        head->next = p;;
//        p = head;
//        head = pc;
//    }
//    return p;
//}
//struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
//    struct ListNode* pc = (struct ListNode*)malloc(sizeof(struct ListNode));
//    pc->next = head;
//    struct ListNode* p = pc;
//    int cout = 0;
//    while (p->next != NULL)
//    {
//        cout++;
//        p = p->next;
//    }
//    p = pc;
//    for (int i = 0; i < cout - n; i++)
//    {
//        p = p->next;
//    }
//    struct ListNode* Li = p->next;
//    p->next = p->next->next;
//    free(Li);
//    return pc->next;
//}
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    struct ListNode* b = headB;
//    while (headA != NULL)
//    {
//        b = headB;
//        while (b != NULL)
//        {
//            if (headA == b)
//            {
//                return b;
//            }
//            b = b->next;
//        }
//        headA = headA->next;
//    }
//    return NULL;
//}
//int is_arr(struct ListNode* arr[], struct ListNode* p)
//{
//    int i = 0;
//    while (arr[i] != 0)
//    {
//        if (arr[i] == p)
//            return 1;
//        i++;
//    }
//    return 0;
//}
//struct ListNode* detectCycle(struct ListNode* head) {
//    struct ListNode* arr[10000] = { 0 };
//    int i = 0;
//    while (head != NULL)
//    {
//        if (is_arr(arr, head))
//            return head;
//        else
//            arr[i++] = head;
//        head = head->next;
//    }
//    return NULL;
//}
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* a = head;
    struct ListNode* b = head;
    do
    {
        if (a == NULL || b == NULL || b->next == NULL)
            return NULL;
        a = a->next;
        b = b->next->next;
    } while (b != a);
    while (head != b)
    {
        head = head->next;
        b = b->next;
    }
    return head;
}