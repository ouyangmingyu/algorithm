#include<iostream>
#include<string>
#include<stack>

using namespace std;


int MinNum(int data[], int length)
{
	if (data == nullptr || length <= 0) {
		throw new exception("Invalid Input");
	}

	int start = 0;
	int end = length - 1;
	int midIndex = 0;
	int minNum = data[0];//当移动0个元素时，直接返回
	while (data[start] >= data[end]) {
		if (end - start == 1) {
			if (data[end] <= minNum) {
				minNum = data[end];
				break;
			}
		}
		midIndex = (start + end) / 2;
		if (data[midIndex] == data[start] && data[midIndex] == data[end]) {
			for (int i = start; i <= end; i++) {
				if (data[i] < minNum) {
					minNum = data[i];
				}
			}
			break;
		}
		if (data[midIndex] >= data[start]) {
			start = midIndex;
		}
		if (data[midIndex] <= data[end]) {
			end = midIndex;
		}
	}
	return minNum;
}


int main15()
{
	int data[5] = { 1,0,1,1,1 };
	cout << MinNum(data, 5) << endl;
	system("pause");
	return EXIT_SUCCESS;
}