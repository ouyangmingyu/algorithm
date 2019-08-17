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
	int lengthOfLongestSubstring(string s) {
		int map[128] = { 0 };
		int res = 0;
		string word;
		int len = s.size();
		int begin = 0;
		int ws = 0;
		for (int i = 0; i < len; i++) {
			map[s[i]]++;
			if (map[s[i]] == 1) {
				word += s[i];
				ws = word.size();
				res = res > ws ? res : ws;
			}
			else {
				word = "";
				while (map[s[i]] > 1 && begin < i) {
					map[s[begin]]--;
					begin++;
				}
				for (int j = begin; j <= i; j++) {
					word += s[j];
				}
			}
		}
		return res;
	}
};


//int main()
//{
//	Solution s;
//	cout << s.lengthOfLongestSubstring("pwwkew") << endl;
//	system("pause");
//	return 0;
//}