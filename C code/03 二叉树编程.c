#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct BiNode
{
	char ch;
	struct BiNode *lchild;
	struct BiNode *rchild;
};

//int num = 0;

void cuculateLeafNum(struct BiNode *root,int *p)
{
	if (NULL == root)
	{
		return;
	}

	if (root->lchild == NULL && root->rchild == NULL)
	{
		(*p)++;
	}


	cuculateLeafNum(root->lchild, p);
	cuculateLeafNum(root->rchild, p);
}


int getTreeHeight(struct BiNode *root)
{
	if (NULL == root)
	{
		return 0;
	}


	//�������������߶�
	int lheight = getTreeHeight(root->lchild);
	//�������������߶�
	int rheight = getTreeHeight(root->rchild);

	int height = lheight > rheight ? lheight + 1 : rheight + 1;

	return height;
}


void showBiTree(struct BiNode *root)
{
	if (NULL == root)
	{
		return;
	}

	printf("%c ",root->ch);
	showBiTree(root->lchild);
	showBiTree(root->rchild);
}


struct BiNode *copyBiTree(struct BiNode *root)
{
	if (NULL == root)
	{
		return NULL;
	}

	//�ȿ���������
	struct BiNode *lchild = copyBiTree(root->lchild);
	//����������
	struct BiNode *rchild = copyBiTree(root->rchild);


	struct BiNode *newnode = malloc(sizeof(struct BiNode));
	newnode->lchild = lchild;
	newnode->rchild = rchild;
	newnode->ch = root->ch;

	return newnode;
}

void freeSpace(struct BiNode *root)
{
	if (NULL == root)
	{
		return;
	}

	//�ͷ��������ڴ�
	freeSpace(root->lchild);
	//�ͷ�������
	freeSpace(root->rchild);

	printf("%c ���ͷ�!\n", root->ch);
	free(root);
}


void test()
{
	struct BiNode nodeA = { 'A', NULL, NULL };
	struct BiNode nodeB = { 'B', NULL, NULL };
	struct BiNode nodeC = { 'C', NULL, NULL };
	struct BiNode nodeD = { 'D', NULL, NULL };
	struct BiNode nodeE = { 'E', NULL, NULL };
	struct BiNode nodeF = { 'F', NULL, NULL };
	struct BiNode nodeG = { 'G', NULL, NULL };
	struct BiNode nodeH = { 'H', NULL, NULL };


	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeF;

	nodeB.rchild = &nodeC;

	nodeC.lchild = &nodeD;
	nodeC.rchild = &nodeE;

	nodeF.rchild = &nodeG;

	nodeG.lchild = &nodeH;


	//1. ���������Ҷ�ӽڵ���Ŀ
	int num = 0;
	cuculateLeafNum(&nodeA, &num);
	printf("Ҷ�ӽڵ���Ŀ:%d\n", num);

	//2. ��������ĸ߶�
	int height = getTreeHeight(&nodeA);
	printf("���ĸ߶�:%d\n",height);

	//3. ����������
	struct BiNode *root = copyBiTree(&nodeA);
	showBiTree(root);
	printf("\n");
	showBiTree(&nodeA);

	freeSpace(root);
}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}