#include <cstdio>
#include <algorithm>

int main() {
	long long a, b;

	scanf("%lld %lld", &a, &b);

	if (a > b) std::swap(a, b);
	printf("%lld", ((a+b)*(b-a+1))/2);

	return 0;
}