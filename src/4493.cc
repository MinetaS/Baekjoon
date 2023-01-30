#include <cstdio>

int main() {
	int _case;
	
	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		int round;
		int w1 = 0;
		int w2 = 0;

		scanf("%d\n", &round);

		for (int i=0 ; i<round ; i++) {
			char c1, c2;

			scanf("%c %c\n", &c1, &c2);

			if (c1 == c2) continue;
			if ((c1=='R' && c2=='S') || (c1=='S' && c2=='P') || (c1=='P' && c2=='R')) w1++;
			else w2++;
		}

		if (w1 > w2) printf("Player 1\n");
		else if (w1 < w2) printf("Player 2\n");
		else printf("TIE\n");
	}

	return 0;
}