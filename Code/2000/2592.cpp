#include <cstdio>

int main() {
	int avg = 0;
	int freq[100] = {0,};
	int freq_max = 0;
	int freq_num;
	int t;

	for (int i=0 ; i<10 ; i++) {
		scanf("%d", &t);
		avg += t/10;
		freq[t/10]++;

		if (freq[t/10] > freq_max) {
			freq_max = freq[t/10];
			freq_num = t;
		}
	}

	printf("%d\n%d", avg, freq_num);

	return 0;
}