#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

int res46(string& s,int index,int len)
{
	//ตÝน้
	/*if (index == len - 1) {
		return 1;
	}
	if (index == len - 2) {
		int val = (s[index + 1] - '0') + ((s[index] - '0') * 10);
		if (val >= 10 && val <= 25) {
			return 2;
		}
		else {
			return 1;
		}
	}
	int val = (s[index + 1] - '0') + ((s[index] - '0') * 10);
	if (val >= 10 && val <= 25) {
		return res46(s, index + 1, len) + res46(s, index + 2, len);
	}
	else {
		return res46(s, index + 1, len);
	}*/

	vector<int> counts(len, 0);

	for (int i = len - 1; i >= 0; i--) {
		if (i == len - 1) {
			counts[i] = 1;
			continue;
		}
		if (i == len - 2) {
			int val = (s[i + 1] - '0') + ((s[i] - '0') * 10);
			if (val >= 10 && val <= 25) {
				counts[i] = 2;
			}
			else {
				counts[i] = 1;
			}
			continue;
		}
		int val = (s[i + 1] - '0') + ((s[i] - '0') * 10);
		if (val >= 10 && val <= 25) {
			counts[i] = counts[i + 1] + counts[i + 2];
		}
		else {
			counts[i] = counts[i + 1];
		}
	}
	return counts[0];
}


int main50()
{
	string s = "12258";

	int num = 12345;

	
	cout << res46(s, 0, s.size()) << endl;
	system("pause");
	return EXIT_SUCCESS;
}