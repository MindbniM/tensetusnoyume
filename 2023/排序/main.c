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
int main()
{
	//InsertSortTest();
	ShellSortTest();
	return 0;
}