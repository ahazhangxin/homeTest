#include<deque>
void PrintDeque(const std::deque<int>& d) {
	for (const auto& e : d)
		cout << e << " ";
	cout << endl;
}
// 测试deque的构造函数
void TestDeque1()
{
	// 构造空的双端队列
	std::deque<int> d1;
	// 用10个值为5的元素构造双端队列
	std::deque<int> d2(10, 5);
	PrintDeque(d2);
	// 用数组的区间构造双端队列
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	std::deque<int> d3(array, array + sizeof(array) / sizeof(array[0]));
	PrintDeque(d3);
	// 用d3拷贝构造d4
	std::deque<int> d4(d3);
	PrintDeque(d4);
}
// 测试deque中的迭代器
void TestDeque2()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	std::deque<int> d(array, array + sizeof(array) / sizeof(array[0]));
	// 利用正向迭代器打印deque中的元素
	for (auto it = d.cbegin(); it != d.cend(); ++it)
		cout << *it << " ";
	cout << endl;
	auto cit = d.cbegin();
	//*it = 100; 该条语句编译失败，it为const迭代器，其指向空间元素值不能修改
	// 利用反向迭代器逆向打印deque中的元素
	for (auto it = d.crbegin(); it != d.crend(); ++it)
		cout << *it << " ";
	cout << endl;
}
void TestDeque3()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	std::deque<int> d1(array, array + sizeof(array) / sizeof(array[0]));
	// 在deque的尾部插入5，头部插入1，并打印
	d1.push_back(6);
	d1.push_front(2);
	PrintDeque(d1);
	cout << d1.size() << endl;
	cout << d1.front() << endl;
	cout << d1.back() << endl;
	// 在deque的begin位置插入元素0
	d1.insert(d1.begin(), 0);
	PrintDeque(d1);
	// 删除deque首部与尾部元素
	d1.pop_front();
	d1.pop_back();
	d1.erase(d1.begin());
	PrintDeque(d1);
	// 将deque中的元素清空
	d1.clear();
	cout << d1.size() << endl;
}
// 问题：如果要对deque中的元素进行排序，以下的效率高吗？
#include <algorithm>
#include <deque>
void TestDequeSort()
{
	int array[] = { 5, 2, 1, 9, 6, 3, 8, 7, 4, 0 };
	deque<int> d(array, array + sizeof(array) / sizeof(array[0]));
	PrintDeque(d);
	// 利用标准库中的算法对deque中的元素进行升序排序
	sort(d.begin(), d.end());
	PrintDeque(d);
}
/*
上述对deque中排序操作的效率是非常低的，当对deque排序时，需要多次对deque中的元素进行整体遍历，而
deque中的元素整体遍历时效率比较低，这是因为deque底层的空间不连续，如果要进行整体遍历，在某段空间的
默认或首部时，必须要计算下一段或者前一段空间的位置，导致deque的效率比较底下。
*/