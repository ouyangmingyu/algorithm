#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>

using namespace std;


//ǰ�����￿£�Ա�

bool ishuiwen(const string s)
{
	if (s.size() == 0) {
		throw new exception("�����˿��ַ���");
	}
	int len = s.size();
	for (int i = 0; i < len/2; i++) {
		if (s[i] != s[len - 1 - i]) {
			return false;
		}
	}
	return true;
}

vector<string> huiwenshu(const string& s)
{
	vector<string> sv;

	int len = s.size();

	for (int i = 0; i < len; i++) {
		for (int j = 1; j <= len-i; j++) {
			string s1(s, i, j);
			cout << s1 << endl;
			if (ishuiwen(s1)) {
				sv.push_back(s1);
			}
		}
	}
	return sv;
}


int main06()
{
	vector<string> sv;
	string s ;
	cin >> s;

	sv = huiwenshu(s);

	for (auto x : sv) {
		cout << x << " ";
	}
	cout << endl;

	//if (ishuiwen("a")) {
	//	cout << "������" << endl;
	//}

	system("pause");
	return 0;
}