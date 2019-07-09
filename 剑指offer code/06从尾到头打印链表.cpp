#include<iostream>
#include<string>
#include<stack>

#include "linklist.h"

using namespace std;




void PrintReversingly_LinkList(ListNode* pHead)
{
	//·ÇµÝ¹é
	//if (pHead == nullptr) {
	//	return;
	//}
	//std::stack<ListNode*> nodes;
	//ListNode* pNode = pHead;

	//while (pNode) {
	//	nodes.push(pNode);
	//	pNode = pNode->next;
	//}
	//while (!nodes.empty()) {
	//	cout << nodes.top()->val << " ";
	//	nodes.pop();
	//}
	//µÝ¹é
	if (!pHead) {
		return;
	}
	if (pHead->next)
	{
		PrintReversingly_LinkList(pHead->next);
	}
	cout << pHead->val << " ";
}


int main08()
{
	struct ListNode* pHead = Init_LinkList();
	Foreach_LinkList(pHead);
	insertbyvalue_LinkList(&pHead, 20);
	Foreach_LinkList(pHead);
	PrintReversingly_LinkList(pHead);
	cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}




