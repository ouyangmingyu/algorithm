//题目描述：
//咖啡机可以连续不间断的工作，但是每台咖啡机煮一杯咖啡所需时间都不一样，并且每台咖啡机
//一次只能煮一次咖啡。
//
//每个人喝完咖啡后需要清理自己的杯子，有两种清洗方式。
//一种是洗杯器清洗，但洗杯器只有一个，每次只能洗一个杯子，洗一个杯子需要x单位时间。
//另外一种是靠咖啡自然挥发，经过y单位时间后，残留咖啡挥发完，杯子也会变干净。
//
//现有n个人想喝咖啡，有m台咖啡机。每台咖啡机煮一杯咖啡所需时间为Vi，让所有人喝完咖啡并
//且清洗完自己的杯子的时间最少是多少？
//
//
//输入描述：
//1.输入一个数字T，表示有T组数据。
//2.对于每组数据，第一行输入四个数n，m，x，y，表示人数、咖啡机数量、洗杯器洗杯子时间、
//咖啡自然挥发的时间。第二行输入m个数字，表示每台咖啡机煮一杯咖啡所需的时间。
//对于40%的数据，1 <= n, m, x, y, Vi<100。
//	对于80%的数据，1 <= n, m, x, y, Vi<1000。
//	对于100%的数据，1 <= n, m, x, y, Vi<10000。
//
//	输出描述：
//	对于每一组数据，输出一个最小时间。
//
//	样例
//	输入：
//	2
//	1 1 1 1
//	10
//	2 2 1 1
//	10 7
//	输出：
//	11
//	11

#include <iostream>
#include <cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int mintime(int n, int m, int x, int y, vector<int>& v)
{
	sort(v.begin(), v.end());

	

	return 0;
}

int main21()
{
	int T, n, m, x, y;
	cin >> T;


	vector<int> t;
	for (int i = 0; i < T; i++) {
		cin >> n >> m >> x >> y;
		vector<int> v;
		for (int j = 0; j < m; j++) {
			int t;
			cin >> t;
			v.push_back(t);
		}

		int mt = mintime(n, m, x, y, v);
		t.push_back(mt);
	}

	for_each(t.begin(), t.end(), [](int t) {cout << t << endl; });

	system("pause");
	return 0;
}
