#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void res26(string s)
{
	int len = s.size();
	if (len <= 0) {
		cout << "false" << endl;
	}
	//�ж��Ƿ�ż����
	if (len % 2 == 1) {
		cout << "false" << endl;
		return;
	}
	//�ж϶Գ�
	for (int i = 0; i < len / 2; i++) {
		//�жϵ��Գ�
		if (s[i] != s[len - 1 - i]) {
			cout << "false" << endl;
			return;
		}
		//�ж�˫�Գ�
		if (i % 2 == 0) {
			if (s[i] != s[i + 1]) {
				cout << "false" << endl;
				return;
			}
		}
	}
	for (int i = 0; i < len; i++) {
		cout << s[i];
		i++;
	}
	cout << endl;
}

int main26()
{
	string s;
	while (cin >> s) {
		res26(s);
	}
	system("pause");
	return 0;
}