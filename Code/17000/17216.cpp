#include <cstdio>

int cache[1001], num[1001];

int main() {
	int n;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", num+i);
		cache[i] = num[i];
	}

	int max = cache[0];

	for (int i=1 ; i<n ; i++) {
		for (int j=0 ; j<i ; j++)
			if (num[i]<num[j] && cache[i]<cache[j]+num[i]) cache[i] = cache[j]+num[i];

		if (cache[i] > max) max = cache[i];
	}

	printf("%d", max);

	return 0;
}