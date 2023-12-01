#include"Tree.h"
BTNode* BuyTreeNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	assert(node);

	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}
void BinaryTreeDestroy(BTNode** root)
{
	if (*root == NULL);
		return;
	BinaryTreeDestroy(&(*root)->left);
	BinaryTreeDestroy(&(*root)->right);
	free(*root);
	*root = NULL;
}
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	BTNode* T1 = BinaryTreeFind(root->left, x);
	BTNode* T2 = BinaryTreeFind(root->right, x);
	if (T1 != NULL)
		return T1;
	if (T2 != NULL)
		return T2;
	return NULL;
}
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* newNode = BuyTreeNode(a[*pi]);
	(*pi)++;
	newNode->left = BinaryTreeCreate(a, pi);
	newNode->right = BinaryTreeCreate(a, pi);
	return newNode;
}
