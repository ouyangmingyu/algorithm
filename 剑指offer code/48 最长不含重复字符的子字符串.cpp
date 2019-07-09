#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<map>

using namespace std;


int res48(string str,int len)
{
	map<char,int> m;
	for (char i = 'a'; i <= 'z'; i++) {
		m[i] = -1;
	}
	map<int, int> m2;
	for (int i = 0; i < len; i++) {
		m2[i] = 0;
	}
	int max = -1;
	for (int i = 0; i < len; i++) {
		if (i == 0) {
			 m[str[i]] = i;
			 m2[i]= 1;
		}
		else {
			if (m[str[i]] == -1) {
				m2[i] = m2[i - 1] + 1;
				m[str[i]] = i;
			}
			else {
				int d = i - m[str[i]];
				if (d <= m2[i - 1]) {
					m2[i] = d;
				}
				else {
					m2[i] = m2[i - 1] + 1;
				}
				m[str[i]] = i;
			}
		}	
		max = max > m2[i] ? max : m2[i];
	}
	return max;
}

int main52()
{
	cout << res48("arabcacfr", 9) << endl;
	system("pause");
	return EXIT_SUCCESS;
}