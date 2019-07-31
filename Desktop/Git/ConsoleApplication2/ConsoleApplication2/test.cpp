#include<iostream>

using namespace std;

//int Add(int left, int right);
//
//int& Add(double left, int right);

//int main()
//{
//	double a = 10;
//	const int& ra = a;
//	cout << &a << endl;
//	cout << &ra << endl;
//	return 0;
//}

//int main()
//{
//	const int b = 10;
//	int& rb = b;
//	return 0;
//}

//int main()
//{
//	double a = 10;
//	const int& ra = a;
//	return 0;
//}

int main()
{
	int a = 10;
	int& ra = a;
	ra = 20;

	int *p = &a;
	*p = 20;
	return 0;
}