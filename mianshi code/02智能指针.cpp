#include<iostream>
#include<string>

using namespace std;

class person {
public:
	person() :name("jack"),age(12) {};
	~person() {};
	void print() {
		cout << name<<endl;
	}

private:
	string name;
	int age;
};


class smartptr {
public:
	smartptr(person* p1) {
		p = p1;
	}
	person operator*() {
		return *p;
	}
	person* operator->() {
		return p;
	}
	~smartptr() {
		if (p != NULL) {
			delete p;
			p = nullptr;
		}
	}


private:
	person* p;
};


int main02()
{
	smartptr sp(new person);
	sp->print();
	(*sp).print();
	system("pause");
	return 0;
}