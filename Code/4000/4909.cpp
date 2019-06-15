#include <cstdio>

int main() {
	int score[6];

	while (true) {
		int max = -1;
		int min = 999;
		int sum = 0;
		bool zero = true;

		for (int i=0 ; i<6 ; i++) {
			scanf("%d", score+i);

			zero &= (score[i] == 0);
			if (score[i] > max) max = score[i];
			if (score[i] < min) min = score[i];
			sum += score[i];
		}

		if (zero) break;

		sum -= max+min;
		sum *= 25;

		printf("%d", sum/100);
		if (sum%100 != 0) {
			printf(".%d", (sum%100)/10);
			if (sum%10 != 0) printf("%d", sum%10);
		}
		printf("\n");
	}

	return 0;
}