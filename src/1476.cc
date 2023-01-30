#include <cstdio>

int main() {
	int E, S, M;   // ENERGY SYNERGY MATRIX
	int e, s, m;
	int year;

	scanf("%d %d %d", &E, &S, &M);

	e = 1;
	s = 1;
	m = 1;
	year = 1;

	while (E!=e || S!=s || M!=m) {
		e = e%15+1;
		s = s%28+1;
		m = m%19+1;
		year++;
	}

	printf("%d", year);

	return 0;
}