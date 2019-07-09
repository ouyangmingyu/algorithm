#include<iostream>
#include<string>

using namespace std;


bool duplicate(int numbers[], int length, int* duplication)
{
	if (numbers == nullptr || length <= 0)
	{
		return false;
	}
	for (int i = 0; i < length; i++) {
		if (numbers[i]<0 || numbers[i]>length - 1) {
			return false;
		}
	}
	for (int i = 0; i < length; i++) {
		while (numbers[i] != i) {
			if (numbers[i] == numbers[numbers[i]]) {
				*duplication = numbers[i];
				return true;
			}
			int temnum = numbers[i];
			numbers[i] = numbers[temnum];
			numbers[temnum] = temnum;
		}
	}
	return false;
}


int main04()
{
	int a[7] = { 2,3,1,0,2,5,3 };
	int duplication = 0;
	bool flag = duplicate(a, 7, &duplication);
	if (flag == true)
	{
		cout << "数组中含有重复数字" << duplication << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}