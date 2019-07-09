#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;


double Pow(double base, int ex)
{
	if (ex == 0) {
		return 1;
	}
	if (ex == 1) {
		return base;
	}
	double res = 1.0;
	res = Pow(base, ex >>1)*Pow(base, ex >> 1);
	if (ex&0x1 == 1) {
		res *= base;
	}
	return res;
}




int main35() {


	cout << Pow(2.0, 9) << endl;
	system("pause");
	return EXIT_SUCCESS;
}

