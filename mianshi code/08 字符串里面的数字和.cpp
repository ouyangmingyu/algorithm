#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


//从后往前看
using namespace std;

int count_sum(char* str)
{
	if (str == nullptr) {
		return 0;
	}
	vector<int>  num;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] > '0'&&str[i] <= '9') {
			num.push_back(str[i] - '0');
		}
		if (str[i] == '-') {
			if (i < len - 1 && (str[i + 1] > '0'&&str[i + 1] <= '9')) {
				num.push_back(-(str[i + 1] - '0'));
				i++;
			}
		}
	}
	int lena = num.size();
	int lenb = lena;
	for (int i = lena - 1; i >= 0; i--) {
		if (num[i] < 0 && i>0) {
			num[i - 1] = num[i - 1] + num[i];
			num[i] = 0;
			lenb--;
		}
	}
	for (int j = 0; j < lenb; j++) {
		cout << num[j];
	}
	cout << endl;
	return 0;
}

int main08()
{
	string str;
	getline(cin, str);
	cout << str << endl;
	system("pause");
	return EXIT_SUCCESS;
}