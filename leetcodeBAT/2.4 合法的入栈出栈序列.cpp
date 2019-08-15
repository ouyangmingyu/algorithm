//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<iostream>
//#include<queue>
//#include<queue>
//#include<stack>
//
//using namespace std;
//
//bool isPopOrder(deque<int> in, deque<int> out) {
//	stack<int> s;
//	while (out.size()>0) {
//		if (in.size()) {
//			s.push(in.front());
//			in.pop_front();
//		}
//		if (s.size() == 0) {
//			return false;
//		}
//		if (s.top() == out.front()) {
//			out.pop_front();
//			s.pop();
//			continue;
//		}
//		else {
//			if (in.size() == 0) {
//				return false;
//			}
//			continue;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	deque<int> in = { 1,2,3,4,5 };
//	deque<int> out = { 4,5,3,2,1 };
//	if (isPopOrder(in, out)) {
//		cout << "legal" << endl;
//	}
//	else {
//		cout << "inlegal" << endl;
//	}
//	system("pause");
//	return 0;
//}