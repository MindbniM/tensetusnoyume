#include"Huffman.h"
int main()
{
	char str[] = "ABCDEF";
	int arr[] = { 22,10,50,5,1,24, };
	int size = 6;
	HTree* T = HTreeInit(str, arr, size);
	HTreePrevOrder(T);
	HTreeDestroy(T);
	return 0;
}