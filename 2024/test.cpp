#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	FILE* r=fopen("111.txt", "r");
	FILE* w = fopen("data.txt", "w");
	double n ;
	for (n = -3; n <= 3; n += 0.5)
	{
		char arr[10] = { 0 };
		char arr1[10] = { 0 };
		char arr2[10] = { 0 };
		fscanf(r, "%s", arr);
		fscanf(r, "%s", arr1);
		fscanf(r, "%s", arr2);
		fprintf(w, "%.1llf       %s       %s       %s\n", n, arr,arr1,arr2);
	}
	for (n = 5; n <= 29; n += 2)
	{
		char arr[10] = { 0 };
		char arr1[10] = { 0 };
		char arr2[10] = { 0 };
		fscanf(r, "%s", arr);
		fscanf(r, "%s", arr1);
		fscanf(r, "%s", arr2);
		fprintf(w, "%.1llf       %s       %s       %s\n", n, arr,arr1,arr2);
	}
	n = 30;
	char arr[10] = { 0 };
	char arr1[10] = { 0 };
	char arr2[10] = { 0 };
	fscanf(r, "%s", arr);
	fscanf(r, "%s", arr1);
	fscanf(r, "%s", arr2);
	fprintf(w, "%.1llf       %s       %s       %s\n", n, arr,arr1,arr2);
	fclose(r);
	fclose(w);
	return 0;
}