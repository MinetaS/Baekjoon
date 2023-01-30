#include <cstdio>

int main() {
	int balance;
	int amount;
	char cmd;

	while (true) {
		scanf("%d %c %d", &balance, &cmd, &amount);

		if (amount == 0) break;

		if (cmd == 'D') printf("%d\n", balance+amount);
		else {
			bool p = balance-amount < -200;
			printf((p) ? "Not allowed\n" : "%d\n", (p) ? 0 : balance-amount);
		}
	}

	return 0;
}