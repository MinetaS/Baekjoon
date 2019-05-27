#include <cstdio>

int main() {
	int _case;
	int r, e, c;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d %d %d", &r, &e, &c);

		if (r < e-c) printf("advertise\n");
		else if (r > e-c) printf("do not advertise\n");
		else printf("does not matter\n");
	}

	return 0;
}