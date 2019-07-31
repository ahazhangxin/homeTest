#include<iostream>

using namespace std;

class Date
{
public:
	Date(int year = 2018,int month = 11,int day = 23)//¹¹Ôìº¯Êý
		:_year(year)
		,_month(month)
		,_day(day)
	{
		if (!((_year>0) &&
			(_month>0 && _month<13) &&
			(_day>0 && _day <= _GetDayOfMonth(_year,_month))))
		_year = year;
		_month = month;
		_day = day;
	}

	//Date operator-(int days)
	//{
	//	if (days < 0)
	//	{
	//		return (*this - (0 - days));
	//	}
	//	Date temp(*this);

	//	return temp;
	//}
	Date operator+(int days)
	{
		//if (days < 0)
		//{
		//	return (*this - (0 - days));
		//}
		Date temp(*this);
		temp._day += days;
		int day = 0;
		while (temp._day > (day = _GetDayOfMonth(temp._year, temp._month)))
		{
			temp._day -= day;
			++temp._month;
			if (temp._month > 12)
			{
				temp._year += 1;
				temp._month = 1;
			}
		}
		return temp;
	}
	bool operator==(const Date& d)const
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	bool operator!=(const Date& d1)const
	{
		return (*this == d1);
	}

private:
	int _GetDayOfMonth(int year, int month)
	{
		int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (2 == month&&_IsLeapYear(year))
			days[month] += 1;

		return days[month];
	}
	
	bool _IsLeapYear(int year)
	{
		if ((0 == year % 4 && 0 != year % 100) ||
			(0 == year % 400))
		{
			return true;
		}
		return false;
	}


	friend ostream& operator<<(ostream& _cout, const Date& a)
	{
		_cout << a._year << "-" << a._month << "-" << a._day ;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(1998, 9, 5);	
	cout << d1 + 10000 << endl;
	return 0;
}