/*
#include<queue>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef unsigned char UCH;

typedef HuffmanTree Node;
typedef Node* PNode;

struct HuffmanTree
{
	char data;
	HuffmanTree(const char& weight)
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _weight(weight)
	{}

	HuffmanTree* _pLeft;
	HuffmanTree* _pRight;
	HuffmanTree* _pParent;
	char _weight;
};


struct Compare
{
	typedef HuffmanTree* PNode;
	bool operator()(const PNode pLeft, const PNode pRight)
	{
		return pLeft->_weight > pRight->_weight;
	}
};

HuffmanTree *create_huffman_tree(const std::string& data)
{

	//每次读1K的数据


	while (1)
	{
		size_t rdSize = data.size();
		if (0 == rdSize)
			break;
		for (size_t i = 0; i < rdSize; ++i)
		{
			_charInfo[pReadBuff[i]]._charCount++;
			//以 ASCII 码作为地址的下标
		}
	}

	void CreatHuffmanTree(const std::vector& v, const W& invalid)
	{
		if (v.empty())
		{
			return;
		}
		//用所给的权值创建二叉树森林
		std::priority_queue<PNode, std::vector<PNode>, Compare<W>>q;
		//优先级队列
		for (size_t i = 0; i < v.size(); ++i)
		{
			if (v[i] != invalid)
				q.push(new Node(v[i]));
		}


		while (q.size()>1)
		{
			PNode pLeft = q.top();
			q.pop();

			PNode pRight = q.top();
			q.pop();

			PNode pParent = new Node(pLeft->_weight + pRight->_weight);

			pParent->_pLeft = pLeft;
			pLeft->_pParent = pParent;

			pParent->_pRight = pRight;
			pRight->_pParent = pParent;

			q.push(pParent);
		}
		_pRoot = q.top();
	}

	PNode GetRoot()
	{
		return _pRoot;
	}

}


int main()
{
	string q;
	while (cin >> q)
	{
		create_huffman_tree(q);
	}
	return 0;
}
*/
/*
#include"test.h"


int main()
{
	Solution solution;
	vector<int> Array{ 3, 4, 5, 1, 2 };
	int a = solution.minNumberInRotateArray(Array);
	cout << a << endl;
	return 0;
}*/

/*
#include<iostream>
using namespace std;

int Fibonacci(int n) {
	if (n < 0)
		return -1;
	int i = 0;
	int j = 1;
	n--;
	while (n--){
		i = i + j;
		j = i + j;
	}
	return i;
}

int main()
{
	int a = Fibonacci(0);
	cout << a << endl;
	return 0;
}

*/



/*

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str1, str2;
	int len1, len2;
	unsigned int count = 0;
	while (cin >> str1 >> str2 >> len1 >> len2)
	{
		int len = str1.size();
		len2 = str2.size();
		str1 += str2;
		if (len > len1)
			len = len1;
		for (int i = 0; i <= len; ++i){
			if (i == len && len < len2){
				break;
			}
			count += (str2[i] - str1[i]) * 26 * (len2 - i - 1);
		}
		int a = len2 - len;
		for (int i = a; i < len2; ++i)
		{
			count += 26 * (len2 - i - 1);
		}
		count += ((str2[len2 - 1] - str1[len2 - 1]) + 1);
		cout << count << endl;
		count = 0;
	}
	return 0;
}

*/

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int MaxLength = 0;
	int count = 7;
	int temp;
	vector< int > a{1,7,3,5,9,4,8};
	//cin >> count;
	//for (int i = 0; i < count; ++i){
	//	cin >> temp;
	//	a.push_back(temp);
	//}
	temp = 0;
	for (int i = 0; i < count; ++i){
		if (a[i] > a[i + 1]){
			if (temp < MaxLength){
				temp = MaxLength;
				MaxLength = 0;
			}
		}
		MaxLength++;
	}
	cout << temp;
	return 0;
}