#pragma once

#include<stdio.h>
#include<assert.h>
#include <stdlib.h>
#include<malloc.h>

#define ADD_SIZE 3

typedef int DataType;

typedef  struct SeqList
{
	DataType *p;
	int sz;
	int capacity;
}SeqList, *PSeqList;


int CheakCapcity(PSeqList Seq)//检查顺序表是否已满
{
	DataType *temp = Seq->p;
	assert(Seq);
	if (Seq->sz >= Seq->capacity)
	{
		DataType Newcapacity = Seq->capacity + 5;
		Seq->p = (DataType*)realloc(Seq->p, Newcapacity * sizeof(DataType));
		if (Seq->p == NULL)
		{
			Seq->p = temp;
			printf("扩容失败\n");
			return -1;
		}
		else
		{
			Seq->capacity = Newcapacity;
		}
	}
	return 1;
}

void InitSeqList(PSeqList pSeqList)//初始化顺序表
{
	pSeqList->sz = 0;
	pSeqList->capacity = 5;
	pSeqList->p = (DataType *)malloc(pSeqList->capacity * sizeof(DataType));
	if (NULL == pSeqList->p)
	{
		printf("初始化顺序表失败");
	}
}


void PushFront(PSeqList Seq,DataType data)//头插
{
	int i = 0;
	int ret = 0;
	assert(Seq);
	ret = CheakCapcity(Seq);
	if (1 == ret)
	{
		for (i = Seq->sz; i > 0; i--)
		{
			Seq->p[i] = Seq->p[i - 1];

		}
		Seq->p[0] = data;
		Seq->sz++;
	}

}

void PopFront(PSeqList Seq)//头删
{
	if (Seq == NULL)
	{
		printf("已空\n");
		return;
	}
	else
	{
		for (int i = 0; i < Seq->sz - 1; i++)
		{
			Seq->p[i] = Seq->p[i + 1];
		}
	}
	Seq->sz--;
}

void PushBack(PSeqList Seq,DataType data)//尾插
{
	int ret = 0;
	assert(Seq);
	ret = CheakCapcity(Seq);
	if (1 == ret)
	{
		Seq->p[Seq->sz] = data;
		Seq->sz++;
	}
}

void PopBack(PSeqList Seq)//尾删
{
	assert(Seq);
	if (Seq->p == NULL)
	{
		printf("已空\n");
		return;
	}
	else
		Seq->sz--;
}

int Search(PSeqList Seq,DataType data)//查找顺序表中第一个元素data，并返回位置
{
	assert(Seq);
	for (int i = 0; i < Seq->sz; i++)
	{
		if (Seq->p[i] == data)
		{
			printf("在顺序表中的第%d个\n", i+1);
			return i + 1;
		}
	}
	return -1;
}

void Insert(PSeqList Seq, int pos, DataType data)//插入在pos位置
{
	assert(Seq);
	int ret = CheakCapcity(Seq);
	for (int i = Seq->sz; i >= pos; i--)
	{
		Seq->p[i + 1] = Seq->p[i];
	}
	Seq->p[pos] = data;
	Seq->sz++;
}


void Erase(PSeqList Seq, int pos)//删除在pos位置
{
	assert(Seq);
	for (int i = pos; i < Seq->sz; i++)
	{
		Seq->p[i] = Seq->p[i + 1];
	}
	Seq->sz--;
}

void Remove(PSeqList Seq, DataType data)//删除顺序表中的第一个data元素
{
	assert(Seq);
	Erase(Seq, Search(Seq, data));
	printf("删除成功\n");
}

void RmeoveAll(PSeqList Seq, DataType data)//删除顺序表中所有的data元素
{
	assert(Seq);
	int j = Seq->sz;
	for (int i = 0; i < j; i++)
	{
		if (Seq->p[i] == data)
		{
			Remove(Seq, data);
			i--;
			j--;
		}
	}
	printf("删除成功\n");
}

void Swap(size_t *num1,size_t *num2)
{
	DataType tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void BorbbleSort(PSeqList Seq)//冒泡排序
{
	size_t i = 0;
	size_t j = 0;
	assert(Seq);
		for (i = 0; i < ((Seq->sz) - 1); i++)
		{
			for (j = 0; j < ((Seq->sz) - 1); j++)
			{

				if (Seq->p[j]>Seq->p[j + 1])
				{
					Swap(&Seq->p[j + 1], &Seq->p[j + 1]);
				}
			}
		}
}

void SelectSort(PSeqList Seq)//快速排序
{
	size_t left = 0;
	size_t i = 0;
	size_t num = 0;
	size_t min = 0;
	size_t max = 0;
	assert(Seq);
	for (left = 0; left < (Seq->sz/2+1); left++)
	{
		for (i = left; i < Seq->sz - left;i++)
		{
			min = Seq->p[i] > Seq->p[min] ? min : i;
			max = Seq->p[i] < Seq->p[max] ? max : i;
		}
		Swap(&Seq->p[left], &Seq->p[min]);
		Swap(&Seq->p[Seq->sz - left], &Seq->p[max]);
		min += 1;
		max += 1;
	}
}

void PrintSeqList(PSeqList Seq)//打印
{
	assert(Seq);
	for (int i = 0;i < (Seq->sz); i++)
	{
		printf("%d  ", Seq->p[i]);
	}
	printf("\n");
}


void DestroyList(PSeqList Seq)
{
	assert(Seq);
	Seq->sz = 0;
	Seq->capacity = 0;
	free(Seq->p);
}

void test()
{
	SeqList seqList;
	InitSeqList(&seqList);
	printf("顺序表：");
	PushBack(&seqList, 1);
	PushBack(&seqList, 4);
	PushBack(&seqList, 7);
	PushBack(&seqList, 8);
	PushBack(&seqList, 5);
	PushBack(&seqList, 2);
	PushBack(&seqList, 3);
	PushBack(&seqList, 6);
	PushBack(&seqList, 9);
	SelectSort(&seqList);
	PrintSeqList(&seqList);
}