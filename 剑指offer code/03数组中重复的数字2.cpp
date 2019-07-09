#include<iostream>
#include<string>

using namespace std;


int countRange(const int* numbers, int length, int start, int end)
{
	if (numbers == nullptr) {
		return 0;
	}
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (numbers[i] >= start && numbers[i] <= end) {
			count++;
		}
	}
	return count;
}

int duplicate(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0) {
		return -1;
	}

	int start = 1;
	int end = length ;
	int middle = start + (end - start) / 2;

	while (end >= start) {
		middle= start + (end - start) / 2;
		int count = countRange(numbers, length,start,middle);
		if (end == start) {
			if (count > 1) {
				return start;
			}
			else {
				break;
			}
		}
		if (count > (middle - start + 1)) {
			end = middle;
		}
		else {
			start = middle + 1;
		}
	}
	return -1;
}


int main05()
{
	int a[8] = { 2,3,5,4,3,2,6,7 };
	int duplication = -1;
	duplication = duplicate(a, 8);
	if (duplication >0)
	{
		cout << "数组中含有重复数字" << duplication << endl;
	}
	else if(duplication==0){
		cout << "数组中不含有重复数字" << endl;
	}
	else{
		cout << "出现错误" << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}