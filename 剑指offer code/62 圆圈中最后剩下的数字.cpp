#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>
#include<list>

using namespace std;




void res62(int n, int m)
{
	/*list<int> l;
	for (int i = 0; i < n; i++) {
		l.push_back(i);
	}


	auto pos = l.begin();
	
	while(true) {
		if (l.size() == 1) {
			cout << "ʤ������" << *pos << endl;
			break;
		}
		
		for (int i = 1; i < m; i++) {
			pos++;
			if (pos == l.end()) {
				pos = l.begin();
			}
		}
		pos=l.erase(pos);
		if (pos == l.end()) {
			pos = l.begin();
		}
	}*/
	//�ݹ鹫ʽ��
	int res = 0;
	for (int i = 2; i <= n; i++) {
		res = (res + m) % i;
	}
	cout << "�Ҵ�����:" << res << endl;
}


int main62()
{
	list<int> l;
	l.push_back(0);

	res62(5, 3);

	system("pause");
	return EXIT_SUCCESS;
}