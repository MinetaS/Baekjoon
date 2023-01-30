#include <cstdio>
#include <cstring>

#define min(x, y) (((x) > (y)) ? (y) : (x))
#ifdef _MSC_VER
#include <intrin.h>
#define bit_count __popcnt64
#else
#define bit_count __builtin_popcount
#endif

typedef unsigned char uint8_t;
typedef unsigned long long uint64_t;

int main() {
	int width, height;
	uint64_t board[50] = {0,};   // White=0, Black=1

	unsigned int opt_convert = 32;

	// Board Initalize
	scanf("%d %d", &height, &width);

	for (int i=0 ; i<height ; i++) {
		char _tmp[50];
		
		scanf("%s", _tmp);

		for (size_t j=0 ; j<strlen(_tmp) ; j++)
			if (_tmp[j] == 'B') board[i] |= 1uLL << j;
	}

	const uint8_t compare1 = 0b10101010;
	const uint8_t compare2 = 0b01010101;
	
	// Analyze
	for (int y=0 ; y<height-7 ; y++) {
		for (int x=0 ; x<width-7 ; x++) {
			unsigned int convert = 0;

			for (int i=0 ; i<8 ; i++) {
				uint8_t label = (uint8_t)((board[y+i]>>x) & (uint64_t)0xFF);
				convert += bit_count(label ^ ((i%2) ? compare1 : compare2));
			}

			convert = min(convert, 64-convert);
			opt_convert = min(opt_convert, convert);
		}
	}

	printf("%d\n", opt_convert);

	return 0;
}