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
	int wiggleMaxLength(vector<int>& nums) {
		int len = nums.size();
		if (len < 2) {
			return nums.size();
		}
		const int STATE_BEGIN = 0;
		const int STATE_UP = 1;
		const int STATE_DOWN = 2;
		int res = 1;
		int STATE = STATE_BEGIN;
		for (int i = 1; i < len; i++) {
			switch (STATE)
			{
			case STATE_BEGIN:
				if (nums[i] < nums[i - 1]) {
					STATE = STATE_DOWN;
					res++;
				}
				if (nums[i] > nums[i - 1]) {
					STATE = STATE_UP;
					res++;
				}
				break;

			case STATE_UP:
				if (nums[i] < nums[i - 1]) {
					STATE = STATE_DOWN;
					res++;
				}
				break;

			case STATE_DOWN:
				if (nums[i] > nums[i - 1]) {
					STATE = STATE_UP;
					res++;
				}
				break;
			}
		}
	}
};