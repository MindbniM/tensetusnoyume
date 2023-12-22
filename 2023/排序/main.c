#include"sort.h"
void SortTest(void(*Sort)(int*,int))
{
	int a[] = { 8,8,8,6,5,8,3,2,8,7,8,8,16,15,14,12 };
	Prin(a, 16);
	Sort(a, 16);
	Prin(a, 16);
}
int main()
{
	SortTest(CountSort);
	return 0;
}