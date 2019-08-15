#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<functional>
#include<queue>
#include<queue>
#include<stack>
#include<set>
#include<list>
#include "zx.h"

using namespace std;

class Solution {
public:
	int find_left(vector<int> nums, int target) {
		int len = nums.size();
		int l = 0;
		int r = len - 1;
		int res = -1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] == target) {
				res =mid;
				while (mid > 0) {
					mid--;
					if (nums[mid] == target) {
						res = mid;
					}
					else {
						break;
					}
				}
				break;
			}
			if (nums[mid] > target) {
				r = mid - 1;
			}
			if (nums[mid] < target) {
				l = mid + 1;
			}
		}
		return res;
	}

	int find_right(vector<int> nums, int target) {
		int len = nums.size();
		int l = 0;
		int r = len - 1;
		int res = -1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] == target) {
				res = mid;
				while (mid < len-1) {
					mid++;
					if (nums[mid] == target) {
						res = mid;
					}
					else {
						break;
					}
				}
				break;
			}
			if (nums[mid] > target) {
				r = mid - 1;
			}
			if (nums[mid] < target) {
				l = mid + 1;
			}
		}
		return res;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		int len = nums.size();
		int left = find_left(nums, target);
		int right = -1;
		if (left != -1) {
			right = find_right(nums, target);
		}
		vector<int> res;
		res.push_back(left);
		res.push_back(right);
		return res;
	}
};

//int main() {
//	Solution s;
//	vector<int> v = { 5,7,7,8,8,10 };
//	s.searchRange(v, 8);
//	system("pause");
//	return 0;
//}