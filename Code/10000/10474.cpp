#include <cstdio>

int main() {
	int nu, de;

	while (true) {
		scanf("%d %d", &nu, &de);
		if (nu==0 && de==0) break;
		printf("%d %d / %d\n", nu/de, nu%de, de);
	}

	return 0;
}