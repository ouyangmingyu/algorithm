#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

void res42(vector<int>& v)
{
	int len = v.size();
	int max = v[0];
	int now = v[0];
	for (int i = 1; i < len; i++) {
		now = (v[i] > (now + v[i])) ? v[i] : now + v[i];
		max = now > max ? now : max;
	}
	cout << max << endl;
}



int main46()
{
	vector<int> v = { 1,-2,3,10,-4,7,2,-5 };
	res42(v);
	system("pause");
	return EXIT_SUCCESS;
}