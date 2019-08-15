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
	int findContentChildren(vector<int>& g, vector<int>& s) {
		int leng = g.size();
		int lens = s.size();
		int res = 0;
		int i = 0;
		int j = 0;
		sort(g.begin(),g.end());
		sort(s.begin(), s.end());
		while (i < leng&&j < lens) {
			if (s[j] >= g[i]) {
				res++;
				i++;
				j++;
			}
			else {
				j++;
			}
		}
		return res;
	}
};