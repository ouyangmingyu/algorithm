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
	int searchInsert(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 0) {
			return 0;
		}
		int l = 0;
		int r = len - 1;
		int index = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			if (nums[mid] > target) {
				r = mid - 1;
			}
			if (nums[mid] < target) {
				l = mid + 1;
			}
			if (r == -1) {
				index = 0;
				break;
			}
			if (l == len) {
				index = len;
				break;
			}
			if (r < l) {
				index = r + 1;
				break;
			}
		}
		return index;
	}
};