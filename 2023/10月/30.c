#define _CRT_SECURE_NO_WARNINGS
#include "text.h"
void SeqListInit(SeqList* SL)
{
	assert(SL != NULL);
	SLDateType* pSLDate = (SLDateType*)malloc(sizeof(SLDateType) * MAX);
	if (pSLDate == NULL)
	{
		perror("malloc:");
		return;
	}
	SL->a = pSLDate;
	SL->capacity = MAX;
	SL->size = 0;
}
void SeqListDestroy(SeqList* SL)
{
	assert(SL != NULL);
	if (SL->a != NULL)
	{
		free(SL->a);
		SL->a = NULL;
		SL->capacity = 0;
		SL->size = 0;
	}
}
void SeqListPrint(SeqList* SL)
{
	assert(SL != NULL);
	for (int i = 0; i < SL->size; i++)
	{
		printf("%d ", SL->a[i]);
	}
}
void SeqListPushFront(SeqList* SL,SLDateType x)
{
	assert(SL != NULL);
	int num = SL->size;
	while (num> 0)
	{
		SL->a[num] = SL->a[num-1];
		num--;
	}
	SL->size++;
	SL->a[0] = x;
}
void SeqListPushBack(SeqList* SL,SLDateType x)
{
	assert(SL != NULL);
	SL->a[SL->size++] = x;
}
void SeqListPopFront(SeqList* SL)
{
	assert(SL != NULL&&SL->size>0);
	for (int i = 0; i < SL->size-1; i++)
	{
		SL->a[i] = SL->a[i + 1];
	}
	SL->size--;
}
void SeqListPopBack(SeqList* SL)
{
	assert(SL != NULL&&SL->size>0);
	SL->size--;
}
int SeqListFind(SeqList* SL, SLDateType x)
{
	assert(SL != NULL);
	for (int i = 0; i < SL->size; i++)
	{
		if (SL->a[i] == x)
			return i;
	}
	return -1;
}
void SeqListInsert(SeqList* SL, int pow, SLDateType x)
{
	int num = SL->size;
	while (num > pow)
	{
		SL->a[num] = SL->a[num - 1];
		num--;
	}
	SL->size++;
	SL->a[pow] = x;
}
void SeqListErase(SeqList* SL, int pow)
{
	assert(SL != NULL);
	for (int i = pow; i < SL->size - 1; i++)
	{
		SL->a[i] = SL->a[i + 1];
	}
	SL->size--;
}
void test1()
{
	SeqList SL;
	SeqListInit(&SL);
	SeqListPushFront(&SL, 1);
	SeqListPushFront(&SL, 2);
	SeqListPushFront(&SL, 3);
	SeqListPushBack(&SL, 1);
	SeqListPushBack(&SL, 2);
	SeqListPushBack(&SL, 3);
	SeqListPopFront(&SL);
	SeqListPopBack(&SL);
	SeqListInsert(&SL, 1, 5);
	SeqListPrint(&SL);
	printf("\n");
	SeqListErase(&SL, 2);
	SeqListPrint(&SL);

	SeqListDestroy(&SL);
}
int main()
{
	test1();
	return 0;
}