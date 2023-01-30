// C

#include <cstdio>

extern "C" {
	int main() {
		char c[] = {0xEF, 0xBF, 0xBD, 0};

		puts(c);
		return 0;
	}
}