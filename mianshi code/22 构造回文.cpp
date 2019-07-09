#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>

using namespace std;


int gouzaohuiwen(string& s)
{
	int min = 0;
	int len = s.size();
	string sr = s;

	int v[1010][1010] = { 0 };

	reverse(sr.begin(), sr.end());

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (s[i] == sr[j]) {
				v[i + 1][j + 1] = v[i][j] + 1;
			}
			else {
				v[i + 1][j + 1] = v[i + 1][j] > v[i][j + 1] ? v[i + 1][j] : v[i][j + 1];
			}
		}
	}


	return len - v[len][len];
}



int main22()
{
	string s;
	while (cin >> s) {
		cout << gouzaohuiwen(s);
	}

	system("pause");
	return 0;
}