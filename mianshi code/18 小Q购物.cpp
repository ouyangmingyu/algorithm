/*现有n种不同的硬币，要组合出1-X的任意面值，问至少需要多少个硬币
* 20 4
* 1 2 5 10
* 输出5
* 贪心求解
* 每次都拿当前可拿的最大的硬币
* */
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<functional>

using namespace std;


//贪心算法
int res1(int m, int n, vector<int>& v)
{
	int cnt = 0;
	sort(v.begin(), v.end(), greater<int>());
	vector<int> res;

	if (*(v.end() - 1) > 1) {
		return -1;
	}

	int sum = 0;

	while (sum < m) {
		for (auto ele : v) {
			if (ele <= sum + 1) {
				res.push_back(ele);
				sum += ele;
				break;
			}
		}
	}

	cout << res.size() << endl;
	for_each(res.begin(), res.end(), [](int num) {cout << num << " "; });
	cout << endl;
	return 0;
}



int main18()
{
	int m, n;
	cin >> m >> n;
	vector<int>  v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if (res1(m, n, v) == -1) {
		cout << "不存在这样的组合" << endl;
	}
	system("pause");
	return 0;
}