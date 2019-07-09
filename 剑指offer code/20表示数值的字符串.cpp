#include<iostream>
#include<string>
#include<stack>

using namespace std;

//bool BiaoShiShu(const string& s)
//{
//	if (s.size()) {
//		return false;
//	}
//	int len = s.size();
//	//for (int i = 0; i < len; i++) {
//	//	if (s[i] == '+' || s[i] == '-' || (s[i] > '0'&&s[i] < '9') {
//
//	//	}
//	//	if()
//	//}
//
//	if (s[0] == '+' || s[0] == '-' || (s[0] > '0'&&s[0] < '9')||s[0]=='.') {
//		//有整数部分的情况
//		if (s[0] == '+' || s[0] == '-' || (s[0] > '0'&&s[0] < '9')) {
//			for (int i = 1; i < len; i++) {
//				if ((s[i] > '0'&&s[i] < '9')) {
//					continue;
//				}
//				if (s[i] == 'E' || s[i] == 'e') {
//					for (int j = i + 1; j < len; j++) {
//						if (s[i + 1] == '+' || s[i + 1] == '-') {
//							continue;
//						}
//						if (!(s[j] > '0'&&s[j] < '9')) {
//							return false;
//						}
//						if (j == len - 1) {
//							return true;
//						}
//					}
//				}
//				if (s[i] == '.') {
//					for (int j = i + 1; j < len; j++) {
//						if (s[j] == '.') {
//							return false;
//						}
//						if (s[j] > '0'&&s[j] < '9') {
//							continue;
//						}
//						if (s[j] == 'E' || s[j] == 'e') {
//							for (int k = j + 1; k < len; k++) {
//								if (s[j + 1] == '+' || s[j + 1] == '-') {
//									continue;
//								}
//								if (!(s[k] > '0'&&s[k] < '9')) {
//									return false;
//								}
//								if (k == len - 1) {
//									return true;
//								}
//							}
//						}
//						if (j == len - 1) {
//							return true;
//						}
//					}
//				}
//			}
//		}
//		if (s[0] == '.') {
//			for (int i = 1; i < len; i++) {
//				if ((s[i] > '0'&&s[i] < '9')) {
//					continue;
//				}
//				if (s[i] == 'E' || s[i] == 'e') {
//					for (int j = i + 1; j < len; j++) {
//						if (s[i + 1] == '+' || s[i + 1] == '-') {
//							continue;
//						}
//						if (!(s[j] > '0'&&s[j] < '9')) {
//							return false;
//						}
//						if (j == len - 1) {
//							return true;
//						}
//					}
//				}
//				return false;
//			}
//		}
//	}
//	return false;
//}


bool isUnsigned(const char*& s)
{
	const char* t = s;
	while (*s >= '0'&&*s <= '9') {
		++s;
	}
	if (s > t) {
		return true;
	}
	return false;
}

bool isSigned(const char*& s) {
	if (*s == '+' || *s == '-') {
		++s;
	}
	bool  isS= isUnsigned(s);
	return   isS;
}




bool isNum(const char*& s)
{
	if (s == nullptr) {
		return false;
	}
	bool isnum = isSigned(s);
	if (*s == '.') {
		++s;
		isnum = isnum||isUnsigned(s);
	}

	if (*s == 'e' || *s == 'E') {
		++s;
		isnum = isnum&&isSigned(s);
	}
	return isnum&&(*s=='\0');
}


int main24()
{
	const char* s = ".23e+2";

	if (isNum(s)) {
		cout << "1" << endl;
	}
	else {
		cout << "0" << endl;
	}
	
	system("pause");
	return EXIT_SUCCESS;
}