#include <cstdio>

typedef unsigned char byte;

constexpr unsigned int size = 128000;

int main() {
	int i;

	for (byte buf[size+1] ; fread(buf, 1, size, stdin) != 0 ; ) {
		for (i=0 ; i<size && buf[i]!=10 ; i++) buf[i] -= 32;
		buf[i] = 0;
		printf("%s", buf);
	}

	return 0;
}