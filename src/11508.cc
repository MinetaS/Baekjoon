#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	int n;
	int *cost;
	long long sum = 0;

	scanf("%d", &n);
	cost = new int[n];
	for (int i=0 ; i<n ; i++) scanf("%d", cost+i);

	sort(cost, cost+n, greater<int>());

	for (int t=0, i=0 ; i<n ; i++)
		if (i%3 != 2) sum += cost[i];

	printf("%lld", sum);

	delete[] cost;

	return 0;
}