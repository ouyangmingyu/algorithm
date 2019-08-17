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
	int minPathSum(vector<vector<int>>& grid) {
		int row = grid.size();
		if (row == 0) {
			return 0;
		}
		int col = grid[0].size();
		vector<int> dp(col, INT_MAX);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int left = 0;
				int up = 0;
				if (i > 0) {
					up = dp[j];
				}
				if (j > 0) {
					left = dp[j - 1];
				}
				dp[j] = (up < left ? up : left) + grid[i][j];
			}
		}
		return dp[col - 1];
	}
};