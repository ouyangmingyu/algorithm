#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<math.h>

using namespace std;

void res47(int num)
{
	int tmp = num;
	int ws = 0;
	int res = 0;
	while (true) {
		if (tmp) {
			tmp /= 10;
			ws++;
		}
		else {
			break;
		}
	}
	for (int i = 1; i <= ws; i++) {

	}
}

int zuheshu(int n, int m) {
	int fz=1, fm=1;
	for (int i = 0; i < m; i++) {
		fz *= (n - i);
	}
	for (int i = 1; i <= m; i++) {
		fm *= i;
	}
	return fz / fm;
}


int main47()
{
	int num = 12;
	int tmp = num;
	int ws=0;
	int res=0;
	while (true) {
		if (tmp) {
			ws++;
			tmp /= 10;
		}
		else {
			break;
		}
	}
	int fst = num / (pow(10,ws-1));
	cout << ws << endl;
	cout << fst << endl;
	//分为两段
	//第一段0~2999
	if (fst != 1) {
		//第一位为1
		for (int i = 0; i < ws; i++) {
			res += (i + 1)*zuheshu(ws - 1, i)*pow(9, ws - (i + 1));
		}
		//第一位不为1
		for (int i = 0; i < ws; i++) {
			res += (i)*zuheshu(ws - 1, i)*pow(9, ws - (i + 1))*(fst - 1);
		}
	}
	else {
		for (int i = 0; i < ws; i++) {
			res += (i)*zuheshu(ws - 1, i)*pow(9, ws - (i + 1));
		}
	}
	//第二段3000~3845
	for (int i = fst*pow(10, ws - 1); i <= num; i++) {
		int cnt = 0;
		int num2 = i;
		while (true) {
			if (num2 % 10 == 1) {
				cnt++;	
			}
			num2 /= 10;
			if (num2 == 0) {
				break;
			}
		}
		res += cnt;
	}
	

	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}