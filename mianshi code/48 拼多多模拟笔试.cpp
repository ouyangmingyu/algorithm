#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<limits.h>
#include<exception>
#include<queue>
#include<functional>


using namespace std;

//1 给定一个无序数组，包含正数、负数和0，要求从中找出3个数的乘积，使得乘积最大，要求时间复杂度：O(n)，空间复杂度：O(1)

long long max3mul(vector<int> v) {
	int len = v.size();
	if (len < 3) {
		return INT_MIN;
	}
	//保存最大的三个数
	priority_queue<long long, vector<long long>, greater<long long>> min;
	//保存最小的两个数
	priority_queue<long long, vector<long long>, less<long long>> max;

	min.push(v[0]);
	max.push(v[0]);

	for (int i = 1; i < len; i++) {
		if (min.size() < 3) {
			min.push(v[i]);
		}
		else {
			if (v[i] > min.top()) {
				min.pop();
				min.push(v[i]);
			}
		}
		if (max.size() < 2) {
			max.push(v[i]);
		}
		else {
			if (v[i] < max.top()) {
				max.pop();
				max.push(v[i]);
			}
		}
	}
	vector<long long> min2(2, 0);
	vector<long long> max3(3, 0);

	min2[1] = max.top();
	max.pop();
	min2[0] = max.top();

	max3[0] = min.top();
	min.pop();
	max3[1] = min.top();
	min.pop();
	max3[2] = min.top();

	long long maxres = INT_MIN;

	maxres = maxres > (max3[0] * max3[1] * max3[2]) ? maxres : (max3[0] * max3[1] * max3[2]);
	maxres = maxres > (max3[2] * min2[0] * min2[1]) ? maxres : (max3[2] * min2[0] * min2[1]);

	return maxres;
}

//2 有两个用字符串表示的非常大的大整数,算出他们的乘积，也是用字符串表示。不能用系统自带的大整数类型。
//string bigmul(string s1, string s2) {
//
//}



int mainpdd() {
	string s1;
	string s2;

	cin >> s1 >> s2;
	//cout << bigmul(s1, s2) << endl;

	system("pause");
	return EXIT_SUCCESS;
}

