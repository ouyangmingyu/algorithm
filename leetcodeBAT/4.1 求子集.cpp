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
	vector<vector<int>> subsets(vector<int>& candidates,int target) {
		len = candidates.size();
		if (len == 0) {
			return res;
		}
		targets = target;
		sort(candidates.begin(), candidates.end());
		numsv = candidates;
		Backtrace(0);
		return res;
	}
private:
	vector<int> cur;
	int targets;
	vector<vector<int>> res;
	set<vector<int>> res_set;
	int len;
	vector<int> numsv;
	int sum;
	void Backtrace(int i) {
		if (i == len) {
			if ((find(res_set.begin(), res_set.end(), cur) == res_set.end())&&sum==targets) {
				res_set.insert(cur);
				res.push_back(cur);
			}
			return;
		}
		sum += numsv[i];
		if (sum <=targets ) {
			cur.push_back(numsv[i]);
			Backtrace(i + 1);
		}
		if (sum <= targets) {
			cur.pop_back();
		}
		sum -= numsv[i];
		
		Backtrace(i + 1);
	}
};

class Solution2 {
public:
	vector<vector<int>> subsets(vector<int>& candidates) {
		int len = candidates.size();
		int all = 1 << len;
		vector<vector<int>> res;
		for (int i = 0; i < all; i++) {
			vector<int> cur;
			for (int j = 0; j < len; j++) {
				if (i&(1<<j)) {
					cur.push_back(candidates[j]);
				}
			}
			res.push_back(cur);
		}
		return res;
	}
};