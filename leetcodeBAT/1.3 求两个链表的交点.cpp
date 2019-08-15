#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

#include "zx.h"

using namespace std;

int getListLen(ListNode* head) {
	int len = 0;
	while (head) {
		len++;
		head = head->next;
	}
	return len;
}

void forward_List(ListNode*& head, int step)
{
	while (head&&step) {
		head = head->next;
		step--;
	}
}


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	int lena = getListLen(headA);
	int lenb = getListLen(headB);

	if (lena > lenb) {
		int dis = lena - lenb;
		forward_List(headA, dis);
	}
	else {
		int dis = lenb - lena;
		forward_List(headB, dis);
	}
	while (headA&&headB) {
		if (headA == headB) {
			return headA;
		}
		headA = headA->next;
		headB = headB->next;
	}
	return nullptr;
}

int main13()
{
	return 0;
}