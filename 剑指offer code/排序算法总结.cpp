#include<iostream>
#include<string>
#include<stack>
#include<time.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;



class solution {
public:
	//√∞≈›≈≈–Ú
	void maopaopx(vector<int> v)
	{
		int len = v.size();
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len - i - 1; j++) {
				if (v[i] > v[j]) {
					swap(v[i], v[j]);
				}
			}
		}
	}

	//—°‘Ò≈≈–Ú
	void xuanzepx(vector<int>& v)
	{
		int len = v.size();
		for (int i = 0; i < len; i++) {
			int min = INT_MAX;
			int minindex = i;
			for (int j = i; j < len; j++) {
				if (min > v[i]) {
					min = v[i];
					minindex = j;
				}
			}
			if (minindex != i) {
				swap(v[i], v[minindex]);
			}
		}
	}

	//≤Â»Î≈≈–Ú
	void ChaRuSort(vector<int>& v)
	{
		int len = v.size();
		for (int i = 1; i < len; i++) {
			int tmp = v[i];
			for (int j = i - 1; j >= 0; j--) {
				if (v[j] > tmp) {
					v[j + 1] = v[j];
					if (j == 0) {
						v[j + 1] = v[j];
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

	//πÈ≤¢≈≈–Ú
	void Merge(vector<int>& v, int start, int mid, int end)
	{
		vector<int> tmp;
		int i = start;
		int j = mid + 1;
		while (i <= mid && j <= end) {
			if (v[i] <= v[j]) {
				tmp.push_back(v[i]);
				i++;
			}
			else {
				tmp.push_back(v[j]);
				j++;
			}
		}

		while (i <= mid) {
			tmp.push_back(v[i++]);
		}

		while (j <= end) {
			tmp.push_back(v[j++]);
		}
		int k = 0;
		for (int i = start; i <= end; i++) {
			v[i] = tmp[k];
			k++;
		}
	}
	void GuiBingSort(vector<int>& v, int start, int end)
	{
		if (start < end) {
			int mid = (start + end) / 2;
			GuiBingSort(v, start, mid);
			GuiBingSort(v, mid + 1, end);
			Merge(v, start, mid, end);
		}
	}

	//øÏÀŸ≈≈–Ú
	void Quicksort(vector<int>& v, int l, int r)
	{
		if (l < r) {
			int i = l;
			int j = r;
			int tmp = v[l];
			while (i < j) {
				while (i<j&&v[j]>tmp) {
					j--;
				}
				if (i < j) {
					v[i] = v[j];
					i++;
				}
				while (i<j&&v[i]<tmp) {
					i++;
				}
				if (i < j) {
					v[j] = v[i];
					j--;
				}
			}
			v[i] = tmp;
			Quicksort(v, l, i - 1);
			Quicksort(v, i + 1, r);
		}
	}

	//∂—≈≈–Ú£®¥Û∂•∂—£©
	void Adjd(vector<int>& v, int k, int len) {
		v[0] = v[k];
		for (int i = 2 * k; i <= len; i *= 2) {
			if (i < len&&v[i] < v[i + 1]) i++;
			if (v[i] <= v[0]) break;
			else {
				v[k] = v[i];
				k = i;
			}
		}
		v[k] = v[0];
	}
	void BuildMaxHeap(vector<int>& v, int len) {
		for (int i = len / 2; i > 0; i--) {
			Adjd(v, i, len);
		}
	}
	void duipx(vector<int>& v, int len)
	{
		BuildMaxHeap(v, len);
		for (int i = len; i > 0; i--) {
			swap(v[1], v[i]);
			Adjd(v, 1, i - 1);
		}
	}

	//œ£∂˚≈≈–Ú
	void xierpax(vector<int>& v)
	{
		int len = v.size();
		int gap = len;
		do {
			gap = (gap / 3) + 1;
			//∂‘gap◊È“¿¥ŒΩ¯––≤Â»Î≈≈–Ú
			for (int i = 0; i < gap; i++) {
				for (int j = i + gap; j < len; j += gap) {
					int tmp = v[j];
					for (int k = j - gap; k >= i; k -= gap) {
						if (v[k] > tmp) {
							v[k + gap] = v[k];
							if (k == i) {
								v[k] = tmp;
								break;
							}
						}
						else {
							v[k + gap] = tmp;
							break;
						}
					}
				}
			}
		} while (gap > 1);
	}

	//º∆ ˝≈≈–Ú
	void findmaxandmin(vector<int> v, int& max, int& min)
	{
		max = INT_MIN;
		min = INT_MAX;
		int len = v.size();
		for (int i = 0; i < len; i++) {
			max = max > v[i] ? max : v[i];
			min = min < v[i] ? min : v[i];
		}
	}
	void jishupx(vector<int>& v) {
		int max, min;

		findmaxandmin(v, max, min);
		int len = v.size();
		vector<int> res(len, 0);
		int sz = max - min + 1;
		vector<int> tmp(sz, 0);
		for (int i = 0; i < len; i++) {
			tmp[v[i] - min]++;
		}
		for (int i = 1; i < sz; i++) {
			tmp[i] += tmp[i - 1];
		}
		for (int i = len - 1; i >= 0; i--) {
			res[tmp[v[i] - min] - 1] = v[i];
			tmp[v[i] - min]--;
		}
		v.swap(res);
	}

	//ª˘ ˝≈≈–Ú(Õ∞≈≈–Ú)
	void tongpx(vector<int>& v)
	{
		vector<queue<int>> t(10, queue<int>());
		int len = v.size();
		int max = INT_MIN;
		for (int i = 0; i < len; i++) {
			max = v[i] > max ? v[i] : max;
		}
		int cnt = 1;
		while (max / 10) {
			cnt++;
			max /= 10;
		}
		int base = 10;
		for (int i = 0; i < cnt; i++) {
			//∑÷≈‰
			for (int j = 0; j < len; j++) {
				int num = (v[j] / (int)pow(10, i)) % 10;
				t[num].push(v[j]);
			}
			// ’ºØ
			int k = 0;
			for (int m = 0; m < 10; m++) {
				while (t[m].size()) {
					v[k] = t[m].front();
					t[m].pop();
					k++;
				}
			}
		}
	}
};




int mainpx()
{
	vector<int> v= {0,1,2,5,3,4,6,7 };
	
	solution s;

	for_each(v.begin(), v.end(), [](int num) {cout << num << " "; });
	cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}