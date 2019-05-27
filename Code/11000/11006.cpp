#include <cstdio>

int main() {
	int _case;
	int leg, head;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d %d", &leg, &head);
		printf("%d %d\n", head*2-leg, leg-head);
	}

	return 0;
}