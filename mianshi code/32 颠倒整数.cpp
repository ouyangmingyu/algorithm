#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int res32(int& num)
{
	long long tmp = num;
	
	int cnt = 0;
	
	vector<int> v;

	while (tmp % 10) {
		v.push_back(tmp % 10);
		tmp = tmp / 10;
	}
	int len = v.size();
	long long res = v[len-1];
	for (int i = len-2; i >=0 ; i--) {
		res += 10 * i*v[i];
	}
	cout << res;
	return 0;
}


int main32() {

	int src;
	cin >> src;
	res32(src);
	if (res32(src) == 0) {
		cout << "Ô½½çÁË" << endl;
	}
	else {
		cout << src << endl;
	}
	cout << src << endl;
	system("pause");
	return EXIT_SUCCESS;
}

