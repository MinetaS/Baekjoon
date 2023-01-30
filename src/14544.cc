#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

template<template<typename> class P = less>
struct compare_pair_second {
	template<class T1, class T2> bool operator()(const pair<T1, T2>&left, const pair<T1, T2>&right) {
		return P<T2>()(left.second, right.second);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _case;
	int _case_cnt = 0;

	cin >> _case;

	while (_case_cnt < _case) {
		_case_cnt++;

		int n, m;
		map<string, int> votes;

		cin >> n >> m;

		for (int i=0 ; i<n ; i++) {
			string s;
			cin >> s;
			votes[s] = 0;
		}

		for (int i=0 ; i<m ; i++) {
			string s, t;
			int v;

			cin >> s >> v >> t;
			votes[s] += v;
		}

		vector<pair<string, int>> sort_vector;

		for (auto it = votes.begin() ; it!=votes.end() ; it++)
			sort_vector.emplace_back(make_pair(it->first, it->second));

		sort(sort_vector.begin(), sort_vector.end(), compare_pair_second<greater>());

		if (votes.size() == 1) cout << votes.begin()->first << '\n';
		else {
			int first = sort_vector[0].second;
			int second = sort_vector[1].second;

			if (first == second) cout << "VOTE " << _case_cnt << ": THERE IS A DILEMMA" << '\n';
			else cout << "VOTE " << _case_cnt << ": THE WINNER IS " << sort_vector[0].first << " " << first << '\n';
		}
	}

	return 0;
}