#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

void res29(vector<vector<int>> v,int row,int col)
{
	
	int cnt = row % 2 ? (row / 2+1) : row / 2 ;

	for (int i = 0; i < cnt; i++) {
		for (int j = i; j < col - i; j++) {
			cout << v[i][j] << " ";
		}
		for (int j = i+1; j < row - i; j++) {
			cout << v[j][col-i-1] << " ";
		}
		for (int j = col - i - 2; j > i-1;j--) {
			cout << v[row-i-1][j] << " ";
		}
		for (int j = row - i - 2; j > i;j--) {
			cout << v[j][i] << " ";
		}
	}
	
}


int main33()
{
	vector<vector<int>> v = { {1,2,3,4,5},
							{6,7,8,9,10},
							{11,12,13,14,15},
							{16,17,18,19,20},
							{17,18,19,20,21} };

	//res29(v,5,5);
	cout << endl;

	vector<int> v1 = { 1,2,3,4,5 };

	auto ele=find(v1.begin(), v1.end(), 1);
	
	if (ele == v1.end()) {
		cout << "ц╩спур╣╫" << endl;
	}

	cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}