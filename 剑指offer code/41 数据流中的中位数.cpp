#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<functional>


using namespace std;



void res41(vector<int>& v)
{
	vector<int> max;
	vector<int> min;
	int len = v.size();

	for (int i = 0; i < len; i++) {
		int num = v[i];
		if (((max.size() + min.size()) & 1) == 1) {
			if (min.size() > 0 && num > min[0]) {
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<int>());
				num = min[0];
				pop_heap(min.begin(), min.end(), greater<int>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<int>());
		}
		else {
			if (max.size() > 0 && num < max[0]) {
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<int>());
				num = max[0];
				pop_heap(max.begin(), max.end(), less<int>());
				max.pop_back();
			}
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<int>());
		}
	}
	if (((min.size() + max.size()) & 1) == 1) {
		cout << min[0] << endl;
	}
	else {
		cout << (((min[0] + max[0])) / 2 )<< endl;
	}
}


int main45()
{
	vector<int> v = { 3,2,1,5,6,7 };

	res41(v);

	system("pause");
	return EXIT_SUCCESS;
}