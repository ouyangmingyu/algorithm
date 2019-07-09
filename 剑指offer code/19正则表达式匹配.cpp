#include<iostream>
#include<string>
#include<stack>

using namespace std;



bool pipeistr(char* str, char* mode)
{
	if (str == nullptr || mode == nullptr) {
		return false;
	}
	int lens = strlen(str);
	int lenm = strlen(mode);

	if (lens > lenm) {
		return false;
	}

	int j = 0;
	for (int i = 0; i < lens; i++) {
		//��ƥ���λ�üȲ���.Ҳ����*
		if (str[i] != mode[j]&&mode[j]!='.'&&mode[j]!='*') {
			int tmp = j + 1;
			for (int k = tmp; k < lenm-1; k++) {
				if (mode[k] != '*')
					return false;
				if (mode[k + 1] != str[i]&&mode[k+1]!='*')
					return false;
				if (mode[k + 1] == str[i]) {
					j = k + 1;
					break;
				}
				else {
					k++;
				}
			}
		}
		//��ƥ���λ����*
		if (str[i] != mode[j] && mode[j] == '*') {
			int tmp = j + 1;
			for (int k = tmp; k < lenm; k++) {
				if (mode[k] == str[i]) {
					j = k;
					break;
				}
				if (mode[k] != str[i] && mode[k] != '*') {
					return false;
				}
				if (k == lenm) {
					return false;
				}
			}
		}
		j++;
	}
	return true;
}

int main23()
{
	if (pipeistr("aaa", "ab*aa")) {
		cout << "ƥ��ɹ�" << endl;
	}
	else {
		cout << "ƥ��ʧ��" << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}