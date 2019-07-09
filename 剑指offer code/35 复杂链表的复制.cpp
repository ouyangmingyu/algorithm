#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (!pHead) return NULL;
	RandomListNode *currNode = pHead;
	//连接
	while (currNode) {
		RandomListNode *TreeNode = new RandomListNode(currNode->label);
		TreeNode->next = currNode->next;
		currNode->next = TreeNode;
		currNode = TreeNode->next;
	}
	currNode = pHead;
	//第二个指针
	while (currNode) {
		RandomListNode *TreeNode = currNode->next;
		if (currNode->random) {
			TreeNode->random = currNode->random->next;
		}
		currNode = TreeNode->next;
	}
	//拆分
	RandomListNode *pCloneHead = pHead->next;
	RandomListNode *tmp;
	currNode = pHead;
	while (currNode->next) {
		tmp = currNode->next;
		currNode->next = tmp->next;
		currNode = tmp;
	}
	return pCloneHead;
	}

};
