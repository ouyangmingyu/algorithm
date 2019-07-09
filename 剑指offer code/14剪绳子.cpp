#include<iostream>
#include<string>
#include<stack>
#include<math.h>

using namespace std;


int MaxProductAfter(int length)
{
	//动态规划法
	/*if (length < 2) {
		return 0;
	}
	if (length == 2) {
		return 1;
	}
	if (length == 3) {
		return 2;
	}
	int* products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;
	for (int i = 4; i <= length; i++)
	{
		max = 0;
		for (int j = 1; j <= i / 2; j++) {
			if (max < (products[j] * products[i - j])) {
				max = products[j] * products[i - j];
			}
		}
		products[i] = max;
	}
	max = products[length];
	delete[] products;
	return max;*/

	//贪婪算法
	if (length < 2) {
		return 0;
	}
	if (length == 2) {
		return 1;
	}
	if (length == 3) {
		return 2;
	}

	int timeof3 = length / 3;
	if (length - 3 * timeof3 == 1) {
		timeof3--;
	}

	int timeof2 = (length - 3 * timeof3) / 2;

	return (int)pow(3, timeof3)*(int)pow(2, timeof2);
}

int main18()
{
	cout << MaxProductAfter(8) << endl;
	system("pause");
	return EXIT_SUCCESS;
}