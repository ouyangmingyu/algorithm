#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>

using namespace std;


//利用滑动窗口
int fangshi(int num, string& s)
{
	if (num <= 0 || s.empty()) {
		return -1;
	}
	int len = s.size();
	int cnt = 0;
	int max = 0;
	//找到最大连续1的个数（修改以后）
	for (int i = 1; i <= len; i++) {
		for (auto it = s.begin(); it < (s.end()-i+1); it++) {
			cnt = count(it, it + i, '0');
			if (cnt<=num) {
				max = i;
				break;
			}
		}
	}

	int res = 0;
	//找出有多少种方式使得达到最大数目的1
	for (auto it = s.begin(); it < (s.end() - max + 1); it++) {
		cnt= count(it, it + max, '0');
		if (cnt <= num) {
			res++;
		}
	}
	return res;
}


int main14()
{
	string s;
	int num;

	getline(cin, s);
	cin >> num;

	int m = fangshi(num, s);


	cout << m << endl;

	system("pause");
	return 0;
}