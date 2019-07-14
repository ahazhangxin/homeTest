#include<iostream>
using namespace std;

#if 0
class Base
{
public:
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}
private:
	int _b = 1;
};

int main()
{
	cout << sizeof(Base);
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
// 以下测试函数能通过编译吗？
void Test()
{
	Date d1;
}

#endif

