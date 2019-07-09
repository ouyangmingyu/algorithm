#include<iostream>
#include<string>
#include<stack>
#include "Btree.h"

using namespace std;

bool Res28(TreeNode* root1, TreeNode* root2)
{
	if (root1 == nullptr&&root2 == nullptr) {
		return true;
	}
	if (root1 == nullptr || root2 == nullptr) {
		return false;
	}
	if (root1->val != root2->val) {
		return false;
	}

	return Res28(root1->left, root2->right) && Res28(root1->right, root2->left);
}

bool res28(TreeNode* root)
{
	return Res28(root, root);
}



void For_each2(TreeNode* root)
{
	if (root == nullptr) {
		return;
	}

	cout << root->val << " ";
	For_each2(root->left);
	For_each2(root->right);
}


int main32()
{
	TreeNode root1 = { 8,nullptr,nullptr };
	TreeNode node1 = { 6,nullptr,nullptr };
	TreeNode node2 = { 6,nullptr,nullptr };
	TreeNode node3 = { 5,nullptr,nullptr };
	TreeNode node4 = { 7,nullptr,nullptr };
	TreeNode node5 = { 7,nullptr,nullptr };
	TreeNode node6 = { 5,nullptr,nullptr };

	root1.left = &node1;
	root1.right = &node2;

	node1.left = &node3;
	node1.right = &node4;

	node2.left = &node5;
	node2.right = &node6;

	if (res28(&root1)) {
		cout << "是对称的二叉树" << endl;
	}
	else {
		cout << "是不对称的" << endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}