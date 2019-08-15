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

using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int nv) {
		n = nv;
		cur = vector<string>(n, string(n,'.'));
		x = vector<int>(n, 0);
		Backtrace(0);
		return res;
	}

private:
	int n;
	vector<string> cur;
	vector<vector<string>> res;
	vector<int> x;
	void Backtrace(int t) {
		if (t == n) {
			res.push_back(cur);
			return;
		}
		for (int i = 0; i < n; i++) {
			cur[t][i] = 'Q';
			x[t] = i;
			if (islegal(t)) Backtrace(t + 1);
			cur[t][i] = '.';
		}
	}
	bool islegal(int k) {
		for (int i = 0; i < k; i++) {
			if (abs(i - k) == abs(x[i] - x[k])||(x[i]==x[k])) return false;
		}
		return true;
	}
};

//int main()
//{
//	Solution s;
//	vector<vector<string>> res=s.solveNQueens(4);
//	system("pause");
//	return 0;
//}