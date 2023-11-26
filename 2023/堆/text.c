#include"Heap.h"
void HeapSort1(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		AdjustUp(arr, i);
	}
	int n=size-1;
	while (n>0)
	{
		Swap(&arr[0], &arr[n]);
		AdjustDown(arr, n, 0);
		n--;
	}

}
void HeapSort2(int* arr, int size)
{
	for (int i = (size - 1) / 2; i >= 0; i--)
		AdjustDown(arr, size, i);
	int n = size - 1;
	while (n > 0)
	{
		Swap(&arr[0], &arr[n]);
		AdjustDown(arr, n, 0);
		n--;
	}
}
void CreatData()
{
	FILE* file = fopen("test.txt", "w");
	if (file == NULL)
		return;
	int n = 1000;
	for (int i = 0; i < n; i++)
	{
		fprintf(file, "%d\n", (rand() + i) % 100);
	}
	fclose(file);
}
void test1()
{
	int arr[] = { 5,44,5,33,2,1,1,4,66,54,52,11,2, };
	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort2(arr, size);
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}
void PrintTopK(int k)
{
	int* arr = (int*)malloc(sizeof(int) * k);
	if (arr == NULL)
		return;

	FILE* file = fopen("test.txt", "r");
	if (file == NULL)
		return;

	for (int i = 0; i < k; i++)
	{
		fscanf(file, "%d", &arr[i]);
		AdjustUp(arr, i);
	}

	int x;
	while (fscanf(file, "%d", &x) != EOF)
	{
		if (x > arr[0])
		{
			arr[0] = x;
			AdjustDown(arr, k, 0);
		}
	}
	int n = k - 1;
	while (n > 0)
	{
		Swap(&arr[0], &arr[n]);
		AdjustDown(arr, n, 0);
		n--;
	}
	for (int i = 0; i < k; i++)
		printf("%d ", arr[i]);
	free(arr);
	fclose(file);

}
void test2()
{
	CreatData();
	PrintTopK(10);
}
int main()
{
	//test2();
	PrintTopK(10);
	return 0;
}