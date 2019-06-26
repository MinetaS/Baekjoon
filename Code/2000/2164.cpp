#include <cstdio>
#include <deque>

using namespace std;

int main() {
	int n;
	deque<int> q;

	scanf("%d", &n);
	q.resize(n);
	for (int i=0 ; i<n ; i++) q[i] = i+1;

	while (n != 1) {
		q.pop_front();
		int r = q.front();
		q.pop_front();
		q.push_back(r);
		n--;
	}

	printf("%d", q.back());

	return 0;
}