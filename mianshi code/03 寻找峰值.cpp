#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int FindTopVal(int* a,int len)
{
	if (a == nullptr || len <= 0) {
		throw new exception("��������");
	}
	if (len == 1) {
		throw new exception("�������С����1������");
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
	cout << "�����ڷ�ֵ" << endl;
	return -1;
}

int main03() {
	int a[3] = { 0 };
	int len = sizeof(a)/sizeof(a[0]);
	for (int i = 0; i < len; i++) {
		cin >> a[i];
	}


	cout << "��ֵΪ" << FindTopVal(a, len);
	cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}