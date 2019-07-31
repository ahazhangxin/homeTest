#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	while (cin>>str)
	{
		int i;
		int max = 0;
		string ss;
		string out;
		for (size_t i = 0; i < ss.size(); i++)
		{
			if (str[i] > '0' && str[i] < '9')
			{
				ss += str[i];
			}
			while (str[i + 1] > '0' && str[i + 1] < '9')
			{
				++i;
				ss += str[i];
			}
			if (ss.size() > max)
			{
				max = ss.size();
				out = ss;
			}
			else if (ss.size() == max)
			{
				out = ss;
			}
			ss.clear();
		}
		cout << out << ',' << out.size();
	}
	return 0;
}

/**/