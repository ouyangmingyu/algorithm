#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


string Inttostr(int& num)
{
	string str;
	stack<int> s;
	while (true) {
		s.push(num % 10);
		num /= 10;
		if (num == 0) {
			break;
		}
	}
	while (!s.empty())
	{
		str += '0' + s.top();
		s.pop();
	}
	return str;
}

bool compare(string s1, string s2)
{
	string scomb1, scomb2;
	scomb1 = s1 + s2;
	scomb2 = s2 + s1;
	return scomb1 < scomb2;
}

void res45(vector<int> v)
{
	vector<string> s;
	int len = v.size();
	for (int i = 0; i < len; i++) {
		s.push_back(Inttostr(v[i]));
	}
	for_each(s.begin(), s.end(), [](string s) {cout << s << " "; });
	cout << endl;

	sort(s.begin(), s.end(), compare);
	for_each(s.begin(), s.end(), [](string s) {cout << s << " "; });
}


int main49()
{
	vector<int> v = { 3,32,321 };
	
	res45(v);
	

	system("pause");
	return EXIT_SUCCESS;
}