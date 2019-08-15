#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

#include "zx.h"

using namespace std;



ListNode* partition(ListNode* head, int x) {
	ListNode less_phead(0);
	ListNode* less_p = &less_phead;
	ListNode greater_phead(0) ;
	ListNode* greater_p = &greater_phead;
	while (head) {
		if (head->val < x) {
			less_p->next = head;
			less_p = head;
		}
		else {
			greater_p->next = head;
			greater_p = head;
		}
		head = head->next;
	}
	less_p->next = greater_phead.next;
	greater_p->next = nullptr;
	return less_phead.next;
}

int main15()
{
	ListNode n1(1);
	ListNode n2(2);
	n1.next = &n2;
	n2.next = &n1;
	
	system("pause");
	return 0;
}
