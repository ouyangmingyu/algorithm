#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

int res47(vector<vector<int>> v, int m, int n,int i,int j)
{
	//递归的方法
	
	if (i == 0 && j == 0) {
		return v[i][j];
	}
	if (i == 0 && j > 0) {
		return v[i][j] + res47(v,m,n,i, j - 1);
	}
	if (j == 0 && i > 0) {
		return v[i][j] + res47(v, m, n, i - 1, j);
	}
	return v[i][j] + (res47(v, m, n, i, j - 1) > res47(v, m, n, i - 1, j) ? res47(v, m, n, i, j - 1) : res47(v, m, n, i - 1, j));
	
	//循环的办法

}


int main51()
{
	vector<vector<int>> v = { 
								{1,10,3,8},
								{12,2,9,6},
								{5,7,4,11},
								{3,7,16,5}
	};
	cout << "最大价值为" << res47(v,4,4,3,3) << endl;
	system("pause");
	return EXIT_SUCCESS;
}