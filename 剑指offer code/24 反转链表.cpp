#include<iostream>
#include<string>
#include<stack>


#include"linklist.h"

using namespace std;


ListNode* fanzhuan(ListNode* head)
{
	if (head == nullptr) {
		return nullptr;
	}
	if (head->next == nullptr) {
		return head;
	}

	ListNode* TreeNode = head;
	ListNode* next = head->next;
	TreeNode->next = nullptr;

	while (next->next) {
		ListNode* nnext = next->next;
		next->next = TreeNode;
		TreeNode = next;
		next = nnext;
		if (next->next == nullptr) {
			next->next = TreeNode;
			break;
		}
	}

	return next;
}


int main28()
{
	ListNode* head = Init_LinkList();

	Foreach_LinkList(head);

	ListNode* nhead = fanzhuan(head);

	Foreach_LinkList(nhead);


	system("pause");
	return EXIT_SUCCESS;
}