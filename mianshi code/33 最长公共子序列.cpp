#include<iostream>
#include<string>
#include<vector>

using namespace std;


void res33(string s1, string s2,string res)
{
	int len1 = s1.size(), len2 = s2.size();
	vector<vector<int>> v(len1,vector<int>(len2,0));

	int maxlen = 0;
	int endindex = 0;
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (s1[i] == s2[j]) {
				if (i == 0 || j == 0) {
					v[i][j] = 1;
				}
				else {
					v[i][j] = v[i - 1][j - 1] + 1;
				}
			}
			if (v[i][j] >= maxlen) {
				maxlen = v[i][j];
				endindex = j;
			}
		}
	}
	res.assign(s2, endindex - maxlen+1, maxlen);
	cout << res << endl;
}

int main33()
{
	string s1 = "abccade";
	string s2 = "dgcadde";

	string res;
	res33(s1, s2,res);
	system("pause");
	return 0;
}