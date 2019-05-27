#include <cstdio>

bool check(int);

int main() {
	for (int i=2992 ; i<=9999 ; i++)
		if (check(i)) printf("%d\n", i);

	return 0;
}

bool check(int n) {
	int b10 = 0;
	int b12 = 0;
	int b16 = 0;

	int t = n;
	while (t > 0) {
		b10 += t%10;
		t /= 10;
	}

	t = n;
	while (t > 0) {
		b12 += t%12;
		t /= 12;
	}

	t = n;
	while (t > 0) {
		b16 += t%16;
		t /= 16;
	}

	if (b10==b12 && b12==b16) return true;
	else return false;
}