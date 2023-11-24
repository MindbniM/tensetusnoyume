#include"Heap.h"
void test1()
{
	Heap h;
	HeapInit(&h);
	int arr[] = { 5,44,5,33,2,1,1,4,66,54,52,11,2, };
	for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
		HeapPush(&h, arr[i]);
	while (!HeapEmpty(&h))
	{
		printf("%d ", HeapTop(&h));
		HeapPop(&h);
	}

}
int main()
{
	//test1();
	return 0;
}