#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

void res60t1(int num,int& sum, map<int, int>& m)
{
	//循环
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

	//循环，动态规划的思想，假设f(m,n)表示投第m个骰子的时候，点数之和为n出现的次数，投第m个骰子的点数之和只与投第m-1个骰子有关
	  
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