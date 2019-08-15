#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
#include<queue>
#include<stack>

#include "zx.h"

using namespace std;

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		if (q1.size()) {
			q1.push(x);
		}
		else {
			q2.push(x);
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		if (q1.size()) {
			while (q1.size() != 1) {
				q2.push(q1.front());
				q1.pop();
			}
			int res = q1.back();
			q1.pop();
			return res;
		}
		else {
			while (q2.size() != 1) {
				q1.push(q2.front());
				q2.pop();
			}
			int res = q2.back();
			q2.pop();
			return res;
		}
	}

	/** Get the top element. */
	int top() {
		if (q1.size()) {
			return q1.back();
		}
		else {
			return q2.back();
		}
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		if (q1.size() || q2.size()) {
			return false;
		}
		return true;
	}

private:
	queue<int> q1;
	queue<int> q2;
};

int mainz()
{
	ListNode n1(1);
	ListNode n2(2);
	n1.next = &n2;
	n2.next = &n1;

	system("pause");
	return 0;
}
