#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//����ڵ����ݽṹ
struct LinkNode
{
	struct LinkNode *next;
};


//����ṹ��
struct LList
{
	struct LinkNode header; //ͷ���
	int size;
};

typedef void * LinkList;


//��ʼ������
LinkList Init_LinkList()
{

	struct LList *list = malloc(sizeof(struct LList));
	if (NULL == list)
	{
		return NULL;
	}

	list->header.next = NULL;
	list->size = 0;

	return list;
}


void Insert_LinkList(LinkList list, int position, void *data)
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	struct LList * mylist = (struct LList *)list;
	struct LinkNode *mynode = (struct LinkNode *)data;


	if (position < 0 || position > mylist->size)
	{
		position = mylist->size;
	}


	//��λ��(�ҵ�positionλ�õ�ǰһ��λ��)
	struct LinkNode *pCurrent = &(mylist->header); 
	for (int i = 0; i < position; ++i)
	{
		pCurrent = pCurrent->next;
	}


	//����������
	mynode->next = pCurrent->next;
	pCurrent->next = mynode;


	mylist->size++;
}


void Foreach_LinkList(LinkList list, void(*myforeach)(void *) )
{

	if (NULL == list)
	{
		return;
	}

	if (NULL == myforeach)
	{
		return;
	}

	struct LList * mylist = (struct LList *)list;

	struct LinkNode *pCurrent = mylist->header.next;

	while (pCurrent != NULL)
	{
		
		myforeach(pCurrent);
		pCurrent = pCurrent->next;
	}

}


struct Person
{
	struct LinkNode node; //�ṹ��Ӧ��ָ�룿
	char name[64];
	int age;
};

void myPrint(void *data)
{
	struct Person *person = (struct Person *)data;
	printf("Name:%s Age:%d\n", person->name,person->age);
}

void test()
{

	//��ʼ������
	LinkList list = Init_LinkList();


	//��������
	struct Person p1 = { NULL, "aaa", 10 };
	struct Person p2 = { NULL, "bbb", 20 };
	struct Person p3 = { NULL, "ccc", 30 };
	struct Person p4 = { NULL, "ddd", 40 };
	struct Person p5 = { NULL, "eee", 50 };
	struct Person p6 = { NULL, "fff", 60 };


	//��������
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);
	Insert_LinkList(list, 0, &p6);


	//����
	Foreach_LinkList(list, myPrint);


}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}