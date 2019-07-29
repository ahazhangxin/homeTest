#include<iostream>
using namespace std;


void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

//冒泡排序
//稳定性	稳定
//时间复杂度	最好O(n)	最差O(n2)
//空间复杂度	O(1)
void BubbleSort(int array[],int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int t = 0;
		for (int j = 0; j < size - 1 - i; j++){

			
			if (array[j] > array[j + 1])
			{
				Swap(&array[j], &array[j + 1]);
				t = 1;
			}
		}
		if (t == 0)
		{
			break;
		}
	}
}


//选择排序
//稳定性	不稳定
//时间复杂度	O(n2)
//空间复杂度	O(1)
void SelectSort(int array[], int size)
{
	for (int i = 0; i <= size/2 + 1; i++)
	{
		int min = i;
		int max = i;
		for (int j = i + 1; j <= size - 1 - i; j++)
		{
			if (array[min] > array[j])
			{
				min = j;
			}
			if (array[max] < array[j])
			{
				max = j;
			}
		}
		Swap(&array[min], &array[i]);
		if (max == i)
			max = min;
		Swap(&array[max], &array[size - i - 1]);
		
	}
}

//插入排序	
//稳定性	稳定
//时间复杂度	O(n2)
//空间复杂度		O(1)
void InsertSort(int array[], int size)
{
	int temp = array[0];
	int j;
	for (int i = 0; i < size; i++)
	{
		j = i;
		while (j--)
		{
			if (array[j]>array[j + 1])
			{
				Swap(&array[j], &array[j + 1]);
			}
		}
	}
}


//归并排序
//稳定性	稳定
//时间复杂度	O(n*logN)
//空间复杂度	O(n)

void Merge(int array[], int left, int mid, int right, int extra[])
{
	//合并过程
	int left_i = left;	//[left , mid)
	int right_i = mid;	//[mid , right)
	int extra_i = left;
	while (left_i < mid && right_i < right)
	{
		if (array[left_i] <= array[right_i])
		{
			extra[extra_i++] = array[left_i++];
		}
		else
		{
			extra[extra_i++] = array[right_i++];
		}
	}

	while (left_i < mid) {
		extra[extra_i++] = array[left_i++];
	}

	while (right_i < right) {
		extra[extra_i++] = array[right_i++];
	}

	for (int i = left; i < right; i++) {
		array[i] = extra[i];
	}


}

void _MergeSort(int array[],int left,int right,int extra[])
{
	//拆分过程
	int mid = left + (right - left) / 2;
	
	
	if (left >= right)
		return;
	if (left == right - 1)
		return;
	
	_MergeSort(array, left, mid, extra);
	_MergeSort(array, mid, right, extra);
	Merge(array, left, mid, right, extra);


}

//归并排序递归写法
void MergeSort(int *array, int size)
{
	int* extra = (int *)malloc(sizeof(int)* size);
	_MergeSort(array,0,size,extra);
	free(extra);
}

//归并排序非递归写法
void MergeSortLoop(int array[], int size)
{
	int *extra = (int *)malloc(sizeof(int)* size);
	for (int i = 1; i < size; i *= 2) {	// 一共循环 log(size)
		for (int j = 0; j < size; j = j + 2 * i) {
			int left = j;
			int mid = j + i;
			int right = mid + i;

			if (mid >= size) {
				continue;
			}

			if (right > size) {
				right = size;
			}

			Merge(array, left, mid, right, extra);
		}
	}
	free(extra);
}

int Partition_01(int *array, int left, int right)
{
	int begin = left;
	int end = right;
	while (begin < end)
	{
		//begin<end
		while (begin < end && array[begin] <= array[right])
		{
			begin++;
		}

		while (begin < end && array[end] >= array[right])
		{
			end--;
		}


		Swap(&array[begin], &array[end]);
	}

	Swap(&array[begin], &array[right]);
	return begin;
}



void _QuickSort(int *array, int left, int right)
{
	if (left > right)
	{
		return;
	}

	if (left == right)
	{
		return;
	}
	int div = Partition_01(array, left, right);
	_QuickSort(array, left, div - 1);
	_QuickSort(array, div + 1, right);
}

void QuickSort(int array[], int size)
{
	_QuickSort(array, 0, size - 1);
}


//打印数组
void Printf(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << array[i];
	}
	cout << endl;
}

void Test()
{
	int array[] = { 3, 5, 1, 4, 7, 2, 6, 0, 9, 8, 8 };

	int size = sizeof(array) / sizeof(array[0]);
	//BubbleSort(array, size);
	//SelectSort(array, size);
	//InsertSort(array, size);
	//MergeSort(array, size);
	//MergeSortLoop(array, size);
	QuickSort(array, size);
	Printf(array, size);
}