#include<string>
#include<vector>
#include<algorithm>
#include<functional>
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
	bool DFS_sq(vector<int> nums,int i,int target,vector<int> bucket) {
		int len = nums.size();
		if (i == len) {
			return bucket[0] == target&&bucket[1] == target&&bucket[2] == target&&bucket[3] == target;
		}
		for (int j = 0; j < 4; j++) {
			if (bucket[j]+nums[i] > target) {
				continue;
			}
			bucket[j] += nums[i];
			if (DFS_sq(nums, i + 1, target, bucket)) {
				return true;
			}
			bucket[j] -= nums[i];
		}
		return false;
	}
	bool makesquare(vector<int>& nums) {
		int sum = 0;
		int len = nums.size();
		if (len < 4) {
			return false;
		}
		for (int i = 0; i < len; i++) {
			sum += nums[i];
		}
		if (sum % 4) {
			return false;
		}
		int target = sum / 4;
		sort(nums.begin(), nums.end());
		vector<int> bucket(4, 0);
		
		return DFS_sq(nums, 0, target, bucket);
	}
};