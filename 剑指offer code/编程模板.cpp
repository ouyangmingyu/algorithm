#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<functional>
#include<unordered_map>
#include<exception>
#include "time.h"
#include "zx.h"

using namespace std;

bool func(string s1, string s2) {
	string s3 = s1 + s2;
	string s4 = s2 + s1;
	return s3 < s4;
}

struct qdata {
	int val;
	int index;
	qdata(int data, int index) :val(data), index(index) {}
};

class Solution {

public:
	//01赋值运算符(注意内存申请安全)
	Solution& operator=(Solution& s)
	{
		if (this != &s) {
			Solution tmps(s);
			swap(tmp, s.tmp);
		}
		return *this;
	}

	//02 单例模式的实现（线程安全、饱汉、饿汉）
	static Solution* instance()
	{
		//mutexlockguard();
		p = new Solution();
		return p;
	}

	//03 二维数组查找（根据数组特性从右上角开始找）
	bool erweichazhao(vector<vector<int>> v, int tar) {
		int row = v.size();
		int line = v[0].size();
		
		int i = 0;
		int j = line-1;
		while (i < row&&j >= 0) {
			if (v[i][j] == tar) {
				return true;
			}
			if (v[i][j] > tar) {
				j--;
			}
			if (v[i][j] < tar) {
				i++;
			}
		}

		return false;
	}

	//04 替换空格（提前把位置腾出来）
	void thkg(string& s) {
		int len1 = s.size();
		int cnt = 0;
		for (auto ch : s) {
			if (ch == ' ') {
				cnt++;
			}
		}
		for (int i = 0; i < 2 * cnt; i++) {
			s.push_back('\0');
		}
		int len2 = s.size();
		int p1 = len1 - 1;
		int p2 = len2 - 1;
		while (p1>=0) {
			if (s[p1] != ' ') {
				s[p2] = s[p1];
				p1--;
				p2--;
			}else{
				s[p2] = '0';
				p2--;
				s[p2] = '2';
				p2--;
				s[p2] = '%';
				p2--;
				p1--;
			}
		}
	}

	//05 从尾到头打印链表(利用栈，即递归思想)
	void dylb(ListNode* root) {
		if (root == nullptr) {
			return;
		}
		dylb(root->next);
		cout << root->val << endl;
	}

	//06重建二叉树（递归，注意判断大小是否为0）
	TreeNode* chongjianBT(vector<int> pre, vector<int> in) {
		int len1 = pre.size();
		int len2 = in.size();
		if (len1 == 0 || len2 == 0 || len1 != len2) {
			return nullptr;
		}
		return chongjiancore(pre, 0, len1 - 1, in, 0, len2 - 1);
	}
	TreeNode* chongjiancore(vector<int> pre, int prebegin, int preend, vector<int> in, int inbegin, int ineend) {
		int rootval = pre[prebegin];
		TreeNode* root = new TreeNode(rootval);
		int indexin = inbegin;
		while (rootval != in[indexin] && indexin <= ineend) {
			indexin++;
		}
		if (indexin > ineend) {
			return false;
		}
		int lenl = indexin - inbegin;
		int lenr = ineend - indexin;
		if (lenl > 0) {
			root->left = chongjiancore(pre, prebegin + 1, prebegin + 1 + lenl, in, inbegin, indexin - 1);
		}
		if (lenr > 0) {
			root->right = chongjiancore(pre, inbegin + 1 + lenl + 1, inbegin + 1 + lenl + 1 + lenr, in, indexin + 1, ineend);
		}
		return root;
	}

	//07 用两个栈实现队列(一个固定不动作为入队列，一个作为出队列，类比两个队列实现栈)
	void append(int val) {
		s1.push(val);
	}
	int deleteval()
	{
		if (s2.size()) {
			int ele = s2.top();
			s2.pop();
			return ele;
		}
		else {
			while (s1.size()) {
				s2.push(s1.top());
				s1.pop();
			}
			int ele = s2.top();
			s2.pop();
			return ele;
		}
	}

	//08 旋转数组的最小数字（二分法，因为是有序的序列,找到的标志是两游标相差为1）
	int xzzx(vector<int> v) {
		int len = v.size();
		if (len == 0) {
			return -1;
		}
		int p1 = 0;
		int p2 = len - 1;
		while (p1 < p2) {
			if (p1 - p2 == 1) {
				return v[p2];
			}
			int mid = (p1 + p2) / 2;
			if (v[mid] >= v[p2]) {
				p1 = mid;
			}
			if (v[mid] <= v[p1]) {
				p2 = mid;
			}
		}
		return -1;
	}

	//09 斐波拉契数列(自上而下分析，自下而上记录，有logn的算法但是不实用)
	int fblq(int n) {
		if (n <= 0) {
			return -1;
		}
		if (n == 1) {
			return 1;
		}
		if (n == 2) {
			return 1;
		}
		vector<int> fb;
		fb.push_back(0);
		fb.push_back(1);
		fb.push_back(2);
		for (int i = 3; i <= n; i++) {
			fb[i] = fb[i - 1] + fb[i - 2];
		}
		return fb[n];
	}

	//10 二进制中1的个数(用无符号1依次右移位于即可  或者和val-1与运算，看可以多少次)
	int numof1(int num) {
		int cnt = 0;
		while (num) {
			cnt++;
			num = num&(num - 1);
		}
		return cnt;
	}

	//11 数值的整次方(拆分实现log（n）的时间复杂度,二分法，注意奇偶情况的不同)
	double szzcf(int base, int ex) {
		if (equal(base,0.0)) {
			return 0.0;
		}
		if (ex < 0) {
			ex = -ex;
		}
		double res = value(base, ex);
		if (ex < 0) {
			res = 1.0 / res;
		}
		return res;
	}

	double value(int base, int ex)
	{
		if (ex == 0) {
			return 1;
		}
		if (ex == 1) {
			return base;
		}
		double res = value(base, ex >> 1)*value(base, ex >> 1);
		if (ex & 1) {
			res *= base;
		}
		return res;
	}

	bool equal(double d1, double d2)
	{
		return (abs(d1 - d2) < 0.0000001);
	}

	//12 打印1到最大的n位数(利用数字排列来打印)
	void printnum(string s)
	{
		int i = 0;
		int len = s.size();
		string s1;
		while (s[i] == '0') {
			i++;
			if (i == len - 1) {
				s1.assign(s, i, 1);
				cout << s1 << " ";
			}
		}
		s1.assign(s, i, len - i);
		cout << s1<<" ";
	}
	void print1ton(int n) {
		string s(n, '0');
		for (int i = 0; i < 10; i++) {
			s[0] = '0' + i;
			print1toncore(s, n, 0);
		}
	}
	void print1toncore(string& s, int length, int index) {
		if (index == length - 1) {
			printnum(s);
			return;
		}
		for (int i = 0; i < length; i++) {
			s[index + 1] = '0' + i;
			print1toncore(s, length, index + 1);
		}
	}
	
