#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<stack>

using namespace std;


struct Bnode {
	int data;
	Bnode* left;
	Bnode* right;
};



void pre_order_digui(Bnode* root)
{
	if (root == nullptr) {
		return;
	}

	cout << root->data<<" ";
	pre_order_digui(root->left);
	pre_order_digui(root->right);
}


typedef struct Info {
	Bnode* node;
	bool flag ;
}info;

void pre_order_feidigui(Bnode* root)
{
	if (root == nullptr) {
		return;
	}

	stack<info> s;
	info rf ={root,false};
	s.push(rf);

	while (s.size()) {
		info tmp = s.top();
		s.pop();

		if (tmp.flag == true) {
			cout << tmp.node->data << " ";
		}
		else {
			if (tmp.node->right) {
				s.push({ tmp.node->right,false });
			}
			if (tmp.node->left) {
				s.push({ tmp.node->left,false });
			}
			s.push({ tmp.node,true });
		}
	}

}

int main10()
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

	pre_order_digui(&root);
	cout << endl;

	pre_order_feidigui(&root);
	cout << endl;

	system("pause");
	return 0;
}








