#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

void res56t1(vector<int>& v)
{
	int num1 = 0,num2=0;
	int tmp = 0;
	int len = v.size();
	for (int i = 0; i < len; i++) {
		tmp ^= v[i];
	}
	unsigned int tmp1 = 1;
	while (true) {
		if ((tmp1&tmp) != 0) {
			tmp1 &= tmp;
			break;
		}
		tmp1 <<= 1;
	}
	for (int i = 0; i < len; i++) {
		if ((v[i] & tmp1) == 0) {
			num1 ^= v[i];
		}
		else {
			num2 ^= v[i];
		}
	}
	cout << "不同的两个数是：" << num1 << "和" << num2 << endl;
}

void res56t2(vector<int>& v)
{
	unsigned int tmp1 = 1;
	int res=0;
	int len = v.size();
	int tmp2 = 0,tmp3=0;

	for (int i = 0; i < 32; i++) {
		tmp2 = 0;
		for (int i = 0; i < len; i++) {
			if ((v[i] & tmp1) != 0) {
				tmp2++;
			}
		}
		tmp3 = tmp2 % 3;
		if (tmp3 == 0) {
			tmp1 <<= 1;
		}
		else {
			res |= tmp1;
			tmp1 <<= 1;
		}
	}
	cout << "唯一不同的数是" << res << endl;
}


int main56()
{
	vector<int> v = { 1,2,1,2,1,2,5,3,3,3 };
	res56t2(v);
	system("pause");
	return EXIT_SUCCESS;
}