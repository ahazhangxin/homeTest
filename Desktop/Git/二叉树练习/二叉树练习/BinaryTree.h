#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


typedef int TDataType

typedef struct BNode//树的模板
{
	TDataType data;
	struct BNode *Left;
	struct BNode *Right;
} BNode;

static BNode * PTree(TDataType data)//创建一个节点（树是由许多个相同的节点组成的一种结构体）
{
	BNode *node = (Tree*)malloc(sizeof(Tree));
	node->data = data;
	node->Left = node->Right = 0;
	return node;
}

typedef struct
{
	BNode *root;
	int used;
} RESULT;

RESULT CreateTree(TDataType preorder[],int size)//创建一个二叉树需要前序/中序？/后序？   还有多少个数组的大小
{
	//两种情况
	//数组大小等于0
	if (size == 0)
	{
		RESULT result = (NULL, 0);
		return result;
	}
	//数组大小不等于零
	//根 左子树 右子树
	//size==1
	if (size == 1)
	{
		RESULT result = (preorder[0], 1);
		return result;
	}
	//size!=1
	else
	{
		
	}

}




