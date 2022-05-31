#include"binaryTree.h"
#include"queue.h"
//typedef char BTDataType;
//
//typedef struct BinaryTreeNode
//{
//	BTDataType _data;
//	struct BinaryTreeNode* _left;
//	struct BinaryTreeNode* _right;
//}BTNode;


// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
//								��ʼ����src  ��Сn     ����i
BTNode* BinaryTreeCreate(BTDataType* src, int n, int* pi)
{
	if (src[*pi] == '#' || (*pi) >= n)
	{
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (!root)
	{
		exit(-1);
	}
	root->_data = src[*pi];
	(*pi)++;
	root->_left = BinaryTreeCreate(src, n, pi);
	root->_right = BinaryTreeCreate(src, n, pi);
	return root;
}

// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root)
	{
		BinaryTreeDestory(&(*root)->_left);
		BinaryTreeDestory(&(*root)->_right);
		free(*root);
		*root = NULL;
	}	
}

// �������ڵ���� 
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* temp = BinaryTreeFind(root->_left, x);
	if (temp)
		return temp;
	BTNode* temp2 = BinaryTreeFind(root->_right, x);
	if (temp2)
		return temp2;
	return NULL;
}

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

// �������
void BinaryTreeLevelOrder(BTNode* root)
{ 
	Q q;
	initQueue(&q);
	if (root)
	{
		enQueue(&q, root);
	}
	while (!isEmptyQueue(&q))
	{
		BTNode* front = getFrontQueue(&q);
		deQueue(&q);
		
		printf("%c ", front->_data);
		if (front->_left)
		{
			enQueue(&q, front->_left);
		}
		if (front->_right)
		{
			enQueue(&q, front->_right);
		}
	}
	destroyQueue(&q);
}
// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root)
{
	Q q;
	initQueue(&q);
	if (root)
	{
		enQueue(&q, root);
	}
	while (!isEmptyQueue(&q))
	{
		BTNode* front = getFrontQueue(&q);
		if (front == NULL)
		{
			break;
		}
		deQueue(&q);
		enQueue(&q, front->_left);
		enQueue(&q, front->_right);
	}
	while (!isEmptyQueue(&q))
	{
		BTNode* front = getFrontQueue(&q);
		deQueue(&q);
		if (front != NULL)
		{
			destroyQueue(&q);
			return false;
		}
	}
	destroyQueue(&q);
	return true;
}