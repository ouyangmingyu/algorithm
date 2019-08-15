//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<iostream>
//#include<functional>
//#include<queue>
//#include<queue>
//#include<stack>
//#include<set>
//
//using namespace std;
//
//class Solution {
//public:
//	vector<int> countSmaller(vector<int>& nums) {
//		int len = nums.size();
//		for (int i = 0; i < len; i++) {
//			tmp.push_back(make_pair(i, nums[i]));
//			count.push_back(0);
//		}
//		countSmallerc(0, len - 1);
//		return count;
//	}
//
//	void countSmallerc(int l,int r) {
//		if (l < r) {
//			int mid = (l + r) / 2;
//			countSmallerc(l, mid);
//			countSmallerc(mid + 1, r);
//			merge(l, mid, r);
//		}
//	}
//
//	void merge(int l, int mid, int r) {
//		vector<pair<int,int>> vt(r - l + 1, make_pair(0,0));
//		int i = mid;
//		int j = r;
//		int index = r - l;
//		while (i >= l&&j > mid) {
//			if (tmp[i].second > tmp[j].second) {
//				vt[index].first = tmp[i].first;
//				vt[index].second = tmp[i].second;
//				count[tmp[i].first] += j - mid;
//				index--;
//				i--;
//			}else if (tmp[j].second > tmp[i].second) {
//				vt[index].first = tmp[j].first;
//				vt[index].second = tmp[j].second;
//				index--;
//				j--;
//			}
//		}
//		while (i >= l) {
//			vt[index].first = tmp[i].first;
//			vt[index].second = tmp[i].second;
//			index--;
//			i--;
//		}
//		while (j > mid) {
//			vt[index].first = tmp[j].first;
//			vt[index].second = tmp[j].second;
//			index--;
//			j--;
//		}
//		int k = 0;
//		for (i = l; i <= r; i++) {
//			tmp[i].first = vt[k].first;
//			tmp[i].second = vt[k].second;
//			k++;
//		}
//	}
//
//private:
//	vector<pair<int,int>> tmp;
//	vector<int> count;
//};
//
//
//int main()
//{
//	Solution s;
//	vector<int> v = { 5,2,6,1 };
//	vector<int> res = s.countSmaller(v);
//	for_each(res.begin(), res.end(), [](int num) {cout << num << " "; });
//	system("pause");
//	return 0;
//}