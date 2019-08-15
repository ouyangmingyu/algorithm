#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<list>
#include "zx.h"

using namespace std;


struct BTreeNode
{
	int val;
	BTreeNode* left;
	BTreeNode* right;
	int count;
	BTreeNode(int x,int c) : val(x),count(c),left(NULL), right(NULL) {}
};

class Solution {
public:

	void BST_insert(BTreeNode* root, BTreeNode* node,int count_small) {
		if (root == nullptr || node == nullptr) {
			return;
		}
		if (node->val <= root->val) {
			root->count++;
			if (root->left) {
				BST_insert(root->left, node, count_small);
			}
			else {
				root->left = node;
			}
		}
		else {
			count_small += root->count + 1;
			if (root->right) {
				BST_insert(root->right, node, count_small);
			}
			else {
				root->right = node;
			}
		}
	}

	vector<int> countSmaller(vector<int>& nums) {
		vector<BTreeNode* > tmp;
		int len = nums.size();
		for (int i = len - 1; i >= 0; i--) {
			tmp.push_back(new BTreeNode(nums[i], 0));
		}
		vector<int> res(len, 0);
		for (int i = 0; i < len; i++) {
			int count_small = 0;
			BST_insert(tmp[0], tmp[i], count_small);
			res[i] = count_small;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> v = { -1,-1 };
	vector<int> res = s.countSmaller(v);
	for_each(res.begin(), res.end(), [](int num) {cout << num << " "; });
	system("pause");
	return 0;
}