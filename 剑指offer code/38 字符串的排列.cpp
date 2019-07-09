#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

void res38(string s,int len)
{
	if (len == s.size()) {
		cout << s << " ";
	}
	else {
		for (int i = len; i < s.size(); i++) {
			char tmp = s[i];
			s[i] = s[len];
			s[len] = tmp;
			res38(s, len + 1);
			tmp = s[i];
			s[i] = s[len];
			s[len] = tmp;
		}
	}
}


int main42()
{
	string s = "abc";
	
	res38("abc",0);
	system("pause");
	return EXIT_SUCCESS;
}