#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

#include "zx.h"

using namespace std;



class solution {
public:
	bool KMP(string s,string sb) {
		int lens = s.size();
		int lensb = sb.size();
		if (lens <= 0 || lensb <= 0 || lensb > lens) {
			return false;
		}
		vector<int> next(lensb, 0);
		getnext(next, sb);
		next = { -1,0,0,1,2 };
		for_each(next.begin(), next.end(), [](int num) {cout << num << " "; });
		cout << endl;
		int i = 0;
		int j = 0;
		while (i < lens&&j < lensb) {
			if (s[i] == sb[j]) {
				i++;
				j++;
			}
			else {
				if (next[j] == -1) {
					j = 0;
					i++;
				}
				else {
					j = next[j];
				}
			}
			if (j == lensb) {
				return true;
			}
		}
		
		return false;
	}

	void getnext(vector<int>& next, string sb) {
		int len = sb.size();
		next[0] = 0;
		if (len == 1) {
			return;
		}
		for (int i = 1; i < len; i++) {
			int k = next[i - 1];
			while (sb[k] != sb[i] && k != 0) {
				k = next[k-1];
			}
			if (sb[k] == sb[i]) {
				next[i] = k + 1;
			}
			else {
				next[i] = 0;
			}
		}
		for (int i = len - 1; i > 0; i--) {
			next[i] = next[i - 1];
		}
		next[0] = -1;
	}
};





int main45() {
	
	solution sol;

	string s = "cababcc";
	string sb = "ababc";

	if (sol.KMP(s, sb)) {
		cout << "匹配上了" << endl;
	}
	else {
		cout << "没有匹配上" << endl;
	}


	system("pause");
	return EXIT_SUCCESS;
}
