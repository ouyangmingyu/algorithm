#include<iostream>
#include<string>
#include<stack>

using namespace std;


int OneCount(int num)
{
	//�ⷨһ
	//int cnt = 0;
	//unsigned int flag = 1;
	//while (flag) {
	//	if (num&flag) {
	//		cnt++;
	//	}
	//	flag = flag << 1;
	//}
	//return cnt;

	//�ⷨ2 ����Ч
	int count = 0;
	while (num) {
		num = (num - 1)&num;
		count++;
	}
	return num;

}


int main19()
{
	cout<<
	system("pause");
	return EXIT_SUCCESS;
}