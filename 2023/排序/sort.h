#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdbool.h>


void Prin(int* a, int n);

void InsertSort(int* a, int n);//插入排序

void ShellSort(int* a, int n);//希尔排序

void SelectSort(int* a, int n);//选择排序

void HeapSort(int* a, int n);//堆排序

void BubbleSort(int* a, int n);

void QuickSort(int* a, int begin, int end);//快排

void QuickNonRSort(int* a, int begin, int end);//快排非递归

void QSort(int* a, int begin, int end);//快排优化

void MergeSort(int* a, int n);//归并排序

void MergeNonRSort(int* a, int n);//归并非递归

void CountSort(int* a, int n);//计数排序
