#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

#include "zx.h"

using namespace std;

void clonenext(Node* head) {
	Node* tmp = head;
	while (tmp) {
		Node* pc = new Node(tmp->val, tmp->next, nullptr);
		tmp->next = pc;
		tmp = pc->next;
	}
}

void clonerand(Node* head) {
	Node* tmp = head;
	while (tmp) {
		if (tmp->random) {
			tmp->next->random = tmp->random->next;
			tmp = tmp->next->next;
		}
		else {
			tmp = tmp->next->next;
		}
	}
}

Node* returnres(Node* head) {
	Node* tmp = head;
	Node* res = head->next;
	Node* rest = res;
	while (tmp) {
		tmp->next = rest->next;
		tmp = tmp->next;
		if (tmp) {
			rest->next = tmp->next;
			rest = rest->next;
		}
	}
	return res;
}

Node* copyRandomList(Node* head) {
	if (head == nullptr) {
		return nullptr;
	}
	clonenext(head);
	clonerand(head);
	return returnres(head);
}

int main16()
{
	ListNode n1(1);
	ListNode n2(2);
	n1.next = &n2;
	n2.next = &n1;

	system("pause");
	return 0;
}
