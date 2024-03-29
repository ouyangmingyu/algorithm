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
	int rob(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) {
			return 0;
		}
		if (len == 1) {
			return nums[0] > nums[1] ? nums[0] : nums[1];
		}
		vector<int> dp(len, 0);
		dp[0] = nums[0];
		dp[1]= nums[0] > nums[1] ? nums[0] : nums[1];
		for (int i = 2; i < len; i++) {
			dp[i] = dp[i - 1] > (dp[i - 2] + nums[i]) ? dp[i - 1] : (dp[i - 2] + nums[i]);
		}
		return dp[len - 1];
	}
};