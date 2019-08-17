#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<list>
#include<map>
#include "zx.h"

using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		map<char, int> m;
		int len = s.size();
		int res = 0;
		for (int i = 0; i < len; i++) {
			m[s[i]]++;
		}
		bool flag = false;
		for (auto i = m.begin(); i != m.end(); i++) {
			if ((*i).second % 2 == 0) {
				res += (*i).second;
			}
			else {
				res += (*i).second-1;
				flag = true;
			}
		}
		if (flag == true) {
			res++;
		}
		return res;
	}
};

