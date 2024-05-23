#ifndef LINKSTACK_H
#define LINKSTACK_H

typedef int SElemType;
typedef struct StackNode
{
	SElemType data;
	struct StackNode* next;
}StackNode;

typedef struct
{
	StackNode* top;
	int cursize;
}LinkStack;

extern void InitStack(LinkStack& st);
extern void DestroyStack(LinkStack& st);
extern void ClearStack(LinkStack& st);
extern int GetSize(const LinkStack& st);
extern bool StackEmpty(const LinkStack& st);
extern bool Push(LinkStack& st, SElemType val);
extern bool GetTop(const LinkStack& st, SElemType& val);
extern bool Pop(LinkStack& st, SElemType& val);


#endif 

