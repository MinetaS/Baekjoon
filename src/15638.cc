#include <cstdio>

int main() {
	int n;
	bool prime = true;

	scanf("%d", &n);

	if (n>2 && !(n&1)) prime = false;

	for (int i=3 ; i*i<=n ; i+=2) {
		if (n%i == 0) {
			prime = false;
			break;
		}
	}

	if (prime) printf("Yes");
	else printf("No");
	
	return 0;
}