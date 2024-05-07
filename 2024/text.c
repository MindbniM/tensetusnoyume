#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int merge(int* arr, size_t size)//接收一个数组的首地址和元素个数,返回数组逆序对的个数
{
	int gap = 1;//表示归并的两个子数组的元素个数
	int* temp = (int*)malloc(sizeof(int) * size);//辅助数组
	int r_ret = 0;//逆序对的个数
	while (gap < size)
	{
		int begin = 0, end = size - 1;//数组的区间
		for (int i = begin; i <=end; i+=2*gap)
		{
			int begin1 = i, end1 = i + gap-1;//要归并的第一个子数组的闭区间
			int begin2 = i + gap, end2 = i + 2 * gap - 1;//要归并的第二个子数组的闭区间
			if (begin2 > end) continue;//第二个子数组不存在
			if (end2 > end) end2 = end;//第二个子数组的元素个数不够,修正边界
			int p = begin1;//辅助数组的相应位置
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (arr[begin1] <= arr[begin2])
				{
					temp[p++] = arr[begin1++];
				}
				else
				{
					r_ret += end1 - begin1 + 1;//在这里统计逆序对的个数
					temp[p++] = arr[begin2++];
				}
			}
			while (begin1 <= end1) temp[p++] = arr[begin1++];
			while (begin2 <= end2) temp[p++] = arr[begin2++];//上面都是归并过程
			memcpy(arr+i, temp+i, 4 * (end2-i+1));//从辅助数组拷贝回原数组
		}
		gap *= 2;
	}
	free(temp);
	return r_ret;
}
int main()
{
	int arr[2] = {0,0 };
	int ret=merge(arr, 2);
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	printf("逆序对的个数%d\n", ret);
	return 0;
}