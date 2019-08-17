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
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) {
			return 0;
		}
		vector<int> dp(len, INT_MIN);
		dp[0] = nums[0];
		int max_sum = INT_MIN;
		for (int i = 1; i < len; i++) {
			dp[i] = (dp[i - 1] + nums[i]) > nums[i] ? (dp[i - 1] + nums[i]) : nums[i];
			max_sum = max_sum > dp[i] ? max_sum : dp[i];
		}
		return max_sum;
	}
};