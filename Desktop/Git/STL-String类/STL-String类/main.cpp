/*
*	这个demo模拟实现String
*	并解决深浅拷贝问题
*/
#include<iostream>
#include<assert.h>
using namespace std;

//class MyString
//{
//public:
//	//构造函数
//	MyString(const char* str = "")
//	{
//		if (str == nullptr)
//		{
//			assert(false);
//			return;
//		}
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//	//析构函数
//	~MyString()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//	//赋值运算符重载
//	MyString& operator=(const MyString& s)
//	{
//		if (&s != this)
//		{
//			delete[] this->_str;
//
//			_str = new char[strlen(s._str) + 1];
//			strcpy(_str, s._str);
//		}
//
//		return *this;
//	}
//
//	//拷贝构造
//	MyString(const MyString& s)
//		:_str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}
//private:
//	char* _str;
//};


//class MyString
//{
//public:
//	MyString(const char* str = "")
//	{
//		if (nullptr == str)
//			str = "";
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//
//	MyString(const MyString& s)
//	{
//		MyString str(s._str);
//		swap(_str, str._str);
//	}
//
//	MyString& operator=(MyString& s)
//	{
//		swap(_str, s._str);
//		return *this;
//	}
//	~MyString()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//
//private:
//	char* _str;
//};


class String
{
public:
	String()
		: data_(new char[1])
	{
		*data_ = '\0';
	}

	String(const char* str)
		: data_(new char[strlen(str) + 1])
	{
		strcpy(data_, str);
	}

	String(const String& rhs)
		: data_(new char[rhs.size() + 1])
	{
		strcpy(data_, rhs.c_str());
	}
	/* Delegate constructor in C++11
	String(const String& rhs)
	: String(rhs.data_)
	{
	}
	*/

	~String()
	{
		delete[] data_;
	}

	/* Traditional:
	String& operator=(const String& rhs)
	{
	String tmp(rhs);
	swap(tmp);
	return *this;
	}
	*/
	String& operator=(String rhs) // yes, pass-by-value
	{
		swap(rhs);
		return *this;
	}

	// C++ 11
	String(String&& rhs)
		: data_(rhs.data_)
	{
		rhs.data_ = nullptr;
	}

	String& operator=(String&& rhs)
	{
		swap(rhs);
		return *this;
	}

	// Accessors

	size_t size() const
	{
		return strlen(data_);
	}

	const char* c_str() const
	{
		return data_;
	}

	void swap(String& rhs)
	{
		std::swap(data_, rhs.data_);
	}

private:
	char* data_;
};
int main()
{
	String s = { "123456" };

	String s1 = s;
	String s2(s1);
	return 0;
}