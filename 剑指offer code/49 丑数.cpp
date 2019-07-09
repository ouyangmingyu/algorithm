#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<set>

using namespace std;


int res49(int num)
{
	vector<int> res = { 1 };
	
	int index2=0, index3=0, index5=0;
	int max = 1;
	int max2, max3, max5;
	while (true) {
		while (2 * res[index2] <= max) {
			index2++;
		}
		max2 = 2 * res[index2];
		while (3 * res[index3] <= max) {
			index3++;
		}
		max3 = 3 * res[index3];
		while (5 * res[index5] <= max) {
			index5++;
		}
		max5 = 5 * res[index5];
		max = max2 < max3 ? max2 : max3;
		max = max < max5 ? max : max5;
		res.push_back(max);
		if (res.size() == num) {
			return max;
		}
	}

}

int main53()
{
	cout << "第" << 1500 << "个丑数是：" << res49(1500) << endl;
	system("pause");
	return EXIT_SUCCESS;
}