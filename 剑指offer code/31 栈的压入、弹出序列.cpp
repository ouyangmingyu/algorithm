#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

bool res31(vector<int> v1,vector<int> v2)
{
	int i = 0, j = 0;
	int len1 = v1.size();
	int len2 = v2.size();
	stack<int> s;

	while (true) {
		if (s.size() == 0) {
 			if (j == len2) {
				return true;
			}
			if (i == len1&&s.top() != v2[j]) {
				return false;
			}
			s.push(v1[i]);
			i++;
			continue;
		}
		if (s.size() != 0) {
			if (j == len2) {
				return true;
			}
			if (i == len1&&s.top()!=v2[j]) {
				return false;
			}
			if (s.top() == v2[j]) {
				s.pop();
				j++;
				continue;
			}
			if (s.top() != v2[j]) {
				s.push(v1[i]);
				i++;
				continue;
			}
		}
	}	
}


int main35()
{
	vector<int> v1 = {1,2,3,4,5};
	vector<int> v2 = {4,5,2,3,1};

	if (res31(v1, v2)) {
		cout << "正确的搭配" << endl;
	}
	else {
		cout << "不正确的搭配" << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}