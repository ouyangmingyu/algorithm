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
////С��׼��ȥħ�������ɹ�ħ������, ����ħ��������Ҫʹ��ħ����, ����С������һöħ���Ҷ�û��, ����С������̨ħ����������ͨ��Ͷ��x(x����Ϊ0)��ħ��
////�Ҳ��������ħ���ҡ�
////ħ������1 : ���Ͷ��x��ħ����, ħ�������Ὣ���Ϊ2x + 1��ħ����
////	ħ������2 : ���Ͷ��x��ħ����, ħ�������Ὣ���Ϊ2x + 2��ħ����
////	С�ײɹ�ħ�������ܹ���Ҫn��ħ����, ����С��ֻ��ͨ����̨ħ����������ǡ��n��ħ����, С����Ҫ��������һ��Ͷ�뷽��ʹ�����ǡ��ӵ��n��ħ���ҡ�
//
////��������:
////�������һ��, ����һ��������n(1 �� n �� 10 ^ 9), ��ʾС����Ҫ��ħ����������
////
////������� :
////���һ���ַ���, ÿ���ַ���ʾ�ô�С��ѡȡͶ���ħ������������ֻ�����ַ�'1'��'2'��
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
////Ϊ�˵õ�һ������"�෴��", ���ǽ������������˳��ߵ�, Ȼ���ټ���ԭ�ȵ����õ�"�෴��"������, Ϊ�˵õ�1325��"�෴��", 
////�������ǽ�����������˳��ߵ�, ���ǵõ�5231, ֮���ټ���ԭ�ȵ���, ���ǵõ�5231 + 1325 = 6556.����ߵ�֮���������ǰ׺��, 
////ǰ׺�㽫�ᱻ���ԡ�����n = 100, �ߵ�֮����1.
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
////һ����Сд��ĸ��ɵ��ַ������Կ���һЩͬһ��ĸ�������Ƭ��ɵġ�����, "aaabbaaac"����������Ƭ��ɵ�:'aaa', 'bb', 'c'��
////ţţ���ڸ���һ���ַ���, ���������������ַ�����������Ƭ��ƽ�������Ƕ��١�
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
////ħ������һ����n������, ���Ϊ0~n - 1��, n������֮��ĵ�·��������ǡ�ù���һ������
////С��������0�ų���, ÿ���ж�С�׻�ӵ�ǰ���ڵĳ����ߵ��������ڵ�һ������, С��������ж�L�Ρ�
////���С�׵����ĳ�����о���ΪС�����������������, С������Ҫ�ƶ��õ����μƻ�ʹ�����������ĳ���, 
////�����������һ������������������ٸ�����(ע��0�ų����Ѿ�������, �������ĳ��в��ظ�����)��
//
//class sol4c {
//	friend void sol4(int n, int L, vector<int> parent);
//
//private:
//	void BackTrace(int t);
//	
//	vector<vector<int>> v;//�����������
//	int n;//������Ŀ
//	int L;//���Ʋ���
//	int cl;//���ڵĲ���
//	int cn;//���ڵĳ���
//	int maxn;//���ĳ���
//	int cc;//���������ĳ���
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
////С����һ������ΪN������������A = { A[1], A[2], A[3]..., A[N] }��
////ţ��ʿ��С�׳���һ������ :
////������A������������, ʹ����A�������е�A[i] * A[i + 1](1 �� i �� N - 1)����4�ı�����
////С��������Ҫ�ж�һ�������Ƿ��������֮������ţ��ʿ��Ҫ��
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
////һ���Ϸ�������ƥ�����б�����Ϊ:
////1. �մ�""�ǺϷ�����������
////2. ���"X"��"Y"�ǺϷ�������, ��ô"XY"Ҳ��һ���Ϸ�����������
////3. ���"X"��һ���Ϸ�������, ��ô"(X)"Ҳ��һ���Ϸ�����������
////4. ÿ���Ϸ����������ж�����������Ĺ�������
////����"", "()", "()()()", "(()())", "(((()))"���ǺϷ��ġ�
////��һ���ַ���S���Ƴ�������߶���ַ��õ������г�ΪS�������С�
////����"abcde"����������"abe", "", "abcde"�ȡ�
////����LCS(S, T)Ϊ�ַ���S���ַ���T����������еĳ���, ��һ���������W����S��������Ҳ��T�������еĳ��ȡ�
////С�׸���һ���Ϸ�������ƥ������s, С��ϣ�������ҳ�����������������������t:
////1��t��s��ͬ, ���ǳ�����ͬ
////2��tҲ��һ���Ϸ�������ƥ������
////3��LCS(s, t)��������������������t������
////��Ϊ������t���ܴ��ڶ��, С����Ҫ����������������t�ж��ٸ���
////
////��������ʾ : s = "(())()", ���ַ���s������ͬ�ĺϷ�����ƥ�������� :
////	"()(())", "((()))", "()()()", "(()())", ����LCS("(())()", "()(())")Ϊ4, ����������Ϊ5, �������3.
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
////СQ��ţ��ʿ�ϳ�һ�׸���, ���׸�����n���������, ÿ��������һ����������ʾ��
////����ÿ������Ҫô��СQ�ݳ�Ҫô��ţ��ʿ�ݳ�, ����һϵ�������ݳ����Ѷȵ����������������仯����֮��, 
////����һ������������8, 8, 13, 12, ��ô�����Ѷȵ��� | 8 - 8 | +| 13 - 8 | +| 12 - 13 | = 6(���� || ��ʾ����ֵ)��
////����Ҫ�԰���n�����������СQ��ţ��ʿ, �������ݳ����Ѷ�֮����С, ����������С���ѶȺ��Ƕ��١�
////��������ʾ : СQѡ���ݳ�{ 5, 6 }�Ѷ�Ϊ1, ţ��ʿѡ���ݳ�{ 1, 2, 1 }�Ѷ�Ϊ2, �Ѷ�֮��Ϊ3, ��һ������С�ѶȺ͵�
////�����ˡ�
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
////С��������һ���³��������Ϸ, ��������Ϸ��һ����άƽ�����, С��������ԭ��(0, 0), ƽ������nֻ����, 
////ÿ�����������ڵ�����(x[i], y[i])��С�׽���һ��������x���y����(��������ԭ��)�Ĺ���һ��������
////С���������Ϸ��VIP���, ��ӵ��������Ȩ����:
////1����ƽ���ڵ����й���ͬʱ������ͬһ�����ƶ�����ͬһ����
////2����ƽ���ڵ����й���ͬʱ����С��(0, 0)��ת����ͬһ�Ƕ�
////С��Ҫ����һ�������С���ڽ������ǰ, ����ʹ����������Ȩ��������Ρ�
////С����֪�����������ʱ��������ͬʱ�������ֻ����, ������С�ס�
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