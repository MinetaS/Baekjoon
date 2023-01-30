#include <cstdio>
#include <cmath>
#include <vector>

#define E 2.7182818284590452353602874713526624977572L
#define PI 3.1415926535897932384626433832795028841971L

using namespace std;

int factorial_digit(int);

int main() {
	int n;
	vector<int> set;

	scanf("%d", &n);

	for (int t, i=0 ; ; i++) {
		if ((t=factorial_digit(i)) > n) break;
		if (t == n) set.push_back(i);
	}

	if (set.size() == 0) printf("NO");
	else {
		printf("%d\n", set.size());
		for (int &e : set) printf("%d\n", e);
	}

	return 0;
}

int factorial_digit(int _Val) {
	if (_Val < 0) return 0;
	if (_Val <= 1) return 1;

	return floorl(_Val*log10l(_Val/E)+log10(2*PI*_Val)/2.0)+1;
}