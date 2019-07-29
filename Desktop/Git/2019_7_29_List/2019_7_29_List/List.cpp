/*

// constructing lists
#include <iostream>
#include <list>
using namespace std;
int main()
{
	std::list<int> l1; // 构造空的l1
	std::list<int> l2(4, 100); // l2中放4个值为100的元素
	std::list<int> l3(l2.begin(), l2.end()); // 用l2的[begin(), end()）左闭右开的区间构造l3
	std::list<int> l4(l3); // 用l3拷贝构造l4
	// 以数组为迭代器区间构造l5
	int array[] = { 16, 2, 77, 29 };
	std::list<int> l5(array, array + sizeof(array) / sizeof(int));
	// 用迭代器方式打印l5中的元素
	for (std::list<int>::iterator it = l5.begin(); it != l5.end(); it++)
		std::cout << *it << " ";
	std::cout << endl;
	// C++11范围for的方式遍历
	for (auto& e : l5)
		std::cout << e << " ";
	std::cout << endl;
	return 0;
}

*/
/*
#include<vector>
#include <list>
#include<iostream>
using namespace std;
void PrintList(list<int>& l)
{
	for (auto& e : l)
		cout << e << " ";
	cout << endl;
}
//=========================================================================================
// push_back/pop_back/push_front/pop_front
void TestList1()
{
	int array[] = { 1, 2, 3 };
	list<int> L(array, array + sizeof(array) / sizeof(array[0]));
	// 在list的尾部插入4，头部插入0 L.push_back(4);
	L.push_front(0);
	PrintList(L);
	// 删除list尾部节点和头部节点
	L.pop_back();
	L.pop_front();
	PrintList(L);
}
//=========================================================================================
// insert /erase 
void TestList3()
{
	int array1[] = { 1, 2, 3 };
	list<int> L(array1, array1 + sizeof(array1) / sizeof(array1[0]));
	// 获取链表中第二个节点
	auto pos = ++L.begin();
	cout << *pos << endl;
	// 在pos前插入值为4的元素
	L.insert(pos, 4);
	PrintList(L);
	// 在pos前插入5个值为5的元素
	L.insert(pos, 5, 5);
	PrintList(L);
	// 在pos前插入[v.begin(), v.end)区间中的元素
	vector<int> v{ 7, 8, 9 };
	L.insert(pos, v.begin(), v.end());
	PrintList(L);
	// 删除pos位置上的元素
	L.erase(pos);
	PrintList(L);
	// 删除list中[begin, end)区间中的元素，即删除list中的所有元素
	L.erase(L.begin(), L.end());
	PrintList(L);
}
// resize/swap/clear
void TestList4()
{
	// 用数组来构造list
	int array1[] = { 1, 2, 3 };
	list<int> l1(array1, array1 + sizeof(array1) / sizeof(array1[0]));
	PrintList(l1);
	// 交换l1和l2中的元素
	l1.swap(l2);
	PrintList(l1);
	PrintList(l2);
	// 将l2中的元素清空
	l2.clear();
	cout << l2.size() << endl;
}
*/
#include<iostream>
using namespace std;

