#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<stack>

using namespace std;


//利用坐标轴投影的思想以及递归、STL排序算法

struct Bnode {
	int data;
	Bnode* left;
	Bnode* right;
};


bool func(pair<int, pair<int, int>> num1, pair<int, pair<int, int>> num2)
{
	if (num1.second.first != num2.second.first) {
		return num1.second.first < num2.second.first;
	}
	else {
		return num1.second.second > num2.second.second;
	}
}



void getzuobiao(Bnode* root,vector<int>& v,int width,int depth)
{
	if (root == nullptr) {
		return;
	}
	v.push_back(root->data);
	v.push_back(width);
	v.push_back(depth);
	if (root->left) {
		getzuobiao(root->left,v,width-1,depth-1);
	}
	if (root->right) {
		getzuobiao(root->right,v, width + 1, depth - 1);
	}
}




void fushi(Bnode* root) {
	vector<int>   v;
	getzuobiao(root, v, 0, 0);

	for (auto e : v) {
		cout << e << " ";
	}
	cout << endl;

	int len = v.size();
	cout << len << endl;


	vector<pair<int, pair<int, int>>> vt;

	for (int i = 0; i < len-2; i += 3) {
		vt.push_back(make_pair(v[i], make_pair(v[i + 1], v[i + 2])));
	}
	for (auto el : vt) {
		cout << el.first << ":(" << el.second.first << "," << el.second.second << ")" << endl;
	}
	cout << "----------------" << endl;
	sort(vt.begin(), vt.end(), func);
	for (auto el : vt) {
		cout << el.first << ":(" << el.second.first << "," << el.second.second << ")" << endl;
	}

	len = vt.size();
	for (int i = 0; i < len; i++) {
		if (i == 0) {
			cout << vt[i].first << " ";
			continue;
		}
		if (vt[i].second.first == vt[i - 1].second.first) {
			continue;
		}
		cout << vt[i].first << " ";
	}
	cout << endl;
}




int main11()
{
	Bnode root = { 0,nullptr,nullptr };
	Bnode nodeA = { 1,nullptr,nullptr };
	Bnode nodeB = { 2,nullptr,nullptr };
	Bnode nodeC = { 3,nullptr,nullptr };
	Bnode nodeD = { 4,nullptr,nullptr };
	Bnode nodeE = { 5,nullptr,nullptr };
	Bnode nodeF = { 6,nullptr,nullptr };
	Bnode nodeG = { 7,nullptr,nullptr };
	Bnode nodeH = { 8,nullptr,nullptr };

	root = { 0,&nodeA,&nodeB };
	nodeA = { 1,&nodeC,nullptr };
	nodeB = { 2,&nodeD, &nodeE };
	nodeC = { 3,&nodeF,&nodeG };
	nodeD = { 4,nullptr,nullptr };
	nodeE = { 5,&nodeH,nullptr };
	nodeF = { 6,nullptr,nullptr };
	nodeG = { 7,nullptr,nullptr };
	nodeH = { 8,nullptr,nullptr };

	fushi(&root);
	system("pause");
	return 0;
}