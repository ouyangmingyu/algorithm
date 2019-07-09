#include<iostream>
#include<string>
#include<stack>
#include "linklist.h"

using namespace std;

int daoshuK(ListNode* head,int k)
{
	if (head == nullptr||k<=0) {
		return -1;
	}
	ListNode* pres = head;
	ListNode* ptail = head;
	
	for (int i = 0; i < k-1; i++) {
		if (ptail->next) {
			ptail = ptail->next;
		}
		else {
			return -1;
		}
	}

	while (true) {
		if (ptail->next == nullptr) {
			return pres->val;
		}
		else {
			ptail = ptail->next;
			pres = pres->next;
		}

	}
	
}


int main26()
{
	ListNode* head = Init_LinkList();

	Foreach_LinkList(head);

	int res = daoshuK(head, 3);

	cout << "元素的倒数第三个值为：" << res << endl;

	system("pause");
	return EXIT_SUCCESS;
}