#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include"Btree.h"

using namespace std;

void res34(TreeNode* root)
{
	stack<TreeNode*> s[2];
	int n1 = 1;
	int n2 = 0;
	s[0].push(root);

	while (s[0].size() || s[1].size()) {
		while (s[0].size()) {
			TreeNode* n = s[0].top();
			s[0].pop();
			cout << n->val << " ";
			n1--;
			if (n->left) {
				s[1].push(n->left);
				n2++;
			}
			if (n->right) {
				s[1].push(n->right);
				n2++;
			}
			if (n1 == 0) {
				cout << endl;
				n1 = n2;
				n2 = 0;
			}
		}
		while (s[1].size()) {
			TreeNode* n = s[1].top();
			s[1].pop();
			cout << n->val << " ";
			n1--;
		
			if (n->right) {
				s[0].push(n->right);
				n2++;
			}
			if (n->left) {
				s[0].push(n->left);
				n2++;
			}
			if (n1 == 0) {
				cout << endl;
				n1 = n2;
				n2 = 0;
			}
		}
	}
}


int main38()
{

	TreeNode root = { 8,nullptr,nullptr };
	TreeNode node1 = { 6,nullptr,nullptr };
	TreeNode node2 = { 10,nullptr,nullptr };
	TreeNode node3 = { 5,nullptr,nullptr };
	TreeNode node4 = { 7,nullptr,nullptr };
	TreeNode node5 = { 9,nullptr,nullptr };
	TreeNode node6 = { 11,nullptr,nullptr };

	root.left = &node1;
	root.right = &node2;

	node1.left = &node3;
	node1.right = &node4;

	node2.left = &node5;
	node2.right = &node6;

	res34(&root);

	system("pause");
	return EXIT_SUCCESS;
}