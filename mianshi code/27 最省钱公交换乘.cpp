#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

void res27(vector<vector<int>> v, int s, int d, int n)
{
	int res;
	vector<int> v1;
	v1.push_back(s);
	int min = -1;
	int flag = -1;
	vector<int> prev(n, 0);

	while (v1.size() < n) {
		for (int i = 1; i < n + 1; i++) {
			min = v[s][i] < min ? v[s][i] : min;
			flag = v[s][i] < min ? i : flag;
		}
		v1.push_back(flag);
		for (int i = 1; i < n + 1; i++) {
			if (find(v1.begin(), v1.end(), i) == v1.end()) {
				if (v[s][flag] + v[flag][s] < v[s][i]) {
					v[s][i] = v[s][flag] + v[flag][s] < v[s][i];
					prev[i] = flag;
				}
			}
		}
	}
}

int main27()
{
	/*int n1;
	int n2;
	cin >> n1 >> n2;

	vector<vector<int>> v(n1+1, vector<int>(n1+1, 10000));
	vector<int> v2(4, 0);

	for (int i = 0; i < n2; i++) {
	for (int j = 0; j < 4; j++) {
	cin >> v2[j];
	}
	v[v2[1]][v2[2]] = v2[3];
	v[v2[2]][v2[1]] = v2[3];
	}
	cout << v[1][3] << endl;
	int s, d;
	cin >> s >> d;

	res2(v, s, d,n1);*/

	vector<int> v(1, 0);

	while (v.size() > 2) {
		cout << "hello" << endl;
	}


	system("pause");
	return 0;
}