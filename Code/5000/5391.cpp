#include <cstdio>
#include <cstring>
#include <algorithm>
#include <malloc.h>

#define _penalty(x, block, pnCut, pnOver) (((x)>(block)) ? ((pnCut)*((x)-(block))) : ((pnOver)*((block)-(x))))

int main() {
	int _case;
	int *cache;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		int s, block;
		int p_cut, p_over;
		int *single;

		scanf("%d %d", &s, &block);
		scanf("%d %d", &p_cut, &p_over);
		single = (int *)malloc(s*sizeof(int));
		cache = (int *)calloc(s+1, sizeof(int));
		
		for (int i=0 ; i<s ; i++) scanf("%d", single+i);
		
		int s_total = 0;
		cache[0] = 0;

		for (int i=0 ; i<s ; i++) {
			s_total += single[i];
			cache[i+1] = std::min(_penalty(s_total, block, p_cut, p_over), _penalty(single[i], block, p_cut, p_over)+cache[i]);

			int v1 = single[i];

			for (int j=i-1 ; j>=0 ; j--) {
				v1 += single[j];
				cache[i+1] = std::min(_penalty(v1, block, p_cut, p_over)+cache[j], cache[i+1]);

				if (v1 > block) break;
			}
		}

		printf("%d\n", cache[s]);

		free(single);
		free(cache);
	}

	return 0;
}