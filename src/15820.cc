#include <cstdio>

int main() {
	int sample, nonsample;
	int correct, ret;

	scanf("%d %d", &sample, &nonsample);

	for (int i=0 ; i<sample ; i++) {
		scanf("%d %d", &correct, &ret);

		if (correct != ret) {
			printf("Wrong Answer");
			return 0;
		}
	}

	for (int i=0 ; i<nonsample ; i++) {
		scanf("%d %d", &correct, &ret);

		if (correct != ret) {
			printf("Why Wrong!!!");
			return 0;
		}
	}

	printf("Accepted");

	return 0;
}