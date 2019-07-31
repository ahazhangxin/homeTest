#pragma once
#include<stdio.h>
#include<Windows.h>


void InsertSort(int array[],int size)//c/插入排序
{
	int key;
	int i, j;
	for (i = 1; i < size; i++)
	{
		key = array[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (key >= array[j])
			{
				break;
			}
			else
			{
				array[j + 1] = array[j];
			}
		}
		array[j+1] = key;
	}
}


//void ShellSort(int Array[],int size)
//{
//	int gap = size;
//	while (1)
//	{
//		gap = gap / 3 + 1;
//		_InsertSort()
//	}
//}
void Swap( int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


void SelectSort(int array[], int size)//选择排序
{
	int left = 0;
	int right = size - 1;
	int min;
	int max;
	while (left>right)
	{
		for (int i = 0; i < size ;i++)
		{
		if (array[i] < array[left])
			{
				min = i;
			}
			if (array[i]>array[right])
			{
				max = i;
			}
		}
		Swap(&array[min], &array[left]);
		if (max == left)
		{
			max = min;
		}
		Swap(&array[max], &array[right]);
		left++;
		right--;
	}
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

void CreatHeap(int array[], int size)
{
	for (int i = ((size - 2) / 2); i >= 0; i--)
	{
		AdjustDown(array, size, i);
	}
}

void HeapSort(int array[], int size)
{
	CreatHeap(array, size);

	for (int i = 0; i < size; i++)
	{
		Swap(&array[0], &array[size - 1 - i]);
		AdjustDown(array, size, ((size - 2) / 2));
	}
}
void _QuickSort(int array[], int size, int left)
{
	int div = Partition(array, left, right);
	_QuickSort(array, left, div - 1);
	_QuickSort(array, div+1, right);
}


void QuickSort(int array[], int size)
{
	_QuickSort(array, size, 0);
}

void PrintArray(int array[],int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}




void test()
{
	int Array[] = { 4, 8, 7, 5, 8, 2, 7, 9, 2, 4 };
	int size = (sizeof(Array)) / sizeof(Array[0]);

	HeapSort(Array, size);
	PrintArray(Array,size);
}