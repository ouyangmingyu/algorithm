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
	cout << "��Ҫɾ��"<<pdelete->val << endl;
	//����β�ڵ�
	if(pdelete->next){
		ListNode* pnext = pdelete->next;
		pdelete->val = pnext->val;
		pdelete->next = pnext->next;
		delete(pnext);
		pnext = nullptr;
		return;
	}
	//ֻ��һ���ڵ�
	if (*phead == pdelete&&((pdelete->next)==nullptr)) {
		delete *phead;
		*phead = nullptr;
		pdelete =nullptr;
		return;
	}
	//ɾ��β�ڵ�
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
	cout << "ɾ��ǰ" << endl;
	Foreach_LinkList(phead);
	DeleteNode(&phead, pdelete);
	cout << "ɾ����" << endl;
	Foreach_LinkList(phead);
	system("pause");
	return EXIT_SUCCESS;
}