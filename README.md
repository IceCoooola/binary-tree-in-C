# binary-tree-in-C

This project include following functions. 
# binary-tree-in-C

This project includes the following functions. 


## BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
create a binary tree by using prev order. # will seen as a NULL character. 
will test by string "ABD##E#H##CF##G##" in test.c.

## void BinaryTreeDestory(BTNode** root);
destroy the binary tree.

## int BinaryTreeSize(BTNode* root);
calculate binary tree node size. 

## int BinaryTreeLeafSize(BTNode* root);
calculate binary tree leaf size.
 
## int BinaryTreeLevelKSize(BTNode* root, int k);
calculate how many node are in K level. 

## BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
 Finds the node with the value x. return to the address of it. 

## void BinaryTreePrevOrder(BTNode* root);
prev order print binary tree. 

## void BinaryTreeInOrder(BTNode* root);
in order print binary tree. 

## void BinaryTreePostOrder(BTNode* root);
post order print binary tree. 

## void BinaryTreeLevelOrder(BTNode* root);
level order print binary tree. 

## bool BinaryTreeComplete(BTNode* root);
check if the binary tree is complete binary tree. 
