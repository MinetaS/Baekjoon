#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long uint64;

uint64 reverse_digit(uint64);

int main() {
	vector<uint64> set;
	int n;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		uint64 t;

		scanf("%llu", &t);

		t = reverse_digit(t);
		set.push_back(t);
	}

	sort(set.begin(), set.end());

	for (uint64 &e : set) printf("%llu\n", e);

	return 0;
}

uint64 reverse_digit(uint64 _Val) {
	uint64 rev = 0;

	while (_Val > 0) {
		rev = rev*10 + _Val%10;
		_Val = _Val/10;
	}

	return rev;
}