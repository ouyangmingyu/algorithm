#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

void res40(vector<int> v)
{
	multiset<int> res;
	int len = v.size();
	for (int i = 0; i < len; i++) {
		if (i < 4) {
			res.insert(v[i]);
		}
		else {
			if (v[i] < *(--res.end())) {
				res.insert(v[i]);
				res.erase((--res.end()));
			}
		}
	}
	for_each(res.begin(), res.end(), [](int num) {cout << num << " "; });
	cout << endl;
}





int main44()
{
	vector<int> v = { 4,5,1,6,2,7,3,8 };
	
	system("pause");
	return EXIT_SUCCESS;
}