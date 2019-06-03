#include <cstdio>

int main() {
	int num[10] = {0,};
	int s=0, c;
	bool zero = false;

	while ((c=getchar()) != 10) {
		if (c == 48) zero = true;
		s += c-48;
		num[c-48]++;
	}

	if (s%3==0 && zero) {
		for (int i=9 ; i>=0 ; i--)
			for (int j=0 ; j<num[i] ; j++) printf("%d", i);
	}
	else printf("-1");

	return 0;
}