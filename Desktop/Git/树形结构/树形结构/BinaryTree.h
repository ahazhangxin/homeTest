#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<assert.h>

typedef int BDataType;

typedef struct BNode{
	BDataType data;
	struct BNode *left;
	struct BNode *right;
}BNode;

static BNode* CreatNode(BDataType data)
{
	BNode *node = (BNode*)malloc(sizeof(BNode));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

typedef struct{
	BNode *root;
	int used;
}RESULT;

RESULT CreatTree(BDataType perorder[],int size)
{
	if (size == 0)
	{
		RESULT result = { NULL, 0 };
	}
	BDataType rootVelue = perorder[0];
	if (rootVelue == -1)
	{
		RESULT result = { NULL, 1 };
		return result;
	}
	
	BNode *root = CreatNode(rootVelue);

	RESULT lr = CreatTree(&perorder[1], size - 1);
	root->left = lr.root;

	RESULT rr = CreatTree(&perorder[1 + lr.used], size - 1 - lr.used);
	root->right = rr.root;

	RESULT result = { root, 1 + lr.used + rr.used };
	return result;

}

void Preorder(BNode *root)//前序输出树
{
	//终止的条件
	if (root == NULL)
	{
		return;
	}
	//根节点直接输出
	printf("%d ", root->data);
	//左子树
	Preorder(root->left);
	//右子树
	Preorder(root->right);

}

void Inorder(BNode *root)//中序输出树
{
	//终止的条件
	if (root == NULL)
	{
		return;
	}
	Inorder(root->left);//找到最左节点后开始输出
	printf("%d ", root->data);
	//右子树
	Inorder(root->right);
}

void Postorder(BNode *root)//后序输出树
{
	//终止的条件
	if (root == NULL)
	{
		return;
	}
	Postorder(root->left);//找到最左节点后开始
	Postorder(root->right);//开始找所有的右节点
	//输出根
	printf("%d ", root->data);
}

int GetSize(BNode *root)//求节点个数
{
	if (root == NULL)
	{
		return 0;
	}
	return GetSize(root->left) + GetSize(root->right) + 1;
}

int GetLeafSize(BNode *root)//求叶子节点个数
{
	if (root == NULL)
	{
		return 0;
	}
	else if (root->left==NULL && root->right==NULL)
	{ 
		return 1;
	}
	else
	{
	return GetLeafSize(root->left) + GetLeafSize(root->right);
	}
}

int GetKLeafSize(BNode *root, int k)//求第k层的叶子节点
{
	assert(k > 0);
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return GetKLeafSize(root->left, k - 1) + GetKLeafSize(root->right, k - 1);
}

#define MAX(a,b) ((a)>(b)?(a):(b))

int GetHeight(BNode *root)//求树的高度
{
	if (root == NULL){
		return 0;
	}
	int leftHeight = GetHeight(root->left);
	int rightHelght = GetHeight(root->right);
	//return MAX(GetHeight(root->left), GetHeight(root->right)) + 1;
	//注意下调用问题，不要进行多次调用
	return MAX(leftHeight, rightHelght) + 1;
}

BNode * Search(BNode *root,BDataType key)
{
	if (root == NULL){
		return NULL;
	}
	//根命中
	if (root->data == key){
		return root;
	}
	BNode * node = Search(root->left, key);
	if (node != NULL){
       return node;
	}
	node = Search(root->right, key);
	if (node != NULL){
		return node;
	}
	else{
		return NULL;
	}
}

#include"Queue.h"


void LevelOrder(BNode *root)//层序二叉树
{
	Queue queue;
	QueueInit(&queue);
	if (root == NULL)
	{
		return;
	}
	QueuePush(&queue,root);
	while (!QueueEmpty(&queue)){
		BNode *front = QueueFront(&queue);
		QueuePop(&queue);
		printf("%d ", front->data);
		if (front->left != NULL){
			QueuePush(&queue, front->left);
		}
		if (front->right != NULL){
			QueuePush(&queue, front->right);
		}
	}
	QueueDestroy(&queue);
}

int IsComplete(BNode *root)//判断二叉树是否为完全二叉树
{
	Queue queue;
	QueueInit(&queue);
	if (root == NULL)
	{
		return 1;
	}
	QueuePush(&queue, root);
	while (!QueueEmpty(&queue))
	{
		BNode *front = QueueFront(&queue);
		QueuePop(&queue);
		if (front == NULL)
		{
			break;
		}
			QueuePush(&queue, front->left);
			QueuePush(&queue, front->right);
	}
	while (!QueueEmpty(&queue))
	{
		BNode *node = QueueFront(&queue);
		QueuePop(&queue);
		if (node != NULL)
		{
			QueueDestroy(&queue);
			return 0;
		}
	}
	QueueDestroy(&queue);
	return 1;
}



#include"Stack.h"

void PreorderLoop(BNode *root)//用非递归方法实现前序遍历
{
	Stack stack;
	InitStack(&stack);
	BNode *node = root;
	BNode *top;
	while (node != NULL || !StackEmpty(&stack))
	{
		while (node != NULL)
		{
			printf("%d ", node->data);
			StackPush(&stack, node);//压栈  压的是节点地址
			node = node->left;
		}

		top = StackTop(&stack);
		StackPop(&stack);
		node = top->right;
	}
}

void InorderLoop(BNode *root)//用非递归方法实现中序遍历
{
	Stack stack;
	InitStack(&stack);
	BNode *node = root;
	BNode *top;
	while (node != NULL || !StackEmpty(&stack))
	{
		while (node != NULL)
		{
			
			StackPush(&stack, node);//压栈  压的是节点地址
			node = node->left;
		}

		top = StackTop(&stack);
		StackPop(&stack);
		printf("%d ", top->data);
		node = top->right;
	}
}

void PostorderLoop(BNode *root)//用非递归方法实现后序遍历
{
	Stack stack;
	InitStack(&stack);
	BNode *node = root;
	BNode *top;
	BNode *last = NULL;
	while (node != NULL || !StackEmpty(&stack))
	{
		while (node != NULL)
		{

			StackPush(&stack, node);//压栈  压的是节点地址
			node = node->left;
		}


		top = StackTop(&stack);
		if (top->right == NULL || top->right == last)
		{
			printf("%d ", top->data);
			last = top;
			StackPop(&stack);
		}
		else
		{
			node = top->right;
		}
	}
}

void Mirror(BNode *root)//镜像二叉树
{
	if (root == NULL)
	{
		return;
	}
	BNode *t = root->left;
	root->left = root->right;
	root->right = t;
	Mirror(root->left);
	Mirror(root->right);
}

BNode * GetNearstAncestor(BNode *root,BNode *n1,BNode *n2)//获取最近的祖先节点
{
	BNode *n1InLeft = Search(root->left, n1->data);
	BNode *n2Inleft = Search(root->left, n2->data);
	if (n1InLeft && !n2Inleft)
	{
		return root;
	}
	if (!n1InLeft && n2Inleft)
	{
		return root;
	}
	if (n1InLeft)
	{
		return GetNearstAncestor(root->left, n1, n2);
	}
	else
	{
		return GetNearstAncestor(root->right, n1, n2);
	}
}

int IsBalance1(BNode *root)//判断是否为平衡二叉树
{
	if (root == NULL)
	{
		return 1;
	}

	int isBalance = IsBalance1(root->left);
	if (isBalance == 0)
	{
		return 0;
	}
	isBalance = IsBalance1(root->right);
	if (isBalance == 0)
	{
		return 0;
	}
	int leftHeight = GetHeight(root->left);
	int rightHeight = GetHeight(root->right);
	int diff = leftHeight - rightHeight;
	if (diff<-1 || diff>1)
	{
		return 0;
	}
}

int IsBalance2(BNode *root,int *pHeight)//判断是否为平衡二叉树
{
	if (root == NULL)
	{
		*pHeight = 0;
		return 1;
	}
	int leftHeight;
	int rightHeight;
	int leftBalance = IsBalance2(root->left, leftHeight);
	int rightBalance = IsBalance2(root->right, rightHeight);
	*pHeight = MAX(leftHeight, rightHeight) + 1;
	if (leftBalance == 0 || rightBalance == 0)
	{
		return 0;
	}
	int diff = leftHeight - rightHeight;
	if (diff<-1 || diff>1)
	{
		return 0;
	}
	else
	{
		return 1;
	}	
}

void test()
{
	//BDataType perorder[] = { 1, 2, 3, -1, -1, 4, 5, -1, -1, -1, 6, 7, -1, -1, -1 };
	//int size = sizeof(perorder) / sizeof(perorder[0]);
	//RESULT result = CreatTree(perorder, size);
	//Preorder(result.root);
	//printf("\n");
	//Inorder(result.root);
	//printf("\n");
	//Postorder(result.root);
	//printf("\n");
	//BNode *root = result.root;
	//printf("结点个数: %d\n", GetSize(root));
	//printf("叶子结点个数: %d\n", GetLeafSize(root));
	//printf("第 3 层结点个数: %d\n", GetKLeafSize(root, 3));
	//printf("高度: %d\n", GetHeight(root));
	//printf("查找 D: %d\n", (Search(root, 4))->data);
	//printf("查找 E: %d\n", (Search(root, 5))->data);
	//printf("查找 H: %p\n", Search(root, 8));
	BDataType perorder[] = { 1, 2, 4, -1, -1,  5, -1, -1, 3, -1, -1 };
	int size = sizeof(perorder) / sizeof(perorder[0]);
	RESULT result = CreatTree(perorder, size);
	//Preorder(result.root);
	//printf("\n");
	//PreorderLoop(result.root);
	//printf("\n");
	//InorderLoop(result.root);
	//printf("\n");
	//PostorderLoop(result.root);
	//printf("\n");
	//BNode *root = result.root;
	//Mirror(result.root);
}