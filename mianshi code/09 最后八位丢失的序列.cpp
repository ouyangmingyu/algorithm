#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//Œª‘ÀÀ„
char xulie(vector<int>& v, int step)
{
	unsigned char res = 0;
	unsigned char b = 1;
	int ori[8] = { 0 };
	ori[7] = *(v.end() - 1);
	for (int i = 6; i >= 0; i--) {
		ori[i] = ori[i + 1] - step;
	}
	bool flag = false;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < v.size(); j++) {
			if (v[j] == ori[i]) {
				break;
			}
			if (j == v.size() - 1) {
				res |= (b << (7 - i));
			}
		}
	}
	return res;
}

int main09()
{
	int num;
	vector<int> v;
	cin >> num;
	int ele;
	for (int i = 0; i < num; i++) {
		cin >> ele;
		v.push_back(ele);
	}
	int step;
	cin >> step;
	int res = xulie(v, step);
	cout << res;
	system("pause");
	return EXIT_SUCCESS;
}