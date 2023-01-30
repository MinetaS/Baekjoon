#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>

#define INF 2147483647

using namespace std;

class BipartiteGraph {
private:
	int _Size_Left;
	int _Size_Right;
	vector<vector<int>> _Adjacent;

	// Hopcroft-Karp Matching Algorithm Elements
	void _HopcroftKarpMatch_SetLevel();
	bool _HopcroftKarpMatch_AddAugmentPath(int);
	vector<int> _HK_Level;
	vector<int> _HK_Match_Left;
	vector<int> _HK_Match_Right;

public:
	BipartiteGraph();
	BipartiteGraph(int _Size_Left, int _Size_Right);

	void AddEdge(int _Left, int _Right);

	int HopcroftKarpMatch();
};

BipartiteGraph::BipartiteGraph() {
	_Size_Left = 0;
	_Size_Right = 0;
	_Adjacent = vector<vector<int>>();
}

BipartiteGraph::BipartiteGraph(int _Size_Left, int _Size_Right) {
	this->_Size_Left = _Size_Left;
	this->_Size_Right = _Size_Right;
	_Adjacent = vector<vector<int>>(_Size_Left);
}

void BipartiteGraph::AddEdge(int _Left, int _Right) {
	if (_Left > _Size_Left) return;
	if (_Right > _Size_Right) return;

	_Adjacent[_Left].push_back(_Right);
}

int BipartiteGraph::HopcroftKarpMatch() {
	_HK_Level = vector<int>(_Size_Left, -1);
	_HK_Match_Left = vector<int>(_Size_Left, -1);
	_HK_Match_Right = vector<int>(_Size_Right, -1);

	int match = 0;

	while (true) {
		_HopcroftKarpMatch_SetLevel();

		int augment = 0;

		for (int i=0 ; i<_Size_Left ; i++)
			if (_HK_Match_Left[i]==-1 && _HopcroftKarpMatch_AddAugmentPath(i)) augment++;

		if (augment == 0) break;

		match += augment;
	}

	return match;
}

void BipartiteGraph::_HopcroftKarpMatch_SetLevel() {
	deque<int> q;

	for (int i=0 ; i<_Size_Left ; i++) {
		if (_HK_Match_Left[i] == -1) {
			_HK_Level[i] = 0;
			q.push_back(i);
		}

		else _HK_Level[i] = INF;
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop_front();

		for (int next : _Adjacent[now]) {
			int update = _HK_Match_Right[next];

			if (update!=-1 && _HK_Level[update]==INF) {
				_HK_Level[update] = _HK_Level[now]+1;
				q.push_back(update);
			}
		}
	}
}

bool BipartiteGraph::_HopcroftKarpMatch_AddAugmentPath(int _Node) {
	for (int next : _Adjacent[_Node]) {
		int update = _HK_Match_Right[next];

		if (update==-1 || (_HK_Level[update]==_HK_Level[_Node]+1 && _HopcroftKarpMatch_AddAugmentPath(update))) {
			_HK_Match_Left[_Node] = next;
			_HK_Match_Right[next] = _Node;

			return true;
		}
	}

	return false;
}


int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	BipartiteGraph graph(n, m);

	for (int p, i=0 ; i<n ; i++) {
		scanf("%d", &p);

		for (int t, j=0 ; j<p ; j++) {
			scanf("%d", &t);
			graph.AddEdge(i, t-1);
		}
	}

	printf("%d", graph.HopcroftKarpMatch());

	return 0;
}