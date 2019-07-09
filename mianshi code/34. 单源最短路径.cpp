#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;


vector<vector<int>> c = {
						{0      ,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX },
						{INT_MAX,0      ,10     ,INT_MAX,30     ,100     },
						{INT_MAX,INT_MAX,0      ,50     ,INT_MAX,INT_MAX },
						{INT_MAX,INT_MAX,INT_MAX,0      ,INT_MAX,10      },
						{INT_MAX,INT_MAX,INT_MAX,20     ,0      ,60      },
						{INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,0       },
};

void DJK(vector<vector<int>> c, int s,vector<int>& d, vector<int>& pre)
{
	int len = d.size();
	vector<bool> flag(len, false);
	flag[s] = true;
	for (int i = 1; i < len; i++) {
		d[i] = c[s][i];
		if (d[i] == INT_MAX)
			pre[i] = 0;
		else
			pre[i] = s;
	}

	for (int i = 1; i < len; i++) {
		int minval = INT_MAX;
		int n = s;
		for (int j = 1; j < len; j++) {
			if (!flag[j] && d[j] < minval)
			{
				minval = d[j];
				n = j;
			}
		}
		flag[n] = true;

		for (int j = 1; j < len; j++) {
			if (!flag[j]&&c[n][j]<INT_MAX) {//一定要判断，不判断的话下面有溢出问题 INT_MAX+X会溢出
				if (d[n] + c[n][j] < d[j]) {
					d[j] = d[n] + c[n][j];
					pre[j] = n;
				}
			}
		}
	}
}


int main34() {
	vector<int> d(6, INT_MAX);
	vector<int> pre(6, 0);
	DJK(c, 1, d, pre);

	for_each(d.begin(), d.end(), [](int num) {cout << num << " "; });
	cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}

