#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include "Btree.h"

using namespace std;

void res36(TreeNode* root,int sum,int& sum1, vector<int>& path)
{
	if (root == nullptr) {
		return;
	}

	sum1 += root->val;
	path.push_back(root->val);
	//叶节点
	if (!root->left && !root->right) {
		//等于目标值
		if (sum1 == sum) {			
			for_each(path.begin(), path.end(), [](int num) {cout << num<<" "; });
			cout << endl;			
		}
	}
	//非叶子结点
	if (root->left || root->right) {
		if (root->left) {
			res36(root->left, sum, sum1, path);
			
		}
		if (root->right) {
			res36(root->right, sum, sum1, path);
			
		}
	}
	path.pop_back();
	sum1 -= root->val;
}


int main40()
{
	TreeNode root = { 10,nullptr,nullptr };
	TreeNode node1 = { 5,nullptr,nullptr };
	TreeNode node2 = { 12,nullptr,nullptr };
	TreeNode node3 = { 4,nullptr,nullptr };
	TreeNode node4 = { 7,nullptr,nullptr };

	root.left = &node1;
	root.right = &node2;

	node1.left = &node3;
	node1.right = &node4;

	int sum = 22;
	int sum1 = 0;

	vector<int> path;

	res36(&root,sum,sum1,path);

	system("pause");
	return EXIT_SUCCESS;
}