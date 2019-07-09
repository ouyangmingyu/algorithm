#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int FindTopVal(int* a,int len)
{
	if (a == nullptr || len <= 0) {
		throw new exception("输入有误");
	}
	if (len == 1) {
		throw new exception("请输入大小大于1的数组");
	}
	for (int i = 0; i < len; i++) {
		if (i == 0) {
			if (a[i] > a[i + 1]) {
				return a[i];
			}
		}
		if (i == len-1) {
			if (a[i] > a[i - 1]) {
				return a[i];
			}
		}
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
			return a[i];
		}
	}
	cout << "不存在峰值" << endl;
	return -1;
}

int main03() {
	int a[3] = { 0 };
	int len = sizeof(a)/sizeof(a[0]);
	for (int i = 0; i < len; i++) {
		cin >> a[i];
	}


	cout << "峰值为" << FindTopVal(a, len);
	cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}