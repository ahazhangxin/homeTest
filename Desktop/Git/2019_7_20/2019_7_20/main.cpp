/*#include<iostream>
#include<stdlib.h>
using namespace std;
*/
/*
class Date
{
public:


	bool IsLeapYear(int year)
	{
		return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
	}

	int GetDayInMonth(int year, int month)
	{
		int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (IsLeapYear(year))
		{
			months[2] = 29;
		}
		return months[month];
	}

	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
			_year = d._year;
			_month = d._month;
			_day = d._day;
	}

	Date& operator=(const Date& d)
	{
		if (this != &d){
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	Date operator+(int days)
	{
		_day += days;

		if (_day > GetDayInMonth(_year, _month))
		{
			_month += 1;
			if (_month > 12)
			{
				_year += 1;
				_month = 1;
			}
			_day = 1;
		}
		return *this;
	}

	Date operator-(int days)
	{
		if (days < 0)//天数若为负数变为加
		{
			return *this + (0 - days);
		}
		Date temp(*this);
		temp._day -= days;
		while (temp._day <= 0)
		{
			temp._month--;
			if (temp._month <= 0)
			{
				temp._year--;
				temp._month = 12;
			}
			temp._day += temp.GetDayInMonth(temp._year,temp._month);
		}
		return temp;
	}

	int operator-(const Date& d)
	{
		Date maxdate(*this);
		Date mindate(d);
		if (maxdate < mindate)
		{
			maxdate = mindate;
			mindate = *this;
		}
		int count = 0;
		while (mindate < maxdate)
		{
			mindate = mindate + 1;
			++count;
		}
		return count;
			
	}

	Date& operator++()
	{
		_day += 1;
		if (_day > GetDayInMonth(_year, _month))
		{
			_month += 1;
			if (_month > 12)
			{
				_year += 1;
				_month = 1;
			}
			_day = 1;
		}
		return *this;
	}

	Date operator++(int)
	{
		Date temp = *this;
		_day += 1;
		return temp;
	}

	Date& operator--()
	{
		_day -= 1;
		if (_day == 0)
		{
			_month -= 1;
			if (_month == 0)
			{
				_year -= 1;
				_month = 12;
				_day = GetDayInMonth(_year - 1, 12);
			}
			else{
				_day = GetDayInMonth(_year, _month);
			}
		}
		return *this;
	}

	Date operator--(int)
	{
		Date temp = *this;
		_day -= 1;
		return temp;
	}

	bool operator>(const Date& d)const
	{
		while (_year > d._year || (_year == d._year&&_month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day))
		{
			return true;
		}
		return false;

	}

	bool operator>=(const Date& d)const
	{
		while (_year > d._year || (_year == d._year&&_month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day) || 
			(_year == d._year && _month == d._month && _day == d._day))
		{
			return true;
		}
		return false;
	}

	bool operator<(const Date& d)const
	{
		while (_year <d._year || (_year == d._year&&_month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}
		return false;
	}
	bool operator<=(const Date& d)const
	{
		while (_year <d._year || (_year == d._year&&_month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day) ||
			(_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}
		return false;
	}
	bool operator==(const Date& d)const
	{
		if (_year == d._year && _month == d._month && _day == d._day)
			return true;
		return false;

	}
	bool operator!=(const Date& d)const
	{
		if (_year != d._year || _month != d._month || _day != d._day)
			return true;
		return false;
	}

	friend ostream& operator<<(ostream& _cout, const Date& d);

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

void FunTest()
{
	Date d1(1900, 2, 28);
	cout << ++d1 << endl;
	cout << --d1 << endl;
	cout << d1 << endl;

	cout << d1-- << endl;
	cout << d1++ << endl;
	cout << d1 << endl;

	Date d2(2017, 5, 1);
	cout << d2 + 100 << endl;
	Date d3(1997, 11, 1);
	cout << d3 - 100 << endl;

	cout << boolalpha << (Date(2016, 10, 1) < d1) << endl;
	cout << d1 - d2 << endl;
}


int main()
{
	FunTest();
	system("pause\n");
	return 0;
}
*/
/*

#include<Windows.h>
int main()
{
	int year = 0;
	for (int i = 0; i < 9999; i++)
	{
		if (((i % 6) == 0) && ((i % 8) == 0) && ((i % 9) == 0))
			cout << i << endl;
	}
	system("pause");
	return 0;

}
*/
/*
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string m, n;
	int count[1025][1025];
	for (int i = 0; i <= 1024; i++){
		count[i][0] = 0;
	}
	for (int j = 0; j <= 1024; j++){
		count[0][j] = 0;
	}
	while (cin >> m >> n){
		for (int i = 1; i <= 1024; i++){
			for (int j = 1; j <= 1024; j++){
				if (m[i - 1] == n[j - 1]){
					count[i][j] = count[i - 1][j - 1] + 1;
				}
				else{
					count[i][j] = max(count[i][j - 1], count[i - 1][j]);
				}
			}
		}
		cout << count[m.length()][n.length()];
	}
	return 0;
}
*/
/*
#include <iostream>
using namespace std;
int main()
{
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}
*/
/*
#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		: _str(nullptr)
	{
		String strTmp(s._str);
		swap(_str, strTmp);
	}

	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};


int main()
{
	return 0;
}
*/

