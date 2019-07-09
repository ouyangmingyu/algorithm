#include<iostream>
#include<string>

#include "Btree.h"

using namespace std;



TreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	int rootvalue = startPreorder[0];
	TreeNode* root = new TreeNode();
	root->val = rootvalue;
	root->left = nullptr;
	root->right = nullptr;
	if (startPreorder == endPreorder) {
		if (startInorder == endInorder&&*startInorder == *startPreorder) {
			return root;
		}
		else {
			throw std::exception("invalid input");
		}
	}
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder&&*rootInorder != rootvalue) {
		++rootInorder;
	}
	if (rootInorder == endInorder&&*rootInorder != rootvalue) {
		throw std::exception("invalid input");
	}

	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;

	if (leftLength > 0) {
		root->left = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder-startPreorder) {
		root->right = ConstructCore(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
	}
	return root;
}

TreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0) {
		return nullptr;
	}
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}



int main09()
{
	int preorder[8] = { 1,2,4,7,3,5,6,8 };
	int inorder[8] = { 4,7,2,1,5,3,8,6 };
	TreeNode* root = Construct(preorder, inorder, 8);
	cout << root->right->left->val << endl;
	system("pause");
	return EXIT_SUCCESS;
}