namespace bite
{
	// List的节点类
	template<class T>
	struct ListNode
	{
		ListNode(const T& val = T())
		: _pPre(nullptr)
		, _pNext(nullptr)
		, _val(val)
		{}
		ListNode<T>* _pPre;
		ListNode<T>* _pNext; T _val;
	};
	/*
	List 的迭代器
	迭代器有两种实现方式，具体应根据容器底层数据结构实现：
	1. 原生态指针，比如：vector
	2. 将原生态指针进行封装，因迭代器使用形式与指针完全相同，因此在自定义的类中必须实现以下方法：
	1. 指针可以解引用，迭代器的类中必须重载operator*()
	2. 指针可以通过->访问其所指空间成员，迭代器类中必须重载oprator->()
	3. 指针可以++向后移动，迭代器类中必须重载operator++()与operator++(int)
	至于operator--()/operator--(int)释放需要重载，根据具体的结构来抉择，双向链表可以向前
	移动，所以需要重载，如果是forward_list就不需要重载--
	4. 迭代器需要进行是否相等的比较，因此还需要重载operator==()与operator!=()
	*/
	template<class T, class Ref, class Ptr>
	class ListIterator
	{
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;
	public:
		ListIterator(PNode pNode = nullptr)
			: _pNode(pNode)
		{}
		ListIterator(const Self& l)
			: _pNode(l._pNode)
		{}
		T& operator*(){ return _pNode->_val; }
		T* operator->(){ return &(operator*()); }
		Self& operator++()
		{
			_pNode = _pNode->_pNext;
			return *this;
		}
		Self operator++(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pNext;
			return temp;
		}
		Self& operator--();
		Self& operator--(int);
		bool operator!=(const Self& l){ return _pNode != l._pNode; }
		bool operator==(const Self& l){ return _pNode != l._pNode; }
		PNode _pNode;
	};
	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T&> const_iterator;
	public:
		///////////////////////////////////////////////////////////////
		// List的构造
		list()
		{
			CreateHead();
		}
		list(int n, const T& value = T())
		{
			CreateHead();
			for (int i = 0; i < n; ++i)
				push_back(value);
		}
		template <class Iterator>
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		list(const list<T>& l)
		{
			CreateHead();
			// 用l中的元素构造临时的temp,然后与当前对象交换
			list<T> temp(l.cbegin(), l.cend());
			this->swap(temp);
		}
		list<T>& operator=(const list<T> l)
		{
			this->swap(l);
			return *this;
		}
		~list()
		{
			clear();
			delete _pHead;
			_pHead = nullptr;
		}
		///////////////////////////////////////////////////////////////
		// List Iterator
		iterator begin(){ return iterator(_pHead->_pNext); }
		iterator end(){ return iterator(_pHead); }
		const_iterator begin(){ return const_iterator(_pHead->_pNext); }
		const_iterator end(){ return const_iterator(_pHead); }
		///////////////////////////////////////////////////////////////
		// List Capacity
		size_t size()const;
		bool empty()const;
		////////////////////////////////////////////////////////////
		// List Access
		T& front();
		const T& front()const; T& back();
		const T& back()const;
		////////////////////////////////////////////////////////////
		// List Modify
		void push_back(const T& val){ insert(begin(), val); }
		void pop_back(){ erase(--end()); }
		void push_front(const T& val){ insert(begin(), val); }
		void pop_front(){ erase(begin()); }
		// 在pos位置前插入值为val的节点
		iterator insert(iterator pos, const T& val)
		{
			PNode pNewNode = new Node(val);
			PNode pCur = pos._pNode;
			// 先将新节点插入
			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;
			return iterator(pNewNode);
		}
		// 删除pos位置的节点，返回该节点的下一个位置
		iterator erase(iterator pos)
		{
			// 找到待删除的节点
			PNode pDel = pos._pNode;
			PNode pRet = pDel->_pNext;
			// 将该节点从链表中拆下来并删除
			pDel->_pPre->_pNext = pDel->_pNext;
			pDel->_pNext->_pPre = pDel->_pPre;
			delete pDel;
			return iterator(pRet);
		}
		void clear();
		void swap(List<T>& l);
	private:
		void CreateHead()
		{
			_pHead = new Node;
			_pHead->_pPre = _pHead;
			_pHead->_pNext = _pHead;
		}
	private:
		PNode _pHead;
	};
}


// 正向打印链表
template<class T>
void PrintList(const bite::list<T>& l) {
	auto it = l.cbegin();
	while (it != l.cend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
// 测试List的构造
void TestList1()
{
	bite::list<int> l1;
	bite::list<int> l2(10, 5);
	PrintList(l2);
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	bite::list<int> l3(array, array + sizeof(array) / sizeof(array[0]));
	PrintList(l3);
	bite::list<int> l4(l3);
	PrintList(l4);
	l1 = l4;
	PrintList(l1);
	PrintListReverse(l1);
}
// PushBack()/PopBack()/PushFront()/PopFront()
void TestList2()
{
	// 测试PushBack与PopBack
	bite::list<int> l; l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	PrintList(l);
	l.pop_back();
	l.pop_back();
	PrintList(l);
	l.pop_back();
	cout << l.size() << endl;
	// 测试PushFront与PopFront
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	PrintList(l);
	l.pop_front();
	l.pop_front();
	PrintList(l);
	l.pop_front();
	cout << l.size() << endl;
}
void TestList3()
{
	int array[] = { 1, 2, 3, 4, 5 };
	bite::list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	auto pos = l.begin();
	l.insert(l.begin(), 0);
	PrintList(l);
	++pos; l.insert(pos, 2);
	PrintList(l);
	l.erase(l.begin());
	l.erase(pos);
	PrintList(l);
	// pos指向的节点已经被删除，pos迭代器失效
	cout << *pos << endl;
	auto it = l.begin();
	while (it != l.end())
	{
		it = l.erase(it);
	}
	cout << l.size() << endl;
}


int main()
{
	TestList1();
	TestList2();
	TestList3();
	return 0;
}