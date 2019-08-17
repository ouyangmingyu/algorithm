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
	bool is_legal(int map_s[], int map_t[], vector<int> vec_c) {
		int len = vec_c.size();
		for (int i = 0; i <len; i++) {
			if (map_s[vec_c[i]] < map_t[vec_c[i]]) {
				return false;
			}
		}
		return true;
	}
	string minWindow(string s, string t) {
		int lens = s.size();
		int lent = t.size();
		int map_s[128] = { 0 };
		int map_t[128] = { 0 };
		vector<int> vec_c;
		for (int i = 0; i < lent; i++) {
			map_t[t[i]]++;
		}
		for (int i = 0; i < 128; i++) {
			if (map_t[i] > 0) {
				vec_c.push_back(i);
			}
		}
		int begin = 0;
		string res;
		for (int i = 0; i < lens; i++) {
			map_s[s[i]]++;
			while (begin < i) {
				char beg_char = s[begin];
				if (map_t[beg_char] == 0) {
					begin++;
				}
				else if (map_s[beg_char] > map_t[beg_char]) {
					map_s[beg_char]--;
					begin++;
				}
				else {
					break;
				}
			}
			if (is_legal(map_s, map_t, vec_c)) {
				int new_len = i - begin + 1;
				if (res == "" || new_len < res.size()) {
					res = s.substr(begin, new_len);
				}
			}
		}
		return  res;
	}
};

//int main()
//{
//	Solution s;
//	cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
//	system("pause");
//	return 0;
//}