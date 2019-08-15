#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<functional>
#include<queue>
#include<queue>
#include<stack>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int len = nums.size();
		vector<int> index(len, 0);
		int cur_max = nums[0];
		int pre_max = nums[0];
		int jump_min = 1;
		for (int i = 1; i < len; i++) {
			if (i > cur_max) {
				jump_min++;
				cur_max = pre_max;
			}
			if (nums[i] + i > pre_max) {
				pre_max = nums[i] + i;
			}
		}
		return jump_min;
	}
};

