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
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> res;
		int len = s.size();
		if (len < 10) {
			return res;
		}
		map<string,int> m;
		string tmp = s.substr(0, 10);
		m[tmp] = 1;
		for (int i = 10; i < len; i++) {
			tmp.erase(0, 1);
			tmp += s[i];
			m[tmp]++;
		}
		for (auto i = m.begin(); i != m.end(); i++) {
			if ((*i).second > 1) {
				res.push_back((*i).first);
			}
		}
		return res;
	}
};