#include<queue>
#include<stack>
#include<set>
#include<list>
#include<map>
#include<math.h>
#include "zx.h"

using namespace std;

class Solution {
public:
	int Bis(vector<int> B, int target) {
		int l = 0;
		int r = B.size() - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (B[mid] == target) {
				return mid;
			}
			if (B[mid] > target) {
				r = mid - 1;
			}
			if (B[mid] < target) {
				l = mid + 1;
			}
		}
		return l;
	}
	int lengthOfLIS(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) {
			return 0;
		}
		vector<int> B;
		B.push_back(nums[0]);
		int res = 0;
		for (int i = 1; i < len; i++) {
			if (nums[i] > B[res]) {
				B.push_back(nums[i]);
				res++;
			}
			else {
				int pos = Bis(B, nums[i]);
				B[pos] = nums[i];
			}
		}
		return B.size();
	}
};