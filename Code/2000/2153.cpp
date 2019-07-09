#include <cstdio>

bool is_prime(int);

int main() {
	char str[21];
	int value = 0;

	scanf("%s", str);

	for (int i=0 ; str[i]!=0 ; i++) {
		if (str[i]>=65 && str[i]<=90) value += str[i]-38;
		if (str[i]>=97 && str[i]<=122) value += str[i]-96;
	}

	printf((is_prime(value)) ? "It is a prime word." : "It is not a prime word.");

	return 0;
}

bool is_prime(int _Val) {
	if (_Val < 1) return false;
	if (_Val == 1) return true;

	for (int i=2 ; i*i<=_Val ; i++)
		if (_Val%i == 0) return false;

	return true;
}