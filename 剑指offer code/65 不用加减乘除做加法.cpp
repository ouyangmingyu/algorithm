#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int Add(int num1, int num2) {
	int sum = 0, carry = 0;
	do {
		sum = num1^num2;
		carry = num1&num2 << 1;
		num1 = sum;
		num2 = carry;
	} while (num2!=0);

	return num1;
}

int ex2num(int num1, int num2)
{
	//加减法
	/*num1 = num1 + num2;
	num2 = num1 - num2;
	num1 = num1 - num2;*/
	//异或法
	/*num1 = num1^num2;
	num2 = num1^num2;
	num2 = num1^num2;*/
	return 0;
}


int main65()
{

	system("pause");
	return EXIT_SUCCESS;
}