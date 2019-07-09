#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;


double StrtoInt(string s)
{
	int len = s.size();
	double res = 0;
	if (len == 0) {
		throw new exception("�ַ���Ϊ��");
	}
	if (s[0] == '+') {
		if (len == 1){
			throw new exception("�ַ����Ƿ�");
		}
		for (int i = len - 1; i > 0; i--) {
			if (s[i]<'0' || s[i]>'9') {
				throw new exception("�ַ����Ƿ�");
			}
			res += ((s[i] - '0') * pow(10, (len - 1 - i)));
		}
		return res;
	}
	if (s[0] == '-') {
		if (len == 1) {
			throw new exception("�ַ����Ƿ�");
		}
		for (int i = len - 1; i > 0; i--) {
			if (s[i]<'0' || s[i]>'9') {
				throw new exception("�ַ����Ƿ�");
			}
			res += (s[i]-'0') * pow(10, (len - 1 - i));
		}
		res = -res;
		return res;
	}
	for (int i = len - 1; i >= 0; i--) {
		if (s[i]<'0' || s[i]>'9') {
			throw new exception("�ַ����Ƿ�");
		}
		res += (s[i] - '0') * pow(10, (len - 1 - i));
	}
	return res;
}


int main67()
{
	string s = "1a00";
	cout << StrtoInt(s) << endl;
	system("pause");
	return EXIT_SUCCESS;
}