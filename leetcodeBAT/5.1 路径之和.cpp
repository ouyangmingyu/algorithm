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
#include "zx.h"

using namespace std;

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		cs = 0;
		pathSumc(root, sum);
		return res;
	}

	void pathSumc(TreeNode* root, int sum) {
		if (root == nullptr) {
			return;
		}
		if (root->left == nullptr&&root->right == nullptr) {
			cs += root->val;
			cv.push_back(root->val);
			if (cs == sum) {
				res.push_back(cv);
			}
			cs -= root->val;
			cv.pop_back();
			return;
		}
		cs += root->val;
		cv.push_back(root->val);
	
		if (root->left) {
			pathSumc(root->left, sum);
		}
		if (root->right) {
			pathSumc(root->right, sum);
		}

		cs -= root->val;
		cv.pop_back();
	}

private:
	int cs;
	vector<int> cv;
	vector<vector<int>> res;
};