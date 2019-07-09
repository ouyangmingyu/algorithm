#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

void res57t1(vector<int>& v,int sum)
{
	int len = v.size();
	int big = len-1;
	int small = 0;
	
	while (small < big) {
		if (v[small] + v[big] == sum) {
			cout << "这两个数是" << v[small] << "和" << v[big] << endl;
			break;
		}
		if (v[small] + v[big] > sum) {
			big--;
		}
		if (v[small] + v[big] < sum) {
			small++;
		}
		if (small == big) {
			cout << "没找到" << endl;
			break;
		}
	}
}

void res57t2(int sum)
{
	int small = 1, big = 2;
	int mid = sum / 2;
	int tmp = small+big;
	while (true) {
		if (small > mid || big > sum) {
			break;
		}
		if (tmp == sum) {
			for (int i = small; i <= big; i++) {
				cout << i << " ";
			}
			cout << endl;
			big++;
			tmp += big;
			continue;
		}
		if (tmp > sum) {
			tmp -= small;
			small++;
			continue;
		}
		if (tmp < sum) {
			big++;
			tmp += big;
			continue;
		}
	}

}


int main57()
{
	/*vector<int> v = { 1,2,4,7,11,15 };
	res57t1(v,50);*/
	res57t2(15);
	system("pause");
	return EXIT_SUCCESS;
}