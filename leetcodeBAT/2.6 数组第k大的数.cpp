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
	int findKthLargest(vector<int>& nums, int k) {
		int len = nums.size();
		for (int i = 0; i < k; i++) {
			q.push(nums[i]);
		}
		for (int i = k; i < len; i++) {
			if (nums[i] > q.top()) {
				q.pop();
				q.push(nums[i]);
			}
		}
		cout << q.top() << endl;
	}

	priority_queue<int, vector<int>, greater<int>> q;
};