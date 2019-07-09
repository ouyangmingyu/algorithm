#include<iostream>
#include<string>

using namespace std;

void ReplaceBlank(char* str, int leng)
{
	if (str == nullptr || leng <= 0) {
		return;
	}
	int originalLength = 0;
	int newLength = 0;
	int numberofBlank = 0;
	int i = 0;
	//统计空格数目
	while (str[i] != '\0') {
		originalLength++;
		if (str[i] == ' ') {
			numberofBlank++;
		}
		++i;
	}
	newLength = originalLength + 2 * numberofBlank;
	if (newLength > leng) {
		return;
	}
	int indexofOriginal = originalLength;
	int indexofNew = newLength;
	while (indexofOriginal >= 0 && indexofNew > indexofOriginal) {
		if (str[indexofOriginal] == ' ') {
			str[indexofNew--] = '0';
			str[indexofNew--] = '2';
			str[indexofNew--] = '%';
		}
		else {
			str[indexofNew--] = str[indexofOriginal];
		}
		indexofOriginal--;
	}
}

int main07()
{
	char str[40] = "I love WenJun";
	ReplaceBlank(str, 40);
	cout << str << endl;
	system("pause");
	return EXIT_SUCCESS;
}