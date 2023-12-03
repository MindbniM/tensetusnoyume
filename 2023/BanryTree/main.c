#include"Tree.h"
void test1()
{
	char a[] = "12##3##45###";
	int size = 0;
	BTNode* T = BinaryTreeCreate(a, &size);
	printf("%d\n", BinaryTreeLeafSize(T));
	printf("%d\n", BinaryTreeLevelKSize(T, 3));
	printf("%d\n", BinaryTreeSize(T));
	printf("%p\n", BinaryTreeFind(T, 5));
	BinaryTreePrevOrder(T);
	printf("\n");
	BinaryTreeInOrder(T);
	printf("\n");
	BinaryTreePostOrder(T);
	printf("\n");
	BinaryTreeLevelOrder(T);
	printf("\n");
	printf("%d", BinaryTreeComplete(T));
	BinaryTreeDestroy(&T);
}
int main()
{
	test1();
	return 0;
}