#include <cstdio>

int main() {
	int N, L;
	int pos[102], red[100], green[100];

	scanf("%d %d", &N, &L);

	for (int i=0 ; i<N ; i++)
		scanf("%d %d %d", pos+i+1, red+i, green+i);

	int time = 0;
	pos[0] = 0;
	pos[N+1] = L;

	for (int i=1 ; i<=N ; i++) {
		time += pos[i]-pos[i-1];
		if (time%(red[i-1]+green[i-1]) < red[i-1]) time += red[i-1]-time%(red[i-1]+green[i-1]);
	}

	time += pos[N+1]-pos[N];

	printf("%d", time);

	return 0;
}