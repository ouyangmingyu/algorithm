#include<iostream>
#include<string>
#include<stack>

using namespace std;

long long Fibonacci(int n)
{
	//�ݹ�汾
	/*if (n <= 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}

	return Fibonacci(n - 1) + Fibonacci(n - 2);*/

	//�������ϣ��������ظ�����
	if (n <= 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	long long firstnum = 1;
	long long secondnum = 0;
	long long Finum = 0;

	for (int i = 2; i <= n; ++i) {
		Finum = firstnum + secondnum;
		secondnum = firstnum;
		firstnum = Finum;
	}

	return Finum;
}


int main13()
{
	cout << Fibonacci(3) << endl;
	system("pause");
	return EXIT_SUCCESS;
}