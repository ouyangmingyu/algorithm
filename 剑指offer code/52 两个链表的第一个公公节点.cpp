#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>
#include "linklist.h"

using namespace std;

ListNode* res52(ListNode* pHead1, ListNode* pHead2)
{
	ListNode* p1 = pHead1;
	ListNode* p2 = pHead2;
	int len1 = 0, len2 = 0;
	while (p1) {
		len1++;
		p1 = p1->next;
	}
	while (p2) {
		len2++;
		p2 = p2->next;
	}
	if (len1 > len2) {
		p1 = pHead1;
		p2 = pHead2;
		int len = len1 - len2;
		for (int i = 0; i < len; i++) {
			p1 = p1->next;
		}
		while (true) {
			if ((p1->val == p2->val) && (p1->next == p2->next)) {
				return p1;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	else {
		p1 = pHead1;
		p2 = pHead2;
		int len = len2 - len1;
		for (int i = 0; i < len; i++) {
			p2 = p2->next;
		}
		while (true) {
			if ((p1->val == p2->val) && (p1->next == p2->next)) {
				return p1;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
	}
}

int tmain56()
{
	ListNode p1 = { 1,nullptr };
	ListNode node1 = { 2,nullptr };
	ListNode node2 = { 3,nullptr };
	ListNode node3 = { 6,nullptr };
	ListNode node4 = { 7,nullptr };

	p1.next = &node1;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;

	ListNode p2 = { 4,nullptr };
	ListNode pnode1 = { 5,nullptr };
	
	p2.next = &pnode1;
	pnode1.next = &node3;

	
	ListNode* p = res52(&p1, &p2);
	cout << p->val << endl;


	system("pause");
	return EXIT_SUCCESS;
}