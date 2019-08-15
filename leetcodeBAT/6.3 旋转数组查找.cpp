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
	int search(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 0) {
			return -1;
		}
		int res = -1;
		int l = 0;
		int r = len - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] == target) {
				res = mid;
				break;
			}
			if (target < nums[mid]) {
				if (nums[mid] > nums[l]) {
					if (target >= nums[l]) {
						r = mid - 1;
					}
					else {
						l = mid + 1;
					}
				}
				else if (nums[mid] < nums[l]) {
					r = mid - 1;
				}
				else if (nums[mid] == nums[l]) {
					l = mid + 1;
				}
			}
			if (target > nums[mid]) {
				if (nums[l] < nums[mid]) {
					l = mid + 1;
				}
				else if (nums[l] > nums[mid]) {
					if (target >= nums[l]) {
						r = mid - 1;
					}
					else {
						l = mid + 1;
					}
				}
				else if (nums[l] == nums[mid]) {
					l = mid + 1;
				}
			}
		}
		return res;
	}
};