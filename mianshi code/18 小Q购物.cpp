/*����n�ֲ�ͬ��Ӳ�ң�Ҫ��ϳ�1-X��������ֵ����������Ҫ���ٸ�Ӳ��
* 20 4
* 1 2 5 10
* ���5
* ̰�����
* ÿ�ζ��õ�ǰ���õ�����Ӳ��
* */
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<functional>

using namespace std;


//̰���㷨
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
		cout << "���������������" << endl;
	}
	system("pause");
	return 0;
}