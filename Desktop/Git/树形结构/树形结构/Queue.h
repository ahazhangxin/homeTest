#pragma once
#include<assert.h>
#include<stdlib.h>
//用链表实现队列

typedef int BDataType;

typedef struct QNode{//创建队列的一个节点
	BDataType data;
	struct BNode *next;
}QNode;

typedef struct Queue{
	QNode *front;
	QNode *rear;
	int size;
}Queue;

void QueueInit(Queue *pQ)//队列的初始化
{
	assert(pQ != NULL);
	pQ->front = pQ->rear = NULL;
	pQ->size = 0;
}

void QueueDestroy(Queue *pQ)//销毁队列
{
	assert(pQ);
	QNode *del, *next;
	for (del = pQ->front; del != NULL; del = next)
	{
		next = del->next;
		free(del);
	}
	pQ->front = pQ->rear = NULL;
	pQ->size = 0;
}

void QueuePush(Queue *pQ, BDataType data)//插入元素
{
	pQ->size++;
	QNode *node = (QNode*)malloc(sizeof(QNode));
	node->next = NULL;
	node->data -= data;
	if (pQ->front == NULL)
	{
		pQ->front = pQ->rear = node;
		return;
	}
	pQ->rear->next = node;
	pQ->rear = NULL;
}

void QueuePop(Queue *pQ)//删除元素，因为队列遵循先进先出，后进后出，所以删除也就是头删
{
	pQ->size--;
	assert(pQ != NULL);
	assert(pQ->front != NULL);
	if (pQ->front == pQ->rear)
	{
		free(pQ->front);
		pQ->front = pQ->rear = NULL;
	}
	QNode *cur = pQ->front;
	pQ->front = pQ->front->next;
	free(cur);

}

BDataType QueueFront(const Queue *pQ)//返回头元素
{
	assert(pQ != NULL);
	assert(pQ->front != NULL);

	return pQ->front->data;
}

int QueueEmpty(const Queue *pQ)//判断队列是否为空
{
	assert(pQ != NULL);
	return pQ->front == NULL ? 1 : 0;
}

int QueueSize(const Queue *pQ)//返回队列的大小
{
	assert(pQ != NULL);
	//两种方法 
	//一种是对队列遍历，加个计数器
	//其二是用用空间换取时间的方法 在Queue的定义加一个size
	return pQ->size;
}