//#include<iomanip>
//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//#include<queue>
//#include<limits.h>
//
//using namespace std;
//
//
////最大公约数
//
//long long gcd(long long a, long long b)
//{
//	return b == 0 ? a : gcd(b, a%b);
//}
//
//void sol1(string a, string b)
//{
//	long long an=0, bn=0;
//	int lena = a.size();
//	int lenb = b.size();
//	for (int i = 0; i < lena; i++) {
//		an += an * 10 + (a[i] - '0');
//	}
//	for (int i = 0; i < lenb; i++) {
//		bn += bn * 10 + (b[i] - '0');
//	}
//	long long res = gcd(an, bn);
//	cout << res << endl;
//}
//
//
////子集按位或等于k
//void sol2c(vector<int> v, int k)
//{
//	int len = v.size();
//
//}
//
//void sol2(vector<pair<int, int>> v, int cnt)
//{
//	vector<int> vt;
//	for (int i = 0; i < cnt; i++) {
//		if (v[i].first == 1) {
//			vt.push_back(v[i].second);
//		}
//		else {
//			sol2c(vt, v[i].second);
//		}
//	}
//}
//
//
////最大里面的最小
//void sol3c(vector<int> v, int len, vector<int>& res) {
//	int lenv = v.size();
//	int minofmax = INT_MAX;
//	deque<int> max;
//	max.push_back(0);
//	for (int i = 1; i < len; i++) {
//		while (max.size() && v[i] > v[max.back()]) {
//			max.pop_back();
//		}
//		max.push_back(i);
//
//	}
//	minofmax = v[max.front()];
//	for (int i = len; i < lenv; i++) {
//		while (max.size() && v[i] > v[max.back()]) {
//			max.pop_back();
//		}
//		max.push_back(i);
//		if (max.front() == i - len) {
//			max.pop_front();
//		}
//		minofmax = minofmax<v[max.front()] ? minofmax : v[max.front()];
//	}
//	res.push_back(minofmax);
//}
//
//void sol3(vector<int> v) {
//	int len = v.size();
//	vector<int> res;
//	for (int i = 1; i <= len; i++) {
//		sol3c(v, i, res);
//	}
//	for_each(res.begin(), res.end(), [](int num) {cout << num << " "; });
//	cout << endl;
//}
//
////优秀的01串
//void sol4()
//{
//	
//}
//
//
//int main()
//{
//	string a, b;
//	cin >> a >> b;
//
//	sol1(a, b);
//
//	system("pause");
//	return 0;
//}
//
///*int cnt;
//cin >> cnt;
//vector<pair<int, int>> v(cnt, make_pair(0, 0));
//for (int i = 0; i < cnt; i++) {
//cin >> v[i].first >> v[i].second;
//}
//sol2(v,cnt);*/