#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>

#include "zx.h"

using namespace std;

ListNode* MergeTwoList(ListNode* list1, ListNode* list2)
{
	if (list1 == nullptr) {
		return list2;
	}
	if (list2 == nullptr) {
		return list1;
	}

	ListNode* res = new ListNode(0);
	ListNode* tmp = res;
	while (list1&&list2) {
		if (list1->val < list2->val) {
			tmp->next = list1;
			tmp = list1;
			list1 = list1->next;
		}
		else {
			tmp->next = list2;
			tmp = list2;
			list2 = list2->next;
		}
	}
	if (list1) {
		tmp->next = list1;
	}
	else {
		tmp->next = list2;
	}

	return res->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	int len = lists.size();
	if (len == 0) {
		return nullptr;
	}
	if (len == 1) {
		return lists[0];
	}
	if (len == 2) {
		return MergeTwoList(lists[0], lists[1]);
	}

	int m = len / 2;
	vector<ListNode*> lists1;
	vector<ListNode*> lists2;

	for (int i = 0; i < m; i++) {
		lists1.push_back(lists[i]);
	}

	for (int i = m; i < len; i++) {
		lists2.push_back(lists[i]);
	}

	ListNode* l1 = mergeKLists(lists1);
	ListNode* l2 = mergeKLists(lists2);

	return MergeTwoList(l1, l2);
}

int mainhb()
{
	ListNode n1(1);
	ListNode n2(2);
	n1.next = &n2;
	n2.next = &n1;

	system("pause");
	return 0;
}
