#include<iostream>
#include<string>

using namespace std;

bool findnum(int* matrix,int rows,int cols,int number)
{
	int row = 0, col = cols-1;
	if (matrix == nullptr || rows < 0 || cols < 0) {
		return false;
	}
	while (row < rows && col >= 0) {
		if (matrix[row*cols+col] == number) {
			return true;
		}
		else if (matrix[row*cols + col] > number) {
			col--;
		}
		else {
			row++;
		}
	}
	return false;
}


int main06()
{
	int matrix[] = {
		1,2,8,9,
		2,4,9,12,
		4,7,10,13,
		6,8,11,15
	};
	bool flag = findnum(matrix, 4, 4, 20);
	if (flag == true) {
		cout << "存在数组中" << endl;
	}
	else {
		cout << "不存在数组中" << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}