/*
*这个demon测试string的一些功能
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;


//
//int main()
//{
//	string s = {};
//	cout << s.capacity() << endl;
//	s.reserve(31);
//	cout << s.capacity() << endl;
//	s.reserve(15);
//	cout << s.capacity() << endl;
//	return 0;
//}

/*
void test1()
{
string s("hello,world");
cout << s.length() << endl; // 11
cout << s.size() << endl; // 11
cout << s.capacity() << endl;
// 15 ,capacity是15但是实际上开辟了16个char的空间，最后还有`\0`
cout << s << endl;//string类对象支持直接用cin和cout进行输入输出

//将对象s中的字符串清空，只改变有效数据的大小，不改变容量的大小
s.clear();
cout << s.size() << endl; // 0
cout << s.capacity() << endl; // 15
// 将s中有效字符个数增加到10个，多出位置用'j'进行填充
s.resize(10, 'j');
cout << s.size() << endl; // 10
cout << s.capacity() << endl; // 15
cout << s << endl; // jjjjjjjjjj
//将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充
s.resize(15);
cout << s.size() << endl; // 15
cout << s.capacity() << endl; // 15
cout << s << endl; // jjjjjjjjjj\0\0\0\0\0
//将s中有效字符个数缩小到5个
s.resize(5);
cout << s.size() << endl; // 5
cout << s.capacity() << endl; // 15
cout << s << endl; // jjjjj
cout << "--------------" << endl;
//测试reserve
string s2("hehe");
//reserve不会改变string中有效元素个数
cout << s2.size() << endl;//4
cout << s2.capacity() << endl;//15
s2.reserve(100);
cout << s2.size() << endl;//4
cout << s2.capacity() << endl;//111
//当reserve的参数小于 string的底层空间总大小时，reserver不会改变容量大小
s2.reserve(50);
cout << s2.size() << endl; // 4
cout << s2.capacity() << endl; // 111
}
*/


/*
void test1()
{
	string s1("hello");
	const string s2("world");
	cout << s1[0] << " " << s2[0] << endl; //h w
	s1[0] = 'x';
	// s2[0] = 'x';这个不能修改，因为它是const修饰的对象不能修改
	cout << s1[0] << endl;// x
}
*/

/*
void test2()
{
	string str("hello");
	str.push_back('C');//在str后边追加字符C
	cout << str << endl;
	str.append(" world");//在str后边追加字符串
	cout << str << endl;
	str += 'X'; //str后边追加字符X
	cout << str << endl;
	str += "xxx";//str后边追加字符串xxx
	cout << str << endl;
	cout << str.c_str() << endl;//以C语言形式打印字符串
}
// npos是string里面的一个静态成员变量    
// static const size_t npos = -1;
void test3()
{
	string file("test.cpp");
	size_t pos = file.rfind('.');
	if (pos == string::npos)
	{
		cout << "文件不存在后缀" << endl;
	}
	else{
		cout << file.substr(pos, file.size() - pos) << endl;
	}
}
void test4()
{
	string url("http://www.baidu.com/");
	size_t start = url.find("://");
	if (start == string::npos){
		cout << "url error" << endl;
		return;
	}
	//find找不到返回-1，但是用size_t接收finish是一个很大的数字
	size_t finish = url.find('/', start + 3);
	cout << url.substr(start + 3, finish - start - 3) << endl;
	//删除url的前缀
	int pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl;
}
*/

//void test()
//{
//	string num = "1234";
//	string::iterator it = num.begin();
//	int res = 0;
//	while (it != num.end())
//	{
//		res += 10;
//		res += (*it) - '0';
//		cout << *it << '-';
//		cout << res << endl;
//		it++;
//	}
//
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	vector<int>::iterator vit = v.begin();
//	while (vit != v.end())
//	{
//		cout << *vit << endl;
//		vit++;
//	}
//	cout << "--------------------------" << endl;
//	vector<int>::reverse_iterator rvit = v.rbegin();
//	while (rvit != v.rend())
//	{
//		cout << *rvit << endl;
//		rvit++;
//	}
//	cout << "--------------------------" << endl;
//
//}
//int main()
//{
//	test1();
//	test2();
//	test3();
//	test4();
//	test();
//	return 0;
//}