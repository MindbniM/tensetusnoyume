#include"Heap.h"
void HeapInit(Heap* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->size = 0;
	hp->capacity = 0;
}

void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->size = 0;
	hp->capacity = 0;
}
void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType num = *a;
	*a = *b;
	*b = num;
}
void AdjustUp(HPDataType* a, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void AdjustDown(HPDataType* a,int size, int panest)
{
	assert(a);
	int child = panest * 2 + 1;
	while (child<size)
	{
		if (child+1<size&&a[child] > a[child + 1])
		{
			child++;
		}
		if (a[panest] > a[child])
		{
			Swap(&a[panest], &a[child]);
			panest = child;
			child = panest * 2 + 1;
		}
		else
		{
			break;
		}

	}
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newcapacity = hp->capacity == 0 ? 10 : hp->capacity *2;
		HPDataType* arr = (HPDataType*)realloc(hp->a,sizeof(HPDataType) * newcapacity);
		if (arr == NULL)
		{
			perror("realloc:");
			exit(-1);
		}
		hp->a = arr;
		hp->capacity = newcapacity;
	}
	hp->a[hp->size++] = x;
	AdjustUp(hp->a, hp->size - 1);
}

void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);
	Swap(&(hp->a[0]), &(hp->a[hp->size - 1]));
	hp->size--;
	AdjustDown(hp->a, hp->size, 0);
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);
	return hp->a[0];
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size - 1;
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}
