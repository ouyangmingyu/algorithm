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
	bool wordPattern(string pattern, string str) {
		map<string, char> m;
		int lenp = pattern.size();
		str += ' ';
		int lens = str.size();
		string tmp;
		int index = 0;
		for (int i = 0; i < lens; i++) {
			if (str[i] == ' ') {
				auto it = m.find(tmp);
				if (it==m.end()) {
					if (index >= lenp) {
						return false;
					}
					m[tmp] = pattern[index++];
					tmp = "";
				}
				else {
					if ((*it).second != pattern[index]) {
						return false;
					}
					index++;
				}
			}
			else {
				tmp += str[i];
			}
		}
		if (index < lenp - 1) {
			return false;
		}
		return true;
	}
};