#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

//利用STL的sort函数

using namespace std;

bool func(int num1, int num2) {
	int bit1=1, bit2 = 1;

	int num1tmp = num1;
	int num2tmp = num2;

	while (num1tmp /= 10) {
		bit1++;
	}
	while (num2tmp /= 10) {
		bit2++;
	}
	
	for (int i = bit1-1,j = bit2-1; i >= 0 && j >= 0; i--, j--) {
		int div1 = pow(10, i);
		int div2 = pow(10, j);
		if (div1 == 1 || div2 == 1) {
			if (((num1 / div1) % 10) == ((num2 / div2) % 10)) {
				if (div1 == 1) {
					return true;
				}
				else {
					return false;
				}
			}
			return ((num1 / div1)%10) < ((num2 / div2)%10);
		}
		if (((num1 / div1) % 10) == ((num2 / div2) % 10)) {
			continue;
		}
		return ((num1 / div1) % 10) < ((num2 / div2) % 10);
	}
	return num1<num2;
}

//大数问题
void  min_num(vector<int>& v,string& result)
{
	sort(v.begin(), v.end(), func);
}


int main07()
{
	int num;
	unsigned char c;
	vector<int> v;
	while (cin >> num) {
		v.push_back(num);
		if ((cin.get()) == '\n')
			break;
	}
	string res;
	min_num(v,res);
	
	for_each(v.begin(), v.end(), [](int num) {cout << num ; });
	cout << endl;

	system("pause");
	return EXIT_SUCCESS;
}