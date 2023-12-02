#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef struct HuffmanTree 
{
	char value;
	int weight;
	struct HuffmanTree* left;
	struct HuffmanTree* right;
}HTree;

HTree* HTreeInit(char* value,int* weight,int size);

void HTreeDestroy(HTree* h);

void HTreePrevOrder(HTree* root);


