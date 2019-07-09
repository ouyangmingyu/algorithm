#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include "Btree.h"

using namespace std;


void func(TreeNode* root, vector<TreeNode*>& v)
{
	if (root == nullptr) {
		return;
	}
	if (root->left) {
		func(root->left, v);
	}
	v.push_back(root);
	if (root->right) {
		func(root->right, v);
	}
}

TreeNode* res37(TreeNode* root, vector<TreeNode*>& v)
{
	if (root == nullptr) {
		return nullptr;
	}

	
	func(root, v);

	int len = v.size();

	if (len == 1) {
		return v[0];
	}

	for (int i = 0; i < len; i++) {
		if (i = 0) {
			v[0]->left = nullptr;
			v[0]->right = v[1];
			continue;
		}
		if (i = len - 1) {
			v[i]->left = v[i - 1];
			v[i]->right = nullptr;
			continue;
		}

		v[i]->left = v[i - 1];
		v[i]->right = v[i + 1];
	}

	return v[0];
}


int main41()
{
	TreeNode root = { 10,nullptr,nullptr };
	TreeNode node1 = { 6,nullptr,nullptr };
	TreeNode node2 = { 14,nullptr,nullptr };
	TreeNode node3 = { 4,nullptr,nullptr };
	TreeNode node4 = { 8,nullptr,nullptr };
	TreeNode node5 = { 12,nullptr,nullptr };
	TreeNode node6 = { 16,nullptr,nullptr };

	root.left = &node1;
	root.right = &node2;

	node1.left = &node3;
	node1.right = &node4;

	node2.left = &node5;
	node2.right = &node6;

	vector<TreeNode*> v;

	res37(&root, v);

	for_each(v.begin(), v.end(), [](TreeNode* ele) {cout << (*ele).val; });


	system("pause");
	return EXIT_SUCCESS;
}