#pragma once
#include<assert.h>
#include<stdlib.h>

typedef int DataType;


//一个双向链表的节点
typedef struct DLinkList{
	struct DLinkList *prior;
	DataType data;
	struct DLinkList *next;
} DLinkList , *PDLinkList;

//创建双向链表的头节点
//头节点需要 双向链表一个元素的地址 对于带头节点的双向链表而言 头节点就是首元素 头节点不能被删除

//typedef struct Head{
//	struct DLinkList *LinkList;
//	DataType num;
//};

//头节点不可改变  指向可为NULL

PDLinkList CreatDLinkList(DataType data)//创建新结点
{	
	PDLinkList newnode = (PDLinkList)malloc(sizeof(DLinkList));
	if (NULL == newnode)
	{
		return NULL;
	}
	newnode->data = data;
	newnode->next = NULL;
	newnode->prior = NULL;
	return newnode;
}

void InitDLinkList(PDLinkList pHead)//初始化
{
	assert(pHead);
	if (NULL == pHead)
	{
		return;
	}
	pHead->next = pHead;
	pHead->prior = pHead;
}



void PushHead(PDLinkList pHead,DataType data)//头插
{
	assert(pHead);
	PDLinkList p = CreatDLinkList(data);
	p->next = pHead->next;
	p->prior = pHead;
	pHead->next->prior = p;
	pHead->next = p;
	pHead->data += 1;
}

void PopHead(PDLinkList pHead)//头删
{
	assert(pHead);
	if (pHead->data == 1)
	{
		free(pHead->next);
		pHead->next = NULL;
		pHead->prior = NULL;
		pHead->data -= 1;
		return;
	}
	pHead->next = pHead->next->next;
	free(pHead->next->prior);
	pHead->next->prior = pHead;
	pHead->data -= 1;
}

void PushBack(PDLinkList pHead，DataType data)  //尾插
{
    

}


//

void test()
{
	PDLinkList p = CreatDLinkList(0);
	InitDLinkList(p);
	PushHead(p, 1);
	PushHead(p, 2);
	PushHead(p, 3);
	PushHead(p, 4);
	PushHead(p, 5);

}


