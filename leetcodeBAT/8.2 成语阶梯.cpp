#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<list>
#include<map>
#include<math.h>
#include "zx.h"

using namespace std;


class Solution2 {
public:
	bool connect(string s1, string s2) {
		int len = s1.size();
		int cnt = 0;
		for (int i = 0; i < len; i++) {
			if (s1[i] != s2[i]) {
				cnt++;
				if (cnt > 1) {
					return false;
				}
			}
		}
		return cnt == 1;
	}
	void creategrapth(string beg,vector<string> wordList,map<string,vector<string>>& m) {
		wordList.push_back(beg);
		int len = wordList.size();
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if (connect(wordList[i], wordList[j])) {
					m[wordList[i]].push_back(wordList[j]);
					m[wordList[j]].push_back(wordList[i]);
				}
			}
		}
	}

	int BFS_gra(string beginWord, string endWord, map<string, vector<string>> m) {
		set<string> visited;
		queue<pair<string, int>> q;
		q.push(make_pair(beginWord, 1));
		while (q.size()) {
			pair<string, int> tmp = q.front();
			q.pop();
			if (tmp.first == endWord) {
				return tmp.second;
			}
			int len = m[tmp.first].size();
			for (int i = 0; i < len; i++) {
				if (visited.find(m[tmp.first][i]) == visited.end()) {
					visited.insert(m[tmp.first][i]);
					q.push(make_pair(m[tmp.first][i], tmp.second + 1));
				}
			}
		}
		return 0;
	}

	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		map<string, vector<string>> m;
		creategrapth(beginWord, wordList, m);
		return BFS_gra(beginWord, endWord, m);
	}
};

struct Qitem {
	string node;
	int pre;
	int step;
	Qitem(string node,int pre,int step):node(node),pre(pre),step(step){}
};

class Solution {
public:
	bool connect(string s1, string s2) {
		int len = s1.size();
		int cnt = 0;
		for (int i = 0; i < len; i++) {
			if (s1[i] != s2[i]) {
				cnt++;
				if (cnt > 1) {
					return false;
				}
			}
		}
		return cnt == 1;
	}
	void creategraph(string beg, vector<string> wordList, map<string, vector<string>>& m)
	{
		if (find(wordList.begin(), wordList.end(), beg)==wordList.end()) {
			wordList.push_back(beg);
		}
		int len = wordList.size();
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if (connect(wordList[i], wordList[j])) {
					m[wordList[i]].push_back(wordList[j]);
					m[wordList[j]].push_back(wordList[i]);
				}
			}
		}
	}

	void BFT_gra(string beginWord, string endWord, map<string, vector<string>> m,vector<Qitem>& Q,vector<int>& end_word) {
		map<string, int> visit;
		int min_step = 0;
		Q.push_back(Qitem(beginWord, -1, 1));
		visit[beginWord] = 1;
		int front = 0;
		while (front != Q.size()) {
			string node = Q[front].node;
			int step = Q[front].step;
			if (min_step != 0 && step > min_step) {
				break;
			}
			if (node == endWord) {
				min_step = step;
				end_word.push_back(front);
			}
			vector<string> neightb = m[node];
			int lenn = neightb.size();
			for (int i = 0; i < lenn; i++) {
				if (visit.find(neightb[i]) == visit.end()|| visit[neightb[i]]==step+1) {
					Q.push_back(Qitem(neightb[i], front, step + 1));
					visit[neightb[i]] = step + 1;
				}
			}
			front++;
		}
	}

	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		map<string, vector<string>> m;
		creategraph(beginWord, wordList, m);
		vector<Qitem> Q;
		vector<int> end_word;
		BFT_gra(beginWord, endWord, m, Q, end_word);
		vector<vector<string>> result;
		int lene = end_word.size();
		for (int i = 0; i < lene; i++) {
			vector<string> res;
			int pos = end_word[i];
			while (pos != -1) {
				res.push_back(Q[pos].node);
				pos = Q[pos].pre;
			}
			reverse(res.begin(), res.end());
			result.push_back(res);
		}
		return result;
	}
};

int main()
{
	Solution s;
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };

	vector<vector<string>> res = s.findLadders(beginWord, endWord, wordList);
		
	system("pause");
	return 0;
}

