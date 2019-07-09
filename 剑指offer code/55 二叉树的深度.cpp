#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>
#include "Btree.h"


using namespace std;



int TreeDepth(TreeNode* pRoot)
{
	if (pRoot == nullptr) {
		return 0;
	}
	int ldept = TreeDepth(pRoot->left);
	int rdept = TreeDepth(pRoot->right);

	return ldept > rdept ? ldept + 1 : rdept + 1;
}

bool IsBalanced_Solution(TreeNode* pRoot) {
	if (pRoot == nullptr) {
		return true;
	}
	int ldept = TreeDepth(pRoot->left);
	int rdept = TreeDepth(pRoot->right);

	if ((ldept - rdept < -1) || (ldept - rdept > 1)) {
		return false;
	}

	return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
}

int main55()
{

	system("pause");
	return EXIT_SUCCESS;
}