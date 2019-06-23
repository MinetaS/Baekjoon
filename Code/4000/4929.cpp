#include <cstdio>

int main() {
	while (true) {
		int s1, s2;
		int *set1, *set2;

		scanf("%d", &s1);
		if (s1 == 0) break;
		set1 = new int[s1+1];
		set1[s1] = 2147483647;
		for (int i=0 ; i<s1 ; i++) scanf("%d", set1+i);

		scanf("%d", &s2);
		set2 = new int[s2+1];
		set2[s2] = 2147483647;
		for (int i=0 ; i<s2 ; i++) scanf("%d", set2+i);

		int p1 = 0;
		int p2 = 0;
		int total_sum = 0;
		int sum1 = 0;
		int sum2 = 0;

		while (p1<s1 || p2<s2) {
			if (set1[p1] == set2[p2]) {
				total_sum += set1[p1]+((sum1 > sum2) ? sum1 : sum2);
				sum1 = 0;
				sum2 = 0;
				p1++;
				p2++;
				continue;
			}

			if (set1[p1] < set2[p2]) sum1 += set1[p1++];
			else sum2 += set2[p2++];
		}

		total_sum += (sum1 > sum2) ? sum1 : sum2;

		printf("%d\n", total_sum);
	}

	return 0;
}