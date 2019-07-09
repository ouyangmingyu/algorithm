//СQ�������ϲ���ʱ�뵽��������⣺��n������������ɶ�Ԫ�飬�����С���ж��ٶ��أ��������أ�
#include<iostream>
#include<string>
#include<vector>
#include<limits.h>
#include<algorithm>

using namespace std;


void res24(vector<int>& v)
{
	int len = v.size();
	int max = INT_MIN;
	int min = INT_MAX;

	int maxdis = INT_MIN;
	int mindis = INT_MAX;

	int mincnt = 0;
	int maxcnt = 0;

	sort(v.begin(), v.end());

	maxdis = v[len - 1] - v[0];

	for (int i = len - 1; i > -1; i--) {
		if (v[i] - v[0] < maxdis) {
			break;
		}
		if (v[i] - v[0] == maxdis) {
			maxcnt++;
			for (int j = 1; j < i; j++) {
				if (v[i] - v[j] < maxdis) {
					break;
				}
				if (v[i] - v[j] == maxdis) {
					maxcnt++;
				}
			}
		}
	}

	for (int i = 0; i < len - 1; i++) {
		mindis = v[i + 1] - v[i] <= mindis ? v[i + 1] - v[i] : mindis;
	}

	for (int i = 0; i < len - 1; i++) {
		if (v[i + 1] - v[i] == mindis) {
			mincnt++;
			if (i < len - 2) {
				for (int j = i + 2; j < len; j++) {
					if (v[j] == v[i + 1]) {
						mincnt++;
					}
					else {
						break;
					}
				}
			}
		}
	}

	cout << mincnt << " " << maxcnt << endl;
}

int main24()
{
	int cnt;
	while (cin >> cnt) {
		vector<int> v(cnt, 0);
		for (int i = 0; i < cnt; i++) {
			cin >> v[i];
		}
		res24(v);
	}
	system("pause");
	return 0;
}