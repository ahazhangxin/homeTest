#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class String
{
public:
	String(const char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		if (nullptr == str)
		{
			str = "";
		}
		strcpy(_str, str);
	}

	String(const String& s)
	{
		String str(s._str);
		swap(_str, str._str);
	}

	String& operator=(String& s)
	{
		swap(_str, s._str);
		return *this;
	}

	String(String&& s)
		:_str(s._str)
	{
		_str = nullptr;
	}

	size_t size()
	{
		return strlen(_str);
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
	String s = { "123456" };
	cout << s.size() << endl;
	return 0;
}