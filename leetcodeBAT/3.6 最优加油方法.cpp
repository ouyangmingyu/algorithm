//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<iostream>
//#include<functional>
//#include<queue>
//#include<queue>
//#include<stack>
//
//using namespace std;
//
//bool cmp2(pair<int, int> p1, pair<int, int> p2) {
//	return p1.first > p2.first;
//}
//
//int get_min_stop(int L, int P, vector<pair<int, int>> v)
//{
//	sort(v.begin(), v.end(), cmp2);
//	int num = 0;
//	priority_queue<int> q;
//	v.push_back(make_pair(0, 0));
//	for (int i = 0; i < v.size(); i++) {
//		int dis = L - v[i].first;
//		while (P < dis&&q.size()) {
//			P += q.top();
//			q.pop();
//			num++;
//		}
//		if (q.empty() && P < dis) {
//			return -1;
//		}
//		P = P - dis;
//		L = v[i].first;
//		q.push(v[i].second);
//	}
//	return num;
//}