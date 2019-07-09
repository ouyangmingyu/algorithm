#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

void res(string& s1, string& s2)
{
	vector<string> v1, v2;
	char* ch1 = const_cast<char*>(s1.c_str());
	char* sa = strtok(ch1, ",");
	while (sa != NULL) {
		v1.push_back(sa);
		sa = strtok(NULL, ",");
	}
	char* ch2 = const_cast<char*>(s2.c_str());
	char* sb = strtok(ch2, ",");
	while (sb != NULL) {
		v2.push_back(sb);
		sb = strtok(NULL, ",");
	}
	int v1d = 0, v2d = 0;

	int len1 = v1.size();
	int len2 = v2.size();

	while (true) {
		if (v1d < len1) {
			for (int i = 0; i < 3; i++) {
				if (v1d == len1) {
					break;
				}
				cout << v1[v1d] << " ";
				v1d++;
			}
		}
		if (v2d < len2) {
			for (int i = 0; i < 3; i++) {
				if (v2d == len1) {
					break;
				}
				cout << v2[v2d] << " ";
				v2d++;
			}
		}
		if (v1d == len1&&v2d == len2) {
			break;
		}
	}
	cout << endl;
}

int main16() {
	//freopen("1.in","r",stdin);
	string s1, s2;

	while (cin >> s1) {
		cin >> s2;
		res(s1, s2);

	}
	system("pause");
	return 0;
}