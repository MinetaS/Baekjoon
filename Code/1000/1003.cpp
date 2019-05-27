#include <cstdio>

int f0[41];
int f1[41];

int f0_c(int n) {
	if (n == 0) return 1;
	if (n == 1) return 0;

	if (f0[n] != -1) return f0[n];

	f0[n] = f0_c(n-1)+f0_c(n-2);
	return f0[n];
}

int f1_c(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	if (f1[n] != -1) return f1[n];

	f1[n] = f1_c(n-1)+f1_c(n-2);
	return f1[n];
}

int main() {
	int _case;
	int n;

	f0[0] = 1;
	f0[1] = 0;
	f1[0] = 0;
	f1[1] = 1;

	for (int i=2 ; i<41 ; i++) {
		f0[i] = -1;
		f1[i] = -1;
	}

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d", &n);
		printf("%d %d\n", f0_c(n), f1_c(n));
	}

	return 0;
}