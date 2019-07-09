#include<iostream>
#include<string>
#include<stack>

using namespace std;

class SStack {
public:
	void spop() {
		if (s.size()) {
			s.pop();
		}
	}
	void spush(int val) {
		if (s.size() == 0) {
			s.push(val);
		}
		if (val < s.top()) {
			s.push(val);
		}
		else {
			s.push(s.top());
		}
	}

	int min() {
		return s.top();
	}

private:
	stack<int> s;
};





int main34()
{
	SStack s;
	
	s.spush(3);
	s.spush(4);
	s.spush(2);
	s.spush(5);

	cout << s.min() << endl;

	system("pause");
	return EXIT_SUCCESS;
}