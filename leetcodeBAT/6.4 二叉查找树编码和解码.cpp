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

class Codec {
public:
	string itoa(int& num) {
		string s;
		if (num == 0) {
			s = "0$";
			return s;
		}
		while (num) {
			s += num % 10 + '0';
			num /= 10;
		}
		reverse(s.begin(), s.end());
		s += '$';
		return s;
	}

	void BST_pre(TreeNode* root, string& res) {
		if (root == nullptr) {
			return;
		}
		res += itoa(root->val);
		BST_pre(root->left, res);
		BST_pre(root->right, res);
	}
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res;
		if (root == nullptr) {
			return string();
		}
		BST_pre(root, res);
		return res;
	}
	void insert(TreeNode* root, TreeNode* node) {
		if (root == nullptr || node == nullptr) {
			return;
		}
		if (node->val < root->val) {
			if (root->left) {
				insert(root->left, node);
			}
			else {
				root->left = node;
			}
		}
		else {
			if (root->right) {
				insert(root->right, node);
			}
			else {
				root->right = node;
			}
		}
	}
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		int len = data.size();
		if (len == 0) {
			return nullptr;
		}
		vector<TreeNode*> node_vec;
		int val = 0;
		for (int i = 0; i < len; i++) {
			if (data[i] == '$') {
				node_vec.push_back(new TreeNode(val));
				val = 0;
			}
			else {
				val = val * 10 + (data[i] - '0');
			}
		}
		len = node_vec.size();
		for (int i = 0; i < len; i++) {
			insert(node_vec[0], node_vec[i]);
		}
		return node_vec[0];
	}
};
//
//int main()
//{
//	Codec s;
//	TreeNode* root = new TreeNode(2);
//	TreeNode* node1 = new TreeNode(1);
//	TreeNode* node2 = new TreeNode(3);
//	root->left = node1;
//	root->right = node2;
//	string str = s.serialize(root);
//	cout << str << endl;
//	TreeNode* res = s.deserialize(str);
//	str = s.serialize(res);
//	cout << str << endl;
//	
//	system("pause");
//	return 0;
//}