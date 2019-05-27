#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	string s = string("");

	scanf("%d", &n);

	while (n > 0) {
		s += to_string(n%9);
		n /= 9;
	}

	reverse(s.begin(), s.end());

	printf("%s", s.c_str());

	return 0;
}