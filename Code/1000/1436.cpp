#include <cstdio>
#include <string>

using namespace std;

int main() {
	int n;
	int c = 0;

	scanf("%d", &n);

	for (int i=666 ; ; i++) {
		string s = to_string(i);

		if (s.find("666") != s.npos) {
			c++;

			if (c == n) {
				printf("%d", i);
				break;
			}
		}
	}

	return 0;
}