#include <cstdio>

int main() {
	int N, M;
	int basket[100] = {0,};

	scanf("%d %d", &N, &M);

	for (int i=0, v1, v2, v3 ; i<M ; i++) {
		scanf("%d %d %d", &v1, &v2, &v3);
		for (int j=v1 ; j<=v2 ; j++) basket[j-1] = v3;
	}

	for (int i=0 ; i<N ; i++) printf("%d ", basket[i]);

	return 0;
}