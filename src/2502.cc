#include <cstdio>
#include <cstring>
struct Pair {
	int first;
	int second;
};

Pair calculate(int);

Pair cache[30];

int main() {
	int d, k;

	scanf("%d %d", &d, &k);
	memset(cache, 0, sizeof(cache));

	Pair r = calculate(d);

	for (int i=1 ; i*r.first<=k ; i++) {
		if (i*r.first == k) break;
		if ((k-i*r.first)%r.second == 0) {
			printf("%d\n%d", i, (k-i*r.first)/r.second);
			break;
		}
	}

	return 0;
}

Pair calculate(int n) {
	if (n == 1) return {1, 0};
	if (n == 2) return {0, 1};

	Pair &ret = cache[n];
	if (ret.first+ret.second != 0) return ret;

	Pair prev1 = calculate(n-1);
	Pair prev2 = calculate(n-2);

	ret.first = prev1.first+prev2.first;
	ret.second = prev1.second+prev2.second;

	return ret;
}