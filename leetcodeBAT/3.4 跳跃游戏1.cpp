//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<iostream>
//#include<functional>
//#include<queue>
//#include<queue>
//#include<stack>
//
//using namespace std;
//
//class Solution {
//public:
//	bool canJump(vector<int>& nums) {
//		int len = nums.size();
//		vector<int> index(len, 0);
//		for (int i = 0; i < len; i++) {
//			index[i] = i + nums[i];
//		}
//		int max_index = 0;
//		int jump = 0;
//		while (jump < len&&jump < max_index) {
//			max_index = max_index > index[jump] ? max_index : index[jump];
//			jump++;
//		}
//		if (jump == len) {
//			return true;
//		}
//		return false;
//	}
//};
//
//int main()
//{
//	vector<int> v = { 3,2,1,0,4 };
//	Solution s;
//	if (s.canJump(v)) {
//		cout << "OK" << endl;
//	}
//	system("pause");
//	return 0;
//}