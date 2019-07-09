#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

void mergevec(vector<int>& v, int start, int mid, int end, int& cnt)
{
	int i = start;
	int j = mid + 1;
	vector<int> res;
	while (true)
	{
		if (i < mid + 1 && j < end + 1) {
			if (v[i] > v[j]) {
				res.push_back(v[j]);
				cnt += (j-mid);
				j++;
			}
			else {
				res.push_back(v[i]);
				i++;
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
				cnt += (j - mid);
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

void res51(vector<int>& v,int start,int end,int& cnt)
{
	if (start < end) {
		int mid = (start + end) / 2;
		res51(v, start, mid, cnt);
		res51(v, mid+1, end, cnt);
		mergevec(v,start, mid, end, cnt);
	}
}

int tmain55()
{
	vector<int> v = { 7,5,6,4 };
	int cnt = 0;
	res51(v,0,3,cnt);
	for_each(v.begin(), v.end(), [](int num) {cout << num << " "; });
	cout << endl;
	cout << cnt << endl;
	system("pause");
	return EXIT_SUCCESS;
}