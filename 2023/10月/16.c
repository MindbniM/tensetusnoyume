#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p->next = head;
    struct ListNode* cout = p;
    while (p->next != NULL)
    {
        if (p->next->val == val)
        {
            struct ListNode* pl = p->next;
            p->next = p->next->next;
            free(pl);
        }
        else
            p = p->next;
    }
    head = cout->next;
    free(cout);
    return head;
}