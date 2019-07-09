#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>
#include<deque>

using namespace std;


void res59t1(vector<int>& v, int size)
{
	deque<int> d;

	int len = v.size();
	
	for (int i = 0; i < size; i++) {
		while (!d.empty() && v[i] >= v[d.back()]) {
			d.pop_back();
		}
		d.push_back(i);
	}
	cout << v[d.front()]<<" ";

	for (int i = size; i < len; i++) {
		while (!d.empty() && v[i] >= v[d.back()]) {
			d.pop_back();
		}
		if (!d.empty() && (i - d.front()>= size)) {
			d.pop_front();
		}
		d.push_back(i);
		cout << v[d.front()] << " ";
	}

	cout << endl;
}



int main59()
{
	vector<int> v = { 2,3,4,2,6,2,5,1 };
	res59t1(v, 3);
	system("pause");
	return EXIT_SUCCESS;
}