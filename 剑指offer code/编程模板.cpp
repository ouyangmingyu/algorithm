#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include "time.h"


using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
            val(x), next(NULL) {
      }
};


 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };




struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};




class Solution {

public:
	int searchInsert(int A[], int n, int target) {
		if (n == 0) {
			return 0;
		}
		int left = 0;
		int right = n - 1;
		
		while (left <= right) {
			int mid = (left + right) / 2;
			if (A[mid] == target) {
				return mid;
			}
			if (A[mid] > target) {
				right = mid - 1;
			}
			if (A[mid] < target) {
				left = mid + 1;
			}
		}
		return left ;
	}
};


class A;


int main()
{

	Solution sol;
	int A[4] = { 1,3,5,6 };
	
	cout << sol.searchInsert(A, 4, 2) << endl;
	
	system("pause");
	return EXIT_SUCCESS;
}