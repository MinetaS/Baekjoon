#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int set[13][2];
	int frame = 1;
	int op = 0;
	int c = 0;
	memset(set, -1, sizeof(set));

	// Input
	while ((c=getchar()) != 10) {
		if (c == 'S') {
			set[frame][0] = 999;
			frame++;
			op = 0;
		}
		if (c == 'P') {
			set[frame][1] = 99;
			frame++;
			op = 0;
		}
		if (c == '-') {
			set[frame][op++] = 0;
			if (op == 2) {
				frame++;
				op = 0;
			}
		}
		if (c>='1' && c<='9') {
			set[frame][op++] = c-48;
			if (op == 2) {
				frame++;
				op = 0;
			}
		}
	}
	
	int score = 0;

	for (int f=1 ; f<=9 ; f++) {
		if (set[f][0] == 999) {
			score += 10;
			score += (set[f+1][0] == 999) ? 10 : set[f+1][0];
			score += (set[f+1][1] == -1) ? ((set[f+2][0] == 999) ? 10 : set[f+2][0]) : ((set[f+1][1] == 99) ? 10-set[f+1][0] : set[f+1][1]);
			continue;
		}

		score += set[f][0];

		if (set[f][1] == 99) {
			score += 10-set[f][0];
			score += (set[f+1][0] == 999) ? 10 : set[f+1][0];
			continue;
		}

		score += set[f][1];
	}

	for (int f=10 ; f<=12 ; f++) {
		if (set[f][0] == -1) break;

		if (set[f][0] == 999) {
			score += 10;
			continue;
		}

		score += std::max(set[f][0], 0);

		if (set[f][1] == 99) {
			score += 10-set[f][0];
			continue;
		}

		score += std::max(set[f][1], 0);
	}

	printf("%d", score);

	return 0;
}