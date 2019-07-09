#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

void res66(vector<int> a, vector<int> b)
{
	int len = a.size();
	vector<int> D1(len,0);
	vector<int> D2(len,0);
	
	
	D1[0] = 1;
	D2[len - 1] = 1;

	for (int i = 1; i < len; i++) {
		D1[i] = D1[i - 1] * a[i - 1];
	}

	for (int i = len-2; i>=0; i--) {
		D2[i] = D2[i+1]*a[i+1];
	}

	for (int i = 0; i < len; i++) {
		b[i] = D1[i] * D2[i];
	}
}


int main66()
{
	
	system("pause");
	return EXIT_SUCCESS;
}