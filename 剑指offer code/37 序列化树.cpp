//#include<iostream>
//#include<string>
//#include<stack>
//#include<vector>
//#include "Btree.h"
//
//using namespace std;
//
//
//
//
//class Solution {
//public:
//	void func(TreeNode *root, vector<char>& res)
//	{
//		if (root == nullptr) {
//			res.push_back('$');
//			return;
//		}
//		res.push_back(root->val);
//		func(root->left, res);
//		func(root->right, res);
//	}
//	char* Serialize(TreeNode *root) {
//		vector<char> res;
//		if (root == nullptr) {
//			res.push_back('$');
//			return ;
//		}
//		func(root, res);
//		int len = res.size();
//		char c[100] = { 0 };
//		for (int i = 0; i < len; i++) {
//			c[i] = res[i];
//		}
//
//		return c;
//	}
//
//
//	TreeNode* Deserialize(char *str) {
//		
//	}
//};