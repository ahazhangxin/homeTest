#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		int temp = rotateArray[0];
		int length = rotateArray.size();
		for (int i = 1; i <= length; ++i){
			if (temp > rotateArray[i])
				return rotateArray[i];
			temp = rotateArray[i];
		}
	}
};
