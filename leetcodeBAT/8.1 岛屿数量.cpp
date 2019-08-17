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
	void BFS_I(vector<vector<int>>& mask,int n,int m,int i,int j) {
		queue<pair<int, int>> q;
		q.push(make_pair(i, j));
		int dx[4] = { 0,0,-1,1 };
		int dy[4] = { 1,-1,0,0 };
		while (q.size()) {
			pair<int, int> tmp = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int newx = tmp.first + dx[i];
				int newy = tmp.second + dy[i];
				if (newx < 0 || newx >= n || newy < 0 || newy >= m) {
					continue;
				}
				if (mask[newx][newy] == 1) {
					q.push(make_pair(newx, newy));
					mask[newx][newy] = 0;
				}
			}
		}
	}

	int numIslands(vector<vector<char>>& grid) {
		int res = 0;
		int n = grid.size();
		if (n <= 0) {
			return 0;
		}
		int m = grid[0].size();
		vector<vector<int>> mask(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '1') {
					mask[i][j] = 1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mask[i][j]==1) {
					res++;
					BFS_I(mask,n,m,i,j);
				}
			}
		}
		return res;
	}
};












