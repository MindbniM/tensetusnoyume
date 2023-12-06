#include"sort.h"
void Prin(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void Swap(int* a, int* b)
{
	int tem = *a;
	*a = *b;
	*b = tem;
}
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp=a[end+1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
	
}
void ShellSort(int* a, int n)
{
	int gap=n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int j = 0; j < gap; j++)
		{
			for (int i = 0; i < n - gap; i += gap)
			{
				int end = i;
				int tmp = a[end + gap];
				while (end >= 0)
				{
					if (tmp < a[end])
					{
						a[end + gap] = a[end];
						end-=gap;
					}
					else
					{
						break;
					}
				}
				a[end + gap] = tmp;
			}
		}
	}
}
void SelectSort(int* a, int n)
{
	int gap = 0;
	int end = n - 1;
	while (gap < end)
	{
		int maxi = gap, mini = gap;
		for (int i = gap+1; i <= end; i++)
		{
			if (a[mini] > a[i])
			{
				mini = i;
			}
			if (a[maxi] < a[i])
			{
				maxi = i;
			}
		}
		Swap(&a[gap], &a[mini]);
		if (gap == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		gap++;
		end--;
	}
}
void AdjustDown(int* a,int parent,int size)
{
	int child = parent *2 + 1;
	while (child < size)
	{
		if (child+1<size&&a[child] < a[child + 1])
			child++;
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent*2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, i, n);
	}
	int end = n-1 ;
	while (end)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, 0, end );
		end--;
	}
}
int PartSort1(int* a, int left, int right)
{
	int keyi = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
			right--;
		while (left < right&&a[left] <= a[keyi])
			left++;
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	return left;
}
int PartSort2(int* a, int left, int right)
{

}
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	int keyi = PartSort1(a, begin, end);
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
	
}