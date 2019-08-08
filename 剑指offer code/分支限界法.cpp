//#include<iostream>
//#include<string>
//#include<stack>
//#include<vector>
//#include<algorithm>
//#include<map>
//#include<stack>
//#include<queue>
//#include<functional>
//#include<unordered_map>
//#include<exception>
//#include "time.h"
//#include "zx.h"
//
//using namespace std;
//
//
//// 优先队列 单源最短路径
//class Graph {
//private:
//	void ShortestPaths(int);
//	int n;//图G的顶点数
//	vector<int> pre;
//	vector<vector<int>> c;
//	vector<int> dist;
//};
//
//class node {
//	friend Graph;
//public:
//	bool operator <(node n) {
//		return length < n.length;
//	}
//
//private:
//	int i;//顶点编号
//	int length;//当前路长
//};
//
//void Graph::ShortestPaths(int v) {
//	priority_queue<node,vector<node>,greater<node>> q;
//	node s;
//	s.i = v;
//	s.length = 0;
//	q.push(s);
//	while (q.size()) {
//		s = q.top();
//		q.pop();
//		for (int j = 1; j <= n; j++) {
//			if ((c[s.i][j] < INT_MAX) && (s.length + c[s.i][j] < dist[j])) {
//				dist[j] = s.length + c[s.i][j];
//				pre[j] = s.i;
//				node n;
//				n.i = j;
//				n.length = dist[j];
//				q.push(n);
//			}
//		}
//	}
//}
//
////0-1背包 子集树
//class object {
//	friend int Knapsack(vector<int> p, vector<int> w, int c, int n, vector<int> bestx);
//public:
//	bool operator<= (object a) const {
//		return d >= a.d;
//	}
//
//private:
//	int id;
//	float d;
//};
//
//class Knap;
////当前扩展节点
//class bbnode {
//	friend Knap;
//	friend int Knapsack(vector<int> p, vector<int> w, int c, int n, vector<int> bestx);
//private:
//	bbnode* parent;
//	bool LChild;
//};
//
//class Heapnode{
//	friend Knap;
//public:
//	operator int() const { return upprofit; }
//
//private:
//	int upprofit;
//	int profit;
//	int weight;
//	int level;
//	bbnode* ptr;
//};
//
//class Knap {
//	friend int Knapsack(vector<int> p, vector<int> w, int c, int n, vector<int> bestx);
//public:
//	int MaxKnapsack();
//
//private:
//	priority_queue<Heapnode> q;
//	int Bound(int i);
//	void Addlivenode(int up, int cp, int cw, bool ch, int level);
//	bbnode* E;
//	int c;
//	int n;
//	vector<int> w;
//	vector<int> p;
//	int cw;
//	int cp;
//	vector<int> bestx;
//};
//
//int Knap::Bound(int i) {
//	int cleft = c - cw;
//	int b = cp;
//	while (i <= n&&w[i] <= cleft) {
//		cleft -= w[i];
//		b += p[i];
//		i++;
//	}
//	if (i <= n) b += p[i] / w[i] * cleft;
//	return b;
//}
//
//void Knap::Addlivenode(int up, int cp, int cw, bool ch, int lev) {
//	bbnode *b = new bbnode;
//	b->parent = E;
//	b->LChild = ch;
//	Heapnode N;
//	N.upprofit = up;
//	N.profit = cp;
//	N.weight = cw;
//	N.level = lev;
//	N.ptr = b;
//	q.push(N);
//}
//
//int Knap::MaxKnapsack() {
//	bestx = vector<int>(n + 1, 0);
//	int i = 1;
//	E = 0;
//	cw = cp = 0;
//	int bestp = 0;
//	int up = Bound(1);
//	while (i != n + 1) {
//		int wt = cw + w[i];
//		if (wt <= c) {
//			if (cp + p[i] > bestp) bestp = cp + p[i];
//			Addlivenode(up, cp + p[i], cw + w[i], true, i + 1);
//			up = Bound(i + 1);
//		}
//		if (up >= bestp) {
//			Addlivenode(up, cp, cw, false, i + 1);
//		}
//		Heapnode N;
//		N = q.top();
//		q.pop();
//		E = N.ptr;
//		cw = N.weight;
//		cp = N.profit;
//		up = N.upprofit;
//		i = N.level;
//	}
//	for (int j = n; j > 0; j--) {
//		bestx[j] = E->LChild;
//		E = E->parent;
//	}
//	return cp;
//}
//
//int Knapsack(vector<int> p, vector<int> w, int c, int n, vector<int> bestx) {
//	int W = 0;
//	int P = 0;
//	vector<object> Q(n);
//	for (int i = 1; i <= n; i++) {
//		Q[i - 1].id = i;
//		//Q[i - 1].d = p[i] / w[i];
//		P += p[i];
//		W += w[i];
//	}
//	if (W <= c) return P;
//	sort(Q.begin(), Q.end());
//	Knap K;
//	K.p = vector<int>(n + 1, 0);
//	K.w = vector<int>(n + 1, 0);
//	for (int i = 1; i <= n; i++) {
//		K.p[i] = p[Q[i - 1].id];
//		K.w[i] = w[Q[i - 1].id];
//	}
//	K.cp = 0;
//	K.cw = 0;
//	K.c = c;
//	K.n = n;
//	int bestp = K.MaxKnapsack();
//	for (int j = 1; j <= n; j++) {
//		bestx[Q[j - 1].id] = K.bestx[j];
//	}
//	return bestp;
//}
//
////旅行售货员 排列树
//
//
//int main()
//{
//
//}