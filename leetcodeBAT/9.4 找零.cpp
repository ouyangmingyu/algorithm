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
	int coinChange(vector<int>& coins, int amount) {
		int lenc = coins.size();
		if (amount == 0) {
			return -1;
		}
		vector<int> dp(amount+1, -1);
		dp[0] = 0;
		for (int i = 1; i <= amount; i++) {
			for (int j = 0; j < lenc; j++) {
				if (i - coins[j] == 0) {
					dp[i] = 1;
					continue;
				}
				else if (i - coins[j] > 0 && dp[i - coins[j]] != -1) {
					if (dp[i] == -1) {
						dp[i] = 1 + dp[i - coins[j]];
					}
					else {
						dp[i] = dp[i] < 1 + dp[i - coins[j]] ? dp[i] : 1 + dp[i - coins[j]];
					}
				}
			}
		}
		return dp[amount];
	}
};