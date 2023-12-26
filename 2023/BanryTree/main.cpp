#include"Tree.h"
void test1()
{
	char a[] = "12##3##";
	int size = 0;
	BTree* T = BinaryTreeCreate(a, &size);
	printf("%d\n", T->TreeHeight());
	//printf("%d\n", T->BinaryTreeLeafSize());
	//printf("%d\n", T->BinaryTreeLevelKSize( 3));
	//printf("%d\n", T->BinaryTreeSize());
	//printf("%p\n", T->BinaryTreeFind( 5));
	//T->BinaryTreePrevOrder();
	//printf("\n");
	//T->BinaryTreeInOrder();
	//printf("\n");
	//T->BinaryNTreeInOrder();
	//printf("\n");
	//T->BinaryTreePostOrder();
	//printf("\n");
	//T->BinaryTreeLevelOrder();
	//printf("\n");
	//printf("%d", T->BinaryTreeComplete());
	BinaryTreeDestroy(T);
}
int main()
{
	test1();
	return 0;
}