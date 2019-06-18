#include <cstdio>

int main() {
	int a, b;
	char op;

	scanf("%d\n", &a);

	while (true) {
		scanf("%c", &op);

		if (op == '=') {
			printf("%d", a);
			break;
		}

		scanf("\n%d\n", &b);

		switch (op) {
		case '+':
			a += b;
			break;

		case '-':
			a -= b;
			break;

		case '*':
			a *= b;
			break;

		case '/':
			a /= b;
			break;
		}
	}

	return 0;
}