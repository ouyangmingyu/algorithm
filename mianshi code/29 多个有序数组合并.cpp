#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void res29(vector<vector<int>>& v)
{
	int len = v.size();


	vector<int> res;

	vector<int> p(len, 0);

	vector<int> len1(len, 0);

	for (int i = 0; i < len; i++) {
		len1[i] = v[i].size();
	}

	int minval = INT_MAX;
	int min = INT_MAX;

	bool flag = false;


	while (true) {
		for (int i = 0; i < len; i++) {
			flag = (p[i] != len1[i]) || flag;
		}
		if (flag == false) {
			break;
		}
		else {
			flag = false;
		}
		for (int i = 0; i < len; i++) {
			if (p[i] == len1[i]) {
				continue;
			}
			if (v[i][p[i]] < minval) {
				minval = v[i][p[i]];
				min = i;
			}
		}
		res.push_back(minval);
		p[min]++;
		minval = INT_MAX;
		min = INT_MAX;
	}

	for_each(res.begin(), res.end(),[](int num) {cout << num<<" " ; });
}



int main29() {

	vector<vector<int>> v1 = { {1,3,5,7,9},{2,4,6,8,10,11 },{12,13,14,18},{1,4,6,8,9} };
	
	res29(v1);

	system("pause");
	return EXIT_SUCCESS;
}

