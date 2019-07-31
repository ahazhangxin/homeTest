#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DataType;

typedef struct LinkList
{
	DataType data;
	struct LinkList * next;
}LinkList, *PLinkList;

PLinkList initLink()//初始化链表  一个有头节点的链表
{
	LinkList* p = (LinkList*)malloc(sizeof(LinkList));//创建一个头结点
	p->data = 0;//表示链表中的元素个数
	p->next = NULL;
	return p;
}

PLinkList CreateLink(PLinkList Link)//创建一个新节点
{
	PLinkList a = (PLinkList)malloc(sizeof(LinkList));
		a->next = NULL;
		a->data = 0;
		Link->data += 1;
		return a;
}

void LPushFront(PLinkList Link,DataType data)//头插
{
		PLinkList a = CreateLink(Link);
		a->next = Link->next;
		a->data = data;
		Link->next = a;
}



void LPushBack(PLinkList Link, DataType data)//尾插
{
	assert(Link);
	PLinkList cur = Link;
	PLinkList a = CreateLink(Link);
	a->data = data;
	a->next = NULL;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = a;
}



void LPopFront(PLinkList Link)//头删
{
	if (Link->next == NULL)
	{
		printf("链表已空\n");
		return;
	}
	else
	{
		PLinkList del = Link->next;
		Link->next = Link->next->next;
		Link->data -= 1;
		free(del);
		del = NULL;
	}
}

void LPopBack(PLinkList Link)//尾删
{
	PLinkList del = Link;
	if (del->next == NULL)
	{
		return;
	}
	else
	{
		while (del->next->next!=NULL)
		{
			del = del->next;
		}
		free(del->next->next);
		del->next = NULL;
	}

}



int SelectLinkList(PLinkList Link,DataType data)//查找某元素并返回其在链表中的位置
{
	int i = 0;
	for (PLinkList cur = Link; cur->next != NULL; cur = cur->next)
	{
		if (cur->data == data)
		{
			return i;
		}
		i += 1;
	}
	return -1;
}

void PInsertLinkList(PLinkList Link, int pos, DataType data)//插入在链表中
{
	PLinkList cur = Link;
	while (pos-1)
	{
		cur = cur->next;
		pos--;
	}
	PLinkList Ins = CreateLink(Link);
	Ins->next = cur->next->next;
	cur->next = Ins;
	Ins->data = data;
}

void PDelLinkList(PLinkList Link, int pos)//删除链表中的节点
{
	PLinkList del = Link;
	PLinkList tmp = Link;
	while (pos)
	{
		tmp = del;
		del = del->next;
		pos--;
	}
	tmp->next = del->next;
	free(del);
	del = NULL;
	Link->data -= 1;
}

void PRINTF(PLinkList Link)//输出链表
{
	PLinkList cur = Link;
	while (cur->next != NULL)
	{
		cur = cur->next;
		printf("%d-->", cur->data);
	}
	printf("NULL", cur->data);
}

void test()
{
	PLinkList p = initLink();
	LPushFront(p, 5);
	LPushFront(p, 4);
	LPushFront(p, 3);
	LPushFront(p, 2);
	LPushFront(p, 1);
	LPopFront(p);
	LPushBack(p, 6);
	LPopBack(p);
	PInsertLinkList(p, 2, 10);
	PDelLinkList(p, 3);
	PRINTF(p);
}
