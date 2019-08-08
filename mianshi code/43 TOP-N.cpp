#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

#include "zx.h"

using namespace std;

class solution0 {
public:
	void Adjd(int k) {
		v[0] = v[k];
		for (int i = 2 * k; i <= t; i *= 2) {
			if (i<t&&v[i]<v[i + 1]) i++;
			if (v[i] <= v[0]) break;
			else {
				v[k] = v[i];
				k = i;
			}
		}
		v[k] = v[0];
	}

	void BuildDui()
	{
		for (int i = t / 2; i > 0; i--) {
			Adjd(i);
		}
	}

	void inputnum(int num)
	{
		if (num < v[1]) {
			v[1] = num;
			Adjd(1);
		}
	}

	vector<int> v = { 0,5,2,7,1,3,4,0,6 };
	int t;
};





int main43() {
	vector<int> v = { 9,11,8,5,7,12,16,14 };

	
	system("pause");
	return EXIT_SUCCESS;
}

