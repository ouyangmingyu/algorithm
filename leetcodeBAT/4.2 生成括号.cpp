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
	vector<string> generateParenthesis(int n) {
		left = n;
		right = n;
		Backtrace(0);
		return res;
	}

private:
	int left;
	int right;
	vector<string> res;
	string cur;
	void Backtrace(int i) {
		if (left == 0 && right == 0) {
			res.push_back(cur);
			return;
		}
		if (left > 0) {
			cur += '(';
			left--;
			Backtrace(i + 1);
			left++;
			cur.erase(cur.size() - 1, 1);
		}
		if (right > left) {
			cur += '(';
			right--;
			Backtrace(i + 1);
			right++;
			cur.erase(cur.size() - 1, 1);
		}
	}
};