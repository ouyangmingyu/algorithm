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
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<vector<int>>& dp = triangle;
		int lent = triangle.size();
		if (lent == 0) {
			return 0;
		}
		for (int i = 0; i < lent; i++) {
			triangle.push_back(vector<int>());
			int len = triangle[i].size();
			for (int j = 0; j < len; j++) {
				triangle[i].push_back(0);
			}
		}
		for (int i = 0; i < triangle[lent - 1].size(); i++) {
			dp[lent - 1][i] = triangle[lent - 1][i];
		}
		if (lent > 1) {
			for (int i = lent - 2; i >= 0; i--) {
				for (int j = 0; j < triangle[i].size(); j++) {
					dp[i][j] = (dp[i + 1][j] < dp[i + 1][j + 1] ? dp[i + 1][j] : dp[i + 1][j + 1]) + triangle[i][j];
				}
			}
		}
		return dp[0][0];
	}
};