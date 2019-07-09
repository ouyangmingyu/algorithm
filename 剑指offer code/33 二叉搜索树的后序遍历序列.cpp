#include<iostream>
#include<vector>
#include"Btree.h"


bool res35(vector<int>& v,int l,int r)
{
	if (l == r) {
		return true;
	}

	if (l == r - 1) {
		if (v[l] > v[r]) {
			return false;
		}
		else {
			return true;
		}
	}

	int mid;
	int midval;

	for (int i = l; i < r; i++) {
		//找左右子树分界
		if (v[i] > v[r]) {
			mid = i - 1;
			midval = v[i];
		}
		if (i == r - 1) {
			return res35(v, l, r - 1);
		}
	}

	for (int i = mid + 1; i < r; i++) {
		if (v[i] < v[r]) {
			return false;
		}
		if (mid == l - 1 && i == r - 1) {
			return res35(v, l, r - 1);
		}
	}

	return res35(v, l, mid) && res35(v, mid + 1, r);
}


int main39()
{
	vector<int> v = {7,4,6,5};
	if (res35(v, 0, 3)) {
		cout << "是一个二叉搜索树的后序遍历" << endl;
	}
	else {
		cout << "不是一个二叉搜索树的后序遍历" << endl;
	}
	system("pause");
	return 0;
}