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
	vector<int> rightSideView(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);
		TreeNode* last = root;
		TreeNode* nlast = root;
		vector<int> res;
		while (q.size()) {
			TreeNode* tmp = q.front();
			q.pop();
			if (tmp->left) {
				q.push(tmp->left);
				nlast = tmp->left;
			}
			if (tmp->right) {
				q.push(tmp->right);
				nlast = tmp->right;
			}
			if (tmp == last) {
				last = nlast;
				res.push_back(tmp->val);
			}
		}
		return res;
	}
};