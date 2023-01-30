#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Problem {
	int index;
	int score;
};

bool compare(Problem &, Problem &);

int main() {
	vector<Problem> problemset;
	vector<int> top;
	int sum = 0;

	for (int i=0 ; i<8 ; i++) {
		int s;

		scanf("%d", &s);
		problemset.push_back({i+1, s});
	}

	sort(problemset.begin(), problemset.end(), compare);

	for (int i=0 ; i<5 ; i++) {
		top.push_back(problemset[i].index);
		sum += problemset[i].score;
	}

	sort(top.begin(), top.end());

	printf("%d\n", sum);

	for (int &e : top)
		printf("%d ", e);

	return 0;
}

bool compare(Problem &arg0, Problem &arg1) {
	if (arg0.score > arg1.score) return true;
	else return false;
}