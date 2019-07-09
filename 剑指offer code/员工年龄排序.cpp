#include<iostream>
#include<string>
#include<stack>

using namespace std;


void SortAge(int ages[], int length)
{
	if (ages == nullptr || length <= 0) {
		return;
	}

	const int oldestage = 99;
	int timesOfAge[oldestage + 1] = { 0 };

	for (int i = 0; i < length; i++) {
		if (ages[i]<0 || ages[i]>oldestage) {
			
			new exception("age out of range");
		}
		timesOfAge[ages[i]]++;
	}

	int index = 0;
	for (int i = 0; i < oldestage; i++) {
		for (int j = 0; j < timesOfAge[i]; j++) {
			ages[index] = i;
			++index;
		}
	}
}