#pragma once
#include<iostream>
#include<string>
#include<stack>

using namespace std;


struct ListNode {
	int val;
	ListNode* next;
};

struct ListNode* Init_LinkList();
void insertbyvalue_LinkList(ListNode** pHead, int value);
void insertbyvalue_LinkList(ListNode** pHead, int value);
void Foreach_LinkList(ListNode* pHead);

