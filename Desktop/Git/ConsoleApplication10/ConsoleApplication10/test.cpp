#include<iostream>
using namespace std;
/*
int Function(unsigned int n)
{
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
	return n;
}
*/
//
//class A
//{
//public:
//	int GetValuv()const
//	{
//		vv = 1;
//		return vv;
//	}
//
//private:
//	mutable int vv;
//};
//
//class Base
//{
//public:
//	Base(int j) 
//		:i(j)
//	{}
//
//	virtual~Base()
//	{}
//	void func1(){
//		i *= 10;
//		func2();
//	}
//	int getValue(){
//		return i;
//	}
//protected:
//	virtual void func2(){
//		i++;
//	}
//protected:
//	int i;
//};
//
//class Child: public Base
//{
//public:
//	Child(int j) : Base(j){}
//	void func1(){
//		i *= 100;
//		func2();
//	}
//
//protected:
//	void func2(){
//		i += 2;
//	}
//
//};
//
//
//int main()
//{
//	//int x = Function(197);
//	/*if ( )
//	{
//		std::cout << "默认可以进去" << std::endl;
//	}
//	*/
//	Base * pb = new Child(1);
//	pb->func1();
//	cout << pb->getValue() << endl;
//	delete pb;
//	return 0;
//}
//
//class A {
//public:
//	int GetValue()  {
//		vv = 1;
//		return vv;
//	}
//private:
//	int vv;
//};
//int main()
//{
//	//A a;
//	A a;
//	int x = a.GetValue();
//	cout << x << endl;
//	return 0;
//}
int main()
{
	char str[] = "glad to test something";
	char *p = str;
	p++;
	int *p1 = reinterpret_cast<int *>(p);
	p1++;
	p = reinterpret_cast<char *>(p1);
	printf("result is %s\n", p);
	cout << sizeof(int*) << endl << sizeof(char*) << endl;
	return 0;
}
