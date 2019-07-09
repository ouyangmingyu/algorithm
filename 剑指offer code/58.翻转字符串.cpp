#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

void res58t1(string& s)
{
	int len = s.size();
	reverse(s.begin(), s.end());
	auto start = s.begin(),end=s.begin();
	
	while (true) {
		if (end == s.end()) {
			reverse(start, end);
			break;
		}
		if (*end == ' ') {
			reverse(start,end);
			start = end + 1;
			end = end + 1;
			continue;
		}
		
		end++;
	}
	cout << s << endl;
}

void res58t2(string& s,int num)
{
	reverse(s.begin(), s.end());
	auto it = s.end();
	for (int i = 0; i < num; i++) {
		it--;
	}
	reverse(s.begin(), it);
	reverse(it, s.end());
	cout << s << endl;
}


int main58()
{
	string s = "abcdef";
	int len = s.size();
	
	
	res58t2(s,2);
	system("pause");
	return EXIT_SUCCESS;
}