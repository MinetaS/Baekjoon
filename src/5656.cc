#include <cstdio>
#include <cstring>

int main() {
	int arg0, arg1;
	char op[3];

	const char *result[2] = {"false", "true"};
	int n = 1;

	while (true) {
		scanf("%d %s %d", &arg0, op, &arg1);

		if (strcmp(op, "E") == 0) break;
		if (strcmp(op, ">") == 0) printf("Case %d: %s\n", n, result[arg0 > arg1]);
		if (strcmp(op, ">=") == 0) printf("Case %d: %s\n", n, result[arg0 >= arg1]);
		if (strcmp(op, "<") == 0) printf("Case %d: %s\n", n, result[arg0 < arg1]);
		if (strcmp(op, "<=") == 0) printf("Case %d: %s\n", n, result[arg0 <= arg1]);
		if (strcmp(op, "==") == 0) printf("Case %d: %s\n", n, result[arg0 == arg1]);
		if (strcmp(op, "!=") == 0) printf("Case %d: %s\n", n, result[arg0 != arg1]);

		n++;
	}

	return 0;
}