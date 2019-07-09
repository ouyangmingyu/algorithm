#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

void res28(string& s)
{
	vector<int> v;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= 'A'&&s[i] <= 'Z') {
			s[i] = 'a' + (s[i] - 'A');
		}
	}
	while (s.size()) {
		//ɾ0
		while (find(s.begin(), s.end(), 'z') != s.end()) {
			v.push_back(0);
			s.erase(find(s.begin(), s.end(), 'z'));
			s.erase(find(s.begin(), s.end(), 'e'));
			s.erase(find(s.begin(), s.end(), 'r'));
			s.erase(find(s.begin(), s.end(), 'o'));
		}
		//ɾ2
		while (find(s.begin(), s.end(), 'w') != s.end()) {
			v.push_back(2);
			s.erase(find(s.begin(), s.end(), 't'));
			s.erase(find(s.begin(), s.end(), 'w'));
			s.erase(find(s.begin(), s.end(), 'o'));
		}
		//ɾ4
		while (find(s.begin(), s.end(), 'u') != s.end()) {
			v.push_back(4);
			s.erase(find(s.begin(), s.end(), 'f'));
			s.erase(find(s.begin(), s.end(), 'o'));
			s.erase(find(s.begin(), s.end(), 'u'));
			s.erase(find(s.begin(), s.end(), 'r'));
		}
		//ɾ6
		while (find(s.begin(), s.end(), 'x') != s.end()) {
			v.push_back(6);
			s.erase(find(s.begin(), s.end(), 's'));
			s.erase(find(s.begin(), s.end(), 'i'));
			s.erase(find(s.begin(), s.end(), 'x'));
		}
		//ɾ8
		while (find(s.begin(), s.end(), 'g') != s.end()) {
			v.push_back(8);
			s.erase(find(s.begin(), s.end(), 'e'));
			s.erase(find(s.begin(), s.end(), 'i'));
			s.erase(find(s.begin(), s.end(), 'g'));
			s.erase(find(s.begin(), s.end(), 'h'));
			s.erase(find(s.begin(), s.end(), 't'));
		}
		//ɾ1
		while (find(s.begin(), s.end(), 'o') != s.end()) {
			v.push_back(1);
			s.erase(find(s.begin(), s.end(), 'o'));
			s.erase(find(s.begin(), s.end(), 'n'));
			s.erase(find(s.begin(), s.end(), 'e'));
		}
		//ɾ3
		while (find(s.begin(), s.end(), 'h') != s.end()) {
			v.push_back(3);
			s.erase(find(s.begin(), s.end(), 't'));
			s.erase(find(s.begin(), s.end(), 'h'));
			s.erase(find(s.begin(), s.end(), 'r'));
			s.erase(find(s.begin(), s.end(), 'e'));
			s.erase(find(s.begin(), s.end(), 'e'));
		}
		//ɾ5
		while (find(s.begin(), s.end(), 'f') != s.end()) {
			v.push_back(5);
			s.erase(find(s.begin(), s.end(), 'f'));
			s.erase(find(s.begin(), s.end(), 'i'));
			s.erase(find(s.begin(), s.end(), 'v'));
			s.erase(find(s.begin(), s.end(), 'e'));
		}
		//ɾ7
		while (find(s.begin(), s.end(), 's') != s.end()) {
			v.push_back(7);
			s.erase(find(s.begin(), s.end(), 's'));
			s.erase(find(s.begin(), s.end(), 'e'));
			s.erase(find(s.begin(), s.end(), 'v'));
			s.erase(find(s.begin(), s.end(), 'e'));
			s.erase(find(s.begin(), s.end(), 'n'));
		}
		//ɾ9
		while (find(s.begin(), s.end(), 'i') != s.end()) {
			v.push_back(9);
			s.erase(find(s.begin(), s.end(), 'n'));
			s.erase(find(s.begin(), s.end(), 'i'));
			s.erase(find(s.begin(), s.end(), 'n'));
			s.erase(find(s.begin(), s.end(), 'e'));
		}
	}
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int num) {cout << num; });
	cout << endl;
}

int main28()
{
	string s;
	cin >> s;
	res28(s);
	system("pause");
	return 0;
}