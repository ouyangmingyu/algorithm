#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
#include<queue>
#include<stack>

using namespace std;

class Solution {
public:
	int calculate(string s) {
		int len = s.size();
		static const int STATE_BEGINE = 0;
		static const int STATE_NUMBER = 1;
		static const int STATE_OPERAT = 2;
		int STATE = STATE_BEGINE;
		bool compute_flag = false;
		long long number = 0;
		for (int i = 0; i < len; i++) {
			if (s[i] == ' ') {
				continue;
			}
			switch (STATE)
			{
			case STATE_BEGINE:
				if (s[i] >= '0'&&s[i] <= '9') {
					STATE = STATE_NUMBER;
				}
				else {
					STATE = STATE_OPERAT;
				}
				i--;
				break;

			case STATE_NUMBER:
				if (s[i] >= '0'&&s[i] <= '9') {
					number = number * 10 + s[i] - '0';
				}
				else {
					num_s.push(number);
					if (compute_flag) {
						compute();
					}
					number = 0;
					i--;
					STATE = STATE_OPERAT;
				}
				break;

			case STATE_OPERAT:
				if (s[i] == '-' || s[i] == '+') {
					oper_s.push(s[i]);
					compute_flag = true;
				}
				else if (s[i] >= '0'&&s[i] <= '9') {
					STATE = STATE_NUMBER;
					i--;
				}
				else if (s[i] == '(') {
					compute_flag = false;
					STATE = STATE_NUMBER;
				}
				else if (s[i] == ')') {
					compute();
				}
				break;
			}	
		}
		if (number != 0) {
			num_s.push(number);
			compute();
		}
		if (number == 0 && num_s.empty()) {
			return 0;
		}
		return num_s.top();
	}
	void compute()
	{
		if (num_s.size() < 2) {
			return;
		}
		long long num2 = num_s.top();
		num_s.pop();
		long long num1 = num_s.top();
		num_s.pop();
		if (oper_s.top() == '+') {
			num_s.push(num1 + num2);
		}
		else {
			num_s.push(num1 - num2);
		}
		oper_s.pop();
	}

private:
	stack<long long> num_s;
	stack<char> oper_s;
};