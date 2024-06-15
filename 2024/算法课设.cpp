#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<iostream>
#include<fstream>
#include<limits.h>
#include<vector>
#include<string>
#include<map>


int n;
std::vector<std::vector<int>> matrix;
std::vector<int> weights;
std::vector<int> parent;
int begin;
int end;
std::map<int,std::string> hash;


void create_matrix()
{
	std::fstream in;
	in.open("test.txt", std::ios::in);
	in >> n;
	for (int i = 0; i < n; i++)
	{
		std::string str;
		in >> str;
		hash[i] = str;
		std::cout << str << ":" << i << std::endl;
	}
	matrix.resize(n,std::vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			in >> matrix[i][j];
		}
	}
	in.close();
}
void print_matrix()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%-5d", matrix[i][j]);
		}
		std::cout << std::endl;
	}
}


void Dijkstra()
{
	weights.resize(n, INT_MAX);
	weights[begin] = 0;
	parent.resize(n, -1);
	std::vector<bool> vb(n, false);
	for (int i = 0; i < n; i++)
	{
		int w = INT_MAX;
		int d = 0;
		for (int j = 0; j < n; j++)
		{
			if (vb[j] == false && weights[j] < w)
			{
				w = weights[j];
				d = j;
			}
		}
		vb[d] = true;
		for (int k = 0; k < n; k++)
		{
			if (vb[k] == false &&  matrix[d][k] != 0 && weights[d] +  matrix[d][k] < weights[k])
			{
				weights[k] = weights[d] +  matrix[d][k];
				parent[k] = d;
			}
		}
	}
}
void print()
{
	std::string str;
	int endi = end;
	while (endi != -1)
	{
		str.insert(0,hash[endi]);
		endi = parent[endi];
		if (endi != -1)
			str.insert(0,"-->");
	}
	printf("最短路径为:\n");
	std::cout << "\t" << str << std::endl;
	std::cout << "\t总距离为" << weights[end] << std::endl;
}
int main()
{
	create_matrix();
	std::cout << "输入起点和终点" << std::endl;
	std::cin >> begin >> end;
	//print_matrix();
	Dijkstra();
	print();
	return 0;
}
