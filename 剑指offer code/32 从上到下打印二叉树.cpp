#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include"Btree.h"

using namespace std;

void res32(TreeNode* root)
{
	//深度优先遍历(利用栈)
	//stack<TreeNode*> s;
	//cout << root->val << " ";
	//s.push(root->right);
	//s.push(root->left);
	//
	//while (s.size()) {
	//	TreeNode* v = s.top();
	//	cout << v->val << " ";
	//	s.pop();
	//	if (v->right) {
	//		s.push(v->right);
	//	}
	//	if (v->left) {
	//		s.push(v->left);
	//	}	
	//}
	//广度优先(利用队列)
	queue<TreeNode*> q;

	q.push(root);

	while (q.size()) {
		TreeNode* v = q.front();
		cout << v->val << " ";
		q.pop();
		if (v->left) {
			q.push(v->left);
		}
		if (v->right) {
			q.push(v->right);
		}
	}
	cout << endl;
}



int main36()
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

	res32(&root);

	system("pause");
	return EXIT_SUCCESS;
}