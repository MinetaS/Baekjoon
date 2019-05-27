#include <cstdio>

int main() {
	int n;
	int apple, student;
	int s = 0;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d %d", &student, &apple);
		s += apple%student;
	}

	printf("%d", s);

	return 0;
}