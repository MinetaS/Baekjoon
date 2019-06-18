#include <cstdio>

typedef unsigned char byte;

byte buf[1 << 20];

int main() {
	fread(buf, 1, 1<<20, stdin);
	for (int i=0 ; buf[i]!=10 ; i++) putchar(buf[i]-32);
	
	return 0;
}