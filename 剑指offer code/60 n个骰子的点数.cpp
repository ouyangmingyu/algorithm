#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

void res60t1(int num,int& sum, map<int, int>& m)
{
	//ѭ��
	/*if (num == 1) {
		for (int i = 1; i <= 6; i++) {
			sum += i;
			m[sum]++;
			sum -= i;
		}
		return;
	}
	for (int i = 1; i <= 6; i++) {
		sum += i;
		res60t1(num - 1, sum, m);
		sum -= i;
	}*/

	//ѭ������̬�滮��˼�룬����f(m,n)��ʾͶ��m�����ӵ�ʱ�򣬵���֮��Ϊn���ֵĴ�����Ͷ��m�����ӵĵ���֮��ֻ��Ͷ��m-1�������й�
	  
}


int main60()
{
	int num = 2;
	int sum = 0;
	
	map<int, int> m;

	res60t1(num,sum,m);

	for_each(m.begin(), m.end(), [](auto i) {cout << i.first << ":" << i.second << endl; });

	system("pause");
	return EXIT_SUCCESS;
}