//#include<iostream>
//#include<string>
//#include<stack>
//#include<vector>
//
//using namespace std;
//
//
//int res44(int index)
//{
//	int i = 1;
//	int tmp = 9;
//	int res = 0;
//	while (true) {
//		if (index < tmp) {
//			break;
//		}	
//		i++;
//		tmp += 9 * i*pow(10, i-1);
//	}
//	int fst = tmp - 9 * i*pow(10, i - 1) + 1;
//	int dis = index - fst + 1;
//	int tarnum = pow(10, i - 1) + dis / i;
//	int num2 = tmp - index;
//	for (int i = 0; i < num2; i++) {
//		tarnum /= 10;
//		if (i == num2 - 1) {
//			res = tarnum % 10;
//		}
//	}
//	return res;
//}
//
//
//int main48()
//{
//	cout << "序列的第" << 23 << "位数是" << res44(23) << endl;
//	system("pause");
//	return EXIT_SUCCESS;
//}