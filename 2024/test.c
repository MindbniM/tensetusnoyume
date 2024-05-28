﻿#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct edge//对边的描述
{
	int begin;
	int end;
	int Weights;
}edge;
void print_matrix(int** arr,int n)//打印邻接矩阵
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%-5d", arr[i][j]);
		}
		printf("\n");
	}
}
void scanf_matrix(FILE*file,int** arr, int n)//从文件读取测试样例
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fscanf(file, "%d", &arr[i][j]);
		}
	}
}
int** create_matrix(FILE* file,int n)//创建邻接矩阵并初始化
{
	int** arr = (int**)malloc(sizeof(int*) * n);
	if (arr == NULL)
		return NULL;
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int*)calloc(n, sizeof(int));
		if (arr[i] == NULL)
			return NULL;
	}
	scanf_matrix(file, arr, n);
	return arr;
}
void desrory_matrix(int** arr,int n)//释放内存
{
	for (int i = 0; i < n; i++) free(arr[i]);
	free(arr);
}
int* create_UnionFindSet(int n)//创建一个并查集
{
	int* arr = (int*)malloc(sizeof(int)*n);
	if (arr == NULL)
		return NULL;
	for (int i = 0; i < n; i++)arr[i] = -1;
	return arr;
}
int comp(const void* n1, const void* n2)//qsort函数的比较函数
{
	edge* p1 = n1, * p2 = n2;
	return p1->Weights - p2->Weights;
}
int edge_num(int** arr,int n)//统计有多少边
{
	int size = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < j && arr[i][j] != 0) size++;
		}
	}
	return size;
}
edge* create_edge(int** arr,int n)//对所有边放入数组排序
{
	int size = edge_num(arr, n);
	edge* nums = (edge*)malloc(sizeof(edge) * size);
	if (arr == NULL)
		return NULL;
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < j&&arr[i][j]!=0)
			{
				edge n = { i,j,arr[i][j] };
				nums[s] = n;
				s++;
			}
		}
	}
	qsort(nums, size, sizeof(edge), comp);
	return nums;
}
void destory_UnionFindSet(int* arr)
{
	free(arr);
}
void destory_edge(int* arr)
{
	free(arr);
}
int UFS_findroot(int* arr, int t)//找这个集合里面的头
{
	if (arr == NULL) return -1;
	while (arr[t] >= 0)
	{
		t = arr[t];
	}
	return t;
}
bool UFS_Union(int* arr,int t1, int t2)//集合合并
{
	if (arr == NULL) return false;
	int n1 = UFS_findroot(arr, t1);
	int n2 = UFS_findroot(arr, t2);
	if (n1 == -1 || n2 == -1) return false;
	if (n1 != n2)//防止一个集合里面的合并
	{
		arr[n1] += arr[n2];
		arr[n2] = n1;
	}
	return true;
}
bool UFS_ifself(int* arr, int t1, int t2)//判断两个点是否在一个集合
{
	return UFS_findroot(arr, t1) == UFS_findroot(arr, t2);
}
int function(int** arr, int n, edge* nums, int num,int* UFS)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}
	int n1 = 0;
	int weights = 0;
	int s = 0;
	while (n1 < num)
	{
		int t1 = nums[n1].begin, t2 = nums[n1].end;
		if (!UFS_ifself(UFS,t1,t2))
		{
			UFS_Union(UFS, t1,t2);
			weights += nums[n1].Weights;
			arr[t1][t2] = nums[n1].Weights;
			arr[t2][t1] = nums[n1].Weights;
			s++;
		}
		n1++;
	}
	if (s == n - 1) return weights;
	return -1;
}
int main()
{
	FILE* file = fopen("test3.txt", "r");
	if (file == NULL) return -1;
	int n;
	fscanf(file, "%d", &n);
	int** arr=create_matrix(file,n);
	if (arr == NULL) return -1;
	int* UFS = create_UnionFindSet(n);
	if (UFS == NULL) return -1;
	edge* nums = create_edge(arr, n);
	if (arr == NULL) return -1;
	int num = edge_num(arr, n);
	int weights=function(arr, n, nums, num, UFS);
	printf("最小生成树邻接矩阵为:\n");
	print_matrix(arr, n);
	desrory_matrix(arr, n);
	printf("\n");
	printf("此时总权重为:%d",weights);
	destory_UnionFindSet(UFS);
	destory_edge(nums);
	fclose(file);
	return 0;
}