#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>

using namespace std;


int head_equal_tail(char** ch,int num)
{
	if (num <= 0 || ch == nullptr) {
		return -1;
	}

	if (num == 1) {
		return 1;
	}

	if (num == 2) {
		int len = strlen(ch[0]);
		if (ch[0][len - 1] == ch[1][0]) {
			return 1;
		}
		else {
			return -1;
		}
	}

	for (int i = 0; i < num; i++) {
		if (i == 0) {
			int len = strlen(ch[i]);
			if (ch[i][len - 1] != ch[i + 1][0]) {
				return -1;
			}
		}else if (i == num - 1) {
			int len = strlen(ch[i-1]);
			if (ch[i][0] != ch[i - 1][len-1]) {
				return -1;
			}
		}
		else {
			int len = strlen(ch[i - 1]);
			if (ch[i][len - 1] != ch[i + 1][0]) {
				return -1;
			}
		}


		if (i == num - 1) {
			return 1;
		}
	}

	return -1;
}

int main12()
{
	char* ch[10] = {"abc","cdf","fgh","hij"};


	if (head_equal_tail(ch,3) == 1) {
		cout << "是首首尾相同的" << endl;
	}
	if (head_equal_tail(ch,3) == -1) {
		cout << "不是首尾相同的" << endl;
	}
	system("pause");
	return 0;
}
