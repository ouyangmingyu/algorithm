#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

void pailie(vector<int>& v,vector<bool>& used,int n,int m,int pos,vector<int>& res)
{
	if (pos == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (used[i] == false) {
			used[i] = true;
			res[pos] = v[i];
			pailie(v, used, n, m, pos + 1, res);
			used[i] = false;
		}
	}
}


void zuhe(vector<int>& v,int n,int m,int s,int outlen,vector<int>& res,int index)
{
	if (m == 0) {
		for_each(res.begin(), res.end(), [](int num) {cout << num << " "; });
		cout << endl;
		return;
	}
	for (int i = s; i < n - m + 1; i++) {
		res[index] = v[i];
		zuhe(v, n, m - 1, s + 1, outlen, res, index + 1);
	}
}



int mainpz()
{
	vector<int> v = { 1,2,3,4 };

	vector<int> res(3,-1);
	

	zuhe(v, 4, 3, 0, 3, res, 0);

	
	system("pause");
	return EXIT_SUCCESS;
}