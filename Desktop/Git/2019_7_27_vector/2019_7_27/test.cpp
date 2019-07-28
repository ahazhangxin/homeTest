/*
#include <iostream>
#include <vector>
int main()
{
	size_t sz;
	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i<100; ++i) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}
*/
/*
#include <iostream>
#include <vector>
int main()
{
	size_t sz;
	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i<100; ++i) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100); // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i = 0; i<100; ++i) {
		bar.push_back(i);
		if (sz != bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	return 0;
}
*/


/*

#include <iostream>
#include <vector>
int main()
{
	std::vector<int> myvector;
	// set some initial content:
	for (int i = 1; i<10; i++)
	myvector.push_back(i);
	myvector.resize(5);
	myvector.resize(8, 100);
	myvector.resize(12);
	std::cout << "myvector contains:";
	for (int i = 0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	return 0;
}

*/

/*
// push_back/pop_back
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl; v.pop_back();
	v.pop_back();
	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}

*/

/*

// find / insert / erase
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	// 使用find查找3所在位置的iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	// 在pos位置之前插入30
	v.insert(pos, 30);
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	pos = find(v.begin(), v.end(), 3);
	// 删除pos位置的数据
	v.erase(pos);
	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}

*/



/*
// operator[]+index 和 C++11中vector的新式for+auto的遍历
// vector使用这两种遍历方式是比较便捷的。
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	// 通过[]读写第0个位置。
	v[0] = 10;
	cout << v[0] << endl;
	// 通过[i]的方式遍历vector
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
		cout << endl;
	vector<int> swapv;
	swapv.swap(v);
	cout << "v data:";
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "swapv data:";
	for (size_t i = 0; i < swapv.size(); ++i)
		cout << swapv[i] << " ";
	cout << endl;
	// C++11支持的新式范围for遍历
	for (auto x : v)
		cout << x << " ";
	cout << endl;
	return 0;
}

*/

/*
// insert/erase导致的迭代器失效
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	// 使用find查找3所在位置的iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	// 删除pos位置的数据，导致pos迭代器失效。
	v.erase(pos);
	cout << *pos << endl; // 此处会导致非法访问
	// 在pos位置插入数据，导致pos迭代器失效。
	// insert会导致迭代器失效，是因为insert可
	// 能会导致增容，增容后pos还指向原来的空间，而原来的空间已经释放了。
	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	cout << *pos << endl; // 此处会导致非法访问
	return 0;
}

*/


/*

// 常见的迭代器失效的场景
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	// 实现删除v中的所有偶数
	// 下面的程序会崩溃掉，如果是偶数，erase导致it失效
	// 对失效的迭代器进行++it，会导致程序崩溃
	
	//vector<int>::iterator it = v.begin();
	//while (it != v.end())
	//{
	//	if (*it % 2 == 0) v.erase(it);
	//	++it;
	//}

	
	// 以上程序要改成下面这样，erase会返回删除位置的下一个位置
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}
	return 0;
}


*/

