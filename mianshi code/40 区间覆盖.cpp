#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>


#include "zx.h"

using namespace std;

bool func(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

class solution0 {
public:
	static void qujianfugai(vector<pair<int,int>> v,int begine,int end)
	{
		int cnt = 0;
		int left = begine;
		int right = begine;
		vector<pair<int, int>> res;
 		sort(v.begin(), v.end(), func);
		int len = v.size();
		for (auto i = v.begin(); i != v.end(); i++) {
			if ((*i).first > end || (*i).second < begine) {
				v.erase(i);
			}
		}
		if (v[0].first > begine) {
			cout << "нч╫Б" << endl;
			return ;
		}
		int bj = 0;
		for (int i = 0; i < len; i++) {
			if (v[i].first <= left) {
				if (v[i].second>right) {
					right = v[i].second;
					bj = i;
					if (right >= end) {
						break;
					}
				}	
			}
			else {
				if (v[i].first > right) {
					return;
				}
				else {
					res.push_back(v[bj]);
					bj = -1;
					left = right;
				}
			}
		}
		if (right < end) {
			return;
		}
		for_each(res.begin(), res.end(), [](pair<int, int> p) {cout << "[" << p.first << "," << p.second << "] " << endl; });
	}
};





int main40() {
	
	system("pause");
	return EXIT_SUCCESS;
}

