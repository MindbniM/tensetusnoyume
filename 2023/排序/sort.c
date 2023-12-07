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
	int keyi = Getmind(a, left, right);
	Swap(&a[left], &a[keyi]);
	keyi = left;
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
	int keyi = Getmind(a, left, right);
	int temp = a[keyi];
	Swap(&a[left], &a[keyi]);
	int bol=left;
	while (left < right)
	{
		while (left < right && a[right] >= temp)
			right--;
		a[bol] = a[right];
		bol = right;
		while (left < right && a[left] <= temp)
			left++;
		a[bol] = a[left];
		bol = left;
	}
	a[left] = temp;
	return left;
}
int PartSort3(int* a, int left, int right)
{
	int keyi = Getmind(a,left,right);
	Swap(&a[left], &a[keyi]);
	keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi])
		{
			prev++;
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}
int Getmind(int* a, int left, int right)
{
	int mind = (left + right) / 2;
	if (a[left] > a[mind]&&a[left]>a[right])
	{
		if (a[mind] > a[right])
			return mind;
		else
			return right;
	}
	if (a[right] > a[mind] && a[right] > a[left])
	{
		if (a[mind] > a[left])
			return mind;
		else
			return left;
	}
	if (a[mind] > a[left] && a[mind] > a[right])
	{
		if (a[left] > a[right])
			return left;
		else
			return right;
	}
}
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	int keyi = PartSort1(a, begin, end);
	if (end - begin > 10)
	{
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
	else
		InsertSort(a, end - begin + 1);
}