#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

void res63(vector<int> v)
{
	int max = 0;
	sort(v.begin(), v.end());
	int fst = *v.begin();
	int lst = *(--v.end());
	max = lst - fst;
	cout << max << endl;
}


int main63()
{
	vector<int> v = { 9,11,8,5,7,12,16,14 };

	res63(v);
	system("pause");
	return EXIT_SUCCESS;
}