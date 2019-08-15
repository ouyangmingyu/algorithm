#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

#include "zx.h"

using namespace std;



ListNode *detectCycle(ListNode *head) {
	ListNode* slow = head;
	ListNode* quick = head;
	ListNode* meet = nullptr;
	while (quick) {
		slow = slow->next;
		quick = quick->next;
		if (quick == nullptr) {
			return nullptr;
		}
		quick = quick->next;
		if (quick == slow) {
			meet = quick;
			slow = head;
			break;
		}
	}
	if (meet == nullptr) {
		return nullptr;
	}
	while (true) {
		slow = slow->next;
		quick = quick->next;
		if (slow == quick) {
			return slow;
		}
	}
	return nullptr;
}

int main14()
{
	ListNode n1(1);
	ListNode n2(2);
	n1.next = &n2;
	n2.next = &n1;
	ListNode* res = detectCycle(&n1);
	if (res) {
		cout << res->val << endl;
	}
	else {
		cout << "Ã»ÓÐ»·" << endl;
	}
	system("pause");
	return 0;
}