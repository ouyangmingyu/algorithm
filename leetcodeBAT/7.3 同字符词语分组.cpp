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
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		int len = strs.size();
		map<string, vector<string>> m;
		for (int i = 0; i < len; i++) {
			string str = strs[i];
			sort(str.begin(), str.end());
			m[str].push_back(strs[i]);
		}
		for (auto i = m.begin(); i != m.end(); i++) {
			res.push_back((*i).second);
		}
		return res;
	}
};