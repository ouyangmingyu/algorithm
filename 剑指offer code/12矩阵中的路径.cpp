#include<iostream>
#include<string>
#include<stack>

using namespace std;


bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited)
{
	if (str[pathLength == '\0']) {
		return true;
	}
	
	bool hasPath = false;
	if (row > 0 && row < rows&&col>0 && col < cols&&matrix[row*cols + col] == str[pathLength] && !visited[row*cols + col]) {
		++pathLength;
		visited[row*cols + col] = true;

		hasPath = hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited);

		if (!hasPath) {
			--pathLength;
			visited[row*cols + col] = false;
		}
	}
	return false;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if (matrix == nullptr || cols <= 0 || rows <= 0 || str == nullptr) {
		throw new exception("Input err");
	}

	bool* visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);
	int pathLength = 0;

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
			{
				delete[] visited;
				return true;
			}
		}
	}
	delete[] visited;
	return false;
}



int main16()
{
	char matrix[12] = { 'a','b','t','g','c','f','c','s','j','d','e','h'};
	char str[10] = { 0 };
	cin >> str;
	if (hasPath(matrix, 3, 4, str)) {
		cout << "�������·��" << str << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}