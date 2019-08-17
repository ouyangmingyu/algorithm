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
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int rows = dungeon.size();
		if (rows == 0) {
			return 0;
		}
		int cols = dungeon[0].size();
		vector<vector<int>> dp(rows, vector<int>(cols, 0));
		dp[rows - 1][cols - 1] = 1 > (1 - dungeon[rows - 1][cols - 1]) ? 1 : (1 - dungeon[rows - 1][cols - 1]);
		for (int i = cols - 2; i >= 0; i--) {
			dp[rows - 1][i] = 1 > (dp[rows - 1][i + 1] - dungeon[rows - 1][i]) ? 1 : (dp[rows - 1][i + 1] - dungeon[rows - 1][i]);
		}
		for (int i = rows - 2; i >= 0; i--) {
			dp[i][cols - 1] = 1 > (dp[i + 1][cols - 1] - dungeon[i][cols - 1]) ? 1 : (dp[i + 1][cols - 1] - dungeon[i][cols - 1]);
		}
		for (int i = rows - 2; i >= 0; i--) {
			for (int j = cols - 2; j >= 0; j--) {
				int tmp = dp[i + 1][j] < dp[i][j + 1] ? dp[i + 1][j] : dp[i][j + 1];
				dp[i][j] = 1 > tmp - dungeon[i][j] ? 1 : tmp - dungeon[i][j];
			}
		}
		return dp[0][0];
	}
};