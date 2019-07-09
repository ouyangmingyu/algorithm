#include "linklist.h"

struct ListNode* Init_LinkList()
{
	struct ListNode* pHead = new struct ListNode;
	pHead->val = -1;
	pHead->next = nullptr;

	struct ListNode* pRear = pHead;
	int val = -1;
	while (true) {
		cout << "请输入要插入的数字：";
		cin >> val;
		if (val == -1) {
			break;
		}
		struct ListNode* newNode = new struct ListNode;
		newNode->val = val;
		newNode->next = nullptr;
		pRear->next = newNode;
		pRear = newNode;
	}
	return pHead;
}



void insertbyvalue_LinkList(ListNode** pHead, int value)
{
	struct ListNode* pnewNode = new struct ListNode;
	pnewNode->val = value;
	pnewNode->next = nullptr;

	if (*pHead == nullptr) {
		*pHead = pnewNode;
	}
	else {
		struct ListNode* pNode = *pHead;
		while (pNode->next) {
			pNode = pNode->next;
		}
		pNode->next = pnewNode;
	}
}

void Foreach_LinkList(ListNode* pHead)
{
	if (pHead == nullptr) {
		return;
	}
	struct ListNode* pNode = pHead;
	while (pNode) {
		cout << pNode->val << " ";
		pNode = pNode->next;
	}
	cout << endl;
}