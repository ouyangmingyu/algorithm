#include<iostream>
#include<string>
#include<stack>
#include<time.h>
#include<vector>
#include<algorithm>

using namespace std;


int RandomInRange(int start, int end)
{
	srand((unsigned int)time(0));
	return start + rand() % (end - start+1);
}

//快速排序

int Partition(int data[], int length, int start,int end)
{
	if (data == nullptr || length <= 0 || start < 0 || end >= length) {
		
		new exception("Invalid input");
	}

	int index = RandomInRange(start, end);
	swap(data[index], data[end]);
	int storeindex = start - 1;

	for (index = start; index < end; ++index) {
		if (data[index] < data[end]) {
			storeindex++;
			if (storeindex != index) {
				swap(data[index], data[storeindex]);
			}
		}
	}
	++storeindex;
	swap(data[storeindex], data[end]);

	return storeindex;
}


void QuickSort(int data[], int leng, int start,int end)
{
	//标准解法
	if (start == end) {
		return;
	}

	int index = Partition(data, leng, start, end);
	if (index > start) {
		QuickSort(data, leng, start, index - 1);
	}
	if (index < end) {
		QuickSort(data, leng, index + 1, end);
	}
}

void quicksort(int s[], int l, int r)
{
	if (l < r) {
		int i = l, j = r;
		int x = s[l];
		while (i < j) {
			while (i < j&&s[j]>x) {
				j--;
			}
			if (i < j) {
				s[i++] = s[j];
			}

			while (i < j&&s[i]<x) {
				i++;
			}
			if (i < j) {
				s[j--] = s[i];
			}
		}
		s[i] = x;
		quicksort(s, l, i - 1);
		quicksort(s, i + 1, r);
	}
}

//归并排序


void Merge(vector<int>& v, int start, int mid, int end)
{
	int i = start, j = mid + 1;
	vector<int> res;
	while (true) {
		if (i < mid + 1 && j < end + 1) {
			if (v[i] < v[j]) {
				res.push_back(v[i]);
				i++;
				continue;
			}
			else {
				res.push_back(v[j]);
				j++;
				continue;
			}
		}

		if (i == mid + 1 && j < end + 1) {
			for (int k = j; k < end + 1; k++) {
				res.push_back(v[k]);
			}
			break;
		}

		if (i < mid + 1 && j == end + 1) {
			for (int k = i; k < mid + 1; k++) {
				res.push_back(v[k]);
			}
			break;
		}
	}
	j = 0;
	for (int i = start; i < end + 1; i++) {
		v[i] = res[j];
		j++;
	}
}

void GuiBingSort(vector<int>& v, int start, int end)
{
	if (start < end) {
		int mid = (start + end) / 2;
		GuiBingSort(v, 0, mid);
		GuiBingSort(v, mid+1, end);
		Merge(v, start, mid, end);
	}
}

//插入排序
void ChaRuSort(vector<int>& v)
{
	int len = v.size();
	int tmp = 0;
	for (int i = 1; i < len; i++) {
		int tmp = v[i];
		for (int j = i - 1; j >= 0; j--) {
			if (v[j] > tmp) {
				v[j + 1] = v[j];
				if (j == 0) {
					v[0] = tmp;
					break;
				}
			}
			else {
				v[j + 1] = tmp;
				break;
			}
		}
	}
}

//计数排序



int mainpx()
{
	vector<int> v= { 0,2,4,1,3 };
	
	ChaRuSort(v);

	for_each(v.begin(), v.end(), [](int num) {cout << num << " "; });
	cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}