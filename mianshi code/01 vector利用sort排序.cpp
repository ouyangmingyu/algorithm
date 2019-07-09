#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

struct ss {
	int p1;//第一优先级
	int p2;//第二优先级
};


bool a(ss& s1,ss& s2)
{
	if (s1.p1 < s2.p1) {
		return true;
	}
	if (s1.p1 == s2.p2) {
		if (s1.p2 < s2.p2) {
			return true;
		}
	}
	return false;
}

void sortvec(vector<ss> &vec) {
	sort(vec.begin(), vec.end(), a);
}

int main01()
{
	vector<ss> vec = { {2,3},{2,2} };

	sortvec(vec);

	cout << vec[0].p1 << endl;

	system("pause");
	return 0;
}

