#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

#include "zx.h"

using namespace std;

class solution0 {
public:
	static int longestzc(string s1,string s2)
	{
		int len1 = s1.size();
		
		int len2 = s2.size();
		
		vector<vector<int>> v(len1+1, vector<int>(len2+1, 0));
		vector<vector<int>> b(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 1; i <= len1; i++) {
			for (int j = 1; j <= len2; j++) {
				if (s1[i-1] == s2[j-1]) {
					v[i][j] = v[i - 1][j - 1] + 1;
					b[i][j] = 1;
				}
				else {
					if (v[i - 1][j] >= v[i][j - 1]) {
						v[i][j] = v[i - 1][j];
						b[i][j] = 2;
					}
					else {
						v[i][j] = v[i][j - 1];
						b[i][j] = 3;
					}
				}
			}
		}
		
		for (int i = 0; i <= len1; i++) {
			for (int j = 0; j <= len2; j++) {
				cout << b[i][j] << " ";
			}
			cout << endl;
		}

		string s;
		for (int i = len1, j = len2; i > 0 && j > 0;) {
			if (b[i][j] == 1) {
				s += s1[i-1];
				i--;
				j--;
			}
			if (b[i][j] == 2) {
				i--;
			}
			if (b[i][j] == 3) {
				j--;
			}
		}
		reverse(s.begin(), s.end());
		cout << s << endl;
		return v[len1][len2];
	}
};





int main42() {
	cout << solution0::longestzc("google", "gsdaoogle") << endl;
	system("pause");
	return EXIT_SUCCESS;
}

