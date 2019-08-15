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
//using namespace std;
//
//class MyQueue {
//public:
//	/** Initialize your data structure here. */
//	MyQueue() {
//
//	}
//
//	/** Push element x to the back of queue. */
//	void push(int x) {
//		s1.push(x);
//	}
//
//	/** Removes the element from in front of queue and returns that element. */
//	int pop() {
//		if (s2.size()) {
//			int res = s2.top();
//			s2.pop();
//			return res;
//		}
//		else {
//			while (s1.size() != 1) {
//				s2.push(s1.top());
//				s1.pop();
//			}
//			int res = s1.top();
//			s1.pop();
//			return res;
//		}
//	}
//
//	/** Get the front element. */
//	int peek() {
//		if (s2.size()) {
//			int res = s2.top();
//			return res;
//		}
//		else {
//			while (s1.size() != 0) {
//				s2.push(s1.top());
//				s1.pop();
//			}
//			int res = s2.top();
//			return res;
//		}
//	}
//
//	/** Returns whether the queue is empty. */
//	bool empty() {
//		if (s1.size() || s2.size()) {
//			return false;
//		}
//		return true;
//	}
//
//private:
//	stack<int> s1;
//	stack<int> s2;
//};
//
//
//int main()
//{
//	MyQueue q;
//	q.push(1);
//	q.push(2);
//	cout << q.peek() << endl;
//	cout << q.pop() << endl;
//	if (q.empty()) {
//		cout << "empty queue" << endl;
//	}
//	else {
//		cout << "not empty" << endl;
//	}
//
//	system("pause");
//	return 0;
//}