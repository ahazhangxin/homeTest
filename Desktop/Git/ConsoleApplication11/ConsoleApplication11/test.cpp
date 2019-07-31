/*
#include<iostream>
using namespace std;
class A
{
public:
	void print()
	{
		cout << "a:print";
	}
};
class B:private A
{
public:
	void print()
	{
		cout << "b:print";
	}
};
class C:public B
{
	void print()
	{
		A::print();
	}
};
int main()
{
	C b;
	b.print();
}
*/


//针对一只兔子
//1 1 2 3 4 5 6 7 8 
//没新生一只兔子，便对此进行

/*
#include<iostream>
using namespace std;

class rabbit
{
public:
	int GetTotalCount(int month);
};


int rabbit::GetTotalCount(int n)
{
	if ( n < 2 )
	{
		return 1;
	}
	else
	{

	}
}
*/

#include<iostream>
using namespace std;
class A{
public:
	long a;
};

class B : public A{
public:
	long b;
};

void seta(A* data, int idx)
{
	data[idx].a = 2;
}

int main(int argc, char* argv[])
{
	B data[4];
	for (size_t i = 0; i < 4; ++i)
	{
		data[i].a = 1;
		data[i].b = 1;
		seta(data, i);
	}
	for(int i = 0; i < 4; ++i)
	{
		cout << data[i].a << data[i].b;
	}
	return 0;
}
