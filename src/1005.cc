#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Building {
	vector<int> pre_req;
};

int search(int);

int cache[1001];
int time[1001];
vector<Building> graph;

int main() {
	int _case;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;
		
		int buildings, rules;
		int target;

		memset(cache, -1, sizeof(cache));
		scanf("%d %d", &buildings, &rules);

		graph = vector<Building>(buildings+1, Building());

		for (int i=1 ; i<=buildings ; i++)
			scanf("%d", time+i);

		for (int i=0 ; i<rules ; i++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			graph[t2].pre_req.push_back(t1);
		}

		scanf("%d", &target);

		printf("%d\n", search(target));
	}

	return 0;
}

int search(int n) {
	if (cache[n] != -1) return cache[n];

	int result = 0;

	for (int &pre : graph[n].pre_req)
		result = max(search(pre), result);

	return cache[n] = time[n]+result;
}