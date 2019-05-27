#include <cstdio>
#include <cstring>

typedef unsigned long long uint64_t;

uint64_t pow(int, int);

int main() {
	int n;
	char password[11];
	int length;
	uint64_t count = 0;

	scanf("%d\n%s", &n, password);
	length = strlen(password);

	for (int i=0 ; i<n ; i++) {
		if (i == length) break;

		uint64_t c = 0;

		for (int j=0 ; j<n-i ; j++)
			c += pow(26, j);

		count += c*((uint64_t)password[i]-97)+1;
	}

	printf("%llu", count);

	return 0;
}

uint64_t pow(int n, int r) {
	uint64_t ret = 1;

	for (int i=0 ; i<r ; i++)
		ret *= n;

	return ret;
}