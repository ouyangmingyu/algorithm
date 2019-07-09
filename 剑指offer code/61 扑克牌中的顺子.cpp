#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

bool  res61(vector<int> v)
{
	int len = v.size();

	sort(v.begin(), v.end());

	int vacant=0;

	if (v[0] == 0 && v[1] != 0) {
		for (int i = 2; i < len; i++) {
			vacant += (v[i] - v[i - 1] - 1);
		}
		if (vacant <= 1) {
			return true;
		}
		else {
			return false;
		}
	}
	if (v[0] == 0 && v[1] == 0) {
		for (int i = 3; i < len; i++) {
			vacant += (v[i] - v[i - 1] - 1);
		}
		if (vacant <= 2) {
			return true;
		}
		else {
			return false;
		}
	}
	if (v[0] != 0 && v[1] != 0) {
		for (int i = 1; i < len; i++) {
			if (v[i] - v[i - 1] > 1) {
				return false;
			}
		}
		return true;
	}
	return false;
}


int main61()
{
	vector<int> v = {0,1,4,5,0};

	if (res61(v)) {
		cout << "是一个顺子" << endl;
	}
	else {
		cout<< "不是一个顺子" << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}