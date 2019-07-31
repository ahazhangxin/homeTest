#pragma once

#include <assert.h>

typedef void * SDataType;

#define MAX_SIZE (100)

typedef struct {
	SDataType array[MAX_SIZE];
	int top;		// 起了个别名，含义还是 size
}	Stack;

void StackInit(Stack *pS)
{
	pS->top = 0;
}

void StackDestroy(Stack *pS)
{
	pS->top = 0;
}

void StackPush(Stack *pS, SDataType data)
{
	assert(pS->top < MAX_SIZE);
	pS->array[pS->top++] = data;
}

void StackPop(Stack *pS)
{
	assert(pS->top > 0);
	pS->top--;
}

SDataType StackTop(const Stack *pS)
{
	assert(pS->top > 0);
	return pS->array[pS->top - 1];
}

int StackSize(const Stack *pS)
{
	return pS->top;
}

int StackEmpty(const Stack *pS)
{
	return pS->top == 0 ? 1 : 0;
}