/* ����ޣ�ÿ��һ�����ޣ����Ի�¸���߲���¸����¸֮��Ϳ��Դ���������ޣ�����һ������ʱ�����ǰ����ֵ���ڹ�������ֵ���򲻻ᱻ������������Ҫ����Ӳ�ҡ�
* ����ֵ��8��5��10
* ��ң�1��1��2
* �����2
* ��Ҫע����ǿɴ���ֹһ������
*
* �ⷨ������
* dp[i][j] = max(dp[i-1][j],dp[i-1][j-cion[i]]+force[i]);
* ����dp[i][j]��ʾ������i�����޵�����£���j��������ܻ�õ��������ֵ
* ֻ������Ҫע���������⣺
* 1��ֻ�����㲻��¸����iʱ���������ֵ > ����i������ֵʱ���ſ��Բ���¸����i����dp[i-1][j]
* 2��ֻ�е�ǰ���j���ڻ�¸����i������coin[i]������ʣ��Ľ��j-coin[i]���Ա�֤�㹻��¸i֮ǰ�Ĺ���ʱ�ſ��Ի�¸����i����dp[i-1][j-coin[i]];
*
* ��ʼ������
* dp[0][j]=0;//0������ʼ�ջ������0
* dp[i][0]=-1;//��0����һ�¸���޲�����
* dp[i][j]=-1;//��ʾ��j��Ӳ�һ�¸ǰi�����޲����С�����������ӣ�dp[1][1]=8��dp[3][1]=-1,��1����һ�¸3��������Ȼ�����С�
*
* ���һ������n��¸�������dp[n][j];j��С���������������j��Ӳ�һ�¸n�����У�dp[n][j]=-1���ҵ���һ����Ϊ-1��dp[n][j],���j��Ϊ����
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
			//���Բ���¸
			if (v[i - 1][j] > a[i]) {
				v[i][j] = v[i][j] > v[i - 1][j] ? v[i][j] : v[i - 1][j];
			}
			//���Ի�¸
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