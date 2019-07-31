#include<iostream>
#include<cctype>
using namespace std;

#if 0
int main()
{
	cout << "Enter text for analysis, and type @"
		" to terminate input.\n";
	char ch;
	int whitespace = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int others = 0;
	cin.get(ch);
	while (ch != '@')
	{
		if (isalpha(ch))
			chars++;
		else if (isspace(ch))
			whitespace++;
		else if (isdigit(ch))
			digits++;
		else if (ispunct(ch))
			punct++;
		else
			others++;

		cin.get(ch);

	}
	cout << chars << "letters"
		<< whitespace << "whitespace"
		<< digits << "digis"
		<< punct << "punct"
		<< others << "others.\n";
	return 0;
}
#endif

#if 0

int main()
{
	int a, b;
	cin >> a >> b;
	cout << "The large of " << a << "and" << b << "is";
	int c = a ? b : a > b;
	cout << c;
	return 0;
}
#endif
