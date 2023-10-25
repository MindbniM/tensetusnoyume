#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include <stdio.h>
//int cutRope(int n) {
//    if (n <= 4)
//        return n;
//    else
//    {
//        return cutRope(n - 3) * 3;
//    }
//}
//int cutRope(int n) {
//    if (n <= 4)
//        return n;
//    int temp[n + 1];
//    temp[1] = 1;
//    temp[2] = 2;
//    temp[3] = 3;
//    temp[4] = 4;
//    for (int i = 5; i <= n; i++)
//    {
//        temp[i] = temp[i - 3] * 3;
//    }
//    return temp[n];
//}
//int cutRope(int n) {
//    if (n <= 4)
//        return n;
//    int cout = 1;
//    while (n > 4)
//    {
//        cout *= 3;
//        n -= 3;
//    }
//    return cout * n;
//}
//struct ListNode* deleteNode(struct ListNode* head, int val) {
//    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* newhead = p;
//    p->next = head;
//    while (p->next != NULL)
//    {
//        if (p->next->val == val)
//        {
//            p->next = p->next->next;
//        }
//        p = p->next;
//    }
//    return newhead->next;
//
//}