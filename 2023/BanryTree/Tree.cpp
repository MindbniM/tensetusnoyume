#include"Tree.h"
BTree::BTree(BTDataType data)
	:_data(data)
	,_left(NULL)
	,_right(NULL)
{

}
BTree::~BTree()
{
	_left = NULL;
	_right = NULL;
}
void BinaryTreeDestroy(BTree* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestroy(root->_left);
	BinaryTreeDestroy(root->_right);
	delete(root);
}
BTree* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTree* newNode = new BTree(a[*pi]);
	(*pi)++;
	newNode->_left = BinaryTreeCreate(a, pi);
	newNode->_right = BinaryTreeCreate(a, pi);
	return newNode;
}
int BTree::BinaryTreeSize()
{
	return this == NULL ? 0 : this->_left->BinaryTreeSize() + this->_right->BinaryTreeSize() + 1;
}

int BTree::BinaryTreeLeafSize()
{
	if (this == NULL)
		return 0;
	if (this->_left == NULL && this->_right == NULL)
		return 1;
	return this->_left->BinaryTreeLeafSize() + this->_right->BinaryTreeLeafSize();
}
int BTree::BinaryTreeLevelKSize(int k)
{
	if (this == NULL)
		return 0;
	if (k == 1)
		return 1;
	return this->_left->BinaryTreeLevelKSize(k - 1) + this->_right->BinaryTreeLevelKSize(k - 1);
}
BTree* BTree::BinaryTreeFind( BTDataType x)
{
	if (this == NULL)
		return NULL;
	if (this->_data == x)
		return this;
	BTree* T1 = this->_left->BinaryTreeFind( x);
	BTree* T2 = this->_right->BinaryTreeFind( x);
	if (T1 != NULL)
		return T1;
	if (T2 != NULL)
		return T2;
	return NULL;
}
void BTree::BinaryTreePrevOrder()
{
	if (this == NULL)
		return;
	printf("%c ", this->_data);
	this->_left->BinaryTreePrevOrder();
	this->_right->BinaryTreePrevOrder();
}

void BTree::BinaryTreeInOrder()
{
	if (this == NULL)
		return;
	this->_left->BinaryTreePrevOrder();
	printf("%c ", this->_data);
	this->_right->BinaryTreePrevOrder();
}

void BTree::BinaryTreePostOrder()
{

	if (this == NULL)
		return;
	this->_left->BinaryTreePrevOrder();
	this->_right->BinaryTreePrevOrder();
	printf("%c ", this->_data);
}
void BTree::BinaryTreeLevelOrder()
{
	std::queue<BTree*> q;
	q.push(this);
	int size = 1;
	while (!q.empty())
	{
		while (size--)
		{
			BTree* front = q.front();
			q.pop();
			if (front->_left != NULL)
				q.push(front->_left);
			if (front->_right != NULL)
				q.push(front->_right);
			printf("%c ", front->_data);
		}
		size = q.size();
		printf("\n");
	}
}
bool BTree::BinaryTreeComplete()
{

	std::queue<BTree*> q;
	q.push(this);
	while (!q.empty())
	{
		BTree* front = q.front();
		q.pop();
		if (front == NULL)
			break;
		q.push(front->_left);
		q.push(front->_right);
	}
	while (!q.empty())
	{
		BTree* front = q.front();
		q.pop();
		if (front != NULL)
		{
			return 0;
		}
	}
	return 1;
}
