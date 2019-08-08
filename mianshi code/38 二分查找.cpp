#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

#include "zx.h"

using namespace std;

class solution {
public:
	static bool BinarySearch(vector<int> v,int target)
	{
		int len = v.size();
		if (len == 0) {
			return false;
		}
		int left = 0;
		int right = len - 1;
		int mid=0;
		while (left <= right) {
			mid = (left + right) / 2;
			if (v[mid] == target) {
				return true;
			}
			if (v[mid] > target) {
				right = mid - 1;
			}
			if (v[mid] < target) {
				left=mid+1;
			}
		}
		return false;
	}
};





int main38() {
	vector<int> v = { 1,3,5,7,9,10 };
	if (solution::BinarySearch(v,2)) {
		cout << "找到了" << endl;
	}
	else {
		cout << "没找到" << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}

