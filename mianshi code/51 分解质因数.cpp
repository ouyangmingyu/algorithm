#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void prim(int m) {
	for (int i = 2; i <= m; i++) {
		while (m != i) {
			if (m%i==0) {
				cout << i << " ";
				m /= i;
			}
			else {
				break;
			}
		}
	}
	cout << m;
}

void prim2(int num) {
	int i;
	for (i = 2; i <= num; i++)//���Ĵ���
	{
		while (num != i)//��ȷ��num������2
			if (num%i == 0)//��num/iû������ʱ��˵��i��num��һ������
			{
				cout << i << ",";//���i
				num = num / i;//ȡnum/i��������
			}
			else break;//Ȼ������������������ʱnum���ˣ�iҲ���2�ˣ���Ϊ���¿�ʼ
	}
	cout << num;
}

int main51()
{
	prim(49);
	system("pause");
	return 0;
}