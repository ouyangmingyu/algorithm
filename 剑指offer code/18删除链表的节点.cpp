#include<iostream>
#include<string>
#include<stack>

#include "linklist.h"

using namespace std;


void DeleteNode(ListNode** phead, ListNode* pdelete)
{
	if (phead == nullptr || *phead == nullptr || pdelete == nullptr) {
		return;
	}
	cout << "将要删除"<<pdelete->val << endl;
	//不是尾节点
	if(pdelete->next){
		ListNode* pnext = pdelete->next;
		pdelete->val = pnext->val;
		pdelete->next = pnext->next;
		delete(pnext);
		pnext = nullptr;
		return;
	}
	//只有一个节点
	if (*phead == pdelete&&((pdelete->next)==nullptr)) {
		delete *phead;
		*phead = nullptr;
		pdelete =nullptr;
		return;
	}
	//删除尾节点
	{
		ListNode* pNode = *phead;
		while (pNode->next != pdelete) {
			pNode = pNode->next;
		}
		delete pNode->next;
		pNode->next = nullptr;
		pdelete = nullptr;
	}
}

int main22()
{
	struct ListNode* phead= Init_LinkList();
	struct ListNode* pdelete = phead->next;
	cout << "删除前" << endl;
	Foreach_LinkList(phead);
	DeleteNode(&phead, pdelete);
	cout << "删除后" << endl;
	Foreach_LinkList(phead);
	system("pause");
	return EXIT_SUCCESS;
}