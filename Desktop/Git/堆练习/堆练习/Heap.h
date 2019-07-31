#pragma once
#include<stdio.h>
/*
array 数组 size 大小
root 是开始调整的下标

*/

void Swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void AdjustDown(int array[], int size, int root)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	while (1)
	{
		if (left >= size)
		{
			//[root]是叶子
			return;
		}

		int max = left;
		if (right<size && array[right] > array[left])
		{
			max = right;
		}
		if (array[root] >= array[max])
		{
			return;
		}
		Swap(&array[root], &array[max]);
	root = max;
   }
}

void AdjustUp(int array[], int size, int child)
{
	while (child  >0)
	{
		int parent = (child - 1) / 2;
		if (array[parent] >= array[child])
		{
			return;
		}
		Swap(&array[parent], &array[child]);
		child = parent;
	}
}

void CreateHeap(int array[], int size)
{
	for (int i = ((size - 2) / 2); i > 0; i--)
	{
		AdjustDown(array, size, i);
	}
}

void print(int array[])
{
	for (int i = 0; i < 9; i++)
	{
		printf("%d", array + i);
	}
}

void test()
{
	int array[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	CreateHeap(array, 9);
	print(array);
   
}

//typedef struct Heap
//{
//
//};
//



//void HeapPush(Heap *pH, int data)
//{
//	assert(pH->)
//}