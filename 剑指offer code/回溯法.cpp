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
////n�ʺ�����
//class Queue {
//	friend int nQueue(int);
//private:
//	//Լ������
//	bool Place(int k);
//	void Backtracedg(int t);
//	void Backtracedd(int t);
//	int n;
//	//��ǰ��
//	vector<int> v;
//	int sum;
//};
//
//bool Queue::Place(int k) {
//	for (int i = 1; i < k; i++) {
//		if (abs(k - i) == abs(v[i] - v[k]) || (v[i] == v[k])) return false;
//		return true;
//	}
//}
//
////�ݹ鷨
//void Queue::Backtracedg(int t) {
//	if (t > n) sum++;
//	else {
//		for (int i = 1; i <= n; i++) {
//			v[t] = i;
//			if (Place(t)) Backtracedg(t + 1);
//		}
//	}
//}
//
////������
//void Queue::Backtracedd(int t) {
//	v[1] = 0;
//	int k = 1;
//	while (k > 0) {
//		v[k]++;
//		while (v[k] <= n && (!Place(k))) v[k]++;
//		if (v[k] <= n) {
//			if (k == n) sum++;
//			else {
//				k++;
//				v[k] = 0;
//			}
//		}
//		else {
//			k--;
//		}
//	}
//}
//
//int nQueue(int n) {
//	Queue X;
//	X.n = n;
//	X.sum = 0;
//	X.v = vector<int>(n + 1, 0);
//	X.Backtracedg(1);
//	return X.sum;
//}
//
//
////�Ӽ���  0-1 ����
//class Knap {
//	friend int Knapsack(vector<int> p, vector<int> w, int c, int n);
//private:
//	//�Ͻ纯��
//	int Bound(int i);
//	void Backtrace(int i);
//	int c;//��������
//	int n;
//	vector<int> w;
//	vector<int> p;
//	//��ǰ����������ֵ�����Ž�
//	int cw;
//	int cp;
//	int bestp;
//};
//
//void Knap::Backtrace(int i) {
//	if (i > n) {
//		bestp = cp;
//		return;
//	}
//	if (cw + w[i] <= c) {
//		cw += w[i];
//		cp += p[i];
//		Backtrace(i + 1);
//		cw -= w[i];
//		cp -= p[i];
//	}
//	if (Bound(i + 1) > bestp) {
//		Backtrace(i + 1);
//	}
//}
//
//int Knap::Bound(int i) {
//	int cleft = c - cw;
//	int b = cp;
//	while (i <= n&& w[i] <= cleft) {
//		cleft -= w[i];
//		b += p[i];
//		i++;
//	}
//	if (i <= n) b += p[i] * cleft / w[i];
//	return b;
//}
//
//class object {
//	friend int Knapsack(vector<int> p, vector<int> w, int c, int n);
//public:
//	int operator<=(object a) const {
//		return d >= a.d;
//	}
//
//private:
//	int id;
//	float d;
//};
//
//int Knapsack(vector<int> p, vector<int> w, int c, int n) {
//	int W = 0;
//	int P = 0;
//	vector<object> Q(n, object());
//	for (int i = 1; i <= n; i++) {
//		Q[i - 1].id = i;
//		//Q[i - 1].d = 1.0*p[i] / w[i];
//		W += w[i];
//		P += p[i];
//	}
//	if (W <= c) return P;
//	sort(Q.begin(),Q.end());
//	Knap K;
//	K.p = vector<int>(n + 1, 0);
//	K.w = vector<int>(n + 1, 0);
//
//	for (int i = 1; i <= n; i++) {
//		K.p[i] = p[Q[i - 1].id];
//		K.w[i] = w[Q[i - 1].id];
//	}
//	K.cp = 0;
//	K.cw = 0;
//	K.c = c;
//	K.n = n;
//	K.bestp = 0;
//	K.Backtrace(1);
//
//	return K.bestp;
//}
//
////������  ��������ҵ����
//class Flowshop {
//	friend int Flow(vector<vector<int>> v, int n, vector<int> bestx);
//private:
//	void Backtrace(int i);
//
//	vector<vector<int>> M;//����ҵ���账��ʱ��
//	vector<int> x;//��ǰ��ҵ����
//	vector<int> bestx;//��ǰ������ҵ����
//	vector<int> f2;//����2��ɴ���ʱ��
//	int f1;//����1��ɴ���ʱ��
//	int f;//���ʱ���
//	int bestf;//��ǰ����ֵ
//	int n;//��ҵ��
//};
//
//void Flowshop::Backtrace(int i) {
//	if (i > n) {
//		for (int j = 1; j <= n; j++)
//			bestx[j] = x[j];
//		bestf = f;
//	}
//	else {
//		for (int j = i; j <= n; j++) {
//			f1+=M[x[j]][1];
//			f2[i] = ((f2[i - 1] > f1) ? f2[i - 1] : f1) + M[x[j]][2];
//			f += f2[i];
//			if (f < bestf) {
//				swap(x[i], x[j]);
//				Backtrace(i + 1);
//				swap(x[i], x[j]);
//			}
//			f1 -= M[x[j]][1];
//			f -= f2[i];
//		}
//	}
//}
//
//int Flow(vector<vector<int>> M, int n, vector<int> bestx)
//{
//	Flowshop X;
//	X.x = vector<int>(n + 1, 0);
//	X.f2 = vector<int>(n + 1, 0);
//	X.M = M;
//	X.n = n;
//	X.bestx = bestx;
//	X.bestf = INT_MAX;
//	X.f1 = 0;
//	X.f = 0;
//	for (int i = 0; i <= n; i++) {
//		X.f2[i] = 0;
//		X.x[i] = i;
//	}
//	X.Backtrace(1);
//
//	return X.bestf;
//}
//
//
//// �����ۻ�Ա ������
//
//class Traveling {
//	friend int TSP(vector<vector<int>> a, vector<int> v, int n, int NoEdge);
//private:
//	void BackTrace(int i);
//	int n;
//	vector<int> x;
//	vector<int> bestx;
//	vector<vector<int>> a;
//	int cc;
//	int bestc;
//	int NoEgde;
//};
//
//void Traveling::BackTrace(int i) {
//	if (i == n) {
//		if (
//			(a[x[n-1]][x[n]]!=NoEgde) &&
//			(a[x[n]][1]!=NoEgde) &&
//			(cc+a[x[n-1]][x[n]]+a[x[n]][1]<bestc || bestc==NoEgde)
//			)
//		{
//			for (int j = 1; j <= n; j++) bestx[j] = x[j];
//			bestc = cc + a[x[n - 1]][x[n]] + a[x[n]][1];
//		}
//		else {
//			for (int j = i; j <= n; j++) {
//				if (a[x[i - 1]][x[j]] != NoEgde && (cc + a[x[i - 1]][j]< bestc || bestc == NoEgde)) {
//					swap(x[i], x[j]);
//					cc += a[x[i - 1]][x[i]];
//					BackTrace(i + 1);
//					cc -= a[x[i - 1]][x[i]];
//					swap(x[i], x[j]);
//				}
//			}
//		}
//	}
//}
//
//int TSP(vector<vector<int>> a, vector<int> v, int n, int NoEdge) {
//	Traveling Y;
//	Y.x = vector<int>(n + 1, 0);
//	for (int i = 1; i <= n; i++) Y.x[i] = i;
//	Y.a = a;
//	Y.n = n;
//	Y.bestc = NoEdge;
//	Y.bestx = v;
//	Y.cc = 0;
//	Y.NoEgde = NoEdge;
//	Y.BackTrace(2);
//	return 0;
//
//}
//
//
