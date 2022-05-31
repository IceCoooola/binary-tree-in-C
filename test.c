#include"binaryTree.h"

int main()
{
	char arr[18] = "ABD##E#H##CF##G##";
	printf("binary tree create: %s (# will be translate as NULL)\n", arr);
	int i = 0;
	BTNode* newNode = BinaryTreeCreate(arr, 18, &i);
	printf("Prev order:\n");
	BinaryTreePrevOrder(newNode);
	printf("\n");
	printf("In order:\n");
	BinaryTreeInOrder(newNode);
	printf("\n");
	printf("Post order:\n");
	BinaryTreePostOrder(newNode);
	printf("\n");
	printf("Tree size:\n");
	printf("%d\n", BinaryTreeSize(newNode));
	printf("Leaf size:\n");
	printf("%d\n", BinaryTreeLeafSize(newNode));
	printf("4th level size\n");
	printf("%d\n", BinaryTreeLevelKSize(newNode, 3));
	printf("%p\n", BinaryTreeFind(newNode, 'E'));
	printf("level order:\n");
	BinaryTreeLevelOrder(newNode);
	printf("binary tree complete: \n%d\n",BinaryTreeComplete(newNode));
	BinaryTreeDestory(&newNode);
	return 0;
}