#pragma once
#include<Windows.h>
#include<assert.h>
//对于栈我们可以用顺序表和链表来实现，栈的代码并不难，在此处，为了省事，直接用顺序表来表示

typedef void* SDataType;

#define MAX_SIZE (100)


typedef struct{
	SDataType array[MAX_SIZE];
	int top;
} Stack;

void InitStack(Stack *pS)//初始化栈
{
	pS->top = 0;
}

void StackPush(Stack *pS, SDataType data)//压栈
{
	assert(pS->top < MAX_SIZE);
	pS->array[pS->top] = data;
	pS->top++;
}

void StackPop(Stack *pS)//出栈,栈中只有一个出栈的方向
{
	pS->top--;
}

void StackDestroy(Stack *pS)//销毁栈
{
	pS->top = 0;
}

SDataType StackTop(const Stack *pS)//返回栈顶元素
{
	assert(pS->top > 0);
	return pS->array[pS->top - 1];
}

int StackSize(const Stack *pS)//返回栈元素的数量
{
	return pS->top;
}

int StackEmpty(const Stack *pS)//判断栈是否为空
{
	return pS->top == 0 ? 1 : 0;
}
