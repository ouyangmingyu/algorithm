#include<iostream>
#include<string>
#include<stack>
#include <cstdlib>

using namespace std;


bool inc(char* num)
{
	if (num == nullptr) {
		
		new exception("a err occure");
	}
	int len = strlen(num);
	bool jinwei = false;
	for (int i = len - 1; i >= 0;i--) {
		if (i == len - 1) {
			num[i] += 1;
			if (num[i] == ('9'+1)) {
				num[i] = '0';
				jinwei = true;
				if (len == 1) {
					return true;
				}
			}
			continue;
		}
		if (jinwei == true) {
			num[i] += 1;
			if (i == 0 && num[i] == '9'+1) {
				return true;
			}
			
			if (num[i] == '9'+1) {
				num[i] = '0';
				jinwei = true;
				continue;
			}
			if (num[i] < '9' + 1) {
				jinwei = false;
			}
		}
	}
	return false;
}


void printnum(char* num)
{
	if (num == nullptr) {
		return;
	}
	while (*(num) == '0') {
		num++;
	}
	cout << num << '\t';
}


//常规方法
void print1ton(int n)
{
	if (n <= 0) {
		return;
	}

	char* num = new char[n + 1];
	memset(num, '0', n);
	num[n] = '\0';
	while (!inc(num)) {
		printnum(num);
	}
	delete[] num;
}

//递归方法
void printre(char* num,int len,int index)
{
	if(index==len-1){
		printnum(num);
		return;
	}
	for (int i = 0; i < 10; i++) {
		num[index + 1] = '0' + i;
		printre(num, len, index + 1);
	}
}

void printone2nre(int n)
{
	if (n <= 0) {
		return;
	}
	char* num = new char[n + 1];
	memset(num, '0', n);
	num[n] = '\0';
	for (int i = 0; i < 10; i++) {
		num[0] = '0' + i;
		printre(num, n, 0);
	}
	delete[] num;
}


int main21()
{
	printone2nre(3);
	system("pause");
	return EXIT_SUCCESS;
}