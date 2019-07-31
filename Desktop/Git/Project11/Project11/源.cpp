#include<iostream>
using namespace std;

void TestFunc(double a = 10)
{
	cout << "void TestFunc(int)" << endl;
}
void TestFunc(int a)
{
	cout << "void TestFunc(int)" << endl;
}

int main()
{
	return 0;
}