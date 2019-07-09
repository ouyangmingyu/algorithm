#include<iostream>
#include<string>

using namespace std;


//主席单例模式
class chairman
{
private:
	chairman()
	{

	}
	chairman(const chairman& c)
	{

	}

public:
	static chairman* getinstance()
	{
		return singleman;
	}

private:
	static chairman* singleman;
};

chairman* chairman::singleman = new chairman;

int main03()
{
	chairman* cm1 = chairman::getinstance();
	chairman* cm2 = chairman::getinstance();

	if (cm1 == cm2)
	{
		cout << "equal" << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}