#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;


bool iseven(int num)
{
	if ((num & 0x01) !=0) {
		return true;
	}
	else
	{
		return false;
	}
}

void tiaozheng_model(vector<int>& v,bool (* fun)(int)) {
	int len = v.size();
	if (len == 0 || len == 1) {
		return;
	}

	int* pl = &v[0];
	int* pr = &v[len - 1];

	while (pl < pr) {
		while (pl < pr && fun(*pl)) {
			pl++;
		}


		while (pl < pr && !fun(*pr)) {
			pr--;
		}

		if (pl < pr) {
			int tmp = *pl;
			*pl = *pr;
			*pr = tmp;
		}
	}
}


void tiaozheng(vector<int>& v)
{
	tiaozheng_model(v, iseven);
}



int main25()
{
	vector<int>  v;
	
	while (true) {	
		int ele;
		cin >> ele;
		v.push_back(ele);
		if (cin.get() == '\n') {
			break;
		}
	}

	for_each(v.begin(), v.end(), [](int num) {cout << num << " "; });
	cout << endl;

	tiaozheng(v);
	for_each(v.begin(), v.end(), [](int num) {cout << num << " "; });
	cout << endl;

	system("pause");
	return EXIT_SUCCESS;
}