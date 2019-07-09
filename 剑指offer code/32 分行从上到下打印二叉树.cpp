#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include"Btree.h"

using namespace std;

void res33(TreeNode* root)
{
	//广度优先(利用队列)
	queue<TreeNode*> q;

	q.push(root);

	int n1 = 1;
	int n2 = 0;

	while (q.size()) {
		TreeNode* v = q.front();
		cout << v->val << " ";
		q.pop();
		n1--;
		if (v->left) {
			q.push(v->left);
			n2++;
		}
		if (v->right) {
			q.push(v->right);
			n2++;
		}
		if (n1 == 0) {
			cout << endl;
			n1 = n2;
			n2 = 0;
		}
	}
}



int main37()
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

	res33(&root);

	system("pause");
	return EXIT_SUCCESS;
}