	//13 O(1)时间删除链表节点(替换为要删除节点的下一个节点，并指向下下个节点即可)
	void deletenode(ListNode* head, ListNode* deleten) {
		if (!head || !deleten) {
			return;
		}
		//删除头节点
		if (head == deleten) {
			delete deleten;
			head = nullptr;
			head = nullptr;
			return;
		}
		//删除尾节点
		if (deleten->next == nullptr) {
			delete deleten;
			deleten = nullptr;
			return;
		}
		//既不是头节点也不是尾节点
		ListNode* pn = deleten->next;
		deleten->val = pn->val;
		deleten->next = pn->next;
		delete pn;
		pn = nullptr;
	}

	//14 调整数组顺序使奇数位于偶数前面（1. 维护两个指针  2. 写出通用函数）
	bool isodd(int num) {
		return (num & 0x1);
	}
	void Recorder(vector<int> v, bool(*func)(int))
	{
		int len = v.size();
		if (len == 0) {
			return;
		}
		int p1 = 0;
		int p2 = len - 1;
		
		while (p1 < p2) {
			if (p2 - p1 == 1) {
				return;
			}
			//p1扫描到偶数
			if (!func(v[p1])) {
				//p2定位到奇数需要交换
				if (func(v[p2])) {
					swap(v[p1], v[p2]);
					p1++;
					p2--;
				}
				//p2也是偶数
				else {
					p2--;
				}
			}
			else {
				//p1扫描到奇数
				p1++;
			}
			
		}
	}

	//15 链表中的倒数第k个节点（寻找只需要遍历链表一次的办法，通过一前一后地指针即可实现）
	ListNode* finddk(ListNode* head, int k) {
		if (head == nullptr || k <= 0) {
			return nullptr;
		}
		ListNode* front = head;
		ListNode* back = head;
		while (k > 1) {
			back = back->next;
			if (back == nullptr) {
				return nullptr;
			}
			k--;
		}
		while (true) {
			if (back->next==nullptr) {
				return front;
			}
			front = front->next;
			back = back->next;
		}
	}

	//16 反转链表（利用三个节点,注意判断何时到达尾节点）
	ListNode* fzlb(ListNode* root) {
		if (root == nullptr) {
			return nullptr;
		}
		if (root->next == nullptr) {
			return root;
		}
		ListNode* pfront = nullptr;
		ListNode* pnow = root;
		ListNode* pnext = root->next;
		while (pnext != nullptr) {
			pnow->next = pfront;
			pfront = pnow;
			pnow = pnext;
			pnext = pnext->next;
			if (pnext == nullptr) {
				pnow->next = pfront;
			}
		}
		return pnow;
	}

	//17 合并两个排序的链表（归并排序在链表中的应用）
	ListNode* Merge(ListNode* h1, ListNode* h2) {
		if (h1 == nullptr) {
			return h2;
		}
		if (h2 == nullptr) {
			return h1;
		}
		ListNode* head;
		if (h1->val <= h2->val) {
			head = h1;
			head->next = Merge(h1->next, h2);
		}
		else {
			head = h2;
			head->next = Merge(h1, h2->next);
		}
		return head;
	}

	//18 树的子结构(递归判断即可,分两步 1. 找相同根节点（中左右） 2. 判断依次根节点为公共点的树是不是子树)
	bool treesub(TreeNode* root1, TreeNode* root2)
	{
		bool res = false;
		if (root2 == nullptr) {
			return true;
		}
		if (root1) {
			if (root1->val == root2->val) {
				res=ts(root1, root2);
			}
			if (!res) {
				res = treesub(root1->left, root2);
			}
			if (!res) {
				res = treesub(root1->right, root2);
			}
		}
		return res;
	}
	bool ts(TreeNode* root1, TreeNode* root2)
	{
		if (root2 == nullptr) {
			return true;
		}
		if (root1 == nullptr) {
			return false;
		}
		if (root1->val != root2->val) {
			return false;
		}

		return ts(root1->left, root2->left) && ts(root1->right, root2->right);
	}

	//19 二叉树的镜像（递归交换左右节点即可）

	void btjx(TreeNode* root) {
		if (root == nullptr) {
			return ;
		}
		swap(root->left, root->right);
		btjx(root->left);
		btjx(root->right);
	}

	//20 顺时针打印矩阵(注意分情况，找到继续循环的条件)

	void sszdy(vector<vector<int>> v,int row,int col) {
		if (row <= 0 || col <= 0) {
			return;
		}
		int start = 0;
		while (row > 2 * start&&col > 2 * start) {
			printcircle(v, row, col, start);
			++start;
		}
	}
	void printcircle(vector<vector<int>> v, int row, int col,int start) {
		int endx = row - 1 - start;
		int endy = col - 1 - start;
		//从左往右
		for (int i = start; i <= endy; i++) {
			cout << v[start][i];
		}
		//从上往下
		if (endx > start) {
			for (int i = start; i <= endx; i++) {
				cout << v[i][start];
			}
		}
		//从右往左
		if (endy > start) {
			for (int i = endy; i >=start; i--) {
				cout << v[endx][i];
			}
		}
		//从下往上
		if (endx-1>start&&start<endy) {
			for (int i = endx; i >= start+1; i--) {
				cout << v[i][start];
			}
		}
	}

	//21 包含min函数的栈（利用一个辅助栈来记录最小值，复杂度为O（1））
	void pushs(int val) {
		s1.push(val);
		if (mins.size() == 0) {
			mins.push(val);
		}
		else {
			if (mins.top() > val) {
				mins.push(val);
			}
			else {
				mins.push(mins.top());
			}
		}
	}
	void pops() {
		if (s1.size()) {
			s1.pop();
			mins.pop();
		}
	}
	int minval() {
		if (mins.size()) {
			return mins.top();
		}
	}

	//22 栈的压入弹出序列(利用一个辅助栈来解决)
	bool isPopOrder(deque<int> in, deque<int> out) {
		int len = in.size();
		if (len == 0) {
			return true;
		}
		stack<int> s;
		while (true) {
			if (in.size() == 0) {
				return false;
			}
			s.push(in.front());
			in.pop_front();
			while (true) {
				if (out.size() == 0) {
					return true;
				}
				if (s.size()&&s.top() == out.front()) {
					s.pop();
					out.pop_front();
				}
				else {
					break;
				}
				
			}
		}
	}

