#pragma once
//#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
typedef char BTDataType;

class BTree
{
public:
	BTree(BTDataType data);
	// 通过前序遍历构建二叉树
	~BTree();

	friend BTree* BinaryTreeCreate(BTDataType* a, int* pi);
	friend void BinaryTreeDestroy(BTree* root);

	// 二叉树节点个数
	int BinaryTreeSize();
	// 二叉树叶子节点个数
	int BinaryTreeLeafSize();
	// 二叉树第k层节点个数
	int BinaryTreeLevelKSize(int k);
	// 二叉树查找值为x的节点
	BTree* BinaryTreeFind( BTDataType x);
	// 二叉树前序遍历 
	void BinaryTreePrevOrder();
	// 二叉树中序遍历
	void BinaryTreeInOrder();
	// 二叉树后序遍历
	void BinaryTreePostOrder();
	// 层序遍历
	void BinaryTreeLevelOrder();
	// 判断二叉树是否是完全二叉树
	bool BinaryTreeComplete();

private:
	BTDataType _data;
	BTree* _left;
	BTree* _right;
};
//二叉树创建
BTree* BinaryTreeCreate(BTDataType* a, int* pi);
// 二叉树销毁
void BinaryTreeDestroy(BTree* root);