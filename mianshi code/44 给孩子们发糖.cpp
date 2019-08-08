#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

#include "zx.h"

using namespace std;


//N������վ��һ�ţ���ÿ�����趨һ��Ȩ�أ���֪�����������µĹ�������ǹ���(1)ÿ���������ٷֵ�һ���ǹ� ��2��Ȩ�ؽϸߵĺ��ӣ���������ھӻ�ø�����ǹ���
//�ʣ��ܹ�������Ҫ���ٿ��ǹ���������㷨˼·���Լ��㷨��ʱ�䣬�ռ临�Ӷ��Ƕ��١�

//leetcode�ϵ�ԭ�⣬��ÿ�˷�һ���ǡ���һ���ǰ����ɨ�裬������������С�������Ȩ�ش���ǰ���Ȩ�ص������
//�����С����ǰ���С�����ǹ����Ļ����ϼ�һ�����ڶ���Ӻ���ǰɨ�裬�����������һ��ɨ��һ������������ɨ��
//�����Ϳ��Ա�֤Ȩ�ظߵĺ��ӱ�����Ȩ�ص͵ĺ��ӵ��ǹ��ࡣʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(n)��

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
