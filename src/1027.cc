#include <cstdio>

typedef unsigned long long uint64_t;

int main() {
	int N;
	uint64_t height[50];

	scanf("%d", &N);

	for (int i=0 ; i<N ; i++)
		scanf("%llu", &height[i]);

	uint64_t max = 0;

	for (int set=0 ; set<N ; set++) {
		int visible_building = 0;

		for (int i=0 ; i<set ; i++) {
			bool visible = true;

			for (int j=i+1 ; j<set ; j++) {
				if (height[j]*(set-i) >= (height[set]-height[i])*(j-set)+height[set]*(set-i)) {
					visible = false;
					break;
				}
			}

			if (visible) visible_building++;
		}

		for (int i=set+1 ; i<N ; i++) {
			bool visible = true;

			for (int j=set+1 ; j<i ; j++) {
				if (height[j]*(i-set) >= (height[i]-height[set])*(j-set)+height[set]*(i-set)) {
					visible = false;
					break;
				}
			}

			if (visible) visible_building++;
		}

		if (visible_building > max) max = visible_building;
	}

	printf("%llu", max);

	return 0;
}