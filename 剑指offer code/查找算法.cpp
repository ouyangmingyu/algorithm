#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

bool Bisearch(vector<int> v,int num,int start,int end)
{
	//�ǵݹ�
	/*int mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		if (v[mid] == num) {
			return true;
		}
		if (v[mid] > num) {
			end = mid-1;
		}
		if (v[mid] < num) {
			start = mid + 1;
		}
	}
	return false;*/
	//�ݹ�
	if (start > end) {
		return false;
	}
	int mid = (start + end);
	int data = v[mid];
	if (data == num) {
		return true;
	}
	if (data < num) {
		start = mid + 1;
	}
	if (data > num) {
		end = mid - 1;
	}

	return Bisearch(v, num, start, end);
}




int maincz()
{
	vector<int> v = { 1,3,6,9,10,13,15 };

	if (Bisearch(v, 15, 0, 6)) {
		cout << "�ҵ���" << endl;
	}
	else {
		cout << "û�ҵ�" << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}