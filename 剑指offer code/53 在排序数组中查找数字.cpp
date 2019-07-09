#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;


int getFst(vector<int>& v, int num, int start, int end)
{
	if (start <= end) {
		int mid = (start + end) / 2;
		if (mid == 0&&v[0]==num) {
			return 0;
		}
		if (v[mid] == num&&v[mid-1]!=num) {
			return mid;
		}
		if (v[mid] == num&&v[mid - 1] == num) {
			return getFst(v, num, start, mid - 1);
		}
		if (v[mid] > num) {
			return getFst(v,num,start,mid-1);
		}
		if (v[mid] < num) {
			return getFst(v, num, mid+1,end);
		}
	}
	else {
		return -1;
	}	
	return -1;
}

int getLst(vector<int> v, int num, int start, int end)
{
	if (end < start) {
		return -1;
	}
	int mid = (start + end) / 2;
	int middledata = v[mid];
	if (middledata == num) {
		if (mid == end) {
			return mid;
		}
		if (mid < end&&v[mid + 1] != num) {
			return mid;
		}
		if (mid < end&&v[mid + 1] == num) {
			start = mid + 1;
		}
	}
	if (middledata < num) {
		start = mid + 1;
	}
	if (middledata > num) {
		end = mid - 1;
	}
	return getLst(v, num, start, end);
}

int res53(vector<int> v,int num,int start, int end)
{
	int fst = getFst(v, num, start, end);
	int lst = getLst(v, num, start, end);
	if (fst != -1 && lst != -1) {
		return lst - fst + 1;
	}
	else {
		return 0;
	}
}

int timu531(vector<int> v, int start, int end)
{
	int mid = 0;
	while (start<=end)
	{
		int mid = (start + end) / 2;
		if (v[mid] != mid) {
			if (mid == 0) {
				return 0;
			}
			else {
				if (v[mid - 1] != mid - 1) {
					end = mid - 1;
				}
				else {
					return v[mid - 1] + 1;
				}
			}
		}
		else {
			start = mid + 1;
		}
	}
	if (start = v.size()) {
		return v.size();
	}
	return -1;
}



int tmain()
{
	vector<int> v = { 0,1,2,3,4,5,6,7,9,10 };
	cout << timu531(v, 0, 9) << endl;
	/*int cnt = 0;
	res53(v,2, 0, 8) ;
	cout << "出现了" << cnt << "次" << endl;*/
	system("pause");
	return EXIT_SUCCESS;
}