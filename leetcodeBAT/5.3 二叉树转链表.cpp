#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<functional>
#include<queue>
#include<queue>
#include<stack>
#include<set>
#include<list>
#include "zx.h"

using namespace std;

class Solution {
public:
	void flatten(TreeNode* root) {
		TreeNode* last = nullptr;
		flattenc(root, last);
	}
	void flattenc(TreeNode* root, TreeNode*& last) {
		if (!root) {
			return;
		}
		if (!root->left && !root->right) {
			last = root;
			return;
		}
		TreeNode* leftn = root->left;
		TreeNode* rightn = root->right;
		TreeNode* left_last = nullptr;
		TreeNode* right_last = nullptr;
		if (leftn) {
			flattenc(leftn, left_last);
			root->left = nullptr;
			root->right = leftn;
			last = left_last;
		}
		if (rightn) {
			flattenc(rightn, right_last);
			if (left_last) {
				left_last->right =rightn;
			}
			last = right_last;
		}
	}
};