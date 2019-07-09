#include <iostream>
#include <cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main17()
{
	vector<string> s;
	while (true) {
		if (cin.peek() == '\n') {
			if (cin.peek() == '\n') {
				break;
			}
		}
		string s1;
		getline(cin, s1);
		s.push_back(s1);
	}

	vector<string> hf;
	vector<string> ff;

	for (auto e : s) {
		int len = e.size();
		for (int i = 0; i < len; i++) {
			if (!((e[i] >= '0'&&e[i] <= '9') || (e[i] >= 'a'&&e[i] <= 'z') || (e[i] >= 'A'&&e[i] <= 'Z'))) {
				ff.push_back(e);
				break;
			}
			if (i == len - 1) {
				hf.push_back(e);
			}
		}
	}

	int len1 = hf.size();

	map<string, int> m;

	for (auto e : hf) {
		m[e]++;
	}
	vector<string> hft;

	for (auto e : hf) {
		if (m[e] != -1) {
			hft.push_back(e);
			m[e] = -1;
		}
	}

	for_each(hft.begin(), hft.end(), [](string s) {cout << s << " "; });
	cout << endl;

	for_each(ff.begin(), ff.end(), [](string s) {cout << s << " "; });
	cout << endl;

	int k = 0;
	for (auto e : hft) {
		int len = e.size();
		for (int j = 0; j < 10; j++) {
			char s = e[0];
			for (int i = 1; i < len; i++) {
				e[i - 1] = e[i];
			}
			e[len - 1] = s;
		}
		hft[k] = e;
		k++;
	}

	for_each(hft.begin(), hft.end(), [](string s) {cout << s << " "; });
	cout << endl;


	for (int i = 0; i < hft.size(); i++) {
		sort(hft[i].begin(), hft[i].end());
	}

	for_each(hft.begin(), hft.end(), [](string s) {cout << s << " "; });
	cout << endl;


	system("pause");
	return 0;
}