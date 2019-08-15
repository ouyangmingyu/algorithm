#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* new_head = nullptr;
		while (head) {
			ListNode* next = head->next;
			head->next = new_head;
			new_head = head;
			head = next;
		}
		return new_head;
	}
};