	//23 从上往下打印树（广度优先遍历）
	void printBtree(TreeNode* root) {
		if (root == nullptr) {
			return ;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (q.size()) {
			TreeNode* ele = q.front();
			q.pop();
			cout << ele->val << " ";
			if (ele->left) {
				q.push(ele->left);
			}
			if (ele->right) {
				q.push(ele->right);
			}
		}
	}

	//24 二叉搜索树的后续遍历
	bool ishxbl(vector<int> v, int l, int r) {
		if (l == r) {
			return true;
		}
		int root = v[r];
		//左子树序列
		int i = l;
		for (; i < r; i++) {
			if (v[i] > root) {
				break;
			}
		}
		//右子树序列
		int j = i;
		for (; j < r; j++) {
			if (v[j] < root) {
				return false;
			}
		}
		return ishxbl(v, l, i - 1) && ishxbl(v, i, j);
	}

	//25 二叉树中和为某一值的路径（可以增加剪枝策略）
	void findpath(TreeNode* root, int sum) {
		if (root == nullptr) {
			return;
		}
		vector<int> v;
		int sumn = 0;
		findPathcore(root, sum, v, sumn);
	}
	void findPathcore(TreeNode* root, int sum, vector<int>& v, int sumn) {
		sumn += root->val;
		v.push_back(root->val);
		//到达叶节点且和相等,直接打印
		if (sumn == sum&&root->left == nullptr&&root->right == nullptr) {
			for_each(v.begin(), v.end(), [](int num) {cout << num; });
			cout << endl;
		}
		//不是叶节点和小于sum
		if (root->left) {
			findPathcore(root->left, sum, v, sumn);
		}
		if (root->right) {
			findPathcore(root->right, sum, v, sumn);
		}
		sumn -= root->val;
		v.pop_back();
	}

	//26 复杂链表的复制(分三步来处理，空间复杂度为1，时间复杂度为n)
	ComplexListNode* fzlbfz(ComplexListNode* pHead) {
		if (pHead == nullptr) {
			return nullptr;
		}
		clonem_pNext(pHead);
		clonem_pSibling(pHead);
		return getlist(pHead);
	}
	void clonem_pNext(ComplexListNode* pHead)
	{
		ComplexListNode* now;
		while (true) {
			if (now->m_pNext == nullptr) {
				ComplexListNode* node = new ComplexListNode(now->m_nValue);
				now->m_pNext = node;
				return;
			}
			ComplexListNode* node = new ComplexListNode(now->m_nValue);
			ComplexListNode* next = now->m_pNext;
			now->m_pNext = node;
			now = next;
		}
	}
	void clonem_pSibling(ComplexListNode* pHead)
	{
		ComplexListNode* front=pHead;
		ComplexListNode* back=pHead->m_pNext;
		while (true) {
			if (back->m_pNext == nullptr) {
				back->m_pSibling = front->m_pSibling->m_pNext;
				return;
			}
			back->m_pSibling = front->m_pSibling->m_pNext;
			front = back->m_pNext;
			back = front->m_pNext;
		}
	}
	ComplexListNode* getlist(ComplexListNode* pHead) {
		ComplexListNode* chead = pHead->m_pNext;
		ComplexListNode* now = pHead;
		ComplexListNode* cnow = chead;

		while (true) {
			if (cnow->m_pNext == nullptr) {
				break;
			}
			now->m_pNext = cnow->m_pNext;
			now =cnow->m_pNext;
			cnow->m_pNext = now->m_pNext;
			cnow = now->m_pNext;
		}
		return chead;
	}

	//27 二叉搜索树和双向链表（左-》根-》右依次连接）
	TreeNode* Convert(TreeNode* root) {
		if (root == nullptr) return nullptr;
		TreeNode* plast=nullptr;
		lastnode(root, plast);
		while (plast != nullptr&&plast->left != nullptr) {
			plast = plast->left;
		}
		return plast;
	}
	void lastnode(TreeNode* root, TreeNode*& plast) {
		//找到左子树链表尾节点
		if (root->left) {
			lastnode(root->left, plast);
		}
		//尾节点转为当前根节点
		root->left = plast;
		if (plast) {
			plast->right = root;
		}
		plast = root;
		//连接右子树
		if (root->right) {
			lastnode(root->right, plast);
		}
	}

	//28 字符串的排列(全排列问题)
	void pl(string s) {
		int len = s.size();
		plcore(s, 0, len);
	}
	void plcore(string& s, int index,int len) {
		if (index == len) {
			cout << s << " ";
		}
		for (int i = index; i < len; i++) {
			swap(s[index], s[i]);
			plcore(s, index + 1, len);
			swap(s[index], s[i]);
		}
	}

	//29 数组中出现次数超过一半的数字（1 快排性质（需要修改数组）,超过一半的数字一定在中间 2. 利用数字的特性 都是O（n））
	int cgyb(vector<int> v) {
		int len = v.size();
		if (len <= 0) {
			return -1;
		}
		int res = v[0];
		int cnt = 1;
		for (int i = 1; i < len; i++) {
			if (v[i] == res) {
				cnt++;
				continue;
			}
			if (v[i] != res) {
				if (cnt == 0) {
					res = v[i];
					cnt = 1;
					continue;
				}
				cnt--;
			}
		}
		if (!checkvalid(v, res,len)) {
			res = -1;
		}
		return res;
	}
	bool checkvalid(vector<int> v, int num,int len) {
		int cnt = 0;
		for (int i = 0; i < len; i++) {
			if (v[i] == num) {
				cnt++;
			}
		}
		if (cnt <= len / 2) {
			return false;
		}
		return true;
	}

	//30 最小的K个数(小顶堆)
	void minknum(vector<int> v, int k,vector<int> res) {
		int len = v.size();
		if (len < k) {
			return;
		}
		priority_queue<int, vector<int>, less<int>> maxheap;
		for (int i = 0; i < k; i++) {
			maxheap.push(v[i]);
		}
		for (int i = k; i < len; i++) {
			if (v[i] < maxheap.top()) {
				maxheap.pop();
				maxheap.push(v[i]);
			}
		}
		for (int i = 0; i < k; i++) {
			res.push_back(maxheap.top());
			maxheap.pop();
		}
	}

	//31 连续子数组的最大和（动态规划或者数据规律，异曲同工之妙
	int lxmaxh(vector<int> v) {
		int len = v.size();
		if (len == 0) {
			return -1;
		}
		int maxsum = INT_MIN;
		int cursum = 0;
		for (int i = 0; i < len; i++) {
			if (cursum < 0) {
				cursum = v[i];
			}
			else {
				cursum += v[i];
			}
			maxsum = maxsum > cursum ? maxsum : cursum;
		}
		return maxsum;
	}
	
	//32 从1到n整数中1出现的次数
	int numof11ton(int n) {
		if (n <= 0) {
			return 0;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i *= 10) {
			int tmp = 0;
			int k = n % (10 * i);
			if (k > 2 * i - 1) {
				tmp = i;
			}
			else if (k < i) {
				tmp = 0;
			}
			else {
				tmp = k - i + 1;
			}
			cnt += (n / (10 * i))*i + tmp;
		}
		return cnt;
	}

	//33 把数组排成最小的数(大数问题+排序规则制定)
	void printMinunum(vector<int> v) {
		int len = v.size();
		if (len == 0) {
			return;
		}
		vector<string> vs(len," ");
		for (int i = 0; i < len; i++) {
			char* tmp=(char*)malloc(10);
			sprintf(tmp, "%d", v[i]);
			vs[i] = tmp;
		}
		sort(vs.begin(), vs.end(), func);
		for_each(vs.begin(), vs.end(), [](string s) {cout << s; });
		cout << endl;
	}

	//34 丑数(分析新的定义)
	int GetnUgly(int n) {
		vector<int> v;
		int index = 0;
		v.push_back(1);
		index++;
		int p2 = 0, p3 = 0, p5 = 0;
		while (index < n) {
			int minval = min3val(v[p2] * 2, v[p3] * 3, v[p5] * 5);
			v.push_back(minval);
			index++;
			while (v[p2] * 2 <= minval) {
				p2++;
			}
			while (v[p3] * 3 <= minval) {
				p3++;
			}
			while (v[p5] * 5 <= minval) {
				p5++;
			}
		}
		return v[n - 1];
	}

	int min3val(int i, int j, int k) {
		int min = i < j ? i : j;
		min = min < k ? min : k;
		return min;
	}

	//35 第一个只出现一次的字符(利用哈希表即可)
	char Firstap1(string s) {
		int len = s.size();
		unordered_map<char, int> m;
		if (len <= 0) {
			return NULL;
		}
		for (int i = 0; i < len; i++) {
			m[s[i]]++;
		}
		for (int i = 0; i < len; i++) {
			if (m[s[i]] == 1) {
				return s[i];
			}
		}
	}

	//36 数组的逆序对
	int sznxd(vector<int> v)
	{
		int len = v.size();
		int cnt = 0;
		sznxdc(v, 0, len - 1,cnt);

	}
	void sznxdc(vector<int>& v, int l, int r,int& cnt) {
		if (l < r) {
			int mid = (l + r) / 2;
			sznxdc(v, l, mid, cnt);
			sznxdc(v, mid + 1, r, cnt);
			merges(v, l, mid, r, cnt);
		}
	}
	void merges(vector<int>& v, int l, int mid, int r,int& cnt) {
		int i = l;
		int j = mid+1;
		vector<int> tmp;
		while (i <=mid && j<=r) {
			if (v[i] > v[j]) {
				tmp.push_back(v[j]);
				j++;
				cnt += j - mid;
			}
			else {
				tmp.push_back(v[i]);
				i++;
			}
		}
		while (i <= mid) {
			tmp.push_back(v[i]);
			i++;
		}

		while (j <= r) {
			tmp.push_back(v[j]);
			j++;
		}
		int k = 0;
		for (int i = l; i <= r; i++) {
			v[i] = tmp[k++];
		}
	}

	//37 两个链表的第一个公共节点(利用栈或者链表的性质)
	ListNode* firstcommonnode(ListNode* h1, ListNode* h2)
	{
		if (h1 == nullptr || h2 == nullptr) {
			return nullptr;
		}
		int len1 = 0;
		int len2 = 0;
		ListNode* h1p = h1;
		ListNode* h2p = h2;
		while (h1p) {
			len1++;
			h1p = h1p->next;
		}
		while (h2p) {
			len2++;
			h2p = h2p->next;
		}

		h1p = h1;
		h2p = h2;

		if (len1>=len2) {
			int dis = len1 - len2;
			while (dis) {
				h1p = h1p->next;
				dis--;
			}
			while (h1p != h2p) {
				h1p = h1p->next;
				h2p = h2p->next;
			}
			return h1p;
		}
		else {
			int dis = len2 - len1;
			while (dis) {
				h2p = h2p->next;
				dis--;
			}
			while (h1p != h2p) {
				h1p = h1p->next;
				h2p = h2p->next;
			}
			return h1p;
		}
	}

	//38 数字在排序数组中出现的次数
	int GetFirstk(vector<int> v, int k,int len) {
		int begine = 0;
		int end = len - 1;
		int mid = 0;
		while (begine <= end) {
			mid = (begine + end) / 2;
			//值相等且找到了
			if ((v[mid]==k)&&(mid==0||(mid>0&&v[mid-1]!=k))) {
				return mid;
			}
			//值相等但不是第一个
			if (v[mid] == k) {
				end = mid - 1;
				continue;
			}
			if (v[mid] > k) {
				end = mid - 1;
			}
			if (v[mid] < k) {
				begine = mid + 1;
			}
		}
		return -1;
	}
	int GetLastk(vector<int> v, int k,int len) {
		int begine = 0;
		int end = len - 1;
		int mid = 0;
		while (begine <= end) {
			mid = (begine + end) / 2;
			//值相等且找到了
			if ((v[mid] == k) && (mid == len-1 || (mid<len-1 && v[mid + 1] != k))) {
				return mid;
			}
			//值相等但不是第一个
			if (v[mid] == k) {
				begine = mid + 1;
				continue;
			}
			if (v[mid] > k) {
				end = mid - 1;
			}
			if (v[mid] < k) {
				begine = mid + 1;
			}
		}
		return -1;
	}
	int countk(vector<int> v, int k) {
		int len = v.size();
		if (len == 0) {
			return -1;
		}
		int l = 0;
		int r = len - 1;
		int begine = GetFirstk(v, k,len);
		int end = GetLastk(v, k,len);
		if (begine == -1) {
			return -1;
		}
		return end - begine + 1;
	}

	//39 二叉树的深度
	int depthofbt(TreeNode* root) {
		if (root == 0) {
			return 0;
		}

		int leftd = depthofbt(root->left);
		int rightd = depthofbt(root->right);

		return (leftd > rightd ? leftd : rightd) + 1;
	}

	//40 数组中只出现一次的数字(利用异或性质，然后分组求解)
	int cxyc(vector<int> v,int& num1,int& num2) {
		int len = v.size();
		int res = 0;
		for (int i = 0; i < len; i++) {
			res ^= v[i];
		}
		unsigned int fg = 1;
		for (int i = 0; i < 32; i++) {
			if ((fg&res) != 0) {
				break;
			}
			else
			{
				fg <<= 1;
			}
		}
		vector<int> g1;
		vector<int> g2;

		for (int i = 0; i < len; i++) {
			if (v[i] & fg) {
				g1.push_back(v[i]);
			}
			else {
				g2.push_back(v[i]);
			}
		}
		int leng1 = g1.size();
		int leng2 = g2.size();
		num1 = 0;
		num2 = 0;
		for (int i = 0; i < leng1; i++) {
			num1 ^= v[i];
		}
		for (int i = 0; i < leng2; i++) {
			num2 ^= v[i];
		}
	}

	//41 和为s的两个数字VS和为s的连续正数序列
	bool findsumblx(vector<int> v, int sum,int& num1,int& num2) {
		int len = v.size();
		if (len <= 1) {
			return false;
		}
		int l = 0;
		int r = len - 1;
		while (l < r) {
			if (v[l] + v[r] == sum) {
				num1 = v[l];
				num2 = v[r];
				return true;
			}
			if (v[l] + v[r] > sum) {
				r--;
			}
			else {
				l++;
			}
		}
		return false;
	}
	void findlxseq(int sum) {
		vector<deque<int>>  res;
		int l = 1, r = 2;
		int s = l + r;
		deque<int> tmp;
		tmp.push_back(1);
		tmp.push_back(2);
		if (sum < 3) {
			return;
		}
		if (sum == 3) {
			res.push_back(tmp);
		}
		
		while (r < (sum + 1) / 2) {
			if (s == sum) {
				res.push_back(tmp);
				s -= tmp.front();
				tmp.pop_front();
				l++;
			}
			if (s < sum) {
				r++;
				s += r;
				tmp.push_back(r);			
			}
			if (s > sum) {
				l++;
				s -= tmp.front();
				tmp.pop_front();
			}
		}
	}

	//42 反转单词顺序VS左旋转字符串
	void fzdc(string& s) {
		int len = s.size();
		if (len <= 0) {
			return;
		}
		reverse(s.begin(), s.end());
		auto l = s.begin();
		for (auto i = s.begin(); i < s.end();i++) {
			if (*i == ' '||(i+1)==s.end()) {
				reverse(l, i);
				auto tmp = i;
				++tmp;
				l = tmp;
			}
		}
	}

	void zxzfc(string& s, int num) {
		int len = s.size();
		string s1(s, 0, num);
		s.assign(s, num, len - num);
		s = s + s1;
	}

	//43 n个骰子的点数
	void printnsz(int n) {
		map<int, int> m;
		int sum = 0;
		printcore(m, 0, n, sum);

		for_each(m.begin(), m.end(), [](pair<int, int> p) {cout << p.first << ": " << p.second << endl; });
	}

	void printcore(map<int,int>& m,int index,int n,int& sum)
	{
		if (index == n) {
			m[sum]++;
			return;
		}
		for (int i = 1; i <= 6; i++) {
			sum += i;
			printcore(m, index + 1, n, sum);
			sum -= i;
		}
	}

	//44 扑克牌的顺子
	bool issz(vector<int> v) {
		int len = v.size();
		if (len == 0) {
			return false;
		}
		int numof0 = 0;
		int vacant = 0;
		for (auto i : v) {
			if (i == 0) {
				numof0++;
			}
		}
		for (int i = numof0; i < len; i++) {
			if (i != 0) {
				if (v[i] == v[i - 1]) {
					return false;
				}
			}
			if (i > numof0) {
				vacant += v[i] - v[i - 1]-1;
			}
		}
		return numof0 > vacant ? true : false;
	}

	//45 圆圈中最后剩下的数字
	int sxsz(int n, int m) {
		if (n < 1 || m < 1) {
			return -1;
		}
		list<int> l;
		for (int i = 0; i < n; i++) {
			l.push_back(i);
		}
		auto head = l.begin();
		auto tail = l.end();
		auto cur = head;
		while (true) {
			if (l.size() == 1) {
				return *cur;
			}
			for (int i = 1; i < m; i++) {
				cur++;
			}
			if (cur == tail) {
				cur = head;
			}
			auto tmp = cur;
			tmp++;
			auto next = tmp;
			if (next == tail) {
				next = head;
			}
			cur = next;
		}
	}

	//46 求1+2+。。。+n
	class tmpcl {
	public:
		tmpcl() { cnt++; sum += cnt; }
		static int getres() {
			return sum;
		}

	private:
		static int cnt;
		static int sum;
	};

	//47 不用加减乘除做加法
	int byjjch(int num1, int num2) {
		int sum = 0;
		int carry = 0;
		do {
			sum = num1^num2;//不进位部分
			carry = num1&num2;//进位部分
			num1 = sum;
			num2 = carry;
		} while (num2 != 0);
		return sum;
	}

	//48 不能被继承的类(1 私有化构造函数（不能在栈上创建），利用单例模式  2 利用虚拟继承)
	class bnjc {
	public:
		static bnjc* getinstance() {
			p = new bnjc;
			return p;
		}
	private:
		bnjc(){}
		~bnjc(){}
		static bnjc* p;
	};

	//49 把字符串转换成整数(注意细节处理)
	int str2int(string s) {
		long long res=0;
		int len = s.size();
		if (len == 0) {
			return -1;
		}
		if (s[0] == '+') {
			if (len == 1) {
				return -1;
			}
			for (int i = 1; i < len; i++) {
				if (s[i]<'0' || s[0]>'9') {
					return -1;
				}
				res = res * 10 + (s[i] - '0');
			}
			if (res > INT_MAX) {
				return -1;
			}
		}
		else if(s[0]=='-'){
			if (len == 1) {
				return -1;
			}
			for (int i = 1; i < len; i++) {
				if (s[i]<'0' || s[0]>'9') {
					return -1;
				}
				res = res * 10 + (s[i] - '0');
			}
			if (-res < INT_MIN) {
				return -1;
			}
		}
		else if (s[0] >= '0'||s[0] <= '9') {
			for (int i = 0; i < len; i++) {
				if (s[i]<'0' || s[i]>'9') {
					return -1;
				}
				res = res * 10 + (s[i] - '0');
			}
			if (res > INT_MAX) {
				return -1;
			}
		}
		else {
			return -1;
		}
		return (int)res;
	}

	//50 树中两个节点的最低公共祖先(1. 二叉搜索树只需要找值居中的点（从上往下） 2. 有指向父节点的转化为求两个链表的第一个公共节点 3 普通二叉树)
	TreeNode* getcommonroot(TreeNode* root, TreeNode* node1, TreeNode* node2) {
		if (root == nullptr || node1 == nullptr || node2 == nullptr) {
			return nullptr;
		}
		if (root->val >= node1->val&&root->val >= node2->val) {
			return getcommonroot(root->left, node1, node2);
		}
		if (root->val <= node1->val&&root->val <= node2->val) {
			return getcommonroot(root->right, node1, node2);
		}
		return root;
	}

	TreeNode* getcommonnode(TreeNode* node1, TreeNode* node2) {

	}
	void GetPath(TreeNode* root, TreeNode* node, list<TreeNode*>& path,bool& found) {
		if (root == nullptr) {
			return;
		}
		if (found == true) {
			return;
		}
		if (root == node) {
			path.push_back(root);
			found = true;
			return;
		}
		//左子树找
		if (root->left) {
			path.push_back(root);
			GetPath(root->left, node, path, found);
			if (found == false) {
				path.pop_back();
			}
			else {
				return;
			}
		}
		//右子树找
		if (root->right) {
			path.push_back(root);
			GetPath(root->right, node, path, found);
			if (found == false) {
				path.pop_back();
			}
			else {
				return;
			}
		}
		//到达叶节点
		if (!root->left && !root->right) {
			return;
		}
	}

	TreeNode* getlastcommon(list<TreeNode*>& path1, list<TreeNode*>& path2) {

	}
	//第二版新增题目
	//1 数组中重复的数字(时间复杂度为n，空间复杂度为1，通过交换法)
	bool cfsz(vector<int> v) {
		int len = v.size();
		if (len == 0||len==1) {
			return false;
		}
		for (int i = 0; i < len; i++) {
			if (v[i] == i) {
				continue;
			}
			else {
				if (v[v[i]] == v[i]) {
					cout << "找到一个重复数字" << v[i] << endl;
					return true;
				}
				else {
					swap(v[i], v[v[i]]);
					i--;
				}
			}
		}
		cout << "没有重复数字" << endl;
		return false;
	}

	//2 二叉树的下一个节点（分情况讨论，左右父，或者通过递归）
	TreeNode* Btnext(TreeNode* root,TreeNode* node) {
		if (root == nullptr) {
			return nullptr;
		}
		TreeNode* next = nullptr;
		bool flag = false;
		bool found = false;
		Btnextc(root, flag, node, next,found);
	}

	void Btnextc(TreeNode* root, bool& flag, TreeNode* node,TreeNode*& next,bool& found) {
		if (found == true) {
			return;
		}
		if (root->left) {
			Btnextc(root->left, flag, node, next,found);
		}
		if (flag == true) {
			next = root;
			found = true;
		}
		if (root == node&&flag==false) {
			flag = true;
		}
		if (root->right) {
			Btnextc(root->right, flag, node, next,found);
		}

	}

	// 3. 矩阵中的路径（回溯,图算法需要记录是否被访问过）
	bool haspath(vector<vector<char>> v, string s) {
		int rows = v.size();
		if (rows == 0) {
			return false;
		}
		int cols = v[0].size();
		if (cols == 0) {
			return false;
		}
		int len = s.size();
		if (len == 0) {
			return true;
		}
		vector<vector<bool>> visted(rows, vector<bool>(cols, false));
		bool res = false;
		//不同点作为起点
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				res = res || haspathc(v, 0,rows,cols, i, j, s, visted,len);
			}
		}
		return res;
	}

	bool haspathc(vector<vector<char>> v, int index, int rows, int cols,int row,int col,string s,vector<vector<bool>>& visited,int len) {
		if (row < 0 || row >= rows || col < 0 || col >= cols) {
			return false;
		}
		bool found = false;
		//被访问过
		if (visited[row][col] == true) {
			return false;
		}
		else {
			visited[row][col] = true;
			//到达最后一个位置
			if (index == len - 1) {
				if (v[row][col] == s[index]) {
					found= true;
				}
				else {
					found=false;
				}
			}
			else {
				if (v[row][col] == s[index]) {
					found= haspathc(v, index + 1, rows, cols, row + 1, col, s, visited, len) ||
						haspathc(v, index + 1, rows, cols, row - 1, col, s, visited, len) ||
						haspathc(v, index + 1, rows, cols, row, col + 1, s, visited, len) ||
						haspathc(v, index + 1, rows, cols, row, col - 1, s, visited, len);
				}
				else {
					found= false;
				}
			}
		}
		visited[row][col] = false;
		return found;
	}

	//4. 机器人的运动范围(回溯)
	int robot(int m,int n,int k) {
		if (m <= 0 || n <= 0) {
			return 0;
		}
		int count = 0;
		vector<vector<bool>> v(m, vector<bool>(n, false));
		robotc(m, n, 0,0,k,v, count);
		return count;
	}

	void robotc(int rows, int cols,int row,int col, int k,vector<vector<bool>>& v,int& count) {
		if (row < 0 || row >= rows || col < 0 || col >= cols||v[row][col]) {
			return;
		}
		v[row][col] = true;
		if (check(row, col,k)) {
			count++;
			robotc(rows, cols, row + 1, col, k, v, count);
			robotc(rows, cols, row - 1, col, k, v, count);
			robotc(rows, cols, row, col + 1, k, v, count);
			robotc(rows, cols, row, col - 1, k, v, count);
		}
	}

	bool check(int m, int n, int k) {
		int sum = 0;
		while (m) {
			sum += m % 10;
			m /= 10;
		}
		while (n) {
			sum += n % 10;
			n /= 10;
		}
		if (sum > k) {
			return false;
		}
		else {
			return true;
		}
	}

	//5. 剪绳子(动态规划)
	int cutsz(int length) {
		if (length < 2) {
			return 0;
		}
		if (length == 2) {
			return 1;
		}
		vector<int> f(length+1,0);
		f[0] = 0;
		f[1] = 1;
		f[2] = 2;
		f[3] = 3;

		int max = 0;
		for (int i = 4; i <= length; i++) {
			for (int j = 1; j <= i / 2; j++) {
				if (f[j] * f[i - j] > max) {
					max = f[j] * f[i - j];
				}
			}
			if (i - 1 > max) {
				max = i - 1;
			}
			f[i] = max;
			max = 0;
		}
		return f[length];
	}

	//6. 正则表达式匹配（状态机，需要先匹配*再匹配.）
	bool match(string str, string strm)
	{
		int lens = str.size();
		int len2 = strm.size();
		return matchc(str, lens, 0, strm, len2, 0);
	}

	bool matchc(string str, int lens, int indexs, string strm, int lenm, int indexm) {
		bool match = false;
		if (indexs == lens&&indexm==lenm) {
			return true;
		}
		if (indexs == lens&&indexm != lenm) {
			return false;
		}
		if (indexs <= lens-1 && indexm >= lenm) {
			return false;
		}

		//匹配*
		if (indexm < lenm-1&&strm[indexm+1]=='*') {
			//若相等
			if (str[indexs] == strm[indexm]||strm[indexm]=='.') {
				match = match || matchc(str, lens, indexs, strm, lenm, indexm + 2) ||
					matchc(str, lens, indexs + 1, strm, lenm, indexm) ||
					matchc(str, lens, indexs + 1, strm, lenm, indexm + 2);
			}
			else {//不相等直接跳过
				match = match || matchc(str, lens, indexs, strm, lenm, indexm + 2);
			}
		}
		//匹配.或者一般的字符串
		if (str[indexs] == strm[indexm] || strm[indexm] == '.') {
			match =match|| matchc(str, lens, indexs + 1, strm, lenm, indexm + 1);
		}
		return match;
	}

	//7 表示数值的字符串（模式匹配 A.[B E|e C]）
	bool isNumeric(string s) {
		bool isanum = false;
		int len = s.size();
		if (len == 0) {
			return false;
		}
		int index = 0;
		isanum = isint(s, index, len);
		if (s[index] == '.') {
			index++;
			isanum = isanum && isUnsint(s, index, len);
		}
		if (s[index] == 'e' || s[index] == 'E') {
			index++;
			isanum = isanum && isint(s, index, len);
		}

		return isanum&&index == len;
	}

	bool isUnsint(string s, int& index,int len) {
		int beg = index;
		while (s[index] >= '0'&&s[index] <= '9'&&index<len) {
			index++;
		}
		return index > beg;
	}

	bool isint(string s, int& index, int len) {
		if (s[index] == '+' || s[index] == '-') {
			index++;
		}
		return isUnsint(s, index, len);
	}

	//8. 链表中环的入口地址(先通过快慢指针判断是否有环,再通过前后指针判断入口)
	ListNode* EntryOfLoop(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}
		ListNode* Meeting = MeetingNode(head);
		
		int len = 1;
		ListNode* tmp = Meeting->next;
		while (tmp != Meeting) {
			len++;
			tmp = tmp->next;
		}
		ListNode* front = head;
		ListNode* back = head;
		for (int i = 0; i < len; i++) {
			back = back->next;
		}
		while (front != back) {
			front = front->next;
			back = back->next;
		}
		return front;
	}

	ListNode* MeetingNode(ListNode* head) {
		ListNode* s = head;
		ListNode* q = head;
		if (s->next == nullptr) {
			return nullptr;
		}
		s = s->next;
		if (s->next == nullptr) {
			return nullptr;
		}
		q = s->next;
		while (true) {
			if (s->next == nullptr) {
				return nullptr;
			}
			s = s->next;
			if (q->next == nullptr) {
				return nullptr;
			}
			q = q->next;
			if (q->next == nullptr) {
				return nullptr;
			}
			q = s->next;
			if (q == s) {
				return q;
			}
		}
		return nullptr;
	}

	//9. 对称的二叉树（判断前序遍历和对称前序遍历是否相等即可）
	bool isSymme(TreeNode* root) {
		return isSymmec(root, root);
	}

	bool isSymmec(TreeNode* head1, TreeNode* head2) {
		if (head1 == nullptr&&head2 == nullptr) {
			return true;
		}
		if (head1 == nullptr || head2 == nullptr) {
			return false;
		}
		if (head1->val != head2->val) {
			return false;
		}
		return isSymmec(head1->left, head2->right) && isSymmec(head1->right, head2->left);
	}

	//10. 序列化和反序列化二叉树
	void serial(TreeNode* root, ostream& stream) {
		if (root == nullptr) {
			stream << "$,";
			return;
		}
		stream << root->val << ",";
		serial(root->left, stream);
		serial(root->right, stream);
	}

	void Deserial(TreeNode*& root, istream& stream) {
		char a;
		if (stream >> a) {
			if (a == '$') {
				return;
			}
			else {
				root = new TreeNode(a);
				Deserial(root->left, stream);
				Deserial(root->right, stream);
			}
		}
	}

	//11. 数据流中的中位数(利用堆，前半部分最大堆，后半部分最小堆)
	void insertnum(int num) {
		//当前总数目是偶数，插入最大堆（左边）
		if (!((maxheap.size() + minheap.size()) & 1)) {
			if (minheap.size() > 0 && num > minheap.top()) {
				minheap.push(num);
				num = minheap.top();
				minheap.pop();
			}
			maxheap.push(num);
		}//当前为奇数，插入最小堆（右边）
		else {
			if (maxheap.size() && num < maxheap.top()) {
				maxheap.push(num);
				num = maxheap.top();
				maxheap.pop();
			}
			minheap.push(num);
		}
	}

	int getmidnum() {
		int size = minheap.size() + maxheap.size();
		if (size == 0) {
			throw new exception("没有数据");
		}
		int midnum = 0;
		if (size & 1) {
			midnum = maxheap.top();
		}
		else {
			midnum = (maxheap.top() + minheap.top()) / 2;
		}
		return midnum;
	}

	//12. 数字序列中的某一位数字(分析数字的规律，一位一位的缩小范围)
	int digitatindex(int index) {
		if (index < 0) {
			return-1;
		}
		int digit = 1;
		while (true) {
			int numbers = countofint(digit);
			if (index < numbers*digit) {
				return digitAtindex(index, digit);
			}
			index -= digit*numbers;
			digit++;
		}
	}
	//digit位的数字的总数
	int countofint(int digit) {
		if (digit == 1) {
			return 10;
		}
		return 9 * pow(10, digit - 1);
	}

	int digitAtindex(int index, int digits) {
		int bn = begineNum(digits)+index/digits;
		int left = digits-index%digits;
		for (int i = 1; i < left; i++) {
			bn /= 10;
		}
		return bn % 10;
	}

	int begineNum(int digit) {
		if (digit == 1) {
			return 0;
		}
		return pow(10, digit - 1);
	}

	//13. 把数字翻译成字符串的种类（利用递归思想，从上往下分析，从下往上解答）
	int gettransnum(string s) {
		int len = s.size();
		if (len == 0) {
			return 0;
		}
		return gettranc(s, len);
	}

	int gettranc(string s, int len) {
		vector<int> f(len, 0);
		f[len - 1] = 1;
		if (len >= 2) {
			int tmp = (s[len - 1] - '0') + (s[len - 2] - '0') * 10;
			if (tmp >= 10 && tmp <= 25) {
				f[len - 2] = 2;
			}
			else {
				f[len - 2] = 1;
			}
		}
		for (int i = len - 3; i >= 0; --i) {
			int flag = false;
			int tmp = (s[i+1] - '0') + (s[i] - '0') * 10;
			if (tmp >= 10 && tmp <= 25) {
				f[i] = f[i + 1] + f[i + 2];
			}
			f[i] = f[i + 1];
		}
		return f[0];
	}

	//14. 礼物的最大价值(d动态规划，从上往下分析，从下往上解答，可以不用二维数组来保存动态规划结果)
	int maxgift(vector<vector<int>> v) {
		int rows = v.size();
		if (rows == 0) {
			return 0;
		}
		int cols = v[0].size();
		vector<vector<int>> maxgift(rows, vector<int>(cols, 0));
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (i > 0 && j > 0) {
					int tmp = maxgift[i - 1][j] > maxgift[i][j - 1] ? maxgift[i - 1][j] : maxgift[i][j - 1];
					maxgift[i][j] = maxgift[i - 1][j] + v[i][j];
				}
				else if (i > 0 && j == 0) {
					maxgift[i][j] = maxgift[i - 1][j];
				}
				else if (i == 0 && j > 0) {
					maxgift[i][j] = maxgift[i][j - 1];
				}
			}
		}
		return maxgift[rows - 1][cols- 1];
	}
	
	int maxgift2(vector<vector<int>> v) {
		int rows = v.size();
		if (rows == 0) {
			return 0;
		}
		int cols = v[0].size();
		vector<int> maxgift(cols, 0);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				int up = 0;
				int left = 0;
				if (i > 0) {
					up = maxgift[j];
				}
				if (j > 0) {
					left = maxgift[j - 1];
				}
				int tmp = up > left ? up : left;
				maxgift[j] = tmp + v[i][j];
			}
		}
		return maxgift[cols - 1];
	}

	//15. 最长不含重复字符的子字符串（分情况来讨论，动态规划）
	int longestnoagain(string s) {
		int len = s.size();
		if (len == 0) {
			return 0;
		}
		int maxlength = 0;
		int curlength = 0;
		vector<int> v(26, -1);
		for (int i = 0; i < len; i++) {
			int pre = v[s[i] - 'a'];
			//出现过
			if (pre < 0) {
				curlength++;
			}
			//没出现过
			if (pre > 0) {
				int dis = i - pre;
				if (dis > curlength) {
					curlength++;
				}
				else {
					if (maxlength < curlength) {
						maxlength = curlength;
					}
					curlength = dis;
				}
			}
			v[s[i] - 'a'] = i;
		}
		if (curlength > maxlength) {
			maxlength = curlength;
		}
		return maxlength;
	}

	//16 在排序数组中查找数字（即找出现次数，反正就是用二分法，复杂度为logn）
	int Getlosenum(vector<int> v) {
		int len = v.size();
		if (len == 0) {
			return -1;
		}
		int l = 0;
		int r = len - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (v[mid] == mid) {
				l = mid + 1;
			}
			else {
				if (mid == 0) {
					return 0;
				}
				else {
					if (v[mid - 1] == mid - 1) {
						return mid;
					}
					else {
						r = mid - 1;
					}
				}
			}
		}
		if (l == len) {
			return len;
		}
		return -1;
	}


	//17 二叉搜索树的第K大节点（中序遍历即可）
	TreeNode* maxkoftree(TreeNode* root, int k) {
		if (root == nullptr || k == 0) {
			return nullptr;
		}
		TreeNode* maxnode = nullptr;
		maxkoftreec(root, k,maxnode);
		return maxnode;
	}

	void maxkoftreec(TreeNode* root, int& k,TreeNode*& maxnode) {
		if (k != 0&&root->left) {
			maxkoftreec(root->left, k,maxnode);
		}
		k--;
		if (k == 0) {
			maxnode = root;
		}
		if (k!=0&&root->right) {
			maxkoftreec(root->right, k,maxnode);
		}
	}

	//19 队列的最大值（由滑动窗口的思路来解答）
	void push_back(int num) {
		while (maxq.size() && num > maxq.back().val) {
			maxq.pop_front();
		}
		maxq.push_back(qdata(num, curindexq));
		dataq.push_back(qdata(num, curindexq));
		curindexq++;
	}

	void pop_front() {
		if (dataq.size()) {
			if (dataq.front().index == maxq.front().index) {
				maxq.pop_front();
			}
			dataq.pop_front();
		}
		else {
			throw new exception("出错");
		}
	}

	int maxofqueue() {
		if (maxq.size()) {
			return maxq.front().val;
		}
		else {
			throw new exception("出错");
		}
	}

	//20 股票的最大利润
	int maxpro(vector<int> v) {
		int len = v.size();
		int maxpro = 0;
		int minval = v[0];
		int curpro;
		for (int i = 1; i < len; i++) {
			curpro = v[i] - minval;
			minval = minval < v[i] ? minval : v[i];
			maxpro = maxpro > curpro ? maxpro : curpro;
		}
		return maxpro;
	}

	//21 构建乘积数组
	void multiply(vector<int> a,vector<int>& b) {
		int len = a.size();
		if (len == 0) {
			return;
		}
		vector<int> c(len,0);
		vector<int> d(len, 0);
		c[0] = 1;
		d[len - 1] = 1;
		for (int i = 1; i < len; i++) {
			c[i] = c[i - 1] * a[i - 1];
		}
		for (int i = len - 2; i >= 0; i--) {
			d[i] = d[i + 1] * a[i + 1];
		}

		for (int i = 0; i < len; i++) {
			b[i] = c[i]*d[i];
		}
	}

	//22 剑指offer的快排方式（关键是partition函数的掌握）
	int RandomInRange(int start, int end) {
		srand(time(NULL));
		return start + rand() % (end - start+1);
	}

	int Partition(vector<int>& v, int len, int l, int r) {
		if (len == 0 || l < 0 || r >= len) {
			throw new exception("出错了");
		}
		int index = RandomInRange(l, r);
		swap(v[index], v[r]);
		int small = l - 1;
		for (int i = l; i < r; i++) {
			if (v[i] < v[r]) {
				small++;
				if (small != i) {
					swap(v[small], v[i]);
				}
			}
		}
		++small;
		swap(v[small], v[r]);
		return small;
	}

	void QuickSort(vector<int>& v, int len, int l, int r) {
		if (l == r) {
			return;
		}
		int index = Partition(v, len, l, r);
		if (index > l) {
			QuickSort(v, len, l, index - 1);
		}
		if (index < r) {
			QuickSort(v, len, index + 1, r);
		}
	}


private:
	
	char* tmp;
	static Solution* p;
	deque<qdata> dataq;
	deque<qdata> maxq;
	static int curindexq;
	stack<int> s1;
	stack<int> s2;
	stack<int> mins;
	priority_queue<int, vector<int>, greater<int>> minheap;
	priority_queue<int, vector<int>, less<int>> maxheap;

};

int Solution::curindexq = 0;

int Solution::tmpcl::cnt = 0;
int Solution::tmpcl::sum = 0;

int mainmb()
{

	Solution sol;
	
	TreeNode* root = new TreeNode(2);
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(3);

	root->left = node1;
	root->right = node2;

	cout << sol.maxkoftree(root, 2)->val << endl;


	
	system("pause");
	return EXIT_SUCCESS;
}