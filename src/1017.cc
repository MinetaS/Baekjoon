#define _FUNC_DEF_BEGIN_
#define _FUNC_DEF_END_

#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num1;   // Odd Number Set
vector<int> num2;   // Even Number Set
vector<int> edge[25];
int match[25];

unsigned int visited;

_FUNC_DEF_BEGIN_
	bool is_prime(int);
	bool deep_search(int);
_FUNC_DEF_END_

int main() {
	int N;
	bool _first;

	// Input
	scanf("%d", &N);

	for (int i=0 ; i<N ; i++) {
		int num;
		scanf("%d", &num);

		((num%2) ? num1 : num2).push_back(num);
		if (i == 0) _first = num%2;
	}

	if (num1.size() != num2.size()) {
		printf("-1");
		return 0;
	}

	// Initalize Edge Connection
	if (!_first) swap(num1, num2);

	const int set_size = N/2;

	for (int i=0 ; i<set_size ; i++) {
		for (int j=0 ; j<set_size ; j++) {
			if (is_prime(num1[i]+num2[j])) {
				edge[i].push_back(j);
			}
		}
	}

	vector<int> result;

	// Bipartite Matching
	for (int i=0 ; i<edge[0].size() ; i++) {
		int first_connect = edge[0][i];
		int match_count = 1;

		memset(match, -1, sizeof(match));
		match[first_connect] = 0;

		for (int j=1 ; j<set_size ; j++) {
			visited = 1;
			if (deep_search(j)) match_count++;
		}

		if (match_count == set_size) result.push_back(num2[first_connect]);
	}

	// Output
	if (result.size() == 0) {
		printf("-1");
		return 0;
	}

	sort(result.begin(), result.end());

	for (int i=0 ; i<result.size() ; i++)
		printf("%d ", result[i]);

	return 0;
}

bool is_prime(int n) {
	if (n < 2) return false;
	if (n == 2) return true;

	for (int t=2 ; t<=(int)sqrt((double)n) ; t++)
		if (n%t == 0) return false;

	return true;
}

bool deep_search(int current_node) {
	if ((visited & 1u<<current_node) != 0) return false;

	visited |= 1u << current_node;

	for (size_t i=0 ; i<edge[current_node].size() ; i++) {
		int next_node = edge[current_node][i];

		if (match[next_node]==-1 || deep_search(match[next_node])) {
			match[next_node] = current_node;
			return true;
		}
	}

	return false;
}