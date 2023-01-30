#include <cstdio>
#include <cmath>

bool is_prime(unsigned int);

int main() {
	int n;
	int count = 0;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		unsigned int t;
		scanf("%u", &t);
		if (is_prime(t)) count++;
	}
	
	printf("%d", count);

	return 0;
}

bool is_prime(unsigned int n) {
	if (n == 1) return false;
	if (n == 2) return true;
	if (!(n%2)) return false;

	for (int i=3 ; i<=(int)sqrt((double)n) ; i+=2)
		if (n%i == 0) return false;

	return true;
}