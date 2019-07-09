#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>
#include "Btree.h"


using namespace std;

void zhongxu(TreeNode* pRoot, vector<TreeNode*>& v)
{
	if (pRoot == nullptr) {
		return;
	}
	zhongxu(pRoot->left, v);
	v.push_back(pRoot);
	zhongxu(pRoot->right, v);
}


TreeNode* KthNode(TreeNode* pRoot, int k)
{
	if (pRoot == nullptr || k<1) {
		return nullptr;
	}
	vector<TreeNode*> v;
	zhongxu(pRoot, v);
	int len = v.size();
	if (k>len) {
		return nullptr;
	}
	return v[k - 1];
}


int main54()
{

	system("pause");
	return EXIT_SUCCESS;
}