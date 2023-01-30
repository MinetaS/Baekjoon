#include <cstdio>

int main() {
	unsigned int n, k;

	scanf("%u", &n);
	scanf("%u", &k);

	if (n >= 6) printf("Love is open door");
	else {
		for (int i=1 ; i<n ; i++)
			printf("%u\n", (i+k) & 0x1);
	}

	return 0;
}