#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;


class A {
public:
	A() {
		N++;
		sum += N;
	}
	static int N;
	static int sum;
};

int A::N = 0;
int A::sum = 0;

typedef int(*func)(int);



int solu1(int n) {
	return 0;
}

int solun(int n) {
	static func f[2] = { solu1,solun };
	return f[!!n](n - 1) + n;
}


int main64()
{
	cout << solun(10) << endl;

	system("pause");
	return EXIT_SUCCESS;
}