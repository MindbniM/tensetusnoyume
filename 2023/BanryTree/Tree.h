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
	// ͨ��ǰ���������������
	~BTree();

	friend BTree* BinaryTreeCreate(BTDataType* a, int* pi);
	friend void BinaryTreeDestroy(BTree* root);

	// �������ڵ����
	int BinaryTreeSize();
	// ������Ҷ�ӽڵ����
	int BinaryTreeLeafSize();
	// ��������k��ڵ����
	int BinaryTreeLevelKSize(int k);
	// ����������ֵΪx�Ľڵ�
	BTree* BinaryTreeFind( BTDataType x);
	// ������ǰ����� 
	void BinaryTreePrevOrder();
	// �������������
	void BinaryTreeInOrder();
	// �������������
	void BinaryTreePostOrder();
	// �������
	void BinaryTreeLevelOrder();
	// �ж϶������Ƿ�����ȫ������
	bool BinaryTreeComplete();

private:
	BTDataType _data;
	BTree* _left;
	BTree* _right;
};
//����������
BTree* BinaryTreeCreate(BTDataType* a, int* pi);
// ����������
void BinaryTreeDestroy(BTree* root);