#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
typedef struct Stu
{
	char name[20];
	int age;
}Stu;
void print_arr(int * arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void swap(char* i, char* j, size_t size)
{
	for (int n = 0; n < size; n++)
	{
		char a = *i;
		*i=*j;
		*j = a;
		i++, j++;
	}
}
void bubble_sort(void* arr, size_t num, size_t size, int(*comp)(const void* i, const void* j))
{
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (comp((char*)arr + j * size, (char*)arr + (j + 1) * size) > 0)
			{
				swap((char*)arr + j * size, (char*)arr + (j + 1) * size, size);
			}
		}
	}
}

int comp(const void* i, const void* j)
{
	return *(int*)j - *(int*) i;
}
int cmp_stu_age(const void* e1, const void* e2)
{
	return ((Stu*)e1)->age - ((Stu*)e2)->age;
}
int cmp_stu_name(const void* e1, const void* e2)
{
	return strcmp(((Stu*)e1)->name, ((Stu*)e2)->name);
}

int main()
{
	struct Stu arr[] = { {"zhangsan", 20}, {"lisi", 30}, {"wangwu", 15} };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_stu_name);
	return 0;
}