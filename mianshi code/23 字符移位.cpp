//СQ���������һ�����⣺��һ���ַ����Ĵ�д��ĸ�ŵ��ַ����ĺ��棬�����ַ������λ�ò��䣬�Ҳ����������Ŀռ䡣
#include<iostream>
#include<string>
#include<vector>

using namespace std;


void zizuyiwei(string& s)
{
	int len = s.size();
	for (int i = 0; i < len; ++i) {
		if (!(s[i] >= 'A'&&s[i] <= 'Z')) {
			cout << s[i];
			s[i] = -1;
		}
	}
	int len2 = s.size();
	for (int i = 0; i < len2; ++i) {
		if (s[i] != -1) {
			cout << s[i];
		}
	}
	cout << endl;
}

int main23()
{
	string s;
	while (cin >> s)
	{
		zizuyiwei(s);
	}
	system("pause");
	return 0;
}