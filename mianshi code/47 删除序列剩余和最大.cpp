#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

#include "zx.h"

using namespace std;

class solution {
public:
	int maxzdh(vector<int> v,int len) {
		if (len <= 0) {
			return -1;
		}
		int max = INT_MIN;
		for (int i = 0; i < len; i++) {
			int maxl = INT_MIN;
			int maxr = INT_MIN;
			int cursum = 0;
			for (int l=0; l <= i; l++) {
				if (cursum < 0) {
					cursum = v[l];
				}
				else {
					cursum += v[i];
				}
				maxl = maxl > cursum ? maxl : cursum;
			}
			cursum = 0;
			for (int r=len-1; r > i; r--) {
				if (cursum < 0) {
					cursum = v[r];
				}
				else {
					cursum += v[r];
				}
				maxr = maxl > cursum ? maxr : cursum;
			}
			max = max > (maxl + maxr) ? max : (maxl + maxr);
		}
		return max;
	}
};





int main47() {
	system("pause");
	return EXIT_SUCCESS;
}

