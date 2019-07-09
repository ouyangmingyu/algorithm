#include<iostream>
#include<string>
#include<stack>

using namespace std;


int GetDigitSum(int number)
{
	if (number < 0) {
		throw new exception("Invalid number");
	}
	int sum = 0;
	while (number > 0) {
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

bool check(int threshold, int rows, int cols,int row, int col,bool* visited)
{
	if (row >= 0 && row < rows&&col >= 0 && col < cols && (GetDigitSum(col) + GetDigitSum(row) <= threshold) && !visited[row*cols + col]) {
		return true;
	}
	return false;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	int count = 0;
	if (check(threshold, rows, cols, row, col, visited)) {
		visited[row*cols + col] = true;
		count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row + 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col - 1, visited)
			+ movingCountCore(threshold, rows, cols, row, col + 1, visited);
	}
	return count;
}

int movingCount(int threshold, int rows, int cols)
{
	if (threshold < 0 || rows <= 0 || cols <= 0) {
		throw new exception("Invlid Input");
	}
	bool* visited = new bool[rows*cols];
	for (int i = 0; i < rows*cols; i++) {
		visited[i] = false;
	}

	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
	delete[] visited;

	return count;
}

int main17()
{
	cout << movingCount(17, 10, 10) << endl;
	system("pause");
	return EXIT_SUCCESS;
}