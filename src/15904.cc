#include <cstdio>

int main() {
	constexpr char abbr[4] = {85, 67, 80, 67};
	int index = 0;
	int c;

	while (true) {
		c = getchar();

		if (c==10 || c==-1) break;
		if (c == abbr[index]) index++;
		if (index == 4) break;
	}

	if (index == 4) printf("I love UCPC");
	else printf("I hate UCPC");

	return 0;
}