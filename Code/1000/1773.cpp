#include <cstdio>

bool light[2000001];

int main() {
	int n, time, p;

	scanf("%d %d", &n, &time);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &p);

		for (int j=p ; j<=p*(time/p) ; j+=p)
			light[j] = true;
	}

	int count = 0;

	for (int i=1 ; i<=time ; i++)
		if (light[i]) count++;

	printf("%d", count);

	return 0;
}