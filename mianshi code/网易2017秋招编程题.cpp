#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<functional>
#include<algorithm>
#include<queue>
#include<math.h>

using namespace std;


//如果一个数字序列逆置之后跟原序列是一样的就称这样的数字序列为回文序列。例如：
//{ 1, 2, 1 }, { 15, 78, 78, 15 }, { 112 } 是回文序列,
//{ 1, 2, 2 }, { 15, 78, 87, 51 }, { 112, 2, 11 } 不是回文序列。
//现在给出一个数字序列，允许使用一种转换操作：
//选择任意两个相邻的数，然后从序列移除这两个数，并用这两个数字的和插入到这两个数之前的位置(只插入一个和)。
//现在对于所给序列要求出最少需要多少次操作可以将其变成回文序列。

void sol20171(deque<int> v)
{
	int cnt = 0;
	int len = v.size();
	while (v.size()>1) {
		int i = v.front();
		int j = v.back();
		if (i == j) {
			v.pop_front();
			v.pop_back();
		}
		else {
			cnt++;
			if (i < j) {
				int add = v.front();
				v.pop_front();
				add += v.front();
				v.pop_front();
				v.push_front(add);
			}
			else {
				int add = v.back();
				v.pop_back();
				add += v.back();
				v.pop_back();
				v.push_back(add);
			}
		}
	}
	cout << cnt << endl;
}

//小易有一个圆心在坐标原点的圆，小易知道圆的半径的平方。小易认为在圆上的点而且横纵坐标都是整数的点是优雅的，
//小易现在想寻找一个算法计算出优雅的点的个数，请你来帮帮他。
//例如：半径的平方如果为25
//优雅的点就有：(+/ -3, +/ -4), (+/ -4, +/ -3), (0, +/ -5) (+/ -5, 0)，一共12个点。

void sol20172(int re)
{
	int cnt = 0;
	int num = sqrt(re);
	if (num*num == re) {
		cnt += 4;
	}
	for (int i = 1; i < num; i++) {
		int num2 = sqrt(re - i*i);
		if (num2*num2 + i*i == re) {
			cnt += 4;
		}
	}
	cout << cnt << endl;
}

//小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
//这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)
//步，即跳到K + X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
//例如：
//N = 4，M = 24：
//4->6->8->12->18->24
//于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板

void sol3(int N,int M)
{

}

//一个只包含'A'、'B'和'C'的字符串，如果存在某一段长度为3的连续子串中恰好'A'、'B'和'C'各有一个，那么这个字符串
//就是纯净的，否则这个字符串就是暗黑的。例如：
//BAACAACCBAAA 连续子串"CBA"中包含了'A', 'B', 'C'各一个，所以是纯净的字符串
//AABBCCAABB 不存在一个长度为3的连续子串包含'A', 'B', 'C', 所以是暗黑的字符串
//你的任务就是计算出长度为n的字符串(只包含'A'、'B'和'C')，有多少个是暗黑的字符串。

void sol4()
{

}


int main()
{
	int re;
	cin >> re;
	sol20172(25);
	system("pause");
	return 0;
}