//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<iostream>
//#include<functional>
//#include<queue>
//#include<queue>
//#include<stack>
//
//using namespace std;
//
//class MedianFinder {
//public:
//	/** initialize your data structure here. */
//	MedianFinder() {
//		cnt = 0;
//	}
//
//	void addNum(int num) {
//		if (cnt % 2 == 0) {
//			if (cnt == 0) {
//				big.push(num);
//			}
//			else {
//				if (num <= big.top() || (num>big.top() && num <= small.top())) {
//					big.push(num);
//				}
//				else {
//					big.push(small.top());
//					small.pop();
//					small.push(num);
//				}
//			}
//			cnt++;
//		}
//		else {
//			if (cnt == 1) {
//				if (num < big.top()) {
//					small.push(big.top());
//					big.pop();
//					big.push(num);
//				}
//				else {
//					small.push(num);
//				}
//			}
//			else {
//				if (num >= small.top() || (num<small.top() && num>big.top())) {
//					small.push(num);
//				}
//				else {
//					small.push(big.top());
//					big.pop();
//					big.push(num);
//				}
//			}
//			cnt++;
//		}
//	}
//
//	double findMedian() {
//		if (big.size() > small.size()) {
//			return big.top();
//		}
//		else {
//			cout << big.top() << " " << small.top();
//			double res = (big.top() + small.top())*1.0 / 2.0;
//			return res;
//		}
//	}
//
//private:
//	priority_queue<int, vector<int>, greater<int>> small;
//	priority_queue<int, vector<int>, less<int>> big;
//	int cnt;
//};
//
//int main() {
//	MedianFinder m;
//	m.addNum(1);
//	m.addNum(2);
//	cout << m.findMedian() << endl;
//	system("pause");
//	return 0;
//}
