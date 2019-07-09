/* 打怪兽，每到一个怪兽，可以贿赂或者不贿赂，贿赂之后就可以带上这个怪兽，到下一个怪兽时如果当前武力值大于怪兽武力值，则不会被攻击。至少需要多少硬币。
* 武力值：8，5，10
* 金币：1，1，2
* 输出：2
* 需要注意的是可带不止一个怪兽
*
* 解法：背包
* dp[i][j] = max(dp[i-1][j],dp[i-1][j-cion[i]]+force[i]);
* 其中dp[i][j]表示包含第i个怪兽的情况下，用j个金币所能获得的最大武力值
* 只不过需要注意两个问题：
* 1、只有满足不贿赂怪兽i时的最大武力值 > 怪兽i的武力值时，才可以不贿赂怪兽i，即dp[i-1][j]
* 2、只有当前金币j大于贿赂怪兽i所需金币coin[i]，并且剩余的金币j-coin[i]可以保证足够贿赂i之前的怪兽时才可以贿赂怪兽i，即dp[i-1][j-coin[i]];
*
* 初始条件：
* dp[0][j]=0;//0个怪兽始终获得武力0
* dp[i][0]=-1;//用0个金币贿赂怪兽不可行
* dp[i][j]=-1;//表示用j个硬币贿赂前i个怪兽不可行。如上面的例子：dp[1][1]=8。dp[3][1]=-1,用1个金币贿赂3个怪兽显然不可行。
*
* 最后一个怪兽n贿赂的情况在dp[n][j];j从小到达增长，如果用j个硬币贿赂n不可行，dp[n][j]=-1，找到第一个不为-1的dp[n][j],这个j即为所求。
*
* */
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int res20(int len, vector<int>& a, vector<int>& m)
{

	int ms = 0;
	for (int i = 0; i < len; i++) {
		ms += m[i];
	}

	vector<vector<int>>  v(len + 1, vector<int>(ms + 1, -1));

	for (int j = 1; j <= ms; j++) {
		v[0][j] = 0;
	}

	for (int i = 1; i <= len; i++)
		for (int j = 1; j <= ms; j++) {
			//可以不贿赂
			if (v[i - 1][j] > a[i]) {
				v[i][j] = v[i][j] > v[i - 1][j] ? v[i][j] : v[i - 1][j];
			}
			//可以贿赂
			if (j > m[i] && v[i - 1][j - m[i]] != -1) {
				v[i][j] = v[i][j] > (v[i - 1][j - m[i]] + a[i]) ? v[i][j] : (v[i - 1][j - m[i]] + a[i]);
			}
		}

	for (int j = 1; j <= ms; j++) {
		if (v[len - 1][j] != -1) {
			return j;
		}
	}
}

int main20()
{
	int n;
	cin >> n;

	vector<int> a(n + 1, 0);
	vector<int> m(n + 1, 0);


	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> m[i];
	}

	cout << res20(n, a, m) << endl;

	system("pause");
	return 0;
}