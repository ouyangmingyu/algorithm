#include<iostream>
#include<string>
#include<stack>
#include "Btree.h"

using namespace std;


void res27(TreeNode* root)
{
	if (root == nullptr) {
		return;
	}
	if (root->left == nullptr&&root->right == nullptr) {
		return;
	}
	TreeNode* TreeNode = root->left;
	root->left = root->right;
	root->right = TreeNode;
	if (root->left) {
		res27(root->left);
	}
	if (root->right) {
		res27(root->right);
	}
}

void For_each(TreeNode* root)
{
	if (root == nullptr) {
		return;
	}

	cout << root->val << " ";
	For_each(root->left);
	For_each(root->right);
}


int main31()
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

	For_each(&root1);
	cout << endl;

	res27(&root1);

	For_each(&root1);
	cout << endl;

	system("pause");
	return EXIT_SUCCESS;
}