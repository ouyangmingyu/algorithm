#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>

using namespace std;

pair<char, int> biggest(map<char, int>& m)
{
	pair<char, int> max = { 0,0 };
	for (auto e : m) {
		if (e.second > max.second) {
			max = e;
		}
	}
	return max;
}

string paidui(const string& s)
{
	map<char, int> m;
	string res;

	for (auto c : s) {
		m[c]++;
	}
	int k = m.size();

	pair<char, int> ele;
	ele = biggest(m);
	
	res+=ele.first;
	m[ele.first]--;
	char lastele = ele.first;

	while (res.size() < s.size()) {
		ele = biggest(m);
		if (ele.first == lastele) {
			map<char, int> tmp = m;
			tmp.erase(lastele);
			ele = biggest(tmp);
			res += ele.first;
			lastele = ele.first;
			m[ele.first]--;
		}
		else {
			ele = biggest(m);
			res += ele.first;
			lastele = ele.first;
			m[ele.first]--;
		}
	}

	cout << endl;
	return res;
}


int main15()
{
	string s;
	getline(cin, s);

	string res = paidui(s);

	cout << res << endl;
	system("pause");
	return 0;
}
