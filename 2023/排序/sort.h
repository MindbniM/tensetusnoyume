#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdbool.h>


void Prin(int* a, int n);

void InsertSort(int* a, int n);//��������

void ShellSort(int* a, int n);//ϣ������

void SelectSort(int* a, int n);//ѡ������

void HeapSort(int* a, int n);//������

void BubbleSort(int* a, int n);

void QuickSort(int* a, int begin, int end);//����

void QuickNonRSort(int* a, int begin, int end);//���ŷǵݹ�

void QSort(int* a, int begin, int end);//�����Ż�

void MergeSort(int* a, int n);//�鲢����

void MergeNonRSort(int* a, int n);//�鲢�ǵݹ�

void CountSort(int* a, int n);//��������
