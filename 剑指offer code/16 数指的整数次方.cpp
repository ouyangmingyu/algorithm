#include<iostream>
#include<string>
#include<stack>

using namespace std;


double PBE(double base, unsigned int ex)
{
	if (ex == 0) {
		return 0.0;
	}
	if (ex == 1) {
		return base;
	}
	double result = PBE(base,ex>>1);
	result *= result;
	if ((ex & 0x01) == 1) {
		result *= base;
	}
	return result;
}


int main20()
{
	cout << PBE(3, 0) << endl;
	system("pause");
	return EXIT_SUCCESS;
}