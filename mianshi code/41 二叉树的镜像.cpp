#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

#include "zx.h"

using namespace std;

class solution {
public:
	static void BTjx(TreeNode* root)
	{
		if (root == nullptr) {
			return;
		}
		swap(root->left, root->right);
		BTjx(root->left);
		BTjx(root->right);
	}
};





int main41() {
	
	system("pause");
	return EXIT_SUCCESS;
}

