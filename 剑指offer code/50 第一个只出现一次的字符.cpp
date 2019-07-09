#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

void res50(string s)
{
	map<char, int> m;
	for (char i = 'a'; i <= 'z'; i++) {
		m[i] = 0;
	}

	int len = s.size();
	for (int i = 0; i < len; i++) {
		m[s[i]]++;
	}

	for (int i = 0; i < len; i++) {
		if (m[s[i]] == 1) {
			cout << s[i] << endl;
			break;
		}
	}
}


int tmain54()
{
	res50("abaccdeff");
	system("pause");
	return EXIT_SUCCESS;
}