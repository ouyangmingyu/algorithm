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

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		pt = p;
		qt = q;
		findpath(root);
		return getres();
	}
	void findpath(TreeNode* root) {
		if (root == nullptr||fin==2) {
			return;
		}
		cl.push_back(root);
		if (root == pt) {
			l1 = cl;
			fin++;
		}
		if (root == qt) {
			l2 = cl;
			fin++;
		}
		findpath(root->left);
		findpath(root->right);
		cl.pop_back();
	}
	TreeNode* getres() {
		int len1 = l1.size();
		int len2 = l2.size();
		int min = len1 < len2 ? len1 : len2;
		TreeNode* res;
		for (int i = 0; i < min; i++) {
			if (l1[i] == l2[i]) {
				res = l1[i];
			}
			else {
				break;
			}
		}
		return res;
	}
private:
	TreeNode* pt;
	TreeNode* qt;
	int fin=0;
	vector<TreeNode* > l1;
	vector<TreeNode* > l2;
	vector<TreeNode* > cl;
};