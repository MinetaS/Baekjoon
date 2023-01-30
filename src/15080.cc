#include <cstdio>

int main() {
	int h1, m1, s1;
	int h2, m2, s2;
	int diff = 0;

	scanf("%d : %d : %d\n%d : %d : %d", &h1, &m1, &s1, &h2, &m2, &s2);

	if (s2 < s1) {
		s2 += 60;
		m2--;
	}

	diff += s2-s1;

	if (m2 < m1) {
		m2 += 60;
		h2--;
	}

	diff += (m2-m1)*60;

	if (h2 < h1) h2 += 24;

	diff += (h2-h1)*3600;

	printf("%d", diff);

	return 0;
}