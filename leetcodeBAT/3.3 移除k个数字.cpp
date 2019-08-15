#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<functional>
#include<queue>
#include<queue>
#include<stack>

using namespace std;

class Solution {
public:
	string removeKdigits(string num, int k) {
		deque<int> d;
		string res = "";
		int len = num.size();
		for (int i = 0; i < len; i++) {
			int number = num[i] - '0';
			while (d.size() && number < d.back() && k) {
				d.pop_back();
				k--;
			}
			//解决0
			if (number || d.size()) {
				d.push_back(number);
			}
		}
		//仍然没有删除完了
		while (k) {
			d.pop_back();
			k--;
		}
		len = d.size();
		for (int i = 0; i < len; i++) {
			res += d[i] + '0';
		}
		return res;
	}
};