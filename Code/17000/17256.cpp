#include <cstdio>
#include <cstdint>

struct CakeNumber {
	uint8_t x, y, z;
} __attribute__((aligned(8)));

int main() {
	CakeNumber a, c;

	scanf("%hhu %hhu %hhu", &a.x, &a.y, &a.z);
	scanf("%hhu %hhu %hhu", &c.x, &c.y, &c.z);
	printf("%hhu %hhu %hhu", c.x-a.z, c.y/a.y, c.z-a.x);

	return 0;
}