/*
#include<iostream>
#include<assert.h>
using namespace std;

namespace bit
{
	class String
	{
	public:
		typedef char* iterator;
	public:
		String(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		String(const String& s)
			: _str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			String tmp(s);
			this->Swap(tmp);
		}
		String& operator=(String s)
		{
			this->Swap(s);
			return *this;
		}
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
		/////////////////////////////////////////////////////////////////
		// iterator
		iterator begin() { return _str; }
		iterator end(){ return _str + _size; }
		/////////////////////////////////////////////////////////////////
		// modify
		void PushBack(char c)
		{
			if (_size == _capacity)
				Reserve(_capacity * 2);
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		String& operator+=(char c)
		{
			PushBack(c);
			return *this;
		}
		// 作业实现
		void Append(const char* str);
		String& operator+=(const char* str);
		void Clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}
		void Swap(String& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
		const char* C_Str()const
		{
			return _str;
		}
		/////////////////////////////////////////////////////////////////
		// capacity
		size_t Size()const;
		size_t Capacity()const;
		bool Empty()const;
		void Resize(size_t newSize, char c = '\0')
		{
				if (newSize > _size)
				{
					// 如果newSize大于底层空间大小，则需要重新开辟空间
					if (newSize > _capacity)
					{
						Reserve(newSize);
					}
					memset(_str + _size, c, newSize - _size);
				}
				_size = newSize;
				_str[newSize] = '\0';
			}
		void Reserve(size_t newCapacity)
		{
			// 如果新容量大于旧容量，则开辟空间
			if (newCapacity > _capacity)
			{
				char* str = new char[newCapacity + 1];
				strcpy(str, _str);
				// 释放原来旧空间,然后使用新空间
				delete[] _str;
				_str = str;
				_capacity = newCapacity;
			}
		}
		////////////////////////////////////////////////////////////////////
		// access
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}
		////////////////////////////////////////////////////////////////////
		// 作业
		bool operator<(const String& s);
		bool operator<=(const String& s);
		bool operator>(const String& s);
		bool operator>=(const String& s);
		bool operator==(const String& s);
		bool operator!=(const String& s);
		// 返回c在string中第一次出现的位置
		size_t Find(char c, size_t pos = 0) const;
		// 返回子串s在string中第一次出现的位置
		size_t Find(const char* s, size_t pos = 0) const;
		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		String& Insert(size_t pos, char c);
		String& Insert(size_t pos, const char* str);
		// 删除pos位置上的元素，并返回该元素的下一个位置
		String& Erase(size_t pos, size_t len);
	private:
		friend ostream& operator<<(ostream& _cout, const bit::String& s);
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
		};
}
ostream& bit::operator<<(ostream& _cout, const bit::String& s) {
	cout << s._str;
	return _cout;
}
///////对自定义的string类进行测试
void TestBitString()
{
	bit::String s1("hello");
	s1.PushBack(' ');
	s1.PushBack('b');
	s1.Append(1, 'i');
	s1 += 't';
	cout << s1 << endl;
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	// 利用迭代器打印string中的元素
	String::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	// 这里可以看到一个类只要支持的基本的iterator，就支持范围for
	for (auto ch : s1)
	cout << ch << " ";
	cout << endl;
}

*/