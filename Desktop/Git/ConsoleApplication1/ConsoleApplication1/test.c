#include<iostream>
////普通的命名空间
//namespace N1
//{
//	int a = 10;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//}
////命名空间可以嵌套
//namespace N2
//{
//	int a = 20;
//	int b = 30;
//	namespace N3
//	{
//		int Add(int left, int right)
//		{
//			return left + right;
//		}
//	}
//}
////命名空间可以重名，当命名空间重名时，这两个空间实质上是同一块，所以命名空间中的所有变量和函数会合并起来，所以在这里面不能出现相同命名的变量和函数
//namespace N1 
//{ 
//	int Mul(int left, int right)   
//	{ 
//		return left * right;
//	} 
//}
//
//#include<iostream>
//void TestFunc(int a = 0)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	TestFunc();//没有传参时，使用参数的默认值
//	TestFunc(10);//传参时，使用指定的参数
//	return 0;
//}


//a.h void TestFunc(int a = 10);

// a.c void TestFunc(int a = 20) {}

// 注意：如果生命与定义位置同时出现，恰巧两个位置提供的值不同，那编译器就无法确定到底该用那个 缺省值。
int Add(int left, int right)
{ 
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}
