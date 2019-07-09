#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

void quicksort(vector<int>& v,int l,int r)
{
	if (l < r) {
		int i = l, j = r;
		int x = v[l];
		while (i < j) {
			while (i<j&&v[j]>x) {
				j--;
			}
			if (i < j) {
				v[i++] = v[j];
			}

			while (i<j&&v[i]<x) {
				i++;
			}
			if (i < j) {
				v[j--] = v[i];
			}
		}
		v[i] = x;
		quicksort(v, l, i - 1);
		quicksort(v, i+1, r);
	}
}

void res39(vector<int> v)
{
	map<int, int> m;
	for (int i = 0; i < v.size(); i++) {
		m[v[i]]++;
		if (m[v[i]] > (v.size() / 2)) {
			cout << v[i] << " ";
			return;
		}
	}
}

int main43()
{
	vector<int> v = { 2,4,1,3,2,2,2 };
	
	res39(v);
	cout << endl;

	system("pause");
	return EXIT_SUCCESS;
}