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
	for (i = 2; i <= num; i++)//核心代码
	{
		while (num != i)//先确定num不等于2
			if (num%i == 0)//当num/i没有余数时，说明i是num的一个质数
			{
				cout << i << ",";//输出i
				num = num / i;//取num/i整数部分
			}
			else break;//然后跳出，重新来，此时num变了，i也变成2了，因为重新开始
	}
	cout << num;
}

int main51()
{
	prim(49);
	system("pause");
	return 0;
}