#include<iostream>
#include<string>
#include<stack>

#include "Btree.h"

using namespace std;

bool hassub(TreeNode* root1, TreeNode* root2)
{
	if (root2 == nullptr) {
		return true;
	}
	if (root1 == nullptr) {
		return false;
	}
	if (root1->val != root2->val) {
		return false;
	}

	return hassub(root1->left, root2->left) && hassub(root1->right, root2->right);
}

bool res26(TreeNode* root1, TreeNode* root2)
{
	bool res = false;
	if (root1 != nullptr&&root2 != nullptr) {
		if (root1->val == root2->val) {
			res = hassub(root1, root2);
		}
		if (!res) {
			res = res26(root1->left, root2);
		}
		if (!res) {
			res = res26(root1->right, root2);
		}
	}
	return res;
}


int main30()
{
	TreeNode root1 = { 8,nullptr,nullptr };
	TreeNode node1 = { 8,nullptr,nullptr };
	TreeNode node2 = { 7,nullptr,nullptr };
	TreeNode node3 = { 9,nullptr,nullptr };
	TreeNode node4 = { 2,nullptr,nullptr };
	TreeNode node5 = { 4,nullptr,nullptr };
	TreeNode node6 = { 7,nullptr,nullptr };

	root1.left = &node1;
	root1.right = &node2;
	node1.left = &node3;
	node1.right = &node4;
	node4.left = &node5;
	node4.right = &node6;

	TreeNode root2 = { 8,nullptr,nullptr };
	TreeNode nodeA = { 9,nullptr,nullptr };
	TreeNode nodeB = { 2,nullptr,nullptr };

	root2.left = &nodeA;
	root2.right = &nodeB;

	if (res26(&root1, &root2)) {
		cout << "是一棵子树" << endl;
	}
	else {
		cout << "不是一棵子树" << endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}