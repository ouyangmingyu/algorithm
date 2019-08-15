#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<functional>
#include<queue>
#include<queue>
#include<stack>
#include<set>
#include<list>
#include "zx.h"

using namespace std;


struct GraphNode {
	int label;
	vector<GraphNode*> neightbors;
	GraphNode(int x) :label(x) {};
};

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<GraphNode* > G;
		visit = vector<int>(numCourses, -1);
		for (int i = 0; i < numCourses; i++) {
			G.push_back(new GraphNode(i));
		}
		for (int i = 0; i < prerequisites.size(); i++) {
			GraphNode* begin = G[prerequisites[i][1]];
			GraphNode* end = G[prerequisites[i][0]];
			begin->neightbors.push_back(end);
		}
		for (int i = 0; i < G.size(); i++) {
			if (visit[i] == -1) {
				if (DFS(G[i]) == false) {
					return false;
				}
			}
		}
		return true;
	}

	bool DFS(GraphNode* node) {
		visit[node->label] = 0;
		for (int i = 0; i < node->neightbors.size(); i++) {
			if (visit[node->neightbors[i]->label] == -1) {
				if (DFS(node->neightbors[i]) == false) {
					return false;
				}
			}
			if (visit[node->neightbors[i]->label] == 0) {
				return false;
			}
		}
		visit[node->label] = 1;
		return true;
	}

private:
	vector<int> visit;
};