#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

#include "zx.h"

using namespace std;


//N个孩子站成一排，给每个人设定一个权重（已知）。按照如下的规则分配糖果：(1)每个孩子至少分得一颗糖果 （2）权重较高的孩子，会比他的邻居获得更多的糖果。
//问：总共最少需要多少颗糖果？请分析算法思路，以及算法的时间，空间复杂度是多少。

//leetcode上的原题，先每人发一颗糖。第一遍从前往后扫描，满足相邻两个小孩后面的权重大于前面的权重的情况，
//后面的小孩在前面的小孩的糖果数的基础上加一个。第二遍从后往前扫描，满足条件与第一遍扫描一样。这样两遍扫描
//下来就可以保证权重高的孩子比相邻权重低的孩子的糖果多。时间复杂度是O(n)，空间复杂度是O(n)。

class solution {
public:
	int leastCandy(vector<int> qz) {
		int len = qz.size();
		if (len == 0) {
			return -1;
		}
		vector<int> v(len, 1);
		for (int i = 0; i < len; i++) {
			if (i<len - 1 && qz[i + 1]>qz[i]) {
				v[i + 1] = v[i] + 1;
			}
		}
		for (int i = 0; i < len; i++) {
			if (i<len - 1 && qz[i + 1]>qz[i]) {
				v[i + 1] = v[i] + 1;
			}
		}
		for (int i = len - 1; i >= 0; i--) {
			if (i>0 && qz[i - 1]>qz[i]) {
				v[i - 1] = v[i] + 1;
			}
		}
		int sum = 0;
		for (int i = 0; i < len; i++) {
			sum += v[i];
		}
		return sum;
	}
};





int main44() {
	vector<int> v = { 9,11,8,5,7,12,16,14 };

	
	system("pause");
	return EXIT_SUCCESS;
}
