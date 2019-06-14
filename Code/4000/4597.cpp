#include <cstdio>

typedef char byte;

int main() {
	byte data;
	bool cs = 0;

	while (true) {
		fread(&data, 1, 1, stdin);

		if (data == 35) break;

		if (data > 100) {
			putc((cs ^ (data==101)) ? 48 : 49, stdout);
			cs = 0;
		}
		else {
			if (data==48 || data==49) cs ^= data-48;
			putc(data, stdout);
		}
	}

	return 0;
}