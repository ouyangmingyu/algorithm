#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include <cstdlib>
using namespace std;


//利用最短路径算法

int MaxLen_floyd(vector<int>& dis) {
	int maxlength = 0;
	int len = dis.size();
	int nodenum = (int)sqrt(len);
	for(int k=0;k<nodenum;k++)
		for(int i=0;i<nodenum;i++)
			for (int j = 0; j < nodenum; j++) {
				dis[i*nodenum + j] = ((dis[i*nodenum + k] + dis[k*nodenum + j]) < dis[i*nodenum + j]) ? dis[i*nodenum + k] + dis[k*nodenum + j] : dis[i*nodenum + j];
		}

	for (int i = 0; i < len; i++) {
		if (dis[i] == 10000) {
			dis[i] = -1;
		}
	}

	for (int i = 0; i<nodenum; i++)
		for (int j = 0; j < nodenum; j++) {
			if (dis[i*nodenum + j] > maxlength) {
				maxlength = dis[i*nodenum + j];
			}
		}
	return maxlength;
}




int MaxLen_DJK(vector<int>& dis) {
	int maxlength = 0;
	int len = dis.size();
	int nodenum = (int)sqrt(len);

	vector<int> s;
	vector<int> prev;
	prev.reserve(len);

	prev.assign(len, -1);

	for (int i = 0; i < nodenum; i++) {
		//逐行更新
		vector<bool> flag(nodenum,false);
		//将距离最近的点加入s并更新距离
		for (int j = 1; j < nodenum; j++) {	
			int mindis = 10000;
			int minnode = -1;
			//找到距离最小的点加入s
			for (int k = 0; k < nodenum; k++) {
				if (k == i)
					continue;
				if (!flag[k] && dis[i*nodenum + k] < mindis) {
					mindis = dis[i*nodenum + k];
					minnode = k;
				}
			}
			flag[minnode] = true;
			//更新距离
			for (int m = 0; m < nodenum; m++) {
				if (m == i)
					continue;
				int newstdis = dis[i*nodenum + minnode] + dis[minnode*nodenum + m];
				if (dis[i*nodenum + m] > newstdis) {
						dis[i*nodenum + m] = newstdis;
						prev[i*nodenum + m] = minnode;
					}			
			}
		}
	}


	for (int i = 0; i < len; i++) {
		if (dis[i] == 10000) {
			dis[i] = -1;
		}
	}
	int begin = -1;
	int end = -1;
	for (int i = 0; i<nodenum; i++)
		for (int j = 0; j < nodenum; j++) {
			if (dis[i*nodenum + j] > maxlength) {
				maxlength = dis[i*nodenum + j];
				begin = i;
				end = j;
			}
		}
	cout << begin << " " << end << endl;
	for (int i =0; i < nodenum; i++) {
		cout << prev[begin*nodenum + i] << " ";
	}
	cout << endl;
	return maxlength;
}

int main04() {
	
	int testnum = 0;
	cin >> testnum;
	for (int i = 0; i < testnum; i++) {
		int nodenum = 0;
		vector<int> v;
		cin >> nodenum;
		v.reserve(nodenum*nodenum);
		v.assign(nodenum*nodenum,10000);
		for(int j=0;j<nodenum-1;j++){
			int row, col = 0;
			cin >> row >> col;
			v[row*nodenum + col] = 1;
			v[col*nodenum + row] = 1;
		}
		int R = MaxLen_DJK(v);
		cout << R << endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}