#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<functional>
#include<algorithm>
#include<map>

using namespace std;

//01±³°ü

void back01(vector<pair<int, int>> v, int n, int c)
{
	vector<vector<int>> dp(n+1, vector<int>(c+1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= c; j++) {
			if (j < v[i].first) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = dp[i - 1][j] >(dp[i - 1][j - v[i].first] + v[i].second) ? dp[i - 1][j] : (dp[i - 1][j - v[i].first] + v[i].second);
			}
		}
	}
	cout << dp[n][c] << endl;
}








int main()
{
	int n, c;
	cin >> n >> c;
	vector<pair<int, int>> v(n + 1, make_pair(0, 0));
	for (int i = 1; i <= n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	back01(v, n, c);
	system("pause");
	return 0;
}