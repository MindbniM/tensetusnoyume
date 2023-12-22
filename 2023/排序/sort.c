#include"sort.h"
#include"text.h"
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
void InsertSort(int* a, int n)//插入排序
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
void ShellSort(int* a, int n)//希尔排序
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
void SelectSort(int* a, int n)//选择排序
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
void AdjustDown(int* a,int parent,int size)//堆排序向下调整
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
void HeapSort(int* a, int n)//堆排序
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
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n ; i++)
	{
		bool temp = true;
		for (int j = 0; j < n - 1-i ; j++)
		{
			if (a[j] > a[j+1])
			{
				Swap(&a[j], &a[j+1]);
				temp = false;
			}
		}
		if (temp)
			break;
	}
}
int PartSort1(int* a, int left, int right)//快排方法一(老式)
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
int PartSort2(int* a, int left, int right)//快排方法二(坑)
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
int PartSort3(int* a, int left, int right)//快排方法三(双指针)
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
int Getmind(int* a, int left, int right)//快排优化三数取中
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
void QuickSort(int* a, int begin, int end)//快排
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
		InsertSort(a, end - begin + 1);//快排优化递归优化
}
void QSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	int keyi = Getmind(a, begin, end);
	int key = a[keyi];
	int left = begin, right = end;
	int cur = begin + 1;
	while (cur <= right)
	{
		if (a[cur] < key)
		{
			Swap(&a[cur], &a[left]);
			left++;
			cur++;
		}
		else if (a[cur] == key)
		{
			cur++;
		}
		else
		{
			Swap(&a[cur], &a[right]);
			right--;
		}
	}
	if (end - begin > 10)
	{
		QuickSort(a, begin, left-1);
		QuickSort(a, right+1, end);
	}
	else
		InsertSort(a, end - begin + 1);
}
void QuickNonRSort(int* a, int begin, int end)//快排非递归
{
	Stack s;
	StackInit(&s);
	StackPush(&s, end);
	StackPush(&s, begin);
	while (!StackEmpty(&s))
	{
		int begin1 = StackTop(&s);
		StackPop(&s);
		int end1 = StackTop(&s);
		StackPop(&s);
		int keyi = PartSort1(a, begin1, end1);
		if (keyi - 1 > begin1)
		{
			StackPush(&s, keyi - 1);
			StackPush(&s, begin1);
		}
		if (keyi + 1 < end1)
		{
			StackPush(&s, end1);
			StackPush(&s, keyi+1);
		}
	}
	StackDestroy(&s);
}
void _Merge(int* a, int* temp, int left, int right)//归并递归
{
	if (left >= right)
		return;
	int mid = (right + left) / 2;
	_Merge(a, temp, left, mid);
	_Merge(a, temp, mid+1, right);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int cout = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			temp[cout++] = a[begin1];
			begin1++;
		}
		else
		{
			temp[cout++] = a[begin2];
			begin2++;
		}
	}
	while (begin1 <= end1)
	{
		temp[cout++] = a[begin1];
		begin1++;
	}
	while (begin2 <= end2)
	{
		temp[cout++] = a[begin2];
		begin2++;
	}
	memcpy(a+left, temp+left, (right - left + 1) * sizeof(int));
}
void MergeSort(int* a, int n)//归并
{
	int* temp = (int*)malloc(n * sizeof(int));
	assert(temp);
	_Merge(a, temp, 0, n-1);
	free(temp);
}
void MergeNonRSort(int* a, int n)//归并排序非递归
{
	int* temp = (int*)malloc(n * sizeof(int));
	assert(temp);
	int gap = 1;
	while(gap<n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int cout = i;
			if (begin2 >= n)
				break;
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
				{
					temp[cout++] = a[begin1];
					begin1++;
				}
				else
				{
					temp[cout++] = a[begin2];
					begin2++;
				}
			}
			while (begin1 <= end1)
			{
				temp[cout++] = a[begin1];
				begin1++;
			}
			while (begin2 <= end2)
			{
				temp[cout++] = a[begin2];
				begin2++;
			}
			memcpy(a + i, temp + i, (end2-i+1) * sizeof(int));
		}
		gap *= 2;
	}
	free(temp);
}
void CountSort(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int size = max - min + 1;
	int* arr = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		arr[a[i] - min]++;
	}
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		int cout = arr[i];
		while (cout>0)
		{
			a[temp++] = i + min;
			cout--;
		}
	}

}
