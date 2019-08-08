#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

#include "zx.h"

using namespace std;

class solution39 {
public:
	static int Maxdistanceoftree(TreeNode* root,int maxdis)
	{
		if (root == nullptr) {
			return -1;
		}
		int leftheight = Maxdistanceoftree(root->left,maxdis) + 1;
		int rightheight = Maxdistanceoftree(root->right, maxdis) + 1;
		maxdis = (leftheight + rightheight) > maxdis ? (leftheight + rightheight) : maxdis;
		return leftheight > rightheight ? leftheight : rightheight;
	}
};





int main39() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	system("pause");
	return EXIT_SUCCESS;
}

