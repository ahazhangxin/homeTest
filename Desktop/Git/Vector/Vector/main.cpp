
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	size_t sz;
//	std::vector<int> foo;
//	sz = foo.capacity();
//	cout << "making foo grow:\n";
//	for (int i = 0; i<100; ++i) {
//		foo.push_back(i);
//		if (sz != foo.capacity()) {
//			sz = foo.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//	std::vector<int> bar;
//	sz = bar.capacity();
//	bar.reserve(100); // this is the only difference with foo above
//	cout << "making bar grow:\n";
//	for (int i = 0; i<100; ++i) {
//		bar.push_back(i);
//		if (sz != bar.capacity()) {
//			sz = bar.capacity();
//			std::cout << "capacity changed: " << sz << '\n';
//		}
//	}
//	return 0;
//}

//int main()
//{
//	std::vector<int> myvector;
//	// set some initial content:
//	for (int i = 1; i<10; i++)
//		myvector.push_back(i);
//	myvector.resize(5);
//	myvector.resize(8, 100);
//	myvector.resize(12);
//	std::cout << "myvector contains:";
//	for (int i = 0; i<myvector.size(); i++)
//		std::cout << ' ' << myvector[i];
//	std::cout << '\n';
//	return 0;
//}


//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		vector<int>::iterator it = nums.begin();
//		while (it != (nums.end() - 1))
//		{
//			if (*it == *(it + 1))
//			{
//				it = nums.erase(it);
//			}
//			else
//			{
//				++it;
//			}
//		}
//		return nums.size();
//	}
//};


//int main()
//{
//	Solution s;
//	vector<int> v;
//		v.push_back(1);
//		v.push_back(1);
//		v.push_back(2);
//		v.push_back(2);
//		v.push_back(3);
//		v.push_back(3);
//		v.push_back(4);
//		v.push_back(4);
//		v.push_back(5);
//	s.removeDuplicates(v);
//	return 0;
//}

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		if (nums.size() == 1)
			return nums[0];
		vector<int>::iterator it = nums.begin();
		it++;
		while (it != (nums.end() - 1))
		{
			if (*it != *(it + 1) && *it != *(it - 1))
				return *it;
			it++;
		}
		return *(nums.end());
	}
};


int main()
{
	Solution s;
	vector<int> v;
	v.push_back(-2);
	v.push_back(-2);
	v.push_back(1);
	v.push_back(1);
	v.push_back(-3);
	v.push_back(-3);
	v.push_back(1);
	v.push_back(-2);
	v.push_back(-4);
	s.singleNumber(v);
	return 0;
}