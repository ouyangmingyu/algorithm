#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

#include "zx.h"

using namespace std;


class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* pre_head = nullptr;
		int tm = m;
		int tn = n;
		int chage_len = n - m + 1;
		ListNode* res = head;
		while (--tm&&head) {
			pre_head = head;
			head = head->next;
		}
		ListNode* modify_tail = head;
		ListNode* new_head = nullptr;
		while (head&&chage_len) {
			ListNode* next = head->next;
			head->next = new_head;
			new_head = head;
			head = next;
			chage_len--;
		}
		modify_tail->next = head;
		if (pre_head) {
			pre_head->next = new_head;
		}
		else {
			res = new_head;
		}
		return res;
	}
};