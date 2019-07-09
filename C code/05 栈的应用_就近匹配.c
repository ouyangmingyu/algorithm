#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"SeqStack.h"

int IsLeft(char ch)
{
	return ch == '(';
}

int IsRight(char ch)
{
	return ch == ')';
}

void printError(const char *str,char *errMsg,char *pos)
{

	printf("������Ϣ:%s\n", errMsg);
	printf("%s\n",str);
	int dis = pos - str;
	for (int i = 0; i < dis; ++i)
	{
		printf(" ");
	}
	printf("A\n");


}

void test()
{

	const char *str = "5+5*(6()+9/3*1)-(1)+3(";
	char *p = (char *)str;
	
	//��ʼ��ջ
	SeqStack stack = Init_SeqStack();


	while (*p != '\0')
	{

		//�жϵ�ǰ�ַ��Ƿ���������
		if (IsLeft(*p))
		{
			Push_SeqStack(stack, p);
		}


		//�жϵ�ǰ�ַ��Ƿ���������
		if (IsRight(*p))
		{
			if (Size_SeqStack(stack) > 0)
			{
				//����ջ��Ԫ��
				Pop_SeqStack(stack);
			}
			else
			{
				printError(str,"������û��ƥ���������!",p);

			}

		}

		p++;
	}

	while (Size_SeqStack(stack) > 0)
	{
		printError(str,"û��ƥ���������!",Top_SeqStack(stack));
		//����ջ��Ԫ��
		Pop_SeqStack(stack);
	}


	//����ջ
	Destroy_SeqStack(stack);
	stack = NULL;



}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}