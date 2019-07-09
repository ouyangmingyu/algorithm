#include<iostream>
#include<string>

using namespace std;

struct TreeNode
{
	char val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* m_parent;
};

void For_eachBT(TreeNode* root)
{
	if (root == nullptr)
		return;
	For_eachBT(root->left);
	cout << root->val << " ";
	For_eachBT(root->right);
}

TreeNode* GetNext(TreeNode* pNode)
{
	if (pNode == nullptr) {
		return nullptr;
	}

	TreeNode* pNext = nullptr;

	if (pNode->right) {
		TreeNode* TreeNode = pNode->right;
		while (TreeNode->left != nullptr) {
			TreeNode = TreeNode->left;
		}
		pNext=TreeNode;
	}
	else if (pNode->m_parent != nullptr) {
		TreeNode* pCurrent = pNode;
		TreeNode* pParent = pNode->m_parent;
		while (pParent!=nullptr&&pCurrent == pParent->right) {
			pCurrent = pParent;
			pParent = pParent->m_parent;
		}
		pNext=pParent;
	}
	return pNext;
}

int main10()
{
	struct TreeNode nodeA = { 'A', NULL, NULL,NULL };
	struct TreeNode nodeB = { 'B', NULL, NULL,NULL };
	struct TreeNode nodeC = { 'C', NULL, NULL,NULL };
	struct TreeNode nodeD = { 'D', NULL, NULL,NULL };
	struct TreeNode nodeE = { 'E', NULL, NULL,NULL };
	struct TreeNode nodeF = { 'F', NULL, NULL,NULL };
	struct TreeNode nodeG = { 'G', NULL, NULL,NULL };
	struct TreeNode nodeH = { 'H', NULL, NULL,NULL };
	struct TreeNode nodeI = { 'I', NULL, NULL,NULL };

	nodeA.left = &nodeB;
	nodeA.right = &nodeC;
	
	nodeB.m_parent = &nodeA;
	nodeB.left = &nodeD;
	nodeB.right = &nodeE;

	nodeC.m_parent = &nodeA;
	nodeC.left = &nodeF;
	nodeC.right = &nodeG;

	nodeD.m_parent = &nodeB;

	nodeE.m_parent = &nodeB;
	nodeE.left = &nodeH;
	nodeE.right = &nodeI;

	nodeF.m_parent = &nodeC;
	
	nodeG.m_parent = &nodeC;

	nodeH.m_parent = &nodeE;

	nodeI.m_parent = &nodeE;

	For_eachBT(&nodeA);

	cout << endl;
	cout << GetNext(&nodeA)->val << endl;
	cout << GetNext(&nodeB)->val << endl;
	cout << GetNext(&nodeC)->val << endl;
	cout << GetNext(&nodeD)->val << endl;
	cout << GetNext(&nodeE)->val << endl;
	cout << GetNext(&nodeF)->val << endl;
	//cout << GetNext(&nodeG)->val << endl;
	cout << GetNext(&nodeH)->val << endl;
	cout << GetNext(&nodeI)->val << endl;

	system("pause");
	return EXIT_SUCCESS;
}