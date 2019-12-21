#include <cstdio>

int main() {
	int N, M;
	int card[100];
	int s = -1;

	scanf("%d %d", &N, &M);
	for (int i=0 ; i<N ; i++) scanf("%d", card+i);

	for (int i=0 ; i<N-2 ; i++)
		for (int j=i+1 ; j<N-1 ; j++)
			for (int t, k=j+1 ; k<N ; k++)
				if ((t=card[i]+card[j]+card[k])>s && t<=M) s = t;

	printf("%d", s);

	return 0;
}