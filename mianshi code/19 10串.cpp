#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int res2(int len, string& s)
{
	int res = 0;

	int i = 0;
	while ((i != len - 1) && (len != 0)) {
		if (s[i] ^ s[i + 1]) {
			s.erase(i, 2);
			len = s.size();
			if (i > 0) {
				i -= 1;
			}
			continue;
		}
		i++;
	}
	return s.size();
}

int main19()
{
	int len;
	string s;
	cin >> len;
	cin >> s;

	cout << res2(len, s) << endl;
	system("pause");
	return 0;
}