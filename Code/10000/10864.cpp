#include <cstdio>

int main() {
	int N, M;
	int a, b, i;
	int friends[1000] = {0,};

	scanf("%d %d", &N, &M);

	for (i=0 ; i<M ; i++) {
		scanf("%d %d", &a, &b);
		friends[a-1]++;
		friends[b-1]++;
	}

	for (int i=0 ; i<N ; i++) printf("%d\n", friends[i]);

	return 0;
}