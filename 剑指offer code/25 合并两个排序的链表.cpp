#include<iostream>
#include<string>
#include<stack>


#include"linklist.h"

using namespace std;


ListNode* res25(ListNode* h1,ListNode* h2)
{
	if (h1 == nullptr) {
		return h2;
	}
	if (h2 == nullptr) {
		return h1;
	}

	ListNode* mh = nullptr;

	if (h1->val < h2->val) {
		mh = h1;
		mh->next = res25(h1->next, h2);
	}

	if (h1->val > h2->val) {
		mh = h2;
		mh->next = res25(h1, h2->next);
	}

	return mh;
}


int main29()
{
	
	ListNode* h1 = Init_LinkList();
	Foreach_LinkList(h1);

	ListNode* h2 = Init_LinkList();
	Foreach_LinkList(h2);

	ListNode* h3 = res25(h1, h2);
	Foreach_LinkList(h3);

	system("pause");
	return EXIT_SUCCESS;
}