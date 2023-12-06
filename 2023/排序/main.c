#include"sort.h"
void InsertSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,6, };
	Prin(a, 10);
	InsertSort(a, 10);
	Prin(a, 10);
}
void ShellSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,6, };
	Prin(a, 10);
	ShellSort(a, 10);
	Prin(a, 10);
}
void SelectSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,6, };
	Prin(a, 10);
	SelectSort(a, 10);
	Prin(a, 10);
}
void HeapSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,6, };
	Prin(a, 10);
	HeapSort(a, 10);
	Prin(a, 10);
}
void QuickSortTest()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,6, };
	Prin(a, 10);
	QuickSort(a,0,9);
	Prin(a, 10);
}
int main()
{
	//InsertSortTest();
	//ShellSortTest();
	//SelectSortTest();
	//HeapSortTest();
	QuickSortTest();
	return 0;
}