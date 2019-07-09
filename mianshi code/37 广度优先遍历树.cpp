#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include "zx.h"
#include<queue>

using namespace std;



void BFSTree(TreeNode* root)
{
	if (root == nullptr) {
		return;
	}

	queue<TreeNode*> q;
	q.push(root);

	while (q.size()) {
		TreeNode* ele = q.front();
		cout << ele->val << " ";
		q.pop();
		if (ele->left) {
			q.push(ele->left);
		}
		if (ele->right) {
			q.push(ele->right);
		}
	}
}



int main37() {

	system("pause");
	return EXIT_SUCCESS;
}

