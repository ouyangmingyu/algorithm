#include<iostream>
#include<string>
#include<stack>

using namespace std;

template<class T>
class CQueue {
public:
	CQueue(void){}
	~CQueue(void){}

	void appendTail(const T& ele);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};


template<class T>
void CQueue<T>::appendTail(const T& ele)
{
	stack1.push(ele);
}

template<class T>
T CQueue<T>::deleteHead()
{
	if (stack2.size() == 0) {
		while (stack1.size() > 0) {
			T data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	if (stack2.size()) {
		cout << "╤сапн╙©у" << endl;
	}
	T head = stack2.top();
	stack2.pop();
	return head;
}

int main11()
{
	CQueue<int> myQueue;
	myQueue.appendTail(10);
	myQueue.appendTail(20);
	myQueue.appendTail(30);

	cout << myQueue.deleteHead() << endl;
	system("pause");
	return EXIT_SUCCESS;
}