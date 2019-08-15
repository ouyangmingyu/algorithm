#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<functional>
#include<queue>
#include<queue>
#include<stack>

using namespace std;

bool cmp(vector<int> v1, vector<int> v2) {
	return v1[0] < v2[0];
}

class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		int len = points.size();
		if (len < 2) {
			return len;
		}
		sort(points.begin(), points.end(), cmp);
		int beg = points[0][0];
		int end = points[0][1];
		int cnt = 1;
		for (int i = 1; i < len; i++) {
			if (points[i][0] <= end) {
				beg = points[i][0];
				if (end > points[i][1]) {
					end = points[i][1];
				}
			}
			if (points[i][0] > end) {
				cnt++;
				beg = points[i][0];
				end = points[i][1];
			}
		}
		return cnt;
	}
};