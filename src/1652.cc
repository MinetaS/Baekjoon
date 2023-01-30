#include <cstdio>

int main() {
	int n;
	char room[101][101];
	
	scanf("%d", &n);

	for (int i=0 ; i<n ; i++)
		scanf("%s", room[i]);

	int h = 0;
	int v = 0;

	for (int i=0 ; i<n ; i++) {
		int hc = 0;
		int vc = 0;

		for (int j=0 ; j<n ; j++) {
			if (room[i][j]=='.') hc++;
			else hc = 0;
			if (room[j][i]=='.') vc++;
			else vc = 0;

			if (hc == 2) h++;
			if (vc == 2) v++;
		}
	}

	printf("%d %d", h, v);

	return 0;
}