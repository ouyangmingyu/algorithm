//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<iostream>
//#include<queue>
//#include<queue>
//#include<stack>
//
//#include "zx.h"
//
//class MinStack {
//public:
//	/** initialize your data structure here. */
//	MinStack() {
//
//	}
//
//	void push(int x) {
//		s.push(x);
//		if (min.size()) {
//			if (min.top() < x) {
//				min.push(min.top());
//			}
//			else {
//				min.push(x);
//			}
//		}
//		else {
//			min.push(x);
//		}
//	}
//
//	void pop() {
//		s.pop();
//		min.pop();
//	}
//
//	int top() {
//		return s.top();
//	}
//
//	int getMin() {
//		return min.top();
//	}
//
//private:
//	stack<int> s;
//	stack<int> min;
//};