/*

#include <iostream>
using namespace std;
#include <assert.h>


namespace bit
{
	template<class T>
	class vector
	{
	public:
		// Vector的迭代器是一个原生指针
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin() { return _start; }
		iterator end() { return _finish; }
		const_iterator cbegin() const { return _start; }
		const_iterator cend() const { return _finish; }
		// construct and destroy
		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}
		vector(int n, const T& value = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			reserve(n);
			while (n--)
			{
				push_back(value);
			}
		}
		// 如果使用iterator做迭代器，会导致初始化的迭代器区间[first,last)只能是vector的迭代器
		// 重新声明迭代器，迭代器区间[first,last]可以是任意容器的迭代器
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			reserve(last - first);
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			reserve(v.capacity());
			iterator it = begin();
			const_iterator vit = v.cbegin();
			while (vit != v.cend())
			{
				*it++ = *vit++;
			}
			_finish = _start + v.size();
			_endOfStorage = _start + v.capacity();
		}
		vector<T>& operator= (vector<T> v)
		{
			swap(v);
			return *this;
		}
		~vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
		// capacity
		size_t size() const { return _finish - _start; }
		size_t capacity() const { return _endOfStorage - _start; }
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldSize = size();
				T* tmp = new T[n];
				// 这里直接使用memcpy是有问题的
				// 以后我们会用更好的方法解决
				//if (_start)
				// memcpy(tmp, _start, sizeof(T)*size);
				if (_start)
				{
					for (size_t i = 0; i < oldSize; ++i)
						tmp[i] = _start[i];
				}
				_start = tmp;
				_finish = _start + size;
				_endOfStorage = _start + n;
			}
		}
		void resize(size_t n, const T& value = T())
		{
			// 1.如果n小于当前的size，则数据个数缩小到n
			if (n <= size())
			{
				_finish = _start + n;
				return;
			}
			// 2.空间不够则增容
			if (n > capacity())
				reserve(n);
			// 3.将size扩大到n
			iterator it = _finish;
			iterator _finish = _start + n;
			while (it != _finish)
			{
				*it = value;
				++it;
			}
		}
		///////////////access///////////////////////////////
		T& operator[](size_t pos){ return _start[pos]; }
		const T& operator[](size_t pos)const { return _start[pos]; }
		///////////////modify/////////////////////////////
		void push_back(const T& x){ insert(end(), x); }
		void pop_back(){ erase(--end()); }
		void swap(vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}
		iterator insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			// 空间不够先进行增容
			if (_finish == _endOfStorage)
			{
				size_t size = size();
				size_t newCapacity = (0 == capacity()) ? 1 : capacity() * 2;
				reserve(newCapacity);
				// 如果发生了增容，需要重置pos
				pos = _start + size;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		// 返回删除数据的下一个数据
		// 方便解决:一边遍历一边删除的迭代器失效问题
		iterator erase(Iterator pos)
		{
			// 挪动数据进行删除
			iterator begin = pos + 1;
			while (begin != _finish) {
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			return pos;
		}
private:
	iterator _start; // 指向数据块的开始
	iterator _finish; // 指向有效数据的尾
	iterator _endOfStorage; // 指向存储容量的尾
};
}


// constructing vectors
void TestVector1()
{
	// constructors used in the same order as described above:
	bite::vector<int> first; // empty vector of ints
	bite::vector<int> second(4, 100); // four ints with value 100
	bite::vector<int> third(second.Begin(), second.End()); // iterating through second
	bite::vector<int> fourth(third); // a copy of third
	// the iterator constructor can also be used to construct from arrays:
	int myints[] = { 16, 2, 77, 29 };
	bit::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
	std::cout << "The contents of fifth are:";
	for (bit::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << *it << " ";
	std::cout << endl;
	// 测试T是string时，拷贝问题
	bit::vector<string> strV;
	strV.PushBack("1111");
	strV.PushBack("2222");
	strV.PushBack("3333");
	strV.PushBack("4444");
	for (size_t i = 0; i < strV.size(); ++i)
	{
		cout << strV[i] << " ";
	}
	cout << endl;
}
//vector iterator的使用
void PrintVector(const bite::vector<int>& v) {
	// 使用const迭代器进行遍历打印
	bit::vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void TestVector2()
{
	// 使用push_back插入4个数据
	bite::vector<int> v; v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	PrintVector(v);
	// 使用迭代器进行修改
	auto it = v.begin();
	while (it != v.end())
	{
		*it *= 2;
		++it;
	}
	PrintVector(v);
	// 这里可以看出C++11支持iterator及接口，就支持范围for
	for (auto e : v)
		cout << e << " ";
}
// find / insert / erase
void TestVector3()
{
	int a[] = { 1, 2, 3, 4 };
	bite::vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
	// 使用find查找3所在位置的iterator
	auto pos = find(v.begin(), v.end(), 3);
	// 在pos位置之前插入30
	v.insert(pos, 30);
	PrintVector(v);
	// 删除pos位置的数据
	pos = find(v.begin(), v.end(), 3);
	v.Erase(pos);
	PrintVector(v);
}
// iterator失效问题
void TestVector4()
{
	int a[] = { 1, 2, 3, 4 };
	bite::vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
	// 删除pos位置的数据，导致pos迭代器失效
	auto pos = find(v.begin(), v.end(), 3);
	v.erase(pos);
	cout << *pos << endl; // 此处会导致非法访问
	// 在pos位置插入数据，导致pos迭代器失效。
	// insert会导致迭代器失效，是因为insert可
	// 能会导致增容，增容后pos还指向原来的空间，而原来的空间已经释放了。
	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	cout << *pos << endl; // 此处会导致非法访问
	// 实现删除v中的所有偶数
	// 下面的程序会崩溃掉，如果是偶数，erase导致it失效
	// 对失效的迭代器进行++it，会导致程序崩溃
	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0) v.erase(it);
		++it;
	}
	// 以上程序要改成下面这样，erase会返回删除位置的下一个位置
	it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}
}
**************************************************************************
迭代器失效场景总结：
1. 删除pos迭代器位置所指向元素没有及时给pos赋值，比如v.erase(pos)
2. 可能会引起vector底层空间改变的操作，比如：push_back、insert、resize、reserve等
**************************************************************************
*/

