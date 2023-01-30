#include <cstdio>
#include <algorithm>

int main() {
	int _case;
	int score[5];

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		for (int i=0 ; i<5 ; i++)
			scanf("%d", score+i);

		std::sort(score, score+5);

		if (score[3]-score[1] >= 4) printf("KIN\n");
		else printf("%d\n", score[1]+score[2]+score[3]);
	}

	return 0;
}