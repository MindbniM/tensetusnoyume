#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	FILE* r=fopen("111.txt", "r");
	FILE* w = fopen("data.txt", "w");
	double n = 10;
	for (n = 10; n <= 80; n += 0.4)
	{
		char arr[10] = { 0 };
		fscanf(r, "%s", arr);
		fprintf(w, "%.1llf    %s\n", n, arr);
	}
	fclose(r);
	fclose(w);
	return 0;
}