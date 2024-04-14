#include"Huffman.h"
int cmp(const void* a, const void* b)
{
	return ((HTree*)a)->weight - ((HTree*)b)->weight;
}
HTree* BuyTreeNode(char value,int weight)
{
	HTree* node = (HTree*)malloc(sizeof(HTree));
	assert(node);

	node->value = value;
	node->weight = weight;
	node->left = NULL;
	node->right = NULL;

	return node;
}
HTree* HTreeInit(char* value, int* weight, int size)
{
	HTree* HT = (HTree*)malloc(size * sizeof(HTree));
	assert(HT);
	for (int i = 0; i < size; i++)
	{
		HT[i].value = value[i];
		HT[i].weight = weight[i];
		HT[i].left = NULL;
		HT[i].right = NULL;
	}
	qsort(HT, size, sizeof(HTree), cmp);
	HTree* newNode= BuyTreeNode(HT[0].value, HT[0].weight);;
	while (size > 1)
	{
		HTree* T1 = newNode;
		HTree* T2 = BuyTreeNode(HT[1].value, HT[1].weight);
		newNode = (HTree*)malloc(sizeof(HTree));
		newNode->weight = T1->weight + T2->weight;
		newNode->value = '\0';
		newNode->left = T1;
		newNode->right = T2;
		HT[0] = *newNode;
		for (int i = 1; i < size-1; i++)
			HT[i] = HT[i + 1];
		//qsort(HT, size - 1, sizeof(HTree), cmp);
		size--;
	}
	free(HT);
	return newNode;
}
void HTreePrevOrder(HTree* root)
{
	if (root == NULL)
	{
		//printf("N ");
		return;
	}
	printf("%d ", root->weight);
	HTreePrevOrder(root->left);
	HTreePrevOrder(root->right);
}
void HTreeDestroy(HTree* h)
{
	if (h == NULL)
		return;
	HTreeDestroy(h->left);
	HTreeDestroy(h->right);
	free(h);
}