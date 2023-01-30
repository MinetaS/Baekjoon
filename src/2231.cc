#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	string s;

	scanf("%d", &n);
	s = to_string(n);

	int length = s.length();

	for (int i=max(n-9*length, 1) ; i<n ; i++) {
		s = to_string(i);
		int sum = 0;

		for (char &c : s)
			sum += c-48;

		if (sum+i == n) {
			printf("%d", i);
			return 0;
		}
	}

	printf("0");

	return 0;
}