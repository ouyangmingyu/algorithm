#include<iostream>
#include<string>
#include<stack>
#include "linklist.h"

using namespace std;


bool hashuan(ListNode* phead,int& n)
{
	//快指针
	ListNode* qnode = phead;
	//慢指针
	ListNode* snode = phead;

	while (qnode->next) {
		qnode = qnode->next;
		if (!qnode->next) break;
		qnode = qnode->next;
		snode = snode->next;

		if (qnode == snode) {
			ListNode* pnode = snode;
			while (snode->next) {
				snode = snode->next;
				if (snode == pnode) {
					n++;
					return true;
				}
				n++;
			}
		}
	}
	return false;
}

ListNode* rukou(ListNode* phead)
{
	if (phead == nullptr) {
		return nullptr;
	}
	int n = 0;

	if (hashuan(phead, n)) {
		ListNode* lnode = phead;
		//慢指针
		ListNode* rnode = phead;
		
		int i = 0;
		while (i<n) {
			rnode = rnode->next;
			i++;
		}

		while (true) {
			if (rnode == lnode) {
				return lnode;
			}
			else {
				rnode = rnode->next;
				lnode = lnode->next;
			}
		}
	}
	else {
		return nullptr;
	}
}


int main27()
{
	ListNode head = { -1,nullptr };
	ListNode node1 = { 1,nullptr };
	ListNode node2 = { 2,nullptr };
	ListNode node3 = { 3,nullptr };
	ListNode node4 = { 4,nullptr };
	ListNode node5 = { 5,nullptr };
	ListNode node6 = { 6,nullptr };

	head.next = &node1;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = &node6;
	node6.next = &node3;

	

	ListNode* res = rukou(&head);

	if (res == nullptr) {
		cout << "不符合题意" << endl;
	}
	else {
		cout << "链表环的入口节点为：" << res->val << endl;
	}



	system("pause");
	return EXIT_SUCCESS;
}