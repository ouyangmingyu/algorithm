#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>

using namespace std;


int minpro(int num, int p, int q, vector<int>& s)
{
	

	set<int> st;
	int cnt = 0;
	while (st.size()!=num) {
		int max = 0;
		for (int i = 0; i < num; i++) {
			if (s[max] < s[i]) {
				max = i;
			}
		}

		s[max] = (s[max] - p) > 0 ? (s[max] - p) : 0;

		for (int i = 0; i < num; i++) {
			if (i != max&&s[i] != 0) {
				s[i] = (s[i] - q) > 0 ? (s[i] - q) : 0;
			}
			if (s[i] == 0) {
				st.insert(i);
			}
		}
		cnt++;
	}
	return cnt;
}


int main13()
{
	int num, p, q;
	vector<int> v;

	cin >> num >> p >> q;

	while (cin.peek() != '\n') {
		int num;
		cin >> num;
		v.push_back(num);
	}

	cout << minpro(num, p, q, v);
	cout << endl;

	system("pause");
	return 0;
}