//#include<iostream>
//#include<string>
//#include<vector>
//#include<map>
//#include<set>
//#include<limits.h>
//#include<iomanip>
//#include<algorithm>
//
//using namespace std;
//
//
////小易准备去魔法王国采购魔法神器, 购买魔法神器需要使用魔法币, 但是小易现在一枚魔法币都没有, 但是小易有两台魔法机器可以通过投入x(x可以为0)个魔法
////币产生更多的魔法币。
////魔法机器1 : 如果投入x个魔法币, 魔法机器会将其变为2x + 1个魔法币
////	魔法机器2 : 如果投入x个魔法币, 魔法机器会将其变为2x + 2个魔法币
////	小易采购魔法神器总共需要n个魔法币, 所以小易只能通过两台魔法机器产生恰好n个魔法币, 小易需要你帮他设计一个投入方案使他最后恰好拥有n个魔法币。
//
////输入描述:
////输入包括一行, 包括一个正整数n(1 ≤ n ≤ 10 ^ 9), 表示小易需要的魔法币数量。
////
////输出描述 :
////输出一个字符串, 每个字符表示该次小易选取投入的魔法机器。其中只包含字符'1'和'2'。
//
////class Sol1 {
////	friend void sol1(int num);
////private:
////	void Backtrace(int i);
////	int tn;
////	int cn;
////	string res;
////	bool flag;
////};
////
////void Sol1::Backtrace(int i) {
////	if (2 * cn + 1 < tn&&flag == false) {
////		cn = 2 * cn + 1;
////		res += '1';
////		Backtrace(i + 1);
////		if (flag == false) {
////			res.erase(res.size() - 1, 1);
////			cn = (cn - 1) / 2;
////		}	
////	}
////	if (2 * cn + 1 == tn&&flag == false) {
////		cn = 2 * cn + 1;
////		flag = true;
////		res += '1';
////		return;
////	}
////	if (2 * cn + 1 > tn) {
////		return;
////	}
////
////	if (2 * cn + 2 < tn&&flag == false) {
////		cn = 2 * cn + 2;
////		res += '2';
////		Backtrace(i + 1);
////		if (flag == false) {
////			res.erase(res.size() - 1, 1);
////			cn = (cn - 2) / 2;
////		}
////	}
////	if (2 * cn + 2 == tn&&flag == false) {
////		cn = 2 * cn + 2;
////		flag = true;
////		res += '2';
////		return;
////	}
////	if (2 * cn + 2 > tn) {
////		return;
////	}
////}
////
////void sol1(int num)
////{
////	Sol1 s;
////	s.tn = num;
////	s.cn = 0;
////	s.flag = false;
////	s.Backtrace(1);
////	cout << s.res << endl;
////}
//
//void sol1(int num)
//{
//	string s;
//	while (num != 0) {
//		if ((num & 1) == 0) {
//			num = (num - 2) / 2;
//			s += '2';
//		}
//		if ((num & 1) != 0) {
//			num = (num - 1) / 2;
//			s += '1';
//		}
//	}
//	reverse(s.begin(), s.end());
//	cout << s << endl;
//}
//
//
////为了得到一个数的"相反数", 我们将这个数的数字顺序颠倒, 然后再加上原先的数得到"相反数"。例如, 为了得到1325的"相反数", 
////首先我们将该数的数字顺序颠倒, 我们得到5231, 之后再加上原先的数, 我们得到5231 + 1325 = 6556.如果颠倒之后的数字有前缀零, 
////前缀零将会被忽略。例如n = 100, 颠倒之后是1.
//
//void sol2(int num) {
//	int num1 = num;
//	int res = 0;
//	while (num) {
//		int tmp = num % 10;
//		res = (res * 10 + tmp);
//		num /= 10;
//	}
//	res += num1;
//	cout << res << endl;
//}
//
//
////一个由小写字母组成的字符串可以看成一些同一字母的最大碎片组成的。例如, "aaabbaaac"是由下面碎片组成的:'aaa', 'bb', 'c'。
////牛牛现在给定一个字符串, 请你帮助计算这个字符串的所有碎片的平均长度是多少。
//
////void sol3(string s) {
////	int len = s.size();
////	map<string,int> ss;
////	string s1;
////	s1 += s[0];
////	for (int i = 1; i < len; i++) {
////		if (s[i] != s[i - 1]) {
////			if (ss.find(s1) == ss.end()) {
////				ss[s1] = 1;
////			}
////			else {
////				ss[s1]++;
////			}
////			s1.clear();
////			s1 += s[i];
////			if (i == len - 1) {
////				if (ss.find(s1) == ss.end()) {
////					ss[s1] = 1;
////				}
////				else {
////					ss[s1]++;
////				}
////			}
////			continue;
////		}
////		s1 += s[i];
////		if (i == len - 1) {
////			if (ss.find(s1) == ss.end()) {
////				ss[s1] = 1;
////			}
////			else {
////				ss[s1]++;
////			}
////		}
////	}
////
////
////	int sz = 0;
////	
////	for (auto i = ss.begin(); i != ss.end(); i++) {
////		sz += (*i).second;
////	}
////
////	double res = (double)len / (double)sz;
////	cout <<setiosflags(ios::fixed) << setprecision(2) <<res<< endl;
////}
//
//void sol3(string s) {
//	int len = s.size();
//	set<char> sc;
//	string sb;
//	sb += s[0];
//	for (int i = 1; i < len; i++) {
//		if (s[i] != s[i - 1]) {
//			sb += s[i];
//		}
//	}
//	int cnt = sb.size();
//	double res = (double)len / (double)cnt;
//	cout << setiosflags(ios::fixed) << setprecision(2) << res << endl;
//}
//
//
////魔法王国一共有n个城市, 编号为0~n - 1号, n个城市之间的道路连接起来恰好构成一棵树。
////小易现在在0号城市, 每次行动小易会从当前所在的城市走到与其相邻的一个城市, 小易最多能行动L次。
////如果小易到达过某个城市就视为小易游历过这个城市了, 小易现在要制定好的旅游计划使他能游历最多的城市, 
////请你帮他计算一下他最多能游历过多少个城市(注意0号城市已经游历了, 游历过的城市不重复计算)。
//
//class sol4c {
//	friend void sol4(int n, int L, vector<int> parent);
//
//private:
//	void BackTrace(int t);
//	
//	vector<vector<int>> v;//城市连接情况
//	int n;//城市数目
//	int L;//限制步数
//	int cl;//现在的步数
//	int cn;//现在的城市
//	int maxn;//最多的城市
//	int cc;//现在所处的城市
//	vector<bool> flag;
//	multiset<int> s;
//};
//
//void sol4c::BackTrace(int t) {
//	if (cl == L) {
//		maxn = maxn > cn ? maxn : cn;
//		return;
//	}
//	int curc = cc;
//	int i = 0;
//	while (i < n) {
//		if (i != curc&&v[curc][i]==1) {
//			cl++;
//			if (s.find(i)==s.end()) {
//				cn++;
//			}
//			s.insert(i);
//			cc = i;
//			BackTrace(t + 1);
//			cc = curc;
//			cl--;
//			auto it = s.find(i);
//			s.erase(it);
//			if (s.find(i) ==s.end()) {
//				cn--;
//			}
//		}
//		i++;
//	}
//}
//
//void sol4(int n,int L,vector<int> parent)
//{
//	sol4c S;
//	vector<vector<int>> v(n, vector<int>(n, INT_MAX));
//	
//	int len = parent.size();
//	for (int i = 0; i < len; i++) {
//		v[parent[i]][i + 1] = 1;
//		v[i + 1][parent[i]] = 1;
//	}
//
//	S.n = n;
//	S.L = L;
//	S.cl = 0;
//	S.cn = 1;
//	S.maxn = 0;
//	S.cc = 0;
//	S.v = v;
//	S.flag = vector<bool>(n, false);
//	S.flag[0] = true;
//	S.s.insert(0);
//	S.BackTrace(1);
//	int res = S.maxn;
//	cout << res << endl;
//}
//
//
////小易有一个长度为N的正整数数列A = { A[1], A[2], A[3]..., A[N] }。
////牛博士给小易出了一个难题 :
////对数列A进行重新排列, 使数列A满足所有的A[i] * A[i + 1](1 ≤ i ≤ N - 1)都是4的倍数。
////小易现在需要判断一个数列是否可以重排之后满足牛博士的要求。
//
//class sol5cc {
//	friend void sol5c1(vector<int> v);
//private:
//	int n;
//	void Backtrace(int i);
//	bool flag;
//	vector<int> v;
//};
//
//void sol5cc::Backtrace(int i) {
//	if (i == n-1) {
//		if ((v[i] * v[i - 1]) % 4 == 0) {
//			flag = true;
//			return;
//		}
//		else {
//			return;
//		}
//		
//	}
//	for (int j = i; j < n; j++) {
//		if (i == 0) {
//			swap(v[i], v[j]);
//			Backtrace(i + 1);
//			swap(v[i], v[j]);
//		}
//		else {
//			if ((v[i-1] * v[j]) % 4 == 0) {
//				swap(v[i], v[j]);
//				Backtrace(i + 1);
//				swap(v[i], v[j]);
//			}
//		}
//	}
//}
//
//void sol5c1(vector<int> v) {
//	int len = v.size();
//	sol5cc S;
//	S.n = len;
//	S.flag = false;
//	S.v = v;
//	S.Backtrace(0);
//	if (S.flag) {
//		cout << "Yes" << endl;
//	}
//	else {
//		cout << "No" << endl;
//	}
//}
//
//
//void sol5c2(vector<int> v)
//{
//	int cnt2 = 0;
//	int cnt4 = 0;
//	int cnto = 0;
//	int len = v.size();
//	for (int i = 0; i < len; i++) {
//		if (v[i] % 2 != 0) {
//			cnto++;
//		}
//		if (v[i] % 2 == 0 && v[i] % 4 != 0) {
//			cnt2++;
//		}
//	}
//	cnt4 = len - cnt2 - cnto;
//	if (cnt2 != 0) {
//		if (cnt4 >=  cnto) {
//			cout << "Yes" << endl;
//			return;
//		}
//		else {
//			cout << "No" << endl;
//			return;
//		}
//	}
//	else {
//		if (cnt4 >= cnto) {
//			cout << "Yes" << endl;
//			return;
//		}
//		else {
//			cout << "No" << endl;
//			return;
//		}
//	}
//}
//
//
//void sol5(vector<vector<int>> v)
//{
//	int len = v.size();
//	for (int i = 0; i < len; i++) {
//		sol5c2(v[i]);
//	}
//}
//
////一个合法的括号匹配序列被定义为:
////1. 空串""是合法的括号序列
////2. 如果"X"和"Y"是合法的序列, 那么"XY"也是一个合法的括号序列
////3. 如果"X"是一个合法的序列, 那么"(X)"也是一个合法的括号序列
////4. 每个合法的括号序列都可以由上面的规则生成
////例如"", "()", "()()()", "(()())", "(((()))"都是合法的。
////从一个字符串S中移除零个或者多个字符得到的序列称为S的子序列。
////例如"abcde"的子序列有"abe", "", "abcde"等。
////定义LCS(S, T)为字符串S和字符串T最长公共子序列的长度, 即一个最长的序列W既是S的子序列也是T的子序列的长度。
////小易给出一个合法的括号匹配序列s, 小易希望你能找出具有以下特征的括号序列t:
////1、t跟s不同, 但是长度相同
////2、t也是一个合法的括号匹配序列
////3、LCS(s, t)是满足上述两个条件的t中最大的
////因为这样的t可能存在多个, 小易需要你计算出满足条件的t有多少个。
////
////如样例所示 : s = "(())()", 跟字符串s长度相同的合法括号匹配序列有 :
////	"()(())", "((()))", "()()()", "(()())", 其中LCS("(())()", "()(())")为4, 其他三个都为5, 所以输出3.
//\
//
//
////class sol6c {
////	friend void sol6(string s);
////private:
////	void Backtrace(int t);
////	vector<string> legs;
////	int flag;
////	string s;
////	string sn;
////	int len;
////};
////
////void sol6c::Backtrace(int t) {
////	if (t == len) {
////		if (flag == 0&&s!=sn) {
////			legs.push_back(s);
////		}
////		return;
////	}
////	s[t] = '(';
////	flag++;
////	Backtrace(t + 1);
////	flag--;
////	if (flag > 0) {
////		s[t] = ')';
////		flag--;
////		Backtrace(t + 1);
////		flag++;
////	}
////}
////
////int LCS(string s1, string s2) {
////	int len1 = s1.size();
////	int len2 = s2.size();
////	vector<vector<int>> v(len1 + 1, vector<int>(len2 + 1, 0));
////	for (int i = 1; i <= len1; i++) {
////		for (int j = 1; j <= len2; j++) {
////			if (s1[i] == s2[j]) {
////				v[i][j] = v[i - 1][j - 1] + 1;
////			}
////			else {
////				v[i][j] = v[i - 1][j] > v[i][j - 1] ? v[i - 1][j] : v[i][j - 1];
////			}
////		}
////	}
////	return v[len1][len2];
////}
////
////
////void sol6(string s)
////{
////	sol6c S;
////	vector<string> legs;
////	S.flag = 0;
////	S.legs = legs;
////	int len = s.size();
////	S.s = s;
////	S.sn = s;
////	S.len = len;
////	S.Backtrace(0);
////
////	int maxl=-1;
////	int cnt = 0;
////	int cl;
////
////	len = S.legs.size();
////	
////	for (int i = 0; i < len; i++) {
////		cl = LCS(S.legs[i], s);
////		if (cl == maxl) {
////			cnt++;
////		}
////		if (cl > maxl) {
////			cnt = 1;
////			maxl = cl;
////		}
////	}
////
////	cout << cnt << endl;
////}
//
//bool legal(string s) {
//	int flag = 0;
//	int len = s.size();
//	for (int i = 0; i < len; i++) {
//		if (s[i] == '(') {
//			flag++;
//		}
//		if (s[i] == ')') {
//			if (flag == 0) {
//				return false;
//			}
//			flag--;
//		}
//	}
//	if (flag != 0) {
//		return false;
//	}
//	return true;
//}
//
//
//void sol6(string s)
//{
//	int len = s.size();
//	int cnt = 0;
//	set<string> sv;
//	for (int i = 0; i < len; i++) {
//		string st = s;
//		st.erase(i, 1);
//		for (int j = 0; j < len; j++) {
//			if (j == len - 1) {
//				st += s[i];
//				if (st != s) {
//					if (legal(st)) {
//						sv.insert(st);
//					}
//				}
//				st.erase(j, 1);
//				continue;
//			}
//			st.insert(j, 1, s[i]);
//			if (st != s) {
//				if (legal(st)) {
//					sv.insert(st);
//				}
//			}
//			st.erase(j, 1);
//		}
//	}
//	cnt = sv.size();
//	std::cout << cnt << endl;
//}
//
//
//
////小Q和牛博士合唱一首歌曲, 这首歌曲由n个音调组成, 每个音调由一个正整数表示。
////对于每个音调要么由小Q演唱要么由牛博士演唱, 对于一系列音调演唱的难度等于所有相邻音调变化幅度之和, 
////例如一个音调序列是8, 8, 13, 12, 那么它的难度等于 | 8 - 8 | +| 13 - 8 | +| 12 - 13 | = 6(其中 || 表示绝对值)。
////现在要对把这n个音调分配给小Q或牛博士, 让他们演唱的难度之和最小, 请你算算最小的难度和是多少。
////如样例所示 : 小Q选择演唱{ 5, 6 }难度为1, 牛博士选择演唱{ 1, 2, 1 }难度为2, 难度之和为3, 这一个是最小难度和的
////方案了。
//
//
//void sol7(vector<int> v)
//{
//	int len = v.size();
//	int left = 0;
//	int right = 0;
//	for (int i = 1; i < len - 1; i++) {
//		left += abs(v[i] - v[i + 1]);
//	}
//	int cur = left + right;
//	int min = cur;
//	for (int i = 2; i < len - 1; i++) {
//		left += abs(v[i - 1] - v[i]);
//		right -= abs(v[i] - v[i + 1]);
//		cur = left + right;
//		min = min < cur ? min : cur;
//	}
//	cout << min << endl;
//}
//
////小易正在玩一款新出的射击游戏, 这个射击游戏在一个二维平面进行, 小易在坐标原点(0, 0), 平面上有n只怪物, 
////每个怪物有所在的坐标(x[i], y[i])。小易进行一次射击会把x轴和y轴上(包含坐标原点)的怪物一次性消灭。
////小易是这个游戏的VIP玩家, 他拥有两项特权操作:
////1、让平面内的所有怪物同时向任意同一方向移动任意同一距离
////2、让平面内的所有怪物同时对于小易(0, 0)旋转任意同一角度
////小易要进行一次射击。小易在进行射击前, 可以使用这两项特权操作任意次。
////小易想知道在他射击的时候最多可以同时消灭多少只怪物, 请你帮帮小易。
//
//void sol8(vector<pair<int, int>> v)
//{
//
//}
//
//
//
//
//int mainwy()
//{
//	
//	string num;
//	cin >> num;
//
//	
//	sol6(num);
//
//	system("pause");
//	return 0;
//}