#include<iostream>
#include<string>
#include<stack>
#include<queue>

using namespace std;

template<class T>
class CStack
{
public:
	CStack(void){}
	~CStack(void){}

	void Mypush(const T& ele);
	T Mypop();

private:
	queue<T> q1;
	queue<T> q2;
};

template<class T>
void CStack<T>::Mypush(const T& ele)
{
	if (q1.size()) {
		q1.push(ele);
	}
	else {
		q2.push(ele);
	}
}

template<class T>
T CStack<T>::Mypop()
{
	T result = NULL;
	if (q1.size() && q2.size()) {
		throw new exception("The stack is empty");
	}
	else if (q1.size()) {
		while (q1.size() > 1) {
			T ele = q1.front();
			q1.pop();
			q2.push(ele);
		}
		result = q1.front();
		q1.pop();
	}
	else if (q2.size()) {
		while (q2.size() > 1) {
			T ele = q2.front();
			q2.pop();
			q1.push(ele);
		}
		result = q2.front();
		q2.pop();
	}
	return result;
}


int main12()
{
	CStack<int> st;
	st.Mypush(10);
	st.Mypush(20);
	st.Mypush(30);

	cout << st.Mypop() << endl;
	cout << st.Mypop() << endl;
	st.Mypush(40);
	cout << st.Mypop() << endl;
	system("pause");
	return EXIT_SUCCESS;
}