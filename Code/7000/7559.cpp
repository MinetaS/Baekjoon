#include <stdio.h>

typedef unsigned long long uint64_t;

int main() {
	int _case;
	int scenario = 1;
	int N;

	uint64_t count;
	int x, y;
	uint64_t c_type1, c_type2, c_type3, c_type4;   // 1:OO, 2:EE, 3:OE, 4:EO

	scanf("%d", &_case);
	N = _case;

	while (_case > 0) {
		_case--;

		c_type1 = 0;
		c_type2 = 0;
		c_type3 = 0;
		c_type4 = 0;

		scanf("%llu", &count);

		for (uint64_t i=0 ; i<count ; i++) {
			scanf("%d %d", &x, &y);

			if ((x%2) && (y%2)) c_type1++;
			if (!(x%2) && !(y%2)) c_type2++;
			if ((x%2) && !(y%2)) c_type3++;
			if (!(x%2) && (y%2)) c_type4++;
		}

		uint64_t total = count*(count-1)*(count-2)/6;
		uint64_t ex_type1 = c_type1*c_type2*c_type3;   // type1 & type2 & type3
		uint64_t ex_type2 = c_type1*c_type2*c_type4;   // type1 & type2 & type4
		uint64_t ex_type3 = c_type1*c_type3*c_type4;   // type1 & type3 & type4
		uint64_t ex_type4 = c_type2*c_type3*c_type4;   // type2 & type3 & type4

		printf("Scenario #%d:\n%llu", scenario, total-(ex_type1+ex_type2+ex_type3+ex_type4));
		if (scenario != N) printf("\n\n");
		scenario++;
	}

	return 0;
}